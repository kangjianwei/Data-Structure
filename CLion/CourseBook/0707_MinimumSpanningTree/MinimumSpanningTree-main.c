#include <stdio.h>
#include "MGraph.h"
#include "MinimumSpanningTree.h"

int main(int argc, char* argv[]) {
    MGraph G;
    
    printf("████████ 创建并打印无向网... \n");
    {
        char* path[4];
        
        path[0] = "";
        path[1] = "";
        path[2] = "";
        path[3] = "TestData_UDN.txt";
        
        CreateGraph(&G, path);
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 使用普里姆算法获取最小生成树... \n");
    {
        MinSpanTree_PRIM(G, 'A'); // 默认从顶点'A'出发
    }
    PressEnterToContinue(debug);
    
    printf("████████ 使用克鲁斯卡尔算法获取最小生成树... \n");
    {
        MinSpanTree_KRUSKAL(G);
    }
    PressEnterToContinue(debug);
    
}
