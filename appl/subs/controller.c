/*
 * controller.c
 *
 *  Created on: 16.07.2017
 *      Author: manni1user
 */

#include "subs/controller.h"

static Controller_para *hpara;

void Controller_init(Controller_para *para, Controller_in in)
{
	hpara = para; // copy only pointer ???
	para->rot = .0001;
	in->phi = 0.0;
}

void Controller_calc(Controller_in *in, Controller_out *out)
{

}
