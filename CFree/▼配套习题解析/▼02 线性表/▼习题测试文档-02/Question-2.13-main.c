#include <stdio.h>
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
int Algo_2_13(LinkList L, LElemType_L x);
	
void PrintElem(LElemType_L e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	LinkList L;
	int i;
	
	if(InitList_L(&L))					//链表L创建成功
	{
		for(i=1; i<=10; i++)
			ListInsert_L(L, i, 2*i);	
	}
	
	printf("L = ");
	ListTraverse_L(L, PrintElem); 			//输出L
	printf("\n\n");	
	
	printf("元素 \"12\" 在链表L中的位置为 %d \n", Algo_2_13(L, 18)); 
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━┓
┃题2.13：寻找元素x再L中的位置┃
┗━━━━━━━━━━━━━━*/
int Algo_2_13(LinkList L, LElemType_L x)
{
	int i;
	LinkList p;
		
	if(L)
	{
		i = 1;		
		p = L->next;
		while(p)
		{
			if(p->data==x)
				return i;
			i++;
			p = p->next;
		}
	}
	
	return 0;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
