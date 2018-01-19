#include <stdio.h>
#include <stdlib.h>								//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/02 BinaryTree/BinaryTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
Status Algo_6_70(FILE *fp, BiTree *T);

int main(int argc, char *argv[])
{
	BiTree T;
	FILE *fp;
	
	printf("作为示例录入序列（大写字母）：A(B(#,D),C(E(#,F),#))...\n");
	fp = fopen("Data/Algo_6_70.txt", "r");
	Algo_6_70(fp, &T);
	fclose(fp);
	printf("\n");
	
	printf("展示创建的树：\n");
	PrintTree(T);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━┓
┃题6.70：创建二叉树的二叉链表结构┃
┗━━━━━━━━━━━━━━━━*/
Status Algo_6_70(FILE *fp, BiTree *T)
{
	char c;
	
	while(1)
	{
		Scanf(fp, "%c", &c);
		if(feof(fp))								//字符读取完毕 
			break;
		
		if(c=='#')
			*T = NULL;			
		else if(c>='A' && c<='Z')
		{
			*T = (BiTree)malloc(sizeof(BiTNode));	//根结点 
			if(!(*T))
				exit(OVERFLOW);
			(*T)->data = c;
			(*T)->lchild = (*T)->rchild = NULL;
		}
		else if(c=='(')
		{
			Algo_6_70(fp, &(*T)->lchild);
			Algo_6_70(fp, &(*T)->rchild);
		}
		else
			break;				
	}
	
	return OK;
}
