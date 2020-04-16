#include <stdio.h>
#include "GarbageCollection.h"  //**▲08 动态存储管理**//

// 遍历广义表
void Traverse(GList L, void(Visit)(GList));

// 打印广义表结点信息
void PrintInfo(GList L);


int main(int argc, char* argv[]) {
    GList G;
    
    printf("创建并输出广义表：");
    {
        SString S;
        char* s = "((),(e),(a,(b,c,d)))";
        
        InitGList(&G);
        
        StrAssign(S, s);
        CreateGList(&G, S);
        
        PrintGList(G);
        printf("\n");
    }
    PressEnterToContinue(debug);
    
    printf("████████ MakeList \n");
    {
        printf("访问前的标志状态...\n");
        Traverse(G, PrintInfo);
        printf("\n");
        MakeList(G);
        
        printf("访问后的标志状态...\n");
        Traverse(G, PrintInfo);
        printf("\n");
    }
    PressEnterToContinue(debug);
    
    return 0;
}


// 遍历广义表
void Traverse(GList L, void(Visit)(GList)) {
    if(L == NULL) {
        return;
    }
    
    Visit(L);
    
    if(L->tag == List) {
        Traverse(L->Node.ptr.hp, Visit);
        Traverse(L->Node.ptr.tp, Visit);
    }
}

// 打印广义表结点信息
void PrintInfo(GList L) {
    if(L->tag == Atom) {
        printf("mark = %d 原子结点：%c\n", L->mark, L->Node.atom);
    } else {
        printf("mark = %d 表结点\n", L->mark);
    }
}
