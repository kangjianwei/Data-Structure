/**********************************************
 *						                      *
 * �ļ���: ��02 ���Ա�\08 DualCycleLinkedList *
 * 						                      *
 * ��  ��: ˫ѭ��������غ�������             *
 *                                            *
 **********************************************/

#include <stdio.h>
#include "DualCycleLinkedList.c" 						//**��02 ���Ա�**//

Status CmpGreater(LElemType_DC e, LElemType_DC data);	//��data>e������TRUE�����򷵻�FALSE 
void PrintElem(LElemType_DC e);							//���Ժ�������ӡ����

int main(int argc, char **argv)
{
	DuLinkList L;
	int i;
	LElemType_DC e;
	
	printf("��1\n������ InitList_DuL ����...\n");		//1.����InitList_DuL����
	{
		printf("��ʼ��˫ѭ������ L ...\n");					 
		InitList_DuL(&L);
		printf("\n");
	} 
	PressEnter;
	
	printf("��4\n������ ListEmpty_DuL ����...\n");		//4.����ListEmpty_DuL����
	{
		ListEmpty_DuL(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("��11\n������ ListInsert_DuL ����...\n");	//11.����ListInsert_DuL����
	{
		for(i=1; i<=6; i++)									
		{
			printf("�� L �� %d ��λ�ò��� \"%d\" ...\n", i, 2*i);
			ListInsert_DuL(L, i, 2*i);
		}
		printf("\n");
	} 
	PressEnter;
	
	printf("��13\n������ ListTraverse_DuL ����...\n");	//13.����ListTraverse_DuL����
	{
		printf(" L �е�Ԫ��Ϊ��L = ");							 
		ListTraverse_DuL(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��5\n������ ListLength_DuL ����...\n");		//5.����ListLength_DuL����
	{
		printf(" L �ĳ���Ϊ %d \n", ListLength_DuL(L));
		printf("\n");
	} 
	PressEnter;	
	
	printf("��12\n������ ListDelete_DuL ����...\n");	//12.����ListDelete_DuL����
	{
		ListDelete_DuL(L, 6, &e);
		printf("ɾ�� L �е�6��Ԫ�� \"%d\" ...\n", e);
		printf(" L �е�Ԫ��Ϊ��L = ");						 
		ListTraverse_DuL(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��6\n������ GetElem_DuL ����...\n");		//6.����GetElem_DuL����
	{
		GetElem_DuL(L, 4, &e);
		printf(" L �е� 4 ��λ�õ�Ԫ��Ϊ \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("��7\n������ LocateElem_DuL ����...\n");		//7.����LocateElem_DuL����
	{
		i = LocateElem_DuL(L, 7, CmpGreater); 
		printf(" L �е�һ��Ԫ��ֵ���� \"7\" ��Ԫ�ص�λ��Ϊ %d \n", i); 
		printf("\n");
	} 
	PressEnter;
	
	printf("��8\n������ PriorElem_DuL ����...\n");		//8.����PriorElem_DuL����
	{
		PriorElem_DuL(L, 6, &e);
		printf("Ԫ�� \"6\" ��ǰ��Ϊ \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("��9\n������ NextElem_DuL ����...\n");		//9.����NextElem_DuL����
	{
		NextElem_DuL(L, 6, &e);
		printf("Ԫ�� \"6\" �ĺ��Ϊ \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("��10\n������ GetElem_P ����...\n");			//10.����GetElem_P����
	{
		DuLinkList p;
		p = GetElemPtr_DuL(L, 3);
		printf("����� 3 ������ָ��Ϊ 0x%x�����Ӧ��ֵΪ \"%d\" \n", p, *p);
		printf("\n");
	} 
	PressEnter;
	
	printf("��3\n������ ClearList_DuL ����...\n");		//3.����ClearList_DuL����
	{
		printf("��� L ǰ��");
		ListEmpty_DuL(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		ClearList_DuL(L);
		printf("��� L ��");
		ListEmpty_DuL(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("��2\n������ DestroyList_DuL ����...\n");	//2.����DestroyList_DuL����
	{
		printf("���� L ǰ��");
		L ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
		DestroyList_DuL(&L);
		printf("���� L ��");
		L ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
		printf("\n");
	} 
	PressEnter;
	
	return 0;
}

Status CmpGreater(LElemType_DC e, LElemType_DC data)
{
	return data>e ? TRUE : FALSE;
}

void PrintElem(LElemType_DC e)
{
	printf("%d ", e);
}
