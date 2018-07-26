/*
 * cpu_f401.h
 *
 *  Created on: 21 de mai de 2018
 *      Author: PLínio Barbosa da Silva
 */

#ifndef CPU_F401_H_
#define CPU_F401_H_

/**
 * @brief  Initialize the microcontroller STM32F401 clock to 84MHz.
 * @retval None
 * @note The bus clock follow this scheme
 *   +---------------------------------------+-------------+
 *   |              Peripheral               | Clock Speed |
 *   +---------------------------------------+-------------+
 *   | HCLK to AHB bus, core, memory and DMA | 84MHz       |
 *   | Cortex System Timer                   | 84MHz       |
 *   | FCLK Cortex Clock                     | 84MHz       |
 *   | APB1 Peripheral Clock                 | 42MHz       |
 *   | APB1 Timer Clock                      | 84MHz       |
 *   | APB2 Peripheral Clock                 | 84MHz       |
 *   | APB2 Timer Clock                      | 84MHz       |
 *   +---------------------------------------+-------------+
 */
void CPU_Set_HSI_84MHz(void);

/**
 * @brief  Initialize the microcontroller STM32F401 clock to 16MHz.
 * @retval None
 * @note The bus clock follow this scheme
 *   +---------------------------------------+-------------+
 *   |              Peripheral               | Clock Speed |
 *   +---------------------------------------+-------------+
 *   | HCLK to AHB bus, core, memory and DMA | 16MHz       |
 *   | Cortex System Timer                   | 16MHz       |
 *   | FCLK Cortex Clock                     | 16MHz       |
 *   | APB1 Peripheral Clock                 | 16MHz       |
 *   | APB1 Timer Clock                      | 16MHz       |
 *   | APB2 Peripheral Clock                 | 16MHz       |
 *   | APB2 Timer Clock                      | 16MHz       |
 *   +---------------------------------------+-------------+
 */
void CPU_Set_HSI_16MHz(void);

/**
  * @brief  This function configures the TIM11 as a time base source.
  *         The time source is configured  to have 1ms time base with a dedicated
  *         Tick interrupt priority.
  * @note   This function is called  automatically at the beginning of program after
  *         reset by HAL_Init() or at any time when clock is configured, by HAL_RCC_ClockConfig().
  * @param  TickPriority: Tick interrupt priorty.
  * @retval HAL status
  */
HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority);

#endif /* CPU_F401_H_ */
