#include <stdio.h>
#include <stdlib.h>								//提供malloc、realloc、free、exit原型
#include "../../../▲课本算法实现/▲01 绪论/Status.h"	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲06 树和二叉树/06 ChildTree/ChildTree.c" //**▲06 数和二叉树**//

/* 全局变量 */
CTree H;								//自动初始化，默认根结点在0号单元 

/* 函数原型 */
void Algo_6_75(FILE *fp, int parent);
void Algo_6_76_1(CTree H, int i);
void Algo_6_76_2(CTree H, int i);

int main(int argc, char *argv[])
{
	FILE *fp; 

	printf("题 6.75 验证...\n");	
	printf("作为示例，录入序列：A(B(E,F),C(G),D)...\n");
	printf("创建孩子-兄弟链表...\n");
	fp = fopen("Data/Algo_6_75-6.76.txt", "r");
	Algo_6_75(fp, -1);
	fclose(fp);
	Print_C_2(H, H.r, 0);
	printf("\n");

	printf("题 6.76 验证...\n");	
	printf("按广义表打印孩子链表...\n");
	printf("方法 1 ：");
	Algo_6_76_1(H, H.r);
	printf("\n");
	printf("方法 2 ：");
	Algo_6_76_2(H, H.r);
	printf("\n\n");
			
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━┓
┃题6.75：创建孩子链表(并未考虑双亲结点)┃
┗━━━━━━━━━━━━━━━━━━━*/
void Algo_6_75(FILE *fp, int parent)	//parent标记当前位置结点的双亲结点位置 
{										//即将创建的树设为全局变量，
	char c;	
	ChildPtr p, q;
	
	while(1)
	{	
		Scanf(fp, "%c", &c);
		if(feof(fp))
			break;

		if(c>='A' && c<='Z')
		{
			H.nodes[H.n].data = c;		//H.n用来追踪结点个数			
						
			if(parent!=-1)
			{
				p = (ChildPtr)malloc(sizeof(CTNode));
				p->child = H.n;
				p->next = NULL;
			
				q = H.nodes[parent].firstchild;
				if(!q)
					H.nodes[parent].firstchild = p;
				else
				{			
					while(q->next)
						q = q->next;
					q->next = p;			
				}			
			}

			H.n++;
		}
		else if(c=='(')
			Algo_6_75(fp, H.n-1);		//第一个孩子
		else if(c==',')					//创建兄弟结点 
		{
			Algo_6_75(fp, parent);
			break;		
		}
		else
			break;			
	}
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题6.76：按广义表方式打印孩子链表(并未考虑双亲结点)┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/
/* 方法1 */
void Algo_6_76_1(CTree H, int i)
{
	ChildPtr p;

	if(H.n)
	{
		printf("%c", H.nodes[i].data);		//打印双亲结点 
		
		if(H.nodes[i].firstchild)	
		{
			printf("(");

			p = H.nodes[i].firstchild;
			
			while(p)						//打印各孩子结点 
			{
				Algo_6_76_1(H, p->child);
				p = p->next;				//遍历各孩子 
				if(p)
					printf(",");
				else
					printf(")");
			}		
		}			
	}
}

/* 方法2：改变了循环方式 */
void Algo_6_76_2(CTree H, int i)
{
	ChildPtr p;

	if(H.n)
	{
		printf("%c", H.nodes[i].data);					//打印双亲结点 
		
		if(H.nodes[i].firstchild)	
		{
			printf("(");
			
			for(p=H.nodes[i].firstchild; p; p=p->next)	//边遍历边打印 
			{
				Algo_6_76_2(H, p->child);
				if(p->next)
					printf(",");
			}
			
			printf(")");			
		}			
	}
}
