/***********************************************
 *							                   *
 * �ļ���: ��06 ���Ͷ�����\04 ThreadBinaryTree *
 *							                   *
 * �ļ���: ThreadBinaryTree-main.c             *
 * 								               *
 * ��  ��: ������������ز����б�              *
 *                                             *
 ***********************************************/

#include <stdio.h>
#include "ThreadBinaryTree.c" 									//**��06 ���Ͷ�����**//

void PrintElem(TElemType_Thr e);

int main(int argc, char *argv[])
{
	ThrBiTree Thrt1, Thrt2, Thrt3;
	ThrBiTree T1, T2, T3; 
	int mark;
			
	printf("��1\n������ CreateBiTree_Thr ����...\n");				//1.����CreateBiTree_Thr����
	{
		FILE *fp;
		
		printf("���������д���������...\n");
		printf("��Ϊʾ����¼���������У�ABDG^^^EH^^I^^CF^J^^^\n");
		fp = fopen("TestData_T.txt", "r");
		CreateBiTree_Thr(fp, &T1);
		fseek(fp, 0, SEEK_SET);										//�˻ص��ĵ���ͷ 
		CreateBiTree_Thr(fp, &T2);
		fseek(fp, 0, SEEK_SET);										//�˻ص��ĵ���ͷ 
		CreateBiTree_Thr(fp, &T3);
		fclose(fp);
		printf("\n");
	} 
	PressEnter; 
	
	printf("��\n���������������������...\n��\n");
	{
		printf("��5��6\n������ PreTheading_Thr��PreOrderThreading_Thr ����...\n");//5��6.����PreTheading_Thr��PreOrderThreading_Thr����
		printf("�� T1 ������������Ϊ Thrt1 ...\n");
		PreOrderThreading_Thr(&Thrt1, T1);
		printf("\n");
	}
	PressEnter;
	
	printf("��7\n������ PreOrderTraverse_Thr ����...\n");		//4.����PreOrderTraverse_Thr����
	{
		printf("������� Thrt1 = ");
		PreOrderTraverse_Thr(Thrt1, PrintElem);
		printf("\n\n");
	}
	PressEnter;		
	
	printf("��\n���������ȫ����������...\n��\n");
	printf("��2��3\n������ InTheading_Thr��InOrderThreading_Thr ����...\n");	//2��3.����InTheading_Thr��InOrderThreading_Thr����
	{
		printf("�� T2 ����ȫ������Ϊ Thrt2 ...\n");
		InOrderThreading_Thr(&Thrt2, T2);
		printf("\n");
	}
	PressEnter;
	
	printf("��4\n������ InOrderTraverse_Thr ����...\n");		//4.����InOrderTraverse_Thr����
	{
		printf("������� Thrt2 = ");
		InOrderTraverse_Thr(Thrt2, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��\n����Ժ���������������...\n��\n");
	printf("��11\n������ ParentPtr_Thr�� ����...\n");								//11.����ParentPtr_Thr����
	{
		printf("Ϊ�����Ѱ��˫�׽��...\n");
		ParentPtr_Thr(T3);
		printf("\n");
	}
	PressEnter;
				
	printf("��8��9\n������ PosTheading_Thr��PosOrderThreading_Thr ����...\n");	//8��9.����PosTheading_Thr��PosOrderThreading_Thr����
	{
		printf("�� T3 ������������Ϊ Thrt3 ...\n");
		PosOrderThreading_Thr(&Thrt3, T3);
		printf("\n");
	}
	PressEnter;

	printf("��10��12\n������ PosOrderTraverse_Thr�� ����...\n");					//10��12.����PosOrderTraverse_Thr��Pos_NextPtr_Thr����
	{
		printf("������� Thrt3 = ");
		PosOrderTraverse_Thr(Thrt3, PrintElem);
		printf("\n\n");
	}
	PressEnter;
	
	return 0;
}

void PrintElem(TElemType_Thr e)
{
	printf("%c ",e);
}
