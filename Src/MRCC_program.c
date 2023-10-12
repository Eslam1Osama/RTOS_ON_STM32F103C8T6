/****************************************************************/
/************** NAME : Eslam Osama Saad *************************/
/************** DATE : 31 / 03 / 2023   *************************/
/************** VERSION : 1.0 			*************************/
/************** SWC : STM32F103XX 		*************************/
/****************************************************************/
/*1 - include which state in LIB layer*/
#include"LSTD_TYPES.h"
#include"LBIT_MATH.h"
#include"LSTM32F103C8.h"

/*2 - include which state in MCAL layer for RCC*/
#include"MRCC_interface.h"
#include"MRCC_config.h"
#include"MRCC_private.h"


u8 RCC_u8_InitSysClk(void)
{
	/*always do not forget to return error states*/
	u8 local_u8ErrorState = LSTD_TYPES_OK;
	/* enable the clk to be selected */
	/* select clk source 1- HSI , 2- HSE , 3- PLL */
#if(MRCC_u8_CLK_SYS == MRCC_u8_HSI)
	SET_BIT(MRCC->CR , 0);
	CLR_BIT(MRCC->CFGR , 0);
	CLR_BIT(MRCC->CFGR , 1);

#elif(MRCC_u8_CLK_SYS == MRCC_u8_HSE)
	SET_BIT(MRCC->CR , 16);
	SET_BIT(MRCC->CFGR , 0);
	CLR_BIT(MRCC->CFGR , 1);

#elif(MRCC_u8_CLK_SYS == MRCC_u8_PLL)
	SET_BIT(MRCC->CR , 24);
	CLR_BIT(MRCC->CFGR , 0);
	SET_BIT(MRCC->CFGR , 1);

#else
	#error "Wrong choice"
#endif

	return local_u8ErrorState;
}

u8 RCC_u8_EnablePeripheralClk(u8 copy_u8_PeripheralId)
{
	/*always do not forget to return error states*/
	u8 local_u8ErrorState = LSTD_TYPES_OK;

	if( (copy_u8_PeripheralId >= 0) && (copy_u8_PeripheralId <=  31) )
		SET_BIT(MRCC->AHBENR , copy_u8_PeripheralId);

	else if( (copy_u8_PeripheralId >= 32) && (copy_u8_PeripheralId <= 63) )
		SET_BIT(MRCC->APB2ENR , ( copy_u8_PeripheralId - 32 ) );

	else if( (copy_u8_PeripheralId >= 64) && (copy_u8_PeripheralId <= 95) )
		SET_BIT(MRCC->APB1ENR , ( copy_u8_PeripheralId - 64 ) );

	else
		local_u8ErrorState = LSTD_TYPES_NOK;
	return local_u8ErrorState;
}

u8 RCC_u8_DisablePeripheralClk(u8 copy_u8_PeripheralId)
{
	/*always do not forget to return error states*/
	u8 local_u8ErrorState = LSTD_TYPES_OK;

	if( (copy_u8_PeripheralId >= 0) && (copy_u8_PeripheralId <=  31) )
		CLR_BIT(MRCC->AHBENR , copy_u8_PeripheralId);

	else if( (copy_u8_PeripheralId >= 32) && (copy_u8_PeripheralId <= 63) )
		CLR_BIT(MRCC->APB2ENR , ( copy_u8_PeripheralId - 32 ) );

	else if( (copy_u8_PeripheralId >= 64) && (copy_u8_PeripheralId <= 95) )
		CLR_BIT(MRCC->APB1ENR , ( copy_u8_PeripheralId - 64 ) );

	else
		local_u8ErrorState = LSTD_TYPES_NOK;
	return local_u8ErrorState;
}
