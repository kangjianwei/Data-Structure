#include <stdio.h>
#include "CSTree.h"
#include "MinimumSpanningTree.h"
#include "Graph.h"

/*
 * 求无向网的最小生成树
 */
void Algo_7_33(Graph G);


int main(int argc, char* argv[]) {
    Graph G;
    
    printf("████████ 创建并打印无向网... \n");
    {
        CreateGraph(&G, "TestData_UDN.txt");
        PrintGraph(G);
        printf("\n");
    }
    
    printf("████████ 使用克鲁斯卡尔算法获取最小生成树... \n");
    {
        Algo_7_33(G);
        printf("\n");
    }
}


/*
 * 求无向网的最小生成树
 */
void Algo_7_33(Graph G) {
    CSTree T = MinSpanTree_KRUSKAL(G);
    
    // 输出求取的最小生成树，此步骤可选
    PrintTree(T);
}
