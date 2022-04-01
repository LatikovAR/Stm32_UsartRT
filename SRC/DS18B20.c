#include "DS18B20.h"

static void write_byte(const uint8_t byte);
static uint8_t read_bit(void);
static uint8_t get_devider(const DS18B20_RESOLUTION_t resolution);
static uint16_t read_temperature(void);
static uint32_t reset(void);
static uint32_t convert_delay = DELAY_T_CONVERT;

static void delay_us(uint32_t microseconds)
{
  /*
  max 1 us
  max 2.796202 s per 48MHz Core clock 
  */  
  SysTick->VAL   = 0UL; 
  SysTick->LOAD  = (uint32_t)(SystemCoreClock/8000000*microseconds);
  SysTick->CTRL = 0x1UL;

  while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
  SysTick->CTRL =0UL;   
}


uint32_t reset(void) 
{     
   GPIO_PinReset(DataPin);
   delay_us(DELAY_RESET);
   GPIO_PinSet(DataPin);    
   delay_us(DELAY_PRESENCE);
   if(GPIO_IsPinSet(DataPin)==0UL)
   {
     delay_us(DELAY_RESET);
     return 1; 
   } 
   else
   {
     delay_us(DELAY_RESET);
     return 0;
   }  
}
                                                

void write_byte(uint8_t data) 
{
    for (uint8_t i = 0; i < 8; i++)
    {
        GPIO_PinReset(DataPin);
        delay_us((data >> i & 0x01) ? DELAY_WRITE_1 : DELAY_WRITE_0);
        GPIO_PinSet(DataPin);
        delay_us((data >> i & 0x01) ? DELAY_WRITE_1_PAUSE : DELAY_WRITE_0_PAUSE);
        delay_us(DELAY_RELAXATION);
    }
}


uint8_t read_bit(void)
{
  uint8_t bit = 0;

  GPIO_PinReset(DataPin);
  delay_us(DELAY_READ_SLOT);
  GPIO_PinSet(DataPin);
  delay_us(DELAY_BUS_RELAX);
  bit = (uint8_t)GPIO_IsPinSet(DataPin);
  delay_us(DELAY_READ_PAUSE); 
  
  return bit;
 
}

uint16_t read_temperature(void) 
{
  uint16_t data = 0;
  for (uint8_t i = 0; i < 16; i++)
    data += (uint16_t) read_bit() << i;
  return  data;
}

uint8_t get_devider(const DS18B20_RESOLUTION_t resolution) {
    uint8_t devider;
    switch (resolution) {
    case DS18B20_Resolution_9_bit:
        devider = 8;
        break;
    case DS18B20_Resolution_10_bit:
        devider = 4;
        break;
    case DS18B20_Resolution_11_bit:
        devider = 2;
        break;
    case DS18B20_Resolution_12_bit:
    default:
        devider = 1;
        break;
    }
    return devider;
}

void DS18B20_set_resolution(const DS18B20_RESOLUTION_t resolution)
{
   reset();                      // send reset     
   write_byte(SKIP_ROM);         // work only with one device
   write_byte(WRITE_SCRATCHPAD); // set resolution
   write_byte(TH_REGISTER);      //
   write_byte(TL_REGISTER);      //
   write_byte(resolution);       //
   convert_delay = DELAY_T_CONVERT / get_devider(resolution); // calc conversation delay  
}

void DS18B20_init(DS18B20_RESOLUTION_t resolution)
{
  
  GPIO_Pin(DataPin, MODE_OUTPUT, PULL_UP, AF0);
  GPIO_Speed(DataPin, SPEED_HIGH);
  GPIO_Type(DataPin, TYPE_OPENDRAIN);
  //you must use external pull up with 4.7Kohm
  DS18B20_set_resolution(DS18B20_Resolution_12_bit);
}

uint16_t DS18B20_get_temperature() {
  uint16_t pres = reset();  
  write_byte(SKIP_ROM);
  write_byte(CONVERT_T);
            
  GPIO_Type(DataPin, TYPE_PUSHPULL);
  GPIO_PinSet(DataPin);
  delay_us(convert_delay);
  GPIO_Type(DataPin, TYPE_OPENDRAIN);
    
  reset();
  write_byte(SKIP_ROM);
  write_byte(READ_SCRATCHPAD);
    
  return read_temperature();
}

