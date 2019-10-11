/***************************************
 *							           *
 * 文件夹: ▲06 树和二叉树\10 PowerSet *
 * 						               *
 * 文件名: PowerSet.c                  *
 * 						               *
 * 算  法: 6.14、6.15                  * 
 * 						               *
 ***************************************/

#ifndef POWERSET_C
#define POWERSET_C

#include "PowerSet.h" 							//**06 树和二叉树**//

Status CreatePowerSet_PS(FILE *fp, LinkList *A)
{
	int i, j;
	PElemType e;								//集合元素类型为int 
	
	InitList_L(A);
	Scanf(fp, "%d", &j);
	printf("录入集合 A 的元素个数 %d...\n", j);
	
	for(i=1; i<=j; i++)
	{
		Scanf(fp, "%d", &e);
		printf("录入第 %d 个元素：%d\n", i, e);
		ListInsert_L(*A, i, e);
	}
	
	return OK; 
}

/*═════════╗
║ 算法6.14 && 6.15 ║ 
╚═════════*/
void GetPowerSet_PS(int i, LinkList A, LinkList B)
{
	int k;
	LElemType_L x;
	
	if(i>ListLength_L(A))
		Output_PS(B);	
	else
	{
		GetElem_L(A, i, &x);
		k = ListLength_L(B);
		
		ListInsert_L(B, k+1, x);				//+第i个元素 
		GetPowerSet_PS(i+1, A, B);
		
		ListDelete_L(B, k+1, &x);				//-第i个元素
		GetPowerSet_PS(i+1, A, B);
	}	 
}

void Output_PS(LinkList A)
{
	LinkList p;
	int len = ListLength_L(A);
	
	if(len)
	{
		for(p=A->next; p; p=p->next)
			printf("%d ", p->data);
	}
	else
		printf("⊙");

	printf("\n");
}

#endif 
