#include "communication.h"              // 

static	osMessageQueueId_t	receiveListenerQueue;
static	ReceiveListener	receiveListener[RECEIVE_LISTENER_MAX_NUM];
static	osMessageQueueId_t	sendQueue; 

extern	CAN_HandleTypeDef	hcan1;
extern	CAN_HandleTypeDef	hcan2;
static	const CAN_HandleTypeDef*	pCOMMUNICATION_DEVICE_CAN_NO_MAP[2]={&hcan1,&hcan2};

extern	UART_HandleTypeDef huart5;
extern	UART_HandleTypeDef huart1;
extern	UART_HandleTypeDef huart3;
static	const UART_HandleTypeDef*	pCOMMUNICATION_DEVICE_UART_NO_MAP[3]={&huart1,&huart3,&huart5};

/* 
 *ͨ�ŷ����ʼ��
 *
*/
void CommunicationServiceInit()
{

	sendQueue = osMessageQueueNew (10, 10, NULL);		//
}

/* 
 *ע��һ������
 *
*/
_Bool RegisterListener(uint8_t portNo,osMessageQueueId_t receiveQueue)
{

	static uint8_t no=0;
	if(no>=RECEIVE_LISTENER_MAX_NUM)
		return 0;
	receiveListener[no].portNo=portNo;
	receiveListener[no].receiveQueue=receiveQueue;
	osMessageQueuePut(receiveListenerQueue,&receiveListener[no],0,NULL);  //ע��һ������
	return 1;
}

/* 
 *����������֡����
 *
*/
_Bool Send(uint8_t portNo,ReceiveServiceFrame bf)
{

	osStatus_t status = osMessageQueuePut(sendQueue,&bf,0,NULL);  //���뷢�Ͷ���
	if(status==osOK)
		return 1;
	else
		return 0;
}


/* 
 *���ս����߳�
 *
*/
static void ThreadReceiveAnalyze(void *argument)
{
	for(;;)
	{
	}
}

/* 
 *�����߳�
 *
*/
static void ThreadSend(void *argument)
{
	osStatus_t	osStatus;
	StxCkProtocolFrame	stxCkProtocolFrame;
	for(;;)
	{
		SendServiceFrame	*pBf;
		osStatus = osMessageQueueGet(sendQueue,pBf,0,NULL);
		switch(pBf->protocolType)
		{
			case PROTOCOL_STX_CK:
				break;
			case PROTOCOL_HAMILTON_CAN:
				break;
			default:
				break;
		}	
		
		switch(pBf->communicationDevice)
		{
			case COMMUNICATION_DEVICE_CAN:
				break;
			case COMMUNICATION_DEVICE_UART:
				break;
			default:
				break;
		}	
	}
}