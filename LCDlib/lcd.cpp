#ifndef __LCD_H
#include "lcd.h"
#endif

using namespace LCD;
				
extern void delay(uint32_t);
extern unsigned int strlen(char* str);
				
void LCD_WriteData16(uint16_t d, uint32_t num)
{
  for(;num > 0; num--)
  {
    *(uint16_t*)LCD_DATA = d;
  }
}

void LCD_WriteData(uint8_t d, uint32_t num)
{
  for(;num > 0; num--)
  {
    *(uint8_t*)LCD_DATA = d;
  }
}

void LCD_WriteCom16(uint16_t c)
{
  *(uint16_t*)LCD_COM = c;
}

uint16_t LCD_ReadData16()
{
	return *(uint16_t*)LCD_DATA;
}

uint8_t LCD_ReadData()
{
	return *(uint8_t*)LCD_DATA;
}

void LCD_Display_on()
{
	GPIOB->BSRR |= GPIO_BSRR_BR15;
}

void LCD_Display_off()
{
	GPIOB->BSRR |= GPIO_BSRR_BS15;
}

void LCD_DrawPixel(uint16_t x, uint16_t y, uint16_t color)
{
	LCD_SetWindowXY(x, y, x, y);
	LCD_WriteData16(color);
}

void LCD_FillRect(int16_t x, int16_t y, int16_t width, int16_t height, uint16_t color)
{
	LCD_SetWindowXY(x, y, x + width - 1, y + height - 1);
	LCD_WriteData16(color, uint32_t(width) * uint32_t(height));
}

void LCD_PrintChar(uint16_t x, uint16_t y, uint8_t num, uint16_t color, uint16_t scale, UB_Font font)
{
	num = num - ' ';
	uint16_t mask;
	uint16_t symb;
	uint16_t yDraw;
	symb = font.Table[num * font.Hieght];
	for(uint8_t i = font.Hieght; i > 0 ; i--)
	{
		symb = font.Table[num * font.Hieght + i - 1];
		mask = 15;  //16-1
		yDraw = y;
		for(uint8_t j = 0; j < font.Width; j++)
		{
			if(symb & (1 << mask))
			{
				LCD_FillRect(x, yDraw, scale, scale, color);
			}
			else
			{
				
				LCD_FillRect(x, yDraw, scale, scale, GREEN);
			}
			mask--;
			yDraw += scale; // next pixel
		}
		x += scale; // next line
	}
}

//unsigned int strlen(char* str)
//{
//	return ((*str) ? strlen(++str) + 1 : 0);
//}

void LCD_PrintString(uint16_t x, uint16_t y, char* str, uint16_t color, uint8_t scale, UB_Font font)
{
	uint16_t yDraw = y;
	for(static int i = 0; i < strlen(str); i++)
	{
		if(str[i] == '\n' || yDraw > LCD_WIDTH - font.Width) //endl
		{
			x -= font.Hieght * scale;
			yDraw = y;
		}
		else
		{
			LCD_PrintChar(x, yDraw, str[i], color, scale, font);
			yDraw += font.Width * scale;
		}
	}
}

uint32_t LCD_ReadID()
{
  return LCD_ReadRegister(0xA1, 2, 2);
}

uint32_t LCD_ReadRegister(uint8_t nr, uint8_t index, uint8_t bytes)
{
  uint32_t rv = 0;
  //bytes = uint8_t(bytes << 4); bytes = uint8_t(bytes >> 4); //bytes = gx_uint8_min(bytes, 4);
  LCD_WriteCom16(nr << 8);
  LCD_ReadData16(); // change read8
  for (uint8_t i = 0; i < index; i++)
  {
    LCD_ReadData16(); // change read8
  }
  for (; bytes > 0; bytes--)
  {
    rv <<= 16; // change 8
    rv |= LCD_ReadData16(); // change read8
  }
  return rv;
}

void LCD_ReadRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t* data)
{
  uint16_t xe = x + w - 1;
  uint16_t ye = y + h - 1;
  for (uint16_t yy = y; yy <= ye; yy++)
  {
    for (uint16_t xx = x; xx <= xe; xx++)
    {
      LCD_SetWindowXY(xx, yy, xx, yy);
      LCD_WriteCom16(0x2E00);  // read from RAM
      LCD_ReadData16(); // dummy
      uint16_t g = LCD_ReadData16();
      uint16_t r = LCD_ReadData16();
      uint16_t b = LCD_ReadData16();
      *data++ = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b & 0xF8) >> 3);
    }
  }
}							  

void LCD_SetRotation(uint8_t rotation)
{
  LCD_WriteCom16(OTM8009A_MADCTL);
  switch (rotation & 3)
  {
    case 0:
      LCD_WriteData(0);
      break;
    case 1:
      LCD_WriteData(OTM8009A_MADCTL_MX | OTM8009A_MADCTL_MV);
      break;
    case 2:
      LCD_WriteData(OTM8009A_MADCTL_MX | OTM8009A_MADCTL_MY);
      break;
    case 3:
      LCD_WriteData(OTM8009A_MADCTL_MY | OTM8009A_MADCTL_MV);
      break;
  }
}

void LCD_SetWindowXY(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
	LCD_WriteCom16(0x2A00);
	LCD_WriteData16(x0 >> 8);
	LCD_WriteCom16(0x2A01);
	LCD_WriteData16(x0 & 0x00ff);
	LCD_WriteCom16(0x2A02);
	LCD_WriteData16(x1 >> 8);
	LCD_WriteCom16(0x2A03);
	LCD_WriteData16(x1 & 0x00ff);
	LCD_WriteCom16(0x2B00);
	LCD_WriteData16(y0 >> 8);
	LCD_WriteCom16(0x2B01);
	LCD_WriteData16(y0 & 0x00ff);
	LCD_WriteCom16(0x2B02);
	LCD_WriteData16(y1 >> 8);
	LCD_WriteCom16(0x2B03);
	LCD_WriteData16(y1 & 0x00ff);
	LCD_WriteCom16(0x2C00);
}


void FSMC_INIT()
{
//	FLASH->ACR &= ~FLASH_ACR_LATENCY;
//	FLASH->ACR |= FLASH_ACR_LATENCY_6WS; //?
//	FLASH->ACR |= FLASH_ACR_PRFTEN;
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN 	// RCC init
				 |  RCC_AHB1ENR_GPIODEN
				 |  RCC_AHB1ENR_GPIOEEN
				 |  RCC_AHB1ENR_GPIOFEN
				 |  RCC_AHB1ENR_GPIOGEN;
		
	GPIOD->MODER |= AF << GPIO_MODER_MODER0_Pos		//FSMC_D2 		// AF
				 |  AF << GPIO_MODER_MODER1_Pos		//FSMC_D3
				 |  AF << GPIO_MODER_MODER4_Pos		//FSMC_NOE
				 |  AF << GPIO_MODER_MODER5_Pos		//FSMC_NWE
				 |  AF << GPIO_MODER_MODER8_Pos		//FSMC_D13
				 |  AF << GPIO_MODER_MODER9_Pos		//FSMC_D14
				 |  AF << GPIO_MODER_MODER10_Pos	//FSMC_D15
				 |  AF << GPIO_MODER_MODER14_Pos	//FSMC_D0
				 |  AF << GPIO_MODER_MODER15_Pos;	//FSMC_D1
	GPIOE->MODER |= AF << GPIO_MODER_MODER7_Pos		//FSMC_D4
				 |  AF << GPIO_MODER_MODER8_Pos		//FSMC_D5
				 |  AF << GPIO_MODER_MODER9_Pos		//FSMC_D6
				 |  AF << GPIO_MODER_MODER10_Pos	//FSMC_D7
				 |  AF << GPIO_MODER_MODER11_Pos 	//FSMC_D8
				 |  AF << GPIO_MODER_MODER12_Pos 	//FSMC_D9
				 |  AF << GPIO_MODER_MODER13_Pos 	//FSMC_D10
				 |  AF << GPIO_MODER_MODER14_Pos 	//FSMC_D11
				 |  AF << GPIO_MODER_MODER15_Pos;	//FSMC_D12
	GPIOF->MODER |= AF << GPIO_MODER_MODER12_Pos;	//FSMC_A6
	GPIOG->MODER |= AF << GPIO_MODER_MODER12_Pos;	//FSMC_NE4
	
	GPIOD->OSPEEDR |= MS << GPIO_OSPEEDR_OSPEED0_Pos 	//FSMC_D2 		// VERY HIGH SPEED
				   |  MS << GPIO_OSPEEDR_OSPEED1_Pos 	//FSMC_D3
				   |  MS << GPIO_OSPEEDR_OSPEED4_Pos 	//FSMC_NOE
				   |  MS << GPIO_OSPEEDR_OSPEED5_Pos 	//FSMC_NWE
				   |  MS << GPIO_OSPEEDR_OSPEED8_Pos 	//FSMC_D13
				   |  MS << GPIO_OSPEEDR_OSPEED9_Pos 	//FSMC_D14
				   |  MS << GPIO_OSPEEDR_OSPEED10_Pos 	//FSMC_D15
				   |  MS << GPIO_OSPEEDR_OSPEED14_Pos	//FSMC_D0
				   |  MS << GPIO_OSPEEDR_OSPEED15_Pos;	//FSMC_D1
	GPIOE->OSPEEDR |= MS << GPIO_OSPEEDR_OSPEED7_Pos	//FSMC_D4
				   |  MS << GPIO_OSPEEDR_OSPEED8_Pos	//FSMC_D5
				   |  MS << GPIO_OSPEEDR_OSPEED9_Pos	//FSMC_D6
				   |  MS << GPIO_OSPEEDR_OSPEED10_Pos	//FSMC_D7
				   |  MS << GPIO_OSPEEDR_OSPEED11_Pos	//FSMC_D8
				   |  MS << GPIO_OSPEEDR_OSPEED12_Pos	//FSMC_D9
				   |  MS << GPIO_OSPEEDR_OSPEED13_Pos	//FSMC_D10
				   |  MS << GPIO_OSPEEDR_OSPEED14_Pos	//FSMC_D11
				   |  MS << GPIO_OSPEEDR_OSPEED15_Pos;	//FSMC_D12
	GPIOF->OSPEEDR |= MS << GPIO_OSPEEDR_OSPEED12_Pos;	//FSMC_A6
	GPIOG->OSPEEDR |= MS << GPIO_OSPEEDR_OSPEED12_Pos;	//FSMC_NE4
	
	GPIOD->AFR[0] |= AFR_FSMC << GPIO_AFRL_AFSEL0_Pos;	//FSMC_D2 		// AFR 1100 fsmc
	GPIOD->AFR[0] |= AFR_FSMC << GPIO_AFRL_AFSEL1_Pos;	//FSMC_D3
	GPIOD->AFR[0] |= AFR_FSMC << GPIO_AFRL_AFSEL4_Pos;	//FSMC_NOE
	GPIOD->AFR[0] |= AFR_FSMC << GPIO_AFRL_AFSEL5_Pos;	//FSMC_NWE
	GPIOD->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL8_Pos;	//FSMC_D13
	GPIOD->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL9_Pos;	//FSMC_D14
	GPIOD->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL10_Pos;	//FSMC_D15
	GPIOD->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL14_Pos;	//FSMC_D0
	GPIOD->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL15_Pos;	//FSMC_D1
	GPIOE->AFR[0] |= AFR_FSMC << GPIO_AFRL_AFSEL7_Pos;	//FSMC_D4
	GPIOE->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL8_Pos;	//FSMC_D5
	GPIOE->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL9_Pos;	//FSMC_D6
	GPIOE->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL10_Pos;	//FSMC_D7
	GPIOE->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL11_Pos;	//FSMC_D8
	GPIOE->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL12_Pos;	//FSMC_D9
	GPIOE->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL13_Pos;	//FSMC_D10
	GPIOE->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL14_Pos;	//FSMC_D11
	GPIOE->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL15_Pos;	//FSMC_D12
	GPIOF->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL12_Pos;	//FSMC_A6
	GPIOG->AFR[1] |= AFR_FSMC << GPIO_AFRH_AFSEL12_Pos;	//FSMC_NE4
	
	RCC->AHB3ENR |= RCC_AHB3ENR_FSMCEN;
	
	FSMC_Bank1->BTCR[6] = 0x1	<< FSMC_BCR4_MBKEN_Pos		// memory bank enable
						| 0x0 	<< FSMC_BCR4_MUXEN_Pos		// Address/Data nonmultiplexed
						| 0x01 	<< FSMC_BCR4_MTYP_Pos		// memory type SRAM
						| 0x1 	<< FSMC_BCR4_MWID_Pos		// memory width 16bit
						| 0x0 	<< FSMC_BCR4_FACCEN_Pos		//
						| 0x0	<< FSMC_BCR4_BURSTEN_Pos	// Burst mode disabled
						| 0x0 	<< FSMC_BCR4_WAITPOL_Pos	// wait signal polarity low
						| 0x0	<< FSMC_BCR4_WRAPMOD_Pos	// Direct wrapped burst is not enabled
						| 0x0	<< FSMC_BCR4_WAITCFG_Pos	// NWAIT signal is active one data cycle before wait state
						| 0x1	<< FSMC_BCR4_WREN_Pos		// write enable
						| 0x0	<< FSMC_BCR4_WAITEN_Pos		// NWAIT signal is disabled
						| 0x0	<< FSMC_BCR4_EXTMOD_Pos		//
						| 0x0	<< FSMC_BCR4_ASYNCWAIT_Pos	//
						| 0x0	<< FSMC_BCR4_CPSIZE_Pos		//
						| 0x0	<< FSMC_BCR4_CBURSTRW_Pos;	//
	
	FSMC_Bank1->BTCR[7] = 0x0 	<< FSMC_BTR4_ADDSET_Pos		// adress setup time 
						| 0x4 	<< FSMC_BTR4_ADDHLD_Pos		// adress hold time 15 × HCLK clock cycle (0000-1111) F
						| 0x05 	<< FSMC_BTR4_DATAST_Pos		// data setup time 0-255 (00000000-11111111)
						| 0x0 	<< FSMC_BTR4_BUSTURN_Pos	//
						| 0x2 	<< FSMC_BTR4_CLKDIV_Pos		// clk division 16
						| 0x6 	<< FSMC_BTR4_DATLAT_Pos		// data latency 17
						| 0x0 	<< FSMC_BTR4_ACCMOD_Pos;	// access mode A

	GPIOB->MODER |= OUTPUT << GPIO_MODER_MODE15_Pos; 		//LCD_BL
	GPIOB->OSPEEDR |= HS << GPIO_OSPEEDR_OSPEED15_Pos; 
}

void LCD_Init()
{
	LCD_WriteCom16(0x0100); //software reset
	delay(100);				//wait for reset 
	
	FSMC_INIT();
  //============ OTM8009A+HSD3.97 20140613 ===============================================//
	LCD_WriteCom16(0xff00);    	LCD_WriteData16(0x80);    //enable access command2
	LCD_WriteCom16(0xff01);    	LCD_WriteData16(0x09);    //enable access command2
	LCD_WriteCom16(0xff02);    	LCD_WriteData16(0x01);    //enable access command2
	LCD_WriteCom16(0xff80);    	LCD_WriteData16(0x80);    //enable access command2
	LCD_WriteCom16(0xff81);    	LCD_WriteData16(0x09);    //enable access command2
	LCD_WriteCom16(0xff03);    	LCD_WriteData16(0x01);    //
	LCD_WriteCom16(0xc5b1);    	LCD_WriteData16(0xA9);    //power control

	LCD_WriteCom16(0xc591);    	LCD_WriteData16(0x0F);               //power control
	LCD_WriteCom16(0xc0B4);    	LCD_WriteData16(0x50);

  //panel driving mode : column inversion

  ////  gamma
	LCD_WriteCom16(0xE100);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xE101);    	LCD_WriteData16(0x09);
	LCD_WriteCom16(0xE102);    	LCD_WriteData16(0x0F);
	LCD_WriteCom16(0xE103);    	LCD_WriteData16(0x0E);
	LCD_WriteCom16(0xE104);    	LCD_WriteData16(0x07);
	LCD_WriteCom16(0xE105);    	LCD_WriteData16(0x10);
	LCD_WriteCom16(0xE106);    	LCD_WriteData16(0x0B);
	LCD_WriteCom16(0xE107);    	LCD_WriteData16(0x0A);
	LCD_WriteCom16(0xE108);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xE109);    	LCD_WriteData16(0x07);
	LCD_WriteCom16(0xE10A);    	LCD_WriteData16(0x0B);
	LCD_WriteCom16(0xE10B);    	LCD_WriteData16(0x08);
	LCD_WriteCom16(0xE10C);    	LCD_WriteData16(0x0F);
	LCD_WriteCom16(0xE10D);    	LCD_WriteData16(0x10);
	LCD_WriteCom16(0xE10E);    	LCD_WriteData16(0x0A);
	LCD_WriteCom16(0xE10F);    	LCD_WriteData16(0x01);
	LCD_WriteCom16(0xE200);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xE201);    	LCD_WriteData16(0x09);
	LCD_WriteCom16(0xE202);    	LCD_WriteData16(0x0F);
	LCD_WriteCom16(0xE203);    	LCD_WriteData16(0x0E);
	LCD_WriteCom16(0xE204);    	LCD_WriteData16(0x07);
	LCD_WriteCom16(0xE205);    	LCD_WriteData16(0x10);
	LCD_WriteCom16(0xE206);    	LCD_WriteData16(0x0B);
	LCD_WriteCom16(0xE207);    	LCD_WriteData16(0x0A);
	LCD_WriteCom16(0xE208);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xE209);    	LCD_WriteData16(0x07);
	LCD_WriteCom16(0xE20A);    	LCD_WriteData16(0x0B);
	LCD_WriteCom16(0xE20B);    	LCD_WriteData16(0x08);
	LCD_WriteCom16(0xE20C);    	LCD_WriteData16(0x0F);
	LCD_WriteCom16(0xE20D);    	LCD_WriteData16(0x10);
	LCD_WriteCom16(0xE20E);    	LCD_WriteData16(0x0A);
	LCD_WriteCom16(0xE20F);    	LCD_WriteData16(0x01);
	
	
	LCD_WriteCom16(0xD900);    	LCD_WriteData16(0x45); //0x4E -1.2625V   //vcom setting

	LCD_WriteCom16(0xc181);    	LCD_WriteData16(0x66);    //osc=65HZ

	LCD_WriteCom16(0xc1a1);    	LCD_WriteData16(0x08); 	//RGB video mode settings ???
	LCD_WriteCom16(0xc592);    	LCD_WriteData16(0x01);    //power control 

	LCD_WriteCom16(0xc595);    	LCD_WriteData16(0x34);    //power control 

	LCD_WriteCom16(0xd800);    	LCD_WriteData16(0x0F);    //GVDD / NGVDD setting //GVDD=3.3V

	LCD_WriteCom16(0xd801);    	LCD_WriteData16(0x0F);    //GVDD / NGVDD setting //NGVDD=3.3V

	LCD_WriteCom16(0xc594);    	LCD_WriteData16(0x33);    //power control

	LCD_WriteCom16(0xc0a3);    	LCD_WriteData16(0x1B);       //panel timing setting
	LCD_WriteCom16(0xc582);    	LCD_WriteData16(0x83);    //power control

	LCD_WriteCom16(0xc481);    	LCD_WriteData16(0x83); //0.86 uA   //source driver setting 

	LCD_WriteCom16(0xc1a1);    	LCD_WriteData16(0x0E);
	LCD_WriteCom16(0xb3a6);    	LCD_WriteData16(0x20);
	LCD_WriteCom16(0xb3a7);    	LCD_WriteData16(0x01);
	LCD_WriteCom16(0xce80);    	LCD_WriteData16(0x85);    // GOA VST

	LCD_WriteCom16(0xce81);    	LCD_WriteData16(0x01);  // GOA VST

	LCD_WriteCom16(0xce82);    	LCD_WriteData16(0x00);    // GOA VST

	LCD_WriteCom16(0xce83);    	LCD_WriteData16(0x84);    // GOA VST
	LCD_WriteCom16(0xce84);    	LCD_WriteData16(0x01);    // GOA VST
	LCD_WriteCom16(0xce85);    	LCD_WriteData16(0x00);    // GOA VST

	LCD_WriteCom16(0xcea0);    	LCD_WriteData16(0x18);    // GOA CLK
	LCD_WriteCom16(0xcea1);    	LCD_WriteData16(0x04);    // GOA CLK
	LCD_WriteCom16(0xcea2);    	LCD_WriteData16(0x03);    // GOA CLK
	LCD_WriteCom16(0xcea3);    	LCD_WriteData16(0x39);    // GOA CLK
	LCD_WriteCom16(0xcea4);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xcea5);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xcea6);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xcea7);    	LCD_WriteData16(0x18);    // GOA CLK
	LCD_WriteCom16(0xcea8);    	LCD_WriteData16(0x03);    // GOA CLK
	LCD_WriteCom16(0xcea9);    	LCD_WriteData16(0x03);    // GOA CLK
	LCD_WriteCom16(0xceaa);    	LCD_WriteData16(0x3a);    // GOA CLK
	LCD_WriteCom16(0xceab);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xceac);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xcead);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xceb0);    	LCD_WriteData16(0x18);    // GOA CLK
	LCD_WriteCom16(0xceb1);    	LCD_WriteData16(0x02);    // GOA CLK
	LCD_WriteCom16(0xceb2);    	LCD_WriteData16(0x03);    // GOA CLK
	LCD_WriteCom16(0xceb3);    	LCD_WriteData16(0x3b);    // GOA CLK
	LCD_WriteCom16(0xceb4);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xceb5);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xceb6);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xceb7);    	LCD_WriteData16(0x18);    // GOA CLK
	LCD_WriteCom16(0xceb8);    	LCD_WriteData16(0x01);    // GOA CLK
	LCD_WriteCom16(0xceb9);    	LCD_WriteData16(0x03);    // GOA CLK
	LCD_WriteCom16(0xceba);    	LCD_WriteData16(0x3c);    // GOA CLK
	LCD_WriteCom16(0xcebb);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xcebc);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xcebd);    	LCD_WriteData16(0x00);    // GOA CLK
	LCD_WriteCom16(0xcfc0);    	LCD_WriteData16(0x01);    // GOA ECLK
	LCD_WriteCom16(0xcfc1);    	LCD_WriteData16(0x01);    // GOA ECLK
	LCD_WriteCom16(0xcfc2);    	LCD_WriteData16(0x20);    // GOA ECLK

	LCD_WriteCom16(0xcfc3);    	LCD_WriteData16(0x20);    // GOA ECLK

	LCD_WriteCom16(0xcfc4);    	LCD_WriteData16(0x00);    // GOA ECLK

	LCD_WriteCom16(0xcfc5);    	LCD_WriteData16(0x00);    // GOA ECLK

	LCD_WriteCom16(0xcfc6);    	LCD_WriteData16(0x01);    // GOA other options

	LCD_WriteCom16(0xcfc7);    	LCD_WriteData16(0x00);

  // GOA signal toggle option setting

	LCD_WriteCom16(0xcfc8);    	LCD_WriteData16(0x00);    //GOA signal toggle option setting
	LCD_WriteCom16(0xcfc9);    	LCD_WriteData16(0x00);

  //GOA signal toggle option setting

	LCD_WriteCom16(0xcfd0);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb80);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb81);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb82);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb83);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb84);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb85);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb86);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb87);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb88);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb89);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb90);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb91);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb92);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb93);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb94);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb95);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb96);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb97);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb98);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb99);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb9a);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb9b);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb9c);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb9d);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcb9e);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcba0);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcba1);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcba2);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcba3);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcba4);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcba5);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcba6);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcba7);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcba8);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcba9);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbaa);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbab);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbac);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbad);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbae);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbb0);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbb1);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbb2);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbb3);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbb4);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbb5);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbb6);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbb7);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbb8);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbb9);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbc0);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbc1);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xcbc2);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xcbc3);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xcbc4);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xcbc5);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xcbc6);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbc7);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbc8);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbc9);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbca);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbcb);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbcc);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbcd);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbce);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbd0);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbd1);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbd2);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbd3);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbd4);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbd5);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbd6);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xcbd7);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xcbd8);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xcbd9);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xcbda);    	LCD_WriteData16(0x04);
	LCD_WriteCom16(0xcbdb);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbdc);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbdd);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbde);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbe0);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbe1);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbe2);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbe3);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbe4);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbe5);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbe6);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbe7);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbe8);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbe9);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcbf0);    	LCD_WriteData16(0xFF);
	LCD_WriteCom16(0xcbf1);    	LCD_WriteData16(0xFF);
	LCD_WriteCom16(0xcbf2);    	LCD_WriteData16(0xFF);
	LCD_WriteCom16(0xcbf3);    	LCD_WriteData16(0xFF);
	LCD_WriteCom16(0xcbf4);    	LCD_WriteData16(0xFF);
	LCD_WriteCom16(0xcbf5);    	LCD_WriteData16(0xFF);
	LCD_WriteCom16(0xcbf6);    	LCD_WriteData16(0xFF);
	LCD_WriteCom16(0xcbf7);    	LCD_WriteData16(0xFF);
	LCD_WriteCom16(0xcbf8);    	LCD_WriteData16(0xFF);
	LCD_WriteCom16(0xcbf9);    	LCD_WriteData16(0xFF);
	LCD_WriteCom16(0xcc80);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc81);    	LCD_WriteData16(0x26);
	LCD_WriteCom16(0xcc82);    	LCD_WriteData16(0x09);
	LCD_WriteCom16(0xcc83);    	LCD_WriteData16(0x0B);
	LCD_WriteCom16(0xcc84);    	LCD_WriteData16(0x01);
	LCD_WriteCom16(0xcc85);    	LCD_WriteData16(0x25);
	LCD_WriteCom16(0xcc86);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc87);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc88);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc89);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc90);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc91);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc92);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc93);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc94);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc95);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc96);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc97);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc98);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc99);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc9a);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcc9b);    	LCD_WriteData16(0x26);
	LCD_WriteCom16(0xcc9c);    	LCD_WriteData16(0x0A);
	LCD_WriteCom16(0xcc9d);    	LCD_WriteData16(0x0C);
	LCD_WriteCom16(0xcc9e);    	LCD_WriteData16(0x02);
	LCD_WriteCom16(0xcca0);    	LCD_WriteData16(0x25);
	LCD_WriteCom16(0xcca1);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcca2);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcca3);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcca4);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcca5);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcca6);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcca7);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcca8);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcca9);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccaa);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccab);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccac);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccad);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccae);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccb0);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccb1);    	LCD_WriteData16(0x25);
	LCD_WriteCom16(0xccb2);    	LCD_WriteData16(0x0C);
	LCD_WriteCom16(0xccb3);    	LCD_WriteData16(0x0A);
	LCD_WriteCom16(0xccb4);    	LCD_WriteData16(0x02);
	LCD_WriteCom16(0xccb5);    	LCD_WriteData16(0x26);
	LCD_WriteCom16(0xccb6);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccb7);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccb8);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccb9);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccc0);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccc1);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccc2);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccc3);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccc4);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccc5);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccc6);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccc7);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccc8);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccc9);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccca);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xcccb);    	LCD_WriteData16(0x25);
	LCD_WriteCom16(0xcccc);    	LCD_WriteData16(0x0B);
	LCD_WriteCom16(0xcccd);    	LCD_WriteData16(0x09);
	LCD_WriteCom16(0xccce);    	LCD_WriteData16(0x01);
	LCD_WriteCom16(0xccd0);    	LCD_WriteData16(0x26);
	LCD_WriteCom16(0xccd1);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccd2);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccd3);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccd4);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccd5);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccd6);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccd7);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccd8);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccd9);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccda);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccdb);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccdc);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccdd);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0xccde);    	LCD_WriteData16(0x00);
	LCD_WriteCom16(0x3A00);    	LCD_WriteData16(0x55); 

	LCD_WriteCom16(0x1100);		//sleep out
	delay(100);
	LCD_WriteCom16(0x2900);		//disp on
	delay(50);
	LCD_WriteCom16(0x2C00);		// memory write
	LCD_WriteCom16(0x2A00);   	LCD_WriteData16(0x00); //column
	LCD_WriteCom16(0x2A01);   	LCD_WriteData16(0x00);
	LCD_WriteCom16(0x2A02);   	LCD_WriteData16(0x01);
	LCD_WriteCom16(0x2A03);   	LCD_WriteData16(0xe0);
	LCD_WriteCom16(0x2B00);   	LCD_WriteData16(0x00); //padge
	LCD_WriteCom16(0x2B01);   	LCD_WriteData16(0x00);
	LCD_WriteCom16(0x2B02);   	LCD_WriteData16(0x03);
	LCD_WriteCom16(0x2B03);   	LCD_WriteData16(0x20);
}

