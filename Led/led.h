#include "stm32f4xx_hal_gpio.h"
#include "stm32f4xx_hal.h"
#include "stm32f401xe.h"

#define GPIOB_CLK_ENABLE()  __HAL_RCC_GPIOB_CLK_ENABLE();//enable GPIOB Clock
#define GPIOA_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE();//enable GPIOA Clock
#define cMaxActiveLeds 6

void Single_Led_Init(uint8_t LedNum);
void LED_Init(uint8_t LedCount);
void LED_DeInit();
void LED_ON(uint8_t LedNum);
void LED_OFF(uint8_t LedNum);
void LED_TOGGLE(uint8_t LedNum);
