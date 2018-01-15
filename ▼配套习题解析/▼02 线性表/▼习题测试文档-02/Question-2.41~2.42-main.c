#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型		
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	//**▲01 绪论**//

/* 类型定义 */
typedef struct						//稀疏多项式链式结构
{
	int coef;						//系数 
	int exp;						//指数 
}PolyTerm;
typedef struct PolyNode
{
	PolyTerm data;
	struct PolyNode *next;
}PolyNode;
typedef PolyNode *PolyLink;
typedef PolyLink LinkedPoly;

/* 函数原型 */
Status Algo_2_41(LinkedPoly P);
Status Algo_2_42(LinkedPoly *P, LinkedPoly *P_Odd, LinkedPoly *P_Even);
Status CreatPoly_L(LinkedPoly *P, int n, PolyTerm Data[]);
Status OutputPoly_L(LinkedPoly P);

int main(int argc, char *argv[])
{
	LinkedPoly P1, P2;
	PolyTerm a[7] = {-2,1,4,2,2,3,11,5,-7,6,8,9,-3,10};

	CreatPoly_L(&P1, 7, a);
	CreatPoly_L(&P2, 7, a);
	printf("Pn(x) = ");
	OutputPoly_L(P1);
	printf("\n\n");
	
	printf("███题 2.41 验证...███\n");
	{
		
		Algo_2_41(P1);
		printf("求多项式的导函数之后...\n");
		printf("Pn(x) = ");
		OutputPoly_L(P1);
		printf("\n\n");	
	}

	
	printf("███题 2.42 验证...███\n");
	{
		LinkedPoly P_odd, P_even;	
		Algo_2_42(&P2, &P_odd, &P_even);
		printf("按指数奇偶性拆分多项式之后...\n");
		printf("奇次幂 P_odd = ");
		OutputPoly_L(P_odd);
		printf("\n");
		printf("偶次幂 P_even = ");
		OutputPoly_L(P_even);
		printf("\n\n");	
	}
	
	return 0;
}

/*━━━━━━━━┓
┃题2.41：求导函数┃
┗━━━━━━━━*/
Status Algo_2_41(LinkedPoly P)
{
	LinkedPoly r, pre;
	
	if(!P)
		return ERROR;
	
	pre = P;
	r = P->next;
	while(r!=P)
	{
		if(r->data.exp)
		{
			r->data.coef *= r->data.exp;	//系数与指数想乘 
			r->data.exp--;					//指数减一
			pre = r;
		}				 
		else								//删除当前结点 
		{
			pre->next = r->next;
			free(r);				
		}
		
		r = pre->next;
	}
	
	return OK;
}

/*━━━━━━━━━━━━━━━┓
┃题2.42：按指数奇偶性拆分多项式┃
┗━━━━━━━━━━━━━━━*/
Status Algo_2_42(LinkedPoly *P, LinkedPoly *P_Odd, LinkedPoly *P_Even)
{
	LinkedPoly r, s, p, q;
	
	*P_Odd = (LinkedPoly)malloc(sizeof(PolyNode)); 
	*P_Even = (LinkedPoly)malloc(sizeof(PolyNode));
	if(!(*P_Odd) || !(*P_Even))
		exit(OVERFLOW);
	(*P_Odd)->next = *P_Odd;
	(*P_Even)->next = *P_Even;
	
	if(!(*P))
		return ERROR;
	
	p = *P_Odd;
	q = *P_Even;
	r=(*P)->next;
	
	while(r!=(*P))
	{
		s = r;
		r = r->next;

		if(s->data.exp%2)							//指数为奇次
		{
			s->next = p->next;
			p->next = s;
			p = p->next;
		}
		else
		{
			s->next = q->next;
			q->next = s;
			q = q->next;
		}
	}

	free(*P);
	*P = NULL;
}

Status CreatPoly_L(LinkedPoly *P, int n, PolyTerm Data[])	//从无到有创建 
{
	int i;
	LinkedPoly s, r;
	
	*P = (LinkedPoly)malloc(sizeof(PolyNode));				//创建头结点 
	if(!(*P))
		exit(OVERFLOW);
	(*P)->next = *P;
	
	for(i=0,r=*P; i<n; i++)
	{
		s = (LinkedPoly)malloc(sizeof(PolyNode)); 
		if(!s)
			exit(OVERFLOW);		
		s->data = Data[i];
		
		s->next = r->next;
		r->next = s;
		
		r = r->next;
	}
	
	return OK;
}

Status OutputPoly_L(LinkedPoly P)
{
	int i;
	LinkedPoly r;
	
	if(!P)
		return ERROR;
	
	for(r=P->next; r!=P; r=r->next)
	{
		if(r==P->next)
			printf("%d" , r->data.coef);
		else
		{
			if(r->data.coef<0)
			{
				printf(" - ");
				printf("%d", -r->data.coef);
			}
			else
			{
				printf(" + ");
				printf("%d", r->data.coef);			
			}
		}
		
		if(r->data.exp)
		{
			printf("x");
			
			if(r->data.exp!=1)
				printf("^%d", r->data.exp);		
		}
	}
	
	return OK;
}
