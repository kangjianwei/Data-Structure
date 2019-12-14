#include <stdio.h>
#include "../../../���α��㷨ʵ��/��05 ����͹����/05 GeneralizedList-H&T/GeneralizedList-H-T.c" //**��05 ����͹����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c" 	//**��04 ��**//

/* ����ԭ�� */
void Algo_5_34_1(GList *L);

int main(int argc, char *argv[])
{
	GList L;
	char *s = "(a,((b,c),()),(((d),e),f))";
	SString S;
	
	printf("��������� L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_H_T_1(&L, S);
	printf("L = ");
	Output_GL_H_T(L, Head);	
	printf("\n\n");	
	
	printf("���ù����...\n");
	Algo_5_34_1(&L);
	printf("L = ");
	Output_GL_H_T(L, Head);
	printf("\n\n");
		
	return 0;
}

/*����������������������
����5.34-1�����ù����
����������������������*/ 
/* ͷβ����洢��ʾ */ 
void Algo_5_34_1(GList *L)
{
	GList head, tail;
	
	if(*L)								//�Ӻ���ǰ�����ﵽ������ 
	{
		head = *L;
		tail = (*L)->Union.ptr.tp;
					
										//�Ա�ͷ�������� 
		if(head->Union.ptr.hp && head->Union.ptr.hp->tag==List)
			Algo_5_34_1(&(head->Union.ptr.hp));
					 
		if(tail)						//�Ա�β��������
		{	
			Algo_5_34_1(&((*L)->Union.ptr.tp));
		
			*L = (*L)->Union.ptr.tp;	//ͷβ����
			tail->Union.ptr.tp = head;
			head->Union.ptr.tp = NULL;
		}
	}
}
