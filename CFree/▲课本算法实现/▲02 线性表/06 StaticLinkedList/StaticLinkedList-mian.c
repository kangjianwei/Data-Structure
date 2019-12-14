/********************************
 *						        *
 * �ļ���: ��02 ���Ա�          *
 * 						        *
 * ��  ��: ��̬������غ������� *
 *                              *
 ********************************/

#include <stdio.h>
#include "StaticLinkedList.c" 								//**��02 ���Ա�**//
	
void PrintElem(LElemType_S e);		//���Ժ�������ӡ����
	
int main(int argc, char **argv)
{
	SLinkList H;
	LElemType_S e;
	int i;
	
	printf("��1\n������InitSpace_SL����...\n");				//1.����InitSpace_SL����
	{
		printf("��ʼ����̬����ı��ÿռ� SPACE ...\n");					 
		InitSpace_SL();
		printf("\n");	
	} 
	PressEnter;
	
	printf("��2��4\n������Malloc_SL��InitList_SL����...\n");//4.����Malloc_SL��InitList_SL����
	{
		printf("��ʼ����̬���� H ����Malloc_SL����ռ�...\n");
		InitList_SL(&H);
		printf("\n");
	} 
	PressEnter;
		
	printf("��7\n������ListEmpty_SL����...\n");				//7.����ListEmpty_SL����
	ListEmpty_SL(H) ? printf(" H Ϊ�գ���\n") : printf(" H ��Ϊ�գ�\n");
	printf("\n");
	PressEnter;
	
	printf("��13\n������ListInsert_SL����...\n");			//13.����ListInsert_SL����
	{
		for(i=1; i<=6; i++)									
		{
			printf("�� H �� %d ��λ�ò���\"%d\" ...\n", i, 2*i);
			ListInsert_SL(H, i, 2*i);
		}
		printf("\n");
	} 
	PressEnter;
	
	printf("��15\n������ListTraverse_SL����...\n");			//15.����ListTraverse_SL����
	{
		printf(" H �е�Ԫ��Ϊ��H = ");						 
		ListTraverse_SL(H, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��8\n������ListLength_SL����...\n");			//8.����ListLength_SL����
	{
		printf(" H �ĳ���Ϊ %d \n", ListLength_SL(H));
		printf("\n");
	} 
	PressEnter;
		
	printf("��3��14\n������Free_SL��ListDelete_SL����...\n");//3��14.����Free_SL��ListDelete_SL����
	{
		ListDelete_SL(H, 6, &e);
		printf("ɾ�� H �е� 6 ��Ԫ�� \"%d\" ����Free_SL�ͷſռ�...\n", e);	
		printf(" H ��Ԫ��Ϊ��H = ");						 
		ListTraverse_SL(H, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��9\n������GetElem_SL����...\n");				//9.����GetElem_SL����
	{
		GetElem_SL(H, 4, &e);
		printf(" H �е� 4 ��λ�õ�Ԫ��Ϊ \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("��10\n������LocateElem_SL����...\n");			//10.����LocateElem_SL����
	{
		printf("Ԫ�� \"8\" �� H �е�λ��Ϊ %d \n", LocateElem_SL(H, 8)); 
		printf("\n");
	} 
	PressEnter;
	
	printf("��11\n������PriorElem_SL����...\n");			//11.����PriorElem_SL����
	{
		PriorElem_SL(H, 6, &e);
		printf("Ԫ�� \"6\" ��ǰ��Ϊ \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("��12\n������NextElem_SL����...\n");				//12.����NextElem_SL����
	{
		NextElem_SL(H, 6, &e);
		printf("Ԫ�� \"6\" �ĺ��Ϊ \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("��5\n������ClearList_SL����...\n");				//5.����ClearList_SL����
	{
		printf("��� H ǰ��");
		ListEmpty_SL(H) ? printf(" H Ϊ�գ���\n") : printf(" H ��Ϊ�գ�\n");
		ClearList_SL(H);
		printf("��� H ��");
		ListEmpty_SL(H) ? printf(" H Ϊ�գ���\n") : printf(" H ��Ϊ�գ�\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("��6\n������DestroyList_SL����...\n");			//6.����DestroyList_SL����
	{
		printf("���� H ǰ��");
		H ? printf(" H ���ڣ�\n") : printf(" H �����ڣ���\n");
		DestroyList_SL(&H);
		printf("���� H ��");
		H ? printf(" H ���ڣ�\n") : printf(" H �����ڣ���\n");
		printf("\n");
	} 
	PressEnter;
	
	return 0;
}

void PrintElem(LElemType_S e)
{
	printf("%d ", e);
}
