/*
 * matrix_display.h
 *
 *  Created on: 26 de jul de 2018
 *      Author: plinio
 */

#ifndef MATRIX_DISPLAY_H_
#define MATRIX_DISPLAY_H_

#include "stm32f4xx_hal.h"

void vTask_Matrix_Display(void *pvParameters);

void Matrix_Display_Init(void);

void Matrix_Display_Write(uint8_t address, uint8_t data);

#endif /* MATRIX_DISPLAY_H_ */
