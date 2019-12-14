#include <stdio.h>
#include "../../../���α��㷨ʵ��/��09 ����/11 TrieTree/TrieTree.c"

/* ����ԭ�� */
void Algo_9_42(TrieTree *TT, Record R);
void Algo_9_43(TrieTree *TT, KeysType K);
void Print(Record *r);

int main(int argc, char *argv[])
{
	FILE *fp;
	TrieTree TT;
	Record R = {"SUN"};
	KeysType K = {"YANG", 4};
	
	printf("����һ�ü���...\n");
	fp = fopen("Data/Algo_9_42-9_43.txt", "r");	
	CreateTrie(fp, &TT);	
	TraverseTrie(TT, Print);
	printf("\n\n");

	printf("������ �� 9.42 ��֤... ������\n");
	printf("���뺬�ؼ��� %s �ļ�¼...\n", R.key);	
	Algo_9_42(&TT, R);
	TraverseTrie(TT, Print);
	printf("\n\n");	

	printf("������ �� 9.43 ��֤... ������\n");
	printf("ɾ�����ؼ��� %s �ļ�¼...\n", K.ch);
	Algo_9_43(&TT, K);
	TraverseTrie(TT, Print);
	printf("\n\n");	
		
	return 0;
}

void Algo_9_42(TrieTree *TT, Record R)
{
	InsertTrie(TT, R);		//�Ѷ��� 
}

void Algo_9_43(TrieTree *TT, KeysType K)
{
	DeleteTrie(TT, K);		//�Ѷ��� 
}

void Print(Record *r)
{
	printf("%s ", r->key);
}
