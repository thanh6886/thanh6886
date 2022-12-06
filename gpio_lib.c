#include "stm32f10x.h"
#include "stm32f10x_gpio.h"  // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f10x_rcc.h"   
#include "gpio_lib.h"


void GPIO_LED_CONFIG(void)
{
		GPIO_InitTypeDef GPIO_struct;
	
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
		
		GPIO_struct.GPIO_Mode = GPIO_Mode_Out_PP;
		GPIO_struct.GPIO_Pin = GPIO_DF_SEG7_A|GPIO_DF_SEG7_B|GPIO_DF_SEG7_C|GPIO_DF_SEG7_D|GPIO_DF_SEG7_E|GPIO_DF_SEG7_F|GPIO_DF_SEG7_G|LED_1|LED_2|LED_3|LED_4;
		GPIO_struct.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOA, &GPIO_struct);
}
	
void GPIO_BUTTON_CONFIG(void)
{
	
		GPIO_InitTypeDef GPIO_BUTTON;
		
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
		GPIO_BUTTON.GPIO_Mode = GPIO_Mode_IPD;
		GPIO_BUTTON.GPIO_Pin = button_1|button_2|button_3;
		GPIO_BUTTON.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_Init(GPIOB, &GPIO_BUTTON);
}

void Delay_ms(unsigned int _time)
{
		int i, j;
		for(i=0;i<_time;i++){
			for(j=0;j<0x2aff;j++);
		}
}
