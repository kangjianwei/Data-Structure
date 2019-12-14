/******************************
 *						      *
 * �ļ���: ��11 �ⲿ����      *
 * 						      *
 * �ļ���: LoserTree-main.c   *
 * 							  *
 * ��  ��: ��������غ������� *
 *                            *
 ******************************/

#include <stdio.h>
#include "LoserTree.c"		//**��11 �ⲿ����**//

int main(int argc, char *argv[])
{	
	FILE *fp;
	LoserTree ls;
	External b;
	
	printf("��6\n������ RandomNum ����...\n");						//6.����RandomNum����		
	{
		printf("�������������Ϊʾ���ļ�...\n");
		fp = fopen("TestData.txt", "w+");							//�������д���ļ�
		RandomNum(fp);
		printf("\n");
	}	
	PressEnter; 
	
	printf("��7\n������ Cut_Sort ����...\n");						//7.����Cut_Sort����
	{
		printf("�ָ�����������ֱ���������[0..k-1].txt...\n");
		fp = fopen("TestData.txt", "r");							//��ȡ������ļ�
		Cut_Sort(fp);												//�ָ�fpΪk���ļ������ֱ����� 
		printf("\n");
	}	
	PressEnter; 	
	
	printf("��1��2��3��4��5\n������ K_Merge�� ����...\n");			//1��2��3��4��5.����K_Merge�Ȳ���
	{
		printf("��k���鲢��[0..k-1].txt�����д���ļ�Order.txt");
		fp = fopen("Order.txt", "w+");								//������鲢����д�������Ĺؼ���
		K_Merge(fp, ls, b);
		system("start Order.txt");									//�����Ĺؼ��� 
		printf("\n\n");	
	}
	PressEnter;
	
	system("rd/s/q tmpfile");										//ɾ����ʱ�ļ��� 
	
	return 0;
}
