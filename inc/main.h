#ifndef __MAIN_H
#define __MAIN_H

#ifndef __STM32F407xx_H
#include "stm32f407xx.h"
#endif

#ifndef __LCD_H
#include "lcd.h"
#endif

#ifndef __TOUCH_H
#include "touch.h"
#endif

void RCC_INIT(void);
void GPIO_INIT(void);
void EXTI_INIT(void);
void TIM_INIT(void);
void NVIC_INIT(void);
void SPI_INIT(void);

template <typename T>
void swap(T a, T b)
{ 
	T c = a; 
	a = b; 
	b = c; 
}

int32_t power(int16_t a, int8_t b)
{
	if(b == 0){ return 1; }
	for(; b > 1; b--)
	{
		a *= a;
	}
	return a;
}

unsigned int strlen(char* str)
{
	return ((*str) ? strlen(++str) + 1 : 0);
}

char* ItoA(int32_t number, char* str, int8_t base = 10)
{
	for(int16_t i = 0; *str; i++)
	{
		*str = (number / power(base, i)) % base;
		++str;
	}
	str -= strlen(str);
	return str;
}

void strcpy(char* array, char* str)
{
	for(uint8_t i = 0; *str; i++)
	{
		array[i] = str[i];
	}
}


#endif
