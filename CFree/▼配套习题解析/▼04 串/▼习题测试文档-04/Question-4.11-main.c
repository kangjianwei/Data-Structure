#include <stdio.h>	
#include "../../../���α��㷨ʵ��/��04 ��/01 SequenceString/SequenceString.c"//**��04 ��**//

/* ����ԭ�� */
void Algo_4_11(SString R, SString S, SString T, int a[]);

int main(int argc, char *argv[])
{
	int a[MAXSTRLEN+1];
	char *s = "amdhcjgfdlpinbefcopgkqikeb";
	char *t = "mhjlpinopkqik";
	SString T, S, R;
	int i;
	
	printf("��ʼ��S��T...\n");
	StrAssign_Sq(S, s);
	StrAssign_Sq(T, t);
	printf("\n");
	
	printf("S = ");	
	StrPrint_Sq(S);
	printf("\n");
	printf("T = ");	
	StrPrint_Sq(T);
	printf("\n\n");
	
	Algo_4_11(R, S, T, a);
	printf("R = ");	
	StrPrint_Sq(R);
	printf("\n");
	printf("a = ");
	for(i=1; i<=a[0]; i++)
		printf("%d ", a[i]);
	printf("\n\n");

	return 0;
}

/*������������������
����4.11��r=s-s��t��
������������������*/
void Algo_4_11(SString R, SString S, SString T, int a[])	//����a��0�Ŵ洢a��Ԫ�ظ��� 
{
	int i, p;
	SString Tmp;
	
	StrAssign_Sq(R, "");
	Tmp[0] = 1;
	
	for(i=1,a[0]=0; i<=S[0]; i++)
	{
		Tmp[1] = S[i];										//��S[i]��Ϊ�� 
		
		p = Index_Sq_1(T, Tmp, 1);							//�ж�S[i]�Ƿ���T��
		
		if(!p)
			p = Index_Sq_1(R, Tmp, 1);						//�ж�S[i]�Ƿ��ѳ��ֹ� 
		
		if(!p)
		{		
			a[0]++;
			a[a[0]] = i;
			StrInsert_Sq(R, a[0], Tmp);		
		}
	}
	
} 
