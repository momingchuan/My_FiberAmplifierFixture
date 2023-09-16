/* */
/**
  ******************************************************************************
  * @file    
  * @brief   
  *          
  ******************************************************************************
  * @attention
  *
  * 
  *
  *
  * 
  * 
  * 
  *
  ******************************************************************************
  */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif


	#define CutApartBufLen 50
	
	
#define RECEIVE_REAL_DATA 100
#define CLEAN_BUF_DATA 50
	
#define SendDataBuf_Len 200
	
#define  RECEIVE_DATA_BUF_LEN_USART1 1000/*buf����ĳ���*/
	
#define  RECEIVE_DATA_BUF_LEN_USART3 50/*buf����ĳ���*/

#define  RECEIVE_DATA_BUF_LEN_USART4 RECEIVE_REAL_DATA/*buf����ĳ���*/	
	
#define  RECEIVE_DATA_BUF_LEN_USART6 RECEIVE_REAL_DATA/*buf����ĳ���*/	
	
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned int u32;
	
	typedef enum _pageNumType
	{
		page_main,
		page_CurConsume_T,
		page_KV_T,
		page_HL_T,
		page_Setting,
		page_Data,
		page_Button,
		page_Calibration,
		page_NNNNNNNO,
	
	}pageNumType;
	
//
	typedef enum _MeasureResults
	{
		ResultsTesting,
		ResultsSuccess,
		ResultsFail,
		ResultsStop,
		ResultsNULL,
		
	}MeasureResultsType;
	
	typedef enum _DeviceStatus
	{
		DS_Error_USART4,
		DS_Non,

		
	}DeviceStatusType;
	

    typedef enum _MainStep
	{
		MS_SelfChecking,
		MS_PageKeyVoltage_T,
		MS_PageReversePower_T,
		MS_Calibration,
		MS_NixieTube,
		MS_PageCurConsume_T,
		MS_ExternalInputLine,
		MS_HighLowLoad,
		MS_ButtonCheck,
		MS_SaveData,
		MS_non
		
	}MainStepType;
	
	typedef struct _USART_DataType
	{
//		char SeparatorString;
		
		struct 
		{
			
			
			//pageҳ��
			pageNumType PageNum;
			pageNumType PageNumChange;
			
			//page a ���ĵ���
			float US1_a_Voltage;/*��ѹ*/
			float US1_a_Max_mA; /*������*/
			float US1_a_Min_mA; /*��С����*/
			//page b �ؼ���ѹ
			
			float US1_b_Voltage0;/*��ѹ*/
			float US1_b_Voltage1;/*��ѹ*/
			float US1_b_Voltage2;/*��ѹ*/
			float US1_b_Voltage3;/*��ѹ*/
			float US1_b_Voltage4;/*��ѹ*/
			float US1_b_Voltage5;/*��ѹ*/
			float US1_b_Voltage6;/*��ѹ*/
			float US1_b_Voltage7;/*��ѹ*/
			
			float US1_b_Min_mA0; /*��С����*/
			float US1_b_Min_mA1; /*��С����*/
			float US1_b_Min_mA2; /*��С����*/
			float US1_b_Min_mA3; /*��С����*/
			float US1_b_Min_mA4; /*��С����*/
			float US1_b_Min_mA5; /*��С����*/
			float US1_b_Min_mA6; /*��С����*/
			float US1_b_Min_mA7; /*��С����*/
			
			float US1_b_Max_mA0; /*������*/
			float US1_b_Max_mA1; /*������*/
			float US1_b_Max_mA2; /*������*/
			float US1_b_Max_mA3; /*������*/
			float US1_b_Max_mA4; /*������*/
			float US1_b_Max_mA5; /*������*/
			float US1_b_Max_mA6; /*������*/
			float US1_b_Max_mA7; /*������*/
			
			//page c �ߵ͸���
			float US1_c_ValN1;/*ֵ ©�����*/
			float US1_c_ValN2;/*ֵ*/
			float US1_c_ValN3;/*ֵ*/
			float US1_c_ValN4;/*ֵ �����ѹ���Ե���*/
			float US1_c_ValN5;/*ֵ ��������ѹ*/
			float US1_c_ValN6;/*ֵ*/
			float US1_c_ValN7;/*ֵ*/
			float US1_c_ValN8;/*ֵ*/
			
			float US1_c_ValP1;/*ֵ ©�����*/
			float US1_c_ValP2;/*ֵ*/
			float US1_c_ValP3;/*ֵ*/
			float US1_c_ValP4;/*ֵ �����ѹ���Ե���*/
			float US1_c_ValP5;/*ֵ ��������ѹ*/
			float US1_c_ValP6;/*ֵ*/
			float US1_c_ValP7;/*ֵ*/
			float US1_c_ValP8;/*ֵ*/
			
			float US1_c_Min_mA1; /*��Сֵ*/
			float US1_c_Min_mA2; /*��Сֵ*/
			float US1_c_Min_mA3; /*��Сֵ*/
			float US1_c_Min_mA4; /*��Сֵ*/
			float US1_c_Min_mA5; /*��Сֵ*/
			float US1_c_Min_mA6; /*��Сֵ*/
			float US1_c_Min_mA7; /*��Сֵ*/
			float US1_c_Min_mA8; /*��Сֵ*/
			
			float US1_c_Max_mA1; /*��Сֵ*/
			float US1_c_Max_mA2; /*��Сֵ*/
			float US1_c_Max_mA3; /*��Сֵ*/
			float US1_c_Max_mA4; /*��Сֵ*/
			float US1_c_Max_mA5; /*��Сֵ*/
			float US1_c_Max_mA6; /*��Сֵ*/
			float US1_c_Max_mA7; /*��Сֵ*/
			float US1_c_Max_mA8; /*��Сֵ*/
			
			



//page d У׼ҳ��

			unsigned short int US1_d_Min_Val; /*У׼1*/
			unsigned short int US1_d_Min_Va2; /*У׼2*/
			unsigned short int US1_d_Min_Va3; /*У׼3*/
			unsigned short int US1_d_Min_Va4; /*У׼4*/
			unsigned short int US1_d_Min_Va5; /*У׼5*/
			unsigned short int US1_d_Min_Va6; /*У׼6*/
			unsigned short int US1_d_Min_Va7; /*У׼7*/
			unsigned short int US1_d_Min_Va8; /*У׼8*/
			unsigned short int US1_d_Min_Va9; /*У׼9*/
			unsigned short int US1_d_Min_Va10; /*У׼10*/
			unsigned short int US1_d_Min_Va11; /*У׼11*/
			
			
			unsigned short int US1_d_Max_Val; /*У׼1*/
			unsigned short int US1_d_Max_Va2; /*У׼2*/
			unsigned short int US1_d_Max_Va3; /*У׼3*/
			unsigned short int US1_d_Max_Va4; /*У׼4*/
			unsigned short int US1_d_Max_Va5; /*У׼5*/
			unsigned short int US1_d_Max_Va6; /*У׼6*/
			unsigned short int US1_d_Max_Va7; /*У׼7*/
			unsigned short int US1_d_Max_Va8; /*У׼8*/
			unsigned short int US1_d_Max_Va9; /*У׼9*/
			unsigned short int US1_d_Max_Va10; /*У׼10*/
			unsigned short int US1_d_Max_Va11; /*У׼11*/
			


//����---------------------------------------------------------------

		   int  US1_CalibrationData[20];//У׼����
/*0-3
			FINEģʽDAC
			FINEģʽ��Դ��������
			FINEģʽ�ɼ���ֵ
			FINEģʽ���ݲ���
4-7
			HSPģʽDAC
			HSPģʽ��Դ��������
			HSPģʽ�ɼ���ֵ
			HSPģʽ���ݲ���
4-7
*/

unsigned int  ResidualVoltageData[2];//�����ѹ����
/*[0]�����ѹ���Ե���
[1]�����ѹ
*/

float  ConsumeCur;//���ĵ���

//����---------------------------------------------------------------


			char US1_CutApartBuf[20][CutApartBufLen];//�ָ��
		
			
			char US1_SendDataBuf[50][SendDataBuf_Len];
			unsigned char US1_SendAutoAdd;//������������
			unsigned char US1_Send_Flag;//���ͱ�־λ
			unsigned char US1_SendDataSucce_Flag;/*���ͳɹ����Ϊ*/
			unsigned char US1_ReceiDataSucce_Flag;//���ճɹ����λ
//			unsigned char US1_ReceiDataSucceCount;/*���ռ���*/
			unsigned char US1_ReceiveDataStr[RECEIVE_DATA_BUF_LEN_USART1];

		
		}USART1_Data;//SCREEN
	
		
		struct 
		{
			unsigned char US2_SendDataSucce_Flag;/*���ͳɹ����Ϊ*/
			
		}USART2_Data;
		
		struct 
		{
			float US3_OutValCurrent;/*�����������ֵ*/
			float US3_OutValVoltage;/*�����ѹ����ֵ*/
			float US3_OutValPower;  /*������ʵ���ֵ*/
			unsigned char US3_OutState;
			
			char US3_SendDataBuf[10][SendDataBuf_Len];
			unsigned char US3_ReceiDataSucce_Flag;
			unsigned char US3_SendAutoIncrement;//������������
			unsigned char US3_Send_Flag;//���ͱ�־λ
			unsigned char US3_SendDataSucce_Flag;/*���ͳɹ����Ϊ*/
			unsigned char US3_ReceiDataSucceCount;/*���ռ���*/
			unsigned char US3_ReceiveDataStr[20][20];
			float         US3_ReceiveDataNum[20];
			
		}USART3_Data;//POWER
		
		struct 
		{

			unsigned char US4_SendDataSucce_Flag;/*���ͳɹ����Ϊ*/
			unsigned char US4_ReceiDataSucce_Flag;/*���ճɹ����Ϊ*/
			unsigned char US4_receiveData[RECEIVE_REAL_DATA];
			
		}USART4_Data;//SENSOR
		struct 
		{
			float US6_OutValCurrent;/*�����������ֵ*/
			float US6_OutValVoltageDC;/*���DC��ѹ����ֵ*/
			float US6_OutValVoltageAC;/*���AC��ѹ����ֵ*/
			
			char US6_SendDataBuf[10][SendDataBuf_Len];
			unsigned char US6_SendAutoIncrement;//������������
			unsigned char US6_Send_Flag;//���ͱ�־λ
			unsigned char US6_SendDataSucce_Flag;/*���ͳɹ����Ϊ*/
			unsigned char US6_ReceiDataSucce_Flag;
			unsigned char US6_ReceiDataSucceCount;/*���ռ���*/
			unsigned char US6_ReceiveDataStr[20][20];
			float         US6_ReceiveDataNum[20];
			
		}USART6_Data;//MULTIMETER
		
	
	}USART_DataType;
	

	
	
	typedef struct _SYStickTime
	{
		unsigned int sys_ReceiveData_ms; 
		
		unsigned int sys_sendTime_ms; 
		unsigned int sys_WaitOutTime_ms;
		unsigned int sys_MeasuringTime_ms;
		unsigned int sys_LEDTime_ms;
		unsigned int sys_Test_ms;
		unsigned int sys_SendDataToScreen_ms;

	}SYStickTimeType;


typedef struct _comVariableBlockType
{
	unsigned char *SaveDATA_BUF; 
	unsigned short int SaveDATA_BUF_Len; 
	unsigned char SaveDataFlag;
	unsigned char KeyPointVoltageResult;
	unsigned char HighLowDetectionResult;
	unsigned char NixieTubeResult;
	unsigned char ExternalInputLineResult;
	unsigned char AutoSetOrManual;  //0Ϊ�ֶ�����0Ϊ�Զ�
	unsigned char StartDetecFlag;  //������⣬1Ϊ���
	unsigned char StopDetecFlag;  //1��ֹͣ
	unsigned char StartRunLED;  //������main����
	unsigned char BeepControl;  //
	
	DeviceStatusType DeviceStatus;//�豸״̬
	MainStepType MainStep;
//	unsigned char StartCountTimeFlag;  //
	
	unsigned char ScreenCommunicationState;  //
	
	unsigned char MachineSelfTestState;
	
	
	MeasureResultsType MeasureResults;
	
	unsigned short int TimYear;
	unsigned short int TimMonth;
	unsigned short int TimDay;
	unsigned short int TimHour;
	unsigned short int TimMinute;
	unsigned short int TimSecond;
	
	
unsigned short int DataException;
//��ȡ����У׼����ϵ���쳣

	
	unsigned char SDInsertState;
	unsigned char ID_SreeFindScreen[4][50];
	unsigned char ID_BUF[20][25];
	unsigned char ID_Sensor[50];
	unsigned char ID_SensorChanged[50];
//	unsigned char ID_SameFlag;//1����ͬ��0����ͬ
	 char ID_RowCoordinate;
	unsigned char ID_FineRowCoordinate;//��¼�ҵ�id�Ķ�λ�����±�
	unsigned short int NumOfNQualified;//��ͨ��
	unsigned short int NumOfQualified;//ͨ��
	unsigned short int NumOfQualifiedTotal;//����
	unsigned short int NumOfQualifiedFlag;//
//	unsigned short int NumOfProducts;

	unsigned char  Progress;//������
	float ProgressCoefficient;
	
	unsigned int OutputPWM_Num;
	float Coefficient_PNP_A;
	float Coefficient_PNP_B;
	float Coefficient_NPN_A;
	float Coefficient_NPN_B;

}comVariableBlockType;

extern SYStickTimeType  SYS_tickTime;
extern USART_DataType USART_Data;
//extern DATA_storeType DATA_store;	
extern comVariableBlockType comVariableBlock;

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

