/****************************************
 *                                      *
 * 文件夹: ▲06 树和二叉树\08 MFSet     *
 *                                      *
 * 文件名: MFSet.h                      *
 *                                      *
 * 内  容: 并查集（等价类）相关操作列表 *
 *                                      *
 ****************************************/

#ifndef MFSET_H
#define MFSET_H

#include <stdio.h>
#include "../../▲01 绪论/Status.h"				//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"				//**▲01 绪论**//

/* 并查集（等价类）的树的双亲表类型定义 */
typedef int TElemType_P;						//假设集合中元素均为整数 
#include "../05 ParentTree/ParentTree.c" 		//**06 树和二叉树**//
typedef PTree MFSet;

/* 二元关系 */
typedef struct
{
	int i;
	int j;
}Node;

/* 等价关系 */
typedef struct
{
	Node nodes[MAX_TREE_SIZE];					//足够大的集合空间 
	int n; 
}Relation; 

/* 并查集（等价类）函数列表 */ 
void Initial_mfset(FILE *fp, MFSet *S);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)构造一个由n个子集（每个子集只包含单个成员）构成的集合S。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/ 

int find_mfset(MFSet S, int i);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(02)算法6.8：查找集合S中i所在子集的根。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

Status merge_mfset(MFSet *S, int i, int j);
/*━━━━━━━━━━━━━━━━━━━━━━┓
┃(03)算法6.9：求Si和Sj的并集，Si和Sj无交集。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━*/

Status mix_mfset(MFSet *S, int i, int j);
/*━━━━━━━━━━━━━━━━━━━━━┓
┃(04)算法6.10：集合归并函数，算法6.9改进。 ┃
┗━━━━━━━━━━━━━━━━━━━━━*/

int fix_mfset(MFSet *S, int i);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(05)算法6.11：查找集合S中i所在子集的根, 算法6.8改进。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status BuildRelation_mfset(FILE *fp, Relation *R);
/*━━━━━━━━━━━┓
┃(06)建立二元等价关系。┃
┗━━━━━━━━━━━*/

int EquivalenceClass_mfset_1(MFSet *S, Relation R); 
/*━━━━━━━━━━━━━━━━━━┓
┃(07-1)求在等价关系R下集合S的等价类。┃
┗━━━━━━━━━━━━━━━━━━*/

int EquivalenceClass_mfset_2(MFSet *S, Relation R); 
/*━━━━━━━━━━━━━━━━━━┓
┃(07-2)求在等价关系R下集合S的等价类。┃
┗━━━━━━━━━━━━━━━━━━*/

int SubsetCount_mfset(MFSet S);
/*━━━━━━━━━━━━━━━┓
┃(08)返回集合S中非空子集数目。 ┃
┗━━━━━━━━━━━━━━━*/

void ShowSet_mfset(MFSet S);
/*━━━━━━━━┓
┃(09)展示集合S。 ┃
┗━━━━━━━━*/

#endif
