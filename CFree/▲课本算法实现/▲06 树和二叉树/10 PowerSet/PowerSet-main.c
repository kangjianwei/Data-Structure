/***************************************
 *							           *
 * �ļ���: ��06 ���Ͷ�����\10 PowerSet *
 * 						               *
 * �ļ���: PowerSet-main.c             *
 * 					    	           *
 * ��  ��: �ݼ���غ�������            *
 *                                     *
 ***************************************/

#include <stdio.h>
#include "PowerSet.c" 									//**��06 ���Ͷ�����**//															

int main(int argc, char *argv[])
{
	LinkList A;
	
	printf("��1\n������ CreatePowerSet_PS ����...\n");	//1.����CreatePowerSet_PS����
	{
		FILE *fp;
		
		printf("�������� A ...\n");	
		fp = fopen("TestData_A.txt", "r");
		CreatePowerSet_PS(fp, &A);
		fclose(fp);
		printf("\n");
	}
	PressEnter;
	
	printf("��3\n������ Output_PS ����...\n");			//3.����Output_PS����
	{
		printf("������� A = ");	
		Output_PS(A); 
		printf("\n");
	}
	PressEnter;

	printf("��2\n������ GetPowerSet_PS ����...\n");		//2.����GetPowerSet_PS����
	{
		LinkList B;
		
		printf("���㼯�ϵ��ݼ�...\n");	
		printf("�������� B ��ʱ�洢�ݼ�Ԫ��...\n");
		InitList_L(&B);
		printf("���������ȡ���ݼ��еĸ��Ӽ�...\n");
		GetPowerSet_PS(1, A, B);
		printf("\n");
	}
	PressEnter;
}
