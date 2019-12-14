/*********************************************************
 *										                 *
 * �ļ���: ��06 ���Ͷ�����\07 ChildSiblingTree           *
 * 									                     *
 * �ļ���: ChildSiblingTree-main.c                       *
 * 										                 *
 * ��  ��: ���Ķ�����������-�ֵܣ��洢��ʾ��غ������� *
 *                                                       *
 *********************************************************/

#include <stdio.h> 
#include "ChildSiblingTree.c" 											//**��06 ���Ͷ�����**//

void PrintElem(TElemType_CS e);

int main(int argc, char *argv[])
{
	CSTree T;															//��Ϊ����Դ
	
	printf("��1\n������ InitTree_CS ����...\n");						//1.����InitTree_CS����
	{
		printf("��ʼ��һ�ÿ��� T \n");
		InitTree_CS(&T);
		printf("\n");
	}
	PressEnter;

	printf("��4\n������ TreeEmpty_CS ����...\n");						//4.����TreeEmpty_CS����
	{
		TreeEmpty_CS(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
		
	printf("��5\n������ CreateTree_CS ����...\n");						//5.����CreateTree_CS����
	{
		FILE *fp;
		
		printf("���������д��������� T ...\n");
		printf("��Ϊʾ����¼���������У�RAD^E^^B^CFG^H^K^^^^^...\n");
		fp = fopen("TestData_T.txt", "r");								//������� 
		CreateTree_CS(fp, &T); 
		fclose(fp);
		printf("\n");
	}
	PressEnter;

	printf("��21\n������ Print_CS ����...\n");							//21.����Print_CS����
	{
		printf("�����Ľṹ��ӡ�� T = \n");
		Print_CS(T);
		printf("\n");
	} 
	PressEnter;
		
	printf("��18\n������ LevelOrderTraverse_CS ����...\n");				//18.����LevelOrderTraverse_CS����
	{
		printf("��������� T = ");
		LevelOrderTraverse_CS(T, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��19\n������ PreOrderTraverse_CS ����...\n");				//19.����PreOrderTraverse_CS����
	{
		printf("ǰ������� T = ");
		PreOrderTraverse_CS(T, PrintElem);
		printf("\n\n");
	} 
	PressEnter;

	printf("��20\n������ InOrderTraverse_CS ����...\n");				//20.����InOrderTraverse_CS����
	{
		printf("��������� T = ");
		InOrderTraverse_CS(T, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("��6\n������ TreeDegree_CS ����...\n");						//6.����TreeDegree_CS����
	{
		printf(" T �Ķ�Ϊ��%d \n", TreeDegree_CS(T)); 
		printf("\n");
	}
	PressEnter;

	printf("��7\n������ TreeDepth_CS ����...\n");						//7.����TreeDepth_CS����
	{
		printf(" T ���� %d ��\n", TreeDepth_CS(T)); 
		printf("\n");
	}
	PressEnter;
	
	printf("��8\n������ Root_CS ����...\n");							//8.����Root_CS����
	{
		printf(" T �ĸ����Ϊ��%c\n", Root_CS(T)); 
		printf("\n");
	}
	PressEnter;	
	
	printf("��9\n������ Value_CS ����...\n");							//9.����Value_CS����
	{
		printf(" T �е� %d ������ֵΪ��%c\n", 2, Value_CS(T, 2)); 
		printf("\n");
	}
	PressEnter;

	printf("��10\n������ Order_CS ����...\n");							//10.����Order_CS����
	{
		printf(" T ��Ԫ�� %c �ĵ�ַΪ��0x%X \n", 'A', Order_CS(T, 'A')); 
		printf("\n");
	}
	PressEnter;
	
	printf("��11\n������ Assign_CS ����...\n");							//11.����Assign_CS����
	{
		printf("����� 'B' ��ֵΪ 'X' ��T = \n");
		Assign_CS(T, 'B', 'X');
		Print_CS(T);
		printf("\n");
	}
	PressEnter;

	printf("��12\n������ ChildValue_CS ����...\n");						//12.����ChildValue_CS����
	{
		printf("��� %c �ĵ� %d ������Ϊ��%c \n", 'A', 2, ChildValue_CS(T, 'A', 2)); 
		printf("\n");
	}
	PressEnter;

	printf("��13\n������ Sibling_CS ����...\n");						//13.����Sibling_CS����
	{
		printf(" %c �����ֵ�Ϊ��%c��", 'E', Sibling_CS(T, 'E', 0));
		printf(" %c �����ֵ�Ϊ��%c\n", 'D', Sibling_CS(T, 'D', 1));
		printf("\n");
	}
	PressEnter;
	
	printf("��14��15��16\n������ InsertTree_CS�� ����...\n");		//14��15��16����ChildCount_CS��ChildSeat_CS��InsertTree_CS����
	{
		FILE *fp;
		CSTree T0;
		
		printf("��������ӡ�� T0 ...\n");
		InitTree_CS(&T0);
		printf("��Ϊʾ����¼���������У�01^2^34^5^^^^...\n");
		fp = fopen("TestData_T0.txt", "r");
		CreateTree_CS(fp, &T0);
		fclose(fp);
		Print_CS(T0); 
		printf("�� T0�޽�Ϊ %c �ĵ� %d ��������T = \n", 'X', 1);
		InsertTree_CS(T, 'X', 1, T0);
		Print_CS(T); 
		printf("\n");
	}
	PressEnter;
	
	printf("��17\n������ DeleteTree_CS ����...\n");						//17.����DeleteTree_CS����
	{
		printf("ɾ�� T �н�� %c �ĵ� %d ��������T = \n", '0', 3);
		DeleteTree_CS(T, '0', 3); 
		Print_CS(T);	
		printf("\n");
	}
	PressEnter;

	printf("��2\n������ ClearTree_CS�� ����...\n");						//2.����ClearTree_CS����
	{
		ClearTree_CS(&T);
		TreeEmpty_CS(T) ? printf(" T Ϊ�գ�\n") : printf(" T ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;	
}

void PrintElem(TElemType_CS e)
{
	printf("%c ",e);
}
