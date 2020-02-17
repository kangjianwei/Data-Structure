#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "MGraph.h"    //**▲07 图**//

// 访问标志数组，记录访问过的顶点
static Boolean visited[MAX_VERTEX_NUM];


/*
 * 输出满足条件的简单路径
 */
void Algo_7_28(MGraph G, VertexType start, VertexType end);

/*
 * 查找start到end之间的所有的简单路径
 */
void SimplePath_7_28(MGraph G, int start, int end, int path[MAX_VERTEX_NUM]);


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
    
    printf("████████ 查找简单路径...\n");
    {
        VertexType start = 'u';
        VertexType end = 'v';
        
        Algo_7_28(G, start, end);
        printf("\n");
    }
    
    return 0;
}


/*
 * 输出start到end之间的所有的简单路径
 */
void Algo_7_28(MGraph G, VertexType start, VertexType end) {
    int i, m, n;
    int path[MAX_VERTEX_NUM + 1]; // 0号单元用来记录path中存储的顶点数量
    
    m = LocateVex(G, start);
    n = LocateVex(G, end);
    
    if(m == -1 || n == -1 || m == n) {
        printf("参数错误！\n");
        return;
    }
    
    // 把所有顶点标记为未访问
    for(i = 0; i < G.vexnum; i++) {
        visited[i] = FALSE;
    }
    
    path[0] = 0;
    
    printf("查找 %c 到 %c 之间存在的所有简单路径...\n", start, end);
    SimplePath_7_28(G, m, n, path);
}

/*
 * 查找start到end之间的所有的简单路径
 */
void SimplePath_7_28(MGraph G, int start, int end, int path[MAX_VERTEX_NUM]) {
    int i, w;
    
    path[0]++;
    path[path[0]] = start;
    visited[start] = TRUE;  // 标记该顶点已访问
    
    // 如果遇到满足题意的路径，则输出它
    if(start == end) {
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
    
            SimplePath_7_28(G, w, end, path);
        }
    }
    
    // 从路径中移除该顶点，并将其状态降级为"已访问"
    path[0]--;
    visited[start] = FALSE;  // 清除访问标记
}
