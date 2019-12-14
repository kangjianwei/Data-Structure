#include <stdio.h>
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
void Algo_10_37(LinkList L);
void Merge_10_37(LinkList SR[], LinkList TR[], int i, int m, int n);	//按指定分割点归并SR到TR 
void PrintKey(LElemType_L e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	LinkList L;
	int num;
		
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_37.txt", "r");
	Scanf(fp, "%d", &num);
	CreateList_TL(fp, &L, num);
	ListTraverse_L(L, PrintKey);
	printf("\n\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_37(L); 
	ListTraverse_L(L, PrintKey);
	printf("\n\n");	

	return 0;
}

/*━━━━━━━━━━━━┓
┃题10.37：逐段归并(链表) ┃
┗━━━━━━━━━━━━*/
void Algo_10_37(LinkList L)
{
	int l, len, k;
	int i, m, n;
	LinkList SR[101], TR[101];				//设置一个数组存放指向链表各数据结点的指针 
	LinkList p, r;
	
	for(len=0,p=L->next; p; p=p->next)		//初始化链表指针数组 
		SR[++len] = p;
	
	for(l=1; l<=len; l*=2)					//分段归并 
	{
		i=1, m=l;
		n = 2*m>len ? len : 2*m;
		
		while(i<len&&m<len)
		{
			Merge_10_37(SR, TR, i, m, n);
			i = n+1;
			m = i+l-1;
			n = i+2*l-1;
		}
		
		for(k=1; k<=len; k++)
			SR[k] = TR[k];
	}
	
	for(k=1,r=L; k<=len; k++)				//根据排好的指针顺序重排记录
	{
		r->next = SR[k];
		r = r->next;
	}
	
	r->next = NULL;
}

void Merge_10_37(LinkList SR[], LinkList TR[], int i, int m, int n)
{	
	int j, k;
	
	for(j=m+1,k=i; i<=m&&j<=n; ++k)					//将SR中记录由小到大地并入TR 
	{
		if(SR[i]->data<=SR[j]->data)
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
		
	while(i<=m)										//将剩余的SR[i..m]复制到TR 
		TR[k++] = SR[i++];
	
	while(j<=n)										//将剩余的SR[j..n]复制到TR 
		TR[k++] = SR[j++];
}

void PrintKey(LElemType_L e)
{
	printf("%d ", e);
}
