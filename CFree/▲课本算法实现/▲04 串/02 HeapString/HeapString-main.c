/*********************************
 *                               *
 * �ļ���: ��04 ��\02 HeapString *
 *                               *
 * ��  ��: �Ѵ���غ�������      *
 *                               *
 *********************************/

#include <stdio.h>
#include "HeapString.c" 								//**��04 ��**//

int main(int argc, char **argv)
{
	char *chars = "abcdefg";
	char *t = "***";
	char *v = "^^^^";
	HString S, Tmp, T, V, Sub;
	int i;
	
	printf("��1\n������ InitString_H ����...\n");		//1.����InitString_H����
	{
		printf("��ʼ���մ� Tmp ...\n");
		InitString_H(&Tmp);
		printf("\n");
	} 
	PressEnter;
	
	printf("��2\n������ StrAssign_H ����...\n");		//2.����StrAssign_H����
	{
		printf("Ϊ Tmp ��ֵ %s ...\n", chars);					 
		StrAssign_H(&Tmp, chars);
		printf("\n");
	}
	PressEnter;
	
	printf("��4\n������ StrEmpty_H ����...\n");			//4.����StrEmpty_H����
	{
		StrEmpty_H(Tmp) ? printf(" Tmp Ϊ�գ���\n") : printf(" Tmp ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��6\n������ StrLength_H ����...\n");		//6.����StrLength_H����
	{
		i = StrLength_H(Tmp);
		printf(" Tmp �ĳ���Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("��15\n������ StrPrint_H ����...\n");		//15.����StrPrint_H����
	{
		printf(" Tmp �е�Ԫ��Ϊ��Tmp = ");						 
		StrPrint_H(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��3\n������ StrCopy_H ����...\n");			//3.����StrCopy_H����
	{
		printf("���� Tmp �� S ...\n");
		StrCopy_H(&S, Tmp);
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_H(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��5\n������ StrCompare_H ����...\n");		//5.����StrCompare_H����
	{
		printf("�Ƚ��ַ��� Tmp �� S ...\n");
		i = StrCompare_H(Tmp, S);
		i==0 ? printf("Tmp==S����\n") : (i<0 ? printf("Tmp<S����\n") : printf("Tmp>S����\n"));
		printf("\n");
	}
	PressEnter;
	
	printf("��12\n������ StrInsert_H ����...\n");		//12.����StrInsert_H����
	{
		printf("�� \"***\" ���� T ...\n");
		StrAssign_H(&T, t);
		printf("�� S �ĵ� 5 ���ַ�ǰ���� T ...\n");
		StrInsert_H(&S, 5, T);
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_H(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��10\n������ Index_H ����...\n");			//10.����Index_H����
	{
		printf("��ȡ�ַ��� \"***\" �� S �дӵ� 1 ���ַ�����ĵ�һ�γ��ֵ�λ��...\n");
		i = Index_H(S, T, 1);
		printf(" \"***\" �� S �е�1���ַ����һ�γ��ֵ�λ��Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("��9\n������ SubString_H ����...\n");		//9.����SubString_H����
	{
		printf("�� Sub ���� S �е� 5 ���ַ���� 3 ���ַ�...\n");
		SubString_H(&Sub, S, 5, 3);
		printf(" Sub �е�Ԫ��Ϊ��Sub = ");						 
		StrPrint_H(Sub);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��11\n������ Replace_H ����...\n");			//11.����Replace_H����
	{
		printf("�� \"^^^^\" ���� V ...\n");
		StrAssign_H(&V, v);
		printf("�� \"^^^^\" �滻 S �е� \"***\" ...\n");
		Replace_H(&S, T, V);
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_H(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��13\n������ StrDelete_H ����...\n");		//13.����StrDelete_H����
	{
		printf("ɾ�� S �е� 5 ���ַ���� 4 ���ַ�...\n");
		StrDelete_H(&S, 5, 4); 
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_H(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��7\n������ ClearString_H ����...\n");		//7.����ClearString_H����
	{
		printf("��� S ǰ��");
		StrEmpty_H(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		ClearString_H(&S);
		printf("��� S ��");
		StrEmpty_H(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��8\n������ Concat_H ����...\n");			//8.����Concat_H����
	{
		printf("���� T �� V �γ�Tmp...\n");
		Concat_H(&Tmp, T, V);
		printf(" Tmp �е�Ԫ��Ϊ��Tmp = ");						 
		StrPrint_H(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	return 0;
}
