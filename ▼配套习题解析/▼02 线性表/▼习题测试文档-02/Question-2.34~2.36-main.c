#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型 
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//

/* 类型定义 */
typedef char XElemType;
typedef struct XorNode			//异或指针链表结点结构		
{
	XElemType data;
	struct XorNode *LRPtr;
}XorNode;
typedef XorNode* XorPointer;	//指向结点结构的指针 
typedef struct					//无头结点的异或指针双向链表的头尾指针 
{
	XorPointer Left;			//分别指向链表的最左端（头指针）和最右端（尾指针） 
	XorPointer Right;
}XorLinkedList;
typedef XorLinkedList* Xor;

/* 异或指针链表函数原型 */
Status Algo_2_34_1(Xor L, int mark);
Status Algo_2_34_2(Xor L, int mark);
Status Algo_2_35(Xor L, int i, XElemType e);
Status Algo_2_36(Xor L, int i, char *e);
XorPointer XorP_XorL(XorPointer p, XorPointer q);
Status Init_XorL(Xor *L);
Status Create_XorL(Xor L, int n, XElemType Data[]);
XorPointer Prior_Next_Ptr_XorL(Xor L, XorPointer cur, int mark);
int Length_XorL(Xor L);
XorPointer GetElemPtr_XorL(Xor L, int i);

int main(int argc, char **argv)
{
	Xor L;
	XElemType e;
	int n = 9;
	XElemType *data = "123456789";
	
	Init_XorL(&L);			//先初始化 
	 
	Create_XorL(L, n, data);		
	printf("███题 2.34 验证...███\n");
	printf("顺序输出L = ");
	Algo_2_34_1(L, 0);
	printf("\n");
	printf("逆序输出L = ");
	Algo_2_34_1(L, 1);
	printf("\n\n");

	printf("███题 2.35 验证...███\n");		
	Algo_2_35(L, 5, '*');
	printf("插入 '*' 为L的第5个结点后顺序输出...\n");
	Algo_2_34_2(L, 0);
	printf("\n\n");

	printf("███题 2.36 验证...███\n");			
	Algo_2_36(L, 5, &e);
	printf("删除L的第5个结点 '%c' 后逆序输出...\n", e);
	Algo_2_34_2(L, 1);
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━┓
┃(01)指针异或函数，返回指针p和q的异或值┃
┗━━━━━━━━━━━━━━━━━━━*/
XorPointer XorP_XorL(XorPointer p, XorPointer q)
{					 
	unsigned long x, y, z;
	
	x = (unsigned long)p;
	y = (unsigned long)q;
	
	z = x^y;					//求异或 
	
	return (XorPointer)z;
}

/*━━━━━━━━━━━━┓
┃(02)初始化异或指针链表L ┃
┗━━━━━━━━━━━━*/
Status Init_XorL(Xor *L)
{
	*L = (Xor)malloc(sizeof(XorLinkedList));
	if(!(*L))
		exit(OVERFLOW);
		
	(*L)->Left = NULL;
	(*L)->Right = NULL;

	return OK; 
}

/*━━━━━━━━━━━┓
┃(03)创建异或指针链表L ┃
┗━━━━━━━━━━━*/
Status Create_XorL(Xor L, int n, XElemType Data[])
{
	int i;
	XorPointer pre_l, pre_m, pre_r; 

	pre_l = pre_m = NULL;
	
	for(i=1; i<=n; i++)
	{
		pre_r = (XorPointer) malloc (sizeof(XorNode));
		if(!pre_r)
			exit(OVERFLOW);
		
		pre_r->data = Data[i-1];
		
		if(i==1)					//左指针（创建首结点时设立） 
			L->Left = pre_r;
 			
		if(pre_m)					//pre_m不为空时执行,从创立第二个结点时执行 
			pre_m->LRPtr = XorP_XorL(pre_l, pre_r);				

		L->Right = pre_r;			//右指针					
		pre_r->LRPtr = XorP_XorL(pre_m, NULL);
		pre_l = pre_m;
		pre_m = pre_r;	
	}
	
	return OK;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃(04)获取当前结点(cur)的前驱(mark=0)或后继(mark=1) ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/
XorPointer Prior_Next_Ptr_XorL(Xor L, XorPointer cur, int mark) 
{
	XorPointer p_l, p_m, p_r;

	if(mark!=1 && mark!=0)
		return NULL;
	
	if(!L || !L->Left || !cur)					//链表不存在或链表为空或cur为空则无法求地址
		return NULL;

	if(mark==1)									//求后继，从左向右 
	{
		p_l = NULL;
		p_m = L->Left;
		
		while(p_m!=cur)
		{
			p_r = XorP_XorL(p_l, p_m->LRPtr);	//计算右侧第一个结点地址
			p_l = p_m;							//指针不断向右推进 
			p_m = p_r;
		}
		
		p_r = XorP_XorL(p_l, p_m->LRPtr);
		
		return p_r;
	}
	
	if(mark==0)									//求前驱，从右向左 
	{
		p_m = L->Right;
		p_r = NULL;
		while(p_m!=cur)
		{
			p_l = XorP_XorL(p_m->LRPtr, p_r);	//计算左侧第一个结点地址
			p_r = p_m;							//指针不断向左推进
			p_m = p_l;
		}
		
		p_l = XorP_XorL(p_m->LRPtr, p_r);
		
		return p_l;
	}
}

/*━━━━━━━┓
┃(05)获取L长度 ┃
┗━━━━━━━*/
int Length_XorL(Xor L)
{
	int count;	
	XorPointer p, pre, psuc;
	
	if(!L)
		exit(OVERFLOW);					//链表不存在则退出 
	
	count = 0;	
	pre = NULL;
	p = L->Left;						//从左向右遍历
	
	while(p)
	{
		count++;
		psuc = XorP_XorL(pre, p->LRPtr);
		pre = p;
		p = psuc;
	}
	
	return count; 
}

/*━━━━━━━━━━━━━━┓
┃(06)返回指向第i个结点的指针 ┃
┗━━━━━━━━━━━━━━*/ 
XorPointer GetElemPtr_XorL(Xor L, int i)	//i为元素位序 
{
	int count;
	XorPointer p, pre, psuc;

	if(!L || !L->Left)						//链表不存在或链表为空无法求地址 
		return ERROR;

	if(i<1)
		return ERROR;
	
	count = 1;
	pre = NULL;
	p = L->Left;
	
	while(count<i && p)
	{
		psuc = XorP_XorL(pre, p->LRPtr);
		pre = p;
		p = psuc;
		count++;
	}
	
	return p;
}

/*━━━━━━━━━━━━━━━┓
┃(07-1)输出L，mark表示输出方向 ┃
┗━━━━━━━━━━━━━━━*/
/* 方法1：借助Prior_Next_Ptr_XorL函数遍历链表 */ 
Status Algo_2_34_1(Xor L, int mark)
{
	XorPointer cur;
	
	if(mark!=1 && mark!=0)
		return ERROR;
		
	if(!L || !L->Left)				//链表不存在或链表为空则无法输出 
		return ERROR;
		
	if(mark==0)
	{
		cur = L->Left;
		do
		{
			printf("%c ",cur->data);
			cur = Prior_Next_Ptr_XorL(L, cur, !mark);
		}while(cur);
	}
	
	if(mark==1)
	{
		cur = L->Right;
		do
		{
			printf("%c ",cur->data);
			cur = Prior_Next_Ptr_XorL(L, cur, !mark);
		}while(cur);
	}

	return OK;
}

/*━━━━━━━━━━━━━━━┓
┃(07-2)输出L，mark表示输出方向 ┃
┗━━━━━━━━━━━━━━━*/
/* 方法2：不借助前驱_后继函数遍历链表 */
Status Algo_2_34_2(Xor L, int mark)		//i等于0代表从左向右输出，1代表从右向左输出 
{
	XorPointer p_l, p_m, p_r;
	
	if(mark!=1 && mark!=0)
		return ERROR;
		
	if(!L && !L->Left)					//链表不存在或链表为空则无法输出 
		return ERROR;

	if(mark==0)							//从左向右
	{
		p_l = NULL;
		p_m = L->Left;
		
		while(p_m)						//p_m为空时说明已输出完毕 
		{
			printf("%c ",p_m->data);
			p_r = XorP_XorL(p_l, p_m->LRPtr);//计算右侧第一个结点地址
			p_l = p_m;					//指针不断推进 
			p_m = p_r;			
		}
	}
	
	if(mark==1)
	{
		p_m = L->Right;
		p_r = NULL;

		while(p_m)
		{
			printf("%c ",p_m->data);
			p_l = XorP_XorL(p_m->LRPtr, p_r);
			p_r = p_m;
			p_m = p_l;			      
		} 
	}

	return OK;
}

/*━━━━━━━━━━━━━━━┓
┃(08)将元素e插入到第i个结点之前┃
┗━━━━━━━━━━━━━━━*/
Status Algo_2_35(Xor L, int i, XElemType e)
{
	XorPointer s, i_pre_pre, i_pre, i_cur, i_suc;
	
	if(!L)										//L必须存在 
		return ERROR;
		 
	if(i<1 || i>Length_XorL(L)+1)				//i限制在正确的范围内					
		return ERROR;
		
	s = (XorPointer)malloc(sizeof(XorNode));
	if(!s)
		return OVERFLOW;
	s->data = e;

	i_cur = GetElemPtr_XorL(L, i);				//指向第i个结点 	
	i_pre = GetElemPtr_XorL(L, i-1);			//指向第i-1个结点
	i_pre_pre = GetElemPtr_XorL(L, i-2);		//指向第i-2个结点
	
	if(!i_cur)									//第i个结点不存在 
	{
		if(!i_pre)								//链表为空，插入为首结点						
		{
			s->LRPtr = NULL;
			L->Left =s;
		}
		else									//链表不空，插入为尾结点
		{
			s->LRPtr = i_pre;
			i_pre->LRPtr = XorP_XorL(i_pre_pre, s);		
		}
		
		L->Right = s;
	}
	else										//第i个结点存在 
	{
		i_suc = XorP_XorL(i_pre, i_cur->LRPtr);	//指向第i+1个结点 
		
		s->LRPtr = XorP_XorL(i_pre, i_cur);		//设定s的后继指针 
		i_cur->LRPtr = XorP_XorL(s, i_suc);		//当前结点的后继指针也要改变 
		
		if(!i_pre)								//链表不空，插入为首结点 
			L->Left = s;		
		else
			i_pre->LRPtr = XorP_XorL(i_pre_pre, s);
	}	

	return OK;
}


/*━━━━━━━━━━━━━━━━━━━━┓
┃(09)删除第i个结点，并用e接受结点中元素值┃
┗━━━━━━━━━━━━━━━━━━━━*/
Status Algo_2_36(Xor L, int i, char *e)
{
	XorPointer i_pre_pre, i_pre, i_cur, i_suc, i_suc_suc;
	
	if(i<1 || i>Length_XorL(L))
		return ERROR;
		
	if(!L || !L->Left)
		return ERROR;
		
	i_cur = GetElemPtr_XorL(L, i);					//指向第i个结点 
	*e = i_cur->data;
	
	i_pre = GetElemPtr_XorL(L, i-1);				//指向第i-1个结点 	
	i_suc = XorP_XorL(i_pre, i_cur->LRPtr);			//指向第i+1个结点 	
	
		
	if(!i_suc)										//删除尾结点 
	{
		L->Right = i_pre;
		
		if(!i_pre)									//只有一个结点的情况
			L->Left = NULL;
		else
			i_pre->LRPtr = XorP_XorL(i_pre->LRPtr, i_cur);	
	}
	else
	{
		if(!i_pre)									//删除首结点
		{
			L->Left = i_suc;
			i_suc->LRPtr = 	XorP_XorL(i_cur, i_suc->LRPtr);
		}
		else
		{
			i_pre_pre = XorP_XorL(i_pre->LRPtr, i_cur);		//指向第i-2个结点 	
			i_suc_suc = XorP_XorL(i_cur, i_suc->LRPtr);		//指向第i+2个结点
			i_pre->LRPtr = XorP_XorL(i_pre_pre, i_suc);
			i_suc->LRPtr = XorP_XorL(i_pre, i_suc_suc);
		}
	}
	
	free(i_cur);
	i_cur = NULL;
	
	return OK;
}
