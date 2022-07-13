#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "MOTOR_interface.h"
#include "MOTOR_private.h"
#include "MOTOR_config.h"

void MOTOR_voidClockwise(MOTOR_STRUCT* Copy_MotorStruct)
{
	DIO_u8SetPinValue(Copy_MotorStruct->MOTOR_PORTPIN1,Copy_MotorStruct->MOTOR_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_MotorStruct->MOTOR_PORTPIN2,Copy_MotorStruct->MOTOR_PIN2,DIO_u8PIN_HIGH);
}

void MOTOR_voidAntiClockwise(MOTOR_STRUCT* Copy_MotorStruct)
{
	DIO_u8SetPinValue(Copy_MotorStruct->MOTOR_PORTPIN2,Copy_MotorStruct->MOTOR_PIN2,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_MotorStruct->MOTOR_PORTPIN1,Copy_MotorStruct->MOTOR_PIN1,DIO_u8PIN_HIGH);
}

void MOTOR_voidOFF(MOTOR_STRUCT* Copy_MotorStruct)
{
	DIO_u8SetPinValue(Copy_MotorStruct->MOTOR_PORTPIN1,Copy_MotorStruct->MOTOR_PIN1,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(Copy_MotorStruct->MOTOR_PORTPIN2,Copy_MotorStruct->MOTOR_PIN2,DIO_u8PIN_LOW);
}
