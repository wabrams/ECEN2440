#include "bumps.h"

void setup_bumpsensors()
{
    P4SEL0 = 0x00; //CLR SEL REG0 PORT1
    P4SEL1 = 0x00; //CLR SEL REG0 PORT1
    P4DIR  = 0x00; //ALL INPUTS
    P4REN  = 0xED;
    P4OUT  = 0xED; //IMPORTANTE, DO NOT FORGET
    P4IES  = 0x00;
    P4IFG  = 0x00; //CLEAR ANY INITIAL INTERRUPT FLAGS
    P4IE   = 0xED; //ENABLE INTERRUPTS FOR LEFT AND RIGHT ENCODERS
}
