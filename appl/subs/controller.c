/*
 * controller.c
 *
 *  Created on: 16.07.2017
 *      Author: manni1user
 */

#include "subs/controller.h"
#include <math.h>

static Controller_para *hpara;

void Controller_init(Controller_para *para, Controller_in *in)
{
	hpara = para; // copy only pointer ???
	para->rot = .0001;
	in->phi = 0.0f;

	para -> pf = para-> pwm_resolution * 0.5;
	para -> po = para-> pwm_resolution * 0.5;
}

void Controller_calc(Controller_in *in, Controller_out *out)
{
	in->phi += hpara->rot;
	if (in->phi > (2.0 * M_PI))
		in->phi -= (2.0 * M_PI);
	out -> l1 = sin(in->phi) * hpara-> pf + hpara-> po;
	out -> l2 = sin(in->phi+(M_PI*2.0/3.0)) * hpara-> pf + hpara-> po;
	out -> l3 = sin(in->phi+(M_PI*4.0/3.0)) * hpara-> pf + hpara-> po;
}


