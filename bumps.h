/*
 * bumps.h
 *
 *  Created on: Dec 9, 2018
 *      Author: Will
 *  BUMP SWITCHES: (RIGHT TO LEFT)
 *  P4.0 P4.2 P4.3 P4.5 P4.6 P4.7
*   1 2 3 4 5 6
*   0b 1110 1101
*   0x 14 13
*   0x ED
 */
#include "msp.h"

#ifndef BUMPS_H_
#define BUMPS_H_

#define BUMP_SW_1 BIT0
#define BUMP_SW_2 BIT2
#define BUMP_SW_3 BIT3
#define BUMP_SW_4 BIT5
#define BUMP_SW_5 BIT6
#define BUMP_SW_6 BIT7

static volatile int flag_bumpswitches = 0;

void setup_bumpsensors();

#endif /* BUMPS_H_ */
