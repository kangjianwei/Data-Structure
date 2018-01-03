/************************************
 *					                *
 * 文件夹: ▲02 线性表\05 MergeList *
 * 					                *
 * 文件名: MergeList.c              *
 * 				                    *
 * 算  法: 2.12                     * 
 *                                  *
 ************************************/

#ifndef MERGELIST_C
#define MERGELIST_C

#include "MergeList.h"					//**▲02 线性表**//

/*═════╗
║ 算法2.12 ║ 
╚═════*/
void MergeList_L(LinkList La, LinkList *Lb, LinkList *Lc)
{										//指针Lb,Lc要改变，故形参是指向指针的指针 
	LinkList pa, pb, pc;
	
	pa = La->next;
	pb = (*Lb)->next;
	pc = *Lc = La;						//用La的头结点作为Lc的头结点 						

	while(pa && pb)
	{
		if(pa->data <= pb->data)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}	
	}

	pc->next = pa ? pa : pb;			//插入剩余段 
	
	free(*Lb);							//释放Lb的头结点
	*Lb = NULL; 
}

#endif
