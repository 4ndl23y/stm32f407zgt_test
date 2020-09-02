#ifndef __LCD_H
#define __LCD_H

#ifndef __stdint_h
#include "stdint.h"
#endif

#ifndef __STM32F4xx_H 
#include "stm32f4xx.h" 
#endif 

#ifndef __DELAY_h
#include "delay.h"
#endif

#ifndef __FONT_H__
#include "font.h"
#endif

#define WHITE  0xFFFF 
#define BLACK  0x0000 
#define BLUE   0x001F 
#define RED    0xF800 
#define GREEN  0x07E0 

namespace LCD{
	
#define LCD_DATA 	0x6C000080
#define LCD_COM		0x6C000000
	
#define LCD_WIDTH	800
#define LCD_HIEGHT	480
		

#define OUTPUT		0x01UL
#define INPUT		0x00UL
#define AF 			0x02UL
#define AFR_FSMC	0x0CUL
#define PULL_UP 	0x01UL
#define PULL_DOWN 	0x02UL
#define MS			0x01UL
#define HS			0x02UL
#define VERY_HS		0x03UL

#define OTM8009A_MADCTL     0x3600
#define OTM8009A_MADCTL_MY  0x80
#define OTM8009A_MADCTL_MX  0x40
#define OTM8009A_MADCTL_MV  0x20
#define OTM8009A_MADCTL_ML  0x10
#define OTM8009A_MADCTL_RGB 0x00
#define OTM8009A_MADCTL_BGR 0x08
	


static UB_Font Font[7] = {	Arial_7x10, 
					Arial_8x13,
					Arial_10x15,
					Arial_11x18,
					Arial_13x19,
					Arial_14x22,
					Arial_16x25};	// To add new font, write fontname to "font.h" and add fontfile.c

//struct LCD
//{
//	public:
//		LCD() : LCD_DATA(0x6C000080), LCD_COM(0x6C000000)
//		{
//			Width = 800;
//			Hieght = 480;
//			Color = RED;
//			BackColor = GREEN;
//			//Font = Font[6];
//		}
//		~LCD();
//		uint16_t Width;
//		uint16_t Hieght;
//		uint16_t Color;
//		uint16_t BackColor;
//		UB_Font Font;
//	private:
//		const uint32_t LCD_DATA;
//		const uint32_t LCD_COM;
//};

}

void FSMC_INIT(void);
void LCD_Init(void);
void LCD_Display_on(void);                                      
void LCD_Display_off(void);
void LCD_WriteCom16(uint16_t);
void LCD_WriteData16(uint16_t, uint32_t num = 1);
void LCD_WriteData(uint8_t d, uint32_t num = 1);
uint16_t LCD_ReadData16(void);
uint8_t LCD_ReadData(void);
void LCD_SetRotation(uint8_t);
void LCD_SetWindowXY(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
uint32_t LCD_ReadRegister(uint8_t nr, uint8_t index, uint8_t bytes);

void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
void LCD_FillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void LCD_ReadRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t* data);

void LCD_PrintChar(uint16_t x, uint16_t y, uint8_t num, uint16_t color = BLACK, uint16_t scale = 1, UB_Font font = Arial_16x25);
void LCD_PrintString(uint16_t x, uint16_t y, char* str, uint16_t color = BLACK, uint8_t scale = 1, UB_Font font = Arial_16x25);

#endif 

 
