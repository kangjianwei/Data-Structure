#include <stdio.h>
#include "HString.h"                                //**▲04 串**//

// 测试函数，打印字符串
void PrintElem(HString S);

int main(int argc, char** argv) {
    char* chars = "01234567899876543210";
    HString S, T, sub, V;
    int i;
    
    printf("████████ StrAssign \n");
    {
        printf("█ 为堆串 S 赋值...\n");
        StrAssign(&S, chars);
        printf("█ S = ");
        PrintElem(S);
    }
    PressEnterToContinue();
    
    printf("████████ StrEmpty \n");
    {
        StrEmpty(S) ? printf("█ S 为空！！\n") : printf("█ S 不为空！\n");
    }
    PressEnterToContinue();
    
    printf("████████ StrLength \n");
    {
        i = StrLength(S);
        printf("█ S 的长度为 %d \n", i);
    }
    PressEnterToContinue();
    
    printf("████████ StrCopy \n");
    {
        printf("█ 复制 S 到 T ...\n");
        StrCopy(&T, S);
        printf("█ T = ");
        PrintElem(T);
    }
    PressEnterToContinue();
    
    printf("████████ StrCompare \n");
    {
        printf("█ 比较字符串 S 和 T ...\n");
        i = StrCompare(S, T);
        i == 0 ? printf("█ S==T\n") : (i < 0 ? printf("█ S<T\n") : printf("█ S>T\n"));
    }
    PressEnterToContinue();
    
    printf("████████ StrInsert \n");
    {
        StrAssign(&T, "*****");
        printf("█ 将 \"*****\" 插入到串 S 的第 11 个位置处... \n");
        StrInsert(&S, 11, T);
        printf("█ S = ");
        PrintElem(S);
    }
    PressEnterToContinue();
    
    printf("████████ Index \n");
    {
        StrAssign(&T, "*****");
        printf("█ 获取 \"*****\" 在串 S 中的第一次出现的位置...\n");
        i = Index(S, T, 1);
        printf("█ 串 \"*****\" 在 S 中第一次出现的位置为 %d \n", i);
    }
    PressEnterToContinue();
    
    printf("████████ SubString \n");
    {
        printf("█ 用 sub 返回 S 中第 11 个字符起的 5 个字符...\n");
        SubString(&sub, S, 11, 5);
        printf("█ Sub = ");
        PrintElem(sub);
    }
    PressEnterToContinue();
    
    printf("████████ Replace \n");
    {
        StrAssign(&T, "*****");
        StrAssign(&V, "#####@@@@@");
        printf("█ 用 \"#####@@@@@\" 替换S中的 \"*****\" ...\n");
        Replace(&S, T, V);
        printf("█ S = ");
        PrintElem(S);
    }
    PressEnterToContinue();
    
    printf("████████ StrDelete \n");
    {
        printf("█ 删除 S 中第 16 个字符起的 5 个字符...\n");
        StrDelete(&S, 16, 5);
        printf("█ S = ");
        PrintElem(S);
    }
    PressEnterToContinue();
    
    printf("████████ ClearString \n");
    {
        printf("█ 清空 S 前：");
        StrEmpty(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
    
        ClearString(&S);
    
        printf("█ 清空 S 后：");
        StrEmpty(S) ? printf(" S 为空！！\n") : printf(" S 不为空！\n");
    }
    PressEnterToContinue();
    
    printf("████████ Concat \n");
    {
        HString Tmp, S1, S2;
    
        StrAssign(&S1, "+++++");
        StrAssign(&S2, "-----");
    
        printf("█ 联接 \"+++++\" 和 \"-----\" 形成 Tmp ...\n");
        Concat(&Tmp, S1, S2);
        printf("█ Tmp = ");
        PrintElem(Tmp);
    }
    PressEnterToContinue();
    
    return 0;
}

// 测试函数，打印字符串
void PrintElem(HString S) {
    int i;
    
    for(i = 0; i <= S.length-1; i++) {
        printf("%c", S.ch[i]);
    }
    
    printf("\n");
}
