/*
 * ThreadCDC.c
 *
 *  Created on: 25.05.2017
 *      Author: manni1user
 */

#include "FreeRTOS.h"
#include "task.h"
#include <stdbool.h>
#include "intersect/IntersectCDC.h"

#include "main.h"
#include "usbd_cdc_if.h"

static struct
{
	int counter_step1;
	int counter_step2;
	bool is_connected;
	bool is_bauded;
}stms_cdc
=
{
	0,
	0,
	false,
	false,
};

void ThreadCDC(void const * argument)
{
	bool step2 = true;

	UNUSED(argument);

	printf("\015\012starting");


	while (true)
	{
		int pcount = 1;
		if (stms_cdc.is_connected)
			pcount++;
		if (stms_cdc.is_bauded)
			pcount++;
		printf("\015\012loop");
		vTaskDelay(1800);
	}
}

void CBConnect(void)
{
	stms_cdc.is_connected = true;
	stms_cdc.is_bauded = false;
}
void CBDisconnect(void)
{
	stms_cdc.is_connected = false;
	stms_cdc.is_bauded = false;
}

void CBBaud(void)
{
	stms_cdc.is_bauded = true;
}

static unsigned char answer[] = "Hello\015\012";

void CBIncomming(void)
{
	CDC_Transmit_FS(answer, sizeof(answer));
	printf("\015\012printf");
}
