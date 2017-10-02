#pragma once
#include "l6474.h"

/*±€∂®“Â*/
typedef struct{
	deviceParams_t* pDeviceParamX;		//
	deviceParams_t* pDeviceParamY;
	deviceParams_t* pDeviceParamZ;
	uint8_t		communicationDeviceNo;
	uint32_t	sequence;
	uint16_t	targetAddr;
	uint8_t		targetPortNo;

}NAxisMachine;
