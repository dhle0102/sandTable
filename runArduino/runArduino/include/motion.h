#ifndef MOTION_H
#define MOTION_H

#include <Arduino.h>
#include <AccelStepper.h>
#include <MultiStepper.h>
#include "scara.h"

#define X_AXIS 0
#define Y_AXIS 1

// Define motors pin
#define DIR_X   6 //5
#define DIR_Y   5 //6
// #define DIR_Z   

#define STEP_X  3 //2 
#define STEP_Y  2 //3
// #define STEP_Z  4

#define STEP_EN 8
#define LIMIT_X 9
#define LIMIT_Y 10

void stepper_init(void);
long stepper_getPos(int motor);
void stepper_moveRelative(long *steps);
void stepper_deltaStepCalc(float *target, float *current, float *delta_step);
bool stepper_isRunning(void);
void runX(long pwm);
#endif