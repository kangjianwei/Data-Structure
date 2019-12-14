#include <stdio.h>
#include "../../../���α��㷨ʵ��/��02 ���Ա�/04 SinglyLinkedList/SinglyLinkedList.c"	//**��02 ���Ա�**//

/* ����ԭ�� */
void Algo_10_38(LinkList L);
void MSort_10_38(LinkList SR[], LinkList TR[], int seg[], int len, int s, int t);//�鲢��ʼ�鲢�� 
void Merge_10_38(LinkList SR[], LinkList TR[], int seg[], int len, int s, int m, int t);
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
	Algo_10_38(L); 
	ListTraverse_L(L, PrintKey);
	printf("\n\n");	

	return 0;
}

/*��������������������������
����10.38��2-·�鲢(����) ��
��������������������������*/
void Algo_10_38(LinkList L)
{
	int k, len;
	int i, m, n;
	int seg[101];							//0�ŵ�Ԫ���� 
	LinkList SR[101], TR[101];
	LinkList p, r;
	
	for(len=0,p=L->next; p; p=p->next)		//��ʼ������ָ������ 
		SR[++len] = p;
	
	seg[0] = seg[1] = 1;
	
	for(k=2; k<=len; k++)						//����������������ɳ�ʼ�鲢�� 
	{
		if(SR[k]->data<SR[k-1]->data)
		{
			seg[0]++;
			seg[seg[0]] = k;
		}
	}
		
	MSort_10_38(SR, TR, seg, len, 1, seg[0]);	//�Ը���ʼ�鲢�ε�ָ������ 
		
	for(k=1,r=L; k<=len; k++)					//�����źõ�ָ��˳�����ż�¼
	{
		r->next = TR[k];
		r = r->next;
	}
	
	r->next = NULL;
}

void MSort_10_38(LinkList SR[], LinkList TR[], int seg[], int len, int s, int t)
{
	int m, ks, ke;
	LinkList R[len+1];
	
	if(s==t)
	{
		ks = seg[s];
		ke = ++s<=seg[0] ? (seg[s]-1) : len;
		for( ; ks<=ke; ks++)
			TR[ks] = SR[ks];
	}
	else
	{
		m = (s+t)/2;
		MSort_10_38(SR, R, seg, len, s, m);
		MSort_10_38(SR, R, seg, len, m+1, t);
		Merge_10_38(R, TR, seg, len, s, m, t);
	}	
}

void Merge_10_38(LinkList SR[], LinkList TR[], int seg[], int len, int s, int m, int t)
{
	int k;
	int is, ie, js, je;
	
	is = seg[s];
	ie = seg[m+1]-1;
	js = seg[m+1];
	je = ++t<=seg[0] ? (seg[t]-1) : len;
	
	k = is;
	
	while(is<=ie&&js<=je)
	{
		if(SR[is]->data<=SR[js]->data)
			TR[k++] = SR[is++];
		else
			TR[k++] = SR[js++];
	}
	
	while(is<=ie)
		TR[k++] = SR[is++];

	while(js<=je)
		TR[k++] = SR[js++];
}

void PrintKey(LElemType_L e)
{
	printf("%d ", e);
}
