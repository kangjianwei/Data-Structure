#include <stdio.h>
#include "../../../▲课本算法实现/▲08 动态存储管理/01 BoundaryTagMethod/BoundaryTagMethod.c"//**▲08 动态存储管理**//

/* 函数原型 */
int Algo_8_13(Space *pav, Space **p);

int main(int argc, char *argv[])
{
	WORD_a memory[MAX];
	Space pav, p1, p2, p3;						 
	Space *p;
	
	printf("初始化一个内存块 ：");
	InitSpace_a(memory);
	pav = av;
	PrintLayout_a(av, pav);
	printf("\n");
	
	p1 = AllocBoundTag(&pav, 200);
	p2 = AllocBoundTag(&pav, 200);
	p3 = AllocBoundTag(&pav, 200);
	printf("分别申请大小为 200 的内存块 p1、p2、p3 后...\n");
	PrintLayout_a(av, pav);
	printf("\n");
	
	printf("回收内存块 p2 后...\n");
	p = &p2;
	Algo_8_13(&pav, &p);
	PrintLayout_a(av, pav);
	printf("\n");
			
	return 0;
}

/*━━━━━━━━━━━━━┓
┃题8.13：边界标志法回收算法┃
┗━━━━━━━━━━━━━*/
int Algo_8_13(Space *pav, Space **p)
{
	Reclaim_a(pav, *p);		//已定义 
}
