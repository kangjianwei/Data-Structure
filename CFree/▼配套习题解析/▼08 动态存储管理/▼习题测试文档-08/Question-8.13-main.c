#include <stdio.h>
#include "../../../���α��㷨ʵ��/��08 ��̬�洢����/01 BoundaryTagMethod/BoundaryTagMethod.c"//**��08 ��̬�洢����**//

/* ����ԭ�� */
int Algo_8_13(Space *pav, Space **p);

int main(int argc, char *argv[])
{
	WORD_a memory[MAX];
	Space pav, p1, p2, p3;						 
	Space *p;
	
	printf("��ʼ��һ���ڴ�� ��");
	InitSpace_a(memory);
	pav = av;
	PrintLayout_a(av, pav);
	printf("\n");
	
	p1 = AllocBoundTag(&pav, 200);
	p2 = AllocBoundTag(&pav, 200);
	p3 = AllocBoundTag(&pav, 200);
	printf("�ֱ������СΪ 200 ���ڴ�� p1��p2��p3 ��...\n");
	PrintLayout_a(av, pav);
	printf("\n");
	
	printf("�����ڴ�� p2 ��...\n");
	p = &p2;
	Algo_8_13(&pav, &p);
	PrintLayout_a(av, pav);
	printf("\n");
			
	return 0;
}

/*����������������������������
����8.13���߽��־�������㷨��
����������������������������*/
int Algo_8_13(Space *pav, Space **p)
{
	Reclaim_a(pav, *p);		//�Ѷ��� 
}
