/*=========================
 * ջ��˳��洢�ṹ��˳��ջ��
 ==========================*/

#include "SqStack.h"    //**��03 ջ�Ͷ���**//

/*
 * ��ʼ��
 *
 * ����һ����ջ����ʼ���ɹ��򷵻�OK�����򷵻�ERROR��
 */
Status InitStack(SqStack* S) {
    if(S == NULL) {
        return ERROR;
    }
    
    (*S).base = (SElemType*) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if((*S).base == NULL) {
        exit(OVERFLOW);
    }
    
    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;
    
    return OK;
}

/*
 * ����(�ṹ)
 *
 * �ͷ�˳��ջ��ռ�ڴ档
 */
Status DestroyStack(SqStack* S) {
    if(S == NULL) {
        return ERROR;
    }
    
    free((*S).base);
    
    (*S).base = NULL;
    (*S).top = NULL;
    (*S).stacksize = 0;
    
    return OK;
}

/*
 * �п�
 *
 * �ж�˳��ջ���Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ˳��ջΪ��
 * FALSE: ˳��ջ��Ϊ��
 */
Status StackEmpty(SqStack S) {
    if(S.top == S.base) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*
 * ��ջ
 *
 * ��Ԫ��eѹ�뵽ջ����
 */
Status Push(SqStack* S, SElemType e) {
    if(S == NULL || (*S).base == NULL) {
        return ERROR;
    }
    
    // ջ��ʱ��׷�Ӵ洢�ռ�
    if((*S).top - (*S).base >= (*S).stacksize) {
        (*S).base = (SElemType*) realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
        if((*S).base == NULL) {
            exit(OVERFLOW);     // �洢����ʧ��
        }
        
        (*S).top = (*S).base + (*S).stacksize;
        (*S).stacksize += STACKINCREMENT;
    }
    
    // ��ջ�ȸ�ֵ��ջ��ָ��������
    *(S->top++) = e;
    
    return OK;
}

/*
 * ��ջ
 *
 * ��ջ��Ԫ�ص���������e���ա�
 */
Status Pop(SqStack* S, SElemType* e) {
    if(S == NULL || (*S).base == NULL) {
        return ERROR;
    }
    
    if((*S).top == (*S).base) {
        return ERROR;
    }
    
    // ��ջջ��ָ���ȵݼ����ٸ�ֵ
    *e = *(--(*S).top);
    
    return OK;
}
