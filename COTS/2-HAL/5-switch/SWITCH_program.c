#include "STD_TYPES.h"

#include "DIO_interface.h"

#include "SWITCH_interface.h"
#include "SWITCH_config.h"
#include "SWITCH_private.h"

u8 SWITCH_u8GetState(SWITCH_STRUCT * Copy_pSwitchStruct)
{
	u8 Local_SwitchState;
	DIO_u8GetPinValue(Copy_pSwitchStruct->SWITCH_PORT,Copy_pSwitchStruct->SWITCH_PIN,& Local_SwitchState);

	if(Copy_pSwitchStruct->SWITCH_TYPE==PULL_UP)
	{
		if(Local_SwitchState==0)
		{
			while(Local_SwitchState==0)
			{
				DIO_u8GetPinValue(Copy_pSwitchStruct->SWITCH_PORT,Copy_pSwitchStruct->SWITCH_PIN,& Local_SwitchState);
			}
			return PRESSED;
		}
	}
	else if(Copy_pSwitchStruct->SWITCH_TYPE==PULL_DOWN)
	{
		if(Local_SwitchState==1)
				{
					while(Local_SwitchState==1)
					{
						DIO_u8GetPinValue(Copy_pSwitchStruct->SWITCH_PORT,Copy_pSwitchStruct->SWITCH_PIN,& Local_SwitchState);
					}
					return PRESSED;
				}
	}

	return NOT_PRESSED;
}
