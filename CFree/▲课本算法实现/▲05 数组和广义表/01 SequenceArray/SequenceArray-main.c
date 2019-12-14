/**********************************************
 *                                            *
 * 文件夹: ▲05 数组和广义表\01 SequenceArray *
 *                                            *
 * 内  容: 数组相关函数测试                   *
 *                                            *
 **********************************************/

#include <stdio.h> 
#include "SequenceArray.c" 						//**▲05 数组和广义表**//

/* 以二维数组为例测试 */
int main(int argc, char **argv)
{
	Array A;
	
	printf("▼1\n▲函数 InitArray 测试（以二维数组为例）...\n");//1.函数InitArray测试
	{
		printf("初始化一个 2 行 3 列的二维数组 A ...\n");					 
		InitArray(&A, 2, 2, 3);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼5\n▲函数 AssignArray 测试...\n");				//5.函数AssignArray测试
	{
		int i, j;
		AElemType_Sq e = 0;
		
		for(i=0; i<A.bounds[0]; i++)
		{
			for(j=0; j<A.bounds[1]; j++)
			{
				printf("赋值：A[%d][%d] = %d\n", i, j, ++e);
				AssignArray(&A, e, i, j);
			}
		}				
		printf("\n");
	} 
	PressEnter;
	
	printf("▼6\n▲函数 ArrayPrint 测试...\n");					//6.函数ArrayPrint测试
	{
		printf(" A = ");
		ArrayPrint(A); 
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼3、4\n▲函数 LocateArray、ValueArray 测试...\n");	//3、4.函数LocateArray、ValueArray测试
	{
		AElemType_Sq x;
		
		printf("获取 A 中下标为 (1,1) 的元素的值，Locate 用于求出 A[1][1] 的相对位置...\n");
		ValueArray(A, &x, 1, 1);
		printf(" A[1][1] = %d\n", x);
		printf("\n");
	} 
	PressEnter;
		
	printf("▼2\n▲函数 DestroyArray 测试...\n");				//2.函数DestroyArray测试
	{
		printf("销毁 A 前：");
		A.dim!=0 ? printf(" A 存在！\n") : printf(" A 不存在！！\n"); 					 
		DestroyArray(&A); 
		printf("销毁 A 后：");
		A.dim!=0 ? printf(" A 存在！\n") : printf(" A 不存在！！\n");
		printf("\n");
	} 
	PressEnter;
		
	return 0;
}
