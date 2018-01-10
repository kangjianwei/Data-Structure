/**************************************
 *                                    *
 * 文件夹: ▲09 查找                  *
 *                                    *
 * 文件名: BalancedBinarySortTree.h   *
 *                                    *
 * 内  容: 平衡二叉排序树相关操作列表 *
 *                                    *
 **************************************/

#ifndef BALANCEDBINARYSORTTREE_H
#define BALANCEDBINARYSORTTREE_H

#include <stdlib.h>
#include <math.h>
#include "../00 Base/Base.c" 			//**▲09 查找**//

/* 宏定义 */
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a) < (b))
#define RT(a,b) ((a) > (b))
#define LH  1							//左子树高 
#define EH  0							//等高 
#define RH -1							//右子树高 

/* 类型定义 */
typedef int Boolean;					//布尔值 
typedef ElemType_Search BBSTElemType;	//平衡二叉排序树元素类型 
typedef struct BBSTNode					//平衡二叉树（AVL树）存储表示
{
	BBSTElemType data;
	int bf;								//结点的平衡因子 
	struct BBSTNode* lchild;
	struct BBSTNode* rchild;
	
	union								//只在习题测试时候使用 
	{
		int lsize;						//其值为左子树中结点数加1 
	};//匿名联合体 
}BBSTNode;								//平衡二叉排序树结点 
typedef BBSTNode* BBSTree;				//指向平衡二叉排序树结点的指针
 
/* 平衡二叉树（AVL树）函数列表 */
Status CreateAVL(BBSTree *BBST, Table T);
/*━━━━━━━━┓
┃(01)创建AVL树。 ┃
┗━━━━━━━━*/

BBSTree SearchAVL(BBSTree BBST, KeyType key);
/*━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)查找，返回指向key的指针，若不存在返回MULL。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━*/

Status InsertAVL(BBSTree *BBST, ElemType_Search e, Boolean *taller);
/*━━━━━━━━━━┓
┃(03)算法9.11：插入。┃
┗━━━━━━━━━━*/

Status DeleteAVL(BBSTree *BBST, ElemType_Search e, BBSTree f, BBSTree p, Boolean *taller, int mark);
/*━━━━━┓
┃(04)删除。┃
┗━━━━━*/

void RightBalance(BBSTree *BBST);
/*━━━━━━━━┓
┃(05)右平衡处理。┃
┗━━━━━━━━*/

void LeftBalance(BBSTree *BBST);
/*━━━━━━━━━━━━━┓
┃(06)算法9.12：左平衡处理。┃
┗━━━━━━━━━━━━━*/

void R_Rotate(BBSTree *p);
/*━━━━━━━━━━┓
┃(07)算法9.9：右旋。 ┃
┗━━━━━━━━━━*/

void L_Rotate(BBSTree *p);
/*━━━━━━━━━━┓
┃(08)算法9.10：左旋。┃
┗━━━━━━━━━━*/

void InOrderTraverse_AVL(BBSTree BBST, void(Visit)(ElemType_Search));
/*━━━━━━━┓
┃(09)中序遍历。┃
┗━━━━━━━*/

int AVLDepth(BBSTree BBST);
/*━━━━━━━━┓
┃(10)求树的深度。┃
┗━━━━━━━━*/

void PrintAVLTree(BBSTree BBST);
/*━━━━━━┓
┃(11)打印树。┃
┗━━━━━━*/

#endif 
