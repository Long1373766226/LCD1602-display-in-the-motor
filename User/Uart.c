#include "Uart.h"

/**
		�������ڶ�ʱ���������ò�����Ϊ9600
**/
void UartInit()		//9600bps@11.0592MHz
{
    SCON = 0x50; // SCON: ģʽ1, 8-bit UART, ʹ�ܽ���
    TMOD |= 0x20;
    TH1 = 0xfd; //������9600 ��ֵ
    TL1 = 0xfd;
    TR1 = 1;
    EA = 1; //�����ж�
    ES = 1; //�򿪴����ж�
}