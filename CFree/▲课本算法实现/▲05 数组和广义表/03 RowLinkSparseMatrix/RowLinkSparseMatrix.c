/****************************************************
 *							                        *
 * �ļ���: ��05 ����͹����\03 RowLinkSparseMatrix *
 *							                        *
 * �ļ���: RowLinkSparseMatrix.c                    *
 *							                        *
 * ��  ��: 5.3                                      * 
 *							                        *
 ***************************************************/

#ifndef ROWLINKSPARSEMATRIX_C
#define ROWLINKSPARSEMATRIX_C

#include "RowLinkSparseMatrix.h" 				//**��05 ����͹����**//

Status CreateSMatrix_RL(FILE *fp, int n, ...)
{
	int count, k;
	RLSMatrix *M;
		
	if(n<1)
		return ERROR;

	va_list ap;	
	va_start(ap, n);
	
	for(count=1; count<=n; count++)
	{
		M = va_arg(ap, RLSMatrix *);
		
		for(k=0; k<=MAXRC; ++k)					//��ʼ������rpos 
			(*M).rpos[k] = 0;
			
		Scanf(fp, "%d%d%d", &((*M).mu), &((*M).nu), &((*M).tu));

		for(k=1; k<=(*M).tu; k++)
		{
			Scanf(fp, "%d%d%d", &((*M).data[k].i), &((*M).data[k].j), &((*M).data[k].e));
			
			if((*M).rpos[(*M).data[k].i]==0)	//��¼ÿ�е�һ������Ԫ��λ��
				(*M).rpos[(*M).data[k].i] = k;	//��ֻ���ڵ�ǰ���з���Ԫ������¼�¼��
		}
	
		for(k=(*M).mu; k>=1; --k)				//������Щû�з���Ԫ���� 
		{
			if((*M).rpos[k]==0)
			{
				if(k==(*M).mu)					//�����һ���޷���Ԫ�������⴦��
					(*M).rpos[k] = (*M).tu + 1;
				else
					(*M).rpos[k] = (*M).rpos[k+1];
			}
		}	
	}
	
	va_end(ap);
	
	return OK;
}

void DestroySMatrix_RL(RLSMatrix *M)
{
	int i;
	
	M->mu = 0;
	M->nu = 0;
	M->tu = 0;
	
	for(i=0; i<=MAXRC; ++i)
		M->rpos[i] = 0;
}

void PrintSMatrix_RL(RLSMatrix M)
{
	int r, c;
	int k = 1;
	
	for(r=1; r<=M.mu; ++r)
	{
		for(c=1; c<=M.nu; ++c)
		{
			if(r==M.data[k].i && c==M.data[k].j)
			{
				printf("%3d ", M.data[k].e);
				k++;
			}
			else
				printf("  0 ");
		}
		printf("\n");
	}
	
	printf("rpos = ");
	for(k=1; k<=M.mu; ++k)
		printf("%d ", M.rpos[k]);
	printf("\n");
}

void CopySMatrix_RL(RLSMatrix M, RLSMatrix *T)
{
	(*T) = M;											//�ṹ����ֱ�Ӹ���
}

Status AddSMatri_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q)
{
	int m, n, k;
	int i;
	
	if(M.mu!=N.mu || M.nu!=N.nu)
	{
		printf("����������ӣ���\n");
		return ERROR;	
	}
	
	Q->mu = M.mu;
	Q->nu = M.nu;
	Q->tu = 0;
	m = n = k = 1;
	
	while(m<=M.tu && n<=N.tu)							//���α���M��N����Ԫ�� 
	{
		if(M.data[m].i<N.data[n].i)
		{
			Q->data[k] = M.data[m];
			m++;
		}
		else if(M.data[m].i>N.data[n].i)
		{
			Q->data[k] = N.data[n];
			n++;
		}
		else											//M.data[m].i==N.data[n].i
		{
			if(M.data[m].j<N.data[n].j)
			{
				Q->data[k] = M.data[m];
				m++;
			}
			else if(M.data[m].j>N.data[n].j)
			{
				Q->data[k] = N.data[n];
				n++;
			}
			else										//M.data[m].j==N.data[n].j
			{
				if(M.data[m].e+N.data[n].e)
				{
					Q->data[k].i = M.data[m].i;
					Q->data[k].j = M.data[m].j;
					Q->data[k].e = M.data[m].e+N.data[n].e;
					m++;
					n++;
				}
				else
				{
					m++;
					n++;
					continue;
				}		
			}
		}
		
		k++;
		Q->tu++;
	}
	
	while(m<=M.tu)
	{
		Q->data[k] = M.data[m];
		m++;
		k++;
		Q->tu++;
	}
	
	while(n<=N.tu)
	{
		Q->data[k] = N.data[n];
		n++;
		k++;
		Q->tu++;
	}
	
	for(i=0; i<=MAXRC; ++i)								//��ʼ������rpos
		Q->rpos[i] = 0;
	
	for(i=1; i<=Q->tu; ++i)		
	{
		m = Q->data[i].i;								//��ǰ��Ԫ����Ԫ�����ڵ���
		if(Q->rpos[m]==0)								//��¼ÿ�е�һ������Ԫ��λ��
			Q->rpos[m] = i;								//��ֻ���ڵ�ǰ���з���Ԫ������¼�¼��
	}
	
	for(i=Q->mu; i>=1; --i)								//������Щû�з���Ԫ���� 
	{
		if(Q->rpos[i]==0)
		{
			if(i==Q->mu)								//�����һ���޷���Ԫ�������⴦��
				Q->rpos[i] = Q->tu + 1;
			else
				Q->rpos[i] = Q->rpos[i+1];
		}
	}
	
	return OK;
}

Status SubSMatrix_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q)
{
	int m, n, k;
	int i;
	
	if(M.mu!=N.mu || M.nu!=N.nu)
	{
		printf("���������������\n");
		return ERROR;	
	}
	
	Q->mu = M.mu;
	Q->nu = M.nu;
	Q->tu = 0;
	m = n = k = 1;
	
	while(m<=M.tu && n<=N.tu)
	{
		if(M.data[m].i<N.data[n].i)
		{
			Q->data[k] = M.data[m];
			m++;
		}		
		else if(M.data[m].i>N.data[n].i)
		{
			Q->data[k].i =  N.data[n].i;
			Q->data[k].j =  N.data[n].j;
			Q->data[k].e = -N.data[n].e;
			n++;
		}
		else											//M.data[m].i==N.data[n].i
		{
			if(M.data[m].j<N.data[n].j)
			{
				Q->data[k] = M.data[m];
				m++;
			}
			else if(M.data[m].j>N.data[n].j)
			{
				Q->data[k].i =  N.data[n].i;
				Q->data[k].j =  N.data[n].j;
				Q->data[k].e = -N.data[n].e;
				n++;
			}
			else										//M.data[m].j==N.data[n].j
			{
				if(M.data[m].e-N.data[n].e)
				{
					Q->data[k].i = M.data[m].i;
					Q->data[k].j = M.data[m].j;
					Q->data[k].e = M.data[m].e-N.data[n].e;
					m++;
					n++;
				}
				else
				{
					m++;
					n++;
					continue;
				}		
			}
		}
		
		k++;
		Q->tu++;
	}
	
	while(m<=M.tu)
	{
		Q->data[k] = M.data[m];
		m++;
		k++;
		Q->tu++;
	}
	
	while(n<=N.tu)
	{
		Q->data[k].i =  N.data[n].i;
		Q->data[k].j =  N.data[n].j;
		Q->data[k].e = -N.data[n].e;;
		n++;
		k++;
		Q->tu++;
	}
	
	for(i=0; i<=MAXRC; ++i)								//��ʼ������rpos
		Q->rpos[i] = 0;
	
	for(i=1; i<=Q->tu; ++i)		
	{
		m = Q->data[i].i;								//��ǰ��Ԫ����Ԫ�����ڵ���
		if(Q->rpos[m]==0)								//��¼ÿ�е�һ������Ԫ��λ��
			Q->rpos[m] = i;								//��ֻ���ڵ�ǰ���з���Ԫ������¼�¼��
	}
	
	for(i=Q->mu; i>=1; --i)								//������Щû�з���Ԫ���� 
	{
		if(Q->rpos[i]==0)
		{
			if(i==Q->mu)								//�����һ���޷���Ԫ�������⴦��
				Q->rpos[i] = Q->tu + 1;
			else
				Q->rpos[i] = Q->rpos[i+1];
		}
	}
	
	return OK;
}

/*�T�T�T�T�[
�U �㷨5.3�U 
�^�T�T�T�T*/
Status MultSMatrix_RL(RLSMatrix M, RLSMatrix N, RLSMatrix *Q)
{
	int arow, brow, p, q, tp, tq, ccol;
	int ctemp[N.nu+1];									//Q�и���Ԫ��ֵ�ۼ�����ctemp[0]���� 
	int i, m;
	
	if(M.nu!=N.mu)										//M��������N���� 
	{
		printf("����������ˣ���\n");
		return ERROR;	
	}
	
	Q->mu = M.mu;										//Q��ʼ�� 
	Q->nu = N.nu;
	Q->tu = 0;
	
	if(M.tu*N.tu)										//Q�Ƿ������
	{
		for(arow=1; arow<=M.mu; ++arow)					//����M��ÿһ��
		{												//arowΪ�˻�Ԫ����Q�е��к� 
			for(i=0; i<=N.nu; ++i)						//��ʼ��Q����Ԫ��ֵ������
				ctemp[i] = 0;
			
			if(arow<M.mu)
				tp = M.rpos[arow+1];					//tpָ��M��ǰ�е���һ�е�һ������Ԫλ��
			else
				tp = M.tu + 1;
	
			for(p=M.rpos[arow]; p<tp; ++p)				//p��M��ǰ�е�һ������Ԫλ�ÿ�ʼ�ۼ�
			{
				brow = M.data[p].j;						//��M��ǰ����ÿһ������Ԫ���ҵ���ӦԪ��N�е��к�
				
				if(brow<N.mu)
					tq = N.rpos[brow+1];				//tqָ��N��ǰ�е���һ�е�һ������Ԫλ��
				else
					tq = N.tu + 1;
					
				for(q=N.rpos[brow]; q<tq; ++q)			//q��N��ǰ�е�һ������Ԫλ�ÿ�ʼ�ۼ�
				{
					ccol = N.data[q].j;					//�˻�Ԫ����Q�е��к�
					ctemp[ccol] += M.data[p].e * N.data[q].e;
				}
			}//Q�е�arow��Ԫ������� 
			
			for(ccol=1; ccol<=Q->nu; ++ccol)
			{
				if(ctemp[ccol])							//��Q�е�arow��ccol��Ԫ�ز�Ϊ0 
				{
					++Q->tu;
 					if(Q->tu>MAXSIZE)					//����Ԫ������������ 
						return ERROR;
					Q->data[Q->tu].i = arow;
					Q->data[Q->tu].j = ccol;
					Q->data[Q->tu].e = ctemp[ccol];
				}
			}//for(ccol)
		}//for(arow)
	}//if
		
	for(i=0; i<=MAXRC; ++i)								//��ʼ������rpos
		Q->rpos[i] = 0;
	
	for(i=1; i<=Q->tu; ++i)		
	{
		m = Q->data[i].i;								//��ǰ��Ԫ����Ԫ�����ڵ���
		if(Q->rpos[m]==0)								//��¼ÿ�е�һ������Ԫ��λ��
			Q->rpos[m] = i;								//��ֻ���ڵ�ǰ���з���Ԫ������¼�¼��
	}
	
	for(i=Q->mu; i>=1; --i)								//������Щû�з���Ԫ���� 
	{
		if(Q->rpos[i]==0)
		{
			if(i==Q->mu)								//�����һ���޷���Ԫ�������⴦��
				Q->rpos[i] = Q->tu + 1;
			else
				Q->rpos[i] = Q->rpos[i+1];
		}
	}
	
	return OK;
}

void TransposeSMatrix_RL(RLSMatrix M, RLSMatrix *T)
{
	int p, q, col;
	int i, m;
	
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	
	for(i=0; i<=MAXRC; ++i)								//��ʼ������rpos
		T->rpos[i] = 0;
	
	if(T->tu)
	{
		q = 1;											//q����T�з���Ԫ���� 
		for(col=1; col<=M.nu; ++col)					//col����M���У�T���� 
		{
			for(p=1; p<=M.tu; ++p)						//p����M�з���Ԫ����
			{
				if(M.data[p].j==col)
				{
					T->data[q].i = M.data[p].j;			//M���б�ΪT���� 
					T->data[q].j = M.data[p].i;			//M���б�ΪT����
					T->data[q].e = M.data[p].e;			//ÿ����Ԫ��ֵ���� 
				
					if(T->rpos[col]==0)					//��¼ÿ�е�һ������Ԫ��λ��
						T->rpos[col] = q;				//��ֻ���ڵ�ǰ���з���Ԫ������¼�¼��
					
					++q;
				}				
			}
		}
	}
	
	for(i=T->mu; i>=1; --i)								//������Щû�з���Ԫ���� 
	{
		if(T->rpos[i]==0)
		{
			if(i==T->mu)								//�����һ���޷���Ԫ�������⴦��
				T->rpos[i] = T->tu + 1;
			else
				T->rpos[i] = T->rpos[i+1];
		}
	}
}

void FastTransposeSMatrix_RL(RLSMatrix M, RLSMatrix *T)
{
	int col, t, p, q;
	int num[M.nu];										//num[col]��ʾM��col���з���Ԫ�ĸ��� 
	int copt[M.nu];										//copt[col]��ʾM��col�е�һ������Ԫ��T->data��ǡ����λ�� 
	int i, m;
	
	T->mu = M.nu;
	T->nu = M.mu;
	T->tu = M.tu;
	
	if(T->tu)
	{
		for(col=1; col<=M.nu; ++col)
			num[col] = 0;								//��ʼ������num
		
		for(t=1; t<=M.tu; ++t)							//t����M����Ԫ��
			++num[M.data[t].j];							//ͳ��M��ÿ�з���Ԫ����
		
		copt[1] = 1;
		for(col=2; col<=M.nu; ++col)
			copt[col] = copt[col-1] + num[col-1];
		
		for(p=1; p<=M.tu; ++p)							//����ɨ��M�е���Ԫ�� 
		{
			col = M.data[p].j;							//colΪM�е�p����Ԫ����Ԫ�ص��� 
			q = copt[col];								//qΪ��ǰ��Ԫ��Ԫ����T��Ӧ���õ�λ�� 
			T->data[q].i = M.data[p].j;
			T->data[q].j = M.data[p].i;
			T->data[q].e = M.data[p].e;
			++copt[col];								//����������Ԫ��ʱλ����һ 
		}
	}
	
	for(i=0; i<=MAXRC; ++i)								//��ʼ������rpos
		T->rpos[i] = 0;
	
	for(i=1; i<=T->tu; ++i)		
	{
		m = T->data[i].i;								//��ǰ��Ԫ����Ԫ�����ڵ���
		if(T->rpos[m]==0)								//��¼ÿ�е�һ������Ԫ��λ��
			T->rpos[m] = i;								//��ֻ���ڵ�ǰ���з���Ԫ������¼�¼��
	}
	
	for(i=T->mu; i>=1; --i)								//������Щû�з���Ԫ���� 
	{
		if(T->rpos[i]==0)
		{
			if(i==T->mu)								//�����һ���޷���Ԫ�������⴦��
				T->rpos[i] = T->tu + 1;
			else
				T->rpos[i] = T->rpos[i+1];
		}
	}
}

#endif
