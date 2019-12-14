#include <stdio.h>
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
void Algo_10_33(LinkList *L);
void SelectMinPtr_10_33(LinkList s, LinkList *pre, LinkList *p);
void PrintKey(LElemType_L e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	LinkList L;
	int num;
		
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_33.txt", "r");
	Scanf(fp, "%d", &num);
	CreateList_TL(fp, &L, num);
	ListTraverse_L(L, PrintKey);
	printf("\n\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_33(&L); 
	ListTraverse_L(L, PrintKey);
	printf("\n\n");	

	return 0;
}

/*������������������������������
����10.33���������ѡ������ ��
������������������������������*/
void Algo_10_33(LinkList *L)
{
	LinkList r, s, pre, p;
	
	s = (*L)->next;							//sָ�������һ����� 
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
