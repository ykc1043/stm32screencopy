#include "Device/Include/stm32f10x.h"   // Device header
#include "Delay.h"


void GPIOBset_in(void){

	GPIO_InitTypeDef  GPIO_B_InitStruct;
	GPIO_B_InitStruct.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_B_InitStruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_B_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_Init(GPIOB, &GPIO_B_InitStruct);

}

uint8_t GetKeyNUM(void){

	uint8_t KeyNUM = 0;
	if(KeyNUM == 0){
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0){
			Delay_ms(20);
			while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0);
			Delay_ms(20);
			KeyNUM = 1;
		}
	}
	
	if(KeyNUM == 1){
		if (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0){
			Delay_ms(20);
			while (GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11) == 0);
			Delay_ms(20);
			KeyNUM = 0;
		}
	}
	Delay_s(3);
	



	return KeyNUM;
}

uint8_t testKeyNUM(void){
	uint8_t KeyNUM = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
	return KeyNUM;
}
	
