#include <stdio.h>
#include "../../../���α��㷨ʵ��/��08 ��̬�洢����/04 StorageCompacting/StorageCompacting.c"//**��08 ��̬�洢����**//

/* ����ԭ�� */
int Algo_8_16();

int main(int argc, char *argv[])
{
	char *p1, *p2, *p3;
	int k;
	
	printf("��ʼ��һ���СΪ %d ���ڴ�...\n", 300);
	InitMemory(300);	
	printf("\n");
	
	printf("�ֱ������СΪ %d ���ڴ�� p1��p2��p3...\n", 100*sizeof(char));		
	p1 = (char*)MallocMemory(100*sizeof(char));	
	p2 = (char*)MallocMemory(100*sizeof(char));	
	p3 = (char*)MallocMemory(100*sizeof(char));	
	PrintLayout();
	printf("\n");
	
	printf("�ͷ� p2 ָ����ڴ��...\n");
	FreeMemory(p2);
	PrintLayout();
	printf("\n");

	printf("�����洢֮��...\n");
	Algo_8_16();
	PrintLayout();
	printf("\n");
			
	return 0;
}

/*����������������������
����8.16���洢�����㷨��
����������������������*/
int Algo_8_16()
{
	return CompressMemory();		//�Ѷ��� 
}
