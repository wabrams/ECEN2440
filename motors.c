#include "motors.h"

void setup_encoders()
{
    P5SEL0 = 0x00; //CLR SEL REG0 PORT1
    P5SEL1 = 0x00; //CLR SEL REG0 PORT1
    P5REN  = 0x30; //ENABLE RES FOR LEFT AND RIGHT ENCODERS (P5.4, P5.5)
    P5DIR  = 0x00; //ALL INPUTS
    P5IES  = 0x30;
    P5IFG  = 0x00; //CLEAR ANY INITIAL INTERRUPT FLAGS
    P5IE   = 0x30; //ENABLE INTERRUPTS FOR LEFT AND RIGHT ENCODERS

    enc_left = 0;
    enc_right = 0;
}
void setup_motors()
{
    setup_encoders();
    /*
     * TODO:
     * Better define the registers with preprocessor instructions
     * Check the speed being between the duty cycle and 0
     *      or: accept values between 0 and -duty cycle and use toggle functions
     * Ramp acceleration functions
     * Stop functions
     */
    P2SEL0 |= 0XC0;  // (BIT6 & BIT7)
    P2SEL1 &= 0xC0;  // (BIT6 & BIT7)
    P2DIR |= 0xC0;   // (BIT6 & BIT7)
    P2DS |= 0xC0;    // (BIT6 & BIT7)

    P1SEL0 &= ~0xC0; // ~(BIT6 & BIT7)
    P1SEL1 &= ~0xC0; // ~(BIT6 & BIT7)
    P1DIR |= 0xC0;   // (BIT6 & BIT7)
    P1OUT = 0b10000000;

    TIMER_A0->CCTL[0] = 0x0080;  // toggle Timer_A0 by activating the 7th bit
    TIMER_A0->CCTL[3] = 0x0040;  // enables interrupts toggle/reset for CCR[0] RT
    TIMER_A0->CCTL[4] = 0x0040;  // enables interrupts toggle/reset for CCR[0] LF
    TIMER_A0->CCR[0]  =   200;     //Period
    TIMER_A0->CCR[3]  =   0;       // straight ---  , Duty cycle right motor
    TIMER_A0->CCR[4]  =   0;       // straight ---  , Duty cycle left motor
    TIMER_A0->EX0     = 0x0000;
    TIMER_A0->CTL = 0x0230;
}

void setLeftSpeed(int c)
{
    TIMER_A0->CCR[4] = c;
}
void setRightSpeed(int d)
{
    TIMER_A0->CCR[3] = d;
}
void setBothSpeed(int b)
{
    setLeftSpeed(b);
    setRightSpeed(b);
}
void setBothSpeed_1(int c, int d)
{
    setLeftSpeed(c);
    setRightSpeed(d);
}
void setLeftPower(int c)
{
    int frac = c*PWM_DUTY_PERIOD/100;
    setLeftSpeed(frac+MOTOR_LEFT_OFFSET);
}
void setRightPower(int d)
{
    int frac = d*PWM_DUTY_PERIOD/100;
    setLeftSpeed(frac+MOTOR_LEFT_OFFSET);
}
void setBothPower(int e)
{
    int frac = e*PWM_DUTY_PERIOD/100;
    setLeftSpeed(frac+MOTOR_LEFT_OFFSET);
    setRightSpeed(frac+MOTOR_RIGHT_OFFSET);
}
void setBothPower_1(int c, int d)
{
    int frac1 = c*PWM_DUTY_PERIOD/100;
    int frac2 = d*PWM_DUTY_PERIOD/100;
    setLeftSpeed(frac1+MOTOR_LEFT_OFFSET);
    setRightSpeed(frac2+MOTOR_RIGHT_OFFSET);
}
void stopLeft()
{
    setLeftSpeed(0);
}
void stopRight()
{
    setRightSpeed(0);
}
void stopBoth()
{
    stopLeft();
    stopRight();
}
void setLeftClockwise()
{
    #if MOTOR_LEFT_INVERTED
        MOTOR_PORT &= ~MOTOR_LEFT_BIT;
    #else
        MOTOR_PORT |= MOTOR_LEFT_BIT;
    #endif
}
void setLeftClockwise_1(int s)
{
    setLeftClockwise();
    //TODO: left motor speed function
}
void setLeftCounterclockwise()
{
    #if MOTOR_LEFT_INVERTED
        MOTOR_PORT |= MOTOR_LEFT_BIT;
    #else
        MOTOR_PORT &= ~MOTOR_LEFT_BIT;
    #endif
}
void setLeftCounterclockwise_1(int s)
{
    setLeftCounterclockwise();
    //TODO: left motor speed function
}
void setRightClockwise()
{
    #if MOTOR_RIGHT_INVERTED
        MOTOR_PORT &= ~MOTOR_RIGHT_BIT;
    #else
        MOTOR_PORT |= MOTOR_RIGHT_BIT;
    #endif
}
void setRightClockwise_1(int t)
{
    setRightClockwise();
   //TODO: right motor speed function
}
void setRightCounterclockwise()
{
    #if MOTOR_RIGHT_INVERTED
        MOTOR_PORT |= MOTOR_RIGHT_BIT;
    #else
        MOTOR_PORT &= ~MOTOR_RIGHT_BIT;
    #endif
}
void setRightCounterclockwise_1(int t)
{
    setRightCounterclockwise();
   //TODO: right motor speed function
}
void setLeftForwards()
{
    setLeftCounterclockwise();
}
void setLeftForwards_1(int s)
{
    setLeftForwards();
    //TODO: left motor speed function
}
void setLeftBackwards()
{
    setLeftClockwise();
}
void setLeftBackwards_1(int s)
{
    setLeftBackwards();
    //TODO: left motor speed function
}
void setRightForwards()
{
    setRightClockwise();
}
void setRightForwards_1(int t)
{
    setRightForwards();
    //TODO: right motor speed function
}
void setRightBackwards()
{
    setRightCounterclockwise();
}
void setRightBackwards_1(int t)
{
    setRightBackwards();
    //TODO: right motor speed function
}
void setForwards()
{
    setLeftForwards();
    setRightForwards();
}
void setForwards_1(int r)
{
    setForwards();
    setBothPower(r);
}
void setForwards_2(int s, int t)
{
    setForwards();
    setBothPower_1(s, t);
}
void setBackwards()
{
    setLeftBackwards();
    setRightBackwards();
}
void setBackwards_1(int r)
{
    setBackwards();
    setBothPower(r);
}
void setBackwards_2(int s, int t)
{
    setBackwards();
    //TODO both motor speed functions
}
void setRotateLeft()
{
    setLeftBackwards();
    setRightForwards();
}
void setRotateRight()
{
    setLeftForwards();
    setRightBackwards();
}
