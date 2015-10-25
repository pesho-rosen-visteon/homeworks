#include "main.h"
#include "stm32f4xx_hal_tim.h"

#define  PERIOD_VALUE       (1800 - 1)  /* Period Value  */
#define  PULSE1_VALUE       1350        /* Capture Compare 1 Value  */
#define  PULSE2_VALUE       900         /* Capture Compare 2 Value  */
#define  PULSE3_VALUE       600         /* Capture Compare 3 Value  */
#define  PULSE4_VALUE       5           /* Capture Compare 4 Value  */
#define  MAX_LIGHT_VALUE    4096        /* Max value of light transistor */

void InitHal();

void InitTimHandleStruct();

void PWMInit();

void InitSConfigStruct();

void InitPWMFirstChannel();

void InitPWMSecondChannel();

void StartFirstChannel();

void StartSecondChannel();

void ChangePulse(uint16_t pulse);

void Deinit();