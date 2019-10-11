/******************************************
 *						                  *
 * 文件夹: ▲09 查找                      *
 * 						                  *
 * 文件名: NearlyOptimalSearchTree-main.c *
 * 							              *
 * 内  容: 次优查找树相关函数测试         *
 *                                        *
 ******************************************/

#include <stdio.h>
#include "NearlyOptimalSearchTree.c" 		//**▲09 查找**//

/* 宏定义 */
#define Max 9								//查找表中元素个数 

void Print(ElemType_Search e);		//输出有序表中的关键字和其他域 

int main(int argc, char *argv[])
{		
	Table T;
	SOSTree BT;
		
	printf("创建并输出一个查找表...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, Print);	
	}	
	PressEnter; 
	
	printf("▼1、2、3、4\n▲函数 CreateSOSTree等 测试...\n");	//1、2、3、4.函数CreateSOSTree等测试		
	{
		printf("构造并展示次优查找树：\n");
		CreateSOSTree(&BT, T);
		PrintTree(BT);
		printf("\n");
	}	
	PressEnter; 

	printf("▼5\n▲函数 Search_SOST 测试...\n");				//5.函数Search_SOST测试		
	{
		printf("关键字 %c ", ch[3]);
		Search_SOST(BT, 3) ? printf("在") : printf("不在");
		printf("次优查找树中!\n");
		printf("\n");
	}	
	PressEnter; 
	
	return 0;
}

void Print(ElemType_Search e)
{
	printf("(%c, %.1f) ", ch[e.key], e.weight);
}
