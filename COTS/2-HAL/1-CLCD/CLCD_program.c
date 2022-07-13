/*************************/
/*************************/
/**** Author:Alaa Osama **/
/**** Layer:HAL **********/
/**** SWC:CLCD ***********/
/**** Version:1.00 *******/
/**** Date:30-8-2020******/
/*************************/
/*************************/

#include "STD_TYPES.h"
#include <util/delay.h>

#include "DIO_interface.h"

#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*1-Set RS to high:for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*2-Set RW to low:for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*3-Send the data*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*4-Send the enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

}

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*1-Set RS to low:for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*2-Set RW to low:for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*3-Send the command*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*4-Send the enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

}

void CLCD_voidInit(void)
{
	/*1- wait for more than 30 seconds*/
	_delay_ms(40);

	/*2- function set command: 2 lines , 5x7 font size*/
	CLCD_voidSendCommand(0b00111000);

	/*3- Display on/off control: Display on, cursor on, blink cursor off*/
	CLCD_voidSendCommand(0b00001110);

	/*4- Display clear*/
	CLCD_voidSendCommand(1);
}

void CLCD_voidSendString(const char* Copy_pchString)
{
	u8 Local_u8Counter=0;
	while(Copy_pchString[Local_u8Counter] != '\0')
	{
		CLCD_voidSendData(Copy_pchString[Local_u8Counter]);
		Local_u8Counter++;
		//momken a3melha bel dereferencing
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8DDRAMAddress;
	if(Copy_u8YPos==0)
	{
		/*if first line*/
		Local_u8DDRAMAddress=Copy_u8XPos;
	}
	else if(Copy_u8YPos==1)
	{
		/*if second line*/
		Local_u8DDRAMAddress=0x40 + Copy_u8XPos;
	}
	//Local_u8DDRAMAddress= 0x40 * Copy_u8YPos + Copy_u8XPos;//just in one line

	/*set bit number 7 for SetDDRAM address command then send the command*/
	CLCD_voidSendCommand(Local_u8DDRAMAddress+128);//momken t3mleha b set bit 3ady aw b or elly hwa ell implementation nfso
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_pu8Pattern,u8 Copy_u8PatternNumber,u8 Copy_u8XPos,u8 Copy_u8YPos)
{
	u8 Local_u8CGRAMAddress,Local_u8Counter;

	/*1- calculate the cgram address knowing that every pattern consumes 8 bytes*/
	Local_u8CGRAMAddress=Copy_u8PatternNumber*8;

	/*2- send SetCGRAM address command with bit 6 being set and 7 cleared*/
	CLCD_voidSendCommand(Local_u8CGRAMAddress+64);

	/*3- write the pattern into CGRAM */
	for(Local_u8Counter=0 ; Local_u8Counter<8 ; Local_u8Counter++)
	{
		CLCD_voidSendData(Copy_pu8Pattern[Local_u8Counter]);
	}

	/*4- Back to the DDRAM to display the pattern*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);

	/*5- Display the required pattern in CGRAM*/
	//el DDRAM 3arfa en law etb3tlha rakam ya3ny t3rd el pattern no da fe cgram
	CLCD_voidSendData(Copy_u8PatternNumber);
}

void CLCD_voidWriteNumber(u32 Copy_u32number)
{
	u32 Local_u32array[10];
	u8 Local_u8index=0;
	u32 Local_u32reminder,Local_u32NewNumber;
	do
	{
		Local_u32reminder = Copy_u32number % 10;
		Local_u32array[Local_u8index]=Local_u32reminder;
		Copy_u32number = Copy_u32number / 10;

		Local_u8index++;
	}while(Copy_u32number!=0);

	//Local_u8index--;
	while(Local_u8index!=0)
		{
			CLCD_voidSendData(Local_u32array[Local_u8index-1]+'0');
			Local_u8index--;
			//momken a3melha bel dereferencing
		}

}
