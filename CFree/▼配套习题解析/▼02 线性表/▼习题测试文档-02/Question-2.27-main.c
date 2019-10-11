#include <stdio.h>	
#include "../../../▲课本算法实现/▲02 线性表/01 SequenceList/SequenceList.c"	//**▲02 线性表**//

/* 函数原型 */
void Algo_2_27__1(SqList La, SqList Lb, SqList *Lc);
void Algo_2_27__2(SqList *La, SqList Lb);	
void PrintElem(LElemType_Sq e);					//测试函数，打印整型 

int main(int argc, char *argv[])
{
	SqList La, Lb, Lc_1, *Lc_2;
	int i;
	int a[10] = {1,2,2,3,4,5,6,7,7,8};
	int b[10] = {2,2,3,4,4,6,7,8,8,9}; 
	
	if(InitList_Sq(&La) && InitList_Sq(&Lb)) 	//链表L创建成功
	{
		for(i=1; i<=10; i++)
		{
			ListInsert_Sq(&La, i, a[i-1]);
			ListInsert_Sq(&Lb, i, b[i-1]);		
		} 	
	}
	
	printf("La = ");
	ListTraverse_Sq(La, PrintElem);
	printf("\n");	
	printf("Lb = ");
	ListTraverse_Sq(Lb, PrintElem);
	printf("\n\n");	
	
	printf("题 2.27 第(1)问验证：\n");
	InitList_Sq(&Lc_1);
	Algo_2_27__1(La, Lb, &Lc_1);
	printf("Lc = La∩Lb = ");
	ListTraverse_Sq(Lc_1, PrintElem); 			//输出L
	printf("\n\n");

	printf("题 2.27 第(2)问验证：\n");
	Algo_2_27__2(&La, Lb);
	Lc_2 = &La;
	printf("Lc = La∩Lb = ");
	ListTraverse_Sq(*Lc_2, PrintElem); 			//输出L
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━┓
┃题2.27：C=A∩B┃
┗━━━━━━━*/
/* (1) */
void Algo_2_27__1(SqList La, SqList Lb, SqList *Lc)
{
	int i, j, k;
	
	i = j = 0;
	k = 1;
	
	while(i<La.length && j<Lb.length)
	{
		if(La.elem[i]<Lb.elem[j])
			i++;
		else if(La.elem[i]>Lb.elem[j])
			j++;
		else
		{
			if(!i || La.elem[i]!=La.elem[i-1])
			{
				ListInsert_Sq(Lc, k, La.elem[i]);			
				k++;
			}
			
			i++;
			j++;
		}
	}
}

/*━━━━━━━┓
┃题2.27：C=A∩B┃
┗━━━━━━━*/
/* (2) */
void Algo_2_27__2(SqList *La, SqList Lb)
{
	int i, j, k;
	int len_a;
	
	i = j = k = 0;
	len_a = 0;
	
	while(i<(*La).length && j<Lb.length)
	{
		if((*La).elem[i]<Lb.elem[j])
			i++;
		else if((*La).elem[i]>Lb.elem[j])
			j++;
		else
		{
			if(!i || (*La).elem[i]!=(*La).elem[i-1])
			{
				(*La).elem[k] = (*La).elem[i];
				len_a++;
				k++;			
			}
			i++;
			j++;
		}	
	}
	
	(*La).length = len_a;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}
