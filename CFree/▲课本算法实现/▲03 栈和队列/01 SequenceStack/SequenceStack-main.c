/******************************************
 *						      			  *
 * �ļ���: ��03 ջ�Ͷ���\01 SequenceStack *
 * 						      			  *
 * ��  ��: ˳��ջ��غ������� 			  *
 *                            			  *
 ******************************************/

#include <stdio.h>
#include "SequenceStack.c" 								//**��03 ջ�Ͷ���**//
	
void PrintElem(SElemType_Sq e);
	//���Ժ�������ӡ���� 

int main(int argc, char **argv)
{
	SqStack S;
	int i;
	SElemType_Sq e;
	
	printf("��1\n������ InitStack ����...\n");			//1.����InitStack����
	{
		printf("��ʼ��˳��ջ S ...\n");					 
		InitStack_Sq(&S);
		printf("\n");
	}
	PressEnter;
	
	printf("��4\n������ StackEmpty ����...\n");			//4.����StackEmpty����
	{
		StackEmpty_Sq(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��7\n������ Push ����...\n");					//7.����Push����
	{
		for(i=1; i<=6; i++)									
		{
			printf("�� \"%2d\" ѹ��ջ S ", 2*i);
			Push_Sq(&S, 2*i);
			printf("���ۼƵ� %d ��Ԫ�أ�...\n", S.top-S.base);
		}
		printf("\n");
	}
	PressEnter;
	
	printf("��9\n������ StackTraverse ����...\n");		//9.����StackTraverse����
	{
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StackTraverse_Sq(S, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��8\n������ Pop ����...\n");					//8.����Pop����
	{
		Pop_Sq(&S, &e);
		printf("ջ��Ԫ�� \"%d\" ��ջ...\n", e);
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StackTraverse_Sq(S, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��5\n������ StackLength ����...\n");			//5.����StackLength����
	{
		i = StackLength_Sq(S);
		printf(" S �ĳ���Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("��6\n������ GetTop ����...\n");				//6.����GetTop����
	{
		GetTop_Sq(S, &e);
		printf("ջ��Ԫ�ص�ֵΪ \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("��3\n������ ClearStack ����...\n");			//3.����ClearStack����
	{
		printf("��� S ǰ��");
		StackEmpty_Sq(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		ClearStack_Sq(&S);
		printf("��� S ��");
		StackEmpty_Sq(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��2\n������ DestroyStack ����...\n");			//2.����DestroyStack����
	{
		printf("���� S ǰ��");
		S.base!=NULL && S.top!=NULL ? printf(" S ���ڣ�\n") : printf(" S �����ڣ���\n");
		DestroyStack_Sq(&S);
		printf("���� S ��");
		S.base!=NULL && S.top!=NULL ? printf(" S ���ڣ�\n") : printf(" S �����ڣ���\n");
		printf("\n");
	}
	PressEnter;
		
	return 0;
}

void PrintElem(SElemType_Sq e)
{
	printf("%d ", e);
}
