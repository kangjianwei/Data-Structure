 /*****************************
 *                            *
 * �ļ���: ��09 ����          *
 *                            *
 * �ļ���: Base-main.c        *
 *                            *
 * ��  ��: ���ұ���غ������� *
 *                            *
 ******************************/

#include <stdio.h>
#include "Base.c" 									//**��09 ����**//

/* �궨�� */
#define Max 10										//���ұ���Ԫ�ظ��� 

void Print(ElemType_Search e);
	//���������еĹؼ��ֺ������� 
	
int main(int argc, char *argv[])
{	
	FILE *fp;
	Table T;

	printf("��1\n������ Create ����...\n");			//1.����Create����			
	printf("����һ�����ұ�...\n");
	fp = fopen("TestData_Table.txt", "r");	
	Create(fp, &T, Max);
	printf("\n");	
	PressEnter;	

	printf("��3\n������ Traverse ����...\n");		//3.����Traverse����			
	printf("������ұ���Ϣ...\n");		
	Traverse(T, Print);	
	printf("\n");	
	PressEnter;
	
	printf("��4\n������ PrintKey ����...\n");		//4.����PrintKey����			
	printf("������ұ�ؼ���...\n");		
	Traverse(T, PrintKey);	
	printf("\n");	
	PressEnter;

	printf("��2\n������ DeTory ����...\n");			//2.����DeTory����
	printf("���������...\n");
	Destory(&T);
	printf("�����");
	T.elem==NULL&&T.length==0 ? printf("�ѱ�") : printf("δ��");
	printf("���٣�\n");		
	printf("\n");	
	PressEnter;

	return 0;
}

void Print(ElemType_Search e)
{
	printf("(%3d, %.1f) ", e.key, e.weight);
}
