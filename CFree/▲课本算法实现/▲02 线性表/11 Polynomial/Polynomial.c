/*************************************
 *				     	             *
 * 文件夹: ▲02 线性表\11 Polynomial *
 * 					                 *
 * 文件名: Polynomial.c              *
 * 				                     *
 * 算  法: 2.22、2.23                * 
 *                                   *
 *************************************/

#ifndef	POLYNOMIAL_C
#define	POLYNOMIAL_C

#include "Polynomial.h"					//**▲02 线性表**//

/*═════╗
║ 算法2.22 ║ 
╚═════*/
void CreatPolyn_P(FILE *fp, Polynomial *P, int m)
{
	PositionPtr h;
	ElemType_P e;
	int i;
	Link p;

	InitList_E(P);						//初始化一个扩展的单链表存放多项式 
	h = GetHead_E(*P);					//获取多项式头指针 

	e.coef = 0.0;
	e.expn = -1;
	SetCurElem_E(h, e);			    	//设置头结点的数据元素 
	h->next = NULL;
	
	for(i=1; i<=m; i++)					//依次录入n个非0项 
	{
		Scanf(fp, "%f%d", &(e.coef), &(e.expn));
		MakeNode_E(&p, e);
		p->next = NULL;
		InsFirst_E(P, h, p);
		h = h->next;
	} 
} 

void DestroyPolyn_P(Polynomial *P)
{
	DestroyList_E(P);
}

int PolynLength_P(Polynomial P)
{
	return ListLength_E(P);
}

/*═════╗
║ 算法2.23 ║ 
╚═════*/
void AddPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	PositionPtr ha, hb;
	PositionPtr qa, qb;
	ElemType_P a, b;
	float sum;
	 
	ha = GetHead_E(*Pa);					//ha、hb分别指向Pa、Pb头结点 
	hb = GetHead_E(*Pb);	
	qa = NextPos_E(ha);						//qa、qb分别指向Pa、Pb的当前结点
	qb = NextPos_E(hb);

	while(qa && qb)							//qa、qb均非空
	{
		a = GetCurElem_E(qa);				//a和b为两表中当前比较元素 
		b = GetCurElem_E(qb);

		switch(Cmp_exp(a,b))				//比较当前元素的指数大小 
		{
			case -1:						//多项式Pa中当前结点的指数值较小
				ha = qa;
				qa = NextPos_E(ha);
				break;
			case 0:							//两者数值相等 
				sum = a.coef + b.coef;
				if(sum != 0.0)				//相加不能抵消时更新Pa结点的系数值 
				{
					qa->data.coef = sum;
					SetCurElem_E(qa, qa->data);
					ha = qa;				//此时ha需后移 
				}
				else						//相加抵消时，删除Pa中当前结点
				{
					DelFirst_E(Pa, ha, &qa);
					FreeNode_E(&qa);
				}
				DelFirst_E(Pb, hb, &qb);	//删除Pb中扫描过的结点 
				FreeNode_E(&qb);
				qb = NextPos_E(hb);			//qa、qb均后移 
				qa = NextPos_E(ha);
				break;
			case 1:							//多项式Pb中当前结点的指数值较小
				DelFirst_E(Pb, hb, &qb);	//摘下Pb当前结点
				InsFirst_E(Pa, ha, qb); 	//将摘下结点链入Pa中
				qb = NextPos_E(hb);
				ha = NextPos_E(ha); 
				break; 
		}//switch
	}//while
	
	if(qb)									//若Pb还未扫描完，将剩余项链接到Pa后 
		Append_E(Pa, qb);

	FreeNode_E(&hb);						//释放Pb头结点
	(*Pb).head = (*Pb).tail = NULL;			//设置Pb为销毁状态 
	(*Pb).len = 0;		 
}

void SubtractPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	PositionPtr ha, hb;
	PositionPtr qa, qb;
	PositionPtr r;
	ElemType_P a, b;
	float sum;
	 
	ha = GetHead_E(*Pa);					//ha、hb分别指向Pa、Pb头结点 
	hb = GetHead_E(*Pb);	
	qa = NextPos_E(ha);						//qa、qb分别指向Pa、Pb的当前结点
	qb = NextPos_E(hb);
	
	while(qa && qb)							//qa、qb均非空
	{
		a = GetCurElem_E(qa);				//a和b为两表中当前比较元素 
		b = GetCurElem_E(qb);

		switch(Cmp_exp(a,b))				//比较当前元素的指数大小 
		{
			case -1:						//多项式Pa中当前结点的指数值较小
				ha = qa;
				qa = NextPos_E(ha);
				break;
			case 0:							//两者数值相等 
				sum = a.coef - b.coef;
				if(sum != 0.0)				//相减不能抵消时更新Pa结点的系数值 
				{
					qa->data.coef = sum;
					SetCurElem_E(qa, qa->data);
					ha = qa;				//此时ha需后移 
				}
				else						//相加抵消时，删除Pa中当前结点
				{
					DelFirst_E(Pa, ha, &qa);
					FreeNode_E(&qa);
				}
				DelFirst_E(Pb, hb, &qb);	//删除Pb中扫描过的结点 
				FreeNode_E(&qb);
				qb = NextPos_E(hb);			//qa、qb均后移 
				qa = NextPos_E(ha);
				break;
			case 1:							//多项式Pb中当前结点的指数值较小
				DelFirst_E(Pb, hb, &qb);	//摘下Pb当前结点
				qb->data.coef = - qb->data.coef;	//改变当前结点符号 
				InsFirst_E(Pa, ha, qb); 	//将摘下结点链入Pa中
				qb = NextPos_E(hb);
				ha = NextPos_E(ha); 
				break; 
		}//switch
	}//while

	if(qb)									//Pb还未扫描完
	{
		r = qb;
		while(r)							
		{
			r->data.coef = - r->data.coef;	//改变剩余结点符号 
			r = r->next;
		}
		Append_E(Pa, qb);	
	} 

	FreeNode_E(&hb);						//释放Pb头结点
	(*Pb).head = (*Pb).tail = NULL;
	(*Pb).len = 0;
}

void MultiplyPolyn_P(Polynomial *Pa, Polynomial *Pb)
{
	Polynomial Pc, Ptmp;
	int i, j, la, lb;
	PositionPtr ha;
	PositionPtr qa, qb;
	Link s;
	
	la = PolynLength_P(*Pa);
	lb = PolynLength_P(*Pb);
	ha = (*Pa).head;

	InitList_E(&Pc);
	
	for(i=1; i<=la; i++)
	{
		InitList_E(&Ptmp);

		DelFirst_E(Pa, ha, &qa);
		qb = (*Pb).head->next;

		for(j=1; j<=lb; j++)
		{
			s = (Link)malloc(sizeof(ELNode));				//申请空间 	
			if(!s)
				exit(OVERFLOW);
			
			s->data.coef = qa->data.coef * qb->data.coef;	//系数相乘 
			s->data.expn = qa->data.expn + qb->data.expn;	//指数相加 
			s->next = NULL;
			
			Append_E(&Ptmp, s);
			 
			qb = qb->next;
		}
		
		AddPolyn_P(&Pc, &Ptmp);		
	}
	
	AddPolyn_P(Pa, &Pc);
	
	DestroyPolyn_P(Pb);
}

int Cmp_exp(ElemType_P c1, ElemType_P c2)
{
	int i = c1.expn - c2.expn; 
	
	if(i<0)
		return -1;
	else if(i==0)
		return 0;
	else
		return 1;
} 

void PrintPolyn_P(Polynomial P)
{
	int i;
	Link p;
	
	p = P.head->next;
	for(i=1; i<=P.len; i++)
	{
		if(i==1)
			printf("%g", p->data.coef);
		else
		{
			if(p->data.coef>0)
			{
				printf(" + ");
				printf("%g", p->data.coef);
			}
			else
			{
				printf(" - ");
				printf("%g", -p->data.coef);
			}				
		}
		
		if(p->data.expn)
		{
			printf("x");
			
			if(p->data.expn!=1)
				printf("^%d", p->data.expn);
		}
		
		p = p->next;
	}
}

#endif
