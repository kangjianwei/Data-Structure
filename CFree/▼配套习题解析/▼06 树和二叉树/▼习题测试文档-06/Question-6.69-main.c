#include <stdio.h>
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
void Algo_6_69(BiTree T, int i);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("创建二叉树（先序序列）T→ AB^D^^CE^F^^^...\n");
	InitBiTree(&T);
	fp = fopen("Data/Algo_6_69.txt", "r");
	CreateBiTree(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("二叉树T为：\n");
	PrintTree(T);
	printf("\n");
	
	printf("逆中序序列且按层序打印树：\n");
	Algo_6_69(T, 0);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━┓
┃题6.69：逆中序序列且按层序打印树┃
┗━━━━━━━━━━━━━━━━*/
void Algo_6_69(BiTree T, int i)			//i代表相对根结点走了几步，隐含了层序信息 
{
	int j;
	
	if(T)
	{
		Algo_6_69(T->rchild, i+1);		//先访问右子树 
		
		for(j=1; j<=2*i; j++)			//i乘以2是为了输出效果美观，实际空格数减半 
			printf(" ");
		printf("%c\n", T->data);
		
		Algo_6_69(T->lchild, i+1);		//最后访问左子树 
	}
}
