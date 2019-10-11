/************************************
 *                                  *
 * 文件夹: ▲11 外部排序            *
 *                                  *
 * 文件名: ReSeSort.h               *
 *                                  *
 * 内  容: 置换选择排序相关操作列表 *
 *                                  *
 ************************************/

#ifndef RESESORT_H
#define RESESORT_H

#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>
#include "../../▲01 绪论/Status.h"			//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"			//**▲01 绪论**//

#define RUNEND_SYMBOL INT_MAX				//初始归并段结束标志
#define MAXKEY INT_MAX						//关键字可能的最大值 
#define W 6									//工作区缓存

/* 类型定义 */
typedef int KeyType;						//定义关键字类型为整数类型
typedef struct
{
	KeyType key;							//关键字项 
}RcdType;									//记录类型
typedef int LoserTree[W];					//败者树 
typedef struct								//败者树叶节点存储结构  
{
	RcdType rec;							//记录 
	KeyType key;							//从记录中抽取的关键字 
	int rnum;								//所属归并段的段号 
}RcdNode;
typedef RcdNode WorkArea[W];				//内存工作区，容量为W 

/* 全局变量 */
int part;									//统计初始归并段个数 
int rmax;									//rmax指示wa中关键字所属初始归并段的最大段号
int rc;										//rc指示当前生成的初始归并段的段号
 
/* 置换选择排序函数列表 */
void Replace_Selectiom(FILE *fi, LoserTree ls, WorkArea wa);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法11.4：在败者树ls和内存工作区wa上用置换-选择排序求初始归并段,fi为指向文件(只读)，fo指向输出文件(只写)。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void get_run(FILE *fi, FILE *fo, LoserTree ls, WorkArea wa);
/*━━━━━━━━━━━━━━━━━┓
┃(02)算法11.5：求得一个初始归并段。┃
┗━━━━━━━━━━━━━━━━━*/

void Select_MiniMax(LoserTree ls, WorkArea wa, int q);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(03)算法11.6：从wa[q]起到败者树的根比较选择minimax记录,并由q指示它所在的归并段。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void Construct_Loser(FILE *fi, LoserTree ls, WorkArea wa);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(04)算法11.7：输入w个记录到内存工作区wa，建得败者树ls，选出关键字最小的记录并由s指示其在wa中的位置。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

#endif 
