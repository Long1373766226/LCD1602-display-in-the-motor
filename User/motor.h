#ifndef _MOTOR_H
#define _MOTOR_H

#include <reg52.h>
#include "delay.h"

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

int back(uchar speed);			//������ת
int forward(uchar speed);		//���Ʒ�ת

#endif