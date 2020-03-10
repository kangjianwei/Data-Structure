#include <stdio.h>
#include "SqList.h"     //**▲02 线性表**//

/*
 * 题2.12
 *
 * 比较顺序表大小，比较策略是从左向右遍历两个顺序表，
 * 遇到首对不同的元素时，根据该元素的大小关系，确定顺序表的大小关系
 *
 * 返回值是-1、0、1，分别代表A<B、A=B、A>B
 */
int Algo_2_12(SqList A, SqList B);

// 测试函数，打印元素
void PrintElem(ElemType e);


int main(int argc, char* argv[]) {
    int i, mark;
    SqList A, B;
    
    int a[7] = {1, 2, 3, 4, 5, 9, 12};
    int b[7] = {1, 2, 3, 4, 5, 11, 12};
    
    // 初始化
    InitList(&A);
    InitList(&B);
    
    // 赋值
    for(i = 1; i <= 7; i++) {
        ListInsert(&A, i, a[i - 1]);
        ListInsert(&B, i, b[i - 1]);
    }
    
    printf("A = ");
    ListTraverse(A, PrintElem);
    
    printf("B = ");
    ListTraverse(B, PrintElem);
    
    mark = Algo_2_12(A, B);
    if(mark < 0) {
        printf("==> A<B\n");
    } else if(mark > 0) {
        printf("==> A>B\n");
    } else {
        printf("A==B\n");
    }
    
    return 0;
}


// 比较顺序表大小
int Algo_2_12(SqList A, SqList B) {
    int i = 0;
    
    // 扫描顺序表A和B
    while(i < A.length && i < B.length) {
        if(A.elem[i] > B.elem[i]) {
            return 1;
        } else if(A.elem[i] < B.elem[i]) {
            return -1;
        } else {
            i++;    //相等时比较下一元素
        }
    }
    
    // 如果A还有剩余，A大
    if(i < A.length) {
        return 1;
        
        // 如果B还有剩余，B大
    } else if(i < B.length) {
        return -1;
        
        // 如果同时扫描完，相等
    } else {
        return 0;
    }
}

// 测试函数，打印元素
void PrintElem(ElemType e) {
    printf("%d ", e);
}
