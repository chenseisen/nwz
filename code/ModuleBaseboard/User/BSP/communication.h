#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2

/*֧�ֵ�Э��*/
typedef enum{
	PROTOCOL_NOT,
	PROTOCOL_STX_CK,
	PROTOCOL_HAMILTON_CAN,
	PROTOCOL_TECAN_CAN,
}ProtocolType;

/*ͨ���豸*/
typedef enum{
	COMMUNICATION_DEVICE_UART,
	COMMUNICATION_DEVICE_CAN,
	COMMUNICATION_DEVICE_SPI,
}CommunicationDevice;

/*�����෢�ͷ���֡*/
typedef struct{
	ProtocolType	protocolType;
	CommunicationDevice		communicationDevice;
	uint8_t		communicationDeviceNo;
	uint32_t	sequence;
	uint16_t	targetAddr;
	uint8_t		targetPortNo;
	uint16_t	datLength;
	uint8_t		dat[1];

}SendServiceFrame;

/*��������շ���֡*/
typedef struct{
	uint32_t	sequence;
	uint16_t	sourceAddr;
	uint8_t		sourcePortNo;
	uint16_t	datLength;
	uint8_t		dat[1];
	
}ReceiveServiceFrame;

/*���ռ���ע��ṹ*/
#define		RECEIVE_LISTENER_MAX_NUM	10		//��������
typedef struct{
	uint8_t portNo;
	osMessageQueueId_t receiveQueue;		//�洢BusClassReceiveServiceFrame�ṹָ��
	
}ReceiveListener;

/*��ʼ��־+У�鷽ʽЭ��֡*/
typedef __packed struct{
	
	uint16_t	stx;
	uint32_t	sequence;
	uint16_t	sourceAddr;
	uint8_t		sourcePortNo;
	uint16_t	targetAddr;
	uint8_t		targetPortNo;
	uint16_t	datLength;
	uint16_t	checkSum;
	uint8_t		dat[1];

}StxCkProtocolFrame;


_Bool RegisterListener(uint8_t portNo,osMessageQueueId_t receiveQueue);			//

