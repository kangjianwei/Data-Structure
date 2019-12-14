#include <stdio.h>
#include "../../../▲课本算法实现/▲08 动态存储管理/04 StorageCompacting/StorageCompacting.c"//**▲08 动态存储管理**//

/* 函数原型 */
int Algo_8_16();

int main(int argc, char *argv[])
{
	char *p1, *p2, *p3;
	int k;
	
	printf("初始化一块大小为 %d 的内存...\n", 300);
	InitMemory(300);	
	printf("\n");
	
	printf("分别申请大小为 %d 的内存块 p1、p2、p3...\n", 100*sizeof(char));		
	p1 = (char*)MallocMemory(100*sizeof(char));	
	p2 = (char*)MallocMemory(100*sizeof(char));	
	p3 = (char*)MallocMemory(100*sizeof(char));	
	PrintLayout();
	printf("\n");
	
	printf("释放 p2 指向的内存块...\n");
	FreeMemory(p2);
	PrintLayout();
	printf("\n");

	printf("紧缩存储之后...\n");
	Algo_8_16();
	PrintLayout();
	printf("\n");
			
	return 0;
}

/*━━━━━━━━━━┓
┃题8.16：存储紧缩算法┃
┗━━━━━━━━━━*/
int Algo_8_16()
{
	return CompressMemory();		//已定义 
}
