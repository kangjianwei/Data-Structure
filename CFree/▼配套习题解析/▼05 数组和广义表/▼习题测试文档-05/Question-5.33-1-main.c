#include <stdio.h>
#include "../../../���α��㷨ʵ��/��05 ����͹����/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**��05 ����͹����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c" 	//**��04 ��**//

/* ����ԭ�� */
void Algo_5_33_1(GList L, int d);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "((),(e),(a,(b,c,d)))";
	SString S;
	
	printf("��������� L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_H_T_1(&L, S);
	printf("L = ");
	Output_GL_H_T(L, Head);	
	printf("\n\n");	
	
	Algo_5_33_1(L, 0);
	printf("\n");
		
	return 0;
}

/*������������������������������������������������������������������
����5.33-1����������������ԭ��������ڲ�Σ�ͷβ����洢��ʾ����
������������������������������������������������������������������*/ 
/* ͷβ����洢��ʾ */ 
void Algo_5_33_1(GList L, int d)
{
	int i = d;								//d�ĳ�ֵ��ֵΪ0
	
	if(L)
	{
		if(L->tag==Atom)
			printf("%c -> ��%d��\n", L->Union.atom, i);
		
		if(L->tag==List)					//��ͷָ��ָ���Ļ�������һ
		{
			Algo_5_33_1(L->Union.ptr.hp, i+1);
			Algo_5_33_1(L->Union.ptr.tp, i);
		}
	}
}
