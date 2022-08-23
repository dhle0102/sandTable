#include "RGB.h"
#define BLYNK_USE_DIRECT_CONNECT
#define BLYNK_PRINT Serial

#include <BlynkSimpleEsp32_BLE.h>
#include <BLEDevice.h>
#include <BLEServer.h>

char auth[] = "HgxrrxKUrgDcHAhEUqcgtArDY2xIzBqS";

// Widgets LCD 
WidgetLCD lcdBlynk(V12);

BLYNK_CONNECTED() {   
  // image 
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3); 
  Blynk.syncVirtual(V4);
  Blynk.syncVirtual(V5);
  // LED 
  Blynk.syncVirtual(V6);
  Blynk.syncVirtual(V7);
  Blynk.syncVirtual(V8);
  Blynk.syncVirtual(V9);
  // home 
  Blynk.syncVirtual(V10);
  Blynk.syncVirtual(V11);

}

// connect image1
BLYNK_WRITE(V0) 
{
  int pinValue = param.asInt(); 
  if (pinValue == 1){
    Serial.println("Image 1 :");
    // connect Aruidno 
    Serial2.write('1');
    //while (Serial2.read() != 'o'){};
  }; 
}
// connect image2
BLYNK_WRITE(V1){
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("Image 2 :");
    // connect Aruidno 
    Serial2.write('2');
    //while (Serial2.read() != 'o'){};
  };
}
// connect image3
BLYNK_WRITE(V2){
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("Image 3 :");
    // connect Aruidno 
    Serial2.write('3');
    //while (Serial2.read() != 'o'){};
  }
}
// connect image4
BLYNK_WRITE(V3){
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("Image 4 :");
    // connect Aruidno 
    Serial2.write('4');
    //while (Serial2.read() != 'o'){};
  }
}
// connect image5
BLYNK_WRITE(V4){
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("Image 5 :");
    // connect Aruidno 
    Serial2.write('5');
    //while (Serial2.read() != 'o'){};
  }
}
// connect image6
BLYNK_WRITE(V5){
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("Image 6 :");
  }
}
// connect LED1 
BLYNK_WRITE(V6){
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("LED 1 :");
    RGBcontrol(255,0,0);
  }
}
// connect LED2
BLYNK_WRITE(V7){
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("lED 2 :");
    RGBcontrol(0,255,0);
  }
}
// connect LED3 
BLYNK_WRITE(V8){
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("LED 3 :");
    RGBcontrol(0,0,255);
  }
} 
// connect LED4
BLYNK_WRITE(V9){
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("LED 4 :");
    RGBcontrol(255,255,0);
  }
}
// connect HOME
BLYNK_WRITE(V10){
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("HOME :");
  }
} 
// connect CLEAR
BLYNK_WRITE(V11){
  int pinValue = param.asInt();
  if(pinValue == 1){
    Serial.println("CLEAR RGB :");
    RGBcontrol(0,0,0);
  }
}
void setup()
{
  // setup 
  RGBinit();
  // Debug console
  Serial.begin(9600);
  Serial2.begin(115200);
  Serial.println("Waiting for connections...");
  Blynk.setDeviceName("SandTable");
  Blynk.begin(auth);
  // send completed 
  Serial.println("OKE BEGIN");
}

void loop()
{
  Blynk.run();
}
