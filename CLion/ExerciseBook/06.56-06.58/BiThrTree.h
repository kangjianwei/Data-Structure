/*=======================
 * 线索二叉树
 *
 * 包含算法: 6.5、6.6、6.7
 ========================*/

#ifndef BITHRTREE_H
#define BITHRTREE_H

#include <stdio.h>
#include <stdlib.h>     // 提供 malloc、free 原型
#include <string.h>     // 提供 memset、strcmp 原型
#include <math.h>       // 提供 pow 原型
#include "Status.h"     //**▲01 绪论**//

/* 线索二叉树结点类型标记 */
typedef enum {
    Link, Thread    // Link==0：指针(孩子)；Thread==1：线索
} PointerTag;

/* 线索二叉树元素类型定义，这里假设其元素类型为char */
typedef char TElemType;

/* 线索二叉树结点定义 */
typedef struct BiThrNode {
    TElemType data;             // 结点元素
    struct BiThrNode* lchild;   // 左孩子指针
    struct BiThrNode* rchild;   // 右孩子指针
    PointerTag LTag;            // 左指针标记
    PointerTag RTag;            // 右指针标记
    
    struct BiThrNode* parent;   // 双亲结点指针，仅在非递归后序遍历后序后继线索二叉树时使用
} BiThrNode;

/* 指向线索二叉树结点的指针 */
typedef BiThrNode* BiThrTree;


/* 全局变量 */
static BiThrTree pre;   // 指向当前访问结点的上一个结点（前驱）


/*
 * 创建
 *
 * 按照预设的定义来创建二叉树。
 * 这里约定使用【先序序列】来创建二叉树。
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
Status CreateBiTree(BiThrTree* T, char* path);

/*
 * ████████ 算法6.6 ████████
 *
 * 中序遍历二叉树T，并将其全线索化为线索二叉树Thrt。
 * 注：这里的线索包括前驱线索与后继线索。
 */
Status InOrderThreading(BiThrTree* Thrt, BiThrTree T);

/*
 * ████████ 算法6.5 ████████
 *
 * 中序遍历中序全线索二叉树T（非递归算法）。
 *
 * 注：该方法可以验证后继线索是否正确
 */
Status InOrderTraverse_Thr(BiThrTree T, Status(Visit)(TElemType));


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

// 创建二叉树的内部函数
static void CreateTree(BiThrTree* T, FILE* fp);

/*
 * ████████ 算法6.7 ████████
 *
 * 中序全线索化的内部实现
 */
static void InTheading(BiThrTree p);


/*━━━━━━━━━━━━━━━━━━━━━━ 辅助函数 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 逆中序遍历中序全线索二叉树（非递归算法）。
 *
 * 注：该方法可以验证前驱线索是否正确
 */
Status InOrderTraverse_Thr_Inverse(BiThrTree T, Status(Visit)(TElemType));

#endif
