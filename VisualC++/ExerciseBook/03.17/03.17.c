#include <stdio.h>
#include "Status.h"   //**▲01 绪论**//
#include "SqStack.h"  //**▲03 栈和队列**//

/*
 * 判定输入序列是否为"序列1&序列2"这种模式
 * 其中，序列2是序列1的逆置
 *
 * s：待验证的序列，以'@'符号结尾
 */
Status Algo_3_17(char* s);


int main(int argc, char* argv[]) {
    char* s = "a+b-c&c-b+a@";
    
    printf("判断序列 %s 是否合规...\n", s);
    
    if(Algo_3_17(s)) {
        printf("█ 序列满足题意！\n");
    } else {
        printf("█ 序列不满足题意！！\n");
    }
    
    return 0;
}


/*
 * 判定输入序列是否为"序列1&序列2"这种模式
 * 其中，序列2是序列1的逆置
 *
 * s：待验证的序列，以'@'符号结尾
 */
Status Algo_3_17(char* s) {
    SqStack S;
    SElemType e;
    int i;
    
    InitStack(&S);
    i = 0;
    
    // 将'&'前的序列入栈
    while(s[i] != '@' && s[i] != '&') {
        Push(&S, s[i]);
        i++;
    }
    
    // 如果遇到了'&'符号
    if(s[i] != '@') {
        i++;    // 跳过&符号
    
        // 将'&'后的序列出栈
        while(!StackEmpty(S) && s[i] != '@') {
            Pop(&S, &e);
            if(s[i] != e) {
                return ERROR;
            }
            i++;
        }
    }
    
    // 如果栈为空，且序列恰好访问完，说明符合题意
    if(StackEmpty(S) && s[i] == '@') {
        return OK;
    }
    
    return ERROR;
}
