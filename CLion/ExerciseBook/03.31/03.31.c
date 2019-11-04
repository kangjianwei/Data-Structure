#include <stdio.h>
#include <string.h>   // 提供strlen函数的原型
#include "Status.h"   //**▲01 绪论**//
#include "SqStack.h"  //**▲03 栈和队列**//

/*
 * 判断序列s是否为回文序列
 * 空串也被视为回文序列
 */
Status Algo_3_31(char* s);


int main(int argc, char* argv[]) {
    char* a = "abcdedcba@";
    char* b = "ababab@";
    
    if(Algo_3_31(a)) {
        printf("%s（不包括@）是回文序列！\n", a);
    } else {
        printf("%s（不包括@）不是回文序列！！\n", a);
    }
    
    if(Algo_3_31(b)) {
        printf("%s（不包括@）是回文序列！\n", b);
    } else {
        printf("%s（不包括@）不是回文序列！！\n", b);
    }
    
    return 0;
}


/*
 * 判断序列s是否为回文序列
 * 空串也被视为回文序列
 */
Status Algo_3_31(char* s) {
    int len;
    int i;
    int m, n;   // 回文串前半段的结尾下标和后半段的开始下标
    SqStack S;
    SElemType e;
    
    len = (int) strlen(s);
    
    if(len == 0 || s[len - 1] != '@') {
        return FALSE;
    }
    
    // 空串被认为是回文序列
    if(len == 1) {
        return TRUE;
    }
    
    if(len % 2 == 0) {
        m = (len - 2) / 2 - 1;
        n = m + 2;
    } else {
        m = (len - 2) / 2;
        n = m + 1;
    }
    
    InitStack(&S);
    
    // 先把回文串前半段入栈
    for(i = 0; i <= m; i++) {
        Push(&S, s[i]);
    }
    
    // 取出回文串前半段，与字符串序列后半段比对
    for(i = n; i <= len - 2; i++) {
        if(!StackEmpty(S)) {
            Pop(&S, &e);
        } else {
            break;
        }
        
        if(s[i] != e) {
            return ERROR;
        }
    }
    
    // 完美的状态应该是栈正好为空，且i为len-1
    if(!(StackEmpty(S) && i == len - 1)) {
        return ERROR;
    }
    
    return OK;
}
