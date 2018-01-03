/************************************
 *						            *
 * 文件夹: ▲02 线性表              *
 * 						            *
 * 内  容: 扩展的单链表相关函数测试 *
 *                                  *
 ************************************/

#include <stdio.h>
#include "ExtenLinkedList.c" 							//**▲02 线性表**//

/* 函数原型 */
Status CmpGreater(LElemType_E e, LElemType_E data);		//判断data是否大于e //若data>e，返回TRUE
void PrintElem(LElemType_E e);							//测试函数，打印整型
	
int main(int argc, char **argv)
{
	ELinkList L;
	Link p, q, s;
	PositionPtr r;
	int i;
	LElemType_E e;
		
	printf("▼3\n▲函数 InitList_E 测试...\n");			//3.函数InitList_E测试
	{
		printf("初始化扩展的单链表 L ...\n");	
		InitList_E(&L);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼14\n▲函数 ListEmpty_E 测试...\n");		//14.函数ListEmpty_E测试
	{
		ListEmpty_E(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("▼23\n▲函数 ListInsert_L_E 测试...\n");	//23.函数ListInsert_L_E测试
	{
		for(i=1; i<=6; i++)
		{
			printf("在 L 第 %d 个位置插入 \"%d\" ...\n", i, 2*i);
			ListInsert_L_E(&L, i, 2*i);
		}
		printf("\n");
	} 
	PressEnter;
	
	printf("▼22\n▲函数 ListTraverse_E 测试...\n");	//22.函数ListTraverse_E测试
	{
		printf(" L 中的元素为：L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("▼15\n▲函数 ListLength_E 测试...\n");		//15.函数ListLength_E测试
	{
		i = ListLength_E(L);
		printf(" L 的长度为 %d \n", i);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼24\n▲函数 ListDelete_E 测试...\n");		//24.函数ListDelete_L_E测试
	{
		ListDelete_L_E(&L, 6, &e);
		printf("删除 L 中第 6 个元素 \"%d\" ...\n", e);
		printf(" L 中的元素为：L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;	

	printf("▼20\n▲函数 LocatePos_E 测试...\n");		//20.函数LocatePos_E测试
	{
		LocatePos_E(L, 3, &p);
		printf(" L 中第 3 个元素 \"%d\" 的地址为 0x%x \n", p->data, p);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼18\n▲函数 PriorPos_E 测试...\n");		//18.函数PriorPos_E测试
	{
		r = PriorPos_E(L, p);
		printf("指针 p 指向的元素 \"%d\" 的前驱元素为 \"%d\" \n", p->data, r->data);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼19\n▲函数 NextPos_E 测试...\n");			//19.函数NextPos_E测试
	{
		r = NextPos_E(p);
		printf("指针 p 指向的元素 \"%d\" 的后继元素为 \"%d\" \n", p->data, r->data);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼21\n▲函数 LocateElem_E 测试...\n");		//21.函数LocateElem_E测试
	{
		r = LocateElem_E(L, 7, CmpGreater);
		printf(" L 中第一个元素值大于 7 的元素 \"%d\" 的地址为 0x%x \n", r->data, r);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼1\n▲函数 MakeNode_E 测试...\n");			//1.函数MakeNode_E测试
	{
		printf("创建结点 p ...\n");
		MakeNode_E(&p, 101);
		printf("创建结点 q ...\n");
		MakeNode_E(&q, 202);
		printf("\n"); 
	} 
	PressEnter;
	
	printf("▼13\n▲函数 GetCurElem_E 测试...\n");		//13.函数GetCurElem_E测试
	{
		e = GetCurElem_E(p);
		printf("结点 p 的值为 \"%d\" \n", e);
		e = GetCurElem_E(q);
		printf("结点 q 的值为 \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼12\n▲函数 SetCurElem_E 测试...\n");		//12.函数SetCurElem_E测试
	{
		printf("用 888 替换 p 结点中的值...\n"); 
		SetCurElem_E(p, 888);
		printf("结点 p 的值为 \"%d\" \n", p->data);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼2\n▲函数 FreeNode_E 测试...\n");			//2.函数FreeNode_E测试
	{
		printf("销毁结点 p 前：");
		p ? printf(" p 存在！\n") : printf(" p 不存在！！\n");
		FreeNode_E(&p);
		printf("销毁结点 p 后：");
		p ? printf(" p 存在！\n") : printf(" p 不存在！！\n");
		printf("\n");
	} 
	PressEnter;
	 
	printf("▼8\n▲函数 Append_E 测试...\n");			//8.函数Append_E测试
	{
		printf("将 q 结点插在 L 最后一个结点之后...\n");
		Append_E(&L, q);
		printf(" L 中的元素为：L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("▼9\n▲函数 Remove_E 测试...\n");			//9.函数Remove_E测试
	{
		printf("删除 L 中最后一个结点，用 p 接收删除的结点...\n");
		Remove_E(&L, &p);
		printf(" L 中的元素为：L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
		
	printf("▼6\n▲函数 InsFirst_E 测试...\n");			//6.函数InsFirst_E测试
	{
		printf("创建值为 303 的结点 p ...\n");
		MakeNode_E(&p, 303);
		printf("令 q 指向 L 中第 4 个元素...\n");
		LocatePos_E(L, 4, &q);
		printf("将 p 结点插入到以 q 作头结点的链表的第一个结点之前...\n");
		InsFirst_E(&L, q, p);
		printf(" L 中的元素为：L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("▼7\n▲函数 DelFirst_E 测试...\n");			//7.函数DelFirst_E测试
	{
		printf("删除 L 中以第4个结点 q 为头结点的链表的第一个结点...\n");
		DelFirst_E(&L, q, &p);
		printf("当前 L 的值为：L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;

	printf("▼16\n▲函数 GetHead_E 测试...\n");			//16.函数GetHead_E测试
	{
		p = GetHead_E(L);
		printf(" L 头指针为 p = L.head = 0x%x \n", p);
		printf("\n");
	} 
	PressEnter;

	printf("▼17\n▲函数 GetLast_E 测试...\n");			//17.函数GetLast_E测试
	{
		q = GetLast_E(L);
		printf(" L 尾指针为 q = L.tail = 0x%x \n", q);	
		printf("\n");
	} 
	PressEnter;
			
	printf("▼10\n▲函数 InsBefore_E 测试...\n");		//10.函数InsBefore_E测试
	{			
		printf("创建值为 404 的结点 s ...\n");						
		MakeNode_E(&s, 404);
		printf("将结点 s 插入到尾结点 q 之前...\n");
		InsBefore(&L, &q, s);
		printf("当前 L 的值为：L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
		
	printf("▼11\n▲函数 InsAfter_E 测试...\n");		//11.函数InsAfter_E测试
	{	
		printf("创建值为 505 的结点 s ...\n");						
		MakeNode_E(&s, 505);
		printf("将结点 s 插入到头结点 p 之后...\n");
		InsAfter(&L, &p, s);
		printf(" L 中的元素为：L = ");			 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("▼4\n▲函数 ClearList_E 测试...\n");		//4.函数ClearList_E测试
	{
		printf("清空 L 前：");
		ListEmpty_E(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		ClearList_E(&L);
		printf("清空 L 后：");
		ListEmpty_E(L) ? printf(" L 为空！！\n") : printf(" L 不为空！\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("▼5\n▲函数 DestroyList_E 测试...\n");		//5.函数DestroyList_E测试
	{
		printf("销毁 L 前：");
		L.head!=NULL && L.tail!=NULL ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
		DestroyList_E(&L);
		printf("销毁 L 后：");
		L.head!=NULL && L.tail!=NULL ? printf(" L 存在！\n") : printf(" L 不存在！！\n");
		printf("\n");
	} 
	PressEnter;
	
	return 0; 
}

Status CmpGreater(LElemType_E e, LElemType_E data)
{
	return data>e ? TRUE : FALSE;
}

void PrintElem(LElemType_E e)
{
	printf("%d ", e);
}
