#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	           	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲04 串/02 HeapString/HeapString.c"//**▲04 串**//

/* 函数原型 */
Status Concat_4_24(HString *T, HString S1, HString S2);
Status Replace_4_25(HString *S, HString T, HString V);
Status StrInsert_4_26(HString *S, int pos, HString T);

int main(int argc, char *argv[])
{
	char *s = "---*^***^*^*^*---";
	char *s1 = "*";
	char *s2 = "^*";
	char *v = "*_*";
	HString S1, S2, T, V, S;
	
	StrAssign_H(&S1, s1);
	StrAssign_H(&S2, s2);
	StrAssign_H(&V, v);
	StrAssign_H(&S, s);
	
	printf("S1 = ");
	StrPrint_H(S1);
	printf("\n");
	printf("S2 = ");
	StrPrint_H(S2);
	printf("\n");
	printf("V = ");
	StrPrint_H(V);
	printf("\n");
	printf("S = ");
	StrPrint_H(S);
	printf("\n\n");

	printf("███题 4.24 验证...███\n");	
	printf("连接S1和S2为T...\n");
	Concat_4_24(&T, S1, S2);
	printf("T = ");
	StrPrint_H(T);
	printf("\n\n");
	
	printf("███题 4.25 验证...███\n");
	printf("用 V 替换 S 中的 T...\n");
	Replace_4_25(&S, T, V);
	printf("S = ");
	StrPrint_H(S);
	printf("\n\n");	
	
	printf("███题 4.26 验证...███\n");
	printf("将 T 插入到 S 的第 2 个字符前...\n");
	StrInsert_4_26(&S, 2, T);
	printf("S = ");
	StrPrint_H(S);
	printf("\n\n");
			
	return 0;
}

/*━━━━━━━┓
┃题4.24：串连接┃
┗━━━━━━━*/
Status Concat_4_24(HString *T, HString S1, HString S2)
{
	if(Concat_H(T, S1, S2))				//已定义 
		return OK;
	else
		return ERROR;
}

/*━━━━━━━┓
┃题4.25：串替换┃
┗━━━━━━━*/
Status Replace_4_25(HString *S, HString T, HString V)
{
	if(Replace_H(S, T, V))				//已定义
		return OK;
	else
		return ERROR;
}

/*━━━━━━━┓
┃题4.26：串插入┃
┗━━━━━━━*/
Status StrInsert_4_26(HString *S, int pos, HString T)
{
	if(StrInsert_H(S, pos, T))			//已定义 
		return OK;
	else
		return ERROR;
}
