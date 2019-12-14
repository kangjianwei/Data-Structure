/*========
 * ��ά����
 =========*/

#include "Array.h"  //**��05 ����͹����**//

/*
 * ��ʼ����
 *
 * ��ʼ��ά��Ϊdim�����飬�ɱ����ָʾ��ά�ȵĴ�С��
 */
Status InitArray(Array* A, int dim, ...) {
    int elemtotal;  // ͳ����������Ԫ�ظ���
    va_list ap;     // ap��ſɱ��������Ϣ��ָʾ��ά�ȵĴ�С
    int i;
    
    if(A == NULL) {
        return ERROR;
    }
    
    if(dim < 1 || dim > MAX_ARRAY_DIM) {    // ����ά��������
        return ERROR;
    }
    
    (*A).dim = dim;     // ��ʼ������ά��
    
    // ��ʼ������ά����Ϣ��
    (*A).bounds = (int*) malloc(dim * sizeof(int));
    if((*A).bounds == NULL) {
        exit(OVERFLOW);
    }
    
    // ��ά�ȳ��ȺϷ��������bounds�������A��Ԫ������elemtotal
    elemtotal = 1;
    
    // ʹapָ���һ���ɱ������dim�൱����ʼ��ʶ
    va_start(ap, dim);
    
    for(i = 0; i < dim; i++) {
        // ��¼��ǰά�ȵĿ��
        (*A).bounds[i] = va_arg(ap, int);
        if((*A).bounds[i] <= 0) {
            return ERROR;
        }
        
        elemtotal *= A->bounds[i];
    }
    
    // �ÿ�ap
    va_end(ap);
    
    // ��ʼ������ռ䣬�Դ��Ԫ��
    (*A).base = (ElemType*) malloc(elemtotal * sizeof(ElemType));
    if((*A).base == NULL) {
        exit(OVERFLOW);
    }
    
    // ��ʼ������ӳ����������Ϣ��
    (*A).constants = (int*) malloc(dim * sizeof(int));
    if((*A).constants == NULL) {
        exit(OVERFLOW);
    }
    
    // �������һ��ά�ȣ�ÿ��������Ҫ��Խһ��Ԫ��
    (*A).constants[dim - 1] = 1;
    for(i = dim - 2; i >= 0; i--) {
        (*A).constants[i] = (*A).bounds[i + 1] * (*A).constants[i + 1];
    }
    
    /*
     * ������
     * ������ά����[2,3,4]��˵��bounds��ֵΪ<2,3,4>��constants��ֵΪ<12,4,1>
     * ����bounds����һά�а���2��Ԫ�أ��ڶ�ά�а���3��Ԫ�أ�����ά�а���4��Ԫ��
     * ����constants��������һά��ÿ����Ҫ���12��Ԫ�أ������ڶ�ά��ÿ����Ҫ��Խ4��Ԫ�أ���������ά��ÿ����Ҫ��Խ1��Ԫ��
     */
    
    return OK;
}

/*
 * ����(�ṹ)��
 *
 * ��������ռ�õĿռ䡣
 */
Status DestroyArray(Array* A) {
    if(A == NULL || (*A).base == NULL || (*A).bounds == NULL || (*A).constants == NULL) {
        return ERROR;
    }
    
    free((*A).base);
    (*A).base = NULL;
    
    free((*A).bounds);
    (*A).bounds = NULL;
    
    free((*A).constants);
    (*A).constants = NULL;
    
    (*A).dim = 0;
    
    return OK;
}

/*
 * ȡֵ��
 *
 * ��ȡָ���±괦��Ԫ��ֵ���ɱ����Ϊdim���±�ֵ��ָʾ����ȡԪ�������±ꡣ
 */
Status Value(Array A, ElemType* e, ...) {
    va_list ap;
    Status result;
    int off;
    
    va_start(ap, e);
    
    // ��������Ԫ�ص�Ŀ��Ԫ����Ҫ��Խ��Ԫ������
    result = Locate(A, ap, &off);
    
    va_end(ap);
    
    if(result == OVERFLOW) {
        return result;
    }
    
    *e = *(A.base + off);
    
    return OK;
}

/*
 * ��ֵ��
 *
 * Ϊָ���±괦��Ԫ�ظ�ֵ���ɱ����Ϊdim���±�ֵ��ָʾ����ֵԪ�������±ꡣ
 */
Status Assign(Array* A, ElemType e, ...) {
    va_list ap;
    Status result;
    int off;
    
    va_start(ap, e);
    
    // ��������Ԫ�ص�Ŀ��Ԫ����Ҫ��Խ��Ԫ������
    result = Locate(*A, ap, &off);
    
    va_end(ap);
    
    if(result == OVERFLOW) {
        return result;
    }
    
    *(A->base + off) = e;
    
    return OK;
}

/*
 * ���apָʾ��ֵ������A�е����λ�ã�
 * ����������Ԫ�ص�Ŀ��Ԫ����Ҫ��Խ��Ԫ��������
 */
static Status Locate(Array A, va_list ap, int* off) {
    int i, ind;
    
    *off = 0;
    
    for(i = 0; i < A.dim; i++) {
        ind = va_arg(ap, int);
        
        // ��֤�±겻Խ��
        if(ind < 0 || ind >= A.bounds[i]) {
            return OVERFLOW;
        }
        
        // ĳ��ά�ȵĵ�λԪ�ظ���*��Ҫ����ĵ�λ
        *off += A.constants[i] * ind;
    }
    
    return OK;
}

/*
 * ����������Ԫ�صĸ���
 *
 *��ע��
 * ��Ϊ�����ĺ���
 */
int Length(Array A) {
    int i;
    int elemtotal = 1;
    
    for(i = 0; i < A.dim; i++) {
        elemtotal *= A.bounds[i];
    }
    
    return elemtotal;
}
