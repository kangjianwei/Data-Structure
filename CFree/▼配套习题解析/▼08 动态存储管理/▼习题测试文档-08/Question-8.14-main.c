#include <stdio.h>
#include "../../../���α��㷨ʵ��/��08 ��̬�洢����/02 BuddySystem/BuddySystem.c"//**��08 ��̬�洢����**//

/* ����ԭ�� */
void Algo_8_14(FreeList avail, WORD_b **p);

int main(int argc, char *argv[])
{
	FreeList avail;
	WORD_b *p;

	printf("��ʼ��һ���ڴ�� ��");	
	InitSpace_b(avail);
	PrintLayout_b(avail);
	printf("\n");

	printf("�����СΪ 1 ���ڴ�� p ��...\n");	
	p = AllocBuddy(avail, 1);
	PrintLayout_b(avail);
	printf("\n");

	printf("�����ڴ�� p ��...\n");	
	Algo_8_14(avail, &p);
	PrintLayout_b(avail);
	printf("\n");
				
	return 0;
}

/*������������������������������
����8.14��������ϵͳ�����㷨��
������������������������������*/
void Algo_8_14(FreeList avail, WORD_b **p)
{
	Reclaim_b(avail, p);		//�Ѷ��� 
}
