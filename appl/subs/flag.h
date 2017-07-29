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
#define FLAG_C_TOGGLE HAL_GPIO_TogglePin(FLAG_B_GPIO_Port,FLAG_B_Pin)
#define FLAG_D_TOGGLE HAL_GPIO_TogglePin(FLAG_B_GPIO_Port,FLAG_B_Pin)

#define FLAG_A_SET    FLAG_A_GPIO_Port->BSRR = FLAG_A_Pin;
#define FLAG_B_SET    FLAG_B_GPIO_Port->BSRR = FLAG_B_Pin;
#define FLAG_C_SET    FLAG_C_GPIO_Port->BSRR = FLAG_C_Pin;
#define FLAG_D_SET    FLAG_D_GPIO_Port->BSRR = FLAG_D_Pin;

#define FLAG_A_CLR    FLAG_A_GPIO_Port->BSRR = FLAG_A_Pin<<16;
#define FLAG_B_CLR    FLAG_B_GPIO_Port->BSRR = FLAG_B_Pin<<16;
#define FLAG_C_CLR    FLAG_C_GPIO_Port->BSRR = FLAG_C_Pin<<16;
#define FLAG_D_CLR    FLAG_D_GPIO_Port->BSRR = FLAG_D_Pin<<16;






#define FLAG_LOOP_PWM 				;
#define FLAG_TIM1_UPDATE      		FLAG_A_TOGGLE;

#define FLAG_DFSDM_READ_START       FLAG_B_CLR
#define FLAG_DFSDM_READ_END         FLAG_B_SET

#define FLAG_TIM3_UPDATE 			;
#define FLAG_TIM1_OC4    			;
#define FLAG_CONTROLLER_START 		FLAG_C_CLR
#define FLAG_CONTROLLER_END  		FLAG_C_SET

#endif /* SUBS_FLAG_H_ */
