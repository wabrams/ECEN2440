#include "msp.h"
/////////////////////////////////////////////////////////////////////////
//  PINOUT:
//      LEFT ENCODER:
//          SLP P3.7
//          DIR P1.7
//          PWR P2.7
//          OUT P5.4
//      RIGHT ENCODER:
//          SLP P3.6
//          DIR P1.6
//          PWR P2.6
//          OUT P5.5
/////////////////////////////////////////////////////////////////////////
#ifndef MOTORS_H_
#define MOTORS_H_

#define MOTOR_PORT P1OUT
#define MOTOR_LEFT_BIT BIT7
#define MOTOR_RIGHT_BIT BIT6

#define MOTOR_LEFT_INVERTED 0
#define MOTOR_RIGHT_INVERTED 1

#define MOTOR_LEFT_OFFSET 3
#define MOTOR_RIGHT_OFFSET 0

#define PWM_DUTY_PERIOD 200

#define PWM_DUTY_PERC_SLOW 20
#define PWM_DUTY_PERC_NORM 40
#define PWM_DUTY_PERC_QUICK 60
#define PWM_DUTY_PERC_FAST  80
#define PWM_DUTY_PERC_INSANE 100

static volatile int enc_left,enc_right;

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
