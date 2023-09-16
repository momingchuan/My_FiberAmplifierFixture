/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "uiPro.h"
#include "config.h"
#include <string.h>
#include "usart.h"
#include "stdio.h"	//ʹ��printf���������õ�ͷ�ļ�
#include <stdlib.h>
#include "processing.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */
//UART_HandleTypeDef huart1;
//UART_HandleTypeDef huart2;
//UART_HandleTypeDef huart3;
//UART_HandleTypeDef huart6;
/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern DMA_HandleTypeDef hdma_i2c1_rx;
extern DMA_HandleTypeDef hdma_i2c1_tx;
extern I2C_HandleTypeDef hi2c1;
extern DMA_HandleTypeDef hdma_sdio_rx;
extern DMA_HandleTypeDef hdma_sdio_tx;
extern SD_HandleTypeDef hsd;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim4;
extern TIM_HandleTypeDef htim9;
extern DMA_HandleTypeDef hdma_uart4_rx;
extern DMA_HandleTypeDef hdma_uart4_tx;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;
extern UART_HandleTypeDef huart4;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart6;
/* USER CODE BEGIN EV */

extern unsigned char UART1_RX_BUF[RECEIVE_DATA_BUF_LEN_USART1];
extern unsigned char UART3_RX_BUF[RECEIVE_DATA_BUF_LEN_USART3];
extern unsigned char UART4_RX_BUF[RECEIVE_DATA_BUF_LEN_USART4];
extern unsigned char UART6_RX_BUF[RECEIVE_DATA_BUF_LEN_USART6];
extern unsigned char string[30];

 uint16_t UART_RX_STA;
 unsigned char ClearData[CLEAN_BUF_DATA]={0};
 
 
 
 void PVD_IRQHandler()
 {
	HAL_PWR_PVD_IRQHandler();
 
 }
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */
if(CoreDebug->DHCSR&1)
{
__breakpoint(0);
}
  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */
	static char Flag_data=0; 
	if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_0)==GPIO_PIN_SET)
	{
		comVariableBlock.SDInsertState=1;
	}
	
	uiTime();
	
	SYS_tickTime.sys_sendTime_ms++;
	SYS_tickTime.sys_MeasuringTime_ms++;
	SYS_tickTime.sys_WaitOutTime_ms++;
	SYS_tickTime.sys_LEDTime_ms++;
	SYS_tickTime.sys_Test_ms++;
	SYS_tickTime.sys_SendDataToScreen_ms++;

//	HAL_GPIO_TogglePin(LED_B1_GPIO_Port,LED_B1_Pin);
//	LED_B1(1)

//	if(SYS_tickTime.sys_ReceiveData_ms<10)
//	{
//		SYS_tickTime.sys_ReceiveData_ms++;
//	}

	
	
	
	
 BeepBeep(&comVariableBlock.BeepControl);
	
//	SYS_tickTime.sys_CheckoutTime_ms++;
  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles DMA1 stream0 global interrupt.
  */
void DMA1_Stream0_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream0_IRQn 0 */

  /* USER CODE END DMA1_Stream0_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_i2c1_rx);
  /* USER CODE BEGIN DMA1_Stream0_IRQn 1 */

  /* USER CODE END DMA1_Stream0_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream2 global interrupt.
  */
void DMA1_Stream2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream2_IRQn 0 */

  /* USER CODE END DMA1_Stream2_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_uart4_rx);
  /* USER CODE BEGIN DMA1_Stream2_IRQn 1 */

  /* USER CODE END DMA1_Stream2_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream4 global interrupt.
  */
void DMA1_Stream4_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream4_IRQn 0 */

  /* USER CODE END DMA1_Stream4_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_uart4_tx);
  /* USER CODE BEGIN DMA1_Stream4_IRQn 1 */

  /* USER CODE END DMA1_Stream4_IRQn 1 */
}

/**
  * @brief This function handles TIM1 break interrupt and TIM9 global interrupt.
  */
void TIM1_BRK_TIM9_IRQHandler(void)
{
  /* USER CODE BEGIN TIM1_BRK_TIM9_IRQn 0 */

  /* USER CODE END TIM1_BRK_TIM9_IRQn 0 */
  HAL_TIM_IRQHandler(&htim9);
  /* USER CODE BEGIN TIM1_BRK_TIM9_IRQn 1 */

  /* USER CODE END TIM1_BRK_TIM9_IRQn 1 */
}

/**
  * @brief This function handles TIM2 global interrupt.
  */
void TIM2_IRQHandler(void)
{
  /* USER CODE BEGIN TIM2_IRQn 0 */

  /* USER CODE END TIM2_IRQn 0 */
  HAL_TIM_IRQHandler(&htim2);
  /* USER CODE BEGIN TIM2_IRQn 1 */

  /* USER CODE END TIM2_IRQn 1 */
}

/**
  * @brief This function handles TIM4 global interrupt.
  */
void TIM4_IRQHandler(void)
{
  /* USER CODE BEGIN TIM4_IRQn 0 */
//10us��һ��
  /* USER CODE END TIM4_IRQn 0 */
  HAL_TIM_IRQHandler(&htim4);
  /* USER CODE BEGIN TIM4_IRQn 1 */
	
	if(SYS_tickTime.sys_ReceiveData_ms<120)
	{
		SYS_tickTime.sys_ReceiveData_ms++;	
	}

	if(SYS_tickTime.sys_ReceiveData_ms==120-2)
	{
//		__HAL_UART_CLEAR_IDLEFLAG(&huart4);  // ����жϱ��
		HAL_UART_DMAStop(&huart4);           // ֹͣDMA����		
		USART_Data.USART4_Data.US4_ReceiDataSucce_Flag = 1;/*������ɱ��λ*/
		UART_RX_STA =   RECEIVE_DATA_BUF_LEN_USART4 - __HAL_DMA_GET_COUNTER(huart4.hdmarx);  // ����������ȥδ���յ���������Ϊ�Ѿ����յ���������

		
		
//		UART4_RX_BUF[UART_RX_STA]   = '\0';  // ��ӽ�����
		memcpy(USART_Data.USART4_Data.US4_receiveData,UART4_RX_BUF,RECEIVE_DATA_BUF_LEN_USART4);/*��ȡ����*/
		
		if(strlen(UART4_RX_BUF)>30)//���ݽ��մ���
		{
			USART_Data.USART4_Data.US4_receiveData[0]='\0';
			comVariableBlock.DeviceStatus=DS_Error_USART4;
		}
		
		memset(UART4_RX_BUF,0,sizeof(UART4_RX_BUF));/*�������*/
		HAL_UART_Receive_DMA(&huart4, UART4_RX_BUF, RECEIVE_DATA_BUF_LEN_USART4);  // ��������DMA����	
	}

  /* USER CODE END TIM4_IRQn 1 */
}

/**
  * @brief This function handles I2C1 event interrupt.
  */
void I2C1_EV_IRQHandler(void)
{
  /* USER CODE BEGIN I2C1_EV_IRQn 0 */

  /* USER CODE END I2C1_EV_IRQn 0 */
  HAL_I2C_EV_IRQHandler(&hi2c1);
  /* USER CODE BEGIN I2C1_EV_IRQn 1 */

  /* USER CODE END I2C1_EV_IRQn 1 */
}

/**
  * @brief This function handles I2C1 error interrupt.
  */
void I2C1_ER_IRQHandler(void)
{
  /* USER CODE BEGIN I2C1_ER_IRQn 0 */

  /* USER CODE END I2C1_ER_IRQn 0 */
  HAL_I2C_ER_IRQHandler(&hi2c1);
  /* USER CODE BEGIN I2C1_ER_IRQn 1 */

  /* USER CODE END I2C1_ER_IRQn 1 */
}

/**
  * @brief This function handles USART1 global interrupt.
  */
void USART1_IRQHandler(void)
{
  /* USER CODE BEGIN USART1_IRQn 0 */

static	char letter='/';
  /* USER CODE END USART1_IRQn 0 */
  HAL_UART_IRQHandler(&huart1);
  /* USER CODE BEGIN USART1_IRQn 1 */

	
	if(__HAL_UART_GET_FLAG(&huart1, UART_FLAG_IDLE) != RESET)  // �����жϱ�Ǳ���λ���Ѿ�������
	{
		USART_Data.USART1_Data.US1_ReceiDataSucce_Flag = 1;/*������ɱ��λ*/
	    __HAL_UART_CLEAR_IDLEFLAG(&huart1);  // ����жϱ��
	    HAL_UART_DMAStop(&huart1);           // ֹͣDMA����
	    UART_RX_STA = RECEIVE_DATA_BUF_LEN_USART1 - __HAL_DMA_GET_COUNTER(huart1.hdmarx);  // ����������ȥδ���յ���������Ϊ�Ѿ����յ���������
				//	    UART1_RX_BUF[UART_RX_STA]   = '\n';  // ��ӽ�����
				//		UART1_RX_BUF[UART_RX_STA+1] = '\0';  // ����ַ���������
				//	    UART_RX_STA |= 0X8000;         // ��ǽ��ս���
		
		if(!(UART1_RX_BUF[0]==0x1a&& UART1_RX_BUF[1]==0xff&&UART1_RX_BUF[2]==0xff))//��Ļ������Ч�ؼ���
		{
			memcpy(USART_Data.USART1_Data.US1_ReceiveDataStr,UART1_RX_BUF,RECEIVE_DATA_BUF_LEN_USART1);/*��ȡ����*/
			memset(UART1_RX_BUF,0,sizeof(UART1_RX_BUF));/*�������*/
	//		memcpy(UART1_RX_BUF,ClearData,RECEIVE_DATA_BUF_LEN_USART1);/*�������*/
			
			
			memset(USART_Data.USART1_Data.US1_CutApartBuf,0,sizeof(USART_Data.USART1_Data.US1_CutApartBuf));//����
			StringSplitting((const char *)USART_Data.USART1_Data.US1_ReceiveDataStr,
			USART_Data.USART1_Data.US1_CutApartBuf,&letter);		
		}
	    HAL_UART_Receive_DMA(&huart1, UART1_RX_BUF, RECEIVE_DATA_BUF_LEN_USART1);  // ��������DMA����
	}


  /* USER CODE END USART1_IRQn 1 */
}

/**
  * @brief This function handles USART2 global interrupt.
  */
void USART2_IRQHandler(void)
{
  /* USER CODE BEGIN USART2_IRQn 0 */

  /* USER CODE END USART2_IRQn 0 */
  HAL_UART_IRQHandler(&huart2);
  /* USER CODE BEGIN USART2_IRQn 1 */



  /* USER CODE END USART2_IRQn 1 */
}

/**
  * @brief This function handles USART3 global interrupt.
  */
void USART3_IRQHandler(void)
{
  /* USER CODE BEGIN USART3_IRQn 0 */

  /* USER CODE END USART3_IRQn 0 */
  HAL_UART_IRQHandler(&huart3);
  /* USER CODE BEGIN USART3_IRQn 1 */

	if(__HAL_UART_GET_FLAG(&UART_HANDLE_POWER, UART_FLAG_IDLE) != RESET)  // �����жϱ�Ǳ���λ���Ѿ�������
	{
		USART_Data.USART3_Data.US3_ReceiDataSucce_Flag = 1;/*������ɱ��λ*/
	    __HAL_UART_CLEAR_IDLEFLAG(&UART_HANDLE_POWER);  // ����жϱ��
		HAL_UART_AbortReceive_IT(&UART_HANDLE_POWER);//��ֹ�жϽ���
		memcpy(USART_Data.USART3_Data.US3_ReceiveDataStr[USART_Data.USART3_Data.US3_ReceiDataSucceCount]
		,UART3_RX_BUF,RECEIVE_DATA_BUF_LEN_USART3);/*��ȡ����*/
		USART_Data.USART3_Data.US3_ReceiveDataNum[USART_Data.USART3_Data.US3_ReceiDataSucceCount] 
		= strtod((char *)USART_Data.USART3_Data.US3_ReceiveDataStr[USART_Data.USART3_Data.US3_ReceiDataSucceCount],NULL);	
		
memset(UART3_RX_BUF,0,sizeof(UART3_RX_BUF));/*�������*/
//		memcpy(UART3_RX_BUF,ClearData,RECEIVE_DATA_BUF_LEN_USART1);/*�������*/
		HAL_UART_Receive_IT(&UART_HANDLE_POWER,UART3_RX_BUF,RECEIVE_DATA_BUF_LEN_USART3);//������������
		
		USART_Data.USART3_Data.US3_ReceiDataSucceCount++;
	}
	
	
  /* USER CODE END USART3_IRQn 1 */
}

/**
  * @brief This function handles DMA1 stream7 global interrupt.
  */
void DMA1_Stream7_IRQHandler(void)
{
  /* USER CODE BEGIN DMA1_Stream7_IRQn 0 */

  /* USER CODE END DMA1_Stream7_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_i2c1_tx);
  /* USER CODE BEGIN DMA1_Stream7_IRQn 1 */

	
  /* USER CODE END DMA1_Stream7_IRQn 1 */
}

/**
  * @brief This function handles SDIO global interrupt.
  */
void SDIO_IRQHandler(void)
{
  /* USER CODE BEGIN SDIO_IRQn 0 */

  /* USER CODE END SDIO_IRQn 0 */
  HAL_SD_IRQHandler(&hsd);
  /* USER CODE BEGIN SDIO_IRQn 1 */

  /* USER CODE END SDIO_IRQn 1 */
}

/**
  * @brief This function handles UART4 global interrupt.
  */
void UART4_IRQHandler(void)
{
  /* USER CODE BEGIN UART4_IRQn 0 */

  /* USER CODE END UART4_IRQn 0 */
  HAL_UART_IRQHandler(&huart4);
  /* USER CODE BEGIN UART4_IRQn 1 */

	
	if(__HAL_UART_GET_FLAG(&huart4, UART_FLAG_IDLE) != RESET)  // �����жϱ�Ǳ���λ���Ѿ�������
	{
		__HAL_UART_CLEAR_IDLEFLAG(&huart4);  // ����жϱ��
		SYS_tickTime.sys_ReceiveData_ms=0;
//		__HAL_UART_CLEAR_IDLEFLAG(&huart4);  // ����жϱ��
//		HAL_UART_DMAStop(&huart4);           // ֹͣDMA����		
//		USART_Data.USART4_Data.US4_ReceiDataSucce_Flag = 1;/*������ɱ��λ*/
//		UART_RX_STA = RECEIVE_DATA_BUF_LEN_USART1 - __HAL_DMA_GET_COUNTER(huart4.hdmarx);  // ����������ȥδ���յ���������Ϊ�Ѿ����յ���������

//		UART4_RX_BUF[UART_RX_STA]   = '\0';  // ��ӽ�����
//	//		UART1_RX_BUF[UART_RX_STA+1] = '\0';  // ����ַ���������
//		memcpy(USART_Data.USART4_Data.US4_receiveData,UART4_RX_BUF,RECEIVE_DATA_BUF_LEN_USART4);/*��ȡ����*/
//		memset(UART4_RX_BUF,0,sizeof(UART4_RX_BUF));/*�������*/
//	//		memcpy(UART4_RX_BUF,ClearData,RECEIVE_DATA_BUF_LEN_USART4);/*�������*/
//		HAL_UART_Receive_DMA(&huart4, UART4_RX_BUF, RECEIVE_DATA_BUF_LEN_USART4);  // ��������DMA����	

		
	}
	
	
	
  /* USER CODE END UART4_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream2 global interrupt.
  */
void DMA2_Stream2_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream2_IRQn 0 */

  /* USER CODE END DMA2_Stream2_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_rx);
  /* USER CODE BEGIN DMA2_Stream2_IRQn 1 */

  /* USER CODE END DMA2_Stream2_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream3 global interrupt.
  */
void DMA2_Stream3_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream3_IRQn 0 */

  /* USER CODE END DMA2_Stream3_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_sdio_rx);
  /* USER CODE BEGIN DMA2_Stream3_IRQn 1 */

  /* USER CODE END DMA2_Stream3_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream6 global interrupt.
  */
void DMA2_Stream6_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream6_IRQn 0 */

  /* USER CODE END DMA2_Stream6_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_sdio_tx);
  /* USER CODE BEGIN DMA2_Stream6_IRQn 1 */

  /* USER CODE END DMA2_Stream6_IRQn 1 */
}

/**
  * @brief This function handles DMA2 stream7 global interrupt.
  */
void DMA2_Stream7_IRQHandler(void)
{
  /* USER CODE BEGIN DMA2_Stream7_IRQn 0 */

  /* USER CODE END DMA2_Stream7_IRQn 0 */
  HAL_DMA_IRQHandler(&hdma_usart1_tx);
  /* USER CODE BEGIN DMA2_Stream7_IRQn 1 */

	
	
  /* USER CODE END DMA2_Stream7_IRQn 1 */
}

/**
  * @brief This function handles USART6 global interrupt.
  */
void USART6_IRQHandler(void)
{
  /* USER CODE BEGIN USART6_IRQn 0 */

  /* USER CODE END USART6_IRQn 0 */
  HAL_UART_IRQHandler(&huart6);
  /* USER CODE BEGIN USART6_IRQn 1 */
	
	if(__HAL_UART_GET_FLAG(&UART_HANDLE_MULTIMETER, UART_FLAG_IDLE) != RESET)  // �����жϱ�Ǳ���λ���Ѿ�������
	{
		USART_Data.USART6_Data.US6_ReceiDataSucce_Flag = 1;/*������ɱ��λ*/
	    __HAL_UART_CLEAR_IDLEFLAG(&UART_HANDLE_MULTIMETER);  // ����жϱ��
		HAL_UART_AbortReceive_IT(&UART_HANDLE_MULTIMETER);//��ֹ�жϽ���
		memcpy(USART_Data.USART6_Data.US6_ReceiveDataStr[USART_Data.USART6_Data.US6_ReceiDataSucceCount]
		,UART6_RX_BUF,RECEIVE_DATA_BUF_LEN_USART6);/*��ȡ����*/
		
		USART_Data.USART6_Data.US6_ReceiveDataNum[USART_Data.USART6_Data.US6_ReceiDataSucceCount] 
		= strtod((char *)USART_Data.USART6_Data.US6_ReceiveDataStr[USART_Data.USART6_Data.US6_ReceiDataSucceCount],NULL);	
		if(USART_Data.USART6_Data.US6_ReceiveDataNum[USART_Data.USART6_Data.US6_ReceiDataSucceCount] >1000)
		{
			USART_Data.USART6_Data.US6_ReceiveDataNum[USART_Data.USART6_Data.US6_ReceiDataSucceCount]=0;
		}
		memset(UART6_RX_BUF,0,sizeof(UART6_RX_BUF));/*�������*/
//		memcpy(UART6_RX_BUF,ClearData,RECEIVE_DATA_BUF_LEN_USART6);/*�������*/
		HAL_UART_Receive_IT(&UART_HANDLE_MULTIMETER,UART6_RX_BUF,RECEIVE_DATA_BUF_LEN_USART6);//������������
		USART_Data.USART6_Data.US6_ReceiDataSucceCount++;
		
	}
	
  /* USER CODE END USART6_IRQn 1 */
}

/* USER CODE BEGIN 1 */



void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{

	
	if(huart->Instance == UART_SCREEN)//������
	{
		USART_Data.USART1_Data.US1_SendDataSucce_Flag = 1;
	}else 	if(huart->Instance == UART_POWER)
	{
	  USART_Data.USART3_Data.US3_SendDataSucce_Flag=1;
	}else if(huart->Instance == UART_MULTIMETER)
	{
	  USART_Data.USART6_Data.US6_SendDataSucce_Flag=1;
	}else if(huart->Instance == UART_SENSOR)
	{
	  USART_Data.USART4_Data.US4_SendDataSucce_Flag=1;
	}

	
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{


//	if(huart->Instance == UART_POWER)//�̿ص�Դ
//	{

//		HAL_UART_Receive_IT(&UART_HANDLE_POWER,USART_Data.USART3_Data.US3_receiveData,8);
//	}


}



/* USER CODE END 1 */
