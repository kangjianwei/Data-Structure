/*************************************
 *                                   *
 * 文件夹: ▲04 串\01 SequenceString *
 *                                   *
 * 内  容: 顺序串相关函数测试        *
 *                                   *
 *************************************/

#include <stdio.h>
#include "SequenceString.c" 							//**▲04 串**//

int main(int argc, char **argv)
{
	char *chars = "abcdef g";
	char *t = "** *";
	char *v = "^^^  ^";
	SString S, Tmp, T, V, Sub;
	int i;
	
	printf("▼1\n▲函数 StrAssign_Sq 测试...\n");		//1.函数StrAssign_Sq测试
	{
		printf("为顺序串 Tmp 赋值...\n");					 
		StrAssign_Sq(Tmp, chars);
		printf("\n");
	} 
	PressEnter;
	
	printf("▼3\n▲函数 StrEmpty_Sq 测试...\n");		//3.函数StrEmpty_Sq测试
	{
		StrEmpty_Sq(Tmp) ? printf(" Tmp 为空！！\n") : printf(" Tmp 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼5\n▲函数 StrLength_Sq 测试...\n");		//5.函数StrLength_Sq测试
	{
		i = StrLength_Sq(Tmp);
		printf(" Tmp 的长度为 %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("▼14\n▲函数 StrPrint_Sq 测试...\n");		//14.函数StrPrint_Sq测试
	{
		printf(" Tmp 中的元素为：Tmp = ");						 
		StrPrint_Sq(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼2\n▲函数 StrCopy_Sq 测试...\n");			//2.函数StrCopy_Sq测试
	{
		printf("复制 Tmp 到 S ...\n");
		StrCopy_Sq(S, Tmp);
		printf(" S 中的元素为：S = ");						 
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼4\n▲函数 StrCompare_Sq 测试...\n");		//4.函数StrCompare_Sq测试
	{
		printf("比较字符串 Tmp 、 S ...\n");
		i = StrCompare_Sq(Tmp, S);
		i==0 ? printf("Tmp==S！！\n") : (i<0 ? printf("Tmp<S！！\n") : printf("Tmp>S！！\n"));
		printf("\n");
	}
	PressEnter;
	
	printf("▼11\n▲函数 StrInsert_Sq 测试...\n");		//11.函数StrInsert_Sq测试
	{
		printf("将 \"***\" 赋给T...\n");
		StrAssign_Sq(T, t);
		printf("在 S 的第 5 个字符前插入T...\n");
		StrInsert_Sq(S, 5, T);
		printf(" S 中的元素为：S = ");						 
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼9\n▲函数 Index_Sq_1 测试...\n");			//9-1.函数Index_Sq_1测试
	{
		printf("获取字符串 \"***\" 在 S 中从第1个字符算起的第一次出现的位置...\n");
		i = Index_Sq_1(S, T, 1);
		printf(" \"***\" 在 S 中第1个字符后第一次出现的位置为%d\n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("▼8\n▲函数 SubString_Sq 测试...\n");		//8.函数SubString_Sq测试
	{
		printf("用 Sub 返回 S 中第 5 个字符起的 3 个字符...\n");
		SubString_Sq(Sub, S, 5, 3);
		printf(" Sub 中的元素为：Sub = ");						 
		StrPrint_Sq(Sub);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼10\n▲函数 Replace_Sq、Index_Sq_2 测试...\n");//9-2、10.函数Replace_Sq、Index_Sq_2测试
	{
		printf("将 \"^^^^\" 赋给V...\n");
		StrAssign_Sq(V, v);
		printf("用 \"^^^^\" 替换S中的 \"***\" ...\n");
		Replace_Sq(S, T, V);
		printf(" S 中的元素为：S = ");						 
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼12\n▲函数 StrDelete_Sq 测试...\n");		//12.函数StrDelete_Sq测试
	{
		printf("删除 S 中第 5 个字符起的 4 个字符...\n");
		StrDelete_Sq(S, 5, 4); 
		printf(" S 中的元素为：S = ");						 
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("▼6\n▲函数 ClearString_Sq 测试...\n");		//6.函数ClearString_Sq测试
	{
		printf("清空 S 前：");
		StrEmpty_Sq(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		ClearString_Sq(S);
		printf("清空 S 后：");
		StrEmpty_Sq(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
		printf("\n");
	}
	PressEnter;
	
	printf("▼7\n▲函数 Concat_Sq 测试...\n");			//7.函数Concat_Sq测试
	{
		printf("连接 T 和 V 形成 Tmp ...\n");
		Concat_Sq(Tmp, T, V);
		printf(" Tmp 中的元素为：Tmp = ");						 
		StrPrint_Sq(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	return 0;
}
