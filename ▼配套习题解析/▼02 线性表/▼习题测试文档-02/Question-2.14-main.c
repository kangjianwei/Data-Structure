#include <stdio.h>
#include "../../../▲课本算法实现/▲02 线性表/04 SinglyLinkedList/SinglyLinkedList.c"	//**▲02 线性表**//

/* 函数原型 */
int Algo_2_14(LinkList L);
	
void PrintElem(LElemType_L e);
	//测试函数，打印整型 

int main(int argc, char *argv[])
{
	LinkList L;
	int i;
	
	if(InitList_L(&L))					//链表L创建成功
	{
		for(i=1; i<=10; i++)			//链表L中元素1~20 
			ListInsert_L(L, i, 2*i);	
	}
	
	printf("L = ");
	ListTraverse_L(L, PrintElem); 			//输出L
	printf("\n\n");	
	
	printf("链表L的长度为 %d \n", Algo_2_14(L)); 
	printf("\n");
		
	return 0;
}

/*━━━━━━━━┓
┃题2.14：求L长度 ┃
┗━━━━━━━━*/
int Algo_2_14(LinkList L)
{
	return ListLength_L(L);				//已定义 
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
