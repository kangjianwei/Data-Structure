/**************************************************
 *						                          *
 * �ļ���: ��05 ����͹����\06 GeneralizedList-E *
 * 						                          *
 * ��  ��: �������չ��������洢����غ������� *
 *                                                *
 *************************************************/

#include <stdio.h>
#include "GeneralizedList-E.c" 				//**��05 ����͹����**//

void PrintElem(AtomType e);					//��ӡ�����ԭ�� 

int main(int argc, char **argv)
{
	GList Tmp, G;
	GList g1, g2, g3;
	SString S1, S2, S3;
	
	printf("��1\n������ InitGList_GL_E ����...\n");				//1.����InitGList_GL_E����
	{
		printf("�����յĹ���� Tmp ...\n");
		InitGList_GL_E(&Tmp);
		printf("\n");
	}
	PressEnter;
	
	printf("��8\n������ GListEmpty_GL_E ����...\n");			//8.����GListEmpty_GL_E����
	{
		int tag;
		
		tag = GListEmpty_GL_E(Tmp);
		tag ? printf(" Tmp Ϊ�գ�\n") : printf(" Tmp ��Ϊ�գ���\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��2��3\n������ sever_GL_E��CreateGList_GL_E ����...\n");	//2��3.����sever_GL_E��CreateGList_GL_E����
	{
		char *s1 = "()";
		char *s2 = "(e)";
		char *s3 = "(a,(b,c,d))";
		
		printf("���������S1��S2��S3...\n");
		StrAssign_Sq(S1, s1);
		CreateGList_GL_E(&g1, S1);
		StrAssign_Sq(S2, s2);
		CreateGList_GL_E(&g2, S2);
		StrAssign_Sq(S3, s3);
		CreateGList_GL_E(&g3, S3);
		printf("\n");
	}
	PressEnter;
		
	printf("��11\n������ InsertFirst_GL_E ����...\n");			//11.����InsertFirst_GL_H_T����		
	{
		printf("�� S3��S2��S1 ���β��뵽 Tmp ���׸�λ��...\n");
		InsertFirst_GL_E(&Tmp, g3);
		InsertFirst_GL_E(&Tmp, g2);
		InsertFirst_GL_E(&Tmp, g1);
		printf("\n");
	}
	PressEnter;
	
	printf("��13\n������ Traverse_GL_E ����...\n");				//13.����Traverse_GL_E����
	{
		printf("����������ԭ�� Tmp = ");
		Traverse_GL_E(Tmp, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("��14\n������ Output_GL_E ����...\n");				//14.����Output_GL_E����
	{
		printf("�������������� Tmp = ");
		Output_GL_E(Tmp);
		printf("\n\n");
	}
	PressEnter;

	printf("��5\n������ CopyGList_GL_E ����...\n");				//5.����CopyGList_GL_E����
	{
		printf("���� Tmp �� G = ");
		CopyGList_GL_E(&G, Tmp);
		Output_GL_E(G);
		printf("\n\n");
	}
	PressEnter;
		
	printf("��12\n������ DeleteFirst_GL_E ����...\n");			//12.����DeleteFirst_GL_E����
	{
		GList h;
		
		printf("ɾ������� Tmp �ı�ͷ��");
		DeleteFirst_GL_E(&Tmp, &h);
		Output_GL_E(h);
		printf("\n");
		printf(" Tmp = ");
		Output_GL_E(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��6\n������ GListLength_GL_E ����...\n");			//6.����GListLength_GL_E����
	{
		printf("����� G �ĳ���Ϊ��%d\n", GListLength_GL_E(G));
		printf("\n");
	}
	PressEnter;
	
	printf("��7-1��7-2\n������ GListDepth_GL_E_1�� ����...\n");	//7-1��7-2.����GListDepth_GL_E_1�Ȳ���
	{
		printf("����� Tmp �����Ϊ��%d\n", GListDepth_GL_E_1(Tmp));
		printf("����� G   �����Ϊ��%d\n", GListDepth_GL_E_2(G));
		printf("\n");
	}
	PressEnter;
	
	printf("��9\n������ GetHead_GL_E ����...\n");				//9.����GetHead_GL_E����
	{
		GList H;
		
		printf("��ȡ����� G �ı�ͷ H = ");
		H = GetHead_GL_E(G);
		Output_GL_E(H);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��10\n������ GetTail_GL_E ����...\n");				//10.����GetTail_GL_E����
	{
		GList T;
		
		printf("��ȡ����� G �ı�β T = ");
		T = GetTail_GL_E(G);
		Output_GL_E(T);
		printf("\n\n");
	}
	PressEnter;
		
	printf("��4\n������ DestroyGList_GL_E ����...\n");			//4.����DestroyGList_GL_E����
	{
		printf("���� G ǰ��");
		G ? printf(" G ���ڣ�\n") : printf(" G �����ڣ���\n");
		DestroyGList_GL_E(&G);
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
