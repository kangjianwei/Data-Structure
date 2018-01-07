/****************************************
 *						                *
 * 文件夹: ▲06 树和二叉树\08 MFSet     *
 * 						                *
 * 文件名: MFSet-main.c                 *
 * 							            *
 * 内  容: 并查集（等价类）相关函数测试 *
 *                                      *
 ****************************************/

#include <stdio.h> 
#include "MFSet.c" 						//**▲06 树和二叉树**//

int main(int argc, char *argv[])
{
	FILE *fp;
	MFSet S;
		
	printf("▼1\n▲函数 Initial_mfset 测试...\n");		//1.函数Initial_mfset测试
	{
		printf("初始化集合（作为示范录入 10 个元素）...\n");
		fp = fopen("TestData_S.txt", "r");
		Initial_mfset(fp, &S);
		fclose(fp);
		printf("初始化完成，现集合中非空子集均只包含单个元素...\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼8、9\n▲函数 ShowSet_mfset等 测试...\n");	//8、9.函数ShowSet_mfset、SubsetCount_mfset测试
	{
		printf("展示集合 S = ");
		ShowSet_mfset(S);
		printf("\n");
	}
	PressEnter;
	
	printf("▼2、3、6、7-1\n▲函数 EquivalenceClass_mfset_1等 测试...\n");
	{													//2、3、6、7-1.函数find_mfset、merge_mfset、BuildRelation_mfset、EquivalenceClass_mfset_1测试
		Relation R1;
		
		printf("根据等价关系建立等价类...\n");
		printf("作为示范录入4个二元关系如：{(1,2),(3,4),(5,6),(7,9)}...\n");
		fp = fopen("TestData_R1.txt", "r");
		BuildRelation_mfset(fp, &R1); 
		fclose(fp);
		EquivalenceClass_mfset_1(&S, R1);
		printf("展示等价类 S = ");
		ShowSet_mfset(S);
		printf("\n");
	}
	PressEnter;
	
	printf("▼4、5、6、7-2\n▲函数 EquivalenceClass_mfset_2等 测试...\n");
	{													//4、5、6、7-2.函数fix_mfset、mix_mfset、BuildRelation_mfset、EquivalenceClass_mfset_2测试
		Relation R2;
		
		printf("根据某集合的等价关系建立其等价类...\n");
		printf("作为示范录入2个二元关系如：{(1,3),(5,7)}...\n");
		fp = fopen("TestData_R2.txt", "r");
		BuildRelation_mfset(fp, &R2);
		fclose(fp);
		EquivalenceClass_mfset_2(&S, R2);
		printf("展示等价类 S = ");
		ShowSet_mfset(S);
		printf("\n");
	}
	PressEnter;
}
