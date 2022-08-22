#ifndef READMIRCOSD_H
#define READMIRCOSD_H

#define READFILE 'r'
#define WRITEFILE 'w'
#define pinSD 4

#define FILE0 "0.txt"
#define FILE1 "1.txt"
#define FILE2 "2.txt"
#define FILE3 "3.txt"
#define FILE4 "4.txt"
#define FILE5 "5.txt"
#define FILE6 "6.txt"
#define FILE7 "7.txt"
#define FILE8 "8.txt"
#define FILE9 "9.txt"
#define FILE10 "10.txt"

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

void initSD();
void runFile(int nameFile);
void convertLineFloat(File file,float * valueFloat);
#endif