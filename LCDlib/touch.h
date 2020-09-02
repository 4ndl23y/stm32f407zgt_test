#ifndef __TOUCH_H
#define __TOUCH_H

#ifndef __stdint_h
#include "stdint.h"
#endif

#ifndef __STM32F4xx_H 
#include "stm32f4xx.h" 
#endif 

#ifndef __DELAY_h
#include "delay.h"
#endif

#define OUTPUT		0x01UL
#define INPUT		0x00UL
#define PULL_UP 	0x01UL
#define PULL_DOWN 	0x02UL
#define MS			0x01UL
#define HS			0x02UL
#define VERY_HS		0x03UL

#define CLK_DELAY 1

extern void delay(uint32_t);

struct Touch_t{
	uint16_t X;
	uint16_t Y;
	uint16_t Z1;
	uint16_t Z2;
	
}Touch;

uint16_t TouchGet(uint8_t);
void Touch_Init();

void TouchRead()
{
	GPIOC->BSRR = GPIO_BSRR_BR13; // T_CS (chip select)
	Touch.X = TouchGet(0x1);
	Touch.Z1 = TouchGet(0x4);
	Touch.Y = TouchGet(0x3);
	Touch.Z2 = TouchGet(0x5);
	GPIOC->BSRR = GPIO_BSRR_BS13; // T_CS 
}

uint16_t TouchGet(uint8_t com)
{
	uint16_t rxBuff = 0;//up to 12-bit data
	uint8_t txBuff;		//send 8-bit command
	//_____transmit_____________________________________
	com &= 0x07; // only 3-bit (a2,a1,a0)
	txBuff =  0x1 << 7	// start bit
			| com << 4	// 3-bit command
			| 0x0 << 3	// mode
			| 0x0 << 2 	// deffirential / serial
			| 0x0 << 0;	// PD1, PD0;
	GPIOB->BSRR = GPIO_BSRR_BR0;	// T_CLK
	for(int8_t i = 7; i >= 0; i--)
	{
		if(txBuff & (1 << i)) // send bit
		{ 
			GPIOF->BSRR = GPIO_BSRR_BS11; 
		}
		else
		{ 
			GPIOF->BSRR = GPIO_BSRR_BR11; 
		}
		delay(CLK_DELAY);
		GPIOB->BSRR = GPIO_BSRR_BS0;	// T_CLK
		delay(CLK_DELAY);
		GPIOB->BSRR = GPIO_BSRR_BR0;
	}
	//_____end_transmit_________________________________
	delay(CLK_DELAY);
	//_____receive______________________________________
	//GPIOB->BSRR = GPIO_BSRR_BR0;	// T_CLK
	for(int8_t i = 15; i >= 0; i--) 
	{
		rxBuff |= ((GPIOB->IDR & GPIO_IDR_ID2) << i);	//read bit
		delay(CLK_DELAY);
		GPIOB->BSRR = GPIO_BSRR_BS0;
		delay(CLK_DELAY);
		GPIOB->BSRR = GPIO_BSRR_BR0;
	}
	//_____end_receive__________________________________
	delay(CLK_DELAY);
	rxBuff >>= 4;
	return rxBuff;
}

void Touch_Init()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	
	GPIOB->MODER |= OUTPUT << GPIO_MODER_MODE0_Pos;		// T_CLK
	GPIOF->MODER |= OUTPUT << GPIO_MODER_MODE11_Pos; 	// DOUT
	GPIOB->OSPEEDR |= HS << GPIO_OSPEEDR_OSPEED0_Pos;
	GPIOF->OSPEEDR |= HS << GPIO_OSPEEDR_OSPEED11_Pos;
	GPIOB->BSRR = GPIO_BSRR_BR0;
	
	GPIOC->MODER |= OUTPUT << GPIO_MODER_MODE13_Pos;	// T_CS
	GPIOC->OSPEEDR |= HS << GPIO_OSPEEDR_OSPEED13_Pos;
	
	GPIOB->MODER |= INPUT << GPIO_MODER_MODER2_Pos; 	// DIN
}
#endif

