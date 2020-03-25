#include <stdio.h>	
#include "../../../▲课本算法实现/▲02 线性表/01 SequenceList/SequenceList.c"	//**▲02 线性表**//

/*
 * 题2.27
 *
 * 求交集：C=A∩B。
 *
 * A和B中元素可能重复，但C中元素不重复。
 * 而且，要求C利用A原有的空间。
 */
Status Algo_2_27(SqList La, SqList Lb, SqList* Lc);

// 测试函数，打印元素
void PrintElem(LElemType_Sq e);


int main(int argc, char* argv[]) {
    SqList La, Lb, Lc;
    int i;
    
    // 0号单元存储的是数组长度
    int a[] = {10, 1, 3, 3, 7,  9, 10, 13, 15, 15, 19};
    int b[] = {8,  1, 3, 7, 7, 10, 18, 18, 20};
    
    // 准备测试数据，同一表中的元素值可能相同
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
    
    // 求交集，新链表的元素各不相同
    Algo_2_27(La, Lb, &Lc);
    
    printf("Lc = ");
    ListTraverse_Sq(Lc, PrintElem);
    printf("\n");
    
    return 0;
}


/*
 * 题2.27
 *
 * 求交集：C=A∩B。
 *
 * A和B中元素可能重复，但C中元素不重复。
 * 而且，要求C利用A原有的空间。
 */
Status Algo_2_27(SqList La, SqList Lb, SqList* Lc) {
    int i, j, k;
    
    // 确保La和Lb存在
    if(La.elem == NULL || Lb.elem == NULL) {
        return ERROR;
    }
    
    // 初始化Lc，使其直接使用La的存储空间
    *Lc = La;
    
    i = j = 0;  // 遍历La和Lb
    k = 0;      // 遍历Lc
    
    // 只遍历La和Lb的共同部分就行
    while(i < La.length && j < Lb.length) {
        if(La.elem[i] < Lb.elem[j]) {
            i++;
        } else if(La.elem[i] > Lb.elem[j]) {
            j++;
            
            // 如果La和Lb中的元素相等
        } else {
            // 如果Lc不为空，则需要保证其中的元素不重复
            if(k == 0 || (*Lc).elem[k - 1] != La.elem[i]) {
                (*Lc).elem[k] = La.elem[i];
                k++;
            }
            
            i++;
            j++;
        }
    }
    
    // 更新顺序表Lc的长度
    (*Lc).length = k;
    
    return OK;
}

void PrintElem(LElemType_Sq	e) {
    printf("%2d ", e);
}
