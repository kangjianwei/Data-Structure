#include <stdio.h>
#include <stdlib.h>								//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/07 ChildSiblingTree/ChildSiblingTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
Status Algo_6_73(FILE *fp, CSTree *T);
void Algo_6_74(CSTree T);

int main(int argc, char *argv[])
{
	CSTree T;
	FILE *fp; 
		
	printf("███ 题 6.73 验证... ███\n");
	printf("作为示例，录入序列：A(B(E,F),C(G),D)...\n");
	printf("创建孩子-兄弟链表...\n");
	fp = fopen("Data/Algo_6_73-6.74.txt", "r");
	Algo_6_73(fp, &T);
	fclose(fp);
	Print_CS(T);
	printf("\n");

	printf("███ 题 6.74 验证... ███\n");	
	printf("按广义表打印孩子-兄弟链表...\n");
	Algo_6_74(T);
	printf("\n\n");	
		
	return 0;
}

/*━━━━━━━━━━━━━┓
┃题6.73：创建孩子-兄弟链表 ┃
┗━━━━━━━━━━━━━*/
Status Algo_6_73(FILE *fp, CSTree *T)
{	
	char c;
	
	while(1)
	{
		Scanf(fp, "%c", &c);
		if(feof(fp))
			break;
	
		if(c>='A' && c<='Z')
		{
			*T = (CSTree)malloc(sizeof(CSNode));	//根结点 
			if(!(*T))
				exit(OVERFLOW);
			(*T)->data = c;
			(*T)->firstchild = (*T)->nextsibling = NULL;
		}
		else if(c=='(')
			Algo_6_73(fp, &(*T)->firstchild);
		else if(c==',')
		{
			Algo_6_73(fp, &(*T)->nextsibling);		
			break;									//注意此处应该返回 
		}
		else
			break;				
	}
	
	return OK;
}

/*━━━━━━━━━━━━━━━━━━━┓
┃题6.74：按广义表方式打印孩子-兄弟链表 ┃
┗━━━━━━━━━━━━━━━━━━━*/
void Algo_6_74(CSTree T)
{
	int i;
	CSTree p;
	
	if(T)
	{
		printf("%c", T->data);
		
		if(T->firstchild)
		{
			printf("(");
			
			for(p=T->firstchild; p; p=p->nextsibling)
			{
				Algo_6_74(p);
				if(p->nextsibling)				//若不是最后一个兄弟，加"," 
					printf(",");
			}
			
			printf(")");
		}
	} 
}
