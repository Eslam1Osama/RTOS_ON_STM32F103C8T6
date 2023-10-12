/*1 - include which state in LIB layer*/
#include"LSTD_TYPES.h"
#include"LBIT_MATH.h"
#include"LSTM32F103C8.h"

/*2 - include what is relate to FreeRtos*/
#include "FREERTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"

/*3- include interface.h files of drivers used in this project*/
#include "MRCC_interface.h"
#include "MGPIO_interface.h"

/***************************************************************************************/

//extern void vApplicationStackOverflowHook( xTaskHandle *pxTask , signed portCHAR *pcTaskName);

//void vApplicationStackOverflowHook( xTaskHandle *pxTask __attribute((unused)) , signed portCHAR *pcTaskName __attribute((unused)) )
//{
//	for(;;);	// Loop forever here..
//}

/*tasks codes prototypes */
static void task1_code(void*pvParamter1);
static void task2_code(void*pvParamter1);
static void task3_code(void*pvParamter1);

/*3- set mode of pin13 at GPIOC -> ouput push pull 10mhz*/
static  MGPIO_PinConfig_t Local_StrLed1 = {MGPIO_u8_GPIOA , MGPIO_u8_PIN0 , MGPIO_u8_OUTPUT_GP_PP_10MHZ};
static  MGPIO_PinConfig_t Local_StrLed2 = {MGPIO_u8_GPIOC , MGPIO_u8_PIN15 , MGPIO_u8_OUTPUT_GP_PP_10MHZ};
static  MGPIO_PinConfig_t Local_StrLed3 = {MGPIO_u8_GPIOC , MGPIO_u8_PIN14 , MGPIO_u8_OUTPUT_GP_PP_10MHZ};
// MGPIO_PinConfig_t Local_StrLed4 = {MGPIO_u8_GPIOC , MGPIO_u8_PIN13 , MGPIO_u8_OUTPUT_GP_PP_10MHZ};

int main(void)
{
	/*intialize system clock*/
	RCC_u8_InitSysClk();

	/*2- enable perpheral clock of GPIOC*/
	RCC_u8_EnablePeripheralClk(34);
	RCC_u8_EnablePeripheralClk(36);

	/*then pass it to initialization function*/
	MGPIO_u8_PinInit(&Local_StrLed1);
	MGPIO_u8_PinInit(&Local_StrLed2);
	MGPIO_u8_PinInit(&Local_StrLed3);
	//MGPIO_u8_PinInit(&Local_StrLed4);

	/*Creat tasks*/
	xTaskCreate(task1_code , NULL , 100 , NULL , 1 , NULL);
	xTaskCreate(task2_code , NULL , 100 , NULL , 2 , NULL);
	xTaskCreate(task3_code , NULL , 100 , NULL , 3 , NULL);

	/*start Scheduler */
	vTaskStartScheduler();

    /* Loop forever */
	while(1){}
	return 0;
}

static void task1_code(void*pvParamter1)
{
	while(1)
	{
		MGPIO_u8_SetPinValue(&Local_StrLed1 , MGPIO_u8_HIGH);
		MGPIO_u8_SetPinValue(&Local_StrLed2 , MGPIO_u8_LOW);
		MGPIO_u8_SetPinValue(&Local_StrLed3 , MGPIO_u8_LOW);

		for(u32 Local_u16_Counter = 0 ; Local_u16_Counter < 1000000 ; Local_u16_Counter++)
		{
			__asm("NOP");
		}

	    vTaskDelay(pdMS_TO_TICKS(400));
	}
}

static void task2_code(void*pvParamter1)
{
	while(1)
	{
		MGPIO_u8_SetPinValue(&Local_StrLed1 , MGPIO_u8_LOW);
		MGPIO_u8_SetPinValue(&Local_StrLed2 , MGPIO_u8_HIGH);
		MGPIO_u8_SetPinValue(&Local_StrLed3 , MGPIO_u8_LOW);

		for(u32 Local_u16_Counter = 0 ; Local_u16_Counter < 1000000 ; Local_u16_Counter++)
		{
			__asm("NOP");
		}

		vTaskDelay(pdMS_TO_TICKS(400));
	}
}


static void task3_code(void*pvParamter1)
{
	while(1)
	{
		MGPIO_u8_SetPinValue(&Local_StrLed1 , MGPIO_u8_LOW);
		MGPIO_u8_SetPinValue(&Local_StrLed2 , MGPIO_u8_LOW);
		MGPIO_u8_SetPinValue(&Local_StrLed3 , MGPIO_u8_HIGH);

		for(u32 Local_u16_Counter = 0 ; Local_u16_Counter < 1000000 ; Local_u16_Counter++)
		{
			__asm("NOP");
		}

		vTaskDelay(pdMS_TO_TICKS(400));
	}
}

