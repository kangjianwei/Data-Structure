/***************************************
 *					     			   *
 * �ļ���: ��03 ջ�Ͷ���\02 Conversion *
 * 					     			   *
 * �ļ���: Conversion.c  			   *
 * 				         			   *
 * ��  ��: 3.1           			   * 
 *                       			   *
 ***************************************/

#ifndef CONVERSION_C
#define CONVERSION_C

#include "Conversion.h"					//**��03 ջ�Ͷ���**//

/*�T�T�T�T�[
�U �㷨3.1�U 
�^�T�T�T�T*/
void conversion(int i)
{	
	SqStack S; 
	SElemType_Sq e;
	
	InitStack_Sq(&S);

	printf("ʮ������ %d ת��Ϊ�˽�������Ϊ��0", i);
	
	while(i)
	{
		Push_Sq(&S, i%8);				//��ջʱ�ӵ�λ����λ 
		i = i/8;
	}
	
	while(!StackEmpty_Sq(S))
	{
		Pop_Sq(&S, &e);					//��ջʱ�Ӹ�λ����λ 
		printf("%d", e);
	}
} 

#endif
