/*****************************************
 *						                 *
 * �ļ���: ��06 ���Ͷ�����\05 ParentTree *
 *						                 *
 * �ļ���: ParentTree-main.c             *
 * 									     *
 * ��  ��: ����˫�ױ�ʾ����غ�������    *
 *                                       *
 *****************************************/

#include <stdio.h>
#include "ParentTree.c" 									//**��06 ���Ͷ�����**/

void PrintElem(TElemType_P e);

int main(int argc, char *argv[])
{
	PTree T, T0;

	printf("��1\n������ InitTree_P ����...\n");				//1.����InitTree_P����
	{
		InitTree_P(&T); 
		printf("��ʼ������ T �������λ��Ĭ����Ϊ 0 ...\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��4\n������ TreeEmpty_P ����...\n");				//4.����TreeEmpty_P����
	{
		TreeEmpty_P(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter; 
	
	printf("��5\n������ CreateTree_P ����...\n");				//5.����CreateTree_P����
	{
		FILE *fp;
		
		fp = fopen("TestData_T.txt", "r");
		CreateTree_P(fp, &T);
		fclose(fp);
		printf("\n");
	}
	PressEnter;	

	printf("��19\n������ LevelOrderTraverse_P ����...\n");	//19.����LevelOrderTraverse_P����
	{
		printf("��������� T = ");
		LevelOrderTraverse_P(T, PrintElem); 
		printf("\n\n");
	}
	PressEnter;

	printf("��20\n������ Print_P ����...\n");					//20.����Print_P����
	{
		printf("��ӡ�� T = \n");
		Print_P(T); 
		printf("\n");
	}
	PressEnter;

	printf("��6\n������ TreeDegree_P ����...\n");				//6.����TreeDegree_P����
	{
		printf(" T �Ķ�Ϊ��%d\n", TreeDegree_P(T)); 
		printf("\n");
	}
	PressEnter;

	printf("��7\n������ TreeDepth_P ����...\n");				//7.����TreeDepth_P����
	{
		printf(" T ���� %d ��\n", TreeDepth_P(T)); 
		printf("\n");
	}
	PressEnter;

	printf("��8\n������ Root_P ����...\n");					//8.����Root_P����
	{
		printf(" T �ĸ����Ϊ��%c \n", Root_P(T)); 
		printf("\n");
	}
	PressEnter;	
	
	printf("��9\n������ Value_P ����...\n");					//9.����Value_P����
	{
		printf(" T �е� %d �����ֵΪ��%c \n", 2, Value_P(T, 2)); 
		printf("\n");
	}
	PressEnter;

	printf("��10\n������ Order_P ����...\n");					//10.����Order_P����
	{
		printf(" T ��Ԫ�� %c ��λ��Ϊ��%d\n", 'A', Order_P(T, 'A')); 
		printf("\n");
	}
	PressEnter;
	
	printf("��11\n������ Assign_P ����...\n");				//11.����Assign_P����
	{
		printf("����� 'B' ��ֵΪ 'X' ��T = \n");
		Assign_P(&T, 'B', 'X');
		Print_P(T);
		printf("\n");
	}
	PressEnter;

	printf("��12\n������ ChildValue_P ����...\n");			//12.����ChildValue_P����
	{
		printf(" %c �ĵ� %d ������Ϊ��%c \n", 'A', 2, ChildValue_P(T, 'A', 2)); 
		printf("\n");
	}
	PressEnter;

	printf("��13\n������ Sibling_P ����...\n");				//13.����Sibling_P����
	{
		printf(" %c �����ֵ�Ϊ��%c��%c �����ֵ�Ϊ��%c \n", 'E', Sibling_P(T, 'E', 0), 'D', Sibling_P(T, 'D', 1));
		printf("\n");
	}
	PressEnter;	
	
	printf("��14��15��16��17\n������ InsertTree_P �Ȳ���...\n");		//14��15��16��17.����ChildCount_P��ChildSeat_P��InsertChild_P��InsertTree_P����
	{
		FILE *fp;
		
		printf("��������ӡ�� T0 ...\n");
		InitTree_P(&T0);
		fp = fopen("TestData_T0.txt", "r");
		CreateTree_P(fp, &T0);
		fclose(fp);	
		Print_P(T0);
		printf("���� T0 ����Ϊ�� T �н�� %c �ĵ� %d ��������T = \n", 'X', 1);
		InsertTree_P(&T, 'X', 1, T0);
		Print_P(T);
		printf("\n");
	}
	PressEnter;
	
	printf("��18\n������ DeleteTree_P ����...\n");				//18.����DeleteTree_P����
	{
		printf("ɾ�� T �н�� %c �ĵ� %d ��������T = \n", '0', 3);
		DeleteTree_P(&T, '0', 3);
		Print_P(T);	
		printf("\n");
	}
	PressEnter;	

	printf("��2\n������ ClearTree_P ����...\n");					//2.����ClearTree_P����
	{
		ClearTree_P(&T);
		TreeEmpty_P(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		printf("\n");
	} 
	PressEnter;
}

void PrintElem(TElemType_P e)
{
	printf("%c ",e);
}
