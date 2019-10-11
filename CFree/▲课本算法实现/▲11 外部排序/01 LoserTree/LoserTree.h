/******************************
 *                            *
 * 文件夹: ▲11 外部排序      *
 *                            *
 * 文件名: LoserTree.h        *
 *                            *
 * 内  容: 败者树相关操作列表 *
 *                            *
 ******************************/

#ifndef LOSERTREE_H
#define LOSERTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"		//**▲01 绪论**//

/* 宏定义 */
#ifndef MAXSIZE
#define MAXSIZE 2000					//一个用作示例的顺序表的最大长度
#endif
#include "../../▲10 内部排序/10 MergingSort/MergingSort.c"//**▲10 内部排序**//

#define MAX 2500						//随机数表关键字个数 
#define K 5								//K-路归并							
#define MAXKEY INT_MAX					//关键字可能的最大值
#define MINKEY INT_MIN					//关键字可能的最小值

/* k-路归并败者树类型定义 */
typedef int LoserTree[K];				//败者树是完全二叉树且不含叶子，可采用顺序存储结构 
typedef struct
{
	KeyType key;
}ExNode;								//外结点，只存放待归并记录的关键字 
typedef ExNode External[K+1];		

/* 败者树函数列表 */
void K_Merge(FILE *fp_out, LoserTree ls, External b);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(01)算法11.1：利用败者树ls将k个输入归并段中的记录归并到输出归并段。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void Adjust(LoserTree ls, External b, int s); 
/*━━━━━━━━━━━━━━━━━━┓
┃(02)算法11.2：从b[s]出发调整败者树。┃
┗━━━━━━━━━━━━━━━━━━*/

void CreateLoserTree(LoserTree ls, External b);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(03)算法11.3：依次从b[k-1..0]出发，调整ls为败者树。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void input(FILE *fp[K], int *x, int i);
/*━━━━━━━━━━━━━━━━┓
┃(04)从文件fp[i]中读取关键字到x。┃
┗━━━━━━━━━━━━━━━━*/

void output(FILE *fp, int x);
/*━━━━━━━━━━━━┓
┃(05)将x输出到有序表fp。 ┃
┗━━━━━━━━━━━━*/

void RandomNum(FILE *fp);
/*━━━━━━━━━━━━━━━━━┓
┃(06)生成MAX个随机数到fp用作测试。 ┃
┗━━━━━━━━━━━━━━━━━*/

void Cut_Sort(FILE *fp);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(07)将随机数表fp分段排序后分别写入文件[0..k-1].txt中。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

#endif 
