#ifndef _LCD_H
#define _LCD_H

#include <reg52.h>
#include "delay.h"


//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

sbit E = P2 ^ 7;		//1602ʹ������
sbit RW = P2 ^ 6;		//1602��д����
sbit RS = P2 ^ 5;		//1602����/����ѡ������

bit Busy(void);		//��״̬���������������Ƿ���æ״̬
void wcmd(uchar del);			//�����
void wdata(uchar del);		//д���ݺ���
void L1602_init(void);		//��ʼ��
//void L1602_char(uchar hang,uchar lie,char sign);		//д���е��ַ�
void L1602_string(uchar hang,uchar lie,uchar *p);			//д�����ַ���
void LCD_display(uchar *p,uchar *q);		//���ճ�����


#endif