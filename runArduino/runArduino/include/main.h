#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <math.h>
#include "scara.h"
#include "motion.h"
#include "serial.h"
#include "readMicroSD.h"

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define HOMING 5
#define START 6
#define STOP 7
#define RUN_1SERIAL 8
#define SET_0 9

typedef struct
{
    float pos[2];
    float deg[2];
    float step[2];
    float step_offset[2];
} state_t;

#endif