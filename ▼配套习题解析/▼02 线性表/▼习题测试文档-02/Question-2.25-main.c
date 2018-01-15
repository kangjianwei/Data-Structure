#include <stdio.h>	
#include "../../../▲课本算法实现/▲02 线性表/01 SequenceList/SequenceList.c"	//**▲02 线性表**//

/* 函数原型 */
void Algo_2_25(SqList La, SqList Lb, SqList *Lc);
	
void PrintElem(LElemType_Sq e);
	//测试函数，打印整型 
	
int main(int argc, char *argv[])
{
	SqList La, Lb, Lc;
	int i;
	
	if(InitList_Sq(&La) && InitList_Sq(&Lb)) //链表L创建成功
	{
		for(i=1; i<=10; i++)
		{
			ListInsert_Sq(&La, i, i);
			ListInsert_Sq(&Lb, i, 2*i);		
		} 	
	}
	
	printf("La = ");
	ListTraverse_Sq(La, PrintElem);
	printf("\n");	
	printf("Lb = ");
	ListTraverse_Sq(Lb, PrintElem);
	printf("\n\n");	
		
	InitList_Sq(&Lc); 
	Algo_2_25(La, Lb, &Lc);
	printf("Lc = La∩Lb = ");
	ListTraverse_Sq(Lc, PrintElem); 			//输出L
	printf("\n\n");
		
	return 0;
}

/*━━━━━━━┓
┃题2.25：C=A∩B┃
┗━━━━━━━*/
void Algo_2_25(SqList La, SqList Lb, SqList *Lc)
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
			ListInsert_Sq(Lc, k, La.elem[i]);			
			k++;			
			i++;
			j++;
		}
	}
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}
