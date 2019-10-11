/******************************
 *                            *
 * 文件夹: ▲09 查找          *
 *                            *
 * 文件名: TrieTree.h         *
 *                            *
 * 内  容: Trie树相关操作列表 *
 *                            *
 ******************************/

#ifndef TRIETREE_H
#define TRIETREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>						//提供isalpha原型 
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"		//**▲01 绪论**//

/* 宏定义 */
#define MAXKEYLEN 26							//关键字的最大长度 

/* 类型定义 */
typedef enum{ LEAF, BRANCH }NodeKind;			//结点种类：0-叶子，1-分支
typedef struct
{
	char ch[MAXKEYLEN+1];						//关键字 
	int num;									//关键字长度 
}KeysType;										//关键字类型 
typedef struct									//叶子结点的记录类型
{
	char key[MAXKEYLEN+1];
}Record;										//记录类型 
typedef struct TrieNode							//Trie树存储表示
{
	NodeKind kind;								//结点种类	 
	union
	{
		struct
		{	
			struct TrieNode* ptr[MAXKEYLEN+1];	//存储26个英文字母和1个"空"字母 
			int count;							//当前分支结点已占用的字母数 
		}bh;									//分支结点 
		
		struct
		{
			KeysType K;
			Record *infoptr;
		}lf;									//叶子结点 
	}Ptr;
}TrieNode;										//Trie树结点 
typedef TrieNode* TrieTree;						//指向Trie树结点的指针

/* Trie树函数列表 */
Status CreateTrie(FILE *fp, TrieTree *TT);
/*━━━━━━━┓
┃(01)创建Trie树┃
┗━━━━━━━*/

Record* SearchTrie(TrieTree TT, KeysType K);
/*━━━━━━━━━┓
┃(02)算法9.16：查找┃
┗━━━━━━━━━*/

Status InsertTrie(TrieTree *TT, Record R); 
/*━━━━━━┓
┃(03)插入记录┃
┗━━━━━━*/

Status DeleteTrie(TrieTree *TT, KeysType K);
/*━━━━━━━━━━━━━┓
┃(04)删除含有关键字K的记录 ┃
┗━━━━━━━━━━━━━*/

int ord(char ch); 
/*━━━━━━━━━━━━━━━━━┓
┃(05)返回字符ch在Trie树结点中的位序┃
┗━━━━━━━━━━━━━━━━━*/

Status cmp(KeysType A, KeysType B);
/*━━━━━━━━━━━━┓
┃(06)判断结构A与B是否相等┃
┗━━━━━━━━━━━━*/

void TraverseTrie(TrieTree TT, void(Visit)(Record*)); 
/*━━━━━━━┓
┃(07)遍历Trie树┃
┗━━━━━━━*/

#endif 
