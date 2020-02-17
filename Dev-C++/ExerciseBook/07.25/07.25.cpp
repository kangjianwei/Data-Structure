#include <stdio.h>
#include "Graph.h"

// 访问标志
typedef enum {
    UnVisited, // 未访问
    Visited,   // 已访问
    InPath,    // 在路径上
} FLAG;

// 访问标志数组，记录访问过的顶点
static FLAG flags[MAX_VERTEX_NUM];


/*
 * 找出有向图中的回路
 */
void Algo_7_25(Graph G);

/*
 * 从start顶点开始查找回路。
 *
 * path用来存储路过的顶点，path[0]存储path中的顶点数量。
 *
 * 如果找到回路，返回回路起始顶点的序号；
 * 如果没找到回路，则返回-1。
 */
int Circuit_7_25(Graph G, int start, int path[MAX_VERTEX_NUM + 1]);


int main(int argc, char* argv[]) {
    Graph G;
    
    printf("████████ 创建并输出图...\n");
    {
        char* path = "TestData_DG.txt";
        
        CreateGraph(&G, path);
        PrintGraph(G);
        printf("\n");
    }
    
    printf("████████ 查找图中的回路...\n");
    {
        Algo_7_25(G);
        printf("\n");
    }
    
    return 0;
}


/*
 * 找出有向图中的回路
 */
void Algo_7_25(Graph G) {
    int i, w = -1;
    int path[MAX_VERTEX_NUM + 1]; // 0号单元用来记录path中存储的顶点数量
    
    // 把所有顶点标记为未访问
    for(i = 0; i < G.vexnum; i++) {
        flags[i] = UnVisited;
    }
    
    path[0] = 0;
    
    for(i = 0; i < G.vexnum; i++) {
        w = Circuit_7_25(G, i, path);
        
        if(w != -1) {
            break;  // 如果找到了任意一条回路，跳出循环
        }
    }
    
    if(w == -1) {
        printf("给定的有向图中不存在回路！\n");
        return;
    }
    
    printf("有向图中找到的首条回路为：");
    for(i = 1; path[i] != w; i++) {
        // 寻找回路起点
    }
    // 找到了回路起点
    if(path[i] == w) {
        while(i <= path[0]) {
            printf("%c -> ", G.vexs[path[i]]);
            i++;
        }
        printf("%c\n", G.vexs[w]);
    }
}

/*
 * 从start顶点开始查找回路。
 *
 * path用来存储路过的顶点，path[0]存储path中的顶点数量。
 *
 * 如果找到回路，返回回路起始顶点的序号；
 * 如果没找到回路，则返回-1。
 */
int Circuit_7_25(Graph G, int start, int path[MAX_VERTEX_NUM]) {
    int i;
    int v, w;
    
    path[0]++;
    path[path[0]] = start;
    flags[start] = InPath;  // 标记该顶点已进入路径
    
    // 遍历顶点start的邻接点
    for(i = G.fst[start]; i <= G.lst[start]; i++) {
        v = G.s[i]; // 获取邻接点序号
        
        // 如果遇到了已在路径中的邻接点，说明出现了回路
        if(flags[v] == InPath) {
            return v;
            
            // 忽略已访问的邻接点
        } else if(flags[v] == Visited) {
            continue;
        } else {
            w = Circuit_7_25(G, v, path);
            if(w != -1) {
                return w;
            }
        }
    }
    
    // 从路径中移除该顶点，并将其状态降级为"已访问"
    path[0]--;
    flags[start] = Visited;
    
    return -1;
}
