#include <stdio.h>
#include "../../../���α��㷨ʵ��/��05 ����͹����/06 GeneralizedList-E/GeneralizedList-E.c" //**��05 ����͹����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c" 	//**��04 ��**//

/* ����ԭ�� */
void Algo_5_34_2(GList *L);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "(a,((b,c),()),(((d),e),f))";
	SString S;
	
	printf("��������� L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_E(&L, S);
	printf("L = ");
	Output_GL_E(L);	
	printf("\n\n");	
	
	printf("���ù����...\n");
	Algo_5_34_2(&L);
	printf("L = ");
	Output_GL_E(L);
	printf("\n\n");
		
	return 0;
}

/*����������������������
����5.34-2�����ù����
����������������������*/ 
/* ��չ��������洢��ʾ */ 
void Algo_5_34_2(GList *L)
{
	GList head, tail;
	
	if(*L)
	{
		head = *L;
		tail = (*L)->tp;
		
		if(head->tag==List && head->Union.hp)
			Algo_5_34_2(&(head->Union.hp));
		
		if(tail)						//�Ա�β��������
		{	
			Algo_5_34_2(&((*L)->tp));
		
			*L = (*L)->tp;				//ͷβ����
			tail->tp = head;
			head->tp = NULL;
		}
	}
}
