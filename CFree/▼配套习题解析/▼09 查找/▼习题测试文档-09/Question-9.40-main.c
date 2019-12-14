#include <stdio.h>
#include "../../../���α��㷨ʵ��/��09 ����/07 BalancedBinarySortTree/BalancedBinarySortTree.c" //**��09 ����**//

/* �궨�� */
#define Max 15

/* ����ԭ�� */
BBSTree Algo_9_40(BBSTree BBST, int k);	//�ҳ�ƽ��������е�kС�Ľ�� 
int fLsize_9_40(BBSTree BBST);			//����lsizeֵ

int main(int argc, char *argv[])
{	

	FILE *fp;
	Table T;
	BBSTree BBST, p;
	int k = 5;
		
	printf("���������һ�����ұ�...\n");
	fp = fopen("Data/Algo_9_40.txt", "r");	
	Create(fp, &T, Max);	
	Traverse(T, PrintKey);	
	printf("\n");	
		
	printf("���첢��ӡ�����������еĹؼ��֣�");
	CreateAVL(&BBST, T);	
	printf("��ӡƽ���������\n");
	PrintAVLTree(BBST);
	printf("\n");

	fLsize_9_40(BBST);				 
	p = Algo_9_40(BBST, k);
	printf("ƽ��������д�С�������е� %d ���ؼ���Ϊ %d ��\n", k, p->data);
	printf("\n");
		
	return 0;
}

BBSTree Algo_9_40(BBSTree BBST, int k)
{
	if(!BBST)
		return NULL;
	else
	{
		if(k==BBST->lsize)
			return BBST;
		else if(k<BBST->lsize)
			return Algo_9_40(BBST->lchild, k);
		else
			return Algo_9_40(BBST->rchild, k-BBST->lsize);	//kֵ�ı� 
	}
}

int fLsize_9_40(BBSTree BBST)
{
	int lnum, rnum;
	
	if(BBST)
	{
		lnum = fLsize_9_40(BBST->lchild);	//������������ 
		rnum = fLsize_9_40(BBST->rchild);	//������������ 
		
		BBST->lsize = lnum + 1;
		
		return lnum+rnum+1;
	}
	else
		return 0;
}
