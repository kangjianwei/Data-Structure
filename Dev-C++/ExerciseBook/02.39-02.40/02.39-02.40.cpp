#include <stdio.h>
#include <stdlib.h>     // �ṩmalloc��realloc��free��exitԭ��
#include <math.h>       // �ṩpowԭ��
#include "Status.h"     //**��01 ����**//

// ϡ�����ʽ˳��ṹ
typedef struct {
    int coef;   //ϵ��
    int exp;    //ָ��
} PolyTerm;

// ����ʽ��˳��洢�ṹ
typedef struct {
    PolyTerm* data;
    int last;       // ����ʽ����
} SqPoly;

/*
 * ��2.39
 *
 * �����ʽ��ֵ��
 */
int Algo_2_39(SqPoly P, int x);

/*
 * ��2.40
 *
 * Pc=Pa-Pb��
 */
Status Algo_2_40(SqPoly Pa, SqPoly Pb, SqPoly* Pc);

// ����ϡ�����ʽ
Status CreatPoly(SqPoly* P, PolyTerm Data[], int n);

// ���ϡ�����ʽ
void OutputPoly(SqPoly P);


int main(int argc, char* argv[]) {
    SqPoly Pa, Pb, Pc;
    
    PolyTerm a[5] = {{-2, 1}, {4, 3}, {11, 5}, {-7, 7}, {8, 9}};
    PolyTerm b[5] = {{3, 2}, {-5, 3}, {12, 4}, {-7, 7}, {6, 11}};
    
    // ׼����������
    CreatPoly(&Pa, a, 5);
    CreatPoly(&Pb, b, 5);
    printf("Pan(x) = ");
    OutputPoly(Pa);
    printf("Pbn(x) = ");
    OutputPoly(Pb);
    
    printf("\n");
    
    printf("���������������� �� 2.39 ��֤...\n");
    printf("�� Pa5(2) = %d", Algo_2_39(Pa, 2));
    printf("\n");
    printf("�� Pb5(2) = %d", Algo_2_39(Pb, 2));
    printf("\n\n");
    
    printf("���������������� �� 2.40 ��֤...\n");
    Algo_2_40(Pa, Pb, &Pc);
    printf("�� Pcn(x) = ");
    OutputPoly(Pc);
    
    printf("�������ʽPc��ֵ Pc5(2) = %d\n", Algo_2_39(Pc, 2));
    
    return 0;
}


// �����ʽ��ֵ
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
    
    // ����Pa��Pb�Ĺ�������
    while(i < Pa.last && j < Pb.last) {
        // Paָ����С������Pa
        if(Pa.data[i].exp < Pb.data[j].exp) {
            (*Pc).data[k++] = Pa.data[i];
            i++;
            // Paָ���ϴ�����Pb��ֻ��򵥸ı�ϵ�����ž���
        } else if(Pa.data[i].exp > Pb.data[j].exp) {
            (*Pc).data[k].coef = -Pb.data[j].coef;    //���Ÿı�
            (*Pc).data[k].exp = Pb.data[j].exp;
            k++;
            j++;
            // ָ�����ʱ����Ҫ����������
        } else {
            sum = Pa.data[i].coef - Pb.data[j].coef;
            
            // ���������Դ�����Ч��
            if(sum != 0) {
                (*Pc).data[k].coef = sum;
                (*Pc).data[k].exp = Pa.data[i].exp;
                k++;
            }
            
            i++;
            j++;
        }
    }
    
    // ���Paδɨ���꣬��Pbɨ�����ˣ����Pa��ʣ�ಿ�ִ浽Pc��
    while(i < Pa.last) {
        (*Pc).data[k++] = Pa.data[i];
        i++;
    }
    
    // ���Pbδɨ���꣬����Ҫ����ϵ��������ת��浽Pc��
    while(j < Pb.last) {
        (*Pc).data[k].coef = -Pb.data[j].coef;
        (*Pc).data[k].exp = Pb.data[j].exp;
        k++;
        j++;
    }
    
    // ��¼����������
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
