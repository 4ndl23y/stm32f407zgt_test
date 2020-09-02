#ifndef __DELAY_H
#define __DELAY_H

#ifndef __stdint_h
#include "stdint.h"
#endif

static void delay(uint32_t time)
{
	for(uint32_t t = 0; t < time*1000; t++);
}

#endif