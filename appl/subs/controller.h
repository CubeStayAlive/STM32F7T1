/*
 * controller.h
 *
 *  Created on: 16.07.2017
 *      Author: manni1user
 */

#ifndef SUBS_CONTROLLER_H_
#define SUBS_CONTROLLER_H_

typedef struct
{
	double pwm_resolution;
	doublle rot;
} Controller_para;

typedef struct
{
	double phi;
} Controller_in;

typedef struct
{
	double l1;
	double l2;
	double l3;
} Controller_out;

void Controller_init(Controller_para *para);
void Controller_calc(Controller_in *in, Controller_out *out);

#endif /* SUBS_CONTROLLER_H_ */
