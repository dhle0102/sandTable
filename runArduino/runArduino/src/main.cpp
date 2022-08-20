#include <Arduino.h>
#include "main.h"

#define MAX_LINE_LENGTH 80

state_t target_state;
state_t current_state;
File file;
float delta_step[2] = {0, 0};

// #define DEBUG
void main_draw(void);
void draw(void);
void setup()
{
  // serial_init();
  serial_register_init();
  stepper_init();
  initSD();
  // clear status
  memset(&target_state, 0, sizeof(state_t));
  memset(&current_state, 0, sizeof(state_t));
  current_state.pos[0] = 0.0;
  current_state.pos[1] = 0.0;
  current_state.step_offset[1] = 4800;
  sei();
  Serial.println("sandTable");
}
void loop()
{
 runFile(1);
 delay(5000);
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