/**********************************************
 *							                  *
 * �ļ���: ��05 ����͹����\01 SequenceArray *
 * 							                  *
 * �ļ���: SequenceArray.c                    *
 * 				     		                  *
 **********************************************/

#ifndef SEQUENCEARRAY_C
#define SEQUENCEARRAY_C

#include "SequenceArray.h" 								//**��05 ����͹����**//

Status InitArray(Array *A, int dim, ...)
{
	int elemtotal;										//ͳ����������Ԫ�ظ��� 
	va_list ap;											//ap��ſɱ��������Ϣ 
	int i;
	
	if(dim<1 || dim>MAX_ARRAY_DIM)						//����ά�������� 
		return ERROR;
	
	A->dim = dim;										//��ʼ������ά�� 
	
	A->bounds = (int*)malloc(dim*sizeof(int));			//��ʼ������ά����Ϣ�� 
	if(!A->bounds)
		return OVERFLOW;
		
	elemtotal = 1;
	
	va_start(ap, dim);									//ʹapָ���һ���ɱ������dim�൱����ʼ��ʶ
	for(i=0; i<dim; i++)
	{
		A->bounds[i] = va_arg(ap, int);					//��ȡ�����С�����Ϣ
		if(A->bounds[i]<=0)
			return UNDERFLOW;

		elemtotal *= A->bounds[i];						
	}
	va_end(ap);											//�ÿ�ap
	
	A->base = (AElemType_Sq*)malloc(elemtotal*sizeof(AElemType_Sq));
	if(!A->base)										//��ʼ������ռ� 
		return OVERFLOW;
	
	A->constants = (int*)malloc(dim*sizeof(int));		//��ʼ������ӳ����������Ϣ�� 
	if(!A->constants)
		return OVERFLOW;

	A->constants[dim-1] = 1;
	for(i=dim-2; i>=0; i--)								//��������ά��Ϊ2����constants�洢�ƶ�ÿһ�С�ÿһ�������Խ��Ԫ�ظ��� 
		A->constants[i] = A->bounds[i+1] * A->constants[i+1];
	
	return OK; 
}

Status DestroyArray(Array *A)
{
	if(!A->base)
		return ERROR;
	free(A->base);
	A->base = NULL;
	
	if(!A->bounds)
		return ERROR;
	free(A->bounds);
	A->bounds = NULL;
	
	if(!A->constants)
		return ERROR;
	free(A->constants);
	A->constants = NULL;
	
	A->dim = 0;
	
	return OK;
}

Status LocateArray(Array A, va_list ap, int *off)
{
	int i, ind;
	
	*off = 0;
	
	for(i=0; i<A.dim; i++)
	{
		ind = va_arg(ap, int);
		if(ind<0 || ind>=A.bounds[i])			//��֤�±겻Խ�� 
			return OVERFLOW;
			 
		*off += A.constants[i] * ind;			//ĳ��ά�ȵĵ�λԪ�ظ���*��Ҫ����ĵ�λ 
	}
	
	return OK;
}

Status ValueArray(Array A, AElemType_Sq *e, ...)
{
	va_list ap;
	Status result;
	int off;
	
	va_start(ap, *e);

	result = LocateArray(A, ap, &off);
	if(result==OVERFLOW)
		return result;

	*e = *(A.base + off);
	
	return OK;
}

Status AssignArray(Array *A, AElemType_Sq e, ...)
{
	va_list ap;
	Status result;
	int off;
	
	va_start(ap, e);
	
	result = LocateArray(*A, ap, &off);
	if(result==OVERFLOW)
		return result;
		
	*(A->base+off) = e;
	
	return OK;
}

void ArrayPrint(Array A)					
{
	int i, j;
	
	for(i=0,j=1; i<A.dim; i++)
		j *= A.bounds[i];
	
	for(i=0; i<j; i++)
		printf("%d ", A.base[i]);
}

#endif
