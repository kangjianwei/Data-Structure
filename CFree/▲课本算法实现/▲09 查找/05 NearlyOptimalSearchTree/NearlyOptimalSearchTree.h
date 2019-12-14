/*************************************
 *                                   *
 * 文件夹: ▲09 查找                 *
 *                                   *
 * 文件名: NearlyOptimalSearchTree.h *
 *                                   *
 * 内  容: 次优查找树相关操作列表    *
 *                                   *
 *************************************/

#ifndef NEARLYOPTIMALSEARCHTREE_H
#define NEARLYOPTIMALSEARCHTREE_H

#include <stdlib.h>
#include <math.h>
#include "../00 Base/Base.c" 				//**▲09 查找**//
#include "../../▲06 树和二叉树/02 BinaryTree/BinaryTree.c"//**▲06 树和二叉树**//

/* 类型定义 */
typedef BiTree SOSTree;

/*全局变量*/
char ch[] = "\0ABCDEFGHI";
 
/* 静态树表查找函数列表 */
void FindSW(float sw[], Table T); 
/*━━━━━━━━━━┓
┃(01)建立累计权值表。┃
┗━━━━━━━━━━*/

int MinSW(float sw[], int low, int high);
/*━━━━━━━━━━━━━━━━━━┓
┃(02)找出左右累计权值差最小的分界点。┃
┗━━━━━━━━━━━━━━━━━━*/

void SecondOptimal(BiTree *BT, ElemType_Search R[], float sw[], int low, int high);
/*━━━━━━━━━━━━━━━━━┓
┃(03)算法9.3：次优查找树构造函数。 ┃
┗━━━━━━━━━━━━━━━━━*/

Status CreateSOSTree(SOSTree *BT, Table T);
/*━━━━━━━━━━━━━━━━━━━┓
┃(04)算法9.4：用有序表T构造次优查找树。┃
┗━━━━━━━━━━━━━━━━━━━*/

Status Search_SOST(SOSTree BT, KeyType key);
/*━━━━━━━━━━━━━━━━━━━┓
┃(5)判断关键字key是否在次优查找树BT中。┃
┗━━━━━━━━━━━━━━━━━━━*/

#endif 
