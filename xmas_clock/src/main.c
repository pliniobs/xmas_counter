#include "stm32f4xx_hal.h"
#include "CPU_F401.h"
#include "FreeRTOS.h"
#include "task.h"
#include "matrix_display.h"

void vTask_LED_Blink(void *pvParameters);

int main(void)
{
	BaseType_t Task_Create_Result;

	HAL_Init();

	CPU_Set_HSI_84MHz();

	HAL_InitTick(0);

	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();

	/* create task */
	Task_Create_Result = xTaskCreate(vTask_LED_Blink,						/* Pointer to the task entry function */
			"vTask_LED_Blink",						/* A descriptive name for the task */
			configMINIMAL_STACK_SIZE,				/* The number of words (not bytes!) to allocate for use as the task's stack */
			(void *)NULL,							/* A value that will passed into the created task as the task's parameter */
			1,										/* The priority at which the created task will execute */
			NULL);									/* Used to pass a handle to the created task out of the xTaskCreate() function.*/

	if( Task_Create_Result != pdPASS )
	{
		while(1); // Falha ao criar a tarefa
	}

	/* create task */
	Task_Create_Result = xTaskCreate(vTask_Matrix_Display,						/* Pointer to the task entry function */
			"vTask_Matrix_Display",					/* A descriptive name for the task */
			configMINIMAL_STACK_SIZE,				/* The number of words (not bytes!) to allocate for use as the task's stack */
			(void *)NULL,							/* A value that will passed into the created task as the task's parameter */
			1,										/* The priority at which the created task will execute */
			NULL);									/* Used to pass a handle to the created task out of the xTaskCreate() function.*/

	if( Task_Create_Result != pdPASS )
	{
		while(1); // Falha ao criar a tarefa
	}

	/* start the scheduler */
	vTaskStartScheduler();

	/* should never reach here! */
	for(;;);

}

void vTask_LED_Blink(void *pvParameters)
{
	GPIO_InitTypeDef LED_Config;

	LED_Config.Mode = GPIO_MODE_OUTPUT_PP;
	LED_Config.Pull = GPIO_NOPULL;
	LED_Config.Speed = GPIO_SPEED_HIGH;
	LED_Config.Pin = GPIO_PIN_5;
	HAL_GPIO_Init(GPIOA, &LED_Config);

	while(1)
	{
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		vTaskDelay(25/ portTICK_PERIOD_MS);
	}
}


