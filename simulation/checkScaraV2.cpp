#include <iostream>
#include <stdio.h>
#include <math.h>

#define RADIANS(d) ((d)*(float)M_PI/180.0f)
#define DEGREES(r) ((r)*180.0f/(float)M_PI)
#define DISTANCE(x,y) (sqrt(x*x+y*y))
float L1 = 130.0;
float L2 = 130.0;
#define X_AXIS 0
#define Y_AXIS 1
#define N_AXIS 2
#define PI 3.14f
#define sq(d) (d*d)

using namespace std;

void forward_kinematics(float *theta, float *pos);
void inverse_kinematics(float *pos, float * theta);
void scara_offset(float *offset_input,float *offset_output);

int main(){
    cout << "begin:" << endl;
    float theta[2];
    float pos[2] = {100.0,100.0};
    inverse_kinematics(pos,theta);
    cout << "theta 1 = " << theta[0] << endl;
    cout << "theta 2 = " << theta[1] << endl;
    forward_kinematics(theta,pos);
    cout << "pos 1 = " << pos[0] << endl;
    cout << "pos 2 = " << pos[1] << endl;
    // end program
    int end;cin >> end;
    return 0;
}

void forward_kinematics(float *theta, float *pos)
{

  pos[X_AXIS] = L1 * cosf(RADIANS(theta[X_AXIS])) + L2 * cosf(RADIANS(theta[X_AXIS] + theta[Y_AXIS]));
  pos[Y_AXIS] = L1 * sinf(RADIANS(theta[X_AXIS])) + L2 * sinf(RADIANS(theta[X_AXIS] + theta[Y_AXIS]));
}

void inverse_kinematics(float *pos, float * theta)
{
  if ((pos[X_AXIS] == 0) && (pos[Y_AXIS] == 0))
  {
    theta[X_AXIS] = 0;
    theta[Y_AXIS] = 180;
    return;
  }

  double scara_c2 = 0.0f;
  double scara_s2 = 0.0f;
  double scara_k1 = 0.0f;
  double scara_k2 = 0.0f;

  scara_c2 = (sq(pos[X_AXIS]) + sq(pos[Y_AXIS]) - sq(L1) - sq(L2)) / (2 * L1 * L2);
  scara_s2 = sqrtf(1 - sq(scara_c2));
  scara_k1 = L1 + L2 * scara_c2;
  scara_k2 = L2 * scara_s2;
  theta[X_AXIS] = atanf(pos[Y_AXIS] / pos[X_AXIS]) - atanf(scara_k2 / scara_k1);
  theta[Y_AXIS] = atanf(scara_s2 / scara_c2) + PI;
  if (pos[X_AXIS] < 0)
  {
    if (pos[Y_AXIS] > 0)
    {
      theta[X_AXIS] = theta[X_AXIS] + PI;
    }
    else
    {
      theta[X_AXIS] = theta[X_AXIS] - PI;
    }
  }
  for (int i = 0; i < N_AXIS; i++)
  {
    theta[i] = DEGREES(theta[i]);
  }
}

void scara_offset(float *offset_input,float *offset_output)
{
  offset_output[X_AXIS] = offset_input[X_AXIS];
  offset_output[Y_AXIS] = offset_input[Y_AXIS] + offset_input[X_AXIS];
}