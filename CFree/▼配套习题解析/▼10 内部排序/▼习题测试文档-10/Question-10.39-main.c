#include <stdio.h>
#include "../../../���α��㷨ʵ��/��01 ����/Status.h"//**��01 ����**//
#include "../../../���α��㷨ʵ��/��01 ����/Scanf.c"//**��01 ����**//

/* �궨�� */
#define SIZE 300				//���йؼ��ָ������� 

/* ����ԭ�� */
void Algo_10_39(int a[], int len1, int len2);
void Algo_5_18(int a[], int n, int k);					//������a[n]�е�Ԫ��ѭ������k��λ��
Status Reversal_5_18(int a[], int n, int start, int end);//��������a[n]�е�start�����end��֮���Ԫ��
void CreatArray_10_39(FILE *fp, int a[], int *len1, int *len2);
void Print_10_39(int a[], int size);

int main(int argc, char *argv[])
{
	FILE *fp;
	int a[SIZE+1];				//0�ŵ�Ԫ���� 
	int len1, len2;
	
	fp = fopen("Data/Algo_10_39.txt", "r");	
	CreatArray_10_39(fp, a, &len1, &len2);
	fclose(fp);

	printf("����ǰ��Σ�\n");
	Print_10_39(a, len1);
	printf("���к��Σ�\n");
	Print_10_39(&a[len1], len2);
	printf("�鲢������У�\n");
	Algo_10_39(a, len1, len2);	
	Print_10_39(a, a[0]);

	return 0;
}

/*����������������������������������������������������
����10.39���鲢����a[1..len1]��a[len1+1..len1+len2] ��
����������������������������������������������������*/
void Algo_10_39(int a[], int len1, int len2)	
{
	int i, j, k;
	
	if(len1>len2)						//ʹС���б�����a��ǰ��
		Algo_5_18(a, a[0], len1);		//��len1�κ�len2�ν���λ�� 	
	
	
	i=1, j=len1+1, k=0;					//len1^2<len1+len2
	
	while(i<j&&j<=a[0])					
	{
		while(a[i]<=a[j]&&i<j)			//�����������ŵ����� 
			i++;
		
		while(i<j&&a[i]>a[j]&&j<=a[0])	//j����Խ�� 
			k++, j++;
		
		Algo_5_18(&a[i], j-i, k); 
		
		i=i+k+1, k=0;
	}
}

void Algo_5_18(int a[], int n, int k)
{
	int p = k%n;							//ʵ��ѭ�����Ƶ�λ��
	
	if(p)									//����λ����Ϊ0����� 
	{
		Reversal_5_18(a, n, 1, n);
		Reversal_5_18(a, n, 1, p);
		Reversal_5_18(a, n, p+1, n);	
	}
}

Status Reversal_5_18(int a[], int n, int start, int end)
{
	int e, i;								//ֻ��eһ���ռ���ʱ�洢��������� 
	
	if(start<1 || end>n || start>end)
		return ERROR;
	
	for(i=0; i<(end-start+1)/2; ++i)		//��"������"����
	{
		e = a[end-i-1];
		a[end-i-1] = a[start+i-1];
		a[start+i-1] = e;
	}
	
	return OK;
}

void Print_10_39(int a[], int size)
{
	int i;
	
	for(i=1; i<=size; i++)
	{
		printf("%3d ", a[i]);
		
		if(i%15==0)
			printf("\n");
	}
	
	size%15==0 ? printf("\n") : printf("\n\n");
}

void CreatArray_10_39(FILE *fp, int a[], int *len1, int *len2)
{
	int k;

	Scanf(fp, "%d", len1);	
	for(k=1; k<=*len1; k++)
		Scanf(fp, "%d", &a[k]);	

	Scanf(fp, "%d", len2);	
	for( ; k<=*len1+*len2; k++)
		Scanf(fp, "%d", &a[k]);

	a[0] = *len1 + *len2;	
}
