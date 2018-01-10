/****************************
 *                          *
 * 文件夹: ▲09 查找        *
 *                          *
 * 文件名: B+Tree.h         *
 *                          *
 * 内  容: B+树相关操作列表 *
 *                          *
 ****************************/

#ifndef B__TREE_H
#define B__TREE_H

#include <stdlib.h>
#include <math.h>							//提供ceil原型
#include "../00 Base/Base.c" 				//**▲09 查找**//

/* 宏定义 */
#define M 3									//B+树的阶，暂设为3 
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a) < (b))

/* 类型定义 */
typedef ElemType_Search B_TElemType;		//B+树元素类型 
typedef struct B_TNode						//B+树存储表示
{
	int keynum;								//结点中关键字个数 
	struct B_TNode* parent;					//指向双亲结点 
											//（与B树区别）  
	KeyType key[M+1];						//关键字向量，占用0号单元 
	struct B_TNode* ptr[M+1];				//子树指针向量，占用0号单元
	
	int leaf;								//leaf=0,非叶结点，leaf=1，叶结点 
	union
	{
		struct B_TNode* next;
	}lf;
}B_TNode;									//B+树结点 
typedef struct
{
	B_TNode* data;							//叶子结点头指针
	B_TNode* root;							//指向B+树根结点
}B_Tree;									//B+树

/* B+树查找结果类型 */ 
typedef struct
{
	B_TNode* pt;							//指向找到的结点 
	int i;									//1...n，关键字在结点中的序号（插入位置） 
	int tag;								//1:查找成功，0:查找失败 
}Result; 

/* B+树函数列表 */
Status CreateB_Tree(B_Tree *B_T, Table T);
/*━━━━━━━┓
┃(01)创建B+树。┃
┗━━━━━━━*/

Result SearchB_Tree(B_Tree B_T, KeyType K);
/*━━━━━━━━━━━━┓
┃(02)查找，返回查找信息。┃
┗━━━━━━━━━━━━*/

int Search(B_TNode *p, KeyType K);
/*━━━━━━━━━━━━━┓
┃(03)返回K在结点p中的次序。┃
┗━━━━━━━━━━━━━*/

Status InsertKey(B_Tree *B_T, KeyType K);
/*━━━━━━━━━━━━┓
┃(04)将关键字K插入B+树。 ┃
┗━━━━━━━━━━━━*/

Status InsertB_Tree(B_Tree *B_T, KeyType K, B_TNode *q, int i);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(05)插入，将K插入为结点*q的第i个关键字。┃
┗━━━━━━━━━━━━━━━━━━━━*/

void Insert(B_TNode *q, int i, KeyType x, B_TNode *ap);
/*━━━━━━━━━━━━━━━━━━━━━━┓
┃(06)将x和ap分别插入到q->key[i]和q->ptr[i]。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━*/

void split(B_TNode *q, int s, B_TNode **ap);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(07)以s为界，将q指向的结点分裂成q和ap指向的两部分。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void NewRoot(B_Tree *B_T, B_TNode *q, int x, B_TNode *ap);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(08)生成含信息(BT,x,ap)的新的根结点*BT，原BT和ap为子树指针，q初值为NULL。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void PrintB_Tree(B_Tree B_T);
/*━━━━━━━━━━┓
┃(09)输出B+树关键字。┃
┗━━━━━━━━━━*/

#endif 
