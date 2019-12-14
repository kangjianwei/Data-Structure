#include <stdio.h>
#include "../../../▲课本算法实现/▲01 绪论/Status.h"//**▲01 绪论**//
#include "../../../▲课本算法实现/▲01 绪论/Scanf.c"//**▲01 绪论**//

/* 宏定义 */
#define SIZE 300				//序列关键字个数上限 

/* 函数原型 */
void Algo_10_39(int a[], int len1, int len2);
void Algo_5_18(int a[], int n, int k);					//将数组a[n]中的元素循环右移k个位置
Status Reversal_5_18(int a[], int n, int start, int end);//逆置数组a[n]中第start个与第end个之间的元素
void CreatArray_10_39(FILE *fp, int a[], int *len1, int *len2);
void Print_10_39(int a[], int size);

int main(int argc, char *argv[])
{
	FILE *fp;
	int a[SIZE+1];				//0号单元计数 
	int len1, len2;
	
	fp = fopen("Data/Algo_10_39.txt", "r");	
	CreatArray_10_39(fp, a, &len1, &len2);
	fclose(fp);

	printf("序列前半段：\n");
	Print_10_39(a, len1);
	printf("序列后半段：\n");
	Print_10_39(&a[len1], len2);
	printf("归并后的序列：\n");
	Algo_10_39(a, len1, len2);	
	Print_10_39(a, a[0]);

	return 0;
}

/*━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃题10.39：归并序列a[1..len1]和a[len1+1..len1+len2] ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━*/
void Algo_10_39(int a[], int len1, int len2)	
{
	int i, j, k;
	
	if(len1>len2)						//使小序列保持在a的前端
		Algo_5_18(a, a[0], len1);		//将len1段和len2段交换位置 	
	
	
	i=1, j=len1+1, k=0;					//len1^2<len1+len2
	
	while(i<j&&j<=a[0])					
	{
		while(a[i]<=a[j]&&i<j)			//跳过不需重排的序列 
			i++;
		
		while(i<j&&a[i]>a[j]&&j<=a[0])	//j不能越界 
			k++, j++;
		
		Algo_5_18(&a[i], j-i, k); 
		
		i=i+k+1, k=0;
	}
}

void Algo_5_18(int a[], int n, int k)
{
	int p = k%n;							//实际循环右移的位数
	
	if(p)									//右移位数不为0的情况 
	{
		Reversal_5_18(a, n, 1, n);
		Reversal_5_18(a, n, 1, p);
		Reversal_5_18(a, n, p+1, n);	
	}
}

Status Reversal_5_18(int a[], int n, int start, int end)
{
	int e, i;								//只用e一个空间临时存储数组的内容 
	
	if(start<1 || end>n || start>end)
		return ERROR;
	
	for(i=0; i<(end-start+1)/2; ++i)		//用"交换法"逆置
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
