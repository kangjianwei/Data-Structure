#include <stdio.h>
#include "../../../���α��㷨ʵ��/��05 ����͹����/06 GeneralizedList-E/GeneralizedList-E.c" //**��05 ����͹����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c" 	//**��04 ��**//

/* ����ԭ�� */
int Algo_5_30_2(GList L);

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
	
	printf("��������Ϊ�� %d\n", Algo_5_30_2(L));
	printf("\n");
		
	return 0;
}

/*������������������������������������������������
����5.30-2����������ȣ���չ��������洢��ʾ����
������������������������������������������������*/
/* ��չ��������洢��ʾ */ 
int Algo_5_30_2(GList L)
{
	int m, n;
	
	if(!L)							//�ձ����Ϊ1 
		return 1;
	
	if(L->tag==Atom)				//ԭ�����Ϊ0 
		return 0;
	
	m = Algo_5_30_2(L->Union.hp) + 1;
	n = Algo_5_30_2(L->tp);
	
	return m>n ? m : n;
}
