/******************************
 *                            *
 * 文件夹: ▲09 查找          *
 *                            *
 * 文件名: DLTree.h           *
 *                            *
 * 内  容: 双链树相关操作列表 *
 *                            *
 ******************************/

#ifndef DLTREE_H
#define DLTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../▲01 绪论/Status.h"			//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"			//**▲01 绪论**//

/* 宏定义 */
#define MAXKEYLEN 16						//关键字的最大长度 

/* 类型定义 */
typedef enum{ LEAF, BRANCH }NodeKind;		//结点种类：0-叶子，1-分支
typedef struct
{
	char ch[MAXKEYLEN+1];					//关键字 
	int num;								//关键字长度 
}KeysType;									//关键字类型 
typedef char Record;						//记录类型 
typedef struct DLTNode						//双链树存储表示
{
	NodeKind kind;							//结点种类	 
	char symbol;							//存储关键字的一个字符 
	struct DLTNode* next;					//指向兄弟结点的指针
	union
	{
		Record *infoptr;					//叶子结点的记录指针 
		struct DLTNode* first;				//分支结点的孩子链指针	
	}Ptr;
}DLTNode;									//B树结点 
typedef DLTNode* DLTree;					//指向B树结点的指针

/* 双链树函数列表 */
Status CreateDLTree(FILE *fp, DLTree *DLT);
/*━━━━━━━━┓
┃(01)创建双链树。┃
┗━━━━━━━━*/

Record* SearchDLTree(DLTree DLT, KeysType K);
/*━━━━━━━━━━━━━━━━━━━┓
┃(02)算法9.15：查找，返回指向K的指针。 ┃
┗━━━━━━━━━━━━━━━━━━━*/

Status InsertDLTree(DLTree *DLT, KeysType K); 
/*━━━━━━━━━━━━━━━━━━┓
┃(03)插入：将关键字K插入到双链树中。 ┃
┗━━━━━━━━━━━━━━━━━━*/

void PrintKeys(DLTree DLT); 
/*━━━━━━━━━━━━┓
┃(04)输出双链树中关键字。┃
┗━━━━━━━━━━━━*/

#endif 
