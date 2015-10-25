#include "led.h"

typedef struct {
GPIO_TypeDef * port;
uint16_t pin;
} MyLED_type;

enum {
    cLED1=0,
    cLED2,
    cLED3,
    cLED4,
    cLED5,
    cLED6
};

const MyLED_type ActiveLeds[cMaxActiveLeds] = {
    {GPIOA, GPIO_PIN_10},
    {GPIOB, GPIO_PIN_3},
    {GPIOB, GPIO_PIN_5},
    {GPIOB, GPIO_PIN_4},
    {GPIOB, GPIO_PIN_10},
    {GPIOA, GPIO_PIN_8}
};

void Single_Led_Init(uint8_t LedNum)
{
 GPIOB_CLK_ENABLE();
 GPIOA_CLK_ENABLE();
  GPIO_InitTypeDef  GPIO_InitStruct = {
      0, // Pin will be selected later
      GPIO_MODE_OUTPUT_PP, // LED is output
      GPIO_PULLDOWN, // pull down to help with reverse LED logic
      GPIO_SPEED_FAST,
      0 //not used
  };

  GPIO_InitStruct.Pin = ActiveLeds[LedNum].pin; // set current Pin
  HAL_GPIO_Init(ActiveLeds[LedNum].port, &GPIO_InitStruct); // init the GPIO

  HAL_GPIO_WritePin(ActiveLeds[LedNum].port, ActiveLeds[LedNum].pin, GPIO_PIN_SET);// LED off after init
}

void LED_Init(uint8_t LedCount)
{
     uint8_t LedInitCount = 0;

  for (LedInitCount = 0; LedInitCount < LedCount; LedInitCount++)
  {//initialize all LEDs on the board
      Single_Led_Init(LedInitCount);
  }
}

void LED_DeInit() {}

void LED_ON(uint8_t LedNum)
{
    HAL_GPIO_WritePin(ActiveLeds[LedNum].port, ActiveLeds[LedNum].pin,GPIO_PIN_RESET);
}
void LED_OFF(uint8_t LedNum)
{
    HAL_GPIO_WritePin(ActiveLeds[LedNum].port, ActiveLeds[LedNum].pin,GPIO_PIN_SET)
}

void LED_TOGGLE(uint8_t LedNum)
{
    HAL_GPIO_TogglePin(ActiveLeds[LedNum].port, ActiveLeds[LedNum].pin);
}