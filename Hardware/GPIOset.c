#include "Device/Include/stm32f10x.h"   // Device header

void GPIOCset_out(void){

	GPIO_InitTypeDef  GPIO_C_InitStruct;
	GPIO_C_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_C_InitStruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_C_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	GPIO_Init(GPIOC, &GPIO_C_InitStruct);

}

void GPIOB10set_out(void){

	GPIO_InitTypeDef  GPIO_B_InitStruct;
	GPIO_B_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_B_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_B_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_Init(GPIOB, &GPIO_B_InitStruct);

}

void GPIOAset_out(void){

	GPIO_InitTypeDef  GPIO_A_InitStruct;
	GPIO_A_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_A_InitStruct.GPIO_Pin = GPIO_Pin_All;
	GPIO_A_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_Init(GPIOA, &GPIO_A_InitStruct);

}

void ledon(void){
	GPIO_ResetBits(GPIOC, GPIO_Pin_13);

}

void ledoff(void){
	GPIO_SetBits(GPIOC, GPIO_Pin_13);

}
