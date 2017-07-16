/*
 * controller.h
 *
 *  Created on: 16.07.2017
 *      Author: manni1user
 */

#ifndef SUBS_CONTROLLER_H_
#define SUBS_CONTROLLER_H_

//typedef double maths;
typedef float maths;

typedef struct
{
	maths pwm_resolution;
	maths rot;
	maths pf;
	maths po;
} Controller_para;

typedef struct
{
	maths phi;
} Controller_in;

typedef struct
{
	maths l1;
	maths l2;
	maths l3;
} Controller_out;

void Controller_init(Controller_para *para, Controller_in *in);
void Controller_calc(Controller_in *in, Controller_out *out);

#endif /* SUBS_CONTROLLER_H_ */
