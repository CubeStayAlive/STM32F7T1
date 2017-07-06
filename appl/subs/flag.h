/*
 * flag.h
 *
 *  Created on: 06.07.2017
 *      Author: manni1user
 */

#ifndef SUBS_FLAG_H_
#define SUBS_FLAG_H_

#include "main.h"

#define FLAG_A_TOGGLE HAL_GPIO_TogglePin(FLAG_A_GPIO_Port,FLAG_A_Pin)
#define FLAG_B_TOGGLE HAL_GPIO_TogglePin(FLAG_B_GPIO_Port,FLAG_B_Pin)


#define FLAG_LOOP_PWM ;
#define FLAG_TIM1_UPDATE ;
#define FLAG_TIM3_UPDATE FLAG_B_TOGGLE
#define FLAG_TIM1_OC4    FLAG_A_TOGGLE;

#endif /* SUBS_FLAG_H_ */
