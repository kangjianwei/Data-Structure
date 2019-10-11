#include <stdio.h>
#include <stdlib.h>										//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/07 ChildSiblingTree/ChildSiblingTree.c" //**▲06 数和二叉树**//

/* 函数原型 */
void Algo_6_67(FILE *fp, CSTree *T);

int main(int argc, char *argv[])
{
	CSTree T;
	FILE *fp;

	fp = fopen("Data/Algo_6_67.txt", "r");	
	Algo_6_67(fp, &T); 
	fclose(fp);
	printf("\n");
	
	printf("创建的孩子兄弟二叉树为：\n");
	Print_CS(T);
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━┓
┃ 题6.67：创建树的孩子-兄弟结构┃
┗━━━━━━━━━━━━━━━*/
void Algo_6_67(FILE *fp, CSTree *T)
{
	char input[3];
	CSTree tmp[100]; 								//顺序存储遇到的每个结点
	CSTree p, q;
	int m, n, count;
	
	m = n = 0;
	count = 0;
	while(1)
	{
		printf("录入第 %d 个二元组：", ++count);
		Scanf(fp, "%s", input); 
		printf("%s\n", input);
		
		if(input[1]=='^')							//退出标志 
			break;
		else
		{
			p = (CSTree)malloc(sizeof(CSNode));
			if(!p)
				exit(OVERFLOW);
			p->data = input[1];
			p->firstchild = p->nextsibling = NULL;
			
			if(input[0]=='^')						//根结点   
				*T = p;
			else
			{
				while(tmp[m]->data!=input[0])
					m++;

				if(tmp[m]->firstchild==NULL)		//作为第一个孩子 
					tmp[m]->firstchild = p;
				else
				{
					q = tmp[m]->firstchild;			//寻找孩子链表的末端 
					while(q->nextsibling)
						q = q->nextsibling;
					q->nextsibling = p;
				}							
			}			
						
			tmp[n++] = p;			
		}
	}
}
