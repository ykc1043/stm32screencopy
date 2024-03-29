#include "Device/Include/stm32f10x.h"   // Device header
#include "Delay.h"
#include "GPIOset.h"
#include "Key.h"
#include "OLED.h"
#include "Serial.h"
#include "DMA.h"

extern uint8_t gImage_jd4[1024];
/*
uint8_t Array[] = {0x63, 0x66, 0xEE};
uint16_t RxDATA;
uint16_t RxArray[];
uint16_t i;
*/

uint8_t ADDRB[1025];

void LED_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
 	GPIO_Init(GPIOC, &GPIO_InitStructure);
	
	
}
int main(void)
{
	OLED_Init();
	SerialInit();
	DMAInit((uint32_t)ADDRB);
	OLED_ShowString(1,1,"hhh");
	Delay_ms(1000);
	OLED_Clear();
	//OLED_Show_Prcture(image_data);
	while(1)
	{
		OLED_Show_Prcture(ADDRB);
		
	}
	
}
