#include <stdio.h>
#include <stdlib.h>
#include "String.h"    //**字符串**//

/*
 * R=S-S∩T，数组a存储R中每个字符在S中第一次出现的位置
 *
 * 注：数组a的0号单元存储的是a中元素的个数
 */
void Algo_4_11(StringType* R, StringType S, StringType T, int** a) {
    int i, p;
    StringType ch;
    
    *a = (int*) malloc((StrLength(S) + 1) * sizeof(int));
    
    StrAssign(R, "");
    
    for(i = 1, (*a)[0] = 0; i <= StrLength(S); i++) {
        // 取出字符进行判断
        ch = SubString(S, i, 1);
        
        // 获取S[i]在T中的位置
        p = Index(T, ch, 1);
        
        // 如果S[i]不在T中
        if(p == 0) {
            // 获取S[i]在R中的位置
            p = Index(*R, ch, 1);
        }
        
        // 如果S[i]既不在T中，又没在R中出现过
        if(p == 0) {
            (*a)[0]++;
            (*a)[(*a)[0]] = i;
            
            // 向R中添加S[i]
            StrInsert(R, (*a)[0], ch);
        }
    }
}


int main(int argc, char* argv[]) {
    char* s = "amdhcjgfdlpinbefcopgkqikeb";
    char* t = "mhjlpinopkqik";
    int* a;
    StringType T, S, R;
    int i;
    
    printf("初始化S和T...\n");
    StrAssign(&S, s);
    StrAssign(&T, t);
    printf("S = ");
    StrPrint(S);
    printf("T = ");
    StrPrint(T);
    
    Algo_4_11(&R, S, T, &a);
    printf("R = ");
    StrPrint(R);
    
    printf("a = ");
    for(i = 1; i <= a[0]; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    return 0;
}
