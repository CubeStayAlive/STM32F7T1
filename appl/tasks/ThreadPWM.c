/*
 * ThreadPWM.c
 *
 *  Created on: 05.07.2017
 *      Author: manni1user
 */

#include <stdbool.h>
#include "stm32f7xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "tim.h"
#include "subs/flag.h"
#include "intersect/event.h"
#include "subs/controller.h"
#include <math.h>

#include "ThreadDFSDM.h"

Controller_para cpara;
Controller_in cin;
Controller_out cout;


#define ROT_FREQ 1.0

void ThreadPWM(void const * argument)
{
	UNUSED(argument);
	HAL_StatusTypeDef result;

	cpara.pwm_resolution = 5000;
	cpara.rot = ROT_FREQ / 10000.0 / 2.0 * M_PI;

	Controller_init(&cpara, &cin);

	result = HAL_TIM_Base_Start_IT(&htim1);
	if (result != HAL_OK)
	{
		Error_Handler();
	}

	result = HAL_TIM_Base_Start_IT(&htim3);
	if (result != HAL_OK)
	{
		Error_Handler();
	}

	result = HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	if (result != HAL_OK)
	{
		Error_Handler();
	}

	result = HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_1);
	if (result != HAL_OK)
	{
		Error_Handler();
	}

	result = HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_2);
	if (result != HAL_OK)
	{
		Error_Handler();
	}

	result = HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_2);
	if (result != HAL_OK)
	{
		Error_Handler();
	}

	result = HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_3);
	if (result != HAL_OK)
	{
		Error_Handler();
	}

	result = HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
	if (result != HAL_OK)
	{
		Error_Handler();
	}


	result = HAL_TIM_OC_Start_IT(&htim1, TIM_CHANNEL_4);
	if (result != HAL_OK)
	{
		Error_Handler();
	}

	while (true)
	{
		FLAG_LOOP_PWM;
		vTaskDelay(20);
	}
}

void interrupt_tim1_update(TIM_HandleTypeDef *htim)
{
	FLAG_TIM1_UPDATE
	;
}

Controller_para cpara;
Controller_in cin;
Controller_out cout;

typedef double mt;
mt phi = 0.0;
mt rot = .0001;

void interrupt_tim3_update(TIM_HandleTypeDef *htim)
{
	FLAG_CONTROLLER_START;
	{
		Controller_calc(&cin, &cout);

		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, (int)cout.l1);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, (int)cout.l2);
		__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, (int)cout.l3);
	}
	FLAG_CONTROLLER_END;
	FLAG_TIM3_UPDATE;
}

// overwrite weak
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim)
//void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM1)
	{
		FLAG_DFSDM_READ_START;
		ReadCurrents();
		FLAG_DFSDM_READ_END;
	}
}

