/*
 * ThreadBlinky.c
 *
 *  Created on: 06.05.2017
 *      Author: manni1user
 */
#include "intersect/DefaultTask.h"
#include "stm32f7xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"

void ThreadBlinky(void const * argument)
{
	UNUSED(argument);
	while (1)
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
		vTaskDelay(200);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_SET);
		vTaskDelay(200);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
		vTaskDelay(200);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
		vTaskDelay(200);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, GPIO_PIN_RESET);
		vTaskDelay(200);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
		vTaskDelay(200);
	}
}
