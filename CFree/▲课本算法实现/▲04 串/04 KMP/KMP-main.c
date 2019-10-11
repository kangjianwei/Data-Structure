/*******************************
 *						       *
 * 文件夹: ▲04 串\04 KMP      *
 * 						       *
 * 内  容: KMP算法相关函数测试 *
 *                             *
 *******************************/

#include "KMP.c"						//**▲04 串**//	
			
int main(int argc, char **argv)
{	
	int L, i1, i2, pos, i;
	SString S, T;
	char *s = "abaaabcaabaabcacabaabcaabaabcac";
	char *t = "abaabcac";

	StrAssign_Sq(S, s);					//主串 
	StrAssign_Sq(T, t);					//模式串
	L = StrLength_Sq(T);					//模式串长度 

	int next[L+1];						//模式串的next函数值 
	int nextval[L+1];					//模式串的nextval函数值
	 
	get_next(T, next);					//算法4.7
	get_nextval(T, nextval);			//算法4.8，即算法4.7的改进版 
	
	pos = 1;							//匹配算法起点 
	i1 = Index_KMP(S, T, pos, next);	//算法4.6 
	i2 = Index_KMP(S, T, pos, nextval);
	
	printf("主  串 ：");
	StrPrint_Sq(S);
	printf("\n");
	printf("模式串 ："); 
	StrPrint_Sq(T);
	printf("\n\n");
		
	printf("next   ：");
	for(i=1; i<=L; i++)
		printf("%d",next[i]);
	printf("\n");
	printf("从%d个字符起第一次匹配成功的位置为i1 = %d\n", pos, i1);
	printf("\n");
	
	printf("nextval：");
	for(i=1; i<=L; i++)
		printf("%d",nextval[i]);
	printf("\n");	
	printf("从%d个字符起第一次匹配成功的位置为i2 = %d\n", pos, i2);
	printf("\n");
	
	return 0;
}
