#include <stdio.h>
#include "ALGraph.h"    //**▲07 图**//

/*
 * 返回有向无环图的根在顶点向量中的序号，如果不存在，返回-1。
 *
 * 注：如果根结点存在，则意味着该根结点的入度一定为0。
 * 　　因为如果根的入度不为0，那么必定会形成环。
 * 　　因此，本题本质上就是寻找有向无环图中入度为0的那个顶点。
 */
int Algo_7_35(ALGraph G);


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
    
    printf("████████ 查找有向无环图的根...\n");
    {
        int r = Algo_7_35(G);
        
        if(r == -1) {
            printf("给定的有向图无环图不存在根\n");
        } else {
            printf("该有向无环图的根为：%c\n", G.vertices[r].data);
        }
        
        printf("\n");
    }
    
    return 0;
}


/*
 * 返回有向无环图的根在顶点向量中的序号，如果不存在，返回-1
 *
 * 注：如果根结点存在，则意味着该根结点的入度一定为0。
 * 　　因为如果根的入度不为0，那么必定会形成环。
 * 　　因此，本题本质上就是寻找有向无环图中入度为0的那个顶点。
 */
int Algo_7_35(ALGraph G) {
    int i, count, root;
    int indegree[MAX_VERTEX_NUM];
    ArcNode* p;
    
    // 初始化所有顶点的入度为0
    for(i = 0; i < G.vexnum; i++) {
        indegree[i] = 0;
    }
    
    // 遍历所有顶点
    for(i = 0; i < G.vexnum; i++) {
        // 指向该顶点的首个邻接点
        p = G.vertices[i].firstarc;
        
        // 遍历该顶点的所有邻接点，统计各顶点的入度
        while(p != NULL) {
            indegree[p->adjvex]++;
            p = p->nextarc;
        }
    }
    
    // 统计入度为0的顶点数量
    count = 0;
    root = -1;
    
    for(i = 0; i < G.vexnum; i++) {
        if(indegree[i] == 0) {
            count++;
            root = i;
        }
    }
    
    // 最多只有一个根
    if(count==1) {
        return root;
    } else {
        return -1;
    }
}
