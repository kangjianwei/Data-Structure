#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <math.h>       // 提供pow原型
#include "Status.h"     //**▲01 绪论**//

// 稀疏多项式顺序结构
typedef struct {
    int coef;   //系数
    int exp;    //指数
} PolyTerm;

// 多项式的顺序存储结构
typedef struct {
    PolyTerm* data;
    int last;       // 多项式项数
} SqPoly;

/*
 * 题2.39
 *
 * 求多项式的值。
 */
int Algo_2_39(SqPoly P, int x);

/*
 * 题2.40
 *
 * Pc=Pa-Pb。
 */
Status Algo_2_40(SqPoly Pa, SqPoly Pb, SqPoly* Pc);

// 创建稀疏多项式
Status CreatPoly(SqPoly* P, PolyTerm Data[], int n);

// 输出稀疏多项式
void OutputPoly(SqPoly P);


int main(int argc, char* argv[]) {
    SqPoly Pa, Pb, Pc;
    
    PolyTerm a[5] = {{-2, 1}, {4, 3}, {11, 5}, {-7, 7}, {8, 9}};
    PolyTerm b[5] = {{3, 2}, {-5, 3}, {12, 4}, {-7, 7}, {6, 11}};
    
    // 准备测试数据
    CreatPoly(&Pa, a, 5);
    CreatPoly(&Pb, b, 5);
    printf("Pan(x) = ");
    OutputPoly(Pa);
    printf("Pbn(x) = ");
    OutputPoly(Pb);
    
    printf("\n");
    
    printf("████████ 题 2.39 验证...\n");
    printf("█ Pa5(2) = %d", Algo_2_39(Pa, 2));
    printf("\n");
    printf("█ Pb5(2) = %d", Algo_2_39(Pb, 2));
    printf("\n\n");
    
    printf("████████ 题 2.40 验证...\n");
    Algo_2_40(Pa, Pb, &Pc);
    printf("█ Pcn(x) = ");
    OutputPoly(Pc);
    
    printf("计算多项式Pc的值 Pc5(2) = %d\n", Algo_2_39(Pc, 2));
    
    return 0;
}


// 求多项式的值
int Algo_2_39(SqPoly P, int x) {
    int i, sum;
    
    for(i = 0, sum = 0; i < P.last; i++) {
        sum += P.data[i].coef * (int) (pow(x, P.data[i].exp));
    }
    
    return sum;
}

// Pc=Pa-Pb
Status Algo_2_40(SqPoly Pa, SqPoly Pb, SqPoly* Pc) {
    int i, j, k, sum;
    
    (*Pc).data = (PolyTerm*) malloc((Pa.last + Pb.last) * sizeof(PolyTerm));
    if((*Pc).data == NULL) {
        exit(OVERFLOW);
    }
    
    i = j = k = 0;
    
    // 遍历Pa和Pb的公共部分
    while(i < Pa.last && j < Pb.last) {
        // Pa指数较小，则处理Pa
        if(Pa.data[i].exp < Pb.data[j].exp) {
            (*Pc).data[k++] = Pa.data[i];
            i++;
            // Pa指数较大，则处理Pb，只需简单改变系数符号就行
        } else if(Pa.data[i].exp > Pb.data[j].exp) {
            (*Pc).data[k].coef = -Pb.data[j].coef;    //符号改变
            (*Pc).data[k].exp = Pb.data[j].exp;
            k++;
            j++;
            // 指数相等时，需要做减法运算
        } else {
            sum = Pa.data[i].coef - Pb.data[j].coef;
            
            // 如果相减后仍存在有效项
            if(sum != 0) {
                (*Pc).data[k].coef = sum;
                (*Pc).data[k].exp = Pa.data[i].exp;
                k++;
            }
            
            i++;
            j++;
        }
    }
    
    // 如果Pa未扫描完，但Pb扫描完了，则把Pa中剩余部分存到Pc中
    while(i < Pa.last) {
        (*Pc).data[k++] = Pa.data[i];
        i++;
    }
    
    // 如果Pb未扫描完，则需要将其系数符号逆转后存到Pc中
    while(j < Pb.last) {
        (*Pc).data[k].coef = -Pb.data[j].coef;
        (*Pc).data[k].exp = Pb.data[j].exp;
        k++;
        j++;
    }
    
    // 记录运算后的项数
    (*Pc).last = k;
    
    return OK;
}

Status CreatPoly(SqPoly* P, PolyTerm Data[], int n) {
    int i;
    
    (*P).data = (PolyTerm*) malloc(n * sizeof(PolyTerm));
    if((*P).data == NULL) {
        exit(OVERFLOW);
    }
    (*P).last = n;
    
    for(i = 0; i < n; i++) {
        (*P).data[i] = Data[i];
    }
    
    return OK;
}

void OutputPoly(SqPoly P) {
    int i;
    
    for(i = 0; i < P.last; i++) {
        if(i == 0) {
            printf("%d", P.data[i].coef);
        } else {
            if(P.data[i].coef < 0) {
                printf(" - ");
                printf("%d", -P.data[i].coef);
            } else {
                printf(" + ");
                printf("%d", P.data[i].coef);
            }
        }
        
        if(P.data[i].exp) {
            printf("x");
            
            if(P.data[i].exp != 1) {
                printf("^%d", P.data[i].exp);
            }
        }
    }
    
    printf("\n");
}
