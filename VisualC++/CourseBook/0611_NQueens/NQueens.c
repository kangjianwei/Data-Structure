/*==============
 * N�ʺ�����
 *
 * �����㷨: 6.16
 ===============*/

#include "NQueens.h"

/*
 * ��ʼ��N*N��ģ������CB��
 *
 *��ע��
 * 0�ŵ�Ԫ������
 */
void InitChessBoard() {
    int i;
    
    CB = (ChessBoard**) malloc((N + 1) * sizeof(ChessBoard*));
    
    for(i = 1; i <= N; i++) {
        CB[i] = (ChessBoard*) malloc(N * sizeof(ChessBoard));
        memset(CB[i], 0, N * sizeof(ChessBoard));
    }
}

/*
 * ���������������� �㷨6.16 ����������������
 *
 * ��ָ����С���������N�ʺ�����ĸ��⡣
 */
void Trial(int i, int n) {
    int j;
    
    if(i > n) {
        printf(" %d �ʺ�����ĵ� %d �ֽⷨ���£�\n", N, ++order);
        ShowChessBoard();
    } else {
        for(j = 1; j <= N; j++) {
            CB[i][j] = 1;   // �ڵ�i�е�j�з���һ������
            
            // �жϴ�ʱ�����Ƿ����
            if(AllowLayout(i, j)) {
                Trial(i + 1, n);
            }
            
            CB[i][j] = 0;   // ��ȥ��i�е�j�е�����
        }
    }
}


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

/*
 * �ж���x��y�з������Ӻ����̲����Ƿ����
 */
static Status AllowLayout(int i, int j) {
    int m, n, k;
    int s;      // �С��С�б�����
    int len;    // �С��С�б���ϵ�Ԫ������
    
    // ��������ѯ
    for(k = 1, n = j; k <= N - 1; k++) {
        n = (n + 1) - n / N * N;
        
        if(CB[i][n] == 1) {
            return ERROR;   // ����������������
        }
    }
    
    
    // ��������ѯ
    for(k = 1, m = i; k <= N - 1; k++) {
        m = (m + 1) - m / N * N;
        
        if(CB[m][j] == 1) {
            return ERROR;   // ����������������
        }
    }
    
    
    len = N - abs(i - j);
    
    // ����б������ѯ(�����µ�����)
    for(k = 1, m = i, n = j; k <= len - 1; k++) {
        // ����(m,n)λ�����²���
        if(i > j) {
            m = (m + 1) - (m - abs(i - j)) / len * len;
            n = (n + 1) - n / len * len;
            
            // ����(m,n)λ�����ϲ���
        } else {
            m = (m + 1) - m / len * len;
            n = (n + 1) - (n - abs(i - j)) / len * len;
        }
        
        if(CB[m][n] == 1) {
            return ERROR;   // ����б��������������
        }
    }
    
    
    // ����(m,n)λ�����ϲ���
    if(i + j < N + 1) {
        len = i + j - 1;
        s = i + j - 1;  // ��Ϊ��б����y��������
        
        // ����(m,n)λ�����²���
    } else {
        len = 2 * N + 1 - (i + j);
        s = i + j - N;  // ��Ϊ��б����x��������
    }
    
    // ����б������ѯ(�����µ�����)
    for(k = 1, m = i, n = j; k <= len - 1; k++) {
        // ����(m,n)λ�����ϲ���
        if(i + j < N + 1) {
            m = (m + 1) - m / len * len;
            n = s - (s - (n - 1)) % len;
            // ����(m,n)λ�����²���
        } else {
            m = (m + 1) - ((m + 1) - s) / len * len;
            n = N - (N - (n - 1)) % len;
        }
        
        if(CB[m][n] == 1) {
            return ERROR;   // ����б��������������
        }
    }
    
    return OK;
}


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

/*
 * չʾ�����еĻʺ󲼾֡�
 */
void ShowChessBoard() {
    int i, j;
    
    for(i = 1; i <= N; i++) {
        for(j = 1; j <= N; j++) {
            printf("+---");
        }
        printf("+\n");
        
        for(j = 1; j <= N; j++) {
            printf("|");
            
            if(CB[i][j] == 1) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("|\n");
    }
    
    for(i = 1; i <= N; i++) {
        printf("+---");
    }
    printf("+\n");
}
