/****************************************
 *						                *
 * �ļ���: ��02 ���Ա�\10 MergeEList    *
 * 						                *
 * ��  ��: �鲢��չ�ĵ�������غ������� *
 *                                      *
 ****************************************/

#include <stdio.h>
#include "MergeEList.c"					//**��02 ���Ա�**//

void PrintElem(LElemType_E e);			//���Ժ�������ӡ����

int main(int argc, char **argv)
{
	FILE *fp;
	ELinkList La, Lb, Lc;
	int m, n;
		
	m = 6;
	n = 7;
	
	printf("��Ϊʾ����La�����趨Ϊ %d ��Lb�趨Ϊ %d ������La��Lb...\n", m, n);	
	fp = fopen("TestData_La.txt", "r");	//�ļ�ָ�룬ָ������Դ	
	CreateList_ascend(fp, &La, m);		//����La��Lb 
	fclose(fp);
	fp = fopen("TestData_Lb.txt", "r");	//�ļ�ָ�룬ָ������Դ
	CreateList_ascend(fp, &Lb, n);	
	fclose(fp);
		
	printf("La= ");						//���La��Lb 
	ListTraverse_E(La, PrintElem);
	printf("\n");
	printf("Lb= ");
	ListTraverse_E(Lb, PrintElem);
	printf("\n\n");
	PressEnter;
	
	MergeEList_L(La, Lb, &Lc, Cmp);
	printf("�ϲ�La��LbΪ Lc = ");
	ListTraverse_E(Lc, PrintElem);
	printf("\n\n");
	PressEnter;
		
	return 0;
}

void PrintElem(LElemType_E e)
{
	printf("%d ", e);
}
