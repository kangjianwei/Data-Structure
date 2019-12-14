/**********************************************
 *                                            *
 * �ļ���: ��05 ����͹����\01 SequenceArray *
 *                                            *
 * ��  ��: ������غ�������                   *
 *                                            *
 **********************************************/

#include <stdio.h> 
#include "SequenceArray.c" 						//**��05 ����͹����**//

/* �Զ�ά����Ϊ������ */
int main(int argc, char **argv)
{
	Array A;
	
	printf("��1\n������ InitArray ���ԣ��Զ�ά����Ϊ����...\n");//1.����InitArray����
	{
		printf("��ʼ��һ�� 2 �� 3 �еĶ�ά���� A ...\n");					 
		InitArray(&A, 2, 2, 3);
		printf("\n");
	} 
	PressEnter;
	
	printf("��5\n������ AssignArray ����...\n");				//5.����AssignArray����
	{
		int i, j;
		AElemType_Sq e = 0;
		
		for(i=0; i<A.bounds[0]; i++)
		{
			for(j=0; j<A.bounds[1]; j++)
			{
				printf("��ֵ��A[%d][%d] = %d\n", i, j, ++e);
				AssignArray(&A, e, i, j);
			}
		}				
		printf("\n");
	} 
	PressEnter;
	
	printf("��6\n������ ArrayPrint ����...\n");					//6.����ArrayPrint����
	{
		printf(" A = ");
		ArrayPrint(A); 
		printf("\n\n");
	}
	PressEnter;
	
	printf("��3��4\n������ LocateArray��ValueArray ����...\n");	//3��4.����LocateArray��ValueArray����
	{
		AElemType_Sq x;
		
		printf("��ȡ A ���±�Ϊ (1,1) ��Ԫ�ص�ֵ��Locate ������� A[1][1] �����λ��...\n");
		ValueArray(A, &x, 1, 1);
		printf(" A[1][1] = %d\n", x);
		printf("\n");
	} 
	PressEnter;
		
	printf("��2\n������ DestroyArray ����...\n");				//2.����DestroyArray����
	{
		printf("���� A ǰ��");
		A.dim!=0 ? printf(" A ���ڣ�\n") : printf(" A �����ڣ���\n"); 					 
		DestroyArray(&A); 
		printf("���� A ��");
		A.dim!=0 ? printf(" A ���ڣ�\n") : printf(" A �����ڣ���\n");
		printf("\n");
	} 
	PressEnter;
		
	return 0;
}
