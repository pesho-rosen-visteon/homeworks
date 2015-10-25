#include<uart.h>
#include <stdlib.h>

static void Error_Handler(void);

UART_HandleTypeDef UartHandle;
static uint8_t u8ReceivedData[10];

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  /*##-1- Enable peripherals and GPIO Clocks #################################*/
  /* Enable GPIO TX/RX clock */
  USARTx_TX_GPIO_CLK_ENABLE();
  USARTx_RX_GPIO_CLK_ENABLE();

  /* Enable USARTx clock */
  USARTx_CLK_ENABLE();

  /*##-2- Configure peripheral GPIO ##########################################*/
  /* UART TX GPIO pin configuration  */
  GPIO_InitStruct.Pin       = USARTx_TX_PIN;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FAST;
  GPIO_InitStruct.Alternate = USARTx_TX_AF;

  HAL_GPIO_Init(USARTx_TX_GPIO_PORT, &GPIO_InitStruct);

  /* UART RX GPIO pin configuration  */
  GPIO_InitStruct.Pin = USARTx_RX_PIN;
  GPIO_InitStruct.Alternate = USARTx_RX_AF;

  HAL_GPIO_Init(USARTx_RX_GPIO_PORT, &GPIO_InitStruct);

  HAL_NVIC_SetPriority(USART6_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(USART6_IRQn);
}

void UART_Init(){
  UartHandle.Instance          = USARTx;

  UartHandle.Init.BaudRate     = 9600;
  UartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
  UartHandle.Init.StopBits     = UART_STOPBITS_1;
  UartHandle.Init.Parity       = UART_PARITY_ODD;
  UartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  UartHandle.Init.Mode         = UART_MODE_TX_RX;
  UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;

  if(HAL_UART_Init(&UartHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }
}

void UART_MainFunction(){


    HAL_UART_Receive_IT(&UartHandle, u8ReceivedData, 10);
}

void UART_DeInit(){

}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    //message send

}

int i;
int j = 0;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    char funcType[5];
    char funcParam[5];
	
	Process_FuncType(&funcType);
	Process_FuncParam(&funcParam)
	
    int function_type = (int)strtol(funcType, NULL, 0);
    int function_parameter = (int)strtol(funcParam, NULL, 0);

/**/
    Process_Command(function_type);
}

private void Process_FuncType(char* funcType){
	for(i=0;i<4;i++){
        funcType[i] = u8ReceivedData[i];
    }
	
	funcType[4] = '\0';
}

private void Process_FuncParam(char* funcParam){
	for(i=6;i<10;i++){
        funcParam[j] = u8ReceivedData[i];
        j++;
    }

    funcParam[4] = '\0';
}

private void Process_Command(function_type){
	switch(function_type){
        case 1:
            break;
        default:
            break;
    }
}

static void Error_Handler(void)
{
  while(1)
  {
  }
}
