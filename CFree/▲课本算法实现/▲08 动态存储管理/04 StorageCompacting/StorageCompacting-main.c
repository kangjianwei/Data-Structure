/************************************
 *						            *
 * �ļ���: ��08 ��̬�洢����        *
 * 						            *
 * �ļ���: StorageCompacting-main.c *
 * 							        *
 * ��  ��: �洢������غ�������     *
 *                                  *
 ************************************/

#include <stdio.h> 
#include "StorageCompacting.c" 									//**��08 ��̬�洢����**//

int main(int argc, char *argv[])
{
	int *p1, *p4;
	char *p2, *p5;
	float *p3;

	printf("��1\n������ InitMemory ����...\n");					//1.����InitMemory����	
	{
		printf("��ʼ��һ���СΪ %d ���ڴ�...\n", MAX);
		InitMemory(MAX);
		printf("\n");
	}
	PressEnter;

	printf("��5\n������ PrintLayout ����...\n");					//5.����PrintLayout����	
	{
		printf("�����ǰ�ڴ�������...\n");
		PrintLayout();
		printf("\n");
	} 
	PressEnter;

	printf("��2��3\n������ MallocMemory��CompressMemory ����...\n");//2��3.����MallocMemory��CompressMemory����		
	{
		printf("�����СΪ %d ���ڴ�� p1...\n", 100*sizeof(int));		
		p1 = (int*)MallocMemory(100*sizeof(int));
		PrintLayout();	
		printf("\n");
		PressEnter;

		printf("�����СΪ %d ���ڴ�� p2...\n", 100*sizeof(char));		
		p2 = (char*)MallocMemory(100*sizeof(char));
		PrintLayout();
		printf("\n");
		PressEnter;

		printf("�����СΪ %d ���ڴ�� p3...\n", 100*sizeof(float));	
		p3 = (float*)MallocMemory(100*sizeof(float));
		PrintLayout();
		printf("\n");
	} 
	PressEnter;

	printf("��4\n������ FreeMemory ����...\n");					//4.����FreeMemory����
	{
		printf("�ͷ� p2 ָ����ڴ��...\n");	
		FreeMemory(p2);
		PrintLayout();
		printf("\n"); 
		PressEnter;

		printf("�����СΪ %d ���ڴ�� p5...\n", 200*sizeof(char));	
		p5 = (char*)MallocMemory(200*sizeof(char));
		PrintLayout();			
		printf("\n");
		PressEnter;

		printf("�����СΪ %d ���ڴ�� p4...\n", sizeof(int));	
		p4 = (int*)MallocMemory(100*sizeof(int));
		PrintLayout();
		printf("\n");
	} 
	PressEnter;
		
	return 0;
}

