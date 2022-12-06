#include "stm32f10x.h" // Device header       
#include "seg7_lib.h"
#include "gpio_lib.h"



unsigned int counter = 0;
const int seg[] = {0x7b, 0xA,0xB3,0x9B,0XCA, 0XD9, 0XF9, 0XB, 0XFB, 0XDB};
void SEG_RUN_2(int i)
{		
				int j;
				for(j=0;j<10;j++){
				GPIO_ResetBits(GPIOA, LED_4);
				GPIOA->ODR = seg[i%10];
				Delay_ms(1);
				GPIO_SetBits(GPIOA,LED_4);
				
				GPIO_ResetBits(GPIOA,LED_3);
				GPIOA->ODR = seg[(i/10)%10];
				Delay_ms(1);
				GPIO_SetBits(GPIOA,LED_3);
				
				GPIO_ResetBits(GPIOA, LED_2);
				GPIOA->ODR = seg[(i/100)%10];
				Delay_ms(1);
				GPIO_SetBits(GPIOA, LED_2);
				
				
				GPIO_ResetBits(GPIOA, LED_1);
				GPIOA->ODR = seg[i/1000];
				Delay_ms(1);
				GPIO_SetBits(GPIOA, LED_1);
}
}

void SEG_Run_3(void)
{
			SEG_RUN_2(counter);
			if(GPIO_ReadInputDataBit(GPIOB, button_1) == 1){
		    while(GPIO_ReadInputDataBit(GPIOB, button_1) == 1);
				counter++;
				if(counter > 9999){
					counter = 0;
				}
				SEG_RUN_2(counter);
			}
			else if(GPIO_ReadInputDataBit(GPIOB, button_2) == 1){
					while(GPIO_ReadInputDataBit(GPIOB, button_2) == 1);
				if(counter >0 && counter < 9999)
							counter--;
				else
					counter = 9999;
				SEG_RUN_2(counter);
			}
			
}


void SEG_run_1()
{
			SEG_LED(counter);
			if(GPIO_ReadInputDataBit(GPIOB, button_1) == 1){
				  while(GPIO_ReadInputDataBit(GPIOB, button_1) == 1);
							counter++;
						if(counter > 9) counter = 0;
						SEG_LED(counter);
			}
			else if(GPIO_ReadInputDataBit(GPIOB, button_2) == 1){
				 while(GPIO_ReadInputDataBit(GPIOB, button_2) == 1);
				if(counter >0 && counter < 10)
							counter--;
				else
					counter = 9;
						SEG_LED(counter);
			}
		
	
}

void SEG_LED(int i){
				GPIOA->ODR = seg[i];
			
}
