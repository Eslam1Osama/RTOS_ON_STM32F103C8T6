/****************************************************************/
/************** NAME : Eslam Osama Saad *************************/
/************** DATE : 31 / 03 / 2023   *************************/
/************** VERSION : 1.0 			*************************/
/************** SWC : STM32F103XX 		*************************/
/****************************************************************/
#ifndef MRCC_INTERFACE_H
#define MRCC_INTERFACE_H

u8 RCC_u8_InitSysClk(void);

u8 RCC_u8_EnablePeripheralClk(u8 copy_u8_PeripheralId);

u8 RCC_u8_DisablePeripheralClk(u8 copy_u8_PeripheralId);

#endif