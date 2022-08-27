#include "RGB.h"
#include <Arduino.h>

void RGBinit(void){
    pinMode(redPin,OUTPUT);
    pinMode(greenPin,OUTPUT);
    pinMode(bluePin,OUTPUT);
    pinMode(ledPin,OUTPUT);
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
    digitalWrite(bluePin,LOW);
    digitalWrite(ledPin,LOW);
};

void RGBcontrol(int red, int green, int blue){
    analogWrite(redPin,red);
    analogWrite(greenPin,green);
    analogWrite(bluePin,blue);
}