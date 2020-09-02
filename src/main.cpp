#include "main.h"

int main()
{
	RCC_INIT();
	GPIO_INIT();
	EXTI_INIT();
	TIM_INIT();
    SPI_INIT();
	__enable_irq ();
    
    SPI1->CR1 |= SPI_CR1_SPE;                       // SPI1 enable
	
	LCD_Init();
	LCD_Display_on(); 
	
	Touch_Init();
	
	LCD_SetRotation(2);
	LCD_FillRect(0, 0, 480, 800, 0x07E0);
	
//	UB_Font LCD_font[8] = {	Arial_7x10,
//							Arial_8x13,
//							Arial_10x15,
//							Arial_11x18,
//							Arial_13x19,
//							Arial_14x22,
//							Arial_16x25};
	
	static int i = 0;
	static uint8_t c = ' '; //CHAR SYMB
	//LCD_SetRotation(rotate);
	static uint16_t x = 10;
	//for(uint16_t y = 0; y < 750; y += 25)
	//{
	
	static uint16_t y = 10;						
	//const char* str = 	//adr = ;
	LCD_PrintString(350, 30, "Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo.");		
	
    while(1)
	{
		
	}
}

#ifdef __cplusplus
extern "C" {
#endif

void EXTI1_IRQHandler()
{
	if(EXTI->PR & EXTI_PR_PR1)
	{
		TouchRead();
		(GPIOF->ODR & GPIO_ODR_OD9) == 0 ? (GPIOF->ODR |= GPIO_ODR_OD9) : (GPIOF->ODR &= ~GPIO_ODR_OD9); // blink if touch
		EXTI->PR |= EXTI_PR_PR1;	//reset flag
	}
}
	
void EXTI9_5_IRQHandler()
{
	if(EXTI->PR & EXTI_PR_PR8)
	{
		GPIOF->BSRR = GPIO_BSRR_BS9;
		EXTI->PR |= EXTI_PR_PR8;	//reset flag
	}
	if(EXTI->PR & EXTI_PR_PR9)
	{
		GPIOF->BSRR = GPIO_BSRR_BR9;
		EXTI->PR |= EXTI_PR_PR9;
	}
}

void TIM3_IRQHandler()
{
	(GPIOF->ODR & GPIO_ODR_OD9) == 0 ? (GPIOF->ODR |= GPIO_ODR_OD9) : (GPIOF->ODR &= ~GPIO_ODR_OD9);
	TIM3->SR &= ~TIM_SR_UIF;
}

#ifdef __cplusplus
}
#endif

void RCC_INIT()
{	
	FLASH->ACR |= FLASH_ACR_PRFTEN;
	FLASH->ACR &= ~FLASH_ACR_LATENCY;
	FLASH->ACR |= FLASH_ACR_LATENCY_7WS;
	
	RCC->CR |= RCC_CR_HSEON;
	while(!(RCC->CR & RCC_CR_HSERDY));
	RCC->CR &= ~RCC_CR_PLLON;
	while ((RCC->CR & RCC_CR_PLLRDY) != 0); 
	
	RCC->PLLCFGR &= ~(RCC_PLLCFGR_PLLSRC_HSE
			| RCC_PLLCFGR_PLLM 
			| RCC_PLLCFGR_PLLN 
			| RCC_PLLCFGR_PLLP
			| RCC_PLLCFGR_PLLQ);
	RCC->PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;     //set HSE as PLL source
	RCC->PLLCFGR |= 4 << RCC_PLLCFGR_PLLM_Pos
			 | 168 	<< RCC_PLLCFGR_PLLN_Pos
			 | 0x00	<< RCC_PLLCFGR_PLLP_Pos     //RCC_PLLCFGR_PLLP: 00 = 2, 01 = 4, 10 = 8, 11 =16 !AHTUNG!
			 | 7 	<< RCC_PLLCFGR_PLLQ_Pos;
	
	RCC->CFGR &= ~(RCC_CFGR_HPRE 
			| RCC_CFGR_PPRE1
			| RCC_CFGR_PPRE2); 
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1         //AHB = SYSCLK/1 	168MHz
		  | RCC_CFGR_PPRE1_DIV4             //APB1	/4		42MHz for periph and  84MHz for timer	
		  | RCC_CFGR_PPRE2_DIV2;            //APB2	/2		84MHz for periph and  168MHz for timer	
	
	RCC->CR |= RCC_CR_PLLON; 
	while ((RCC->CR & RCC_CR_PLLRDY) == 0); 
	RCC->CFGR &= ~RCC_CFGR_SW; 
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
	SystemCoreClockUpdate();
	
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
    RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
}

void GPIO_INIT()
{
	GPIOF->MODER |= OUTPUT << GPIO_MODER_MODE9_Pos		//LED
		     | OUTPUT << GPIO_MODER_MODE10_Pos;
	GPIOF->OSPEEDR |= VERY_HS << GPIO_OSPEEDR_OSPEED9_Pos
			| VERY_HS << GPIO_OSPEEDR_OSPEED10_Pos;
	GPIOF->BSRR = GPIO_BSRR_BS9 
		| GPIO_BSRR_BS10;
}

void EXTI_INIT()
{
	GPIOB->MODER |= INPUT << GPIO_MODER_MODER1_Pos; // T_PEN 
	//GPIOB->PUPDR |= PULL_UP << GPIO_PUPDR_PUPD1_Pos;
	
	GPIOB->MODER |= INPUT << GPIO_MODER_MODER8_Pos; // key 0 
	GPIOB->PUPDR |= PULL_UP << GPIO_PUPDR_PUPD8_Pos;
	GPIOB->MODER |= INPUT << GPIO_MODER_MODER9_Pos; // key 1 
	GPIOB->PUPDR |= PULL_UP << GPIO_PUPDR_PUPD9_Pos;
	EXTI->FTSR |= EXTI_FTSR_TR8
			   | EXTI_FTSR_TR9
			   | EXTI_FTSR_TR1;
	EXTI->IMR |= EXTI_IMR_IM8
			  | EXTI_IMR_IM9
			  | EXTI_IMR_IM1;
	SYSCFG->EXTICR[2] |= SYSCFG_EXTICR3_EXTI8_PB;
	SYSCFG->EXTICR[2] |= SYSCFG_EXTICR3_EXTI9_PB;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI1_PB; // T_PEN for touchscreen
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_SetPriority(EXTI1_IRQn, 3);	
	NVIC_EnableIRQ(EXTI9_5_IRQn);
	NVIC_SetPriority(EXTI9_5_IRQn, 2);
}

void TIM_INIT()
{
	TIM3->PSC = 16800;  // 168`000`000 / 16800 = 10000 hz
	TIM3->ARR = 10000;  // every 1s
	TIM3->DIER = TIM_DIER_UIE;
	//TIM3->EGR |= TIM_EGR_UG; //UPDATE
	NVIC_EnableIRQ(TIM3_IRQn);
	NVIC_SetPriority(TIM3_IRQn, 1);
	
	TIM3->CR1 = TIM_CR1_CEN;
}

void SPI_INIT()
{
    GPIOB->MODER |= AF << GPIO_MODER_MODER3_Pos     // AF for SPI1_SCK
                 | AF << GPIO_MODER_MODER5_Pos;     // AF for SPI1_MOSI
    GPIOB->MODER &=  ~GPIO_MODER_MODER4;            // INPUT for SPI1_MISO
    GPIOB->PUPDR |= PULL_UP << GPIO_PUPDR_PUPD4_Pos;// Pull Up MISO
    
    GPIOB->OSPEEDR |= HS << GPIO_OSPEEDR_OSPEED3_Pos;   // High Speed 
    GPIOB->OSPEEDR |= HS << GPIO_OSPEEDR_OSPEED4_Pos;
    GPIOB->OSPEEDR |= HS << GPIO_OSPEEDR_OSPEED5_Pos;
    
    GPIOB->AFR[0] |= 5 << GPIO_AFRL_AFSEL3_Pos      // AF5 SPI1_SCK
                   | 5 << GPIO_AFRL_AFSEL4_Pos      // AF5 SPI1_MISO
                   | 5 << GPIO_AFRL_AFSEL5_Pos;     // AF5 SPI1_MOSI
    
    SPI1->CR1 |= SPI_CR1_BR_Pos;
    SPI1->CR1 |= 3 << SPI_CR1_BR_Pos;               // 3 -> 011  f(pclk)/16      // 84 MHz / 16 = 5,25 MHz
    //SPI1->CR1 &= ~SPI_CR1_LSBFIRST;               // MSB first
    //SPI1->CR1 &= ~(SPI_CR1_CPHA | SPI_CR1_CPOL);  // cpol = 0, cpha = 0
    //SPI1->CR1 &= ~SPI_CR1_DFF;                    // 8-bit data frame
    SPI1->CR1 |= SPI_CR1_SSI                        // NSS pin disable
              | SPI_CR1_SSM;                        // Master
    SPI1->CR1 |= SPI_CR1_MSTR;                      // Master configuration
    
    NVIC_EnableIRQ(SPI1_IRQn);
    NVIC_SetPriority(SPI1_IRQn, 2);
}
