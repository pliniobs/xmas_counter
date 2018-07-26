/*
 * matrix_display.c
 *
 *  Created on: 26 de jul de 2018
 *      Author: plinio
 */

#include "stm32f4xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "matrix_display.h"

SPI_HandleTypeDef hspi2;

void vTask_Matrix_Display(void *pvParameters)
{
	Matrix_Display_Init();

	while(1)
	{
		Matrix_Display_Write(0xAA, 0x55);
		vTaskDelay(25/ portTICK_PERIOD_MS);
	}
}

void Matrix_Display_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	__HAL_RCC_SPI2_CLK_ENABLE();

	/**SPI2 GPIO Configuration
	     PB13     ------> SPI2_SCK
	     PB14     ------> SPI2_MISO
	     PB15     ------> SPI2_MOSI
	 */
	GPIO_InitStruct.Pin = GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);


	/* SPI2 parameter configuration*/
	hspi2.Instance = SPI2;
	hspi2.Init.Mode = SPI_MODE_MASTER;
	hspi2.Init.Direction = SPI_DIRECTION_2LINES;
	hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
	hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
	hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
	hspi2.Init.NSS = SPI_NSS_SOFT;
	hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
	hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
	hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
	hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
	hspi2.Init.CRCPolynomial = 10;

	if (HAL_SPI_Init(&hspi2) != HAL_OK)
	{
		asm("BKPT 255");
	}
}

void Matrix_Display_Write(uint8_t address, uint8_t data)
{
	uint8_t TXBuffer[2];

	TXBuffer[0] = address;
	TXBuffer[1] = data;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
	if(HAL_SPI_Transmit(&hspi2, TXBuffer, 2, 10) != HAL_OK)
	{
		asm("BKPT 255");
	}
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
}
