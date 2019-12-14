#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"  	                     	//**��01 ����**//
#include "../../../���α��㷨ʵ��/��05 ����͹����/04 CrossList/CrossList.c"   //**��05 ����͹����**//

/* ����ԭ�� */
Status Algo_5_26(CrossList M);

int main(int argc, char *argv[])
{
	CrossList M;
	FILE *fp;
	
	printf("����ʮ������ M...\n");
	fp = fopen("Data/Algo_5_26.txt", "r");	
	CreateSMatrix_OL(fp, 1, &M);
	fclose(fp);	
	printf("M = \n");
	PrintSMatrix_OL(M);
	printf("\n");

	printf("����Ԫ����ʽ��� M...\n");
	printf(" �� ��  ֵ\n");	
	Algo_5_26(M);
	printf("\n");
		
	return 0;
}

/*����������������������������������
����5.26������Ԫ����ʽ���ʮ������
����������������������������������*/ 
Status Algo_5_26(CrossList M)
{
	int i, j;
	OLNode *p;
	
	if(!M.tu)
		return ERROR;
	
	for(i=1; i<=M.mu; ++i)
	{
		p = M.rhead[i];
		for(j=1; j<=M.nu; ++j)
		{
			if(p && p->j==j)
			{
				printf("(%2d %2d %3d)\n", i, j, p->e);
				p = p->right;
			}
		}
	}
	
	return OK;
}
