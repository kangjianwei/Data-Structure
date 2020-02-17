#include <stdio.h>
#include "ALGraph.h"     //**▲07 图**//

// 测试函数，打印元素
Status PrintElem(VertexType c) {
    printf("%c ", c);
    return OK;
}


int main(int argc, char* argv[]) {
    ALGraph G;
    
    printf("████████ CreateGraph \n");
    {
        char* path[4];
        
        path[0] = "TestData_DG.txt";
        path[1] = "TestData_DN.txt";
        path[2] = "TestData_UDG.txt";
        path[3] = "TestData_UDN.txt";
        
        printf("创建图/网...\n");
        CreateGraph(&G, path);
    }
    PressEnterToContinue(debug);
    
    printf("████████ PrintGraph \n");
    {
        printf("输出图/网的邻接矩阵... \n");
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ LocateVex \n");
    {
        VertexType u = 'X';
        printf("顶点 '%c' 的位置为 %d\n", u, LocateVex(G, u));
    }
    PressEnterToContinue(debug);
    
    printf("████████ GetVex \n");
    {
        int v = 1;
        printf("索引 '%d' 处的顶点值为 %c\n", v, GetVex(G, v));
    }
    PressEnterToContinue(debug);
    
    printf("████████ FirstAdjVex \n");
    {
        VertexType v = 'X';
        int k = FirstAdjVex(G, v);
        printf("顶点 '%c' 的第一个邻接顶点为 '%c'\n", v, G.vertices[k].data);
    }
    PressEnterToContinue(debug);
    
    printf("████████ NextAdjVex \n");
    {
        VertexType v = 'X';
        VertexType w = 'A';
        int k = NextAdjVex(G, v, w);
        printf("顶点 '%c' 相对于顶点 '%c' 的下一个邻接顶点为 '%c'\n", v, w, G.vertices[k].data);
    }
    PressEnterToContinue(debug);
    
    printf("████████ DeleteVex \n");
    {
        VertexType v = 'X';
        
        printf("删除顶点 '%c' ...\n", v);
        DeleteVex(&G, v);
        
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ InsertVex \n");
    {
        VertexType v = 'Y';
        printf("插入顶点 '%c' ...\n", v);
        InsertVex(&G, v);
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ InsertArc \n");
    {
        // 注：<E, B>是重复的边
        VertexType v[10] = {'B', 'C', 'E', 'Y', 'Y', 'Y', 'D', 'D', 'E', 'E'};
        VertexType w[10] = {'Y', 'Y', 'Y', 'A', 'B', 'D', 'C', 'A', 'B', 'D'};
        InfoType info[10] = {{8}, {5}, {1}, {11}, {2}, {6}, {3}, {7}, {2}, {9}};
        int k;
        
        // 图
        if(G.kind == DG || G.kind == UDG) {
            for(k = 0; k < 10; k++) {
                printf("插入无权值的边：<%c, %c>...\n", v[k], w[k]);
                InsertArc(&G, v[k], w[k]);
            }
            
            // 网
        } else if(G.kind == DN || G.kind == UDN) {
            for(k = 0; k < 10; k++) {
                printf("插入带权值的边：<%c, %c, %d>...\n", v[k], w[k], info[k].weight);
                InsertArc(&G, v[k], w[k], &info[k]);
            }
        } else {
            return ERROR;
        }
        
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ PutVex \n");
    {
        VertexType v = 'Y';
        VertexType value = 'F';
        printf("对顶点 '%c' 赋值 '%c' ...\n", v, value);
        PutVex(&G, v, value);
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ DeleteArc \n");
    {
        VertexType v[3] = {'D', 'E', 'F'};
        VertexType w[3] = {'A', 'B', 'B'};
        int k;
        
        for(k = 0; k < 3; k++) {
            printf("删除边：<%c, %c>...\n", v[k], w[k]);
            DeleteArc(&G, v[k], w[k]);
        }
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ DFSTraverse等 \n");
    {
        printf("深度优先遍历图/网...\n");
        DFSTraverse(G, PrintElem);
        printf("\n");
    }
    PressEnterToContinue(debug);
    
    printf("████████ BFSTraverse \n");
    {
        printf("广度优先遍历图/网...\n");
        BFSTraverse(G, PrintElem);
        printf("\n");
    }
    PressEnterToContinue(debug);
    
    printf("████████ DestroyGraph \n");
    {
        printf("销毁图/网G...\n");
        DestroyGraph(&G);
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
}
