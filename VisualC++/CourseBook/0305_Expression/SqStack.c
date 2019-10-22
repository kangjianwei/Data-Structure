/*=============================
 * 栈的顺序存储结构（顺序栈）
 =============================*/

#include "SqStack.h"    //**▲03 栈和队列**//

/*
 * 初始化
 *
 * 构造一个空栈。初始化成功则返回OK，否则返回ERROR。
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
 * 判空
 *
 * 判断顺序栈中是否包含有效数据。
 *
 * 返回值：
 * TRUE : 顺序栈为空
 * FALSE: 顺序栈不为空
 */
Status StackEmpty(SqStack S) {
    if(S.top == S.base) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*
 * 取值
 *
 * 获取操作符栈的栈顶元素。
 *
 *【注】
 * 该操作的实现与传统的顺序栈的取值操作有些不同，但核心作用一致
 */
SElemType GetTop(SqStack S) {
    SElemType e;
    
    if(S.base == NULL || S.top == S.base) {
        return '\0';
    }
    
    // 不会改变栈中元素
    e = *(S.top - 1);
    
    return e;
}

/*
 * 入栈
 *
 * 将元素e压入到栈顶。
 */
Status Push(SqStack* S, SElemType e) {
    if(S == NULL || (*S).base == NULL) {
        return ERROR;
    }
    
    // 栈满时，追加存储空间
    if((*S).top - (*S).base >= (*S).stacksize) {
        (*S).base = (SElemType*) realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
        if((*S).base == NULL) {
            exit(OVERFLOW);     // 存储分配失败
        }
        
        (*S).top = (*S).base + (*S).stacksize;
        (*S).stacksize += STACKINCREMENT;
    }
    
    // 进栈先赋值，栈顶指针再自增
    *(S->top++) = e;
    
    return OK;
}

/*
 * 出栈
 *
 * 将栈顶元素弹出，并用e接收。
 */
Status Pop(SqStack* S, SElemType* e) {
    if(S == NULL || (*S).base == NULL) {
        return ERROR;
    }
    
    if((*S).top == (*S).base) {
        return ERROR;
    }
    
    // 出栈栈顶指针先递减，再赋值
    *e = *(--(*S).top);
    
    return OK;
}
