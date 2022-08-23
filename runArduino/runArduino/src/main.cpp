#include <Arduino.h>
#include "main.h"

#define MAX_LINE_LENGTH 80
#define buttonMan A0

state_t target_state;
state_t current_state;
SoftwareSerial mySerial(RxSerial,TxSerial);
float delta_step[2] = {0, 0};

// #define DEBUG
void main_draw(void);
void draw(void);
void runFile(int nameFile);
void home(void);
void setup()
{
  // setup for sandTable
  serial_register_init(); // Serial 
  stepper_init(); // step XY
  initSD(); // mircoSD
  mySerial.begin(BAUD_RATE); // Serial to connect ESP32
  pinMode(buttonMan,INPUT_PULLUP);
  // clear status
  Serial.println("clear");
  memset(&target_state, 0, sizeof(state_t));
  memset(&current_state, 0, sizeof(state_t));
  current_state.step_offset[1] = 4800;
  sei();
  Serial.println("sandTable");
}
void loop()
{
  if (digitalRead(buttonMan) == 1){
    Serial.println("Man Mode");
    // begin Mans
    runFile(5);
    home();
    runFile(2);
    home();
    runFile(3);
    home();
    runFile(4);

  }else {
    Serial.println("Auto Mode");
    // begin Auto
    if(mySerial.available()){
      char value = mySerial.read();
      switch (value)
      {
      case '1':
        Serial.println("auto mode 1");
        runFile(2);
        break;
      case '2':
        Serial.println("auto mode 2");
        runFile(3);
        break;
      case '3':
        Serial.println("auto mode 3");        
        runFile(4);
        break;
      case '4':
        Serial.println("auto mode 4");
        runFile(5);
        break;
      default:
      case '5':
        Serial.println("auto mode 1");
        runFile(1);
        break;
      }
    } 
  }
}

void draw(void){
  if (DISTANCE(target_state.pos[0], target_state.pos[1]) > (L1 + L2))
  {
    Serial.println("Destination over limit area !");
  }
  else
  {
    main_draw();
  }
}

void main_draw(void)
{
  long target_step[2] = {0, 0};
  inverse_kinematics(target_state.pos, target_state.deg);
  scara_transfer(target_state.deg, DESCARTES_COORD);
  scara_offset(target_state.deg, target_state.step_offset);
  stepper_deltaStepCalc(target_state.step_offset, current_state.step_offset, delta_step);

  target_step[0] = lround(current_state.step[0] + delta_step[0]);
  target_step[1] = lround(current_state.step[1] + delta_step[1]);
  //target_step[0] = lround(stepper_getPos(0) + delta_step[0]);
  //target_step[1] = lround(stepper_getPos(1) + delta_step[1]);

  stepper_moveRelative(target_step);
  current_state.step_offset[0] = target_state.step_offset[0];
  current_state.step_offset[1] = target_state.step_offset[1];
  current_state.step[0] = (float) target_step[0];
  current_state.step[1] = (float) target_step[1];
  Serial.println("draw");
  return;
}

void runFile(int nameFile){
  File myFile;
    // convert file 
    switch(nameFile){       
        case 1:
            myFile = SD.open(FILE1);
        break;
        case 2:
            myFile = SD.open(FILE2);
        break;
        case 3:
            myFile = SD.open(FILE3);
        break;
        case 4:
            myFile = SD.open(FILE4);
        break;
        case 5:
            myFile = SD.open(FILE5);
        break;
        case 6:
            myFile = SD.open(FILE6);
        break;
        case 7:
            myFile = SD.open(FILE7);
        break;
        case 8:
            myFile = SD.open(FILE8);
        break;
        case 9:
            myFile = SD.open(FILE9);
        break;
        case 10:
            myFile = SD.open(FILE10);
        break;
        default:
            myFile = SD.open(FILE0);
    };
  if (myFile) {
        while (myFile.available()) {
            // readline and get X Y 
            float coord[2];
            convertLineFloat(myFile,coord);
            // print value
            Serial.print(coord[0]);
            Serial.print(" ");
            Serial.println(coord[1]);
            // run location
            target_state.pos[0] = (float) coord[0];
            target_state.pos[1] = (float) coord[1];
            draw();
        }
        myFile.close();
        Serial.println("endFile");
    } else {
        Serial.println("error opening test.txt");
    }
}

void home(void){
 target_state.pos[0] = 0.0;
 target_state.pos[1] = 0.0;
 draw();
 delay(1000);
}