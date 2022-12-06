#include "stm32f10x.h"                  // Device header            
#include "stm32f10x_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "seg7_lib.h"
#include "gpio_lib.h"

int main()
{
		GPIO_LED_CONFIG();
		GPIO_BUTTON_CONFIG();
	while(1){
			SEG_run_1();
	}
}

