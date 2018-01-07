/*****************************************************
 *										             *
 * 文件夹: ▲06 树和二叉树\07 ChildSiblingTree       *
 * 									                 *
 * 文件名: ChildSiblingTree.h                        *
 * 										             *
 * 内  容: 树的二叉链表（孩子-兄弟）结构相关操作列表 *
 *                                                   *
 *****************************************************/

#ifndef CHILDSIBLINGTREE_H
#define CHILDSIBLINGTREE_H

#include <stdio.h>
#include <stdlib.h>								//提供malloc、realloc、free、exit原型
#include "../../▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"				//**▲01 绪论**//

/* 树的二叉链表（孩子-兄弟）类型定义 */
typedef char TElemType_CS;						//假设树中元素均为字符
typedef struct CSNode
{
	TElemType_CS data;
	struct CSNode* firstchild;					//指向孩子
	struct CSNode* nextsibling;					//指向兄弟 
}CSNode;
typedef CSNode* CSTree;

/* 自定义栈元素类型 */
typedef CSTree SElemType_Sq;
#include "../../▲03 栈和队列/01 SequenceStack/SequenceStack.c"	//**▲03 栈和队列**// 

/* 树的二叉链表存储结构函数列表 */
void InitTree_CS(CSTree *T);
/*━━━━━━━━━━━━━┓
┃(01)构造空树T (初始化树)。┃
┗━━━━━━━━━━━━━*/

void ClearTree_CS(CSTree *T);
/*━━━━━━━┓
┃(02)清空树T。 ┃
┗━━━━━━━*/

void DestroyTree_CS(CSTree *T);
/*━━━━━━━┓
┃(03)销毁树T。 ┃
┗━━━━━━━*/

Status TreeEmpty_CS(CSTree T);
/*━━━━━━━━━━━┓
┃(04)判断树T是否为空。 ┃
┗━━━━━━━━━━━*/

Status CreateTree_CS(FILE *fp, CSTree *T); 
/*━━━━━━━━━━━┓
┃(05)按先序序列构造树。┃
┗━━━━━━━━━━━*/

int TreeDegree_CS(CSTree T);
/*━━━━━━━━┓
┃(06)返回树的度。┃
┗━━━━━━━━*/

int TreeDepth_CS(CSTree T);
/*━━━━━━━━━┓
┃(07)返回树的深度。┃
┗━━━━━━━━━*/

TElemType_CS Root_CS(CSTree T); 
/*━━━━━━━━━━━┓
┃(08)返回树的根结点值。┃
┗━━━━━━━━━━━*/

TElemType_CS Value_CS(CSTree T, int i);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(09)返回树中第i个结点值（按层序计数）。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

CSTree Order_CS(CSTree T, TElemType_CS e);
/*━━━━━━━━━━━━━━━━━━━━━━┓
┃(10)返回指向结点e的指针，NULL代表无此结点。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━*/

Status Assign_CS(CSTree T, TElemType_CS e, TElemType_CS value);
/*━━━━━━━━━━━━━┓
┃(11)替换结点e的值为value。┃
┗━━━━━━━━━━━━━*/

TElemType_CS ChildValue_CS(CSTree T, TElemType_CS e, int order);
/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(12)返回结点e的第order个孩子的值（从左至右计数）。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/

TElemType_CS Sibling_CS(CSTree T, TElemType_CS e, int mark);
/*━━━━━━━━━━━━━━━━━━━━━━┓
┃(13)返回元素e的左（右）兄弟，mark标记左右。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━*/

int ChildCount_CS(CSTree T, TElemType_CS p);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(14)返回结点p的孩子结点（子树）个数，返回负数代表结点p不存在。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

CSTree ChildSeat_CS(CSTree T, TElemType_CS e, int i);
/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(15)返回树T中结点e的第i个孩子（层序计数）的指针。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status InsertTree_CS(CSTree T, TElemType_CS e, int i, CSTree t);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(16)将树t插入为树T中e结点的第i棵子树（层序计数），i=0定义为最后一棵子树。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status DeleteTree_CS(CSTree T, TElemType_CS e, int i);
/*━━━━━━━━━━━━━━━━┓
┃(17)删除树T中e结点的第i棵子树。 ┃
┗━━━━━━━━━━━━━━━━*/

void LevelOrderTraverse_CS(CSTree T, void(Visit)(TElemType_CS));
/*━━━━━━━━┓
┃(18)层序遍历树。┃
┗━━━━━━━━*/

void PreOrderTraverse_CS(CSTree T, void(Visit)(TElemType_CS));
/*━━━━━━━━┓
┃(19)前序遍历树。┃
┗━━━━━━━━*/

void InOrderTraverse_CS(CSTree T, void(Visit)(TElemType_CS));
/*━━━━━━━┓
┃(20)中序遍历树┃
┗━━━━━━━*/

void Print_CS(CSTree T);
/*━━━━━━━━━━┓
┃(21)按树的结构打印树┃
┗━━━━━━━━━━*/

#endif
