#include "msp.h"

#ifndef MOTORS_H_
#define MOTORS_H_

void setup_motors();

void setLeftSpeed(int c);
void setRightSpeed(int d);
void setBothSpeed(int b);
void setBothSpeed_1(int c, int d);

void setLeftPower(int c);
void setRightPower(int d);
void setBothPower(int e);
void setBothPower_1(int c, int d);

void stopLeft();
void stopRight();
void stopBoth();

void setLeftClockwise();
void setLeftClockwise_1(int s);
void setLeftCounterclockwise();
void setLeftCounterclockwise_1(int s);

void setRightClockwise();
void setRightClockwise_1(int t);
void setRightCounterclockwise();
void setRightCounterclockwise_1(int t);

void setLeftForwards();
void setLeftForwards_1(int s);
void setLeftBackwards();
void setLeftBackwards_1(int s);
void setRightForwards();
void setRightForwards_1(int t);
void setRightBackwards();
void setRightBackwards_1(int t);

void setForwards();
void setForwards_1(int r);
void setForwards_2(int s, int t);
void setBackwards();
void setBackwards_1(int r);
void setBackwards_2(int s, int t);

void setRotateLeft();
void setRotateRight();

#endif /* MOTORS_H_ */
