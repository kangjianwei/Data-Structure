/**********************************************
 *											  *
 * 文件夹: ▲06 树和二叉树\03 Tri_BinaryTree  *
 * 									    	  *
 * 文件名: Tri_BinaryTree.h                   *
 * 											  *
 * 内  容: 二叉树三叉链表存储结构相关操作列表 *
 *                                            *
 **********************************************/

#ifndef TRI_BINARYTREE_H
#define TRI_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>								//提供malloc、realloc、free、exit原型
#include <math.h>								//提供pow、log原型 
#include "../../▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"				//**▲01 绪论**//

/* 二叉树（三叉链表存储）相关类型定义 */
typedef char TElemType_Tri;						//假设二叉树元素均为字符
typedef struct TBiTNode
{
	TElemType_Tri data;							//结点元素
	struct TBiTNode* parent;					//双亲结点指针 
	struct TBiTNode* lchild;					//左孩子指针 
	struct TBiTNode* rchild;					//右孩子指针 
}TBiTNode;										//二叉树结点 
typedef TBiTNode* TBiTree;						//指向二叉树结点的指针

/* 队列元素类型 */
typedef TBiTree QElemType_L;						
#include "../../▲03 栈和队列/07 LinkQueue/LinkQueue.c" //**▲03 栈和队列**//

/* 二叉树三叉链表存储结构函数列表 */
void InitBiTree_Tri(TBiTree *T);
/*━━━━━━━━━━━━━━━━━┓
┃(01)构造空二叉树T (初始化二叉树)。┃
┗━━━━━━━━━━━━━━━━━*/

void ClearBiTree_Tri(TBiTree *T);
/*━━━━━━━━━┓
┃(02)清空二叉树T。 ┃
┗━━━━━━━━━*/

void DestroyBiTree_Tri(TBiTree *T);
/*━━━━━━━━━┓
┃(03)销毁二叉树T。 ┃
┗━━━━━━━━━*/

Status BiTreeEmpty_Tri(TBiTree T);
/*━━━━━━━━━━━━━┓
┃(04)判断二叉树T是否为空。 ┃
┗━━━━━━━━━━━━━*/

void Create_Tri(TBiTree *T, FILE *fp);
/*━━━━━━━━━━━━┓
┃(05)二叉树构造函数调用。┃
┗━━━━━━━━━━━━*/

Status CreateBiTree_Tri(FILE *fp, TBiTree *T);
/*━━━━━━━━━━━━━┓
┃(06)按先序序列构造二叉树。┃
┗━━━━━━━━━━━━━*/

int BiTreeLength_Tri(TBiTree T);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(07)返回二叉树长度（按完全二叉树计算）。┃
┗━━━━━━━━━━━━━━━━━━━━*/

int BiTreeDepth_Tri(TBiTree T);
/*━━━━━━━━━━━━━━┓
┃(08)返回二叉树深度（层数）。┃
┗━━━━━━━━━━━━━━*/

Status Root_Tri(TBiTree T, TElemType_Tri *e);
/*━━━━━━━━━━━━━━━┓
┃(09)用e返回二叉树的根结点值。 ┃
┗━━━━━━━━━━━━━━━*/

TElemType_Tri Value_Tri(TBiTree p);
/*━━━━━━━━━━━━━━━━━┓
┃(10)返回某结点的值，p为结点指针。 ┃
┗━━━━━━━━━━━━━━━━━*/

void Assign_Tri(TBiTree p, TElemType_Tri value);
/*━━━━━━━━━━━━━━━━┓
┃(11)为某结点赋值，p为结点指针。 ┃
┗━━━━━━━━━━━━━━━━*/            

TBiTree Point(TBiTree T, TElemType_Tri e);
/*━━━━━━━━━━━━━┓
┃(12)返回指向某结点的指针。┃
┗━━━━━━━━━━━━━*/

TElemType_Tri Parent_Tri(TBiTree T, TElemType_Tri e);
/*━━━━━━━━━━━━━━┓
┃(13)返回某结点的双亲结点值。┃
┗━━━━━━━━━━━━━━*/

TElemType_Tri LeftChild_Tri(TBiTree T, TElemType_Tri e);
/*━━━━━━━━━━━━━━━┓
┃(14)返回某结点的左孩子结点值。┃
┗━━━━━━━━━━━━━━━*/

TElemType_Tri RightChild_Tri(TBiTree T, TElemType_Tri e);
/*━━━━━━━━━━━━━━━┓
┃(15)返回某结点的右孩子结点值。┃
┗━━━━━━━━━━━━━━━*/

TElemType_Tri LeftSibling_Tri(TBiTree T, TElemType_Tri e);
/*━━━━━━━━━━━━━━━┓
┃(16)返回某结点的左兄弟结点值。┃
┗━━━━━━━━━━━━━━━*/

TElemType_Tri RightSibling_Tri(TBiTree T, TElemType_Tri e);
/*━━━━━━━━━━━━━━━┓
┃(17)返回某结点的右兄弟结点值。┃
┗━━━━━━━━━━━━━━━*/

Status InsertBiTree_Tri(TBiTree T, TElemType_Tri e, TBiTree *T0, int LR);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(18)将树T0插入到树T中成为结点e的子树，LR为插入标记。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status DeleteBiTree_Tri(TBiTree T, TElemType_Tri e, int LR);
/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃(19)删除e结点的左子树或右子树，LR为删除标记。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/

void LevelOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));
/*━━━━━━━━━━┓
┃(20)层序遍历二叉树。┃
┗━━━━━━━━━━*/

void PreOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));
/*━━━━━━━━━━┓
┃(21)前序遍历二叉树。┃
┗━━━━━━━━━━*/

void InOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));
/*━━━━━━━━━━┓
┃(22)中序遍历二叉树。┃
┗━━━━━━━━━━*/

void PostOrderTraverse_Tri(TBiTree T, void(Visit)(TElemType_Tri));
/*━━━━━━━━━━┓
┃(23)后序遍历二叉树。┃
┗━━━━━━━━━━*/

void Print_Tri(TBiTree T);
/*━━━━━━━━━━━━━┓
┃(24)按二叉树的结构打印树。┃
┗━━━━━━━━━━━━━*/

#endif
