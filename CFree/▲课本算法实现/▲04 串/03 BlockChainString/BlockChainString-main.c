/***************************************
 *                                     *
 * 文件夹: ▲04 串\03 BlockChainString *
 *                                     *
 * 内  容: 块链串相关函数测试          *
 *                                     *
 ***************************************/

#include <stdio.h>
#include "BlockChainString.c" 							//**▲04 串**//

int main(int argc, char **argv)
{
	char *chars = "kuai-lian-chuan";
	char *t = "***";
	char *v = "^^^^";
	LString S, Tmp, T, V, Sub;
	int i;
	
	printf("▼1\n▲函数 InitString_L 测试...\n");		//1.函数InitString_L测试
	{
		printf("初始化空串 Tmp ...\n");
		InitString_L(&Tmp);
		printf("\n");
	}
	PressEnter;
	
	printf("▼2\n▲函数 StrAssign_L 测试...\n");		//2.函数StrAssign_L测试
	{
		printf("为 Tmp 赋值 %s ...\n", chars);					 
		StrAssign_L(&Tmp, chars);
		printf("\n");
	}
	PressEnter;
	
	printf("▼4\n▲函数 StrEmpty_L 测试...\n");			//4.函数StrEmpty_L测试
	{
		StrEmpty_L(Tmp) ? printf(" Tmp 为空！！\n") : printf(" Tmp 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼6\n▲函数 StrLength_L 测试...\n");		//6.函数StrLength_L测试
	{
		i = StrLength_L(Tmp);
		printf(" Tmp 的长度为 %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("▼15\n▲函数 StrPrint_L 测试...\n");		//15.函数StrPrint_L测试
	{
		printf(" Tmp 中的元素为：Tmp = ");						 
		StrPrint_L(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼3\n▲函数 StrCopy_L 测试...\n");			//3.函数StrCopy_L测试
	{
		printf("复制 Tmp 到 S ...\n");
		StrCopy_L(&S, Tmp);
		printf(" S 中的元素为：S = ");						 
		StrPrint_L(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼5\n▲函数 StrCompare_L 测试...\n");		//5.函数StrCompare_L测试
	{
		printf("比较字符串 Tmp 、 S ...\n");
		i = StrCompare_L(Tmp, S);
		i==0 ? printf("Tmp==S！！\n") : (i<0 ? printf("Tmp<S！！\n") : printf("Tmp>S！！\n"));
		printf("\n");
	}
	PressEnter;
	
	printf("▼12\n▲函数 StrInsert_L 测试...\n");		//12.函数StrInsert_L测试
	{
		printf("将 \"***\" 赋给 T ...\n");
		StrAssign_L(&T, t);
		printf("在 S 的第 5 个字符前插入 T ...\n");
		StrInsert_L(&S, 5, T);
		printf(" S 中的元素为：S = ");						 
		StrPrint_L(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼10\n▲函数 Index_L 测试...\n");			//10.函数Index_L测试
	{
		printf("获取字符串 \"***\" 在 S 中从第 1 个字符算起的第一次出现的位置...\n");
		i = Index_L(S, T, 1);
		printf(" \"***\" 在 S 中第 1 个字符后第一次出现的位置为 %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("▼9\n▲函数 SubString_L 测试...\n");		//9.函数SubString_L测试
	{
		printf("用 Sub 返回S中第 5 个字符起的 3 个字符...\n");
		SubString_L(&Sub, S, 5, 3);
		printf(" Sub 中的元素为：Sub = ");						 
		StrPrint_L(Sub);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼11\n▲函数 Replace_L 测试...\n");			//11.函数Replace_L测试
	{
		printf("将 \"^^^^\" 赋给 V ...\n");
		StrAssign_L(&V, v);
		printf("用 \"^^^^\" 替换 S 中的 \"***\" ...\n");
		Replace_L(&S, T, V);
		printf(" S 中的元素为：S = ");						 
		StrPrint_L(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼13\n▲函数 StrDelete_L 测试...\n");		//13.函数StrDelete_L测试
	{
		printf("删除 S 中第 5 个字符起的 4 个字符...\n");
		StrDelete_L(&S, 5, 4); 
		printf(" S 中的元素为：S = ");						 
		StrPrint_L(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼7\n▲函数 ClearString_L 测试...\n");		//7.函数ClearString_L测试
	{
		printf("清空 S 前：");
		StrEmpty_L(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		ClearString_L(&S);
		printf("清空 S 后：");
		StrEmpty_L(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼8\n▲函数 Concat_L 测试...\n");			//8.函数Concat_L测试
	{
		printf("联接 T 和 V 形成 Tmp ...\n");
		Concat_L(&Tmp, T, V);
		printf(" Tmp 中的元素为：Tmp = ");						 
		StrPrint_L(Tmp);
		printf("\n\n");
	}
	PressEnter;

	return 0;
}
