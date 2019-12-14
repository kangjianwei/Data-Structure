/****************************************
 *						                *
 * �ļ���: ��06 ���Ͷ�����\08 MFSet     *
 * 						                *
 * �ļ���: MFSet-main.c                 *
 * 							            *
 * ��  ��: ���鼯���ȼ��ࣩ��غ������� *
 *                                      *
 ****************************************/

#include <stdio.h> 
#include "MFSet.c" 						//**��06 ���Ͷ�����**//

int main(int argc, char *argv[])
{
	FILE *fp;
	MFSet S;
		
	printf("��1\n������ Initial_mfset ����...\n");		//1.����Initial_mfset����
	{
		printf("��ʼ�����ϣ���Ϊʾ��¼�� 10 ��Ԫ�أ�...\n");
		fp = fopen("TestData_S.txt", "r");
		Initial_mfset(fp, &S);
		fclose(fp);
		printf("��ʼ����ɣ��ּ����зǿ��Ӽ���ֻ��������Ԫ��...\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��8��9\n������ ShowSet_mfset�� ����...\n");	//8��9.����ShowSet_mfset��SubsetCount_mfset����
	{
		printf("չʾ���� S = ");
		ShowSet_mfset(S);
		printf("\n");
	}
	PressEnter;
	
	printf("��2��3��6��7-1\n������ EquivalenceClass_mfset_1�� ����...\n");
	{													//2��3��6��7-1.����find_mfset��merge_mfset��BuildRelation_mfset��EquivalenceClass_mfset_1����
		Relation R1;
		
		printf("���ݵȼ۹�ϵ�����ȼ���...\n");
		printf("��Ϊʾ��¼��4����Ԫ��ϵ�磺{(1,2),(3,4),(5,6),(7,9)}...\n");
		fp = fopen("TestData_R1.txt", "r");
		BuildRelation_mfset(fp, &R1); 
		fclose(fp);
		EquivalenceClass_mfset_1(&S, R1);
		printf("չʾ�ȼ��� S = ");
		ShowSet_mfset(S);
		printf("\n");
	}
	PressEnter;
	
	printf("��4��5��6��7-2\n������ EquivalenceClass_mfset_2�� ����...\n");
	{													//4��5��6��7-2.����fix_mfset��mix_mfset��BuildRelation_mfset��EquivalenceClass_mfset_2����
		Relation R2;
		
		printf("����ĳ���ϵĵȼ۹�ϵ������ȼ���...\n");
		printf("��Ϊʾ��¼��2����Ԫ��ϵ�磺{(1,3),(5,7)}...\n");
		fp = fopen("TestData_R2.txt", "r");
		BuildRelation_mfset(fp, &R2);
		fclose(fp);
		EquivalenceClass_mfset_2(&S, R2);
		printf("չʾ�ȼ��� S = ");
		ShowSet_mfset(S);
		printf("\n");
	}
	PressEnter;
}
