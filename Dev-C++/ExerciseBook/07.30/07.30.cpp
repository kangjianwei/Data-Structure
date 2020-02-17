#include <stdio.h>
#include "Status.h"
#include "MGraph.h"

// 访问标志数组，记录访问过的顶点
static Boolean visited[MAX_VERTEX_NUM];


/*
 * 找出有向图中所有回路
 */
void Algo_7_30(MGraph G);

/*
 * 打印有向图中所有回路
 */
void Circuit_7_30(MGraph G, int start, int end, int path[MAX_VERTEX_NUM + 1]);


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
    
    printf("████████ 查找图中的回路...\n");
    {
        Algo_7_30(G);
        printf("\n");
    }
    
    return 0;
}


/*
 * 找出有向图中所有回路
 */
void Algo_7_30(MGraph G) {
    int i;
    int path[MAX_VERTEX_NUM + 1]; // 0号单元用来记录path中存储的顶点数量
    
    // 把所有顶点标记为未访问
    for(i = 0; i < G.vexnum; i++) {
        visited[i] = FALSE;
    }
    
    path[0] = 0;
    
    for(i = 0; i < G.vexnum; i++) {
        Circuit_7_30(G, i, i, path);
    }
}

/*
 * 打印有向图中所有回路
 */
void Circuit_7_30(MGraph G, int start, int end, int path[MAX_VERTEX_NUM]) {
    int i, w;
    
    path[0]++;
    path[path[0]] = start;
    visited[start] = TRUE;  // 标记该顶点已进入路径
    
    // 遍历顶点start的邻接点
    for(w = FirstAdjVex(G, G.vexs[start]); w >= 0; w = NextAdjVex(G, G.vexs[start], G.vexs[w])) {
        // 如果遇到了已在路径中的邻接点，说明出现了回路
        if(visited[w] == TRUE) {
            if(w == end) {
                // 输出回路
                for(i = 1; i <= path[0]; i++) {
                    printf("%c -> ", GetVex(G, path[i]));
                }
                printf("%c\n", GetVex(G, w));
            }
            
        } else {
            // 筛掉重复路径
            if(w > end) {
                Circuit_7_30(G, w, end, path);
            }
        }
    }
    
    // 从路径中移除该顶点，并将其状态降级为"已访问"
    path[0]--;
    visited[start] = FALSE;
}
