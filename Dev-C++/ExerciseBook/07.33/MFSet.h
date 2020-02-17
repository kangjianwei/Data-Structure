/*=====
 * 集合
 ======*/

#ifndef MFSET_H
#define MFSET_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、free 原型
#include <string.h>     // 提供 memset、strcmp 原型
#include <math.h>       //
#include "Status.h"     //**▲01 绪论**//

/* 树的最大结点数，这里指示子集最大数量 */
#define MAX_TREE_SIZE 1024

/* 二元关系对数量 */
#define MAX_PAIR_SIZE 100

/*
 * (双亲)树的结点定义
 *
 *【注】
 * 1.依照教材的图示，双亲树在集合的应用中，其模型已被简化：即双亲结点不再保留数据域。
 * 2.结点的索引用来表示它是哪一个子集，它会作为更大子集的一个元素存在。
 * 3.确定某个子集属于S中哪个更大的子集时，需要向上追溯到更大子集的根。
 * 4.实际使用中，每个子集会包含很多数据元素，此时可以将每个数据元素与其所属的子集建立关联关系
 *   即把每个数据元素与集合S中各结点的索引关联起来
 */
typedef struct PTNode {
    int parent;         // 双亲位置域，用来指示该结点所属的子集
} PTNode;

/*
 * (双亲)树类型定义
 *
 *【注】
 * 1.树中结点在nodes中"紧邻"存储，没有空隙
 * 2.当子集存在时，树根r设置为1，否则，树根r设置为0
 * 3.除根结点外，其他结点依次按层序顺着根结点往下排列
 * 5.这里假设nodes空间是足够大的，可以视需求将其改为动态分配存储
 */
typedef struct {
    PTNode nodes[MAX_TREE_SIZE];    // 存储树中结点
    int r;  // 树根位置(索引)，这里用来指示第一个子集的位置
    int n;  // 树的结点数，这里用来指示所有
} PTree;

/* 集合类型定义 */
typedef PTree MFSet;

/* 单个二元关系对 */
typedef struct {
    int i;
    int j;
} Pair;

/* 集合内的等价关系 */
typedef struct {
    Pair pairs[MAX_PAIR_SIZE];  // 足够大的空间存储二元关系
    int n;                      // 已知的等价关系数量
} Relation;


/*
 * 初始化一个由多个子集（每个子集只包含单个成员）构成的集合S。
 *
 *
 *【备注】
 *
 * 这里对第6章的MFSet做了改动：
 * 1.直接在参数中传入子集数量
 * 2.子集编号从0开始计数，这会影响到后面的函数中关于下标的判断
 */
Status initial_mfset(MFSet* S, int n);

/*
 * 求两个互不相交的子集Si和子集Sj的并集。
 */
Status merge_mfset(MFSet* S, int i, int j);

/*
 * 在集合S中查找元素i当前所属的子集。
 */
int find_mfset(MFSet S, int i);

/*
 * 根据等价关系R来整理/建立集合S中的元素(子集)。
 */
Status build_mfset(MFSet* S, Relation R);

#endif
