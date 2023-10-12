#ifndef FREERTOSCONFIG_H_
#define FREERTOSCONFIG_H_


#define configCPU_CLOCK_HZ							72000000UL
#define configUSE_TICKLESS_IDLE						0
#define configSYSTICK_CLOCK_HZ						( configCPU_CLOCK_HZ / 8 ) /* vTaskDelay() fix */
#define configTICK_RATE_HZ							( ( TickType_t ) 250 )
#define configUSE_PREEMPTION        				1
#define configUSE_IDLE_HOOK         				0
#define configUSE_TICK_HOOK         				0
#define configMAX_PRIORITIES        				(5)	//system priorities are from 0-4 and 4 is the highest
#define configMINIMAL_STACK_SIZE    				( ( unsigned short ) 128 )
#define configTOTAL_HEAP_SIZE       				( ( size_t ) ( 17 * 1024 ) )
#define configMAX_TASK_NAME_LEN     				(16)
#define configUSE_16_BIT_TICKS      				0	//for 16-bit or 8-bit machines put this 1


/*Interrupts priorties used by the kernel port layer itself. these are generic
  to all cortex_M ports, and do not rely on any particular library functions*/
#define configKERNEL_INTERRUPT_PRIORITY				( 7 << 5 )		/*priority 7, or 0xE0 as only the top 3 bits are implemented.
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  	  	  this is the lowest priority. */
/********************************************************************************************************************************/

#define configMAX_SYSCALL_INTERRUPT_PRIORITY		( 5 << 5 )		/*priority 5, or 0xA0 as only the top 3 bits are implemented*/
/*means if we are entering a critical section disable interrupts starting from priority 5*/


/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskPrioritySet		0
#define INCLUDE_uxTaskPriorityGet		0
#define INCLUDE_vTaskDelete				0
#define INCLUDE_vTaskCleanUpResources	0
#define INCLUDE_vTaskSuspend			0
#define INCLUDE_vTaskDelayUntil			0
#define INCLUDE_vTaskDelay				1
/********************************************************************************************************************************/

#endif /* FREERTOSCONFIG_H_ */



