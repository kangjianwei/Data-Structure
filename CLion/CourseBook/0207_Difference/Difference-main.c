#include <stdio.h>
#include "Difference.h"                    //**▲02 线性表**//

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    SLinkList space;    // 备用空间
    int S;              // 静态链表
    
    printf("S = (A-B)∪(B-A) = ");
    difference("TestData.txt", space, &S);
    ListTraverse(space, S, PrintElem);
    
    return 0;
}
