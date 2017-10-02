#include "NAxisMachine.h"                  // 

static NAxisMachine NAxisArm;

uint8_t PowerUpInit(void)
{
}
uint8_t RunInit(void)
{
}
uint8_t GetTip(uint8_t arm)
{
}
uint8_t MoveToFixedPosition(NAxisMachine nam,uint8_t PosNo)
{
}
uint8_t MoveToFieldPosition(NAxisMachine nam,char FieldNO,uint8_t PosNO)
{
}
uint8_t MoveToAbsPositionAll(NAxisMachine nam,XYZ *xyz)
{
}
uint8_t MoveToPositionSpecifyAxis(NAxisMachine nam,char AxisCha,uint16_t num)
{
}
uint8_t MoveToRelPosition(uint8_t arm,char AxisCha,s16 off)
{
}
uint8_t RSP9000DebugPositionSet(uint8_t arm,s8 *pDat);
uint8_t RSP9000Test(uint8_t arm,uint8_t item);
uint8_t RSP9000CommandPackGet(uint8_t RepFlag,uint8_t *buf);
uint8_t RSP9000AckPackGet(uint8_t RepFlag,char *str,uint8_t *buf); 
