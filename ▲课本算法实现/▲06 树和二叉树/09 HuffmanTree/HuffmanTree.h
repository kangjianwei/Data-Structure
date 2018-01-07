/******************************************
 *								          *
 * 文件夹: ▲06 树和二叉树\09 HuffmanTree *
 * 								          *
 * 文件名: HuffmanTree.h                  *
 * 								          *
 * 内  容: 哈夫曼树相关操作列表           *
 *                                        *
 ******************************************/

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <stdio.h>
#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include <string.h>						//提供strcpy原型 
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"		//**▲01 绪论**//

/* 宏定义 */
#define MAX_TREE_SIZE 100			//树的最大结点数

/* 哈夫曼树和哈夫曼编码类型定义 */
typedef struct
{
	unsigned int weight;			//权值 
	unsigned int parent;						
	unsigned int lchild;
	unsigned int rchild;
}HTNode;
typedef HTNode* HuffmanTree;		//动态分配数组存储哈夫曼树 
typedef char* HCNode;
typedef HCNode* HuffmanCode;		//动态分配数组存储哈夫曼编码表 

/* 哈夫曼树函数列表 */
void InitTree_HT(HuffmanTree *HT);
/*━━━━━━━━━━━━━┓
┃(01)构造空树HT(初始化树)。┃
┗━━━━━━━━━━━━━*/

Status CreateHuffmanTree_HT(FILE *fp, HuffmanTree *HT);
/*━━━━━━━━━┓
┃(02)建立哈夫曼树。┃
┗━━━━━━━━━*/

Status Select_HT(HuffmanTree HT, int end, int *order_1, int *order_2);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(03)在哈夫曼树结点[1...end]中依次选出权值最小且未编入树的两个结点的序号order_1、order_2。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status HuffmanCodeing_HT_1(HuffmanTree HT, HuffmanCode *HC); 
/*━━━━━━━━━━━━━━━━━━━┓
┃(04-1)算法6.12：逆序计算哈夫曼编码值。┃
┗━━━━━━━━━━━━━━━━━━━*/

Status HuffmanCodeing_HT_2(HuffmanTree HT, HuffmanCode *HC);
/*━━━━━━━━━━━━━━━━━━━━━┓
┃(04-2)算法6.13：先序遍历计算哈夫曼编码值。┃
┗━━━━━━━━━━━━━━━━━━━━━*/

void ShowHuffmanTree_HT(HuffmanTree HT);
/*━━━━━━━━━┓
┃(05)展示哈夫曼树。┃
┗━━━━━━━━━*/

void ShowHuffmanCode_HT(HuffmanTree HT, HuffmanCode HC);
/*━━━━━━━━━━┓
┃(06)打印哈夫曼编码。┃
┗━━━━━━━━━━*/

#endif
