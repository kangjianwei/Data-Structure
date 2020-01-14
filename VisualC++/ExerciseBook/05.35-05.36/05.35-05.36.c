#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SString.h"    //**▲04 串**//
#include "GList.h"      //**▲05 数组和广义表**//

/*
 * 创建广义表L，这里将"( )"定义为广义表为空的状态。
 */
Status Algo_5_35(GList* L, SString S);

/*
 * 带括号输出广义表L，这里将"( )"定义为广义表为空的状态。
 */
void Algo_5_36(GList L);


int main(int argc, char* argv[]) {
    GList L;
    char* s = "(( ),(e),(a,(b,c,d)))";
    SString S;
    
    printf("创建广义表 L ...\n");
    StrAssign(S, s);
    Algo_5_35(&L, S);
    
    printf("L = ");
    Algo_5_36(L);
    
    return 0;
}


/*
 * 创建广义表L，这里将"( )"定义为广义表为空的状态。
 */
Status Algo_5_35(GList* L, SString S) {
    return CreateGList(L, S);
}

/*
 * 带括号输出广义表L，这里将"( )"定义为广义表为空的状态。
 */
void Algo_5_36(GList L) {
    PrintGList(L);
}
