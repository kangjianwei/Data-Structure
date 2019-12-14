#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SqStack.h"    //**▲03 栈和队列**//

/*
 * 生成车厢调度序列，其中'I'代表入栈，'O'代表出栈
 *
 * 假设入口在右边，出口在左边，且车厢读取顺序【从左到右】
 *
 * En ：等待调度的列车序列
 * seq：调度序列
 */
void Algo_3_16(char* En, char seq[]);

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
    char* En = "HSHHSHHHSSHSSSHS";  // 等待调度的列车序列
    char Ex[100] = {'\0'};          // 调度完成的列车序列
    char seq[100] = {'\0'};         // 调度序列
    
    printf("████ 入口处的序列：\n");
    printf("█ En  = %s\n", En);
    
    Algo_3_16(En, seq);
    printf("████ 生成的调度序列：\n");
    printf("█ seq = %s\n", seq);
    
    Dispatch(En, seq, Ex);
    printf("████ 根据生成的调度序列，对入口处的车厢调度，调度完成后的车厢序列：\n");
    printf("█ Ex  = %s\n", Ex);
    
    return 0;
}


/*
 * 生成车厢调度序列，其中'I'代表入栈，'O'代表出栈
 *
 * 假设入口在右边，出口在左边，车厢读取顺序从左到右
 *
 * En ：等待调度的列车序列
 * seq：调度序列
 */
void Algo_3_16(char* En, char seq[]) {
    int i, j;
    SqStack S;
    SElemType e;
    
    // 初始化一个中转栈
    InitStack(&S);
    
    // 遍历待调度序列
    for(i = j = 0; En[i] != '\0'; i++) {
        // 遇到硬席，则将其入栈
        if(En[i] == 'H') {
            Push(&S, En[i]);
            seq[j++] = 'I';
        }
        
        // 遇到软席，则先入栈，并立即出栈，相当于用栈做中转
        if(En[i] == 'S') {
            Push(&S, En[i]);
            Pop(&S, &e);
            seq[j++] = 'I';
            seq[j++] = 'O';
        }
    }
    
    // 将中转栈中的硬席出栈
    while(!StackEmpty(S)) {
        Pop(&S, &e);
        seq[j++] = 'O';
    }
    
    seq[j] = '\0';
    
    DestroyStack(&S);
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
    SqStack S;
    SElemType e;
    
    // 初始化一个中转栈
    InitStack(&S);
    
    i = j = k = 0;
    
    // 遍历调度序列
    while(seq[k] != '\0') {
        // 遇到入栈标记，则将车厢加入中转栈
        if(seq[k] == 'I') {
            Push(&S, En[i++]);
        }
        
        // 遇到出栈标记，则将车厢移除，并转移到出口处
        if(seq[k] == 'O') {
            Pop(&S, &e);
            Ex[j++] = e;
        }
        
        k++;
    }
    
    // 如果调度序列为空，但是入口处存在未调度的车厢，或者中转栈里存在未处理的车厢，则表示发生错误
    if(seq[k] == '\0' && (En[i] || StackEmpty(S))) {
        return ERROR;
    }
    
    Ex[j] = '\0';
    
    DestroyStack(&S);
    
    return OK;
}
