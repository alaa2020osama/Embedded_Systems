/*************************/
/*************************/
/**** Author:Alaa Osama **/
/**** Layer:HAL **********/
/*****SWC:Keypad**********/
/**** Version:1.00  ******/
/****** Date:1-9-2020 ****/
/*************************/
/*************************/

#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "KPD_config.h"
#include "KPD_interface.h"
#include "KPD_private.h"

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8ColIdx, Local_u8RowIdx, Local_u8PressedKey=NO_PRESSED_KEY,Local_u8PinState;
	u8 Local_KPDArr[ROW_NUMBER][COLUMN_NUMBER]=KPD_BUTTONS_VAL; //k keam lel arkam
	u8 Local_u8ColArr[COLUMN_NUMBER]=COLUMN_PINS;
	u8 Local_u8RowArr[ROW_NUMBER]=ROW_PINS;

	for(Local_u8ColIdx=0; Local_u8ColIdx < COLUMN_NUMBER;Local_u8ColIdx++)
	{
		/*1- Activate the current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIdx],DIO_u8PIN_LOW);

		for(Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUMBER;Local_u8RowIdx++)
		{
			/*2- Read the current Row*/
			DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8PinState);

			if(Local_u8PinState==DIO_u8PIN_LOW)
			{
				Local_u8PressedKey=Local_KPDArr[Local_u8RowIdx][Local_u8ColIdx];
				/*wait (polling with blocking) until the key is released*/
				while(!Local_u8PinState)//el zorar b low tb e2rah tany
				{
					DIO_u8GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIdx],&Local_u8PinState);
				}
				return Local_u8PressedKey;
			}
		}
		/*3- Deactivate the current column*/
		DIO_u8SetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIdx],DIO_u8PIN_HIGH);

	}
	return Local_u8PressedKey;
}
