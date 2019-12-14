#include <stdio.h>
#include "../../../���α��㷨ʵ��/��09 ����/09 B+Tree/B+Tree.c"

/* �궨�� */
#define Max 15

/* ����ԭ�� */
Result Algo_9_41(B_Tree B_T, KeyType K);

int main(int argc, char *argv[])
{
	FILE *fp;
	Table T;
	B_Tree B_T;
	KeyType Key = 37;
	Result R;
	 
	printf("�������ұ�...\n");
	fp = fopen("Data/Algo_9_41.txt", "r");	
	Create(fp, &T, Max);	
	Traverse(T, PrintKey);	
	printf("\n");

	printf("����B+��...\n");
	CreateB_Tree(&B_T, T);
	PrintB_Tree(B_T);
	printf("\n");

	printf("���ҹؼ��� %d ...\n", Key);	
	R = Algo_9_41(B_T, Key);
	if(R.tag)
		printf("���ҵ��ؼ��� %d��", R.pt->key[R.i]); 
	else
		printf("δ�ҵ��ؼ��֣���");
	printf("\n\n");
		
	return 0;
}

Result Algo_9_41(B_Tree B_T, KeyType K)
{
	return SearchB_Tree(B_T, K);		//�Ѷ��� 
}
