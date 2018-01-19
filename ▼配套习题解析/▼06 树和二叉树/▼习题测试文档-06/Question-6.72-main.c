#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/06 ChildTree/ChildTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
void Algo_6_72_1(CTree T, int order, int i);
void Algo_6_72_2(CTree T, int order, int i);

int main(int argc, char *argv[])
{
	CTree T;
	FILE *fp;

	fp = fopen("Data/Algo_6_72.txt", "r");	
	InitTree_C(fp, &T); 
	CreateTree_C(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("树T为：\n");
	Print_C_1(T);
	printf("\n");
	
	printf("先序遍历按凹入表打印树：\n");
	Algo_6_72_1(T, T.r, 0);
	printf("\n");

	printf("先序遍历按凹入表打印树：\n");
	Algo_6_72_2(T, T.r, 0);
	printf("\n");
		
	return 0;
}

/*━━━━━━━━━━━━━━━┓
┃题6.72：先序遍历按凹入表打印树┃
┗━━━━━━━━━━━━━━━*/
/* 方法1：直接使用递归 */
void Algo_6_72_1(CTree T, int order, int i)			//i初始设为0 
{
	int j, k;
	
	if(T.n)
	{
		for(j=1; j<=2*i; j++)
			printf(" ");		
		printf("%c\n", T.nodes[order].data);
		
		if(T.nodes[order].firstchild)				//访问孩子结点 
			Algo_6_72_1(T, T.nodes[order].firstchild->child, i+1);
		
		k = Sibling_C_2(T, order, 1);				//返回结点order的右结点的位置 
		if(k>=0)									//访问右兄弟结点 
			Algo_6_72_1(T, k, i);
	}
}

/* 方法2：在循环中使用递归 */
void Algo_6_72_2(CTree T, int order, int i)			//i初始设为0 
{
	int j, k;
	ChildPtr p;
	
	if(T.n)
	{
		for(j=1; j<=2*i; j++)
			printf(" ");		
		printf("%c\n", T.nodes[order].data);
		
		for(p=T.nodes[order].firstchild; p; p=p->next)
			Algo_6_72_2(T, p->child, i+1);
	}
}
