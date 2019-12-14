/*******************************************
 *                                         *
 * �ļ���: ��02 ���Ա�\04 SinglyLinkedList *
 *                                         *
 * ��  ��: ��������غ�������              *
 *                                         *
 *******************************************/

#include <stdio.h> 
#include "SinglyLinkedList.c" 						//**��02 ���Ա�**//

/* ����ԭ�� */
Status CmpGreater(LElemType_L e, LElemType_L data);	//�ж�data�Ƿ����e //��data����e������TRUE 
void PrintElem(LElemType_L e);						//���Ժ�������ӡ���� 
	
int main(int argc, char **argv)
{
	LinkList L;
	int i;
	LElemType_L e;
	
	printf("��1\n������ InitList_L ����...\n");			//1.����InitList_L����
	{
		printf("��ʼ�������� L ...\n");					 
		InitList_L(&L);
		printf("\n");	
	}
	PressEnter;
	
	printf("��4\n������ ListEmpty_L ����...\n");		//4.����ListEmpty_L����
	{
		ListEmpty_L(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��10\n������ ListInsert_L ����...\n");		//10.����ListInsert_L����
	{
		for(i=1; i<=6; i++)									
		{
			printf("�� L �� %d ��λ�ò��� \"%d\" ...\n", i, 2*i);
			ListInsert_L(L, i, 2*i);
		}
		printf("\n");
	}
	PressEnter;
	
	printf("��12\n������ ListTraverse_L ����...\n");	//12.����ListTraverse_L����
	{
		printf(" L �е�Ԫ��Ϊ��L = ");						 
		ListTraverse_L(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;

	printf("��5\n������ ListLength_L ����...\n");		//5.����ListLength_L����
	{
		printf(" L �ĳ���Ϊ %d \n", ListLength_L(L));
		printf("\n");
	}
	PressEnter;
		
	printf("��11\n������ ListDelete_L ����...\n");		//11.����ListDelete_L����
	{
		ListDelete_L(L, 6, &e);
		printf("ɾ�� L �е� 6 ��Ԫ�� \"%d\" ...\n", e);
		printf(" L �е�Ԫ��Ϊ��L = ");						 
		ListTraverse_L(L, PrintElem);
		printf("\n\n");
	}
	PressEnter;
		
	printf("��6\n������ GetElem_L ����...\n");			//6.����GetElem_L����
	{
		GetElem_L(L, 4, &e);
		printf(" L �е� 4 ��λ�õ�Ԫ��Ϊ \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("��7\n������ LocateElem_L ����...\n");		//7.����LocateElem_L����
	{
		i = LocateElem_L(L, 13, CmpGreater);
		printf(" L �е�һ��Ԫ��ֵ���� \"7\" ��Ԫ�ص�λ��Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("��8\n������ PriorElem_L ����...\n");		//8.����PriorElem_L����
	{
		PriorElem_L(L, 6, &e);
		printf("Ԫ�� \"6\" ��ǰ��Ϊ \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("��9\n������ NextElem_L ����...\n");			//9.����NextElem_L����
	{
		NextElem_L(L, 6, &e);
		printf("Ԫ�� \"6\" �ĺ��Ϊ \"%d\" \n", e);
		printf("\n");
	}
	PressEnter;
	
	printf("��2\n������ ClearList_L ����...\n");		//2.����ClearList_L����
	{
		printf("��� L ǰ��");
		ListEmpty_L(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		ClearList_L(L);
		printf("��� L ��");
		ListEmpty_L(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��3\n������ DestroyList_L ����...\n");		//3.����DestroyList_L����
	{
		printf("���� L ǰ��");
		L ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
		DestroyList_L(&L);
		printf("���� L ��");
		L ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��13\n������ CreateList_HL ����...\n");		//13.����CreateList_HL����
	{
		FILE *fp;
		LinkList L;
		printf("ͷ�巨���������� L = ");
		fp = fopen("TestData_HL.txt", "r");				//�ļ�ָ�룬ָ������Դ
		CreateList_HL(fp, &L, 5);
		fclose(fp);
		ListTraverse_L(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��14\n������ CreateList_TL ����...\n");		//14.����CreateList_TL����
	{
		FILE *fp;
		LinkList L;
		printf("β�巨���������� L = ");
		fp = fopen("TestData_TL.txt", "r");				//�ļ�ָ�룬ָ������Դ
		CreateList_TL(fp, &L, 5);
		fclose(fp);
		ListTraverse_L(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	return 0;
}

Status CmpGreater(LElemType_L e, LElemType_L data)
{
	return data>e ? TRUE : FALSE;
}

void PrintElem(LElemType_L e)
{
	printf("%d ", e);
}
