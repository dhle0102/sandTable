#ifndef RGB_H
#define RGB_H

#define redPin 15
#define greenPin 2
#define bluePin 4
#define ledPin 5

void RGBinit(void);
void RGBcontrol(int red, int green, int blue);
#endif