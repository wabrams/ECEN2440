//#include "msp.h"
//#include <stdio.h>
//
//#define NVIC_ST_CTRL_R          *(unsigned long *)0xE000E010
//#define NVIC_ST_RELOAD_R        *(unsigned long *)0xE000E014
//#define NVIC_ST_CURRENT_R       *(unsigned long *)0xE000E018
//#define NVIC_ST_CTRL_CLK_SRC    0x00000004
//#define NVIC_ST_CTRL_ENABLE     0x00000001
//#define NVIC_ST_RELOAD_M        0x00FFFFFF
//
//#define ADC14CTL0     *(unsigned long *)0x40012000
//#define ADC14CTL1     *(unsigned long *)0x40012004
//#define ADC14MCTL0    *(unsigned long *)0x40012018
//#define ADC14MEM0     *(unsigned long *)0x40012098
//#define ADC14IFGR0    *(unsigned long *)0x40012144
//#define ADC14IER0     *(unsigned long *)0x4001213C
//#define ADC14IER1     *(unsigned long *)0x4001213C
//
//int raw_data;
//int n;
//
//void LED_Init(void)
//{
//    P1->SEL0 &= ~0x01; // BIT1 -P1.0 LED
//    P1->SEL1 &= ~0x01;
//    P1->DIR |= 0x01;   // sets as output
//}
//
//void stop_motors ()  //a helper called to stop the motors
//{
//      TIMER_A0->CCR[3] = 0;       // OFF RT
//      TIMER_A0->CCR[4] = 0;       // OFF LEFT
//      //for(n = 0; n < 50; n++);
//}
//void fwd_little ()  //a helper called go FWD
//{
//    P1OUT = BIT6; // FWD BOTH
//           TIMER_A0->CCR[3] = 80;  // ON RT
//           TIMER_A0->CCR[4] = 80;  // ON LEFT
//           for(n = 0; n < 200000; n++);
//           stop_motors ();
//
//}
//void SysTick_Init(void)
//{
//  NVIC_ST_CTRL_R = 0;
//  NVIC_ST_RELOAD_R = NVIC_ST_RELOAD_M;
//  NVIC_ST_CURRENT_R = 0;
//  NVIC_ST_CTRL_R = NVIC_ST_CTRL_ENABLE+NVIC_ST_CTRL_CLK_SRC;
//}
//void SysTick_Wait(unsigned long delay)
//{
//  volatile unsigned long elapsedTime;
//  unsigned long startTime = NVIC_ST_CURRENT_R;
//  do
//  {
//    elapsedTime = (startTime-NVIC_ST_CURRENT_R)&0x00FFFFFF;
//  }
//  while(elapsedTime <= delay);
//}
//void ADC14_IRQ()
//{
//    if (ADC14_IFGR0_IFG0 & 1)
//    {
//        //do stuff
//        //ADC14_IFGR0_IFG0 = 0;
//    }
//}
//int main(void){
//    //initialize the Timer_A
//    TIMER_A0->CCTL[0] = 0x0080;  // toggle Timer_A0 by activating the 7th bit
//    TIMER_A0->CCTL[3] = 0x0040;  // enables interrupts toggle/reset for CCR[0] RT
//    TIMER_A0->CCTL[4] = 0x0040;  // enables interrupts toggle/reset for CCR[0] LF
//    TIMER_A0->CCR[0] = 200;  //Period
//    TIMER_A0->CCR[3] = 0;        // straight ---  , Duty cycle right motor
//    TIMER_A0->CCR[4] = 0;        // straight ---  , Duty cycle left motor
//    TIMER_A0->EX0 =     0x0000;
//      //TIMER_A0->CCR[1] = 5000;
//    TIMER_A0->CTL = 0x0230;
//
//    //INTERRUPT SETUP
//    ADC14IER0 = ADC14_IER0_IE0;
//     __enable_irq();
//     NVIC_EnableIRQ(ADC14_IRQn);  //TODO: Find actual name of ADC14_IRQ interrupt handler
//
//    //enable Pinouts for the motors
//
//        P2SEL0 |= 0XC0;  // (BIT6 & BIT7)
//        P2SEL1 &= 0xC0;  // (BIT6 & BIT7)
//        P2DIR |= 0xC0;   // (BIT6 & BIT7)
//        P2DS |= 0xC0;    // (BIT6 & BIT7)
//        P1SEL0 &= ~0xC0; // ~(BIT6 & BIT7)
//        P1SEL1 &= ~0xC0; // ~(BIT6 & BIT7)
//        P1DIR |= 0xC0;   // (BIT6 & BIT7)
//        P1OUT = 0b10000000;
//
//    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;
//    SysTick_Init();
//    LED_Init();
//
//    //P4.1: 0b 0000 0010
//    P4SEL1 = 0x02;
//    P4SEL0 = 0x02;
//
//    ADC14CTL0  = 0x00000000;
//    ADC14CTL0 &= 0xFFFFFFFD;
//    ADC14CTL0 |= 0x00000010;
//    ADC14CTL0 |= 0x04000000;
//
//    ADC14CTL1 =  0x00000030;
//    ADC14MCTL0 = 0x0000008C;
//    ADC14IER0 =  0x00000000;
//    ADC14IER1 =  0x00000000;
//    ADC14CTL0 |= 0x00000002;
//
//
//
//            P1OUT &= ~(0x01); // LED off
//           // fwd back seems good
//            P1OUT = (BIT6 & BIT7); // FWD BOTH
//            TIMER_A0->CCR[3] = 42;     // ON RT
//            TIMER_A0->CCR[4] = 44;     // ON LEFT
//
//    while (1)
//    {
//
//
//        ADC14CTL0 |= 00000001;
//        while(ADC14CTL0 & (1<<16)); //ADC14BUSY bit 16 (1<<16)
//        raw_data = ADC14MEM0;
//        if (raw_data >=5500)
//        {
//            stop_motors ();
//           P1OUT |= (0x01);           // LED for visuale cue
//        }
//        else
//        {
//            P1OUT &= ~(0x01); // LED off
////           // fwd back seems good
////            P1OUT = (BIT6 & BIT7); // FWD BOTH
//            TIMER_A0->CCR[3] = 42;     // ON RT
//            TIMER_A0->CCR[4] = 44;     // ON LEFT
////             for(n = 0; n < 400000; n++);
////
////            TIMER_A0->CCR[3] = 0;       // OFF RT
////            TIMER_A0->CCR[4] = 0;       // OFF LEFT
////             for(n = 0; n < 100; n++);
//        }
//
//
//    }
//}
//
