#include <stdio.h>
#include "../../../���α��㷨ʵ��/��05 ����͹����/06 GeneralizedList-E/GeneralizedList-E.c" //**��05 ����͹����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c" 	//**��04 ��**//

/* ����ԭ�� */
void Algo_5_31(GList *T, GList L);

int main(int argc, char *argv[])
{
	GList L, T;
	char *s = "((),(e),(a,(b,c,d)))";
	SString S;
	
	printf("��������� L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_E(&L, S);
	printf("L = ");
	Output_GL_E(L);
	printf("\n\n");	
	
	printf("���ƹ���� L �� T...\n");
	Algo_5_31(&T, L);
	printf("T = ");
	Output_GL_E(T);
	printf("\n\n");	
		
	return 0;
}

/*��������������������������������������������
����5.31��������ƣ���չ��������洢��ʾ����
��������������������������������������������*/
void Algo_5_31(GList *T, GList L)
{
	CopyGList_GL_E(T, L); 			//�Ѷ��� 
}
