#ifndef __GPIO_LIB__
#define __GPIO_LIB__

//*********************************************************


#define GPIO_DF_SEG7_A 		GPIO_Pin_0
#define GPIO_DF_SEG7_B 		GPIO_Pin_1
#define GPIO_DF_SEG7_C 		GPIO_Pin_3
#define GPIO_DF_SEG7_D 		GPIO_Pin_4
#define GPIO_DF_SEG7_E 		GPIO_Pin_5
#define GPIO_DF_SEG7_F 		GPIO_Pin_6
#define GPIO_DF_SEG7_G 		GPIO_Pin_7


#define LED_1 GPIO_Pin_8
#define LED_2 GPIO_Pin_9
#define LED_3 GPIO_Pin_10
#define LED_4 GPIO_Pin_11

#define button_1 GPIO_Pin_0
#define button_2 GPIO_Pin_1
#define button_3 GPIO_Pin_3



void GPIO_LED_CONFIG(void);
void GPIO_BUTTON_CONFIG(void);
void Delay_ms(unsigned int _time);
//**********************************************************
#endif
