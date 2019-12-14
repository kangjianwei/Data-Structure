/************************************
 *						            *
 * �ļ���: ��08 ��̬�洢����        *
 * 						            *
 * �ļ���: GarbageCollection-main.c *
 * 							        *
 * ��  ��: ���õ�Ԫ�Ѽ���غ������� *
 *                                  *
 ************************************/

#include <stdio.h>
#include "GarbageCollection.c" 								//**��08 ��̬�洢����**//

/* ����ԭ�� */
void Traverse(GList L, void(Visit)(GList));
void print(GList L);

int main(int argc, char *argv[])
{
	GList G;
	
	printf("��������������");
	{
		SString S;	
		char *s = "((),(e),(a,(b,c,d)))";
	
		StrAssign_Sq(S, s);	
		InitGList_GL_H_T(&G);
		CreateGList_GL_H_T_1(&G, S);	
		Output_GL_H_T(G, Head);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��1\n������ MakeList ����...\n");					//1.����MakeList����
	{
		printf("����ǰ�ı�־״̬...\n");
		Traverse(G, print);
		printf("\n");
		MakeList(G);

		PressEnter;

	 	printf("���ʺ�ı�־״̬...\n");
		Traverse(G, print);
		printf("\n");
	}
	PressEnter;
					
	return 0;
}

void Traverse(GList L, void(Visit)(GList))
{
	if(L)
	{
		Visit(L);
		
		if(L->tag==List)
		{
			Traverse(L->Union.ptr.hp, Visit);
			Traverse(L->Union.ptr.tp, Visit);
		}
	}	
}

void print(GList L)
{
	if(L->tag==Atom)
		printf("mark = %d ԭ�ӽ�㣺%c\n", L->mark, L->Union.atom);
	else
		printf("mark = %d ����\n", L->mark);		
}
