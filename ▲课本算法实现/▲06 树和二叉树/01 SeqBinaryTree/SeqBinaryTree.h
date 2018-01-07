/********************************************
 *										    *
 * 文件夹: ▲06 树和二叉树\01 SeqBinaryTree *
 * 									        *
 * 文件名: SeqBinaryTree.h                  *
 * 										    *
 * 内  容: 二叉树顺序存储结构相关操作列表   *
 *                                          *
 ********************************************/

#ifndef SEQBINARYTREE_H
#define SEQBINARYTREE_H

#include <stdio.h>
#include <math.h>								//提供pow原型 
#include "../../▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"				//**▲01 绪论**//

/* 宏定义 */
#define MAX_TREE_SIZE 100						//二叉树的最大结点数

/* 二叉树（顺序存储结构）相关类型定义 */
typedef char TElemType_Sq;						//假设顺序二叉树元素均为字符 
typedef TElemType_Sq SqBiTree[MAX_TREE_SIZE];	//0号单元存储根结点	

/* 结点“坐标”类型 */
typedef struct 
{
	int level;			//结点所在层 
	int order;			//结点在本层序号（按完全二叉树计算） 
}Position;

/* 二叉树顺序存储结构函数列表 */
void InitBiTree_Sq(SqBiTree T);
/*━━━━━━━━━━┓
┃(01)构造空二叉树T。 ┃
┗━━━━━━━━━━*/

void ClearBiTree_Sq(SqBiTree T);
/*━━━━━━━━━┓
┃(02)清空二叉树T。 ┃
┗━━━━━━━━━*/

void DestroyBiTree_Sq(SqBiTree T);
/*━━━━━━━━━┓
┃(03)销毁二叉树T。 ┃
┗━━━━━━━━━*/

Status BiTreeEmpty_Sq(SqBiTree T);
/*━━━━━━━━━━━━━┓
┃(04)判断二叉树T是否为空。 ┃
┗━━━━━━━━━━━━━*/

Status CreateBiTree_Le_Sq(FILE *fp, SqBiTree T);
/*━━━━━━━━━━━━━┓
┃(05)按层序序列构造二叉树。┃
┗━━━━━━━━━━━━━*/

Status CreateBiTree_Pre_Sq(FILE *fp, SqBiTree T, int i);
/*━━━━━━━━━━━━━┓
┃(06)按先序序列构造二叉树。┃
┗━━━━━━━━━━━━━*/

int BiTreeLength_Sq(SqBiTree T);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(07)返回二叉树长度（按完全二叉树计算）。┃
┗━━━━━━━━━━━━━━━━━━━━*/

int BiTreeDepth_Sq(SqBiTree T);
/*━━━━━━━━━━━━━━┓
┃(08)返回二叉树深度（层数）。┃
┗━━━━━━━━━━━━━━*/

Status Root_Sq(SqBiTree T, TElemType_Sq *e);
/*━━━━━━━━━━━━┓
┃(09)用e返回二叉树的根。 ┃
┗━━━━━━━━━━━━*/

TElemType_Sq Value_Sq(SqBiTree T, Position s);
/*━━━━━━━━━━━━━━┓
┃(10)返回树中某位置的结点值。┃
┗━━━━━━━━━━━━━━*/

Status Assign_Sq(SqBiTree T, Position s, TElemType_Sq value);
/*━━━━━━━━━━━━━━┓
┃(11)为树中某位置的结点赋值。┃
┗━━━━━━━━━━━━━━*/

TElemType_Sq Parent_Sq(SqBiTree T, TElemType_Sq e);
/*━━━━━━━━━━━━━━┓
┃(12)返回某结点的双亲结点值。┃
┗━━━━━━━━━━━━━━*/

TElemType_Sq LeftChild_Sq(SqBiTree T, TElemType_Sq e);
/*━━━━━━━━━━━━━━━┓
┃(13)返回某结点的左孩子结点值。┃
┗━━━━━━━━━━━━━━━*/

TElemType_Sq RightChild_Sq(SqBiTree T, TElemType_Sq e);
/*━━━━━━━━━━━━━━━┓
┃(14)返回某结点的右孩子结点值。┃
┗━━━━━━━━━━━━━━━*/

TElemType_Sq LeftSibling_Sq(SqBiTree T, TElemType_Sq e);
/*━━━━━━━━━━━━━━━┓
┃(15)返回某结点的左兄弟结点值。┃
┗━━━━━━━━━━━━━━━*/

TElemType_Sq RightSibling_Sq(SqBiTree T, TElemType_Sq e);
/*━━━━━━━━━━━━━━━┓
┃(16)返回某结点的右兄弟结点值。┃
┗━━━━━━━━━━━━━━━*/

void LevelOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq));
/*━━━━━━━━━━┓
┃(17)层序遍历二叉树。┃
┗━━━━━━━━━━*/

void PreOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq), int i);
/*━━━━━━━━━━┓
┃(18)前序遍历二叉树。┃
┗━━━━━━━━━━*/

void InOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq), int i);
/*━━━━━━━━━━┓
┃(19)中序遍历二叉树。┃
┗━━━━━━━━━━*/

void PostOrderTraverse_Sq(SqBiTree T, void(Visit)(TElemType_Sq), int i);
/*━━━━━━━━━━┓
┃(20)后序遍历二叉树。┃
┗━━━━━━━━━━*/

void Print_Sq(SqBiTree T);
/*━━━━━━━━━━━━━┓
┃(21)按二叉树的结构打印树。┃
┗━━━━━━━━━━━━━*/

#endif
