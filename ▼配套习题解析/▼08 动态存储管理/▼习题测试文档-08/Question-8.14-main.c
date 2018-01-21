#include <stdio.h>
#include "../../../▲课本算法实现/▲08 动态存储管理/02 BuddySystem/BuddySystem.c"//**▲08 动态存储管理**//

/* 函数原型 */
void Algo_8_14(FreeList avail, WORD_b **p);

int main(int argc, char *argv[])
{
	FreeList avail;
	WORD_b *p;

	printf("初始化一个内存块 ：");	
	InitSpace_b(avail);
	PrintLayout_b(avail);
	printf("\n");

	printf("申请大小为 1 的内存块 p 后...\n");	
	p = AllocBuddy(avail, 1);
	PrintLayout_b(avail);
	printf("\n");

	printf("回收内存块 p 后...\n");	
	Algo_8_14(avail, &p);
	PrintLayout_b(avail);
	printf("\n");
				
	return 0;
}

/*━━━━━━━━━━━━━━┓
┃题8.14：伙伴管理系统回收算法┃
┗━━━━━━━━━━━━━━*/
void Algo_8_14(FreeList avail, WORD_b **p)
{
	Reclaim_b(avail, p);		//已定义 
}
