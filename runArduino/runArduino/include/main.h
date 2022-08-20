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

float sample_src[10][2] =
    {
        {9.239, 42.431},
        {-42.774, 100.853},
        {-56.892, 28.179},
        {-138.753, -8.749},
        {-63.230, -49.489},
        {-51.184, -150.000},
        {-50.881, -150.000},
        {18.903, -82.322},
        {130.219, -103.403},
        {0.0,0.0}
        };
float sample_src2[16][2] = 
{
    {-30.0,50.0},
    {0.0,100.0},
    {30.0,50.0},
    {0.0,0.0},
    {50.0,30.0},
    {100.0,0.0},
    {50.0,-30.0},
    {0.0,0.0},
    {30.0,-50.0},
    {0.0,-100.0},
    {-30.0,-50.0},
    {0.0,0.0},
    {-50.0,-30.0},
    {-100.0,30.0},
    {-50.0,30.0},
    {0.0,0.0}
};
#endif