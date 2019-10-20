#include <stdio.h>
#include "SqList.h"    //**▲02 线性表**//

/*
 * 题2.27
 *
 * 求交集：C=A∩B。
 * 不允许C中的元素重复，且C会利用A原有的空间，A被销毁。
 */
SqList Algo_2_27(SqList* La, SqList Lb);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    SqList La, Lb, Lc;
    int i;
    
    int a[10] = {1, 2, 2, 3, 4, 4, 9, 9, 10, 12};
    int b[10] = {1, 1, 2, 2, 3, 3, 4, 5, 12, 13};
    
    // 准备测试数据
    InitList(&La);
    InitList(&Lb);
    for(i = 1; i <= 10; i++) {
        ListInsert(&La, i, a[i - 1]);
        ListInsert(&Lb, i, b[i - 1]);
    }
    
    printf("La = ");
    ListTraverse(La, PrintElem);
    
    printf("Lb = ");
    ListTraverse(Lb, PrintElem);
    
    // 求交集
    Lc = Algo_2_27(&La, Lb);
    
    printf("Lc = ");
    ListTraverse(Lc, PrintElem);
    
    return 0;
}

// 求交集：C=A∩B
SqList Algo_2_27(SqList* La, SqList Lb) {
    int i, j, k;
    SqList Lc;
    
    // 确保La和Lb存在
    if((*La).elem == NULL || Lb.elem == NULL) {
        Lc.elem = NULL;
        Lc.length = 0;
        Lc.listsize = 0;
        return Lc;
    }
    
    i = j = 0;  // 遍历La和Lb
    k = 0;      // 遍历Lc
    
    Lc.elem = (*La).elem;
    Lc.listsize = La->listsize;
    
    // 只遍历La和Lb的共同部分就行
    while(i < (*La).length && j < Lb.length) {
        if((*La).elem[i] < Lb.elem[j]) {
            i++;
        } else if((*La).elem[i] > Lb.elem[j]) {
            j++;
            // 如果La和Lb中的元素相等
        } else {
            // 确保Lc中的元素不重复
            if(k == 0 || Lc.elem[k - 1] != (*La).elem[i]) {
                Lc.elem[k] = (*La).elem[i];
                k++;
            }
            
            i++;
            j++;
        }
    }
    
    // 销毁A，但其空间交给了C使用
    (*La).elem = NULL;
    (*La).length = 0;
    (*La).listsize = 0;
    
    Lc.length = k;
    
    return Lc;
}

void PrintElem(ElemType e) {
    printf("%d ", e);
}
