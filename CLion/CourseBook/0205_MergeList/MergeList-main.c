#include <stdio.h>
#include "MergeList.h"                    //**▲02 线性表**//

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    LinkList La, Lb, Lc;
    
    int m = 5;
    
    printf("作为示例，La长度设定为 %d ，Lb长度设定为 %d ，创建La和Lb...\n", m, m);
    
    CreateList_Head("TestData_Head.txt", &La, m);
    printf("La = ");
    ListTraverse(La, PrintElem);
    
    CreateList_Tail("TestData_Tail.txt", &Lb, m);
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    printf("归并La和Lb为Lc = ");
    MergeList(&La, &Lb, &Lc);
    ListTraverse(Lc, PrintElem);
    
    return 0;
}

