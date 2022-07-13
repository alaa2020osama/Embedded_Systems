/*******************************/
/*******************************/
/**** Author:Alaa Osama ********/
/**** Layer:MCAL ***************/
/**** SWC:EXTERNAL_INTERRUPT ***/
/**** Version:1.00 *************/
/**** Date:16-9-2020 ***********/
/*******************************/
/*******************************/

#ifndef EXTI_REGISTER_H_
#define EXTI_REGISTER_H_

#define MCUCR           *((volatile u8*)0x55)      /*MCU Control register*/
#define MCUCR_ISC11     3                          /*Int1 sense control bit 1*/
#define MCUCR_ISC10     2                          /*Int1 sense control bit 0*/
#define MCUCR_ISC01     1                          /*Int0 sense control bit 1*/
#define MCUCR_ISC00     0                          /*Int0 sense control bit 0*/

#define MCUCSR          *((volatile u8*)0x54)      /*MCU Control and status register*/
#define MCUCSR_ISC2     6                          /*Int2 sense control*/

#define GICR            *((volatile u8*)0x5B)      /*General interrupt control register*/
#define GICR_INT1       7                          /*Int1 PIE*/
#define GICR_INT0       6                          /*Int0 PIE*/
#define GICR_INT2       5                          /*Int2 PIE*/

#endif