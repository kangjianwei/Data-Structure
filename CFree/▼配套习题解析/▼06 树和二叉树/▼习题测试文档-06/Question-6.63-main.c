#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/06 ChildTree/ChildTree.c" //**��06 ���Ͷ�����**//

/* ����ԭ�� */
int Algo_6_63_1(CTree T);
int Algo_6_63_2(CTree T);

int main(int argc, char *argv[])
{
	CTree T;
	int depth_1, depth_2;
	FILE *fp;
	
	fp = fopen("Data/Algo_6_63.txt", "r");	
	InitTree_C(fp, &T);	
	CreateTree_C(fp, &T);
	fclose(fp);
	printf("\n");

	printf("��������Ϊ��\n");	
	Print_C_1(T);
	printf("\n");
	
	depth_1 = Algo_6_63_1(T);

	depth_2 = Algo_6_63_2(T);
	
	printf("���� 1�����������Ϊ�� %d\n", depth_1);
	printf("���� 2�����������Ϊ�� %d\n", depth_2);
	printf("\n");
	
	return 0;
}

/*������������������������������������
����6.63�����㺢�������ʾ��������ȩ�
������������������������������������*/
/* ����1: �����ڴ�˫�׵ĺ������� */
int Algo_6_63_1(CTree T)						 
{
	return TreeDepth_C_1(T);				//�Ѷ��� 
}

/* ����2: ͨ���ں�����������˫��Ҳ���� */
int Algo_6_63_2(CTree T)
{
	return TreeDepth_C_2(T); 				//�Ѷ��� 
}
