#include <stdio.h>
#include "ALGraph.h"
#include "SpanningTree.h"
#include "ArticulationPoints.h"

int main(int argc, char* argv[]) {
    ALGraph G;
    
    printf("████████ 创建并打印无向图... \n");
    {
        char* path[4];
        
        path[0] = "";
        path[1] = "";
        path[2] = "TestData_UDG.txt";
        path[3] = "";
        
        CreateGraph(&G, path);
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 打印该无向图的生成树，该步骤非必要，只是用作展示其遍历结构而已 \n");
    {
        CSTree T;
        
        printf("构造无向图的生成树（森林）... \n");
        DFSForest(G, &T);
        PrintTree(T);
        printf("\n");
    }
    PressEnterToContinue(debug);
    
    printf("████████ 寻找并输出关节点... \n");
    {
        printf("打印所有找到的关节点：\n");
        FindArticul(G);
    }
    PressEnterToContinue(debug);
    
    return 0;
}
