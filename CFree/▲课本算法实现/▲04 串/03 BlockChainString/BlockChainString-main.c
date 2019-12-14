/***************************************
 *                                     *
 * �ļ���: ��04 ��\03 BlockChainString *
 *                                     *
 * ��  ��: ��������غ�������          *
 *                                     *
 ***************************************/

#include <stdio.h>
#include "BlockChainString.c" 							//**��04 ��**//

int main(int argc, char **argv)
{
	char *chars = "kuai-lian-chuan";
	char *t = "***";
	char *v = "^^^^";
	LString S, Tmp, T, V, Sub;
	int i;
	
	printf("��1\n������ InitString_L ����...\n");		//1.����InitString_L����
	{
		printf("��ʼ���մ� Tmp ...\n");
		InitString_L(&Tmp);
		printf("\n");
	}
	PressEnter;
	
	printf("��2\n������ StrAssign_L ����...\n");		//2.����StrAssign_L����
	{
		printf("Ϊ Tmp ��ֵ %s ...\n", chars);					 
		StrAssign_L(&Tmp, chars);
		printf("\n");
	}
	PressEnter;
	
	printf("��4\n������ StrEmpty_L ����...\n");			//4.����StrEmpty_L����
	{
		StrEmpty_L(Tmp) ? printf(" Tmp Ϊ�գ���\n") : printf(" Tmp ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��6\n������ StrLength_L ����...\n");		//6.����StrLength_L����
	{
		i = StrLength_L(Tmp);
		printf(" Tmp �ĳ���Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("��15\n������ StrPrint_L ����...\n");		//15.����StrPrint_L����
	{
		printf(" Tmp �е�Ԫ��Ϊ��Tmp = ");						 
		StrPrint_L(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��3\n������ StrCopy_L ����...\n");			//3.����StrCopy_L����
	{
		printf("���� Tmp �� S ...\n");
		StrCopy_L(&S, Tmp);
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_L(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��5\n������ StrCompare_L ����...\n");		//5.����StrCompare_L����
	{
		printf("�Ƚ��ַ��� Tmp �� S ...\n");
		i = StrCompare_L(Tmp, S);
		i==0 ? printf("Tmp==S����\n") : (i<0 ? printf("Tmp<S����\n") : printf("Tmp>S����\n"));
		printf("\n");
	}
	PressEnter;
	
	printf("��12\n������ StrInsert_L ����...\n");		//12.����StrInsert_L����
	{
		printf("�� \"***\" ���� T ...\n");
		StrAssign_L(&T, t);
		printf("�� S �ĵ� 5 ���ַ�ǰ���� T ...\n");
		StrInsert_L(&S, 5, T);
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_L(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��10\n������ Index_L ����...\n");			//10.����Index_L����
	{
		printf("��ȡ�ַ��� \"***\" �� S �дӵ� 1 ���ַ�����ĵ�һ�γ��ֵ�λ��...\n");
		i = Index_L(S, T, 1);
		printf(" \"***\" �� S �е� 1 ���ַ����һ�γ��ֵ�λ��Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("��9\n������ SubString_L ����...\n");		//9.����SubString_L����
	{
		printf("�� Sub ����S�е� 5 ���ַ���� 3 ���ַ�...\n");
		SubString_L(&Sub, S, 5, 3);
		printf(" Sub �е�Ԫ��Ϊ��Sub = ");						 
		StrPrint_L(Sub);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��11\n������ Replace_L ����...\n");			//11.����Replace_L����
	{
		printf("�� \"^^^^\" ���� V ...\n");
		StrAssign_L(&V, v);
		printf("�� \"^^^^\" �滻 S �е� \"***\" ...\n");
		Replace_L(&S, T, V);
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_L(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��13\n������ StrDelete_L ����...\n");		//13.����StrDelete_L����
	{
		printf("ɾ�� S �е� 5 ���ַ���� 4 ���ַ�...\n");
		StrDelete_L(&S, 5, 4); 
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_L(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��7\n������ ClearString_L ����...\n");		//7.����ClearString_L����
	{
		printf("��� S ǰ��");
		StrEmpty_L(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		ClearString_L(&S);
		printf("��� S ��");
		StrEmpty_L(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��8\n������ Concat_L ����...\n");			//8.����Concat_L����
	{
		printf("���� T �� V �γ� Tmp ...\n");
		Concat_L(&Tmp, T, V);
		printf(" Tmp �е�Ԫ��Ϊ��Tmp = ");						 
		StrPrint_L(Tmp);
		printf("\n\n");
	}
	PressEnter;

	return 0;
}
