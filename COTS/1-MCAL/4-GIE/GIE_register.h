/*************************************/
/*************************************/
/**** Author:Alaa Osama **************/
/**** Layer:MCAL *********************/
/**** SWC:GENERAL_INTERRUPT_ENABLE ***/
/**** Version:1.00 *******************/
/**** Date:16-9-2020 *****************/
/*************************************/
/*************************************/

#ifndef GIE_REGISTER_H_
#define GIE_REGISTER_H_

#define SREG       *((volatile u8*)0x5f)    /*Status Register*/
#define SREG_I     7                        /*Global Interrupt Enable Bit*/

#endif