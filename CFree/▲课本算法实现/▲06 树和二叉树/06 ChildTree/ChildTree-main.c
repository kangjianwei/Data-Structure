/****************************************************
 *										            *
 * �ļ���: ��06 ���Ͷ�����\06 ChildTree             *
 * 									                *
 * �ļ���: ChildTree-main.c                         *
 * 										            *
 * ��  ��: ���ĺ�������(��˫��)�洢��ʾ��غ������� *
 *                                                  *
 ****************************************************/

#include <stdio.h>
#include "ChildTree.c" 													//**��06 ���Ͷ�����**//															

void PrintElem(TElemType_C e);

int main(int argc, char *argv[])
{
	CTree T, T0;
	FILE *fp;															//��Ϊ����Դ

	printf("��1\n������ InitTree_C ����...\n");							//1.����InitTree_C����
	{
		printf("��ʼ��һ�ÿ��� T ...\n");
		fp = fopen("TestData_T.txt", "r");
		InitTree_C(fp, &T);
		printf("\n");
	}
	PressEnter;

	printf("��5\n������ TreeEmpty_C ����...\n");						//5.����TreeEmpty_C����
	{
		TreeEmpty_C(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
		
	printf("��6\n������ CreateTree_C ����...\n");						//6.����CreateTree_C����
	{
		CreateTree_C(fp, &T); 
		fclose(fp);
		printf("\n");
	}
	PressEnter;

	printf("��22\n������ LevelOrderTraverse_C ����...\n");				//22.����LevelOrderTraverse_C����
	{
		printf("��������� T = ");
		LevelOrderTraverse_C(T, PrintElem); 
		printf("\n\n");
	}
	PressEnter;

	printf("��8-2��9��23-1\n������ Print_C�� ����...\n");				//8-2��9��23-1.����Print_C_1��TreeDepth_C_2��Depth_C����
	{
		printf("��ӡ�� T = \n");
		Print_C_1(T); 
		printf("\n");
	}
	PressEnter;

	printf("��24\n������ ShowTree_T ����...\n");						//24.����ShowTree_T����
	{
		printf("չʾ���ṹ T = \n");
		ShowTree_C(T); 
		printf("\n");
	}
	PressEnter;

	printf("��7\n������ TreeDegree_C ����...\n");						//7.����TreeDegree_P����
	{
		printf(" T �Ķ�Ϊ��%d \n", TreeDegree_C(T)); 
		printf("\n");
	}
	PressEnter;

	printf("��8-1\n������ TreeDepth_C_1 ����...\n");					//8-1.����TreeDepth_C_1����
	{
		printf(" T ���� %d �� \n", TreeDepth_C_1(T)); 
		printf("\n");
	}
	PressEnter;
	
	printf("��10\n������ Root_C ����...\n");							//10.����Root_C����
	{
		printf(" T �ĸ����Ϊ��%c\n", Root_C(T)); 
		printf("\n");
	}
	PressEnter;	
	
	printf("��11\n������ Value_C ����...\n");							//11.����Value_C����
	{
		printf(" T �е� %d ������ֵΪ��%c \n", 2, Value_C(T, 2)); 
		printf("\n");
	}
	PressEnter;

	printf("��12\n������ Order_C ����...\n");							//12.����Order_C����
	{
		printf(" T ��Ԫ�� %c ��λ��Ϊ��%d \n", 'A', Order_C(T, 'A')); 
		printf("\n");
	}
	PressEnter;
	
	printf("��13��23-2\n������ Assign_C�� ����...\n");					//13��23-2.����Assign_C��Print_C_2����
	{
		printf("����� 'B' ��ֵΪ 'X' ��T = \n");
		Assign_C(&T, 'B', 'X'); 
		Print_C_2(T, T.r, 0);
		printf("\n");
	}
	PressEnter;

	printf("��14\n������ ChildValue_C ����...\n");						//14.����ChildValue_C����
	{
		printf("��� %c �� %d ������Ϊ��%c \n", 'A', 2, ChildValue_C(T, 'A', 2)); 
		printf("\n");
	}
	PressEnter;

	printf("��15-1��15-2\n������ Sibling_C_1��Sibling_C_2 ����...\n");	//15-1��15-2.����Sibling_C_1��Sibling_C_2����
	{
		printf(" %c �����ֵ�Ϊ��%c��%c �����ֵ�Ϊ��%c \n", 'E', Sibling_C_1(T, 'E', 0), 'D', T.nodes[Sibling_C_2(T, 3, 1)].data);
		printf("\n");
	}
	PressEnter;

	printf("��16��17��18��19��20\n������ InsertTree_C�� ����...\n");	//16��17��18��19��20.����ChildCount_C��ChildSeat_C��SiblingSeat_C��InsertChild_C��InsertTree_C����
	{
		printf("��������ӡ T0 ...\n");
		fp = fopen("TestData_T0.txt", "r");
		InitTree_C(fp, &T0);
		CreateTree_C(fp, &T0);
		fclose(fp);
		Print_C_1(T0);
		printf("\n"); 
		printf("���� T0 �޽�Ϊ %c �ĵ� %d ��������T = ...\n", 'X', 1);
		InsertTree_C(&T, 'X', 1, T0);
		Print_C_1(T); 
		printf("\n");
		ShowTree_C(T);
		printf("\n");
	}
	PressEnter;
	
	printf("��21\n������ DeleteTree_C ����...\n");						//21.����DeleteTree_C����
	{
		printf("ɾ�� T �н�� %c �ĵ� %d ��������T = \n", '0', 3);
		DeleteTree_C(&T, '0', 3); 
		Print_C_1(T);
		printf("\n");
		ShowTree_C(T);
		printf("\n");
	}
	PressEnter;

	printf("��2��3\n������ ClearTree_C�� ����...\n");					//2��3.����ClearTree_C����
	{
		ClearTree_C(&T);
		TreeEmpty_C(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;	
}

void PrintElem(TElemType_C e)
{
	printf("%c ",e);
}
