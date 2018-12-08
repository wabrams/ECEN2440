/*
 * USAGE: FOR TI-RSLK ROBOT
 * AUTHORS: William Abrams, Darren Schultz
 * UNIVERSITY: University of Colorado Boulder
 * COURSE: ECEN 2440
 * TARGET: MSP432P401R
 */
#include "msp.h"
#include "motors.h"
#include "timing.h"

volatile int enc_left,enc_right;
int left_power,right_power;

void PORT5_IRQHandler() //port 5 interrupt handler
{
    P5IE &= ~0x30;      //DISABLE INTERRUPTS FOR ENCODERS
    if (P5IFG & 0x10) //LEFT ENCODER
    {
        enc_left++;
        P5IFG &= ~0x10;     //CLEAR INTERRUPT FLAG
    }
    if (P5IFG & 0x20)//RIGHT ENCODER
    {
        enc_right++;
        P5IFG &= ~0x20;     //CLEAR INTERRUPT FLAG
    }
    P5IE |= 0x30;
}
int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; //disable watchdog

    enc_left = 0;
    enc_right = 0;

    P5SEL0 = 0x00; //CLR SEL REG0 PORT1
    P5SEL1 = 0x00; //CLR SEL REG0 PORT1
    P5REN  = 0x30; //ENABLE RES FOR LEFT AND RIGHT ENCODERS (P5.4, P5.5)
    P5DIR  = 0x00; //ALL INPUTS
    P5IES  = 0x30;
    P5IFG  = 0x00; //CLEAR ANY INITIAL INTERRUPT FLAGS
    P5IE   = 0x30; //ENABLE INTERRUPTS FOR LEFT AND RIGHT ENCODERS

    systick_initialize();
    __enable_irq(); //ENABLE INTERRUPTS
    NVIC_EnableIRQ(PORT5_IRQn); //ENABLE INTERRUPTS FOR PORT 1

    left_power = 40;
    right_power = 40;

    setup_motors();
    setForwards();
//    setRotateRight();
    setBothPower_1(left_power,right_power);
//    int left = 0;
//    int i = 0;
    while (1)
    {

        if (enc_left > enc_right)
            setBothPower_1(left_power-2,right_power+2);
        else if (enc_right > enc_left)
            setBothPower_1(left_power+2,right_power-2);
        else
            setBothPower_1(left_power,right_power);
        if (enc_left >= 500 && enc_right >= 500) //takes time for the wheels to stop, period is 360 - 5
        {
            stopBoth();
            enc_left = 0;
            enc_right = 0;
            systick_wait(1000000);
        }
//
//        if (enc_left >= 178 && enc_right >= 178)
//        {
//            stopBoth();
//            if (left==1)
//            {
//                left = 0;
//                setRotateRight();
//            }
//            else
//            {
//                left = 1;
//                setRotateLeft();
//            }
//            systick_wait(1000000);
//            enc_left = 0;
//            enc_right = 0;
//            i++;
//            if (i == 1)
//                break;
//            setBothPower_1(left_power,right_power);
//        }
    }
}
