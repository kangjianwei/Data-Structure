/*******************************
 *						       *
 * �ļ���: ��04 ��\04 KMP      *
 * 						       *
 * ��  ��: KMP�㷨��غ������� *
 *                             *
 *******************************/

#include "KMP.c"						//**��04 ��**//	
			
int main(int argc, char **argv)
{	
	int L, i1, i2, pos, i;
	SString S, T;
	char *s = "abaaabcaabaabcacabaabcaabaabcac";
	char *t = "abaabcac";

	StrAssign_Sq(S, s);					//���� 
	StrAssign_Sq(T, t);					//ģʽ��
	L = StrLength_Sq(T);					//ģʽ������ 

	int next[L+1];						//ģʽ����next����ֵ 
	int nextval[L+1];					//ģʽ����nextval����ֵ
	 
	get_next(T, next);					//�㷨4.7
	get_nextval(T, nextval);			//�㷨4.8�����㷨4.7�ĸĽ��� 
	
	pos = 1;							//ƥ���㷨��� 
	i1 = Index_KMP(S, T, pos, next);	//�㷨4.6 
	i2 = Index_KMP(S, T, pos, nextval);
	
	printf("��  �� ��");
	StrPrint_Sq(S);
	printf("\n");
	printf("ģʽ�� ��"); 
	StrPrint_Sq(T);
	printf("\n\n");
		
	printf("next   ��");
	for(i=1; i<=L; i++)
		printf("%d",next[i]);
	printf("\n");
	printf("��%d���ַ����һ��ƥ��ɹ���λ��Ϊi1 = %d\n", pos, i1);
	printf("\n");
	
	printf("nextval��");
	for(i=1; i<=L; i++)
		printf("%d",nextval[i]);
	printf("\n");	
	printf("��%d���ַ����һ��ƥ��ɹ���λ��Ϊi2 = %d\n", pos, i2);
	printf("\n");
	
	return 0;
}
