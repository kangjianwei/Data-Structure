#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <string.h>     // 提供strlen原型
#include <ctype.h>      // 提供isalpha原型
#include "SqStack.h"    //**▲03 栈和队列**//

/*
 * 将后缀表达式（逆波兰式）转换为前缀表达式（波兰式）
 *
 *【注】
 * 表达式的变量为单字母，操作符只有'+'、'-'、'*'、'/'四则运算
 */
char* Algo_3_23(char* c);

// 将字符转换为字符串
char* CharToStr(char c);

// 拼接字符串a和b，返回拼接后的字符串
char* StrCat(char* a, char* b);


int main(int argc, char* argv[]) {
    char* s = "abc+*de/-";
    
    printf("中缀表达式：%s\n", "a*(b+c)-d/e");
    
    printf("后缀表达式：");
    printf("%s\n", s);
    
    printf("前缀表达式：");
    printf("%s\n", Algo_3_23(s));
    
    return 0;
}


/*
 * 将后缀表达式（逆波兰式）转换为前缀表达式（波兰式）
 *
 *【注】
 * 表达式的变量为单字母，操作符只有'+'、'-'、'*'、'/'四则运算
 */
char* Algo_3_23(char* c) {
    int i;
    char* s, * e1, * e2;
    SqStack S;
    
    InitStack(&S);
    
    for(i = 0; c[i] != '\0'; i++) {
        s = CharToStr(c[i]);
        
        // 若c[i]为操作符(不是操作数)，则栈中至少应当有两个元素
        if(!isalpha(c[i])) {
            if(Pop(&S, &e2) && Pop(&S, &e1)) {
                s = StrCat(s, StrCat(e1, e2));
            } else {
                return NULL;
            }
        }
        
        Push(&S, s);
    }
    
    Pop(&S, &s);
    
    if(StackEmpty(S)) {
        return s;
    }
    
    return NULL;
}

// 将字符转换为字符串
char* CharToStr(char c) {
    char* s;
    
    s = (char*) malloc(2 * sizeof(char));
    
    s[0] = c;
    s[1] = '\0';
    
    return s;
}

// 拼接字符串a和b，返回拼接后的字符串
char* StrCat(char* a, char* b) {
    char* s;
    int i, j, alen, blen;
    
    alen = (int) strlen(a);
    blen = (int) strlen(b);
    
    s = (char*) malloc((alen + blen + 1) * sizeof(char));
    
    j = 0;
    
    for(i = 0; i < alen; i++) {
        s[j++] = a[i];
    }
    
    for(i = 0; i < blen; i++) {
        s[j++] = b[i];
    }
    
    s[j] = '\0';
    
    return s;
}
