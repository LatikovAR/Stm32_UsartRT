#ifndef GPIO_H
#define GPIO_H

#include "stm32f0xx.h"
#include "system_stm32f0xx.h"

#define PA 0x0
#define PB 0x1
#define PC 0x2
#define PD 0x3

#define PA0     (GPIO_BSRR_BS_0  | (0x0000<<16))
#define PA1     (GPIO_BSRR_BS_1  | (0x0000<<16))
#define PA2     (GPIO_BSRR_BS_2  | (0x0000<<16))
#define PA3     (GPIO_BSRR_BS_3  | (0x0000<<16))
#define PA4     (GPIO_BSRR_BS_4  | (0x0000<<16))
#define PA5     (GPIO_BSRR_BS_5  | (0x0000<<16))
#define PA6     (GPIO_BSRR_BS_6  | (0x0000<<16))
#define PA7     (GPIO_BSRR_BS_7  | (0x0000<<16))
#define PA8     (GPIO_BSRR_BS_8  | (0x0000<<16))
#define PA9     (GPIO_BSRR_BS_9  | (0x0000<<16))
#define PA10    (GPIO_BSRR_BS_10 | (0x0000<<16))
#define PA11    (GPIO_BSRR_BS_11 | (0x0000<<16))
#define PA12    (GPIO_BSRR_BS_12 | (0x0000<<16))
#define PA13    (GPIO_BSRR_BS_13 | (0x0000<<16))
#define PA14    (GPIO_BSRR_BS_14 | (0x0000<<16))
#define PA15    (GPIO_BSRR_BS_15 | (0x0000<<16))

#define PB0     (GPIO_BSRR_BS_0  | (0x0001<<16))
#define PB1     (GPIO_BSRR_BS_1  | (0x0001<<16))
#define PB2     (GPIO_BSRR_BS_2  | (0x0001<<16))
#define PB3     (GPIO_BSRR_BS_3  | (0x0001<<16))
#define PB4     (GPIO_BSRR_BS_4  | (0x0001<<16))
#define PB5     (GPIO_BSRR_BS_5  | (0x0001<<16))
#define PB6     (GPIO_BSRR_BS_6  | (0x0001<<16))
#define PB7     (GPIO_BSRR_BS_7  | (0x0001<<16))
#define PB8     (GPIO_BSRR_BS_8  | (0x0001<<16))
#define PB9     (GPIO_BSRR_BS_9  | (0x0001<<16))
#define PB10    (GPIO_BSRR_BS_10 | (0x0001<<16))
#define PB11    (GPIO_BSRR_BS_11 | (0x0001<<16))
#define PB12    (GPIO_BSRR_BS_12 | (0x0001<<16))
#define PB13    (GPIO_BSRR_BS_13 | (0x0001<<16))
#define PB14    (GPIO_BSRR_BS_14 | (0x0001<<16))
#define PB15    (GPIO_BSRR_BS_15 | (0x0001<<16))

#define PC0     (GPIO_BSRR_BS_0  | (0x0002<<16))
#define PC1     (GPIO_BSRR_BS_1  | (0x0002<<16))
#define PC2     (GPIO_BSRR_BS_2  | (0x0002<<16))
#define PC3     (GPIO_BSRR_BS_3  | (0x0002<<16))
#define PC4     (GPIO_BSRR_BS_4  | (0x0002<<16))
#define PC5     (GPIO_BSRR_BS_5  | (0x0002<<16))
#define PC6     (GPIO_BSRR_BS_6  | (0x0002<<16))
#define PC7     (GPIO_BSRR_BS_7  | (0x0002<<16))
#define PC8     (GPIO_BSRR_BS_8  | (0x0002<<16))
#define PC9     (GPIO_BSRR_BS_9  | (0x0002<<16))
#define PC10    (GPIO_BSRR_BS_10 | (0x0002<<16))
#define PC11    (GPIO_BSRR_BS_11 | (0x0002<<16))
#define PC12    (GPIO_BSRR_BS_12 | (0x0002<<16))
#define PC13    (GPIO_BSRR_BS_13 | (0x0002<<16))
#define PC14    (GPIO_BSRR_BS_14 | (0x0002<<16))
#define PC15    (GPIO_BSRR_BS_15 | (0x0002<<16))

#define  AF0                       (0x0000000U)
#define  AF1                       (0x0000001U)
#define  AF2                       (0x0000002U)
#define  AF3                       (0x0000003U)
#define  AF4                       (0x0000004U)
#define  AF5                       (0x0000005U)
#define  AF6                       (0x0000006U)
#define  AF7                       (0x0000007U)
#define  AF8                       (0x0000008U)
#define  AF9                       (0x0000009U)
#define  AF10                      (0x000000AU)
#define  AF11                      (0x000000BU)
#define  AF12                      (0x000000CU)
#define  AF13                      (0x000000DU)
#define  AF14                      (0x000000EU)
#define  AF15                      (0x000000FU)

#define  MODE_INPUT                (0x00000000U)               
#define  MODE_OUTPUT               GPIO_MODER_MODER0_0         
#define  MODE_ALTERNATE            GPIO_MODER_MODER0_1         
#define  MODE_ANALOG               GPIO_MODER_MODER0           

#define  PULL_NO                   (0x00000000U)               
#define  PULL_UP                   GPIO_PUPDR_PUPDR0_0         
#define  PULL_DOWN                 GPIO_PUPDR_PUPDR0_1         

#define  SPEED_LOW                 (0x00000000U)               
#define  SPEED_MEDIUM              GPIO_OSPEEDER_OSPEEDR0_0   
#define  SPEED_HIGH                GPIO_OSPEEDER_OSPEEDR0_1   
#define  SPEED_VERY_HIGH           GPIO_OSPEEDER_OSPEEDR0     

#define  TYPE_PUSHPULL             (0x00000000U)               
#define  TYPE_OPENDRAIN            GPIO_OTYPER_OT_0            

inline uint32_t POSITION_VAL(uint32_t VAL) {
  uint32_t pos = 0;
  VAL = VAL >> 1;
  while(VAL != 0) {
    pos = pos + 1;
    VAL = VAL >> 1;
  }
  return pos;
}

#define GET_PORT(PPin)     ((GPIO_TypeDef *)(((uint32_t)GPIOA) + ((PPin >> 6) && ~0x3FF)))
#define GET_PIN(PPin)      (PPin & 0xFFFF)

inline void GPIO_PinSet(uint32_t PPin)  { GET_PORT(PPin)->BSRR = GET_PIN(PPin); }
inline void GPIO_PinReset(uint32_t PPin)  { GET_PORT(PPin)->BSRR = (GET_PIN(PPin) << 16); }

//not atomic
inline void GPIO_PinInvert(uint32_t PPin) { GET_PORT(PPin)->ODR = (GET_PORT(PPin)->ODR) ^ GET_PIN(PPin); }

inline uint32_t GPIO_IsPinSet(uint32_t PPin) { return (((GET_PORT(PPin)->IDR) & GET_PIN(PPin)) == GET_PIN(PPin)); }
inline uint32_t GPIO_ReadPort(uint32_t Port) { return ((GPIO_TypeDef *)((uint32_t)GPIOA + (Port << 10)))->IDR; }
inline void GPIO_WritePort(uint32_t Port, uint32_t PortValue) { ((GPIO_TypeDef *)((uint32_t)GPIOA + (Port << 10)))->ODR = PortValue; }

inline void GPIO_Mode(uint32_t PPin, uint32_t Mode){
  
 uint32_t Pin = GET_PIN(PPin); 
 uint32_t Position = POSITION_VAL(Pin); 
 while(Pin !=0){    
   MODIFY_REG(GET_PORT(PPin)->MODER, (0x03UL<<(Position * 2U)), (Mode<<(Position * 2U)));
   Pin &= ~(1U<<Position);
   Position = POSITION_VAL(Pin);  
 }
}

inline void GPIO_Pin(uint32_t PPin, uint32_t Mode, uint32_t Pull, uint32_t Alternate){
  
 uint32_t Pin = GET_PIN(PPin); 
 uint32_t Position = POSITION_VAL(Pin);
 RCC->AHBENR |= RCC_AHBENR_GPIOAEN << (PPin >> 26);     //GPIO clock
 while(Pin !=0){ 
   MODIFY_REG(GET_PORT(PPin)->PUPDR, (0x03UL<<(Position * 2U)), (Pull<<(Position * 2U))); //Pull config
   MODIFY_REG(GET_PORT(PPin)->MODER, (0x03UL<<(Position * 2U)), (Mode<<(Position * 2U))); //Mode config  
   MODIFY_REG(GET_PORT(PPin)->AFR[(Position / 8)], (0x0FUL<<((Position%8UL) * 4U)), (Alternate<<((Position%8UL) * 4U))); //AF config 
   MODIFY_REG(GET_PORT(PPin)->OSPEEDR, (0x03UL<<(Position * 2U)), (SPEED_HIGH<<(Position * 2U))); //Speed config  
   Pin &= ~(1U<<Position);
   Position = POSITION_VAL(Pin);  
 }  
}

inline void GPIO_Speed(uint32_t PPin, uint32_t Speed){
  
 uint32_t Pin = GET_PIN(PPin); 
 uint32_t Position = POSITION_VAL(Pin);
 while(Pin !=0){    
   MODIFY_REG(GET_PORT(PPin)->OSPEEDR, (0x03UL<<(Position * 2U)), (Speed<<(Position * 2U)));
   Pin &= ~(1U<<Position);
   Position = POSITION_VAL(Pin);  
 } 
}

inline void GPIO_Type(uint32_t PPin, uint32_t Type){
  
 uint32_t Pin = GET_PIN(PPin); 
 uint32_t Position = POSITION_VAL(Pin);
 while(Pin !=0){    
   MODIFY_REG(GET_PORT(PPin)->OTYPER, GET_PIN(PPin), (Type * (GET_PIN(PPin))));
   Pin &= ~(1U<<Position);
   Position = POSITION_VAL(Pin);  
 }       
}
#endif //GPIO_H