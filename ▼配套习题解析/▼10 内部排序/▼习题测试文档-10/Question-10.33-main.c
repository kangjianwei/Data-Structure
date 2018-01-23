#include <stdio.h>
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
void Algo_10_33(LinkList *L);
void SelectMinPtr_10_33(LinkList s, LinkList *pre, LinkList *p);
void PrintKey(LElemType_L e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	LinkList L;
	int num;
		
	printf("创建并输出一个任意序列...\n");
	fp = fopen("Data/Algo_10_33.txt", "r");
	Scanf(fp, "%d", &num);
	CreateList_TL(fp, &L, num);
	ListTraverse_L(L, PrintKey);
	printf("\n\n");	

	printf("将关键字按递增顺序排列...\n");
	Algo_10_33(&L); 
	ListTraverse_L(L, PrintKey);
	printf("\n\n");	

	return 0;
}

/*━━━━━━━━━━━━━━┓
┃题10.33：单链表简单选择排序 ┃
┗━━━━━━━━━━━━━━*/
void Algo_10_33(LinkList *L)
{
	LinkList r, s, pre, p;
	
	s = (*L)->next;							//s指向链表第一个结点 
	(*L)->next = NULL;
	
	while(s)
	{
		SelectMinPtr_10_33(s, &pre, &p);
		
		if(p==s)
			s = s->next;
			
		if(pre)
			pre->next = p->next;
		
		if((*L)->next)	
			r->next = p, r = r->next;
		else
			(*L)->next = p, r = (*L)->next;	
	}
	
	r->next = NULL;
}

void SelectMinPtr_10_33(LinkList s, LinkList*pre, LinkList*p)
{
	int min;
	
	*pre = NULL;
	*p = s;
	
	for(min=s->data; s&&s->next; s=s->next)
	{
		if(s->next->data<min)
		{
			min = s->next->data;
			*pre = s;
			*p = s->next;
		}
	}
}

void PrintKey(LElemType_L e)
{
	printf("%d ", e);
}
