/*
 * ThreadDFSDM.c
 *
 *  Created on: 04.06.2017
 *      Author: manni1user
 */

#include "stm32f7xx_hal.h"
#include "dfsdm.h"
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "tim.h"
#include "ThreadDFSDM.h"

// dis optimized out
volatile static int16_t filter0_awd;
volatile static int32_t filter0_reg;
volatile static int16_t filter1_awd;
volatile static int32_t filter1_reg;
volatile static int16_t filter2_awd;
volatile static int32_t filter2_reg;
volatile static int16_t filter3_awd;
volatile static int32_t filter3_reg;

static void sign_extend(volatile int32_t *i)
{
	if((*i & 0X00800000) == 0X00800000 )
	{
		*i |= 0XFF000000;
	}
}
void ThreadDFSDM(void const * argument)
{
	UNUSED(argument);
	HAL_StatusTypeDef result;

	result = HAL_DFSDM_FilterRegularStart(&hdfsdm1_filter0);
	if (result != HAL_OK)
	{
		Error_Handler();
	}

	result = HAL_DFSDM_FilterRegularStart(&hdfsdm1_filter1);
	if (result != HAL_OK)
	{
		Error_Handler();
	}
	result = HAL_DFSDM_FilterRegularStart(&hdfsdm1_filter2);
	if (result != HAL_OK)
	{
		Error_Handler();
	}
	result = HAL_DFSDM_FilterRegularStart(&hdfsdm1_filter3);
	if (result != HAL_OK)
	{
		Error_Handler();
	}
	while (1)
	{
		uint32_t channel;

		filter0_awd = HAL_DFSDM_ChannelGetAwdValue(&hdfsdm1_channel0);
		filter0_reg = HAL_DFSDM_FilterGetRegularValue( &hdfsdm1_filter0, &channel );
		sign_extend(&filter0_reg);

		filter1_awd = HAL_DFSDM_ChannelGetAwdValue(&hdfsdm1_channel1);
		filter1_reg = HAL_DFSDM_FilterGetRegularValue( &hdfsdm1_filter1, &channel );
		sign_extend(&filter1_reg);

		filter2_awd = HAL_DFSDM_ChannelGetAwdValue(&hdfsdm1_channel2);
		filter2_reg = HAL_DFSDM_FilterGetRegularValue( &hdfsdm1_filter2, &channel );
		sign_extend(&filter2_reg);

		filter3_awd = HAL_DFSDM_ChannelGetAwdValue(&hdfsdm1_channel4);
		filter3_reg = HAL_DFSDM_FilterGetRegularValue( &hdfsdm1_filter3, &channel );
		sign_extend(&filter3_reg);

		vTaskDelay(50);
	}
}

void ReadCurrents(void)
{
	uint32_t channel;

	HAL_DFSDM_FilterGetRegularValue( &hdfsdm1_filter0, &channel );
	HAL_DFSDM_FilterGetRegularValue( &hdfsdm1_filter1, &channel );
	HAL_DFSDM_FilterGetRegularValue( &hdfsdm1_filter2, &channel );
	HAL_DFSDM_FilterGetRegularValue( &hdfsdm1_filter3, &channel );
}
