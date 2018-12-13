/*
 * linesensor.c
 *
 *  Created on: Dec 11, 2018
 *      Author: Will
 */

#include "linesensor.h"
#include "timing.h"
#include <stdio.h>
void setup_linesensors()
{
    //ir led (we need to mask this, because other stuff uses P5)
    P5DS |= IRLED;
    P5SEL0 &= ~IRLED;
    P5SEL1 &= ~IRLED;
    P5DIR &= ~IRLED;
    P5OUT &= ~IRLED;

    //linesensors
    P7SEL0 = 0x00;
    P7SEL1 = 0x00;
    P7DIR  = 0x00;
    P7OUT  = 0x00;
}
void IRLEDon()
{
    P5OUT |= IRLED;
}
void IRLEDoff()
{
    P5OUT &= ~IRLED;
}
void calibrate_linesensors()
{
    int i = 0;
    systick_initialize();

    while (i < 8)
    {
        IRLEDoff();
        P7DIR = 0xFF;
        P7OUT = 0xFF;
        IRLEDon();

        P7DIR = 0x00;
        int start = (int)NVIC_ST_CURRENT_R;
        while (P7IN & (0x01 << i));
        CB[i] = -((int)NVIC_ST_CURRENT_R - start);

        i++;
        IRLEDoff();
    }
}
void read_linesensors()
{
    int i = 0;
        while (i < 8)
        {
            systick_initialize();
            IRLEDoff();
            P7DIR = 0xFF;
            P7OUT = 0xFF;
            IRLEDon();

            P7DIR = 0x00;
            int start = (int)NVIC_ST_CURRENT_R;

            while (P7IN & (0x01 << i));

            LS[i] = ((int)NVIC_ST_CURRENT_R - start) + CB[i]; //todo: i negated this equation, make sure it is right
            i++;
            IRLEDoff();
        }
}
