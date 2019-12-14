/**************************************
 *                                    *
 * �ļ���: ��02 ���Ա�\03 MergeSqList *
 *                                    *
 * ��  ��: ˳���鲢��غ�������     *
 *                                    *
 **************************************/

#include <stdio.h>
#include "MergeSqList.c"				//**��02 ���Ա�**//
	
void PrintElem(LElemType_Sq e);			//���Ժ�������ӡ���� 
	
int main(int argc, char **argv)
{
	SqList La, Lb, Lc1, Lc2;
	LElemType_Sq a[4] = {3, 5, 8, 11};
	LElemType_Sq b[7] = {2, 6, 8, 9, 11, 15, 20};
	int i;
	
	InitList_Sq(&La);					//��ʼ��La 
	for(i=1; i<=4; i++)
		ListInsert_Sq(&La, i, a[i-1]);	
	InitList_Sq(&Lb);					//��ʼ��Lb 
	for(i=1; i<=7; i++)
		ListInsert_Sq(&Lb, i, b[i-1]);

	printf("La = ");					//���La 
	ListTraverse_Sq(La, PrintElem); 
	printf("\n");
	printf("Lb = ");					//���Lb 
	ListTraverse_Sq(Lb, PrintElem); 
	printf("\n\n");
	
	MergeSqList_1(La, Lb, &Lc1);		//�ϲ�A��B,�㷨2.6 
	printf("�ϲ�La��LbΪLc1 = "); 		//���Lc1 
	ListTraverse_Sq(Lc1, PrintElem);
	printf("\n\n");

	MergeSqList_2(La, Lb, &Lc2);		//�ϲ�A��B,�㷨2.7  
	printf("�ϲ�La��LbΪLc2 = "); 		//���Lc2 
	ListTraverse_Sq(Lc2, PrintElem);
	printf("\n\n");
	
	return 0;
}

void PrintElem(LElemType_Sq e)
{
	printf("%d ", e);
}
