/************************************
 *						            *
 * �ļ���: ��06 ���Ͷ�����\08 MFSet *
 * 						            *
 * �ļ���: MFSet.c                  *
 *    	    			            *
 * ��  ��: 6.8��6.9��6.10��6.11     * 
 *    	    					    *
 ************************************/

#ifndef MFSET_C
#define MFSET_C

#include "MFSet.h" 								//**��06 ���Ͷ�����**//

void Initial_mfset(FILE *fp, MFSet *S)
{
	int i;

	Scanf(fp, "%d", &(S->n));
	
	for(i=1; i<=S->n; i++)						//nodes[0]���� 
	{
		Scanf(fp, "%d", &i);
		S->nodes[i].data = i;
		S->nodes[i].parent = -1;
	}
}

/*�T�T�T�T�[
�U �㷨6.8�U 
�^�T�T�T�T*/
int find_mfset(MFSet S, int i)
{
	int j;
	
	if(i<1 || i>S.n)							//i������S����һ�Ӽ� 
		return -1; 

	for(j=i; S.nodes[j].parent>0; j=S.nodes[j].parent)
		;
	
	return j;
} 

/*�T�T�T�T�[
�U �㷨6.9�U 
�^�T�T�T�T*/
Status merge_mfset(MFSet *S, int i, int j)
{
	if(i<1 || j<1 || i>S->n || j>S->n)
		return ERROR;
	
	if(i!=j)									//i��j�ǲ�ͬԪ�� 
		S->nodes[i].parent = j;					//�̶�������Si����Sj 
	
	return OK;
} 

/*�T�T�T�T�T�[
�U �㷨6.10 �U 
�^�T�T�T�T�T*/
Status mix_mfset(MFSet *S, int i, int j)		//��parent��洢�Ӽ���������Ա��Ŀ�ĸ�ֵ 
{
	if(i<1 || j<1 || i>S->n || j>S->n)
		return ERROR;
	
	if(S->nodes[i].parent>S->nodes[j].parent)	//Si�г�Ա��Ŀ����
	{
		S->nodes[j].parent += S->nodes[i].parent; 
		S->nodes[i].parent = j;					//��Si����Sj 
	}
	else										//Sj�г�Ա��Ŀ����
	{
		S->nodes[i].parent += S->nodes[j].parent;
		S->nodes[j].parent = i;					//��Sj����Si 
	}
	
	return OK;
} 

/*�T�T�T�T�T�[
�U �㷨6.11 �U 
�^�T�T�T�T�T*/
int fix_mfset(MFSet *S, int i)					//��i����·�������н��ѹ��Ϊ���ĺ��ӽ�� 
{
	int j, k, t;
	
	if(i<1 || i>S->n)							//i������S����һ�Ӽ� 
		return -1; 
	
	for(j=i; S->nodes[j].parent>0; j=S->nodes[j].parent);	//�ҵ�i�����Ӽ������ 
	
	for(k=i; k!=j; k=t)							//˳��ѹ��·�� 
	{
		t = S->nodes[k].parent;					//tΪ��ǰ���ĸ���� 
		S->nodes[k].parent = j;
	}
	
	return j;	
}

Status BuildRelation_mfset(FILE *fp, Relation *R)
{
	int k;

	Scanf(fp, "%d", &(R->n));		
	if(R->n<0)
		return ERROR;
	
	for(k=1; k<=R->n; k++)
		Scanf(fp, "%d%d", &(R->nodes[k-1].i), &(R->nodes[k-1].j));
	
	return OK;
} 

Status EquivalenceClass_mfset_1(MFSet *S, Relation R)
{
	int k, x, y;
	
	for(k=0; k<R.n; k++)
	{
		x = find_mfset(*S, R.nodes[k].i);		//�ֱ���ȡ��ǰԪ�������Ӽ� 
		y = find_mfset(*S, R.nodes[k].j);
		merge_mfset(S, x, y);					//�ϲ��Ӽ� 
	}

	return OK;
}

Status EquivalenceClass_mfset_2(MFSet *S, Relation R)
{
	int k, x, y;
	
	for(k=0; k<R.n; k++)
	{
		x = fix_mfset(S, R.nodes[k].i);			//�ֱ���ȡ��ǰԪ�������Ӽ� 
		y = fix_mfset(S, R.nodes[k].j);
		mix_mfset(S, x, y);						//�ϲ��Ӽ� 
	}

	return OK;
}

int SubsetCount_mfset(MFSet S)
{
	int i, count;
	
	for(i=1,count=0; i<=S.n; i++) 
	{
		if(S.nodes[i].parent<0)
			count++;
	}
	
	return count;
}

void ShowSet_mfset(MFSet S)
{
	int i, j, k, count;
	int a[MAX_TREE_SIZE][MAX_TREE_SIZE] = {};
	int tmp[MAX_TREE_SIZE] = {}; 
	
	for(i=1; i<=S.n; i++)
	{
		j = find_mfset(S, i);					//�жϵ�i����������ĸ����� 
		if(j>0)
		{
			tmp[j]++;
			a[j][tmp[j]] = S.nodes[i].data;
		}	
	}
	
	k = SubsetCount_mfset(S);					//�Ӽ����� 
	
	printf("{");
	count = 0;
	
	for(i=1; i<=S.n; i++)
	{
		for(j=1; j<=S.n; j++)
		{
			if(a[i][j])
			{
				if(j==1)						//ĳ���ϵ�һ��Ԫ�� 
					printf("{%d", a[i][j]);
				else
					printf(",%d", a[i][j]);
				
				if(j==tmp[i])					//ĳ�������һ��Ԫ��
				{
					count++;
					printf("}");
					if(count!=k)				//�Ӽ�֮��Ҫ���� 
						printf(", ");
				}
			}
		}
	}
	
	printf("}\n");
}

#endif
