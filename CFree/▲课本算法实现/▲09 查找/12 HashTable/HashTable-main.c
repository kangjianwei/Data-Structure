/**********************************
 *						          *
 * �ļ���: ��09 ����              *
 * 						          *
 * �ļ���: HashTable-main.c       *
 * 						          *
 * ��  ��: ��ϣ�������غ������� *
 *                                *
 **********************************/

#include <stdio.h>
#include "HashTable.c" 						//**��09 ����**//

#define Max 20								//���ұ���Ԫ�ظ��� 

int main(int argc, char *argv[])
{	
	Table T;
	HashTable H;
	
	printf("���������һ�����ұ�...\n");
	{
		FILE *fp;
		
		fp = fopen("TestData_Table.txt", "r");	
		Create(fp, &T, Max);	
		Traverse(T, PrintKey);	
		printf("\n");
	}	
	PressEnter; 
	
	printf("��1��2��3��4��5��6��7��8\n������ CreateHash�� ����...\n");	//1��2��3��4��5��6��7��8.����CreateHash�Ȳ���		
	{
		printf("����һ����ϣ����������еĹؼ��֣�\n");	
		CreateHash(&H, T);	
		PrintHash(H);	
		printf("\n");
	}	
	PressEnter; 

	printf("��\n�����Ҳ���...\n");										//���Ҳ���
	{ 
		Status r;
		KeyType key = 132;
		int p = 0;
		
		printf("���ҹؼ��� %d ...\n", key);
		r = SearchHash(H, key, &p);
		if(r==DUPLICATE)
			printf("���ҳɹ���%d �ڹ�ϣ���±�Ϊ %d ��λ�á�\n", key, p);
		else
			printf("����ʧ�ܣ�\n");
		printf("\n");
	}	
	PressEnter; 
		
	return 0;
}
