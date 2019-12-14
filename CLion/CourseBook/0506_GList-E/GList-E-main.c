#include <stdio.h>
#include "GList-E.h"                //**▲05 数组和广义表**//

void PrintElem(AtomType e);                    //打印广义表原子

int main(int argc, char** argv) {
    GList Tmp, G;
    GList g1, g2, g3;
    SString S1, S2, S3;
    
    printf("████████ 函数 InitGList \n");
    {
        printf("█ 创建空的广义表 Tmp ...\n");
        InitGList(&Tmp);
    }
    PressEnterToContinue();
    
    printf("████████ 函数 GListEmpty \n");
    {
        int tag;
        
        tag = GListEmpty(Tmp);
        tag ? printf("█ Tmp 为空！\n") : printf("█ Tmp 不为空！！\n");
    }
    PressEnterToContinue();
    
    printf("████████ 函数 CreateGList \n");
    {
        char* s1 = "()";
        char* s2 = "(e)";
        char* s3 = "(a,(b,c,d))";
    
        printf("█ 创建广义表S1: %s ...\n", s1);
        StrAssign(S1, s1);
        CreateGList(&g1, S1);
    
        printf("█ 创建广义表S2: %s ...\n", s2);
        StrAssign(S2, s2);
        CreateGList(&g2, S2);
    
        printf("█ 创建广义表S3: %s ...\n", s3);
        StrAssign(S3, s3);
        CreateGList(&g3, S3);
    }
    PressEnterToContinue();
    
    printf("████████ 函数 InsertFirst \n");
    {
        printf("█ 将 S3、S2、S1 依次插入到 Tmp 的首个位置...\n");
        InsertFirst(&Tmp, g3);
        InsertFirst(&Tmp, g2);
        InsertFirst(&Tmp, g1);
    }
    PressEnterToContinue();
    
    printf("████████ 函数 Traverse \n");
    {
        printf("█ 输出广义表中原子 Tmp = ");
        Traverse(Tmp, PrintElem);
        printf("\n");
    }
    PressEnterToContinue();
    
    printf("████████ 函数 PrintGraph \n");
    {
        printf("█ 带括号输出广义表 Tmp = ");
        PrintGraph(Tmp);
    }
    PressEnterToContinue();
    
    printf("████████ 函数 CopyGList \n");
    {
        printf("█ 复制 Tmp 到 G = ");
        CopyGList(&G, Tmp);
        PrintGraph(G);
    }
    PressEnterToContinue();
    
    printf("████████ 函数 DeleteFirst \n");
    {
        GList h;
        
        printf("█ 删除广义表 Tmp 的表头：");
        DeleteFirst(&Tmp, &h);
        
        PrintGraph(h);
        
        printf("█ Tmp = ");
        PrintGraph(Tmp);
    }
    PressEnterToContinue();
    
    printf("████████ 函数 GListLength \n");
    {
        printf("█ 广义表 G 的长度为：%d\n", GListLength(G));
    }
    PressEnterToContinue();
    
    printf("████████ 函数 GListDepth_1等 \n");
    {
        printf("█ 广义表 G 的深度为：%d\n", GListDepth(G));
    }
    PressEnterToContinue();
    
    printf("████████ 函数 GetHead \n");
    {
        GList H;
        
        printf("█ 获取广义表 G 的表头 H = ");
        H = GetHead(G);
        PrintGraph(H);
    }
    PressEnterToContinue();
    
    printf("████████ 函数 GetTail \n");
    {
        GList T;
        
        printf("█ 获取广义表 G 的表尾 T = ");
        T = GetTail(G);
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    printf("████████ 函数 DestroyGList \n");
    {
        printf("█ 销毁 G 前：");
        G ? printf(" G 存在！\n") : printf(" G 不存在！！\n");
        
        DestroyGList(&G);
        
        printf("█ 销毁 G 后：");
        G ? printf(" G 存在！\n") : printf(" G 不存在！！\n");
    }
    PressEnterToContinue();
    
    return 0;
}

void PrintElem(AtomType e) {
    printf("%c ", e);
}
