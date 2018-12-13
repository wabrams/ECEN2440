#include "msp.h"
/*
 * PINOUT:
 *  IR LINE SENSORS:
 *      P7.0 7.1 7.2 7.3 7.4 7.5 7.6 7.7
 *      1 2 3 4 5 6 7 8
 *      8 IS ON THE FAR LEFT, 1 IS ON THE FAR RIGHT
*/
#ifndef LINESENSOR_H
#define LINESENSOR_H

#define LS_1 BIT0
#define LS_2 BIT1
#define LS_3 BIT2
#define LS_4 BIT3
#define LS_5 BIT4
#define LS_6 BIT5
#define LS_7 BIT6
#define LS_8 BIT7
//IR LED is 5.3
#define IRLED 0x08

static int LS[8];
static int CB[8];

void setup_linesensors();
void IRLEDon();
void IRLEDoff();
void calibrate_linesensors();
void read_linesensors();

#endif /* LINESENSOR_H */
