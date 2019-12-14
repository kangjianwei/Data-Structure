/**********************************************
 *							                  *
 * 文件夹: ▲05 数组和广义表\01 SequenceArray *
 * 							                  *
 * 文件名: SequenceArray.c                    *
 * 				     		                  *
 **********************************************/

#ifndef SEQUENCEARRAY_C
#define SEQUENCEARRAY_C

#include "SequenceArray.h" 								//**▲05 数组和广义表**//

Status InitArray(Array *A, int dim, ...)
{
	int elemtotal;										//统计数组中总元素个数 
	va_list ap;											//ap存放可变参数表信息 
	int i;
	
	if(dim<1 || dim>MAX_ARRAY_DIM)						//数组维数有限制 
		return ERROR;
	
	A->dim = dim;										//初始化数组维度 
	
	A->bounds = (int*)malloc(dim*sizeof(int));			//初始化数组维度信息表 
	if(!A->bounds)
		return OVERFLOW;
		
	elemtotal = 1;
	
	va_start(ap, dim);									//使ap指向第一个可变参数，dim相当于起始标识
	for(i=0; i<dim; i++)
	{
		A->bounds[i] = va_arg(ap, int);					//获取数组行、列信息
		if(A->bounds[i]<=0)
			return UNDERFLOW;

		elemtotal *= A->bounds[i];						
	}
	va_end(ap);											//置空ap
	
	A->base = (AElemType_Sq*)malloc(elemtotal*sizeof(AElemType_Sq));
	if(!A->base)										//初始化数组空间 
		return OVERFLOW;
	
	A->constants = (int*)malloc(dim*sizeof(int));		//初始化数组映像函数常量信息表 
	if(!A->constants)
		return OVERFLOW;

	A->constants[dim-1] = 1;
	for(i=dim-2; i>=0; i--)								//假设数组维度为2，则constants存储移动每一行、每一列所需跨越的元素个数 
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
		if(ind<0 || ind>=A.bounds[i])			//保证下标不越界 
			return OVERFLOW;
			 
		*off += A.constants[i] * ind;			//某个维度的单位元素个数*需要跨过的单位 
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
