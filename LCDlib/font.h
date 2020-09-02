#ifndef __FONT_H__
#define __FONT_H__

#ifndef __stdint_h
#include "stdint.h"
#endif

typedef struct {
	const uint16_t* Table;
	uint8_t Width;
	uint8_t Hieght;
} UB_Font;

extern UB_Font Arial_7x10; 
extern UB_Font Arial_8x13;
extern UB_Font Arial_10x15;
extern UB_Font Arial_11x18;
extern UB_Font Arial_13x19;
extern UB_Font Arial_14x22;
extern UB_Font Arial_16x25;
//extern UB_Font Arial_18x27;

#endif




