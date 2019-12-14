#include <stdio.h>
#include "LString.h"    //**▲04 串**//

/*
 * 判断给定的串是否对称。
 * 空串或单字符的串会被认为是对称的。
 */
Status Algo_4_23(LString T);


int main(int argc, char* argv[]) {
    char* t = "abcdefgfedcba";
    LString T;
    
    StrAssign(&T, t);
    printf("T = ");
    StrPrint(T);
    
    Algo_4_23(T) ? printf("T是对称串！\n") : printf("T是非对称串！！\n");
    
    return 0;
}


/*
 * 判断给定的串是否对称。
 * 空串或单字符的串会被认为是对称的。
 */
Status Algo_4_23(LString T) {
    int len;    // T的长度
    
    int a1, b1; // T的前半部分边界
    int a2, b2; // T的后半部分边界
    int k;      // 限制遍历T时需要经过的元素数量
    int i;      // 遍历T时的游标
    Chunk* t;
    
    char* stack;    // 模拟栈
    int top;        // 栈游标
    
    char c;         // 从T中取出的字符
    
    len = StrLength(T);
    
    // 空串被认为是对称的
    if(len == 0) {
        return OK;
    }
    
    // 如果串的长度是偶数
    if(len % 2 == 0) {
        a1 = 0;
        b1 = len / 2 - 1;
        a2 = len / 2;
        b2 = len - 1;
        // 如果串的长度是奇数
    } else {
        a1 = 0;
        b1 = len / 2 - 1;
        a2 = len / 2 + 1;
        b2 = len - 1;
    }
    
    stack = (char*) malloc(len * sizeof(char));
    top = -1;
    
    i = 0;
    t = T.head;
    
    // 对于串的前半部分，将其入栈
    for(k = a1; k <= b1; k++) {
        c = t->ch[i];
        i = (i + 1) % CHUNKSIZE;
        if(i == 0) {
            t = t->next;
        }
        
        stack[++top] = c;
    }
    
    // 如果串长为奇数，需要跨过一个字符
    if(len % 2 == 1) {
        i = (i + 1) % CHUNKSIZE;
        if(i == 0) {
            t = t->next;
        }
    }
    
    for(k = a2; k <= b2; k++) {
        c = t->ch[i];
        i = (i + 1) % CHUNKSIZE;
        if(i == 0) {
            t = t->next;
        }
        
        // 遇到了不对称的字符
        if(stack[top--] != c) {
            return ERROR;
        }
    }
    
    if(top == -1) {
        return OK;
    } else {
        return ERROR;
    }
}
