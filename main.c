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

int left_power,right_power;

/*
 * PINOUT:
 *  BUMP SWITCHES: (RIGHT TO LEFT)
 *      P4.0 P4.2 P4.3 P4.5 P4.6 P4.7
*          1 2 3 4 5 6
 *  IR LINE SENSORS:
 *      P7.0 7.1 7.2 7.3 7.4 7.5 7.6 7.7
 *      1 2 3 4 5 6 7 8
 *      8 IS ON THE FAR LEFT, 1 IS ON THE FAR RIGHT
 *  IR DIST SENSORS:
 *      5.1 is left
 *      5.2 is right
 *      5.0 is center
 */
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

    systick_initialize();
    __enable_irq(); //ENABLE INTERRUPTS
    NVIC_EnableIRQ(PORT5_IRQn); //ENABLE INTERRUPTS FOR PORT 1

    left_power = 40;
    right_power = 40;

    setup_motors();
    setForwards();
    setBothPower_1(left_power,right_power);

    while (1)
    {
        if (enc_left > enc_right)
            setBothPower_1(left_power-2,right_power+2);
        else if (enc_right > enc_left)
            setBothPower_1(left_power+2,right_power-2);
        else
            setBothPower_1(left_power,right_power);

        if (enc_left >= 720 && enc_right >= 720)
        {
            stopBoth();
            systick_wait(1000000);
            enc_left = 0;
            enc_right = 0;
            setRotateRight();
            setBothPower_1(left_power,right_power);
            while (1)
            {
                if (enc_left > enc_right)
                    setBothPower_1(left_power-2,right_power+2);
                else if (enc_right > enc_left)
                    setBothPower_1(left_power+2,right_power-2);
                else
                    setBothPower_1(left_power,right_power);

                if (enc_left >= 360 && enc_right >= 360)
                {
                    stopBoth();
                    systick_wait(1000000);
                    enc_left = 0;
                    enc_right = 0;
                    setForwards();
                    break;
                }
            }
        }
    }
}
