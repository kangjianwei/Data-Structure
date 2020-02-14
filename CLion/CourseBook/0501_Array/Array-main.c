#include <stdio.h>
#include "Array.h"//**▲05 数组和广义表**//

// 数组输出函数的内部实现
static void Print(Array A, int dim, int index[]) {
    int i;
    int start;
    
    if(dim == A.dim) {
        start = 0;
        
        // 计算本次遍历的起始元素位置
        for(i = 0; i < dim - 1; i++) {
            start += index[i] * A.constants[i];
        }
        
        // 遍历最后一个维度内的元素
        for(i = 0; i < A.bounds[dim - 1]; i++) {
            printf("%d ", A.base[start + i]);
        }
    } else {
        
        for(i = 0; i < A.bounds[dim - 1]; i++) {
            printf("<");
            
            // 索引轮转
            index[dim - 1] = (index[dim - 1] + 1 + A.bounds[dim - 1]) % A.bounds[dim - 1];
            
            Print(A, dim + 1, index);
            
            printf(">");
        }
    }
}

// 按行依次输出数组中内容
static void ArrayPrint(Array A) {
    int i;
    int* index;
    
    // 在遍历数组元素时，记录每个元素的索引（只记录前dim-1维）
    index = (int*) malloc((A.dim - 1) * sizeof(int));
    for(i = 0; i < A.dim - 1; i++) {
        index[i] = -1;
    }
    
    Print(A, 1, index);
    
    printf("\n");
}


/* 以三维数组为例测试 */
int main(int argc, char** argv) {
    Array A;
    
    printf("████████ 函数 InitArray （以三维数组为例）\n");
    {
        printf("█ 初始化一个维度为<2,3,4>的三维数组 A ...\n");
        InitArray(&A, 3, 2, 3, 4);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ 函数 Assign \n");
    {
        int i, j, k;
        ElemType e = 0;
        
        for(i = 0; i < A.bounds[0]; i++) {
            for(j = 0; j < A.bounds[1]; j++) {
                for(k = 0; k < A.bounds[2]; k++) {
                    printf("█ 赋值：A[%d][%d][%d] = %d\n", i, j, k, ++e);
                    Assign(&A, e, i, j, k);
                }
            }
        }
        printf("█ A = ");
        ArrayPrint(A);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ 函数 Value \n");
    {
        ElemType x;
        
        printf("█ 获取 A 中下标为 (1,1,1) 的元素的值，Locate 用于求出 A[1][1][1] 的相对位置...\n");
        Value(A, &x, 1, 1, 1);
        printf("█ A[1][1][1] = %d\n", x);
    }
    PressEnterToContinue(debug);
    
    
    printf("████████ 函数 DestroyArray \n");
    {
        printf("█ 销毁 A 前：");
        A.dim != 0 ? printf(" A 存在！\n") : printf(" A 不存在！！\n");
        
        DestroyArray(&A);
        
        printf("█ 销毁 A 后：");
        A.dim != 0 ? printf(" A 存在！\n") : printf(" A 不存在！！\n");
    }
    PressEnterToContinue(debug);
    
    
    return 0;
}
