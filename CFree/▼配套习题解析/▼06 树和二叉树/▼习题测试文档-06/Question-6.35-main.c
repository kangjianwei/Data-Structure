#include <stdio.h>

/* ����ԭ�� */
int Algo_6_35(int i);

int main(int argc, char *argv[])
{
	int i, j;
	char BiTree[100] = {'A', 'B', 'C', 'D', 'E', 'F', '\0', 'G', '\0', 'H', 'I', '\0', 'J'};
	
	printf("��Ϊʾ����������������˳��洢�ṹ��^������ַ�����ABCDEF^G^HI^J^^");
	printf("\n");
	
	printf("������0-14֮����±�ֵ�� ");
	fflush(stdin);
	scanf("%d", &i);
	printf("\n");
		
	j = Algo_6_35(i);
	
	printf("�±�ֵΪ %d �Ľ��Ķ�Ӧ��ʮ��������Ϊ %d ��\n\n", i, j);
	
	return 0;
}

/*����������������������������
����6.35����������������ֵ��
����������������������������*/
int Algo_6_35(int i)					//����0�ŵ�Ԫ��ʼ�洢			
{
	return i+1;
}
