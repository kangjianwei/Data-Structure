#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SqQueue.h"    //**▲03 栈和队列**//

/*
 * 生成车厢调度序列，其中：
 * 'L': 直接从入口开到出口
 * 'E': 从队头进入中转队列
 * 'A': 从队尾进入中转队列
 * 'D': 从队头出队
 *
 * 假设入口在右边，出口在左边，中转队列的队头在左边，队尾在右边，且车厢读取顺序【从左到右】
 *
 * En ：等待调度的列车序列
 * seq：调度序列
 */
void Algo_3_34(char* En, char seq[]);

/*
 * 使用约定好的调度序列seq，将入口En处的车厢调度到出口Ex
 *
 * 该方法可看做是对调度序列的检验
 *
 * En ：等待调度的列车序列
 * seq：调度序列
 * Ex ：调度完成后的序列
 */
Status Dispatch(char* En, char* seq, char Ex[]);


int main(int argc, char* argv[]) {
    char* En = "HPSHHSHPPHHSPSHSPSSHSP";    // 等待调度的列车序列
    char Ex[100] = {'\0'};                  // 调度完成的列车序列
    char seq[100] = {'\0'};                 // 调度序列
    
    printf("████ 入口处的序列：\n");
    printf("█ En  = %s\n", En);
    
    Algo_3_34(En, seq);
    printf("████ 生成的调度序列：\n");
    printf("█ seq = %s\n", seq);
    
    Dispatch(En, seq, Ex);
    printf("████ 根据生成的调度序列，对入口处的车厢调度，调度完成后的车厢序列：\n");
    printf("█ Ex  = %s\n", Ex);
    
    return 0;
}


/*
 * 生成车厢调度序列，其中：
 * 'L': 直接从入口开到出口
 * 'E': 从队头进入中转队列
 * 'A': 从队尾进入中转队列
 * 'D': 从队头出队
 *
 * 假设入口在右边，出口在左边，中转队列的队头在左边，队尾在右边，且车厢读取顺序【从左到右】
 *
 * En ：等待调度的列车序列
 * seq：调度序列
 */
void Algo_3_34(char* En, char seq[]) {
    int i, j;
    SqQueue Q;
    QElemType e;
    
    // 初始化一个中转队列
    InitQueue(&Q);
    
    for(i = j = 0; En[i] != '\0'; i++) {
        // 如果是硬座，直接调度到目的地
        if(En[i] == 'P') {
            seq[j++] = 'L';     // L代表直接从入口开到出口
        }
        
        // 如果是软卧，从队头进入中转队列
        if(En[i] == 'S') {
            EnQueue_3_34(&Q, En[i], 0);
            seq[j++] = 'E';
        }
        
        // 如果是硬卧，从队尾进入中转队列
        if(En[i] == 'H') {
            EnQueue_3_34(&Q, En[i], 1);
            seq[j++] = 'A';
        }
    }
    
    // 将中转队列中的软卧和硬卧从队头出队
    while(Q.front != Q.rear) {
        DeQueue(&Q, &e);
        seq[j++] = 'D';
    }
    
    seq[j] = '\0';
}

/*
 * 使用约定好的调度序列seq，将入口En处的车厢调度到出口Ex
 *
 * 该方法可看做是对调度序列的检验
 *
 * En ：等待调度的列车序列
 * seq：调度序列
 * Ex ：调度完成后的序列
 */
Status Dispatch(char* En, char* seq, char Ex[]) {
    int i, j, k;
    SqQueue Q;
    QElemType e;
    
    // 初始化一个中转队列
    InitQueue(&Q);
    
    i = j = k = 0;
    
    // 遍历调度序列
    while(seq[k] != '\0') {
        // 如果是硬座，直接从入口开到出口
        if(seq[k] == 'L') {
            Ex[j++] = En[i++];
        }
        
        // 如果是软卧，从队头进入中转队列
        if(seq[k] == 'E') {
            EnQueue_3_34(&Q, En[i++], 0);
        }
        
        // 如果是硬卧，从队尾进入中转队列
        if(seq[k] == 'A') {
            EnQueue_3_34(&Q, En[i++], 1);
        }
        
        // 将中转队列中的软卧和硬卧从队头出队
        if(seq[k] == 'D') {
            DeQueue(&Q, &e);
            Ex[j++] = e;
        }
        
        k++;
    }
    
    // 如果调度序列为空，但是入口处存在未调度的车厢，或者中转队列中存在未处理的车厢，则表示发生错误
    if(seq[k] == '\0' && (En[i] || Q.front == Q.rear)) {
        return ERROR;
    }
    
    Ex[j] = '\0';
    
    return OK;
}
