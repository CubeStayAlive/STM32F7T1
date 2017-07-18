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
	//para->rot = .0001;
	in->phi = 0.0f;

	para -> pf = para-> pwm_resolution * 0.5;
	para -> po = para-> pwm_resolution * 0.5;
}
static const float F_2PHI = 2.0 * M_PI;
static const float F_2D3_PHI = 2.0 / 3.0 * M_PI;
static const float F_4D3_PHI = 4.0 / 3.0 * M_PI;
//static const float F_Q3D2 = sqrt(3.0) / 2.0;
static const float F_Q3D2 = 0.866025404f;


void Controller_calca(Controller_in *in, Controller_out *out)
{
	in->phi += hpara->rot;
	if (in->phi > F_2PHI)
		in->phi -= F_2PHI;
	out -> l1 = VSIN(in->phi) * hpara-> pf + hpara-> po;
	out -> l2 = VSIN(in->phi+F_2D3_PHI) * hpara-> pf + hpara-> po;
	out -> l3 = VSIN(in->phi+F_4D3_PHI) * hpara-> pf + hpara-> po;
}
void Controller_calc(Controller_in *in, Controller_out *out)
{
	in->phi += hpara->rot;
	if (in->phi > F_2PHI)
		in->phi -= F_2PHI;
	{
		maths h1, h2, h3, h4, h5;
		sincosf(in->phi, &h1, &h4);
		h5 = scalbnf(h1,-1);
		h4 *= - F_Q3D2;
		h2 = h5 + h4;
		h3 = h5 - h4;
		out -> l1 = h1 * hpara-> pf + hpara-> po;
		out -> l2 = h2 * hpara-> pf + hpara-> po;
		out -> l3 = h3 * hpara-> pf + hpara-> po;
	}
}


