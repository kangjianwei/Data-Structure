/********************************
 *						        *
 * �ļ���: ��08 ��̬�洢����    *
 * 						        *
 * �ļ���: BuddySystem-main.c   *
 * 							    *
 * ��  ��: ���ϵͳ��غ������� *
 *                              *
 ********************************/

#include <stdio.h>
#include "BuddySystem.c" 									//**��08 ��̬�洢����**//

int main(int argc, char *argv[])
{	
	FreeList avail;
	WORD_b *p1, *p2, *p3, *p4;

	printf("��1��5\n������ InitSpace_b�� ����...\n");			//1��5.����InitSpace_b��PrintLayout_b����
	{
		printf("��ʼ��һ���ڴ�� ��");	
		InitSpace_b(avail);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;

	printf("��2\n������ AllocBuddy ����...\n");				//2.����AllocBuddy����	
	{
		printf("�����СΪ 1 ���ڴ�� p1 ��...\n");	
		p1 = AllocBuddy(avail, 1);
		PrintLayout_b(avail);
		printf("\n");
	}
	PressEnter;
	
	printf("�����СΪ 2 ���ڴ�� p2 ��...\n");
	{
		p2 = AllocBuddy(avail, 2);
		PrintLayout_b(avail);
		printf("\n");
	}
	PressEnter;
	
	printf("�����СΪ 3 ���ڴ�� p3 ��...\n");
	{
		p3 = AllocBuddy(avail, 3);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;
	
	printf("�����СΪ 1 ���ڴ�� p4 ��...\n");
	{
		p4 = AllocBuddy(avail, 1);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;

	printf("��3��4\n������ Reclaim_b�� ����...\n");			//3��4.����Buddy��Reclaim_b����	
	{
		printf("�����ڴ�� p1 ��...\n");	
		Reclaim_b(avail, &p1);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;
	
	printf("�����ڴ�� p2 ��...\n");
	{
		Reclaim_b(avail, &p2);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;
	
	printf("�����ڴ�� p3 ��...\n");
	{
		Reclaim_b(avail, &p3);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;
	
	printf("�����ڴ�� p4 ��...\n");
	{
		Reclaim_b(avail, &p4);
		PrintLayout_b(avail);
		printf("\n");
	} 
	PressEnter;
			
	return 0;
}

