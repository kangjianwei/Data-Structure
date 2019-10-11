/***************************************
 *							           *
 * 文件夹: ▲06 树和二叉树\10 PowerSet *
 * 						               *
 * 文件名: PowerSet-main.c             *
 * 					    	           *
 * 内  容: 幂集相关函数测试            *
 *                                     *
 ***************************************/

#include <stdio.h>
#include "PowerSet.c" 									//**▲06 树和二叉树**//															

int main(int argc, char *argv[])
{
	LinkList A;
	
	printf("▼1\n▲函数 CreatePowerSet_PS 测试...\n");	//1.函数CreatePowerSet_PS测试
	{
		FILE *fp;
		
		printf("创建集合 A ...\n");	
		fp = fopen("TestData_A.txt", "r");
		CreatePowerSet_PS(fp, &A);
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("▼3\n▲函数 Output_PS 测试...\n");			//3.函数Output_PS测试
	{
		printf("输出集合 A = ");	
		Output_PS(A); 
		printf("\n");
	}
	PressEnter;

	printf("▼2\n▲函数 GetPowerSet_PS 测试...\n");		//2.函数GetPowerSet_PS测试
	{
		LinkList B;
		
		printf("计算集合的幂集...\n");	
		printf("创建集合 B 临时存储幂集元素...\n");
		InitList_L(&B);
		printf("依次输出求取的幂集中的各子集...\n");
		GetPowerSet_PS(1, A, B);
		printf("\n");
	}
	PressEnter;
}
