/*==============================
 * 集合
 *
 * 包含算法: 6.8、6.9、6.10、6.11
 ===============================*/

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
    int r;  // 树根位置(索引)，这里用来指示第一个子集的
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
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 *
 * 如果需要从控制台读取数据，则path为NULL或者为空串，
 * 如果需要从文件中读取数据，则需要在path中填写文件名信息。
 */
Status initial_mfset(MFSet* S, char* path);

/*
 * 初始化集合的二元等价关系
 */
Status initial_relation(Relation* R, char* path);

/*
 * ████████ 算法6.9 ████████
 *
 * 求两个互不相交的子集Si和子集Sj的并集。
 */
Status merge_mfset(MFSet* S, int i, int j);

/*
 * ████████ 算法6.8 ████████
 *
 * 在集合S中查找元素i当前所属的子集。
 */
int find_mfset(MFSet S, int i);

/*
 * ████████ 算法6.10 ████████
 *
 * 求两个互不相交的子集Si和子集Sj的并集。
 *
 * 该算法是【算法6.9】的改进，改进之处在于：
 * 1.子集根结点的绝对值为该子集元素的数量
 * 2.坚持将规模小的集合合并到规模大的集合上
 */
Status mix_mfset(MFSet* S, int i, int j);

/*
 * ████████ 算法6.11 ████████
 *
 * 在集合S中查找元素i当前所属的子集。
 *
 * 该算法是【算法6.8】的改进，改进之处在于：
 * 查找完成后，会对树的高度进行摊平，即尽量让元素直接挂载到子集根结点上。
 *
 *【注】
 * 该操作会对集合造成改动
 */
int fix_mfset(MFSet* S, int i);

/*
 * 根据等价关系R来整理/建立集合S中的元素(子集)。
 *
 *【注】
 * 该方法与bix_relation方法目的一致，
 * 但该方法调用的是【算法6.8】和【算法6.9】，
 * 是未优化的版本。
 */
Status build_mfset(MFSet* S, Relation R);

/*
 * 根据等价关系R来整理/建立集合S中的元素(子集)。
 *
 *【注】
 * 该方法与build_relation方法目的一致，
 * 但该方法调用的是【算法6.10】和【算法6.11】，
 * 是优化后的版本。
 */
Status bix_mfset(MFSet* S, Relation R);


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建集合的内部函数
static void mfset(MFSet* S, FILE* fp);

// 创建集合的二元关系内部函数
static void relation(Relation* R, FILE* fp);


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 以图形化形式输出当前集合
void PrintSet(MFSet S);

// 图形化输出树的排列结构，仅限内部测试使用
static void PrintFramework(MFSet S);

#endif
