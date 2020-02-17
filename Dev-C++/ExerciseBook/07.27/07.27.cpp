#include <stdio.h>
#include "Status.h"     //**▲01 绪论**//
#include "ALGraph.h"    //**▲07 图**//

// 访问标志数组，记录访问过的顶点
static Boolean visited[MAX_VERTEX_NUM];


/*
 * 输出满足条件的简单路径
 */
void Algo_7_27(ALGraph G, VertexType start, VertexType end, int k);

/*
 * 查找满足条件的简单路径。
 *
 * path用来存储路过的顶点，path[0]存储path中的顶点数量。
 *
 * 如果找到简单路径，则将其存储到path中，并返回OK；否则，返回ERROR。
 */
Status SimplePath_7_27(ALGraph G, int start, int end, int k, int path[MAX_VERTEX_NUM]);


int main(int argc, char* argv[]) {
    ALGraph G;
    
    printf("████████ 创建并输出图...\n");
    {
        char* path[4];
        
        path[0] = "";
        path[1] = "";
        path[2] = "TestData_UDG.txt";
        path[3] = "";
        
        CreateGraph(&G, path);
        PrintGraph(G);
        printf("\n");
    }
    
    printf("████████ 查找简单路径...\n");
    {
        VertexType start = 'A';
        VertexType end = 'B';
        int k = 4;
        
        Algo_7_27(G, start, end, k);
        printf("\n");
    }
    
    return 0;
}


/*
 * 输出满足条件的简单路径
 */
void Algo_7_27(ALGraph G, VertexType start, VertexType end, int k) {
    int i, m, n;
    int path[MAX_VERTEX_NUM + 1]; // 0号单元用来记录path中存储的顶点数量
    Status s;
    
    m = LocateVex(G, start);
    n = LocateVex(G, end);
    
    if(k <= 0 || m == -1 || n == -1 || m == n) {
        printf("参数错误！\n");
        return;
    }
    
    // 把所有顶点标记为未访问
    for(i = 0; i < G.vexnum; i++) {
        visited[i] = FALSE;
    }
    
    path[0] = 0;
    
    s = SimplePath_7_27(G, m, n, k, path);
    
    if(s == ERROR) {
        printf("未找到符合条件的简单路径！\n");
        return;
    }
    
    printf("%c 到 %c 之间存在的一条长度为 %d 的简单路径为：", start, end, k);
    for(i = 1; i <= path[0]; i++) {
        printf("%c ", GetVex(G, path[i]));
    }
    printf("\n");
}

/*
 * 查找满足条件的简单路径。
 *
 * path用来存储路过的顶点，path[0]存储path中的顶点数量。
 *
 * 如果找到简单路径，则将其存储到path中，并返回OK；否则，返回ERROR。
 */
Status SimplePath_7_27(ALGraph G, int start, int end, int k, int path[MAX_VERTEX_NUM]) {
    int w;
    
    path[0]++;
    path[path[0]] = start;
    visited[start] = TRUE;  // 标记该顶点已访问
    
    // 如果遇到终点，则需要视情形返回
    if(start == end) {
        // 顶点数 = 路径长度+1
        if(path[0] == k + 1) {
            return OK;
        }
    } else {
        // 深度优先遍历
        for(w = FirstAdjVex(G, G.vertices[start].data);
            w >= 0;
            w = NextAdjVex(G, G.vertices[start].data, G.vertices[w].data)) {
            // 忽略已访问过的顶点
            if(visited[w] == TRUE) {
                continue;
            }
            
            if(SimplePath_7_27(G, w, end, k, path) == OK) {
                return OK;
            }
        }
    }
    
    // 从路径中移除该顶点，并将其状态降级为"已访问"
    path[0]--;
    visited[start] = FALSE;  // 清除访问标记
    
    return ERROR;
}
