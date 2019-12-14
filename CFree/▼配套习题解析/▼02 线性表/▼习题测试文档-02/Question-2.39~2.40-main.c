#include <stdio.h>
#include <math.h>												//提供pow原型			
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  			//**▲01 绪论**//

/* 类型定义 */
typedef struct					//稀疏多项式顺序结构
{
	int coef;					//系数 
	int exp;					//指数 
}PolyTerm;
typedef struct
{								//多项式的顺序存储结构
	PolyTerm *data;
	int last;					//多项式项数 
}SqPoly;

/* 函数原型 */
int Algo_2_39(SqPoly P, int x);
Status Algo_2_40(SqPoly Pa, SqPoly Pb, SqPoly *Pc);
Status CreatPoly_Sq(SqPoly *P, int n, PolyTerm Data[]);
void OutputPoly_Sq(SqPoly P);
 
int main(int argc, char *argv[])
{
	SqPoly Pa, Pb, Pc;
	PolyTerm a[5] = {{-2,1},{4,3},{11,5},{-7,7},{8,9}};
	PolyTerm b[5] = {{3,2},{-5,3},{12,4},{-7,7},{6,11}};
	
	CreatPoly_Sq(&Pa, 5, a);
	CreatPoly_Sq(&Pb, 5, b);
	printf("Pan(x) = ");
	OutputPoly_Sq(Pa);
	printf("\n");
	printf("Pbn(x) = ");
	OutputPoly_Sq(Pb);
	printf("\n\n");
		
	printf("███题 2.39 验证...███\n");
	printf("计算多项式Pa的值 Pa5(2) = %d", Algo_2_39(Pa, 2));
	printf("\n");
	printf("计算多项式Pb的值 Pb5(2) = %d", Algo_2_39(Pb, 2));
	printf("\n\n");
	
	printf("███题 2.40 验证...███\n");
	Algo_2_40(Pa, Pb, &Pc);
	printf("Pcn(x) = ");
	OutputPoly_Sq(Pc);
	printf("\n");	
	printf("计算多项式Pc的值 Pc5(2) = %d", Algo_2_39(Pc, 2));
	printf("\n\n");	
	return 0;
}

/*━━━━━━━━━━┓
┃题2.39：求多项式的值┃
┗━━━━━━━━━━*/
int Algo_2_39(SqPoly P, int x)
{
	int i, sum;
	
	for(i=0,sum=0; i<P.last; i++)
		sum += P.data[i].coef * (int)(pow(x, P.data[i].exp));
	
	return sum;
}

/*━━━━━━━━┓
┃题2.40：Pc=Pa-Pb┃
┗━━━━━━━━*/
Status Algo_2_40(SqPoly Pa, SqPoly Pb, SqPoly *Pc)
{
	int i, j, k, sum;
	
	(*Pc).data = (PolyTerm *)malloc((Pa.last+Pb.last)*sizeof(PolyTerm));
	if(!(*Pc).data)
		exit(OVERFLOW);	
	
	i = j = k =0;
	
	while(i<Pa.last && j<Pb.last)
	{
		if(Pa.data[i].exp<Pb.data[j].exp)
		{
			(*Pc).data[k++] = Pa.data[i];
			i++;
		}
		else if(Pa.data[i].exp>Pb.data[j].exp)
		{
			(*Pc).data[k].coef = -Pb.data[j].coef;	//符号改变
		 	(*Pc).data[k].exp = Pb.data[j].exp;
			k++;
			j++;		
		}
		else
		{
			sum = Pa.data[i].coef - Pb.data[j].coef;
			
			if(sum)
			{
				(*Pc).data[k].coef = sum;
				(*Pc).data[k].exp = Pa.data[i].exp;
				k++;
			}
			
			i++;
			j++;
		}
	}
	
	while(i<Pa.last)								//Pa未扫描完 
	{
		(*Pc).data[k++] = Pa.data[i];
		i++;	
	}	

	while(j<Pb.last)								//Pb未扫描完 
	{
		(*Pc).data[k].coef = -Pb.data[j].coef;		//符号改变
	 	(*Pc).data[k].exp = Pb.data[j].exp;
		k++;
		j++;	
	}
	
	(*Pc).last = k;
	
	return OK;	
}

Status CreatPoly_Sq(SqPoly *P, int n, PolyTerm Data[])
{
	int i;
	
	(*P).last = n;
	(*P).data = (PolyTerm *)malloc(n*sizeof(PolyTerm));
	if(!(*P).data)
		exit(OVERFLOW);
		
	for(i=0; i<n; i++)
		(*P).data[i] = Data[i];
	
	return OK;
}

void OutputPoly_Sq(SqPoly P)
{
	int i;
	
	for(i=0; i<P.last; i++)
	{
		if(i==0)
			printf("%d" , P.data[i].coef);
		else
		{
			if(P.data[i].coef<0)
			{
				printf(" - ");
				printf("%d", -P.data[i].coef);
			}
			else
			{
				printf(" + ");
				printf("%d", P.data[i].coef);			
			}
		}
		
		if(P.data[i].exp)
		{
			printf("x");
			
			if(P.data[i].exp!=1)
				printf("^%d", P.data[i].exp);		
		}
	}
}
