#include <stdio.h>
#include <stdlib.h>								                //�ṩmalloc��realloc��free��exitԭ��
#include "../../../���α��㷨ʵ��/��05 ����͹����/06 GeneralizedList-E/GeneralizedList-E.c" //**��05 ����͹����**//
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c" 	//**��04 ��**//

/* ����ԭ�� */
void Algo_5_37_2(GList *L, AtomType x);
	
int main(int argc, char *argv[])
{
	GList L;
	char *s = "((b),(e),(a,(b,c,d)),(b,((b),b)))";
	SString S;
	
	printf("��������� L ...\n");
	StrAssign_Sq(S, s);
	CreateGList_GL_E(&L, S);
	printf("L = ");
	Output_GL_E(L);	
	printf("\n\n");	
	
	printf("ɾ�� L �е�Ԫ�� 'b' ...\n");
	Algo_5_37_2(&L, 'b');
	printf("L = ");
	Output_GL_E(L);
	printf("\n\n");
		
	return 0;
}

/*��������������������������������������
����5.37-2��ɾ���������ֵΪx��ԭ���� ��
��������������������������������������*/ 
/* ��չ��������洢��ʾ */ 
void Algo_5_37_2(GList *L, AtomType x)
{
	GList p;
	
	if(*L)
	{
		if((*L)->tag==List)
		{				
			Algo_5_37_2(&((*L)->Union.hp), x);
			Algo_5_37_2(&((*L)->tp), x);	
		}
		else
		{
			if((*L)->Union.atom==x)
			{	
				p = *L;
				*L = (*L)->tp;
				free(p);
				p = NULL;
				
				Algo_5_37_2(L, x);
			}
			else
				Algo_5_37_2(&((*L)->tp), x);
		}
	}
}
