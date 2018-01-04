/**************************************
 *                                    *
 * 文件夹: ▲03 栈和队列\07 LinkQueue *
 *                                    *
 * 文件名: LinkQueue.h                *
 *                                    *
 * 内  容: 链队相关操作列表           *
 *                                    *
 *************************************/

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//

/* 链队类型定义 */
/* 在模拟银行排队、二叉树三叉链表存储的算法中，QElemType_L需重新定义*/
#if !defined BANKQUEUING_H     &&  \
    !defined TRI_BINARYTREE_H
typedef int QElemType_L;
#endif
typedef struct QNode				 
{
	QElemType_L data;
	struct QNode *next;
}QNode;
typedef QNode* QueuePtr;
typedef struct
{
	QueuePtr front;					//头指针 
	QueuePtr rear;					//尾指针 
}LinkQueue;							//队列的链式存储表示 

/* 链栈函数列表 */
Status InitQueue_L(LinkQueue *Q);
/*━━━━━━━━━┓
┃(01)初始化链队Q。 ┃
┗━━━━━━━━━*/

void ClearQueue_L(LinkQueue *Q);
/*━━━━━━┓
┃(02)置空Q。 ┃
┗━━━━━━*/

void DestroyQueue_L(LinkQueue *Q);
/*━━━━━━┓
┃(03)销毁Q。 ┃
┗━━━━━━*/

Status QueueEmpty_L(LinkQueue Q);
/*━━━━━━━━━━┓
┃(04)判断Q是否为空。 ┃
┗━━━━━━━━━━*/

int QueueLength_L(LinkQueue Q);
/*━━━━━━━━━━┓
┃(05)返回Q元素个数。 ┃
┗━━━━━━━━━━*/

Status GetHead_L(LinkQueue Q, QElemType_L *e);
/*━━━━━━━━━━━┓
┃(06)用e获取队头元素。 ┃
┗━━━━━━━━━━━*/

Status EnQueue_L(LinkQueue *Q, QElemType_L e);
/*━━━━━━━━┓
┃(07)元素e入队。 ┃
┗━━━━━━━━*/

Status DeQueue_L(LinkQueue *Q, QElemType_L *e);
/*━━━━━━━━┓
┃(08)元素e出队。 ┃
┗━━━━━━━━*/

void QueueTraverse_L(LinkQueue Q, void(Visit)(QElemType_L));
/*━━━━━━━┓
┃(09)访问队列。┃
┗━━━━━━━*/

#endif
