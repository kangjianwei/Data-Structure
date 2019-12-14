#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��05 ����͹����/06 GeneralizedList-E/GeneralizedList-E.c" //**��05 ����͹����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c" 	//**��04 ��**//

/* ����ԭ�� */
Status Algo_5_32_2(GList A, GList B);

int main(int argc, char *argv[])
{
	GList A, B;
	char *s = "((),(e),(a,(b,c,d)))";
	SString S;
	
	printf("��������� A��B ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_E(&A, S);
	CreateGList_GL_E(&B, S);
	printf("A = ");
	Output_GL_E(A);
	printf("\n");
	printf("B = ");
	Output_GL_E(B);	
	printf("\n\n");	
	
	Algo_5_32_2(A, B) ? printf("���������ȣ�\n") : printf("���������ȣ���\n");
	printf("\n");
		
	return 0;
}

/*������������������������������������������������������
����5.32-2���жϹ�����Ƿ���ȣ���չ��������洢��ʾ����
������������������������������������������������������*/
/* ��չ��������洢��ʾ */ 
Status Algo_5_32_2(GList A, GList B)
{
	if(!A && !B)							//�����ձ���� 
		return OK;
	
	if(A && B)								//���������Ϊ��
	{
		if(A->tag==B->tag)					//Ԫ��������ͬ
		{
			if(A->tag==Atom)				//ԭ�ӽ��
			{
				if(A->Union.atom==B->Union.atom)
				{
					if(Algo_5_32_2(A->tp, B->tp))
						return OK;
				}	
			}
			else							//���� 
			{
				if(Algo_5_32_2(A->Union.hp, B->Union.hp))
				{
					if(Algo_5_32_2(A->tp, B->tp))
						return OK;
				}
			}
		} 
	}
	
	return ERROR;
}
