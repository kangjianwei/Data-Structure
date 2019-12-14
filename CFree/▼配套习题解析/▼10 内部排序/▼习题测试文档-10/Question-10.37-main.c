#include <stdio.h>
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
void Algo_10_37(LinkList L);
void Merge_10_37(LinkList SR[], LinkList TR[], int i, int m, int n);	//��ָ���ָ��鲢SR��TR 
void PrintKey(LElemType_L e);

int main(int argc, char *argv[])
{	
	FILE *fp;
	LinkList L;
	int num;
		
	printf("���������һ����������...\n");
	fp = fopen("Data/Algo_10_37.txt", "r");
	Scanf(fp, "%d", &num);
	CreateList_TL(fp, &L, num);
	ListTraverse_L(L, PrintKey);
	printf("\n\n");	

	printf("���ؼ��ְ�����˳������...\n");
	Algo_10_37(L); 
	ListTraverse_L(L, PrintKey);
	printf("\n\n");	

	return 0;
}

/*��������������������������
����10.37����ι鲢(����) ��
��������������������������*/
void Algo_10_37(LinkList L)
{
	int l, len, k;
	int i, m, n;
	LinkList SR[101], TR[101];				//����һ��������ָ����������ݽ���ָ�� 
	LinkList p, r;
	
	for(len=0,p=L->next; p; p=p->next)		//��ʼ������ָ������ 
		SR[++len] = p;
	
	for(l=1; l<=len; l*=2)					//�ֶι鲢 
	{
		i=1, m=l;
		n = 2*m>len ? len : 2*m;
		
		while(i<len&&m<len)
		{
			Merge_10_37(SR, TR, i, m, n);
			i = n+1;
			m = i+l-1;
			n = i+2*l-1;
		}
		
		for(k=1; k<=len; k++)
			SR[k] = TR[k];
	}
	
	for(k=1,r=L; k<=len; k++)				//�����źõ�ָ��˳�����ż�¼
	{
		r->next = SR[k];
		r = r->next;
	}
	
	r->next = NULL;
}

void Merge_10_37(LinkList SR[], LinkList TR[], int i, int m, int n)
{	
	int j, k;
	
	for(j=m+1,k=i; i<=m&&j<=n; ++k)					//��SR�м�¼��С����ز���TR 
	{
		if(SR[i]->data<=SR[j]->data)
			TR[k] = SR[i++];
		else
			TR[k] = SR[j++];
	}
		
	while(i<=m)										//��ʣ���SR[i..m]���Ƶ�TR 
		TR[k++] = SR[i++];
	
	while(j<=n)										//��ʣ���SR[j..n]���Ƶ�TR 
		TR[k++] = SR[j++];
}

void PrintKey(LElemType_L e)
{
	printf("%d ", e);
}
