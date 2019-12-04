/*==============
 * N皇后问题
 *
 * 包含算法: 6.16
 ===============*/

#include "NQueens.h"

/*
 * 初始化N*N规模的棋盘CB。
 *
 *【注】
 * 0号单元已弃用
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
 * ████████ 算法6.16 ████████
 *
 * 在指定大小棋盘上求出N皇后问题的各解。
 */
void Trial(int i, int n) {
    int j;
    
    if(i > n) {
        printf(" %d 皇后问题的第 %d 种解法如下：\n", N, ++order);
        ShowChessBoard();
    } else {
        for(j = 1; j <= N; j++) {
            CB[i][j] = 1;   // 在第i行第j列放置一个棋子
            
            // 判断此时布局是否合理
            if(AllowLayout(i, j)) {
                Trial(i + 1, n);
            }
            
            CB[i][j] = 0;   // 移去第i行第j列的棋子
        }
    }
}


/*━━━━━━━━━━━━━━━━━━━━━━ 仅限内部使用的函数 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 判断在x行y列放入棋子后棋盘布局是否合理。
 */
static Status AllowLayout(int i, int j) {
    int m, n, k;
    int s;      // 行、列、斜列起点
    int len;    // 行、列、斜列上的元素数量
    
    // 在行中轮询
    for(k = 1, n = j; k <= N - 1; k++) {
        n = (n + 1) - n / N * N;
        
        if(CB[i][n] == 1) {
            return ERROR;   // 该行中遇到了棋子
        }
    }
    
    
    // 在列中轮询
    for(k = 1, m = i; k <= N - 1; k++) {
        m = (m + 1) - m / N * N;
        
        if(CB[m][j] == 1) {
            return ERROR;   // 该列中遇到了棋子
        }
    }
    
    
    len = N - abs(i - j);
    
    // 在右斜列中轮询(从右下到左上)
    for(k = 1, m = i, n = j; k <= len - 1; k++) {
        // 棋子(m,n)位于左下部分
        if(i > j) {
            m = (m + 1) - (m - abs(i - j)) / len * len;
            n = (n + 1) - n / len * len;
            
            // 棋子(m,n)位于右上部分
        } else {
            m = (m + 1) - m / len * len;
            n = (n + 1) - (n - abs(i - j)) / len * len;
        }
        
        if(CB[m][n] == 1) {
            return ERROR;   // 该右斜列中遇到了棋子
        }
    }
    
    
    // 棋子(m,n)位于左上部分
    if(i + j < N + 1) {
        len = i + j - 1;
        s = i + j - 1;  // 作为该斜列上y坐标的起点
        
        // 棋子(m,n)位于右下部分
    } else {
        len = 2 * N + 1 - (i + j);
        s = i + j - N;  // 作为该斜列上x坐标的起点
    }
    
    // 在左斜列中轮询(从左下到右上)
    for(k = 1, m = i, n = j; k <= len - 1; k++) {
        // 棋子(m,n)位于左上部分
        if(i + j < N + 1) {
            m = (m + 1) - m / len * len;
            n = s - (s - (n - 1)) % len;
            // 棋子(m,n)位于右下部分
        } else {
            m = (m + 1) - ((m + 1) - s) / len * len;
            n = N - (N - (n - 1)) % len;
        }
        
        if(CB[m][n] == 1) {
            return ERROR;   // 该左斜列中遇到了棋子
        }
    }
    
    return OK;
}


/*━━━━━━━━━━━━━━━━━━━━━━ 图形化输出 ━━━━━━━━━━━━━━━━━━━━━━*/

/*
 * 展示棋盘中的皇后布局。
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
