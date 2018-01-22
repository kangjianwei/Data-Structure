#include <stdio.h>
#include "../../../▲课本算法实现/▲09 查找/11 TrieTree/TrieTree.c"

/* 函数原型 */
void Algo_9_42(TrieTree *TT, Record R);
void Algo_9_43(TrieTree *TT, KeysType K);
void Print(Record *r);

int main(int argc, char *argv[])
{
	FILE *fp;
	TrieTree TT;
	Record R = {"SUN"};
	KeysType K = {"YANG", 4};
	
	printf("创建一棵键树...\n");
	fp = fopen("Data/Algo_9_42-9_43.txt", "r");	
	CreateTrie(fp, &TT);	
	TraverseTrie(TT, Print);
	printf("\n\n");

	printf("███ 题 9.42 验证... ███\n");
	printf("插入含关键字 %s 的记录...\n", R.key);	
	Algo_9_42(&TT, R);
	TraverseTrie(TT, Print);
	printf("\n\n");	

	printf("███ 题 9.43 验证... ███\n");
	printf("删除含关键字 %s 的记录...\n", K.ch);
	Algo_9_43(&TT, K);
	TraverseTrie(TT, Print);
	printf("\n\n");	
		
	return 0;
}

void Algo_9_42(TrieTree *TT, Record R)
{
	InsertTrie(TT, R);		//已定义 
}

void Algo_9_43(TrieTree *TT, KeysType K)
{
	DeleteTrie(TT, K);		//已定义 
}

void Print(Record *r)
{
	printf("%s ", r->key);
}
