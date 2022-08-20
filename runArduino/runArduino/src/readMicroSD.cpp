#include "readMicroSD.h"
#include "serial.h"

void initSD(){
    Serial.print("Initializing SD card...");
    if (!SD.begin(pinSD)) {
        Serial.println("initialization failed!");
        while (1);
    }
    Serial.println("initialization done.");
}

void convertLineFloat(File file,float * valueFloat){
    char value;
    String X = "";
    String Y = "";
    int location = 0;
    do{
        // read char 
        value = file.read();
        //Serial.print(value);

        // check value
        switch (value)
        {
        case 'X':
            location = 1;
            continue;
        break;
        case 'Y':
            location = 2;
            continue;
        break;
        case '\n':
            location = 0;
        break;
        }

        // get value 
        if(location == 1){
            X = X + value;
        }else if(location == 2 ){
            Y = Y + value;
        }
    }
    while (value != '\n');

    Serial.println(X);
    Serial.println(Y);
    // convert value 
    valueFloat[0] = X.toFloat();
    valueFloat[1] = Y.toFloat();
    
};

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
        }
        myFile.close();
    } else {
        Serial.println("error opening test.txt");
    }
}
    