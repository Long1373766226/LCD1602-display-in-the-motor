/**
		ʵ�������������ݿ��Ƶ�������ת�ͷ�ת �Լ� �ı�ת��
		����	0	ʵ��˳ʱ����ת
					1	ʵ����ʱ�뷴ת
					2	ʵ��ת��Ϊ����
					3	ʵ��ת��Ϊ����
					4	ʵ��ת��Ϊ����
		���õ�LCD1602��Ϊ��ʾ
					E = P2 ^ 7;		//1602ʹ������
					RW = P2 ^ 6;		//1602��д����
					RS = P2 ^ 5;		//1602����/����ѡ������
		���в�ͬ��lcd.h���޸����Ų���
		**��Ҫ��
				��Ϊ�õ�ULN2003оƬ�����Զ�Ӧ������
					IN1	--	P1^6
					IN2	--	P1^5
					IN3	--	P1^4
					IN4	--	P1^3
					OUT1	--	��ɫ��
					OUT2	--	��ɫ��
					OUT3	--	��ɫ��
					OUT4	--	��ɫ��
				ʣ�º�ɫ��VCC������LCD1602�Ͳ�������Լ���Ƭ�����ֿ�����
		
**/
#include "123.h"

main()
{
		L1602_init();
    Delay(100);
    UartInit();
    while(1)
    {
       if(flag == 0)
        {
					led = 0;
					
					forward(speed);
					
					if(speed == 1)
					{
					 LCD_display("Mo Dir: Goto","Mo Spd: Fast ^_^");
					}
					
					else if(speed == 3)
					{
					 LCD_display("Mo Dir: Goto","Mo Spd: Norl ^_^");
					}
					
					else if(speed == 5)
					{
					 LCD_display("Mo Dir: Goto","Mo Spd: Slow ^_^");
					}
//					switch(speed)		//switch�޷�ʵ�ֲ�֪��Ϊʲô��֪���Ĵ��������
//					{
//				case'1':
//					LCD_display("Mo Dir: Goto","Mo Spd: Fast ^_^");
//				case'2':
//					LCD_display("Mo Dir: Goto","Mo Spd: Norl ^_^");
//				case'3':
//					LCD_display("Mo Dir: Goto","Mo Spd: Slow ^_^");
//					}
        }


       if(flag == 1)
        {
          led = 1;
					back(speed);
					if(speed == 1)
					{
					 LCD_display("Mo Dir: Back","Mo Spd: Fast ^_^");
					}
					else if(speed == 3)
					{
					 LCD_display("Mo Dir: Back","Mo Spd: Norl ^_^");
					}
					else if(speed == 5)
					{
					 LCD_display("Mo Dir: Back","Mo Spd: Slow ^_^");
					}
//				switch(speed)
//					{
//				case'1':
//					LCD_display("Mo Dir: Back","Mo Spd: Fast ^_^");
//				break;
//				case'2':
//					LCD_display("Mo Dir: Back","Mo Spd: Norl ^_^");
//				break;
//				case'3':
//					LCD_display("Mo Dir: Back","Mo Spd: Slow ^_^");
//				break;
//					}
        }

    }
}

void Usart() interrupt 4
{
    uchar n; //������ʱ����
//	led = 1;
    if(RI) //�ж��ǽ����жϲ���
    {
        RI = 0; //��־λ����
        n = SBUF; //���뻺������ֵ
        switch(n)
        {
        case'0':		//������ת
          flag = 0;
         break;
				
        case'1':		//���Ʒ�ת
          flag = 1;
         break;
				
				case'2':		//�����ٶ�Ϊ��
					speed = 5;
				break;
				
				case'3':		//�����ٶ�Ϊ�е�
					speed = 3;
				break;
				
				case'4':		//�����ٶ�Ϊ��
					speed = 1;
				break;
				
        }
        TI = 1;
        SBUF = n; //�ѽ��յ���ֵ�ٷ���
    }
    if(TI) //����Ƿ��ͱ�־λ������
        TI = 0;
}