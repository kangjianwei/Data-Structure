/*************************************
 *                                   *
 * �ļ���: ��04 ��\01 SequenceString *
 *                                   *
 * ��  ��: ˳����غ�������        *
 *                                   *
 *************************************/

#include <stdio.h>
#include "SequenceString.c" 							//**��04 ��**//

int main(int argc, char **argv)
{
	char *chars = "abcdef g";
	char *t = "** *";
	char *v = "^^^  ^";
	SString S, Tmp, T, V, Sub;
	int i;
	
	printf("��1\n������ StrAssign_Sq ����...\n");		//1.����StrAssign_Sq����
	{
		printf("Ϊ˳�� Tmp ��ֵ...\n");					 
		StrAssign_Sq(Tmp, chars);
		printf("\n");
	} 
	PressEnter;
	
	printf("��3\n������ StrEmpty_Sq ����...\n");		//3.����StrEmpty_Sq����
	{
		StrEmpty_Sq(Tmp) ? printf(" Tmp Ϊ�գ���\n") : printf(" Tmp ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��5\n������ StrLength_Sq ����...\n");		//5.����StrLength_Sq����
	{
		i = StrLength_Sq(Tmp);
		printf(" Tmp �ĳ���Ϊ %d \n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("��14\n������ StrPrint_Sq ����...\n");		//14.����StrPrint_Sq����
	{
		printf(" Tmp �е�Ԫ��Ϊ��Tmp = ");						 
		StrPrint_Sq(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��2\n������ StrCopy_Sq ����...\n");			//2.����StrCopy_Sq����
	{
		printf("���� Tmp �� S ...\n");
		StrCopy_Sq(S, Tmp);
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��4\n������ StrCompare_Sq ����...\n");		//4.����StrCompare_Sq����
	{
		printf("�Ƚ��ַ��� Tmp �� S ...\n");
		i = StrCompare_Sq(Tmp, S);
		i==0 ? printf("Tmp==S����\n") : (i<0 ? printf("Tmp<S����\n") : printf("Tmp>S����\n"));
		printf("\n");
	}
	PressEnter;
	
	printf("��11\n������ StrInsert_Sq ����...\n");		//11.����StrInsert_Sq����
	{
		printf("�� \"***\" ����T...\n");
		StrAssign_Sq(T, t);
		printf("�� S �ĵ� 5 ���ַ�ǰ����T...\n");
		StrInsert_Sq(S, 5, T);
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��9\n������ Index_Sq_1 ����...\n");			//9-1.����Index_Sq_1����
	{
		printf("��ȡ�ַ��� \"***\" �� S �дӵ�1���ַ�����ĵ�һ�γ��ֵ�λ��...\n");
		i = Index_Sq_1(S, T, 1);
		printf(" \"***\" �� S �е�1���ַ����һ�γ��ֵ�λ��Ϊ%d\n", i);
		printf("\n");
	}
	PressEnter;
	
	printf("��8\n������ SubString_Sq ����...\n");		//8.����SubString_Sq����
	{
		printf("�� Sub ���� S �е� 5 ���ַ���� 3 ���ַ�...\n");
		SubString_Sq(Sub, S, 5, 3);
		printf(" Sub �е�Ԫ��Ϊ��Sub = ");						 
		StrPrint_Sq(Sub);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��10\n������ Replace_Sq��Index_Sq_2 ����...\n");//9-2��10.����Replace_Sq��Index_Sq_2����
	{
		printf("�� \"^^^^\" ����V...\n");
		StrAssign_Sq(V, v);
		printf("�� \"^^^^\" �滻S�е� \"***\" ...\n");
		Replace_Sq(S, T, V);
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��12\n������ StrDelete_Sq ����...\n");		//12.����StrDelete_Sq����
	{
		printf("ɾ�� S �е� 5 ���ַ���� 4 ���ַ�...\n");
		StrDelete_Sq(S, 5, 4); 
		printf(" S �е�Ԫ��Ϊ��S = ");						 
		StrPrint_Sq(S);
		printf("\n\n");
	}
	PressEnter;
	
	printf("��6\n������ ClearString_Sq ����...\n");		//6.����ClearString_Sq����
	{
		printf("��� S ǰ��");
		StrEmpty_Sq(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		ClearString_Sq(S);
		printf("��� S ��");
		StrEmpty_Sq(S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
		printf("\n");
	}
	PressEnter;
	
	printf("��7\n������ Concat_Sq ����...\n");			//7.����Concat_Sq����
	{
		printf("���� T �� V �γ� Tmp ...\n");
		Concat_Sq(Tmp, T, V);
		printf(" Tmp �е�Ԫ��Ϊ��Tmp = ");						 
		StrPrint_Sq(Tmp);
		printf("\n\n");
	}
	PressEnter;
	
	return 0;
}
