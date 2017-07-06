/*
 * flag.c
 *
 *  Created on: 06.07.2017
 *      Author: manni1user
 */

#include "subs/flag.h"
#include "stm32f7xx_hal.h"


void flag_init(void)
{
	HAL_GPIO_TogglePin(GPIOE,GPIO_PIN_5 );
}
