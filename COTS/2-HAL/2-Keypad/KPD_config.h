/********************/
/*************************/
/*****Author:Alaa Osama***/
/*****Layer:HAL ****/
/*****SWC:Keypad********/
/*****Version:1.00****/
/****** Date:1-9-2020**/
/*************************/
/*************************/

#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_BUTTONS_VAL   {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#define KPD_PORT          DIO_u8PORTD
#define COLUMN_NUMBER    4
#define ROW_NUMBER       4



#define NO_PRESSED_KEY    0
#define COLUMN_PIN0       DIO_u8PIN3
#define COLUMN_PIN1       DIO_u8PIN2
#define COLUMN_PIN2       DIO_u8PIN1
#define COLUMN_PIN3       DIO_u8PIN0

#define ROW_PIN0       DIO_u8PIN4
#define ROW_PIN1       DIO_u8PIN5
#define ROW_PIN2       DIO_u8PIN6
#define ROW_PIN3       DIO_u8PIN7

#define COLUMN_PINS          {COLUMN_PIN0,COLUMN_PIN1,COLUMN_PIN2,COLUMN_PIN3}
#define ROW_PINS             {ROW_PIN0,ROW_PIN1,ROW_PIN2,ROW_PIN3};

#endif
