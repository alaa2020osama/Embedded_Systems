/*************************/
/*************************/
/**** Author:Alaa Osama **/
/**** Layer:HAL **********/
/**** SWC:switch *********/
/**** Version:1.00 *******/
/**** Date:2-9-2020 ******/
/*************************/
/*************************/

#define PULL_UP        0
#define PULL_DOWN      1

#define PRESSED        1
#define NOT_PRESSED    0

typedef struct
{
	u8 SWITCH_TYPE;
	u8 SWITCH_PORT;
	u8 SWITCH_PIN;
}SWITCH_STRUCT;

u8 SWITCH_u8GetState(SWITCH_STRUCT * Copy_pSwitchStruct);
