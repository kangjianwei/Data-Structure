/****************************************************
 *                                                  *
 * 文件夹: ▲06 树和二叉树\06 ChildTree             *
 *                                                  *
 * 文件名: ChildTree.h                              *
 *    	    			                            *
 * 内  容: 树的孩子链表(带双亲)存储表示相关操作列表 *
 *                                                  *
 ****************************************************/

#ifndef CHILDTREE_H
#define CHILDTREE_H

#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include "../../▲01 绪论/Status.h"						//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"						//**▲01 绪论**//
#include "../../▲03 栈和队列/07 LinkQueue/LinkQueue.c" //**▲03 栈和队列**//
#include "../../▲03 栈和队列/01 SequenceStack/SequenceStack.c"	//**▲03 栈和队列**// 

/* 宏定义 */
#define MAX_TREE_SIZE 100						//树的最大结点数

/* 孩子树类型定义 */
typedef char TElemType_C;						//假设树中元素均为字符
typedef struct CTNode							//孩子结点 
{
	int child;
	struct CTNode* next;
}CTNode;
typedef CTNode* ChildPtr;						//孩子结点指针 
typedef struct
{
	int parent;									//双亲结点位置 
	TElemType_C data;
	ChildPtr firstchild;						//孩子链表头指针 
}CTBox;
typedef struct
{
	CTBox nodes[MAX_TREE_SIZE];
	int r;										//根的位置 
	int n;										//树的结点数 
}CTree; 

/* 树的孩子链表存储结构函数列表 */
void InitTree_C(FILE *fp, CTree *T);
/*━━━━━━━━━━━━━┓
┃(01)构造空树T (初始化树)。┃
┗━━━━━━━━━━━━━*/

void FreeChild_C(ChildPtr *p);
/*━━━━━━━━━┓
┃(02)删除孩子链表。┃
┗━━━━━━━━━*/

void ClearTree_C(CTree *T);
/*━━━━━━━┓
┃(03)清空树T。 ┃
┗━━━━━━━*/

void DestroyTree_C(CTree *T);
/*━━━━━━━┓
┃(04)销毁树T。 ┃
┗━━━━━━━*/

Status TreeEmpty_C(CTree T);
/*━━━━━━━━━━━┓
┃(05)判断树T是否为空。 ┃
┗━━━━━━━━━━━*/

Status CreateTree_C(FILE *fp, CTree *T); 
/*━━━━━━━━━━━┓
┃(06)按层序序列构造树。┃
┗━━━━━━━━━━━*/

int TreeDegree_C(CTree T);
/*━━━━━━━━┓
┃(07)返回树的度。┃
┗━━━━━━━━*/

int TreeDepth_C_1(CTree T);
/*━━━━━━━━━━━━━━━━━━┓
┃(08-1)返回树的深度（借助双亲标志）。┃
┗━━━━━━━━━━━━━━━━━━*/

int TreeDepth_C_2(CTree T);
/*━━━━━━━━━━━━━━━━━━━┓
┃(08-2)返回树的深度（不借助双亲标志）。┃
┗━━━━━━━━━━━━━━━━━━━*/

int Depth_C(CTree T, int i);
/*━━━━━━━━━━━━━━━━━┓
┃(09)求T中第i个结点开始的子树深度。┃
┗━━━━━━━━━━━━━━━━━*/

TElemType_C Root_C(CTree T); 
/*━━━━━━━━━━━┓
┃(10)返回树的根结点值。┃
┗━━━━━━━━━━━*/

TElemType_C Value_C(CTree T, int i);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(11)返回树中第i个结点值（按层序计数）。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

int Order_C(CTree T, TElemType_C e);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(12)返回结点e的值位置(在数组中位置)，-1代表无此结点。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status Assign_C(CTree *T, TElemType_C e, TElemType_C value);
/*━━━━━━━━━━━━━┓
┃(13)替换结点e的值为value。┃
┗━━━━━━━━━━━━━*/

TElemType_C ChildValue_C(CTree T, TElemType_C e, int order);
/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(14)返回结点e的第order个孩子的值（从左至右计数）。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/

TElemType_C Sibling_C_1(CTree T, TElemType_C e, int mark);
/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃(15-1)返回元素e的左（右）兄弟，mark标记左右。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/

int Sibling_C_2(CTree T, int order, int mark);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(15-2)返回序号为i的结点左（右）兄弟的序号，mark标记左右。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

int ChildCount_C(CTree T, TElemType_C p);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(16)返回结点p的孩子结点（子树）个数，返回负数代表结点p不存在。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

int ChildSeat_C(CTree T, TElemType_C p, int i);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(17)返回树T中p结点的第i个孩子（层序计数）的位置，i=0定义为最后一个孩子。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

ChildPtr SiblingSeat_C(CTree T, TElemType_C p);
/*━━━━━━━━━━━━━━━━━━━┓
┃(18)返回在孩子链表中指向元素p的指针。 ┃
┗━━━━━━━━━━━━━━━━━━━*/

Status InsertChild_C(CTree *T, TElemType_C p, int i, TElemType_C e);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(19)将结点e插入为树T中p结点的第i个孩子（层序计数），i=0定义为最后一个孩子。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status InsertTree_C(CTree *T, TElemType_C p, int i, CTree t);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(20)将树t插入为树T中p结点的第i棵子树（层序计数），i=0定义为最后一棵子树。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status DeleteTree_C(CTree *T, TElemType_C p, int i);
/*━━━━━━━━━━━━━━━━┓
┃(21)删除树T中p结点的第i棵子树。 ┃
┗━━━━━━━━━━━━━━━━*/

void LevelOrderTraverse_C(CTree T, void(Visit)(TElemType_C));
/*━━━━━━━━┓
┃(22)层序遍历树。┃
┗━━━━━━━━*/

void Print_C_1(CTree T);
/*━━━━━━━━━━━━━━━━┓
┃(23-1)依赖于双亲结点信息打印树。┃
┗━━━━━━━━━━━━━━━━*/

void Print_C_2(CTree T, int start, int step);
/*━━━━━━━━━━━━━━━━━━━━━┓
┃(23-2)不依赖与双亲结点以凹入表形式打印树。┃
┗━━━━━━━━━━━━━━━━━━━━━*/

void ShowTree_C(CTree T);
/*━━━━━━━━━━━┓
┃(24)展示树的存储结构。┃
┗━━━━━━━━━━━*/

#endif
