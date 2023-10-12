/****************************************************************/
/************** NAME : Eslam Osama Saad *************************/
/************** DATE : 31 / 03 / 2023   *************************/
/************** VERSION : 1.0 			*************************/
/************** SWC : GPIO 		*************************/
/****************************************************************/
#ifndef MGPIO_INTERFACE_H
#define MGPIO_INTERFACE_H

/************************/

/*enum for port*/
typedef enum{
	MGPIO_u8_GPIOA = 0,
	MGPIO_u8_GPIOB,
	MGPIO_u8_GPIOC,
}GPIONum_t;
/************************/

/*enum for pin numbers*/
typedef enum{
	MGPIO_u8_PIN0 = 0,
	MGPIO_u8_PIN1,
	MGPIO_u8_PIN2,
	MGPIO_u8_PIN3,
	MGPIO_u8_PIN4,
	MGPIO_u8_PIN5,
	MGPIO_u8_PIN6,
	MGPIO_u8_PIN7,
	MGPIO_u8_PIN8,
	MGPIO_u8_PIN9,
	MGPIO_u8_PIN10,
	MGPIO_u8_PIN11,
	MGPIO_u8_PIN12,
	MGPIO_u8_PIN13,
	MGPIO_u8_PIN14,
	MGPIO_u8_PIN15
}PinNum_t;

/************************/

/*Macros for pin mode*/
/*===================*/
/*INPUT*/
#define MGPIO_u8_INPUT_ANALOG 		0b0000
#define MGPIO_u8_INPUT_FLOATING 	0b0100
#define MGPIO_u8_INPUT_PULL_DOWN 	0b1000
#define MGPIO_u8_INPUT_PULL_UP 		0b11000//we just add extra 1 at MSB to differentiate between pull up and pull down

//================================================

/*OUTPUT*/
/*10MHZ*/
#define MGPIO_u8_OUTPUT_GP_PP_10MHZ 		0b0001
#define MGPIO_u8_OUTPUT_GP_OD_10MHZ 		0b0101
#define MGPIO_u8_OUTPUT_AF_PP_10MHZ 		0b1001
#define MGPIO_u8_OUTPUT_AF_OD_10MHZ 		0b1101

/*2MHZ*/
#define MGPIO_u8_OUTPUT_GP_PP_2MHZ 			0b0010
#define MGPIO_u8_OUTPUT_GP_OD_2MHZ 			0b0110
#define MGPIO_u8_OUTPUT_AF_PP_2MHZ 			0b1010
#define MGPIO_u8_OUTPUT_AF_OD_2MHZ 			0b1110

/*50MHZ*/
#define MGPIO_u8_OUTPUT_GP_PP_50MHZ 		0b0011
#define MGPIO_u8_OUTPUT_GP_OD_50MHZ 		0b0111
#define MGPIO_u8_OUTPUT_AF_PP_50MHZ 		0b1011
#define MGPIO_u8_OUTPUT_AF_OD_50MHZ 		0b1111

/************************/

/*macros for pin value*/
#define MGPIO_u8_HIGH	1
#define MGPIO_u8_LOW	0

/************************/

typedef struct{
	GPIONum_t 	portid;
	PinNum_t 	pinid;
	u8       	pinmode;
}MGPIO_PinConfig_t;

u8 MGPIO_u8_PinInit			(const MGPIO_PinConfig_t * copy_PstrPinConfig);

u8 MGPIO_u8_SetPinValue		(const MGPIO_PinConfig_t * copy_PstrPinConfig , u8 copy_u8_PinValue);

u8 MGPIO_u8_GetPinValue		(const MGPIO_PinConfig_t * copy_PstrPinConfig , u8 * copy_pu8_ReturnedPinValue);

u8 MGPIO_u8_TogglePinValue	(const MGPIO_PinConfig_t * copy_PstrPinConfig);

/************************/

#endif
