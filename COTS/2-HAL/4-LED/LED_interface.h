/*************************/
/*************************/
/**** Author:Alaa Osama **/
/**** Layer:HAL **********/
/**** SWC:LED ************/
/**** Version:1.00 *******/
/**** Date:2-9-2020 ******/
/*************************/
/*************************/

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define SINK     0
#define SOURCE   1

typedef struct
{
	u8 LED_TYPE;
	u8 LED_PORT;
	u8 LED_PIN;
}LED_STRUCT;

void LED_voidON(LED_STRUCT *Copy_pLEDStruct);
void LED_voidOFF(LED_STRUCT *Copy_pLEDStruct);
void LED_voidToggle(LED_STRUCT *Copy_pLEDStruct);

#endif
