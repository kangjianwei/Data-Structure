/*******************************************
 *                                         *
 * 文件夹: ▲02 线性表\04 SinglyLinkedList *
 *                                         *
 * 文件名: SinglyLinkedList.h              *
 *                                         *
 * 内  容: 单链表相关操作列表              *
 *                                         *
 *******************************************/

#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"		//**▲01 绪论**//

/* 单链表类型定义 */
#ifndef BANKQUEUING_H			/*后续的模拟银行排队算法中，此类型需要重新定义*/
typedef int LElemType_L;

/* 单链表结构体 */
typedef struct LNode
{
	LElemType_L data;
	struct LNode* next;
}LNode;
typedef LNode* LinkList;		//指向单链表结点的指针 
#endif

/* 单链表（带头结点）函数列表 */ 
Status InitList_L(LinkList *L);
/*━━━━━━━━━━┓
┃(01)初始化单链表L。 ┃
┗━━━━━━━━━━*/

Status ClearList_L(LinkList L);
/*━━━━━━━━━━━━━━━┓
┃(02)置空单链表L，头结点保留。 ┃ 
┗━━━━━━━━━━━━━━━*/ 

void DestroyList_L(LinkList *L);
/*━━━━━━━━━━━━━━━━━━━┓
┃(03)销毁单链表L，连同通结点一起销毁。 ┃
┗━━━━━━━━━━━━━━━━━━━*/

Status ListEmpty_L(LinkList L);
/*━━━━━━━━━━━━━━━┓
┃(04)判断单链表L是否为空。     ┃
┗━━━━━━━━━━━━━━━*/

int ListLength_L(LinkList L);
/*━━━━━━━━━━━━┓
┃(05)返回单链表L元素个数 ┃
┗━━━━━━━━━━━━*/ 

Status GetElem_L(LinkList L, int i, LElemType_L *e);
/*━━━━━━━━━━━━━━━━━━━┓
┃(06)算法2.8：用e接收单链表L中第i个元素┃
┗━━━━━━━━━━━━━━━━━━━*/ 

int LocateElem_L(LinkList L, LElemType_L e, Status(Compare)(LElemType_L, LElemType_L));
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(07)返回单链表L中第一个与e满足Compare关系的元素位序。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━*/ 

Status PriorElem_L(LinkList L, LElemType_L cur_e, LElemType_L *pre_e);
/*━━━━━━━━━━━━━━┓
┃(08)用pre_e接收cur_e的前驱。┃
┗━━━━━━━━━━━━━━*/ 

Status NextElem_L(LinkList L, LElemType_L cur_e, LElemType_L *next_e);
/*━━━━━━━━━━━━━━━┓
┃(09)用next_e接收cur_e的后继。 ┃
┗━━━━━━━━━━━━━━━*/

Status ListInsert_L(LinkList L, int i, LElemType_L e);
/*━━━━━━━━━━━━━━━━━━━━━┓
┃(10)算法2.9：在单链表L第i个位置之前插入e。┃
┗━━━━━━━━━━━━━━━━━━━━━*/

Status ListDelete_L(LinkList L, int i, LElemType_L *e);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(11)算法2.10：删除单链表L第i个位置的值，并用e接收。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/ 

Status ListTraverse_L(LinkList L, void(Visit)(LElemType_L));
/*━━━━━━━━━━━━━━┓
┃(12)用Visit函数访问单链表L。┃
┗━━━━━━━━━━━━━━*/  

Status CreateList_HL(FILE *fp, LinkList *L, int n);
/*━━━━━━━━━━━━━━━━━━━━━━┓
┃(13)算法2.11：头插法建立单链表L(逆序输入)。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━*/  

Status CreateList_TL(FILE *fp, LinkList *L, int n);
/*━━━━━━━━━━━━━━━━━┓
┃(14)尾插法建立单链表L(顺序输入)。 ┃
┗━━━━━━━━━━━━━━━━━*/  

#endif
