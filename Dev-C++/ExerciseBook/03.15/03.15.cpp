#include <stdio.h>
#include "Status.h"    //**��01 ����**//

/* �궨�� */
#define N 100                                //ջ������

/* ˫��ջԪ�����Ͷ��� */
typedef int SElemType;

/* ˫��ջ�а���������ջ��ջ�� */
typedef enum {
    Left, Right
} StackName;

/* ˫��ջ�ṹ */
typedef struct {
    SElemType stack[N];     // ��һ�������㹻���������ջ
    int top[2];           // ���ջ��ָ��
} TWS;

// ��ʼ��ջ
Status Inistack_3_15(TWS* tws);

// ��ջ��nameָʾ���ĸ�ջ�����Ԫ��
Status Push_3_15(TWS* tws, StackName name, SElemType x);

// ��ջ��nameָʾ���ĸ�ջ���Ƴ�Ԫ��
Status Pop_3_15(TWS* tws, StackName name, SElemType* x);

// ���ջ��Ԫ�أ�nameָʾ����ĸ�ջ�е�Ԫ��
void OutputStack(TWS tws, StackName name);


int main(int argc, char* argv[]) {
    TWS S;
    int i, x;
    
    printf("���������������� ��ʼ��ջ...\n");
    Inistack_3_15(&S);
    
    
    printf("���������������� ������ջ��ѹ��Ԫ��...\n");
    
    for(i = 1; i <= 5; i++) {
        Push_3_15(&S, Left, i);
        Push_3_15(&S, Right, 2 * i);
    }
    printf("�� ��ջ�е�Ԫ�أ���ջ�׵�ջ������");
    OutputStack(S, Left);
    printf("�� ��ջ�е�Ԫ�أ���ջ�׵�ջ������");
    OutputStack(S, Right);
    
    
    printf("���������������� �ֱ𵯳�����ջ��ջ��Ԫ��...\n");
    
    Pop_3_15(&S, Left, &x);
    printf("�� ������ջ��ջ��Ԫ��Ϊ��%d\n", x);
    printf("�� ��ջ�е�Ԫ�أ���ջ�׵�ջ������");
    OutputStack(S, Left);
    
    Pop_3_15(&S, Right, &x);
    printf("�� ������ջ��ջ��Ԫ��Ϊ��%d\n", x);
    printf("�� ��ջ�е�Ԫ�أ���ջ�׵�ջ������");
    OutputStack(S, Right);
    
    return 0;
}


// ��ʼ��ջ
Status Inistack_3_15(TWS* tws) {
    if(tws == NULL) {
        return ERROR;
    }
    
    (*tws).top[Left] = -1;    // ջ0��ջ��ָ�룬ע�ⲻ��0
    (*tws).top[Right] = N;    // ջ1��ջ��ָ�룬ע�ⲻ��N-1
    
    return OK;
}

// ��ջ��nameָʾ���ĸ�ջ�����Ԫ��
Status Push_3_15(TWS* tws, StackName name, SElemType x) {
    if(tws == NULL) {
        return ERROR;
    }
    
    // ע��ջ������������ȫ����������ջ�������˷ѿռ�
    if((*tws).top[Left] + 1 == (*tws).top[Right]) {
        return ERROR;
    }
    
    // ���ƶ�ջ���α꣬�ٴ���Ԫ��
    switch(name) {
        case Left:
            (*tws).top[name]++; // ���ջ���α������ƶ�
            break;
        case Right:
            (*tws).top[name]--; // �ұ�ջ���α������ƶ�
            break;
        default:
            break;
    }
    
    // ����Ԫ��
    (*tws).stack[(*tws).top[name]] = x;
    
    return OK;
}

// ��ջ��nameָʾ���ĸ�ջ���Ƴ�Ԫ��
Status Pop_3_15(TWS* tws, StackName name, SElemType* x) {
    if(tws == NULL) {
        return ERROR;
    }
    
    // ���Ƴ�Ԫ�أ����ƶ��α�
    switch(name) {
        case Left:
            // �ж���ߵ�ջ�Ƿ�Ϊ��
            if((*tws).top[name] == -1) {
                return ERROR;
            }
            *x = (*tws).stack[(*tws).top[name]];
            (*tws).top[name]--;
            break;
        case Right:
            // �ж��ұߵ�ջ�Ƿ�Ϊ��
            if((*tws).top[name] == N) {
                return ERROR;
            }
            *x = (*tws).stack[(*tws).top[name]];
            (*tws).top[name]++;
            break;
        default:
            break;
    }
    
    return OK;
}

// ���ջ��Ԫ�أ�nameָʾ����ĸ�ջ�е�Ԫ��
void OutputStack(TWS tws, StackName name) {
    int i;
    
    switch(name) {
        case Left:
            for(i = 0; i <= tws.top[name]; i++) {
                printf("%d ", tws.stack[i]);
            }
            break;
        case Right:
            for(i = N - 1; i >= tws.top[name]; i--) {
                printf("%d ", tws.stack[i]);
            }
            break;
        default:
            break;
    }
    
    printf("\n");
}
