/************************************
 *						            *
 * �ļ���: ��08 ��̬�洢����        *
 * 						            *
 * �ļ���: BoundaryTagMethod-main.c *
 * 							        *
 * ��  ��: �߽��ʶ����غ�������   *
 *                                  *
 ************************************/

#include <stdio.h>
#include "BoundaryTagMethod.c" 									//**��08 ��̬�洢����**//													

int main(int argc, char *argv[])
{	
	WORD_a memory[MAX];
	Space pav;						 
	Space p1, p2, p3, p4;

	printf("��1��4\n������ InitSpace_a�� ����...\n");				//1��4.����InitSpace_a��PrintLayout_a����	
	{
		printf("��ʼ��һ���ڴ�� ��");
		InitSpace_a(memory);
		pav = av;
		PrintLayout_a(av, pav);
		printf("\n");
	}	
	PressEnter; 

	printf("��2\n������ AllocBoundTag ����...\n");				//2.����AllocBoundTag����		
	{
		printf("�����СΪ 100 ���ڴ�� p1 ��...\n");
		p1 = AllocBoundTag(&pav, 100);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 

	printf("�����СΪ 600 ���ڴ�� p2 ��...\n");	
	{
		p2 = AllocBoundTag(&pav, 600);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 

	printf("�����СΪ 200 ���ڴ�� p3 ��...\n");
	{
		p3 = AllocBoundTag(&pav, 200);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 

	printf("��3\n������ Reclaim_a ����...\n");					//3.����Reclaim_a����	
	{
		printf("���մ�СΪ 600 ���ڴ�� p2 ��...\n");
		Reclaim_a(&pav, &p2);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 

	printf("�����СΪ 400 ���ڴ�� p4 ��...\n");	
	{
		p4 = AllocBoundTag(&pav, 400);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 

	printf("���մ�СΪ 100 ���ڴ�� p1 ��...\n");
	{
		Reclaim_a(&pav, &p1);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 
	
	printf("���մ�СΪ 400 ���ڴ�� p4 ��...\n");
	{
		Reclaim_a(&pav, &p4);
		PrintLayout_a(av, pav);
		printf("\n");
	}
	PressEnter; 
			
	return 0;
}

