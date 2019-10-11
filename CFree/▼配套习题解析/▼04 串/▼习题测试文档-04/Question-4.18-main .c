#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"  	                     	//**▲01 绪论**//
#include "../../../▲课本算法实现/▲04 串/01 SequenceString/SequenceString.c"	//**▲04 串**//

/* 函数原型 */
void Algo_4_18(SString S, int total[]);

int main(int argc, char *argv[])
{
	char *s = "dbasydujhge638940[gptokljrsehgadcsbnmv,c.b'ng[p098437eywdghswqdecxvghju";
	SString S;
	int total[128] = {};
	int i;
	
	StrAssign_Sq(S, s);
	printf("S = ");
	StrPrint_Sq(S);
	printf("\n\n");
	
	Algo_4_18(S, total);
	printf(" S 中不同的字符共计 %d 个：\n", total[0]);
	for(i=1; i<=127; i++)
	{
		if(total[i]!=0)
			printf("字符 \'%c\' 有 %d 个.\n", i, total[i]);
	}
	printf("统计完毕...\n");
	printf("\n");
	
	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题4.18：统计字符串中不同字符总数和每种字符的个数┃
┗━━━━━━━━━━━━━━━━━━━━━━━━*/
/* 利用字符与数字对应的特性 */ 
void Algo_4_18(SString S, int total[])	//total长度设为128，代表各种不同字符
{
	int i;			 
	
	for(i=1; i<=S[0]; i++)				//字符串中间无空字符 
	{
		if(!total[S[i]])				//此处无字符 
			total[0]++;					//不同字符总数 

		total[S[i]]++;					//各种字符个数 
	}
}
