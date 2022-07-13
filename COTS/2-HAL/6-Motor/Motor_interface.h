/*************************/
/*************************/
/**** Author:Alaa Osama **/
/**** Layer:HAL **********/
/**** SWC:Motor **********/
/**** Version:1.00 *******/
/**** Date:3-9-2020 ******/
/*************************/
/*************************/
 typedef struct{
	 u8 MOTOR_PORTPIN1;
	 u8 MOTOR_PIN1;
	 u8 MOTOR_PORTPIN2;
	 u8 MOTOR_PIN2;
 }MOTOR_STRUCT;

 void MOTOR_voidClockwise(MOTOR_STRUCT* Copy_MotorStruct);
 void MOTOR_voidAntiClockwise(MOTOR_STRUCT* Copy_MotorStruct);
 void MOTOR_voidOFF(MOTOR_STRUCT* Copy_MotorStruct);
