#include "KMP.h"                        //**▲04 串**//

// 测试函数，打印字符串
void PrintElem(SString S) {
    int i;
    
    for(i = 1; i <= S[0]; i++) {
        printf("%c", S[i]);
    }
    
    printf("\n");
}


int main(int argc, char** argv) {
    char* s = "abaaabcaabaabcacabaabcaabaabcac";
    char* t = "abaabcac";
    SString S, T;
    int* next;      // 模式串的next函数值
    int* nextval;   // 模式串的nextval函数值
    int pos;        // 匹配起点
    int i, j;
    
    StrAssign(S, s);                    // 初始化主串
    printf("S       = ");
    PrintElem(S);
    
    StrAssign(T, t);                    // 初始化模式串
    printf("T       = ");
    PrintElem(T);
    
    
    // 注：next数组和nextval数组的0号单元是弃用的，从1号单元开始存储有效数据
    next    = (int*) malloc((T[0] + 1) * sizeof(int));
    nextval = (int*) malloc((T[0] + 1) * sizeof(int));
    
    get_next(T, next);                  // 算法4.7
    get_nextval(T, nextval);            // 算法4.8，即算法4.7的改进版
    
    printf("next    : ");
    for(i = 1; i <= T[0]; i++) {
        printf("%d", next[i]);
    }
    printf("\n");
    
    printf("nextval : ");
    for(i = 1; i <= T[0]; i++) {
        printf("%d", nextval[i]);
    }
    printf("\n");
    
    
    pos = 1;
    
    i = Index_KMP(S, T, pos, next);
    j = Index_KMP(S, T, pos, nextval);
    
    printf("从%d个字符起，T 在 S 中第一次匹配成功的位置为 %d\n", pos, i);
    printf("从%d个字符起，T 在 S 中第一次匹配成功的位置为 %d\n", pos, j);
    
    return 0;
}
