/******************************
 *						      *
 * 文件夹: ▲09 查找          *
 * 						      *
 * 文件名: TrieTree-main.c    *
 * 						      *
 * 内  容: Trie树相关函数测试 *
 *                            *
 ******************************/

#include <stdio.h> 
#include "TrieTree.c" 		//**▲09 查找**//

/* 函数原型 */
void Print(Record *r);		//输出记录r的关键字
	 
int main(int argc, char *argv[])
{	
	TrieTree TT;	
	
	printf("▼1、3、5、6\n▲函数 CreateTrie等 测试...\n");		//1、3、5、6.函数CreateTrie等测试		
	{
		FILE *fp;
		
		printf("创建一棵Trie树...\n");
		fp = fopen("TestData_Table.txt", "r");	
		CreateTrie(fp, &TT);	
		printf("\n");
	} 
	PressEnter;
	
	printf("▼7\n▲函数 TraverseTrie 测试...\n");				//7.函数TraverseTrie测试		
	{
		printf("输出Trie树中的记录...\n");	
		TraverseTrie(TT, Print);	
		printf("\n\n");	
	} 
	PressEnter; 
	
	printf("▼2\n▲函数 SearchDLTree 测试...\n");				//2.函数SearchDLTree测试		
	{
		Record *p;
		KeysType K = {"LONG", 4};
		
		printf("查找关键字 %s ...\n", K.ch);
		p = SearchTrie(TT, K);
		p ? printf("查找成功！\n") : printf("查找失败!!\n");
		printf("\n");	
	}
	PressEnter;

	printf("▼4\n▲函数 DeleteTrie 测试...\n");					//4.函数DeleteTrie测试	
	{
		KeysType K1 = {"CAI", 3};
		KeysType K2 = {"CAO", 3};
	
		printf("依次删除含有关键字 %s、%s 的记录...\n", K1.ch, K2.ch);
		DeleteTrie(&TT, K1);
		TraverseTrie(TT, Print);
		printf("\n");
		DeleteTrie(&TT, K2);
		TraverseTrie(TT, Print);
		printf("\n\n");
	} 
	PressEnter;
		
	return 0;
}

void Print(Record *r)
{
	printf("%s ", r->key);
}
