#include <stdio.h>	
#include "../../../���α��㷨ʵ��/��04 ��/03 BlockChainString/BlockChainString.c"//**��04 ��**//

/* ����ԭ�� */
void Algo_4_22(LString S, LString *T, char ch);

int main(int argc, char *argv[])
{
	char *t = "----***--*-**-**^**-*****-----";
	char *s = "12345";
	char ch = '^';
	LString T, S;
	
	StrAssign_L(&T, t);
	StrAssign_L(&S, s);
	printf("T = ");
	StrPrint_L(T);
	printf("\n");
	printf("S = ");
	StrPrint_L(S);
	printf("\n\n");

	Algo_4_22(S, &T, ch);
	printf("T = ");
	StrPrint_L(T);
	printf("\n\n");	

	return 0;
}

/*����������������������������������������������������������
����4.22����S���뵽T��ĳ���ַ�֮���������������T��ĩλ ��
����������������������������������������������������������*/
void Algo_4_22(LString S, LString *T, char ch)
{
	int i;
	char tmp[2];
	LString Tmp;
	
	tmp[0] = ch;
	tmp[1] = '\0';
	StrAssign_L(&Tmp, tmp);
	
	i = Index_L((*T), Tmp, 1);					//Ѱ���ַ�ch��T�е�λ��
	
	if(i)
		StrInsert_L(T, i+1, S); 			//S������T�ĵ�i+1���ַ�ǰ 
	else
		StrInsert_L(T, (*T).curlen+1, S); 	//S������T�����	
} 
