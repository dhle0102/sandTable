#include "readMicroSD.h"
#include "serial.h"
#include "motion.h"

void initSD(){
    Serial.print("Initializing SD card...");
    if (!SD.begin(pinSD)) {
        Serial.println("initialization failed!");
        while (1);
    }
    Serial.println("initialization done.");
}

void convertLineFloat(File file, float * valueFloat){
    char value;
    String X = "";
    String Y = "";
    int location = 0;
    do{
        // read char 
        value = file.read();

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

    // convert value 
    valueFloat[0] = X.toFloat();
    valueFloat[1] = Y.toFloat();
    
};

    