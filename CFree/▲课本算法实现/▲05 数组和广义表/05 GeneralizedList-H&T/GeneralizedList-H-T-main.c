/****************************************************
 *						                            *
 * 文件夹: ▲05 数组和广义表\05 GeneralizedList-H&T *
 * 						                            *
 * 内  容: 广义表（头尾链表存储）相关函数测试       *
 *                                                  *
 ****************************************************/

#include <stdio.h> 
#include "GeneralizedList-H-T.c"		//**▲05 数组和广义表**//

void PrintElem(AtomType e);				//打印广义表原子 

int main(int argc, char **argv)
{
	GList Tmp, G;
	GList g1, g2, g3;
	SString S1, S2, S3;
	 
	printf("▼1\n▲函数 InitGList_GL_H_T 测试...\n");			//1.函数InitGList_GL_H_T测试
	{
		printf("创建空的广义表 Tmp ...\n");
		InitGList_GL_H_T(&Tmp);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼8\n▲函数 GListEmpty_GL_H_T 测试...\n");			//8.函数GListEmpty_GL_H_T测试
	{
		int tag;
		
		tag = GListEmpty_GL_H_T(Tmp);
		tag ? printf(" Tmp 为空！\n") : printf(" Tmp 不为空！！\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("▼2-1、3-1、2-2、3-2\n▲函数 sever_GL_H_T_1、CreateGList_GL_H_T_1等 测试...\n");
	{															//2-1、3-1、2-2、3-2.函数sever_GL_H_T_1、CreateGList_GL_H_T_1等测试
		char *s1 = "()";
		char *s2 = "(e)";
		char *s3 = "(a,(b,c,d))";
		
		printf("创建广义表S1、S2、S3...\n");
		StrAssign_Sq(S1, s1);
		CreateGList_GL_H_T_1(&g1, S1);
		StrAssign_Sq(S2, s2);
		CreateGList_GL_H_T_1(&g2, S2);
		StrAssign_Sq(S3, s3);
		CreateGList_GL_H_T_2(&g3, S3);
		printf("\n");
	}
	PressEnter;
		
	printf("▼11\n▲函数 InsertFirst_GL_H_T 测试...\n");		//11.函数InsertFirst_GL_H_T测试		
	{
		printf("将 S3、S2、S1 依次插入到 Tmp 的首个位置...\n");
		InsertFirst_GL_H_T(&Tmp, g3); 
		InsertFirst_GL_H_T(&Tmp, g2);
		InsertFirst_GL_H_T(&Tmp, g1);
		printf("\n");
	}
	PressEnter;
	
	printf("▼13\n▲函数 Traverse_GL_H_T 测试...\n");			//13.函数Traverse_GL_H_T测试
	{
		printf("输出广义表中原子 Tmp = ");
		Traverse_GL_H_T(Tmp, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼14\n▲函数 Output_GL_H_T 测试...\n");				//14.函数Output_GL_H_T测试
	{
		printf("带括号输出广义表 Tmp = ");
		Output_GL_H_T(Tmp, Head);
		printf("\n\n");
	} 
	PressEnter;

	printf("▼5\n▲函数 CopyGList_GL_H_T 测试...\n");			//5.函数CopyGList_GL_H_T测试
	{
		printf("复制 Tmp 到 G = ");
		CopyGList_GL_H_T(&G, Tmp);
		Output_GL_H_T(G, Head);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼12\n▲函数 DeleteFirst_GL_H_T 测试...\n");		//12.函数DeleteFirst_GL_H_T测试
	{
		GList h;
		
		printf("删除广义表 Tmp 的表头：");
		DeleteFirst_GL_H_T(&Tmp, &h);
		Output_GL_H_T(h, Head);
		printf("\n");
		printf(" Tmp = ");
		Output_GL_H_T(Tmp, Head);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("▼6\n▲函数 GListLength_GL_H_T 测试...\n");			//6.函数GListLength_GL_H_T测试
	{
		printf("广义表 G 的长度为： %d \n", GListLength_GL_H_T(G));
		printf("\n");
	} 
	PressEnter;
	
	printf("▼7\n▲函数 GListDepth_GL_H_T 测试...\n");			//7.函数GListDepth_GL_H_T测试
	{
		printf("广义表 G 的深度为： %d\n", GListDepth_GL_H_T(G));
		printf("\n");
	} 
	PressEnter;
	
	printf("▼9\n▲函数 GetHead_GL_H_T 测试...\n");				//9.函数GetHead_GL_H_T测试
	{
		GList H;
		
		printf("广义表 G 的表头 H = ");
		H = GetHead_GL_H_T(G);
		Output_GL_H_T(H, Head);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("▼10\n▲函数 GetTail_GL_H_T 测试...\n");			//10.函数GetTail_GL_H_T测试
	{
		GList T;
		
		printf("广义表 G 的表尾 T = ");
		T = GetTail_GL_H_T(G);
		Output_GL_H_T(T, Head);
		printf("\n\n");
	}
	PressEnter;
		
	printf("▼4\n▲函数 ClearGList_GL_H_T 测试...\n");			//4.函数ClearGList_GL_H_T测试
	{
		printf("销毁 G 前：");
		G ? printf(" G 存在！\n") : printf(" G 不存在！！\n");
		ClearGList_GL_H_T(&G);
		printf("销毁 G 后：");
		G ? printf(" G 存在！\n") : printf(" G 不存在！！\n");
		printf("\n");
	}
	PressEnter;

	return 0;
}

void PrintElem(AtomType e)
{
	printf("%d ", e);
}
