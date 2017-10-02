#include "communication.h"              // 
#include "cmsis_os2.h"                  // ::CMSIS:RTOS2

#define AFFAIR_PROXY_PORT_NO  80

/* 
 *事务处理线程
 *
*/
void ThreadAffairHandle()
{
	
	RegisterListener(AFFAIR_PROXY_PORT_NO , osMessageQueueNew (10, 10, NULL));		//存储BusClassReceiveServiceFrame结构指针
	
}
