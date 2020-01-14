#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SString.h"    //**▲04 串**//
#include "GList-E.h"    //**▲05 数组和广义表**//

/*
 * 广义表复制（扩展线性链表存储表示）
 *
 *【注】
 * 该函数已在GList-E相关文件中定义
 */
Status Algo_5_31(GList* T, GList L);


int main(int argc, char* argv[]) {
    GList L, T;
    char* s = "((),(e),(a,(b,c,d)))";
    SString S;
    
    printf("创建广义表 L ...\n");
    StrAssign(S, s);
    CreateGList(&L, S);
    printf("L = ");
    PrintGList(L);
    
    printf("复制广义表到 L 到 T...\n");
    Algo_5_31(&T, L);
    printf("T = ");
    PrintGList(T);
    
    return 0;
}


/*
 * 广义表复制（扩展线性链表存储表示）
 *
 *【注】
 * 该函数已在GList-E相关文件中定义
 */
Status Algo_5_31(GList* T, GList L) {
    return CopyGList(T, L);
}
