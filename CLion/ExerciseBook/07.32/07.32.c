#include <stdio.h>
#include "CSTree.h"
#include "ALGraph.h"
#include "MinimumSpanningTree.h"

/*
 * 求无向网的最小生成森林
 */
void Algo_7_32(ALGraph G);


int main(int argc, char* argv[]) {
    ALGraph G;
    
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
    
    printf("████████ 使用普里姆算法获取最小生成森林... \n");
    {
        Algo_7_32(G);
    }
    PressEnterToContinue(debug);
    
}


/*
 * 求无向网的最小生成森林
 */
void Algo_7_32(ALGraph G) {
    CSTree T = MinSpanTree_PRIM(G);
    
    // 输出求取的最小生成森林，此步骤可选
    PrintTree(T);
}
