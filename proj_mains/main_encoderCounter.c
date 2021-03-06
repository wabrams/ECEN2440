///*
// * USAGE: FOR TI-RSLK ROBOT
// * AUTHORS: William Abrams, Darren Schultz
// * UNIVERSITY: University of Colorado Boulder
// * COURSE: ECEN 2440
// * TARGET: MSP432P401R
// */
//#include "msp.h"
//#include "motors.h"
//#include "timing.h"
//#include "bumps.h"
//#include "linesensor.h"
//
//int left_power,right_power;
//
///*
// * PINOUT:
// *  IR LINE SENSORS:
// *      P7.0 7.1 7.2 7.3 7.4 7.5 7.6 7.7
// *      1 2 3 4 5 6 7 8
// *      8 IS ON THE FAR LEFT, 1 IS ON THE FAR RIGHT
// *  IR DIST SENSORS:
// *      5.1 is left
// *      5.2 is right
// *      5.0 is center
// */
//void PORT4_IRQHandler()
//{
//    /*
//     * bumps.h
//     *
//     *  Created on: Dec 9, 2018
//     *      Author: Will
//     *  BUMP SWITCHES: (RIGHT TO LEFT)
//     *  P4.0 P4.2 P4.3 P4.5 P4.6 P4.7
//    *   1 2 3 4 5 6
//    *   0b 1110 1101
//    *   0x 14 13
//    *   0x ED
//     */
//    P4IE &= ~0xED;
//
////    if (P4IFG & 0xED)
////    {
////        flag_bumpswitches |= ((BUMP_SW_1 & P4IFG)?1:0) << 0;
////        flag_bumpswitches |= ((BUMP_SW_2 & P4IFG)?1:0) << 1;
////        flag_bumpswitches |= ((BUMP_SW_3 & P4IFG)?1:0) << 2;
////        flag_bumpswitches |= ((BUMP_SW_4 & P4IFG)?1:0) << 3;
////        flag_bumpswitches |= ((BUMP_SW_5 & P4IFG)?1:0) << 4;
////        flag_bumpswitches |= ((BUMP_SW_6 & P4IFG)?1:0) << 5;
//
//    flag_bumpswitches = 1;
//        P4IFG &= ~0xED;
////    }
//    P4IE |=  0xED;
//}
//void PORT5_IRQHandler() //port 5 interrupt handler
//{
//    P5IE &= ~0x30;      //DISABLE INTERRUPTS FOR ENCODERS
//    if (P5IFG & 0x10) //LEFT ENCODER
//    {
//        enc_left++;
//        P5IFG &= ~0x10;     //CLEAR INTERRUPT FLAG
//    }
//    if (P5IFG & 0x20)//RIGHT ENCODER
//    {
//        enc_right++;
//        P5IFG &= ~0x20;     //CLEAR INTERRUPT FLAG
//    }
//    P5IE |= 0x30;
//}
//int main(void)
//{
//    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD; //disable watchdog
//
//    systick_initialize();
//    __enable_irq(); //ENABLE INTERRUPTS
//    NVIC_EnableIRQ(PORT5_IRQn); //ENABLE INTERRUPTS FOR PORT 5
//    NVIC_EnableIRQ(PORT4_IRQn); //ENABLE INTERRUPTS FOR PORT 4
//
//    left_power = 30;
//    right_power = 30;
//
//    setup_motors();
//    setup_bumpsensors();
//    setup_linesensors();
//
//    //go forwards
//    setForwards_1(PWM_DUTY_PERC_SLOW);
//    while (enc_left < 1725 && enc_right < 1725)
//    {
//        if (enc_left > enc_right)
//            setBothPower_1(PWM_DUTY_PERC_SLOW-2,PWM_DUTY_PERC_SLOW+2);
//        else if (enc_right > enc_left)
//            setBothPower_1(PWM_DUTY_PERC_SLOW+2,PWM_DUTY_PERC_SLOW-2);
//        else
//            setBothPower_1(PWM_DUTY_PERC_SLOW,PWM_DUTY_PERC_SLOW);
//    }
//
//    //stop
//    stopBoth();
//    systick_wait(1000000);
//    enc_left = 0;
//    enc_right = 0;
//
//
//    //turn right
//    setRotateRight();
//    setBothPower(PWM_DUTY_PERC_SLOW);
//    while (enc_left < 175 && enc_right < 175)
//    {
//        if (enc_left > enc_right)
//            setBothPower_1(PWM_DUTY_PERC_SLOW-2,PWM_DUTY_PERC_SLOW+2);
//        else if (enc_right > enc_left)
//            setBothPower_1(PWM_DUTY_PERC_SLOW+2,PWM_DUTY_PERC_SLOW-2);
//        else
//            setBothPower_1(PWM_DUTY_PERC_SLOW,PWM_DUTY_PERC_SLOW);
//    }
//
//    //stop
//    stopBoth();
//    systick_wait(1000000);
//    enc_left = 0;
//    enc_right = 0;
//
//    //go forwards
//    setForwards_1(PWM_DUTY_PERC_SLOW);
//    while (enc_left < 1750 && enc_right < 1750)
//    {
//        if (enc_left > enc_right)
//            setBothPower_1(PWM_DUTY_PERC_SLOW-2,PWM_DUTY_PERC_SLOW+2);
//        else if (enc_right > enc_left)
//            setBothPower_1(PWM_DUTY_PERC_SLOW+2,PWM_DUTY_PERC_SLOW-2);
//        else
//            setBothPower_1(PWM_DUTY_PERC_SLOW,PWM_DUTY_PERC_SLOW);
//    }
//
//    //stop
//    stopBoth();
//    systick_wait(1000000);
//    enc_left = 0;
//    enc_right = 0;
//
//    //uturn left
//    setRotateLeft();
//    setBothPower(PWM_DUTY_PERC_SLOW);
//    while (enc_left < 365 && enc_right < 365)
//    {
//        if (enc_left > enc_right)
//            setBothPower_1(PWM_DUTY_PERC_SLOW-2,PWM_DUTY_PERC_SLOW+2);
//        else if (enc_right > enc_left)
//            setBothPower_1(PWM_DUTY_PERC_SLOW+2,PWM_DUTY_PERC_SLOW-2);
//        else
//            setBothPower_1(PWM_DUTY_PERC_SLOW,PWM_DUTY_PERC_SLOW);
//    }
//
//    //stop
//    stopBoth();
//    systick_wait(1000000);
//    enc_left = 0;
//    enc_right = 0;
//
//    //go forwards
//    setForwards_1(PWM_DUTY_PERC_SLOW);
//    while (enc_left < 1725 && enc_right < 1725)
//    {
//        if (enc_left > enc_right)
//            setBothPower_1(PWM_DUTY_PERC_SLOW-2,PWM_DUTY_PERC_SLOW+2);
//        else if (enc_right > enc_left)
//            setBothPower_1(PWM_DUTY_PERC_SLOW+2,PWM_DUTY_PERC_SLOW-2);
//        else
//            setBothPower_1(PWM_DUTY_PERC_SLOW,PWM_DUTY_PERC_SLOW);
//    }
//
//    //stop
//    stopBoth();
//    systick_wait(1000000);
//    enc_left = 0;
//    enc_right = 0;
//
//
//    //turn left
//    setRotateLeft();
//    setBothPower(PWM_DUTY_PERC_SLOW);
//    while (enc_left < 175 && enc_right < 175)
//    {
//        if (enc_left > enc_right)
//            setBothPower_1(PWM_DUTY_PERC_SLOW-2,PWM_DUTY_PERC_SLOW+2);
//        else if (enc_right > enc_left)
//            setBothPower_1(PWM_DUTY_PERC_SLOW+2,PWM_DUTY_PERC_SLOW-2);
//        else
//            setBothPower_1(PWM_DUTY_PERC_SLOW,PWM_DUTY_PERC_SLOW);
//    }
//
//    //stop
//    stopBoth();
//    systick_wait(1000000);
//    enc_left = 0;
//    enc_right = 0;
//
//    //go forwards
//    setForwards_1(PWM_DUTY_PERC_SLOW);
//    while (enc_left < 1725 && enc_right < 1725)
//    {
//        if (enc_left > enc_right)
//            setBothPower_1(PWM_DUTY_PERC_SLOW-2,PWM_DUTY_PERC_SLOW+2);
//        else if (enc_right > enc_left)
//            setBothPower_1(PWM_DUTY_PERC_SLOW+2,PWM_DUTY_PERC_SLOW-2);
//        else
//            setBothPower_1(PWM_DUTY_PERC_SLOW,PWM_DUTY_PERC_SLOW);
//    }
//
//    //stop
//    stopBoth();
//    systick_wait(1000000);
//    enc_left = 0;
//    enc_right = 0;
//}
