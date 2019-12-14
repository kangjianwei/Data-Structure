#include <stdio.h>
#include "Status.h"     //**��01 ����**//

/* Ԫ��������� */
#define MAX 100

/*
 * ������/�Һ����б��ж�u�Ƿ�Ϊv������
 */
Status Algo_6_33(int L[MAX + 1], int R[MAX + 1], int u, int v);

/*
 * ����˫�׽���б��ж�u�Ƿ�Ϊv������
 */
Status Algo_6_34(int T[MAX + 1], int u, int v);


int main(int argc, char* argv[]) {
    int T[MAX + 1] = {0, 0, 1, 1, 2, 2, 3, 5, 5, 6};    // 0�ŵ�Ԫ����
    int L[MAX + 1] = {0, 2, 4, 6, 0, 7, 0, 0, 0, 0};
    int R[MAX + 1] = {0, 3, 5, 0, 0, 8, 9, 0, 0, 0};
    int u, v;
    
    printf("��Ϊʾ�����������µ�����\n");
    printf("    �� 1 2 3 4 5 6 7 8 9\n");    // ���
    printf("T[n]�� 0 1 1 2 2 3 5 5 6\n");    // ˫�׽���б�
    printf("L[n]�� 2 4 6 0 7 0 0 0 0\n");    // �����б�
    printf("R[n]�� 3 5 0 0 8 9 0 0 0\n");    // �Һ����б�
    printf("\n");
    
    printf("��������Ҫ��֤�����Ｐ����...\n\n");
    
    printf("����(1~9) u = ");
    scanf("%d", &u);
    printf("����(1~9) v = ");
    scanf("%d", &v);
    printf("\n");
    
    printf("�������� 6.33 ��֤...������\n");
    {
        if(Algo_6_33(L, R, u, v) == TRUE) {
            printf("u=%d �� v=%d �����\n", u, v);
        } else {
            printf("u=%d ���� v=%d �������\n", u, v);
        }
        
        printf("\n");
    }
    
    
    printf("�������� 6.34 ��֤...������\n");
    {
        if(Algo_6_34(T, u, v) == TRUE) {
            printf("u=%d �� v=%d �����\n", u, v);
        } else {
            printf("u=%d ���� v=%d �������\n", u, v);
        }
        
        printf("\n");
    }
    
    return 0;
}


/*
 * ������/�Һ����б��ж�u�Ƿ�Ϊv������
 */
Status Algo_6_33(int L[MAX + 1], int R[MAX + 1], int u, int v) {
    // ���u��v�ĺ���
    if(L[v] == u || R[v] == u) {
        return TRUE;
    } else {
        // ����������ӣ���������
        if(L[v]!=0 && Algo_6_33(L, R, u, L[v])==TRUE) {
            return TRUE;
        }
    
        // ��������Һ��ӣ���������
        if(R[v]!=0 && Algo_6_33(L, R, u, R[v])==TRUE) {
            return TRUE;
        }
    }
    
    return FALSE;
}

/*
 * ����˫�׽���б��ж�u�Ƿ�Ϊv������
 */
Status Algo_6_34(int T[MAX + 1], int u, int v) {
    // ���u��˫����v
    if(T[u] == v) {
        return TRUE;
    } else {
        if(T[u] != 0 && Algo_6_34(T, T[u], v) == TRUE) {
            return TRUE;
        }
    }
    
    return FALSE;
}
