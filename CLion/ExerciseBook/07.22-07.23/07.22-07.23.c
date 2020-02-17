#include <stdio.h>
#include "Status.h"   //**▲01 绪论**//
#include "ALGraph.h"  //**▲07 图**//

// 访问标志数组，记录访问过的顶点
static Boolean visited[MAX_VERTEX_NUM];


/*
 * 通过深度优先遍历，输出顶点vi到vj之间的路径
 */
void Algo_7_22(ALGraph G, VertexType vi, VertexType vj);

/*
 * 深度优先遍历图G，查找顶点i到顶点j之间的路径存入path
 */
static Status DFS_7_22(ALGraph G, int i, int j, int path[MAX_VERTEX_NUM + 1]);

/*
 * 通过广度优先遍历，输出顶点vi到vj之间的路径
 */
void Algo_7_23(ALGraph G, VertexType vi, VertexType vj);

/*
 * 广度优先遍历图G，查找顶点i到顶点j之间的路径存入path
 */
static Status BFS_7_23(ALGraph G, int i, int j, int path[MAX_VERTEX_NUM + 1]);


int main(int argc, char* argv[]) {
    ALGraph G;
    
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
    
    printf("████████ 题7.22：通过深度优先遍历判断两顶点间是否存在路径...\n");
    {
        VertexType vi = 'A';
        VertexType vj = 'F';
        
        Algo_7_22(G, vi, vj);
        printf("\n");
    }
    
    printf("████████ 题7.23：通过广度优先遍历判断两顶点间是否存在路径...\n");
    {
        VertexType vi = 'A';
        VertexType vj = 'F';
    
        Algo_7_23(G, vi, vj);
        printf("\n");
    }
    
    return 0;
}


/*
 * 通过深度优先遍历，判断顶点vi到vj之间是否存在路径
 */
void Algo_7_22(ALGraph G, VertexType vi, VertexType vj) {
    int i, j, k;
    int path[MAX_VERTEX_NUM + 1];
    
    for(k = 0; k < G.vexnum; k++) {
        visited[k] = FALSE;
    }
    
    i = LocateVex(G, vi);
    j = LocateVex(G, vj);
    
    path[0] = 0;
    
    if(DFS_7_22(G, i, j, path) == ERROR) {
        printf("%c 到 %c 之间不存在通路！\n", vi, vj);
        return;
    }
    
    printf("%c 到 %c 之间的通路为：", vi, vj);
    for(k = 1; k <= path[0]; k++) {
        printf("%c ", GetVex(G, path[k]));
    }
    printf("\n");
}

/*
 * 深度优先遍历图G，查找顶点i到顶点j之间的路径存入path
 */
static Status DFS_7_22(ALGraph G, int i, int j, int path[MAX_VERTEX_NUM + 1]) {
    int w;
    
    // 将顶点i加入路径
    visited[i] = TRUE;
    path[0]++;
    path[path[0]] = i;
    
    if(i == j) {
        return OK;
    }
    
    // 遍历vi所有邻接点
    for(w = FirstAdjVex(G, GetVex(G, i)); w >= 0; w = NextAdjVex(G, GetVex(G, i), GetVex(G, w))) {
        // 跳过已访问的顶点
        if(visited[w]) {
            continue;
        }
        
        // 递归(深度优先)
        if(DFS_7_22(G, w, j, path) == OK) {
            return OK;
        }
    }
    
    // 移除顶点i
    visited[i] = FALSE;
    path[0]--;
    
    return ERROR;
}

/*
 * 通过广度优先遍历，判断顶点vi到vj之间是否存在路径
 */
void Algo_7_23(ALGraph G, VertexType vi, VertexType vj) {
    int i, j, k;
    int path[MAX_VERTEX_NUM + 1];
    
    for(k = 0; k < G.vexnum; k++) {
        visited[k] = FALSE;
    }
    
    i = LocateVex(G, vi);
    j = LocateVex(G, vj);
    
    path[0] = 0;
    
    if(BFS_7_23(G, i, j, path) == ERROR) {
        printf("%c 到 %c 之间不存在通路！\n", vi, vj);
        return;
    }
    
    printf("%c 到 %c 之间的通路为：", vi, vj);
    for(k = 1; k <= path[0]; k++) {
        printf("%c ", GetVex(G, path[k]));
    }
    printf("\n");
}

/*
 * 广度优先遍历图G，查找顶点i到顶点j之间的路径存入path
 */
static Status BFS_7_23(ALGraph G, int i, int j, int path[MAX_VERTEX_NUM + 1]) {
    int w;
    LinkQueue Q;
    QElemType e;
    
    // 将顶点i加入路径
    visited[i] = TRUE;
    path[0]++;
    path[path[0]] = i;
    
    if(i == j) {
        return OK;
    }
    
    // 置空辅助队列
    InitQueue(&Q);
    
    // 遍历vi所有邻接点
    for(w = FirstAdjVex(G, GetVex(G, i)); w >= 0; w = NextAdjVex(G, GetVex(G, i), GetVex(G, w))) {
        // 跳过已访问的顶点
        if(visited[w]) {
            continue;
        }
        
        if(w == j) {
            // 将顶点w加入路径
            visited[w] = TRUE;
            path[0]++;
            path[path[0]] = w;
            return OK;
        }
        
        EnQueue(&Q, w);
    }
    
    // 从邻接点出发，继续寻找目标路径
    while(!QueueEmpty(Q)) {
        DeQueue(&Q, &e);
    
        // 递归(广度优先)
        if(BFS_7_23(G, e, j, path) == OK) {
            return OK;
        }
    }
    
    // 移除顶点i
    visited[i] = FALSE;
    path[0]--;
    
    return ERROR;
}
