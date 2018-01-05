/*********************************
 *                               *
 * 文件夹: ▲04 串\02 HeapString *
 *                               *
 * 内  容: 堆串相关函数测试      *
 *                               *
 *********************************/

#include <stdio.h>
#include "HeapString.c" 								//**▲04 串**//

int main(int argc, char **argv)
{
	char *chars = "abcdefg";
	char *t = "***";
	char *v = "^^^^";
	HString S, Tmp, T, V, Sub;
	int i;
	
	printf("▼1\n▲函数 InitString_H 测试...\n");		//1.函数InitString_H测试
	{
		printf("初始化空串 Tmp ...\n");
		InitString_H(&Tmp);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼2\n▲函数 StrAssign_H 测试...\n");		//2.函数StrAssign_H测试
	{
		printf("为 Tmp 赋值 %s ...\n", chars);					 
		StrAssign_H(&Tmp, chars);
		printf("\n");
	}
	PressEnter;
	
	printf("▼4\n▲函数 StrEmpty_H 测试...\n");			//4.函数StrEmpty_H测试
	{
		StrEmpty_H(Tmp) ? printf(" Tmp 为空！！\n") : printf(" Tmp 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼6\n▲函数 StrLength_H 测试...\n");		//6.函数StrLength_H测试
	{
		i = StrLength_H(Tmp);
		printf(" Tmp 的长度为 %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("▼15\n▲函数 StrPrint_H 测试...\n");		//15.函数StrPrint_H测试
	{
		printf(" Tmp 中的元素为：Tmp = ");						 
		StrPrint_H(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼3\n▲函数 StrCopy_H 测试...\n");			//3.函数StrCopy_H测试
	{
		printf("复制 Tmp 到 S ...\n");
		StrCopy_H(&S, Tmp);
		printf(" S 中的元素为：S = ");						 
		StrPrint_H(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼5\n▲函数 StrCompare_H 测试...\n");		//5.函数StrCompare_H测试
	{
		printf("比较字符串 Tmp 、 S ...\n");
		i = StrCompare_H(Tmp, S);
		i==0 ? printf("Tmp==S！！\n") : (i<0 ? printf("Tmp<S！！\n") : printf("Tmp>S！！\n"));
		printf("\n");
	}
	PressEnter;
	
	printf("▼12\n▲函数 StrInsert_H 测试...\n");		//12.函数StrInsert_H测试
	{
		printf("将 \"***\" 赋给 T ...\n");
		StrAssign_H(&T, t);
		printf("在 S 的第 5 个字符前插入 T ...\n");
		StrInsert_H(&S, 5, T);
		printf(" S 中的元素为：S = ");						 
		StrPrint_H(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼10\n▲函数 Index_H 测试...\n");			//10.函数Index_H测试
	{
		printf("获取字符串 \"***\" 在 S 中从第 1 个字符算起的第一次出现的位置...\n");
		i = Index_H(S, T, 1);
		printf(" \"***\" 在 S 中第1个字符后第一次出现的位置为 %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("▼9\n▲函数 SubString_H 测试...\n");		//9.函数SubString_H测试
	{
		printf("用 Sub 返回 S 中第 5 个字符起的 3 个字符...\n");
		SubString_H(&Sub, S, 5, 3);
		printf(" Sub 中的元素为：Sub = ");						 
		StrPrint_H(Sub);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼11\n▲函数 Replace_H 测试...\n");			//11.函数Replace_H测试
	{
		printf("将 \"^^^^\" 赋给 V ...\n");
		StrAssign_H(&V, v);
		printf("用 \"^^^^\" 替换 S 中的 \"***\" ...\n");
		Replace_H(&S, T, V);
		printf(" S 中的元素为：S = ");						 
		StrPrint_H(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼13\n▲函数 StrDelete_H 测试...\n");		//13.函数StrDelete_H测试
	{
		printf("删除 S 中第 5 个字符起的 4 个字符...\n");
		StrDelete_H(&S, 5, 4); 
		printf(" S 中的元素为：S = ");						 
		StrPrint_H(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼7\n▲函数 ClearString_H 测试...\n");		//7.函数ClearString_H测试
	{
		printf("清空 S 前：");
		StrEmpty_H(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		ClearString_H(&S);
		printf("清空 S 后：");
		StrEmpty_H(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼8\n▲函数 Concat_H 测试...\n");			//8.函数Concat_H测试
	{
		printf("联接 T 和 V 形成Tmp...\n");
		Concat_H(&Tmp, T, V);
		printf(" Tmp 中的元素为：Tmp = ");						 
		StrPrint_H(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	return 0;
}
