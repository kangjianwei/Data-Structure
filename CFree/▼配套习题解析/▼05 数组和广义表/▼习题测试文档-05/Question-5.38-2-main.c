#include <stdio.h>
#include "../../../���α��㷨ʵ��/��05 ����͹����/06 GeneralizedList-E/GeneralizedList-E.c" //**��05 ����͹����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c" 	//**��04 ��**//

/* ����ԭ�� */
void Algo_5_38_2(GList L, int d, int l);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "((a),(b),(c,(d,e,f)),(g,((h),i)))";
	SString S;
	
	printf("��������� L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_E(&L, S);
	printf("L = ");
	Output_GL_E(L);	
	printf("\n\n");	
	
	printf("������ 2 ���ԭ����Ϊ��");
	Algo_5_38_2(L, 0, 2);
	printf("\n\n");
		
	return 0;
}

/*������������������������������������������������������������
����5.38-2�����������е�l���ԭ����(��չ��������洢��ʾ) ��
������������������������������������������������������������*/
/* ��չ��������洢��ʾ */ 
void Algo_5_38_2(GList L, int d, int l)
{
	int i = d;									//d��ֵ��Ϊ0
	
	if(L && l>=i)
	{
		if(L->tag==Atom)
		{
			if(l==i)
				printf("%c ", L->Union.atom);
		}
		else
			Algo_5_38_2(L->Union.hp, i+1, l); //��ͷָ��ָ���Ļ�������һ
		
		Algo_5_38_2(L->tp, i, l);		
	}
}
