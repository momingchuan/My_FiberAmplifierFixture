
#include "SDPro.h"
//#include "main.h"
#include "dma.h"
//#include "fatfs.h"
#include "i2c.h"
#include "sdio.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "stdio.h"	//ʹ��printf���������õ�ͷ�ļ�
#include <string.h> 
#include <stdlib.h>
#include "processing.h"	
	
extern SD_HandleTypeDef hsd;
	
	/*
char  SDSaveData(void)
{
	
//	uint32_t sdcard_status=0;
	char FileDateStr[30]={0};
	char FileDataStr[50]={0};
	FRESULT f_res0,f_res1;
	FIL file;
	FATFS SD;


	

	if(comVariableBlock.SDInsertState==0)
	{
		
		sprintf(FileDateStr,"0:/%d-%d-%d.XLS",comVariableBlock.TimYear,comVariableBlock.TimMonth,comVariableBlock.TimDay);
		sprintf(FileDataStr,"%d:%d:%d\t%1.3f\t%1.3f\t%1.3f\t%1.3f\n",
		comVariableBlock.TimHour,
		comVariableBlock.TimMinute,
		comVariableBlock.TimSecond,
		USART_Data.USART1_Data.US1_b_Voltage0,
		USART_Data.USART1_Data.US1_b_Voltage2,
		USART_Data.USART1_Data.US1_b_Voltage3,
		USART_Data.USART1_Data.US1_b_Voltage6);
		f_res0=f_mount(&SD,"0:",1);
		if(f_res0 == FR_OK)
		{
		
			f_res1=f_open(&file,FileDateStr,FA_OPEN_EXISTING|FA_WRITE);//�ڸ�Ŀ¼�´���һ����User.XLS��EXCEL�ļ�������Ѿ����ڸ��ļ���д������
			if(f_res1 ==  FR_NO_FILE)
			{
				f_open(&file,FileDateStr,FA_CREATE_NEW|FA_WRITE);//			
				f_printf(&file,"ʱ��\t��ѹ��1\t��ѹ��2\t��ѹ��3\t��ѹ��4\n");//���ӱ���
			}
		
			f_lseek(&file,f_size(&file));//�ƶ��ļ���꣬�Ӷ�ʵ�����ݵ�׷��
			f_printf(&file,FileDataStr);//ͨ����\t�����л���Ԫ��ͨ��\r\n���л���
			f_close(&file);//�ر��ļ�
		}

	}else
	{
		if(HAL_GPIO_ReadPin(GPIOE,GPIO_PIN_0)==GPIO_PIN_SET)
		{
			return 0;
		}
		
		if(HAL_SD_Init(&hsd)==HAL_OK)
		{
			comVariableBlock.SDInsertState=0;
			HAL_Delay(100);
			SDSaveData();			
		}

	}
	
	return 0;
}
	*/
	
void SaveDataExScreen()
{
		char FileDataStr[1024]={0};
	    static char StrTemp[1024] = {0};
	  
		for (int i=0,j=0;i<30;i++,j++)
		{
			comVariableBlock.ID_SensorChanged[i]=comVariableBlock.ID_Sensor[j];
			if(i==20)
			{
				comVariableBlock.ID_SensorChanged[++i]=' ';
			}
		}
		
	    USART_Data.USART1_Data.US1_SendAutoAdd = 0;
		sprintf(FileDataStr,"%1.2d:%1.2d:%1.2d\t%5.3f\t%5.3f\t%5.3f\t%5.3f\t%5.4d\t%5.4d\t%5.4d\t%5.4d\t%5.4d\t%5.4d\t%5.4d\t%5.4d\t%5.3f\t%5.3f\t%7.3f\t%5.3f\t%5.3f\t%7.3f\t%5.3f\t%s %c%c",
		comVariableBlock.TimHour,
		comVariableBlock.TimMinute,
		comVariableBlock.TimSecond,
		USART_Data.USART1_Data.US1_b_Voltage0,
		USART_Data.USART1_Data.US1_b_Voltage2,
		USART_Data.USART1_Data.US1_b_Voltage3,
		USART_Data.USART1_Data.US1_b_Voltage6,
		USART_Data.USART1_Data.US1_CalibrationData[1],
		USART_Data.USART1_Data.US1_CalibrationData[2],
		USART_Data.USART1_Data.US1_CalibrationData[3],
		USART_Data.USART1_Data.US1_CalibrationData[4],
		USART_Data.USART1_Data.US1_CalibrationData[6],
		USART_Data.USART1_Data.US1_CalibrationData[7],
		USART_Data.USART1_Data.US1_CalibrationData[8],
		USART_Data.USART1_Data.US1_CalibrationData[9],
		USART_Data.USART1_Data.ConsumeCur,
		USART_Data.USART1_Data.US1_c_ValN1,
		USART_Data.USART1_Data.US1_c_ValN4,
		USART_Data.USART1_Data.US1_c_ValN5,
		USART_Data.USART1_Data.US1_c_ValP1,
		USART_Data.USART1_Data.US1_c_ValP4,
		USART_Data.USART1_Data.US1_c_ValP5,
		comVariableBlock.ID_SensorChanged,
		0x0d, 0x0a);
	  
	    sprintf((char *)StrTemp, "Date\tVol1\tVol2\tVol3\tVol4\tDAC_M\tCur_M\tVal_M\tWave_M\tDAC_H\tCur_H\tVal_H\tWave_H\tCCur\tLkge_N\tResC_N\tResV_N\tLkge_P\tResC_P\tResV_P\tID%c%c",0x0d, 0x0a);
		StringChangeLine(USART_Data.USART1_Data.US1_SendDataBuf[USART_Data.USART1_Data.US1_SendAutoAdd++], "mainDataStart.txt=",StrTemp, 1);
        StringChangeLine(USART_Data.USART1_Data.US1_SendDataBuf[USART_Data.USART1_Data.US1_SendAutoAdd++], "Data.dataRec.txt=", FileDataStr, 1);
        StringChangeLine(USART_Data.USART1_Data.US1_SendDataBuf[USART_Data.USART1_Data.US1_SendAutoAdd++], "mainDataFlag.val=2", " ", 1);
        ScreenTransmit(&USART_Data, USART_Data.USART1_Data.US1_SendDataBuf, USART_Data.USART1_Data.US1_SendAutoAdd, 1000);
}
	










	
	

