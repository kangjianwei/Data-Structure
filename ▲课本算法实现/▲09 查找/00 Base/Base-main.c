 /*****************************
 *                            *
 * 文件夹: ▲09 查找          *
 *                            *
 * 文件名: Base-main.c        *
 *                            *
 * 内  容: 查找表相关函数测试 *
 *                            *
 ******************************/

#include <stdio.h>
#include "Base.c" 									//**▲09 查找**//

/* 宏定义 */
#define Max 10										//查找表中元素个数 

void Print(ElemType_Search e);
	//输出有序表中的关键字和其他域 
	
int main(int argc, char *argv[])
{	
	FILE *fp;
	Table T;

	printf("▼1\n▲函数 Create 测试...\n");			//1.函数Create测试			
	printf("创建一个查找表...\n");
	fp = fopen("TestData_Table.txt", "r");	
	Create(fp, &T, Max);
	printf("\n");	
	PressEnter;	

	printf("▼3\n▲函数 Traverse 测试...\n");		//3.函数Traverse测试			
	printf("输出查找表信息...\n");		
	Traverse(T, Print);	
	printf("\n");	
	PressEnter;
	
	printf("▼4\n▲函数 PrintKey 测试...\n");		//4.函数PrintKey测试			
	printf("输出查找表关键字...\n");		
	Traverse(T, PrintKey);	
	printf("\n");	
	PressEnter;

	printf("▼2\n▲函数 DeTory 测试...\n");			//2.函数DeTory测试
	printf("销毁有序表...\n");
	Destory(&T);
	printf("有序表");
	T.elem==NULL&&T.length==0 ? printf("已被") : printf("未被");
	printf("销毁！\n");		
	printf("\n");	
	PressEnter;

	return 0;
}

void Print(ElemType_Search e)
{
	printf("(%3d, %.1f) ", e.key, e.weight);
}
