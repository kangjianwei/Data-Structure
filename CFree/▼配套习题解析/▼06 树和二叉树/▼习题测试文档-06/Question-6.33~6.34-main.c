#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"					//**��01 ����**//

/* �궨�� */
#define MAX 100						//���Ԫ�ظ��� 

/* ����ԭ�� */
Status Algo_6_33(int L[MAX+1], int R[MAX+1], int v, int u);
Status Algo_6_34(int T[MAX+1], int v, int u);

int main(int argc, char *argv[])
{
	int T[MAX+1] = {0, 0, 1, 1, 2, 2, 3, 5, 5, 6};				//0�ŵ�Ԫ���� 
	int L[MAX+1] = {0, 2, 4, 6, 0, 7, 0, 0, 0, 0};
	int R[MAX+1] = {0, 3, 5, 0, 0, 8, 9, 0, 0, 0};
	int u, v;
	
	printf("��Ϊʾ��������������š� 1 2 3 4 5 6 7 8 9\n");
	printf("                  L[n]�� 2 4 6 0 7 0 0 0 0\n");
	printf("                  R[n]�� 3 5 0 0 8 9 0 0 0\n");
	printf("                  T[n]�� 0 1 1 2 2 3 5 5 6\n");
	printf("\n");
		
	printf("��������Ҫ��֤�����Ｐ����...\n\n");	

	printf("����(1~9) u = ");
	fflush(stdin);
	scanf("%d", &u);
	printf("����(1~9) v = ");
	fflush(stdin);
	scanf("%d", &v);
	printf("\n");
	
	printf("������ �� 6.33 ��֤... ������\n");
	{
		if(Algo_6_33(L, R, v, u))
			printf("u=%d �� v=%d �����\n", u, v);
		else
			printf("u=%d ���� v=%d �������\n", u, v);	
		
		printf("\n");
	}
		

	printf("������ �� 6.34 ��֤... ������\n");
	{
		if(Algo_6_34(T, v, u))
			printf("u=%d �� v=%d �����\n", u, v);
		else
			printf("u=%d ���� v=%d �������\n", u, v);
	
		printf("\n");
	}

	return 0;
}

/*����������������������������
����6.33���ж�u�Ƿ�Ϊv�����逸
����������������������������*/
Status Algo_6_33(int L[MAX+1], int R[MAX+1], int v, int u)
{
	if(L[v]==u || R[v]==u)
		return TRUE;
	else
	{
		if(L[v] && Algo_6_33(L, R, L[v], u))
			return TRUE;
		if(R[v] && Algo_6_33(L, R, R[v], u))
			return TRUE;
	}
	
	return FALSE;
}

/*����������������������������
����6.34���ж�u�Ƿ�Ϊv�����逸
����������������������������*/
Status Algo_6_34(int T[MAX+1], int v, int u)
{
	if(T[u]==v)
		return TRUE;
	else
	{
		if(T[u] && Algo_6_34(T, v, T[u]))
			return TRUE;
	}
	
	return FALSE;
}
