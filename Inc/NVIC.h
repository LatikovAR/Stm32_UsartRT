#ifndef NVIC_H
#define NVIC_H

#include "stm32f0xx.h"
#include "GPIO.h"

void delay(uint32_t us) {
  SysTick->LOAD = (SystemCoreClock / 8000000) * us;
  SysTick->VAL = 0x0;  //init value
  SysTick->CTRL = 0x1; //enable timer
  while(!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)) {}
  SysTick->CTRL = 0x0;
}

#endif //NVIC_H