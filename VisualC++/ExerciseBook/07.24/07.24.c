#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "SqStack.h"    //**▲03 栈和队列**//
#include "MGraph.h"     //**▲07 图**//

// 访问标志数组，记录访问过的顶点
static Boolean visited[MAX_VERTEX_NUM];


/*
 * 利用栈对有向强连通图进行深度优先遍历，
 * 习题中指出不拘泥于具体的图结构，但是这里依旧采用了邻接矩阵存储的图作为示例。
 */
Status Algo_7_24(MGraph G);


int main(int argc, char* argv[]) {
    MGraph G;
    
    printf("████████ 创建并输出图...\n");
    {
        char* path[4];
        
        path[0] = "TestData_DG.txt";
        path[1] = "";
        path[2] = "";
        path[3] = "";
        
        CreateGraph(&G, path);
        PrintGraph(G);
        printf("\n");
    }
    
    printf("████████ 深度优先遍历图...\n");
    {
        Algo_7_24(G);
        printf("\n");
    }
    
    return 0;
}


/*
 * 利用栈对有向强连通图进行深度优先遍历，
 * 习题中指出不拘泥于具体的图结构，但是这里依旧采用了邻接矩阵存储的图作为示例。
 */
Status Algo_7_24(MGraph G) {
    SqStack S;
    SElemType e;
    int i;
    
    if(G.vexnum < 1) {
        return ERROR;
    }
    
    for(i = 0; i < G.vexnum; i++) {
        visited[i] = FALSE;
    }
    
    InitStack(&S);
    
    // 第一个顶点入栈
    Push(&S, 0);
    visited[0] = TRUE;
    printf("%c ", G.vexs[0]);
    
    while(!StackEmpty(S)) {
        GetTop(S, &e);
        
        for(i = 0; i < G.vexnum; i++) {
            if(G.arcs[e][i].adj!=0 && visited[i]==FALSE) {
                Push(&S, i);
                visited[i] = TRUE;
                printf("%c ", G.vexs[i]);
                
                // 立刻跳出当前循环，进行下一轮深度搜寻
                break;
            }
        }
        
        // 如果顶点e没有未访问的邻接点了，则将该顶点出栈
        if(i == G.vexnum) {
            Pop(&S, &e);
        }
    }
    
    printf("\n");
    
    return OK;
}
