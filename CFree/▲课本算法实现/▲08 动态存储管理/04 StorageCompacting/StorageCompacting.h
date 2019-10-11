/*******************************
 *                             *
 * 文件夹: ▲08 动态存储管理   *
 *                             *
 * 文件名: StorageCompacting.h *
 *                             *
 * 内  容: 存储紧缩            *
 *                             *
 *******************************/

#ifndef STORAGECOMPACTING_H
#define STORAGECOMPACTING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../▲01 绪论/Status.h"							//**▲01 绪论**//

/* 宏定义 */
#define MAX 1000

/* 全局变量 */
struct
{
	int stadr;					//当前内存块起始地址 
	int length;					//当前内存块大小 
}Record[MAX+1];					//内存地址表 

int start, end;					//空闲内存块下阕和上阕（固定） 
int cur;						//当前空闲内存块起点（浮动） 

/* 存储紧缩函数列表 */
void InitMemory(int n);
/*━━━━━━━━━━━━━━━━━━━┓
┃(01)初始化一块大小为 n 的空闲内存块。 ┃
┗━━━━━━━━━━━━━━━━━━━*/

void* MallocMemory(int n);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(02)分配一块大小为 n 的空闲内存块，若分配成功，返回其地址。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void FreeMemory(void* ptr);
/*━━━━━━━━━━━━━━━━━┓
┃(03)释放地址 ptr 处的空闲内存块。 ┃
┗━━━━━━━━━━━━━━━━━*/

int CompressMemory();
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(04)存储紧缩算法，返回压缩后空闲内存块当前起始地址。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void PrintLayout();
/*━━━━━━━━━━━━━━━━━━━┓
┃(05)输出当前空闲、非空闲内存块的数量。┃
┗━━━━━━━━━━━━━━━━━━━*/

#endif 
