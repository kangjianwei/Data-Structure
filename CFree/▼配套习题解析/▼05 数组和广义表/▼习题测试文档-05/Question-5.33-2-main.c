#include <stdio.h>
#include "../../../���α��㷨ʵ��/��05 ����͹����/06 GeneralizedList-E/GeneralizedList-E.c" //**��05 ����͹����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c" 	//**��04 ��**//

/* ����ԭ�� */
void Algo_5_33_2(GList L, int d);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "((),(e),(a,(b,c,d)))";
	SString S;
	
	printf("��������� L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_E(&L, S);
	printf("L = ");
	Output_GL_E(L);	
	printf("\n\n");	
	
	Algo_5_33_2(L, 0);
	printf("\n");
		
	return 0;
}

/*����������������������������������������������������������������������
����5.33-2����������������ԭ��������ڲ�Σ���չ��������洢��ʾ����
����������������������������������������������������������������������*/
/* ��չ��������洢��ʾ */ 
void Algo_5_33_2(GList L, int d)
{
	int i = d;										//d��ֵ��Ϊ0
	
	if(L)
	{
		if(L->tag==Atom)
			printf("%c -> ��%d��\n", L->Union.atom, i);
		
		if(L->tag==List)
			Algo_5_33_2(L->Union.hp, i+1);		//��ͷָ��ָ���Ļ�������һ
		
		Algo_5_33_2(L->tp, i);
	}
}
