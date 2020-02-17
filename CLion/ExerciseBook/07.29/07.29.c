#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "MGraph.h"    //**▲07 图**//

// 访问标志数组，记录访问过的顶点
static Boolean visited[MAX_VERTEX_NUM];


/*
 * 输出有向图G中长度为k的简单路径
 */
void Algo_7_29(MGraph G, int k);

/*
 * 查找有向图G中长度为k的简单路径
 */
void SimplePath_7_29(MGraph G, int start, int k, int path[MAX_VERTEX_NUM]);


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
    
    printf("████████ 查找定长的简单路径...\n");
    {
        int k = 4;
        
        Algo_7_29(G, k);
        printf("\n");
    }
    
    return 0;
}


/*
 * 输出有向图G中长度为k的简单路径
 */
void Algo_7_29(MGraph G, int k) {
    int i;
    int path[MAX_VERTEX_NUM + 1]; // 0号单元用来记录path中存储的顶点数量
    
    if(k <= 0) {
        printf("参数错误！\n");
        return;
    }
    
    // 把所有顶点标记为未访问
    for(i = 0; i < G.vexnum; i++) {
        visited[i] = FALSE;
    }
    
    path[0] = 0;
    
    printf("查找所有长度为 %d 的简单路径...\n", k);
    
    for(i = 0; i < G.vexnum; i++) {
        SimplePath_7_29(G, i, k, path);
    }
    
}

/*
 * 查找有向图G中长度为k的简单路径
 */
void SimplePath_7_29(MGraph G, int start, int k, int path[MAX_VERTEX_NUM]) {
    int i, w;
    
    path[0]++;
    path[path[0]] = start;
    visited[start] = TRUE;  // 标记该顶点已访问
    
    // 如果遇到长度为k的路径(顶点数 = 路径长度+1)，则输出它
    if(path[0] == k + 1) {
        // 输出找到的简单路径
        for(i = 1; i <= path[0]; i++) {
            printf("%c ", GetVex(G, path[i]));
        }
        printf("\n");
    } else {
        // 深度优先遍历
        for(w = FirstAdjVex(G, G.vexs[start]);
            w >= 0;
            w = NextAdjVex(G, G.vexs[start], G.vexs[w])) {
            // 忽略已访问过的顶点
            if(visited[w] == TRUE) {
                continue;
            }
            
            SimplePath_7_29(G, w, k, path);
        }
    }
    
    // 从路径中移除该顶点，并将其状态降级为"已访问"
    path[0]--;
    visited[start] = FALSE;  // 清除访问标记
}
