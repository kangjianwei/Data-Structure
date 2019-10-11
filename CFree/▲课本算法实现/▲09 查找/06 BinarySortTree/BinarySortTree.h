/**********************************
 *                                *
 * 文件夹: ▲09 查找              *
 *                                *
 * 文件名: BinarySortTree.h       *
 *                                *
 * 内  容: 二叉排序树相关操作列表 *
 *                                *
 **********************************/

#ifndef BINARYSORTTREE_H
#define BINARYSORTTREE_H

#include <stdlib.h>
#include "../00 Base/Base.c" 				//**▲09 查找**//

/* 宏函数 */
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a) < (b))

/* 类型定义 */
typedef ElemType_Search BSTElemType;		//二叉排序树元素类型 
typedef struct BSTNode						//二叉排序树存储表示
{
	BSTElemType data;
	struct BSTNode* lchild;
	struct BSTNode* rchild;
	
	union									//匿名联合体，仅在第9章习题测试时使用 
	{
		int RTag;							//线索标志 
	};
}BSTNode;									//二叉排序树结点 
typedef BSTNode* BSTree;					//指向二叉排序树结点的指针
 
/* 二叉排序树函数列表 */
Status CreateBSTree(BSTree *BST, Table T);
/*━━━━━━━━━━┓
┃(01)创建二叉排序树。┃
┗━━━━━━━━━━*/

BSTree SearchBST_1(BSTree BST, KeyType key);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法9.5(a)：查找，返回指向key的指针，若不存在返回MULL。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status SearchBST_2(BSTree BST, KeyType key, BSTree f, BSTree *p);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(03)算法9.5(b)：查找，若不存在key，则插入到正确的位置。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status InsertBST(BSTree *BST, BSTElemType e);
/*━━━━━━━━━━━━━━━━┓
┃(04)算法9.6：插入e到二叉排序树。┃
┗━━━━━━━━━━━━━━━━*/

void InOrderTraverse_BST(BSTree BST, void(Visit)(ElemType_Search));
/*━━━━━━━━━━━━━━━━━━━━┓
┃(05)中序遍历二叉排序树，生成关键字序列。┃
┗━━━━━━━━━━━━━━━━━━━━*/

Status DeleteBST(BSTree *BST, KeyType key);
/*━━━━━━━━━━┓
┃(06)算法9.7：删除。 ┃
┗━━━━━━━━━━*/
 
Status Delete(BSTree *p);
/*━━━━━━━━━━━━━━━┓
┃(07)算法9.8：删除p指向的结点。┃
┗━━━━━━━━━━━━━━━*/

#endif 
