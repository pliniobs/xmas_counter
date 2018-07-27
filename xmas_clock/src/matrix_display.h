/*
 * matrix_display.h
 *
 *  Created on: 26 de jul de 2018
 *      Author: plinio
 */

#ifndef MATRIX_DISPLAY_H_
#define MATRIX_DISPLAY_H_

#include "stm32f4xx_hal.h"

#define OP_NOOP   0
#define OP_DIGIT0 1
#define OP_DIGIT1 2
#define OP_DIGIT2 3
#define OP_DIGIT3 4
#define OP_DIGIT4 5
#define OP_DIGIT5 6
#define OP_DIGIT6 7
#define OP_DIGIT7 8
#define OP_DECODEMODE  9
#define OP_INTENSITY   10
#define OP_SCANLIMIT   11
#define OP_SHUTDOWN    12
#define OP_DISPLAYTEST 15


void vTask_Matrix_Display(void *pvParameters);

void Matrix_Display_Init(void);

void Matrix_Display_Write(uint8_t address, uint8_t data);

void Cpy_Font_To_Buffer(uint8_t Caracter, uint8_t *Buffer, uint16_t Position);

#endif /* MATRIX_DISPLAY_H_ */
