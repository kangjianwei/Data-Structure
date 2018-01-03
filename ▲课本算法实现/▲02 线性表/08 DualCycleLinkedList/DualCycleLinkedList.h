/**********************************************
 *						                      *
 * 文件夹: ▲02 线性表\08 DualCycleLinkedList *
 * 							                  *
 * 文件名: DualCycleLinkedList.h              *
 * 							                  *
 * 内  容: 双向循环链表相关操作列表           *
 *                                            *
 **********************************************/

#ifndef DUALCYCLELINKEDLIST_H
#define DUALCYCLELINKEDLIST_H

#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//

/* 双循环链表类型定义 */
typedef int LElemType_DC;
typedef struct DuLNode
{
	LElemType_DC data;
	struct DuLNode *prior;
	struct DuLNode *next;
}DuLNode;
typedef DuLNode* DuLinkList;		 	//指向双循环链表结构的指针 

/*	双循环链表函数列表	*/ 
Status InitList_DuL(DuLinkList *L);
/*━━━━━━━━━━┓
┃(01)初始化双链表L。 ┃
┗━━━━━━━━━━*/

Status ClearList_DuL(DuLinkList L);
/*━━━━━━┓
┃(02)置空L。 ┃
┗━━━━━━*/ 

void DestroyList_DuL(DuLinkList *L);
/*━━━━━━┓
┃(03)销毁L。 ┃
┗━━━━━━*/

Status ListEmpty_DuL(DuLinkList L);
/*━━━━━━━━━━┓
┃(04)判断L是否为空。 ┃
┗━━━━━━━━━━*/ 

int ListLength_DuL(DuLinkList L);
/*━━━━━━━━━━┓
┃(05)返回L元素个数。 ┃
┗━━━━━━━━━━*/ 

Status GetElem_DuL(DuLinkList L, int i, LElemType_DC *e);
/*━━━━━━━━━━━━━━━━━┓
┃(06)用e接收L中第i个结点的元素值。 ┃
┗━━━━━━━━━━━━━━━━━*/ 

int LocateElem_DuL(DuLinkList L, LElemType_DC e, Status (Compare)(LElemType_DC, LElemType_DC));
/*━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(07)返回L中第一个与e满足Compare关系的元素位序。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━*/ 

Status PriorElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *pre_e);
/*━━━━━━━━━━━━━━┓
┃(08)用pre_e接收cur_e的前驱。┃
┗━━━━━━━━━━━━━━*/ 

Status NextElem_DuL(DuLinkList L, LElemType_DC cur_e, LElemType_DC *next_e);
/*━━━━━━━━━━━━━━━┓
┃(09)用next_e接收cur_e的后继。 ┃
┗━━━━━━━━━━━━━━━*/

DuLinkList GetElemPtr_DuL(DuLinkList L, int i);
/*━━━━━━━━━━━━━━━━┓
┃(10)返回L中指向第i个结点的指针。┃
┗━━━━━━━━━━━━━━━━*/

Status ListInsert_DuL(DuLinkList L, int i, LElemType_DC e);
/*━━━━━━━━━━━━━━━━━━━┓
┃(11)算法2.18：在L第i个位置之前插入e。 ┃
┗━━━━━━━━━━━━━━━━━━━*/

Status ListDelete_DuL(DuLinkList L, int i, LElemType_DC *e);
/*━━━━━━━━━━━━━━━━━━━━━━━┓
┃(12)算法2.19：删除L第i个位置的值，并用e接收。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━*/ 

void ListTraverse_DuL(DuLinkList L, void(Visit)(LElemType_DC));
/*━━━━━━━━━━━┓
┃(13)用Visit函数访问L。┃
┗━━━━━━━━━━━*/ 
 
#endif
