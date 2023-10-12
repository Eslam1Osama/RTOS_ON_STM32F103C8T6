/****************************************************************/
/************** NAME : Eslam Osama Saad *************************/
/************** DATE : 31 / 03 / 2023   *************************/
/************** VERSION : 1.0 			*************************/
/************** SWC : STM32F103XX 		*************************/
/****************************************************************/
#ifndef LSTM32F103C8_H
#define LSTM32F103C8_H

/****************************************************************/
/************** RCC REGISTERS DEFINATION ************************/
/****************************************************************/

#define MRCC_u32_BASE_ADRRESS		0X40021000

typedef struct{
	volatile u32 CR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 APB2RSTR;
	volatile u32 APB1RSTR;
	volatile u32 AHBENR;
	volatile u32 APB2ENR;
	volatile u32 APB1ENR;
	volatile u32 BDCR;
	volatile u32 CSR;
}MRCC_u32_RegDef_t;//_t means type

#define MRCC			( ( MRCC_u32_RegDef_t* ) MRCC_u32_BASE_ADRRESS )

/****************************************************************/
/************** GPIO REGISTERS DEFINATION ***********************/
/****************************************************************/

#define GPIO_u32_GPIOA_BASE_ADRRESS		0X40010800U
#define GPIO_u32_GPIOB_BASE_ADRRESS		0X40010C00U
#define GPIO_u32_GPIOC_BASE_ADRRESS		0X40011000U

typedef struct{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_u32_RegDef_t;//_t means type

#define GPIOA			( ( GPIO_u32_RegDef_t* ) GPIO_u32_GPIOA_BASE_ADRRESS )
#define GPIOB		    ( ( GPIO_u32_RegDef_t* ) GPIO_u32_GPIOB_BASE_ADRRESS )
#define GPIOC			( ( GPIO_u32_RegDef_t* ) GPIO_u32_GPIOC_BASE_ADRRESS )

/****************************************************************/
#endif
