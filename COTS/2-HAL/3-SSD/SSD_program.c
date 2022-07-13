/*************************/
/*************************/
/**** Author:Alaa Osama **/
/**** Layer:HAL **********/
/**** SWC:SSD ************/
/**** Version:1.00 *******/
/**** Date:2-9-2020 ******/
/*************************/
/*************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "SSD_config.h"
#include "SSD_interface.h"
#include "SSD_private.h"


void SSD_voidSetNumber(SSD_struct *Copy_pSSDStruct, u8 Copy_Number)
{
	//static to be saved in dot data not in the stack which is small and also will waste time while saving this array each time this function is called.
	u8 static Local_u8SSDArr[10]= {0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111101,0b00000111,0b01111111,0b01101111};

	DIO_u8SetPinValue(Copy_pSSDStruct->ENABLE_PORT,Copy_pSSDStruct->ENABLE_PIN,Copy_pSSDStruct->SSD_TYPE);

	if (Copy_pSSDStruct->SSD_TYPE==ANODE)
	{
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINDOT,Copy_pSSDStruct->SSD_PINDOT,~ GET_BIT(Local_u8SSDArr[Copy_Number],7));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPING,Copy_pSSDStruct->SSD_PING,~ GET_BIT(Local_u8SSDArr[Copy_Number],6));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINF,Copy_pSSDStruct->SSD_PINF,~ GET_BIT(Local_u8SSDArr[Copy_Number],5));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINE,Copy_pSSDStruct->SSD_PINE,~ GET_BIT(Local_u8SSDArr[Copy_Number],4));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPIND,Copy_pSSDStruct->SSD_PIND,~ GET_BIT(Local_u8SSDArr[Copy_Number],3));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINC,Copy_pSSDStruct->SSD_PINC,~ GET_BIT(Local_u8SSDArr[Copy_Number],2));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINB,Copy_pSSDStruct->SSD_PINB,~ GET_BIT(Local_u8SSDArr[Copy_Number],1));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINA,Copy_pSSDStruct->SSD_PINA,~ GET_BIT(Local_u8SSDArr[Copy_Number],0));
	}
	else if(Copy_pSSDStruct->SSD_TYPE==CATHOD)
	{
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINDOT,Copy_pSSDStruct->SSD_PINDOT,GET_BIT(Local_u8SSDArr[Copy_Number],7));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPING,Copy_pSSDStruct->SSD_PING,GET_BIT(Local_u8SSDArr[Copy_Number],6));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINF,Copy_pSSDStruct->SSD_PINF,GET_BIT(Local_u8SSDArr[Copy_Number],5));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINE,Copy_pSSDStruct->SSD_PINE,GET_BIT(Local_u8SSDArr[Copy_Number],4));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPIND,Copy_pSSDStruct->SSD_PIND,GET_BIT(Local_u8SSDArr[Copy_Number],3));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINC,Copy_pSSDStruct->SSD_PINC,GET_BIT(Local_u8SSDArr[Copy_Number],2));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINB,Copy_pSSDStruct->SSD_PINB,GET_BIT(Local_u8SSDArr[Copy_Number],1));
		DIO_u8SetPinValue(Copy_pSSDStruct->SSD_PORTPINA,Copy_pSSDStruct->SSD_PINA,GET_BIT(Local_u8SSDArr[Copy_Number],0));
	}
}
