/******************************************
 *								          *
 * �ļ���: ��06 ���Ͷ�����\09 HuffmanTree *
 * 								          *
 * �ļ���: HuffmanTree.c                  *
 * 								          *
 * ��  ��: 6.12��6.13                     * 
 *    	    			                  * 
 ******************************************/

#ifndef HUFFMANTREE_C
#define HUFFMANTREE_C

#include "HuffmanTree.h" 								//**��06 ���Ͷ�����**//

void InitTree_HT(HuffmanTree *HT)
{
	*HT = NULL;
}

Status CreateHuffmanTree_HT(FILE *fp, HuffmanTree *HT)
{
	int m, n;
	int w[MAX_TREE_SIZE];
	HuffmanTree p;
	int i;
	int s1, s2;

	Scanf(fp, "%d", &n); 	
	printf("¼���������Ҷ�ӽ������� %d\n", n);
	
	printf("����¼���Ҷ�ӽ���Ȩֵ�� ");
	for(i=1; i<=n; i++)									//0�ŵ�Ԫ����
	{
		Scanf(fp, "%d", &w[i]);
		printf("%d ", w[i]);
	}
	printf("\n");
	
	m = 2*n - 1;										//����������Ч������
		
	*HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));	//0�ŵ�Ԫ����
	if(!(*HT))
		exit(OVERFLOW);
	
	(*HT)[0].weight = n;								//����0�ŵ�Ԫ��Ȩֵ�洢��������Ҷ�Ӹ���
 		
	for(i=1; i<=m; i++)									//��ʼ�����[1...2*n+1]���洢Ҷ�ӽ�㼰˫�׽�� 
	{		
		if(i<=n)										 
			(*HT)[i].weight = w[i];						//[1...n]��Ҷ�ӽ��
		else											 
			(*HT)[i].weight = 0;						//[n+1...2*n+1]��˫�׽��

		(*HT)[i].parent = 0;
		(*HT)[i].lchild = 0;
		(*HT)[i].rchild = 0; 
	} 
	
	for(i=n+1; i<=m; i++)								//������������
	{
		Select_HT(*HT, i-1, &s1, &s2);
	
		(*HT)[s1].parent = (*HT)[s2].parent = i;

		(*HT)[i].lchild = s1;
		(*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
	
	return OK;
} 

Status Select_HT(HuffmanTree HT, int end, int *order_1, int *order_2)
{
	HuffmanTree p;
	int i, count;
	int m, n, tmp;
	
	if(end<2)
		return ERROR;
	
	for(i=1,count=1; i<=end; i++)						//�����ҳ�ǰ����δ�������Ľ�� 
	{
		if(HT[i].parent==0)
		{
			if(count==1)
				m = i;
			if(count==2)
				n = i;
			count++;
		}
		
		if(count>2)
			break;
	}
	
	if(HT[m].weight>HT[n].weight)						//��m����Ȩ��С�ڵ���n����Ȩ�� 
	{
		tmp = n;
		n = m;
		m = tmp;
	}
	
	i = (m>n ? m : n) + 1;
	while(i<=end)										//����������Ѱ�Ҹ�С����ǰ�Ľ��
	{	
		if(HT[i].parent==0)
		{
			if(HT[i].weight<HT[m].weight)
			{
				n = m;
				m = i;
			}
			else
			{
				if(HT[i].weight>=HT[m].weight && HT[i].weight<HT[n].weight)
					n = i;
			}		
		}
		
		i++;
	}
	
	*order_1 = HT[m].weight<=HT[n].weight ? m : n;
	*order_2 = HT[m].weight>HT[n].weight ? m : n;
	
	return OK;
}

/*�T�T�T�T�T�[
�U �㷨6.12 �U 
�^�T�T�T�T�T*/
Status HuffmanCodeing_HT_1(HuffmanTree HT, HuffmanCode *HC)
{
	char* code;
	int n, i;
	int start, c, f;
	
	n = HT[0].weight;									//Ҷ�ӽ����� 
	
	*HC = (HuffmanCode)malloc((n+1)*sizeof(HCNode));
	if(!(*HC))
		exit(OVERFLOW);
	
	code = (char*)malloc(n*sizeof(char));
	if(!code)
		exit(OVERFLOW);	
	
	code[n-1] = '\0';									//�ַ�����β 
	for(i=1; i<=n; i++)									//�����ÿ��Ҷ�ӽ��Ĺ��������� 
	{
		start = n - 1;									//��ֵ��� 
		for(c=i,f=HT[i].parent; f!=0; c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c)
				code[--start] = '0';
			else
				code[--start] = '1';
		}
		
		(*HC)[i] = (char*)malloc((n-start)*sizeof(char));
		
		strcpy((*HC)[i], &code[start]);					//��start��ʼ���� 
	}
	
	free(code);
}

/*�T�T�T�T�T�[
�U �㷨6.13 �U 
�^�T�T�T�T�T*/
Status HuffmanCodeing_HT_2(HuffmanTree HT, HuffmanCode *HC)
{
	int m, n, i;
	int cdlen;
	int p, mark[MAX_TREE_SIZE];
	char* code;
		 
	n = HT[0].weight;									//��������Ҷ�ӽ�����
	m = 2 * n - 1;										//�������������� 
	
	*HC = (HuffmanCode)malloc((n+1)*sizeof(HCNode));
	if(!(*HC))
		exit(OVERFLOW);	

	code = (char*)malloc(n*sizeof(char));
	if(!code)
		exit(OVERFLOW);	

	for(i=1; i<=n; i++)
		code[i] = '\0';
		
	for(i=1; i<=m; i++)									//��ʼ�����ʱ�� 
		mark[i] = 0;									//0��1��2�ֱ��ʾ���ʹ�0�Ρ�1�Ρ�2��
	
	p = m;
	cdlen = 0;
	
	while(p)
	{
		if(mark[p]==0)									//��һ�η��ʴ˽��
		{
			mark[p] = 1;
			if(HT[p].lchild!=0)							//������� 
			{
				p = HT[p].lchild;						//p������һ��							
				code[cdlen] = '0';
				cdlen++;
			}
			else
			{
				if(HT[p].rchild==0)						//�ҵ�Ҷ�ӽ�� 
				{
					(*HC)[p] = (char*)malloc((cdlen+1)*sizeof(char));
					strcpy((*HC)[p], code);				//���Ʊ��봮 
				}
			}
		}
		else
		{
			if(mark[p]==1)								//�ڶ��η��ʴ˽��
			{
				mark[p] = 2;
				if(HT[p].rchild!=0)
				{
					p = HT[p].rchild;
					code[cdlen] = '1';
					cdlen++;
				}
			}
			else	//mark[p]==2						//�����η��� 
			{
				p = HT[p].parent;						//�˻ص������
				cdlen--;								//���볤�ȼ�1
				code[cdlen] = '\0'; 
			}
		}	
	}
	
	free(code);
} 

void ShowHuffmanTree_HT(HuffmanTree HT)
{
	int i;
	
	printf("���������ש������ש������ש������ש�������\n");
	printf("��*order��weight��parent��lchild��rchild��\n");
	for(i=0; i<=2*HT[0].weight-1; i++)
	{
		if(i==0)
			printf("��  %2d  �� %4d ��  ��  ��  ��  ��  ��  ��\n", i, HT[i].weight);
		else
			printf("��  %2d  �� %4d ��  %2d  ��  %2d  ��  %2d  ��\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
	}
	printf("���������ߩ������ߩ������ߩ������ߩ�������\n");
}

void ShowHuffmanCode_HT(HuffmanTree HT, HuffmanCode HC)
{
	int i;
	
	printf("���������ש������ש������ש���������������\n");
	printf("��*order��weight��      ��  ����������  ��\n");
	for(i=1; i<=HT[0].weight; i++)
		printf("��  %2d  �� %4d ��������  %-14s��\n", i, HT[i].weight, HC[i]);	
	printf("���������ߩ������ߩ������ߩ������ߩ�������\n");
}

#endif 
