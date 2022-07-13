/*************************/
/*************************/
/*****Author:Alaa Osama***/
/*****Layer:MCAL *********/
/*****SWC:DIO*************/
/*****Version:1.00********/
/****** Date:29-8-2020****/
/*************************/
/*************************/
//hena btf2 m3 el user zy el # defines el gaya

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define DIO_u8PORTA    0
#define DIO_u8PORTB    1
#define DIO_u8PORTC    2
#define DIO_u8PORTD    3

#define DIO_u8PIN0     0
#define DIO_u8PIN1     1
#define DIO_u8PIN2     2
#define DIO_u8PIN3     3
#define DIO_u8PIN4     4
#define DIO_u8PIN5     5
#define DIO_u8PIN6     6
#define DIO_u8PIN7     7

#define DIO_u8PIN_LOW      0
#define DIO_u8PIN_HIGH     1

#define DIO_u8PORT_HIGH   0xff
#define DIO_u8PORT_LOW    0

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
u8 DIO_u8TogglePinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8* Copy_Pu8Value);//p for pointer as i'll return to the user 2 values .. 1 the i/p value .. 2 the function check value (in the pointer) 

#endif
