/*====================
 * 赫夫曼树
 *
 * 包含算法: 6.12、6.13
 ====================*/

#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <string.h>     // 提供strcpy原型
#include <limits.h>     // 提供一些极限值的宏定义
#include "Status.h"     //**▲01 绪论**//

/*
 * ████ 提示 ████
 *
 * 赫夫曼树又译作哈夫曼树
 */


/* 赫夫曼树结点定义，是一种双亲存储结构 */
typedef struct {
    unsigned int weight;    // 权值
    unsigned int parent;    // 双亲位置
    unsigned int lchild;    // 左孩子位置
    unsigned int rchild;    // 右孩子位置
} HTNode;

/*
 * 赫夫曼树类型定义
 *
 *【注】
 * 1.0号单元的weight域指示赫夫曼树的结点数量
 * 2.其存储空间会动态分配
 */
typedef HTNode* HuffmanTree;

/*
 * 赫夫曼编码表的类型定义，包含了多个字符的赫夫曼编码
 *
 *【注】
 * 1.0号单元是弃用的
 * 2.存储空间需要动态分配
 */
typedef char** HuffmanCode;


/*
 * 初始化环境
 *
 * 主要用来初始化权值信息。
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
Status InitEnvironment(int** w, int* n, char* path);

/*
 * ████████ 算法6.12 ████████
 *
 * 编码
 * 1.根据指定的n个权值信息w来创建赫夫曼树HT。
 * 2.由赫夫曼树HT逆序计算赫夫曼编码值HC。
 *
 *【注】
 * 该算法与【算法6.13】作用一致。
 */
Status HuffmanCodeing_1(HuffmanTree* HT, HuffmanCode* HC, int* w, int n);

/*
 * ████████ 算法6.13 ████████
 *
 * 编码
 * 1.根据指定的n个权值信息w来创建赫夫曼树HT。
 * 2.先序遍历赫夫曼树HT计算赫夫曼编码值HC。
 *
 *【注】
 * 该算法与【算法6.12】作用一致。
 */
Status HuffmanCodeing_2(HuffmanTree* HT, HuffmanCode* HC, int* w, int n);

/*
 * 解码
 * 根据给定的n个赫夫曼编码HC，计算其代表的权值。
 */
Status HuffmanDecoding(HuffmanTree HT, HuffmanCode HC, int** w, int n);


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 初始化环境的内部实现
static Status Init(int** w, int* n, FILE* fp);

// 在赫夫曼树结点[1...end]中依次选出权值最小且未编入树的两个结点的序号s1、s2。
static void Select(HuffmanTree HT, int end, int* s1, int* s2);


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

// 打印赫夫曼树结构。
void PrintHuffmanTree(HuffmanTree HT);

// 打印赫夫曼编码。
void PrintHuffmanCode(HuffmanTree HT, HuffmanCode HC);

// 打印赫夫曼编码对应的权值信息。
void PrintWeight(HuffmanCode HC, int *w, int n);

#endif
