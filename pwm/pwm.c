#include "pwm.h"

TIM_HandleTypeDef    TimHandle;

TIM_OC_InitTypeDef sConfig;

uint32_t uwPrescalerValue = 0;

void InitHal(){
	HAL_Init();
}

void InitTimHandleStruct(){
  TimHandle.Instance = TIMx;

  TimHandle.Init.Prescaler     = 4;
  TimHandle.Init.Period        = PERIOD_VALUE;
  TimHandle.Init.ClockDivision = 0;
  TimHandle.Init.CounterMode   = TIM_COUNTERMODE_UP;
}

void PWMInit(){
	HAL_TIM_PWM_Init(&TimHandle);
}

void InitSConfigStruct(){
  sConfig.OCMode     = TIM_OCMODE_PWM1;
  sConfig.OCPolarity = TIM_OCPOLARITY_LOW;
  sConfig.OCFastMode = TIM_OCFAST_DISABLE;
}

void InitPWMFirstChannel(){
	sConfig.Pulse = PULSE1_VALUE;
	HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_1);
}

void InitPWMSecondChannel(){
	sConfig.Pulse = PULSE4_VALUE;
	HAL_TIM_PWM_ConfigChannel(&TimHandle, &sConfig, TIM_CHANNEL_2);
}

void StartFirstChannel(){
	HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_1);
}

void StartSecondChannel(){
	HAL_TIM_PWM_Start(&TimHandle, TIM_CHANNEL_2);
}

void ChangePulse(uint16_t pulse){
	sConfig.Pulse = pulse;
	HAL_TIM_PWM_ChangePulseWeith(&TimHandle, &sConfig, TIM_CHANNEL_1);
	HAL_TIM_PWM_ChangePulseWeith(&TimHandle, &sConfig, TIM_CHANNEL_2);
}

void Deinit(){}