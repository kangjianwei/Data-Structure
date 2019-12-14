/****************************************
 *                                      *
 * 文件夹: ▲03 栈和队列\08 CylSeqQueue *
 *                                      *
 * 文件名: CylSeqQueue.h                *
 *                                      *
 * 内  容: 循环队列相关操作列表         *
 *                                      *
 ****************************************/

#ifndef CYLSEQQUEUE_H
#define CYLSEQQUEUE_H

#include <stdio.h>
#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//

/* 宏定义 */
#define MAXQSIZE 1000					//最大队列长度

/* 循环队列类型定义 */
typedef int QElemType_CSq;
typedef struct							//队列的顺序存储结构
{
	QElemType_CSq *base;				//初始化的动态分配存储空间 
	int front;							//头指针，若队列不空，指向队头元素 
	int rear;							//尾指针，若队列不空，指向队列尾元素的下一个位置 
}CSqQueue;

/* 循环队列函数列表 */
Status InitQueue_CSq(CSqQueue *Q);
/*━━━━━━━━━━━┓
┃(01)初始化循环队列Q。 ┃
┗━━━━━━━━━━━*/

void ClearQueue_CSq(CSqQueue *Q);
/*━━━━━━┓
┃(02)置空Q。 ┃
┗━━━━━━*/

void DestroyQueue_CSq(CSqQueue *Q);
/*━━━━━━┓
┃(03)销毁Q。 ┃
┗━━━━━━*/

Status QueueEmpty_CSq(CSqQueue Q);
/*━━━━━━━━━━┓
┃(04)判断Q是否为空。 ┃
┗━━━━━━━━━━*/

int QueueLength_CSq(CSqQueue Q);
/*━━━━━━━━━━┓
┃(05)返回Q元素个数。 ┃
┗━━━━━━━━━━*/

Status GetHead_CSq(CSqQueue Q, QElemType_CSq *e);
/*━━━━━━━━━━━┓
┃(06)用e获取队头元素。 ┃
┗━━━━━━━━━━━*/

Status EnQueue_CSq(CSqQueue *Q, QElemType_CSq e);
/*━━━━━━━━┓
┃(07)元素e入队。 ┃
┗━━━━━━━━*/

Status DeQueue_CSq(CSqQueue *Q, QElemType_CSq *e);
/*━━━━━━━━┓
┃(08)元素e出队。 ┃
┗━━━━━━━━*/

void QueueTraverse_CSq(CSqQueue Q, void(Visit)(QElemType_CSq));
/*━━━━━━━┓
┃(09)访问队列。┃
┗━━━━━━━*/

#endif
