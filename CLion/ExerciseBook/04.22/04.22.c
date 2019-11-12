#include <stdio.h>
#include "LString.h"    //**▲04 串**//

/*
 * 将S插入到T中的字符c之后。
 * 如果有多个c，则将S插入到从左向右遍历T时遇到的首个c之后。
 * 如果T在不存在c，则将S插入到T的末尾。
 */
void Algo_4_22(LString* T, char ch, LString S);


int main(int argc, char* argv[]) {
    char* t = "----***--*-**-**^**-*****-----";
    char* s = "12345";
    char ch = '^';
    LString T, S;
    
    StrAssign(&T, t);
    StrAssign(&S, s);
    printf("T = ");
    StrPrint(T);
    printf("S = ");
    StrPrint(S);
    
    Algo_4_22(&T, ch, S);
    printf("T = ");
    StrPrint(T);
    
    return 0;
}


/*
 * 将S插入到T中的字符c之后。
 * 如果有多个c，则将S插入到从左向右遍历T时遇到的首个c之后。
 * 如果T在不存在c，则将S插入到T的末尾。
 */
void Algo_4_22(LString* T, char c, LString S) {
    int i;
    char tmp[2];
    LString Tmp;
    
    // 构造目标串
    tmp[0] = c;
    tmp[1] = '\0';
    StrAssign(&Tmp, tmp);
    
    // 寻找字符c在T中的位置
    i = Index((*T), Tmp, 1);
    
    // 如果找到了c，则将S插入到字符c之后
    if(i != 0) {
        StrInsert(T, i + 1, S);
        
        // 如果没找到c，则将S插入到T的末尾
    } else {
        StrInsert(T, (*T).curlen + 1, S);
    }
} 
