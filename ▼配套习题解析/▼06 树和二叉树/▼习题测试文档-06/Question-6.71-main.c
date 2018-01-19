#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/07 ChildSiblingTree/ChildSiblingTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
void Algo_6_71_1(CSTree T, int i);
void Algo_6_71_2(CSTree T, int i);

int main(int argc, char *argv[])
{
	CSTree T;
	FILE *fp; 

	printf("输入先序序列：ABE^F^^CG^^D^^^...\n");
	InitTree_CS(&T);
	fp = fopen("Data/Algo_6_71.txt", "r");
	CreateTree_CS(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("树T为：\n");
	Print_CS(T);
	printf("\n");
	
	printf("方法 1：先序遍历按凹入表打印树：\n");
	Algo_6_71_1(T, 0);
	printf("\n");

	printf("方法 2：先序遍历按凹入表打印树：\n");
	Algo_6_71_2(T, 0);
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━┓
┃题6.71：先序遍历按凹入表打印树┃
┗━━━━━━━━━━━━━━━*/
/* 方法1：直接使用递归 */
void Algo_6_71_1(CSTree T, int i)			//i初始设为0 
{
	int j;
	
	if(T)
	{
		for(j=1; j<=2*i; j++)
			printf(" ");		
		printf("%c\n", T->data);
		
		Algo_6_71_1(T->firstchild, i+1);
		Algo_6_71_1(T->nextsibling, i);		//此处为i 
	}
}

/* 方法2：在循环中使用递归 */
void Algo_6_71_2(CSTree T, int i)
{
	int j;
	CSTree p;
	
	if(T)
	{
		for(j=1; j<=2*i; j++)
			printf(" ");		
		printf("%c\n", T->data);
		
		for(p=T->firstchild; p; p=p->nextsibling)
			Algo_6_71_2(p, i+1);	
	}
}
