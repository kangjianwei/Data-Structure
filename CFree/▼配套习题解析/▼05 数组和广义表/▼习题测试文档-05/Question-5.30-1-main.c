#include <stdio.h>
#include "../../../���α��㷨ʵ��/��05 ����͹����/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**��05 ����͹����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c" 	//**��04 ��**//

/* ����ԭ�� */
int Algo_5_30_1(GList L);

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
	
	printf("��������Ϊ�� %d\n", Algo_5_30_1(L));
	printf("\n");
		
	return 0;
}

/*��������������������������������������������
����5.30-1����������ȣ�ͷβ����洢��ʾ����
��������������������������������������������*/ 
/* ͷβ����洢��ʾ */ 
int Algo_5_30_1(GList L)
{
	int m, n;
	
	if(!L)							//�ձ����Ϊ1 
		return 1;
	
	if(L->tag==Atom)				//ԭ�����Ϊ0 
		return 0;
	
	m = Algo_5_30_1(L->Union.ptr.hp) + 1;
	n = Algo_5_30_1(L->Union.ptr.tp);
	
	return m>n ? m : n;
}
