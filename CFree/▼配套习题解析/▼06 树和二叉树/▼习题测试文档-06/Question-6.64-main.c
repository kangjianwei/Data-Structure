#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"							//**��01 ����**//
#include "../../../���α��㷨ʵ��/��06 ���Ͷ�����/05 ParentTree/ParentTree.c" 	//**��06 ���Ͷ�����**//

/* ����ԭ�� */
int Algo_6_64(PTree T);

int main(int argc, char *argv[])
{
	PTree T;
	int depth;
	FILE *fp;
	
	InitTree_P(&T);
	fp = fopen("Data/Algo_6_64.txt", "r");
	CreateTree_P(fp, &T);
	fclose(fp);
	printf("\n");

	printf("��������Ϊ��\n");
	Print_P(T);
	printf("\n");

	depth = Algo_6_64(T);
	
	printf("���������Ϊ�� %d\n", depth);
	printf("\n");
	
	return 0;
}

/*������������������������������������
����6.63�����㺢�������ʾ��������ȩ�
������������������������������������*/
int Algo_6_64(PTree T)
{
	return TreeDepth_P(T); 				//�Ѷ��� 
}
