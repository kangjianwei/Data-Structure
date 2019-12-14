/****************************************************
 *						                            *
 * �ļ���: ��05 ����͹����\05 GeneralizedList-H&T *
 * 						                            *
 * ��  ��: �����ͷβ����洢����غ�������       *
 *                                                  *
 ****************************************************/

#include <stdio.h> 
#include "GeneralizedList-H-T.c"		//**��05 ����͹����**//

void PrintElem(AtomType e);				//��ӡ�����ԭ�� 

int main(int argc, char **argv)
{
	GList Tmp, G;
	GList g1, g2, g3;
	SString S1, S2, S3;
	 
	printf("��1\n������ InitGList_GL_H_T ����...\n");			//1.����InitGList_GL_H_T����
	{
		printf("�����յĹ���� Tmp ...\n");
		InitGList_GL_H_T(&Tmp);
		printf("\n");
	} 
	PressEnter;
	
	printf("��8\n������ GListEmpty_GL_H_T ����...\n");			//8.����GListEmpty_GL_H_T����
	{
		int tag;
		
		tag = GListEmpty_GL_H_T(Tmp);
		tag ? printf(" Tmp Ϊ�գ�\n") : printf(" Tmp ��Ϊ�գ���\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("��2-1��3-1��2-2��3-2\n������ sever_GL_H_T_1��CreateGList_GL_H_T_1�� ����...\n");
	{															//2-1��3-1��2-2��3-2.����sever_GL_H_T_1��CreateGList_GL_H_T_1�Ȳ���
		char *s1 = "()";
		char *s2 = "(e)";
		char *s3 = "(a,(b,c,d))";
		
		printf("���������S1��S2��S3...\n");
		StrAssign_Sq(S1, s1);
		CreateGList_GL_H_T_1(&g1, S1);
		StrAssign_Sq(S2, s2);
		CreateGList_GL_H_T_1(&g2, S2);
		StrAssign_Sq(S3, s3);
		CreateGList_GL_H_T_2(&g3, S3);
		printf("\n");
	}
	PressEnter;
		
	printf("��11\n������ InsertFirst_GL_H_T ����...\n");		//11.����InsertFirst_GL_H_T����		
	{
		printf("�� S3��S2��S1 ���β��뵽 Tmp ���׸�λ��...\n");
		InsertFirst_GL_H_T(&Tmp, g3); 
		InsertFirst_GL_H_T(&Tmp, g2);
		InsertFirst_GL_H_T(&Tmp, g1);
		printf("\n");
	}
	PressEnter;
	
	printf("��13\n������ Traverse_GL_H_T ����...\n");			//13.����Traverse_GL_H_T����
	{
		printf("����������ԭ�� Tmp = ");
		Traverse_GL_H_T(Tmp, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��14\n������ Output_GL_H_T ����...\n");				//14.����Output_GL_H_T����
	{
		printf("�������������� Tmp = ");
		Output_GL_H_T(Tmp, Head);
		printf("\n\n");
	} 
	PressEnter;

	printf("��5\n������ CopyGList_GL_H_T ����...\n");			//5.����CopyGList_GL_H_T����
	{
		printf("���� Tmp �� G = ");
		CopyGList_GL_H_T(&G, Tmp);
		Output_GL_H_T(G, Head);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��12\n������ DeleteFirst_GL_H_T ����...\n");		//12.����DeleteFirst_GL_H_T����
	{
		GList h;
		
		printf("ɾ������� Tmp �ı�ͷ��");
		DeleteFirst_GL_H_T(&Tmp, &h);
		Output_GL_H_T(h, Head);
		printf("\n");
		printf(" Tmp = ");
		Output_GL_H_T(Tmp, Head);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��6\n������ GListLength_GL_H_T ����...\n");			//6.����GListLength_GL_H_T����
	{
		printf("����� G �ĳ���Ϊ�� %d \n", GListLength_GL_H_T(G));
		printf("\n");
	} 
	PressEnter;
	
	printf("��7\n������ GListDepth_GL_H_T ����...\n");			//7.����GListDepth_GL_H_T����
	{
		printf("����� G �����Ϊ�� %d\n", GListDepth_GL_H_T(G));
		printf("\n");
	} 
	PressEnter;
	
	printf("��9\n������ GetHead_GL_H_T ����...\n");				//9.����GetHead_GL_H_T����
	{
		GList H;
		
		printf("����� G �ı�ͷ H = ");
		H = GetHead_GL_H_T(G);
		Output_GL_H_T(H, Head);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��10\n������ GetTail_GL_H_T ����...\n");			//10.����GetTail_GL_H_T����
	{
		GList T;
		
		printf("����� G �ı�β T = ");
		T = GetTail_GL_H_T(G);
		Output_GL_H_T(T, Head);
		printf("\n\n");
	}
	PressEnter;
		
	printf("��4\n������ ClearGList_GL_H_T ����...\n");			//4.����ClearGList_GL_H_T����
	{
		printf("���� G ǰ��");
		G ? printf(" G ���ڣ�\n") : printf(" G �����ڣ���\n");
		ClearGList_GL_H_T(&G);
		printf("���� G ��");
		G ? printf(" G ���ڣ�\n") : printf(" G �����ڣ���\n");
		printf("\n");
	}
	PressEnter;

	return 0;
}

void PrintElem(AtomType e)
{
	printf("%d ", e);
}
