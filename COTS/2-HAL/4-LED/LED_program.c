/*************************/
/*************************/
/**** Author:Alaa Osama **/
/**** Layer:HAL **********/
/**** SWC:LED ************/
/**** Version:1.00 *******/
/**** Date:2-9-2020 ******/
/*************************/
/*************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

void LED_voidON(LED_STRUCT *Copy_pLEDStruct)
{
	if(Copy_pLEDStruct->LED_TYPE==SOURCE)
	{
		DIO_u8SetPinValue(Copy_pLEDStruct->LED_PORT,Copy_pLEDStruct->LED_PIN,DIO_u8PIN_HIGH);
	}
	else if(Copy_pLEDStruct->LED_TYPE==SINK)
	{
		DIO_u8SetPinValue(Copy_pLEDStruct->LED_PORT,Copy_pLEDStruct->LED_PIN,DIO_u8PIN_LOW);
	}
}

void LED_voidOFF(LED_STRUCT *Copy_pLEDStruct)
{
	if(Copy_pLEDStruct->LED_TYPE==SOURCE)
		{
			DIO_u8SetPinValue(Copy_pLEDStruct->LED_PORT,Copy_pLEDStruct->LED_PIN,DIO_u8PIN_LOW);
		}
		else if(Copy_pLEDStruct->LED_TYPE==SINK)
		{
			DIO_u8SetPinValue(Copy_pLEDStruct->LED_PORT,Copy_pLEDStruct->LED_PIN,DIO_u8PIN_HIGH);
		}
}

void LED_voidToggle(LED_STRUCT *Copy_pLEDStruct)
{
	DIO_u8TogglePinValue(Copy_pLEDStruct->LED_PORT,Copy_pLEDStruct->LED_PIN);
}
