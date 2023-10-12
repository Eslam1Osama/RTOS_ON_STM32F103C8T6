/****************************************************************/
/************** NAME : Eslam Osama Saad *************************/
/************** DATE : 31 / 03 / 2023   *************************/
/************** VERSION : 1.0 			*************************/
/************** SWC : GPIO 		        *************************/
/****************************************************************/
/*1 - include which state in LIB layer*/
#include"LSTD_TYPES.h"
#include"LBIT_MATH.h"
#include"LSTM32F103C8.h"

/*2 - include which state in MCAL layer for GPIO*/
#include"MGPIO_interface.h"
#include"MGPIO_config.h"
#include"MGPIO_private.h"

/************************/
/*for port*/
GPIO_u32_RegDef_t * GPIO_APSTR[3] = {GPIOA , GPIOB , GPIOC};// APSTR-> shortcut of array of pointer to structures
/************************/

u8 MGPIO_u8_PinInit			(const MGPIO_PinConfig_t * copy_PstrPinConfig)
{
	u8 local_u8_ErrorState = LSTD_TYPES_OK;
	u8 local_u8_PinMode;
	/*check if pointer is wild pointer*/
	if(copy_PstrPinConfig != NULL)
	{
		if( copy_PstrPinConfig->portid <= MGPIO_u8_GPIOC )
		{
			local_u8_PinMode = copy_PstrPinConfig->pinmode;

			/*check if the mode is pulled up*/
			if(local_u8_PinMode == MGPIO_u8_INPUT_PULL_UP)
			{
				/*Set ODR register*/
				SET_BIT(GPIO_APSTR[copy_PstrPinConfig->portid]->ODR , copy_PstrPinConfig->pinid);

				/*modifiy pin mode*/
				CLR_BIT(local_u8_PinMode , 4);
			}
			else if(local_u8_PinMode == MGPIO_u8_INPUT_PULL_DOWN)
			{
				/*Set ODR register*/
				CLR_BIT(GPIO_APSTR[copy_PstrPinConfig->portid]->ODR , copy_PstrPinConfig->pinid);
			}
			/*set mode of pin at 4 bits CRL or CRH*/
			if(copy_PstrPinConfig->pinid <= MGPIO_u8_PIN7)
			{
				/*1- clear 4 bits related to pin targeted*/
				//GPIO_APSTR[copy_PstrPinConfig->portid]->CRL &= ~( (0X0000000F << (copy_PstrPinConfig->pinid * 4) ) );
				GPIO_APSTR[copy_PstrPinConfig->portid]->CRL &= ( (~(0b1111)) << (copy_PstrPinConfig->pinid * 4) );

				/*2- set mode in desired 4 bits targeted which related to pin number*/
				GPIO_APSTR[copy_PstrPinConfig->portid]->CRL |= (local_u8_PinMode << (copy_PstrPinConfig->pinid * 4) );
			}
			else if( (copy_PstrPinConfig->pinid >= MGPIO_u8_PIN8) && (copy_PstrPinConfig->pinid <= MGPIO_u8_PIN15) )
			{
				/*1- clear 4 bits related to pin targeted*/
				//GPIO_APSTR[copy_PstrPinConfig->portid]->CRH &= ~( (0X0000000F << ( (copy_PstrPinConfig->pinid - 8) * 4) ) );
				GPIO_APSTR[copy_PstrPinConfig->portid]->CRH &= ( (~(0b1111)) << ( (copy_PstrPinConfig->pinid - 8) * 4) );

				/*2- set mode in desired 4 bits targeted which related to pin number*/
				GPIO_APSTR[copy_PstrPinConfig->portid]->CRH |= (local_u8_PinMode << ( (copy_PstrPinConfig->pinid - 8) * 4) );
			}
			else
			{
				local_u8_ErrorState = LSTD_TYPES_NOK;
			}
		}
		else
		{
			local_u8_ErrorState = LSTD_TYPES_NOK;
		}
	}
	else
	{
		local_u8_ErrorState = LSTD_TYPES_NOK;
	}
	return local_u8_ErrorState;
}

u8 MGPIO_u8_SetPinValue		(const MGPIO_PinConfig_t * copy_PstrPinConfig , u8 copy_u8_PinValue)
{
	u8 local_u8_ErrorState = LSTD_TYPES_OK;
	if(copy_PstrPinConfig != NULL)
	{
		switch(copy_u8_PinValue)
		{
		case MGPIO_u8_HIGH: GPIO_APSTR[copy_PstrPinConfig->portid]->BSRR = ( 1 << (copy_PstrPinConfig->pinid) ); break;
		case MGPIO_u8_LOW: GPIO_APSTR[copy_PstrPinConfig->portid]->BRR   = ( 1 << (copy_PstrPinConfig->pinid) ); break;
		default: local_u8_ErrorState =  LSTD_TYPES_NOK;
		}
	}
	else
	{
		local_u8_ErrorState = LSTD_TYPES_NOK;
	}
	return local_u8_ErrorState;
}

u8 MGPIO_u8_GetPinValue		(const MGPIO_PinConfig_t * copy_PstrPinConfig , u8 * copy_pu8_ReturnedPinValue)
{
	u8 local_u8_ErrorState = LSTD_TYPES_OK;
	if( (copy_PstrPinConfig != NULL) && (copy_pu8_ReturnedPinValue!= NULL) )
	{
		*copy_pu8_ReturnedPinValue = GET_BIT(GPIO_APSTR[copy_PstrPinConfig->pinid]->IDR , copy_PstrPinConfig->pinid);
	}
	else
	{
		local_u8_ErrorState = LSTD_TYPES_NOK;
	}
	return local_u8_ErrorState;
}

u8 MGPIO_u8_TogglePinValue	(const MGPIO_PinConfig_t * copy_PstrPinConfig)
{
	u8 local_u8_ErrorState = LSTD_TYPES_OK;
	if(copy_PstrPinConfig != NULL)
	{
		TOG_BIT(GPIO_APSTR[copy_PstrPinConfig->pinid]->ODR , copy_PstrPinConfig->pinid);
	}
	else
	{
		local_u8_ErrorState = LSTD_TYPES_NOK;
	}
	return local_u8_ErrorState;
}
