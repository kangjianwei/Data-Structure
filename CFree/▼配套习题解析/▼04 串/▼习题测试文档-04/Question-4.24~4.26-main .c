#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	           	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��04 ��/02 HeapString/HeapString.c"//**��04 ��**//

/* ����ԭ�� */
Status Concat_4_24(HString *T, HString S1, HString S2);
Status Replace_4_25(HString *S, HString T, HString V);
Status StrInsert_4_26(HString *S, int pos, HString T);

int main(int argc, char *argv[])
{
	char *s = "---*^***^*^*^*---";
	char *s1 = "*";
	char *s2 = "^*";
	char *v = "*_*";
	HString S1, S2, T, V, S;
	
	StrAssign_H(&S1, s1);
	StrAssign_H(&S2, s2);
	StrAssign_H(&V, v);
	StrAssign_H(&S, s);
	
	printf("S1 = ");
	StrPrint_H(S1);
	printf("\n");
	printf("S2 = ");
	StrPrint_H(S2);
	printf("\n");
	printf("V = ");
	StrPrint_H(V);
	printf("\n");
	printf("S = ");
	StrPrint_H(S);
	printf("\n\n");

	printf("�������� 4.24 ��֤...������\n");	
	printf("����S1��S2ΪT...\n");
	Concat_4_24(&T, S1, S2);
	printf("T = ");
	StrPrint_H(T);
	printf("\n\n");
	
	printf("�������� 4.25 ��֤...������\n");
	printf("�� V �滻 S �е� T...\n");
	Replace_4_25(&S, T, V);
	printf("S = ");
	StrPrint_H(S);
	printf("\n\n");	
	
	printf("�������� 4.26 ��֤...������\n");
	printf("�� T ���뵽 S �ĵ� 2 ���ַ�ǰ...\n");
	StrInsert_4_26(&S, 2, T);
	printf("S = ");
	StrPrint_H(S);
	printf("\n\n");
			
	return 0;
}

/*����������������
����4.24�������ө�
����������������*/
Status Concat_4_24(HString *T, HString S1, HString S2)
{
	if(Concat_H(T, S1, S2))				//�Ѷ��� 
		return OK;
	else
		return ERROR;
}

/*����������������
����4.25�����滻��
����������������*/
Status Replace_4_25(HString *S, HString T, HString V)
{
	if(Replace_H(S, T, V))				//�Ѷ���
		return OK;
	else
		return ERROR;
}

/*����������������
����4.26�������멧
����������������*/
Status StrInsert_4_26(HString *S, int pos, HString T)
{
	if(StrInsert_H(S, pos, T))			//�Ѷ��� 
		return OK;
	else
		return ERROR;
}
