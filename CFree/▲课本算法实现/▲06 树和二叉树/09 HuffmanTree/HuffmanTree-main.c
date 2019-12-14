/******************************************
 *								          *
 * �ļ���: ��06 ���Ͷ�����\09 HuffmanTree *
 * 								          *
 * �ļ���: HuffmanTree-main.c             *
 * 							              *
 * ��  ��: ����������غ�������           *
 *                                        *
 ******************************************/

#include <stdio.h>
#include "HuffmanTree.c" 										//**��06 ���Ͷ�����**//

int main(int argc, char *argv[])
{
	HuffmanTree HT;
	HuffmanCode HC;
	
	printf("��1\n������ InitTree_HT ����...\n");				//1.����InitTree_HT����
	{
		printf("��ʼ���������� HT ...\n");	
		InitTree_HT(&HT);
		printf("\n");
	}
	PressEnter;

	printf("��2��3\n������ CreateHuffmanTree_HT�� ����...\n");	//2��3.����CreateHuffmanTree_HT��Select_HT����
	{
		FILE *fp;
		
		printf("������������ HT ...\n");
		printf("��Ϊʾ�������� 8 ������Ȩֵ��5, 29, 7, 8, 14, 23, 3, 11��...\n");		
		fp = fopen("TestData_HT.txt", "r");
		CreateHuffmanTree_HT(fp, &HT);
		fclose(fp);
		printf("\n");
	}
	PressEnter;

	printf("��5\n������ ShowHuffmanTree_HT ����...\n");			//5.����ShowHuffmanTree_HT����
	{
		printf("չʾ�������� HT = \n");
		ShowHuffmanTree_HT(HT);
		printf("\n");
	}
	PressEnter;
/*
	//��һ���㷨 
	printf("��4-1\n������ HuffmanCodeing_HT_1 ����...\n");		//4-1.����HuffmanCodeing_HT_1����
	{
		printf("������������� HC ...\n");		
		HuffmanCodeing_HT_1(HT, &HC);
		printf("\n");
	}
	PressEnter;
*/

	printf("��4-2\n������ HuffmanCodeing_HT_1 ����...\n");		//4-2.����HuffmanCodeing_HT_1����
	printf("������������� HC ...\n");		
	HuffmanCodeing_HT_2(HT, &HC);
	printf("\n");
	PressEnter;

		
	printf("��6\n������ ShowHuffmanCode_HT ����...\n");			//6.����ShowHuffmanCode_HT����
	printf("չʾ���������� HC = \n");	
	ShowHuffmanCode_HT(HT, HC);
	printf("\n");
	PressEnter;
}
