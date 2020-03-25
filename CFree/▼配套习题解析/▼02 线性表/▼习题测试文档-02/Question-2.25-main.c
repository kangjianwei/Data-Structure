#include <stdio.h>	
#include "../../../▲课本算法实现/▲02 线性表/01 SequenceList/SequenceList.c"	//**▲02 线性表**//

/*
 * 题2.25
 *
 * 求交集：C=A∩B，要求新顺序表另辟空间。
 */
Status Algo_2_25(SqList La, SqList Lb, SqList* Lc);

// 测试函数，打印元素
void PrintElem(LElemType_Sq e);


int main(int argc, char* argv[]) {
    SqList La, Lb, Lc;
    int i;
    
    // 0号单元存储的是数组长度
    int a[] = {10, 1, 3, 5, 7,  9, 11, 13, 15, 17, 19};
    int b[] = {8,  1, 5, 7, 8, 10, 15, 17, 20};
    
    // 准备测试数据，同一表中的元素值各不相同
    InitList_Sq(&La);
    InitList_Sq(&Lb);
    for(i = 1; i <= a[0]; i++) {
        ListInsert_Sq(&La, i, a[i]);
    }
    for(i = 1; i <= b[0]; i++) {
        ListInsert_Sq(&Lb, i, b[i]);
    }
    printf("La = ");
    ListTraverse_Sq(La, PrintElem);
    printf("\n");
    printf("Lb = ");
    ListTraverse_Sq(Lb, PrintElem);
    printf("\n");
    
    // 求交集
    Algo_2_25(La, Lb, &Lc);
    
    printf("Lc = ");
    ListTraverse_Sq(Lc, PrintElem);
    printf("\n");
    
    return 0;
}

// 求交集：C=A∩B，要求新顺序表另辟空间。
Status Algo_2_25(SqList La, SqList Lb, SqList* Lc) {
    int i, j, k;
    
    // 初始化Lc
    InitList_Sq(Lc);
    
    // 确保La和Lb存在
    if(La.elem == NULL || Lb.elem == NULL) {
        return ERROR;
    }
    
    i = j = 0;  // 遍历La和Lb
    k = 1;      // 遍历Lc
    
    // 只遍历La和Lb的共同部分就行
    while(i < La.length && j < Lb.length) {
        if(La.elem[i] < Lb.elem[j]) {
            i++;
        } else if(La.elem[i] > Lb.elem[j]) {
            j++;
			
            // 如果La和Lb中的元素相等
        } else {
            // 将交集元素插入到Lc
            ListInsert_Sq(Lc, k, La.elem[i]);
            k++;
            i++;
            j++;
        }
    }
    
    return OK;
}

// 测试函数，打印元素
void PrintElem(LElemType_Sq e) {
    printf("%2d ", e);
}
