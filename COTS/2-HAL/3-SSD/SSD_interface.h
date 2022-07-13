/*************************/
/*************************/
/**** Author:Alaa Osama **/
/**** Layer:HAL **********/
/**** SWC:SSD ************/
/**** Version:1.00 *******/
/**** Date:2-9-2020 ******/
/*************************/
/*************************/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


#define ANODE       1
#define CATHOD      0

typedef struct
{
	u8 SSD_PORTPINA;

	u8 SSD_PINA;
	u8 SSD_PORTPINB;
	u8 SSD_PINB;
	u8 SSD_PORTPINC;
	u8 SSD_PINC;
	u8 SSD_PORTPIND;
	u8 SSD_PIND;
	u8 SSD_PORTPINE;
	u8 SSD_PINE;
	u8 SSD_PORTPINF;
	u8 SSD_PINF;
	u8 SSD_PORTPING;
	u8 SSD_PING;
	u8 SSD_PORTPINDOT;
	u8 SSD_PINDOT;

	u8 SSD_TYPE;

	u8 ENABLE_PORT;//For Common

	u8 ENABLE_PIN;
}SSD_struct;

void SSD_voidSetNumber(SSD_struct * Copy_pSSDStruct, u8 Copy_Number);

#endif
