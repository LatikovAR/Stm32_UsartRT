#include "F05_RCC.h"
#include "GPIO.h"
#include "NVIC.h"
#include "DS18B20.h"

#include "stdio.h"

void TIM2_IRQHandler() {
  USART1->TDR = 0x5;
}

void USARTInit(uint32_t PPin, uint32_t BaudRate) {
  GPIO_Mode(PPin, MODE_ALTERNATE);
  GET_PORT(PPin)->AFR[0] = AF1;
  
  USART1->CR3 |= USART_CR3_HDSEL;
  USART1->BRR = BaudRate;
  
  USART1->CR1 |= USART_CR1_TE;
  USART1->CR1 |= USART_CR1_RE;
  USART1->CR1 |= USART_CR1_UE;
}

void RCCInit() {
  HSI_START();
  PLL_MUL(2);
  PLLSourse(PLLSRC_HSI_DIV2);
  PLL_START();
  
  SET_AHB_PRESCALLER(AHB_DIV1); //48 MHz
  SET_APB_PRESCALLER(APB_DIV1); //48 MHz
}

void TIM2InterruptionInit() {
  RCC->APB1ENR |= RCC_APB1RSTR_TIM2RST;
  TIM2->CNT = 0x0;
  TIM2->ARR = 0x3E8; //1000ms
  TIM2->PSC = 0xBB7F; //to 1 ms
  TIM2->EGR |= TIM_EGR_UG;
  TIM2->SR &= ~TIM_SR_UIF;
  TIM2->DIER |= TIM_DIER_UIE; 
  NVIC_EnableIRQ(TIM2_IRQn); 
  __enable_irq();
}

int main()
{
  FLASH_LATENCY_1WS();
  FLASH_PREFETCH_ON();
  RCCInit();
  USARTInit(PA0, 0x4E20);
  TIM2InterruptionInit();
  
  TIM2->CR1 |= TIM_CR1_CEN;
  
  return 0;
}