#include <stdio.h>
#include "../../../���α��㷨ʵ��/��05 ����͹����/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**��05 ����͹����**//

/* ����ԭ�� */
void Algo_5_36_1(GList L, Mark mark);
void Algo_5_36_2(GList L);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "((),(e),(a,(b,c,d)))";
	SString S;
	
	printf("��������� L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_H_T_1(&L, S);
	printf("\n");	
	
	printf("�� 1 �������ʽ('_'����ձ�)...\n");	
	printf("L = ");
	Algo_5_36_1(L, 0);
	printf("\n\n");

	printf("�� 2 �������ʽ...\n");
	printf("L = ");
	Algo_5_36_2(L);
	printf("\n\n");
			
	return 0;
}

/*����������������������������������������
����5.36����������ͷβ����洢��ʾ����
����������������������������������������*/ 
/* ��ʽ1����������Ԫ��('_'����ձ�) */ 
void Algo_5_36_1(GList L, Mark mark)
{
	if(L)
	{
		if(L->tag==Atom)
			printf("%c ", L->Union.atom);
		else
		{
			Algo_5_36_1(L->Union.ptr.hp, Head);
			Algo_5_36_1(L->Union.ptr.tp, Tail);
		}
	}
	
	if(!L && mark==Head)
		printf("_ ");
}

/*����������������������������������������
����5.36����������ͷβ����洢��ʾ����
����������������������������������������*/ 
/* ��ʽ2�����������д��ʽ��� */ 
void Algo_5_36_2(GList L)
{
	Output_GL_H_T(L, Head);					//�Ѷ��� 
}
