/************************************
 *						            *
 * 文件夹: ▲02 线性表              *
 * 							        *
 * 文件名: ExtenLinkedList.h        *
 * 							        *
 * 内  容: 扩展的单链表相关操作列表 *
 *                                  *
 ************************************/

#ifndef EXTENLINKEDLIST_H
#define EXTENLINKEDLIST_H

#include <stdlib.h>						//提供malloc、realloc、free、exit原型
#include "../../▲01 绪论/Status.h"		//**▲01 绪论**//
#include "../../▲01 绪论/Scanf.c"		//**▲01 绪论**//

/*	扩展的单链表类型定义	*/
#ifndef POLYNOMIAL_H					//在多项式操作中，此类型需重新定义 
typedef int LElemType_E; 
#endif
typedef struct ELNode					//结点类型 
{
	LElemType_E data;
	struct ELNode *next;
}ELNode; 
typedef ELNode* Link;			 		//指向结构的指针 
typedef ELNode* PositionPtr;
typedef struct							//链表类型 
{
	Link head, tail;					//分别指向线性链表中的头结点和尾结点 
	int len;							//指示线性链表中数据元素的个数 
}ELinkList;

/*	扩展的单链表函数列表 */ 
Status MakeNode_E(Link *p, LElemType_E e); 
/*━━━━━━━━━━━━┓
┃(01)分配由p指向e的结点。┃
┗━━━━━━━━━━━━*/

void FreeNode_E(Link *p);
/*━━━━━━━━━━━┓
┃(02)释放p指向的结点。 ┃
┗━━━━━━━━━━━*/

Status InitList_E(ELinkList *L);
/*━━━━━━━━━━━━━━┓
┃(03)初始化一个空的线性链表。┃
┗━━━━━━━━━━━━━━*/

void ClearList_E(ELinkList *L);
/*━━━━━━━━━━━━┓
┃(04)重置线性链表L为空。 ┃
┗━━━━━━━━━━━━*/

void DestroyList_E(ELinkList *L);
/*━━━━━━━━━━┓
┃(05)销毁线性链表L。 ┃
┗━━━━━━━━━━*/

void InsFirst_E(ELinkList *L, Link h, Link s);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(06)h指向L中的一个结点，将h当做头结点，将s插入到“第一个结点”之前。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status DelFirst_E(ELinkList *L, Link h, Link *q);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(07)h指向L中的一个结点，将h当做头结点，删除“第一个结点”，并用q接收。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void Append_E(ELinkList *L, Link s);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(08)将s所指的一串结点链接在L的最后一个结点之后，并改变L的尾指针。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status Remove_E(ELinkList *L, Link *q);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(09)删除L的尾结点并用q接收，改变尾指针。┃
┗━━━━━━━━━━━━━━━━━━━━*/

void InsBefore_E(ELinkList *L, Link *p, Link s);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(10)将s所指结点插入p所指结点之前,并将p指向新插入的结点。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void InsAfter_E(ELinkList *L, Link *p, Link s);
/*━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(11)将s所指结点插入p所指结点之后,并将p指向新插入的结点。┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━*/

void SetCurElem_E(Link p, LElemType_E e);
/*━━━━━━━━━━━━━━━┓
┃(12)用e更新p指向的结点中的值。┃
┗━━━━━━━━━━━━━━━*/

LElemType_E GetCurElem_E(Link p);
/*━━━━━━━━━━━┓
┃(13)返回p结点中的值。 ┃
┗━━━━━━━━━━━*/

Status ListEmpty_E(ELinkList L);
/*━━━━━┓
┃(14)判空。┃
┗━━━━━*/

int ListLength_E(ELinkList L);
/*━━━━━┓
┃(15)求长。┃
┗━━━━━*/

PositionPtr GetHead_E(ELinkList L);
/*━━━━━━━━━━━━━━━━━┓
┃(16)以指针形式返回L头结点的位置。 ┃
┗━━━━━━━━━━━━━━━━━*/

PositionPtr GetLast_E(ELinkList L);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(17)以指针形式返回L最后一个结点的位置。 ┃
┗━━━━━━━━━━━━━━━━━━━━*/

PositionPtr PriorPos_E(ELinkList L, Link p);
/*━━━━━━━━━━━━━━┓
┃(18)返回p指向的结点的前驱。 ┃
┗━━━━━━━━━━━━━━*/

PositionPtr NextPos_E(Link p);
/*━━━━━━━━━━━━━━┓
┃(19)返回p指向的结点的后继。 ┃
┗━━━━━━━━━━━━━━*/

Status LocatePos_E(ELinkList L, int i, Link *p);
/*━━━━━━━━━━━━━━━━━━━━┓
┃(20)将*p指向L中第i个结点,i=0时为头结点。┃
┗━━━━━━━━━━━━━━━━━━━━*/

PositionPtr LocateElem_E(ELinkList L, LElemType_E e, Status(Compare)(LElemType_E,LElemType_E));
/*━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(21)返回L中指向第一个与e满足Compare关系的元素指针。 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━*/

Status ListTraverse_E(ELinkList L, void(Visit)(LElemType_E));
/*━━━━━┓
┃(22)访问。┃
┗━━━━━*/

Status ListInsert_L_E(ELinkList *L, int i, LElemType_E e);
/*━━━━━━━━━━━━━━━━━━━┓
┃(23)算法2.20：在L第i个位置之前插入e。 ┃
┗━━━━━━━━━━━━━━━━━━━*/

Status ListDelete_L_E(ELinkList *L, int i, LElemType_E *e);
/*━━━━━━━━━━━━━━━━━━┓
┃(24)删除L第i个位置的值，并用e接收。 ┃
┗━━━━━━━━━━━━━━━━━━*/ 

#endif
