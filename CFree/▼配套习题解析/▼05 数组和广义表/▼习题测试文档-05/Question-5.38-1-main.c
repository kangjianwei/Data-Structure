#include <stdio.h>
#include "../../../���α��㷨ʵ��/��05 ����͹����/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**��05 ����͹����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c" 	//**��04 ��**//

/* ����ԭ�� */
void Algo_5_38_1(GList L, int d, int l);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "((a),(b),(c,(d,e,f)),(g,((h),i)))";
	SString S;
	
	printf("��������� L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_H_T_1(&L, S);
	printf("L = ");
	Output_GL_H_T(L, Head);	
	printf("\n\n");	
	
	printf("������ 2 ���ԭ����Ϊ��");
	Algo_5_38_1(L, 0, 2);
	printf("\n\n");
		
	return 0;
}

/*��������������������������������������������������������
����5.38-1�����������е�l���ԭ����(ͷβ����洢��ʾ) ��
��������������������������������������������������������*/ 
/* ͷβ����洢��ʾ */ 
void Algo_5_38_1(GList L, int d, int l)
{
	int i = d;							//d�ĳ�ֵ��ֵΪ0
	
	if(L && l>=i)
	{
		if(L->tag==Atom)
		{
			if(l==i)					//�������� 
				printf("%c ", L->Union.atom);
		}
		else							//��ͷָ��ָ���Ļ�������һ
		{
			Algo_5_38_1(L->Union.ptr.hp, i+1, l);
			Algo_5_38_1(L->Union.ptr.tp, i, l);
		}
	}
}
