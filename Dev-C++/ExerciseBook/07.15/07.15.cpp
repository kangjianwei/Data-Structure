#include <stdio.h>
#include <stdarg.h>  // 提供宏va_list、va_start、va_arg、va_end
#include "Status.h"  //**▲01 绪论**//
#include "MGraph.h"  //**▲07 图**//

/*
 * 插入顶点
 *
 * 将指定的顶点v追加到顶点集中，未建立该顶点与其他顶点的关系
 */
Status InsertVex_7_15(MGraph* G, VertexType v);

/*
 * 删除顶点
 *
 * 从顶点集中删除指定的顶点v，注意需要更新相关的顶点关系
 */
Status DeleteVex_7_15(MGraph* G, VertexType v);

/*
 * 插入边/弧<v, w>
 *
 * 如果当前图/网是无向的，则插入一条弧需要增加两个顶点关系，但弧的数量只增一。
 *
 * 对于图来说，可以在可变参数中列出边/弧的附加信息；
 * 对于网来说，可以在可变参数中依次列出边/弧的权值以及附加信息。
 */
Status InsertArc_7_15(MGraph* G, VertexType v, VertexType w, ...);

/*
 * 删除边/弧<v, w>
 *
 * 此删除只是更新边/弧的连通关系
 */
Status DeleteArc_7_15(MGraph* G, VertexType v, VertexType w);


int main(int argc, char* argv[]) {
    MGraph G;
    
    printf("████████ 创建并输出图/网...\n");
    {
        char* path[4];
        
        path[0] = "TestData_DG.txt";
        path[1] = "TestData_DN.txt";
        path[2] = "TestData_UDG.txt";
        path[3] = "TestData_UDN.txt";
        
        CreateGraph(&G, path);
        PrintGraph(G);
        printf("\n");
    }
    
    printf("████████ 删除顶点...\n");
    {
        VertexType v = 'X';
    
        printf("删除顶点 '%c' 后的图为：\n", v);
        DeleteVex_7_15(&G, v);
        PrintGraph(G);
        printf("\n");
    }
    
    printf("████████ 插入顶点...\n");
    {
        VertexType v = 'Y';
    
        printf("插入顶点 '%c' 后的图为：\n", v);
        InsertVex_7_15(&G, v);
        PrintGraph(G);
        printf("\n");
    }
    
    printf("████████ 插入边/弧...\n");
    {
        // 注：<E, B>是重复的边
        VertexType v[10] = {'B', 'C', 'E', 'Y', 'Y', 'Y', 'D', 'D', 'E', 'E'};
        VertexType w[10] = {'Y', 'Y', 'Y', 'A', 'B', 'D', 'C', 'A', 'B', 'D'};
        VRType adj[10] = {8, 5, 1, 11, 2, 6, 3, 7, 2, 9};
        int k;
    
        // 图
        if(G.kind == DG || G.kind == UDG) {
            for(k = 0; k < 10; k++) {
                printf("插入无权值的边：<%c, %c>...\n", v[k], w[k]);
                InsertArc_7_15(&G, v[k], w[k]);
            }
        
            // 网
        } else if(G.kind == DN || G.kind == UDN) {
            for(k = 0; k < 10; k++) {
                printf("插入带权值的边：<%c, %c, %d>...\n", v[k], w[k], adj[k]);
                InsertArc_7_15(&G, v[k], w[k], adj[k]);
            }
        } else {
            return ERROR;
        }
    
        PrintGraph(G);
        printf("\n");
    }
    
    printf("████████ 删除边/弧...\n");
    {
        VertexType v[3] = {'D', 'E', 'F'};
        VertexType w[3] = {'A', 'B', 'B'};
        int k;
    
        for(k = 0; k < 3; k++) {
            printf("删除边：<%c, %c>...\n", v[k], w[k]);
            DeleteArc_7_15(&G, v[k], w[k]);
        }
        PrintGraph(G);
        printf("\n");
    }
    
    return 0;
}


/*
 * 插入顶点
 *
 * 将指定的顶点v追加到顶点集中，未建立该顶点与其他顶点的关系
 */
Status InsertVex_7_15(MGraph* G, VertexType v) {
    return InsertVex(G, v);
}

/*
 * 删除顶点
 *
 * 从顶点集中删除指定的顶点v，注意需要更新相关的顶点关系
 */
Status DeleteVex_7_15(MGraph* G, VertexType v) {
    return DeleteVex(G, v);
}

/*
 * 插入边/弧<v, w>
 *
 * 如果当前图/网是无向的，则插入一条弧需要增加两个顶点关系，但弧的数量只增一。
 *
 * 对于图来说，可以在可变参数中列出边/弧的附加信息；
 * 对于网来说，可以在可变参数中依次列出边/弧的权值以及附加信息。
 */
Status InsertArc_7_15(MGraph* G, VertexType v, VertexType w, ...) {
    va_list ap;
    VRType adj;
    InfoType* info = NULL;      // 边/弧的附加信息
    
    // 图
    if((*G).kind == DG || (*G).kind == UDG) {
    
        // 如果边/弧上存在附加信息
        if(IncInfo) {
            va_start(ap, w);                // 在w后查询首个可变参数
            info = va_arg(ap, InfoType*);   // 获取附加信息
            va_end(ap);
        }
        
        return InsertArc(G, v, w, info);
        
        // 网
    } else if((*G).kind == DN || (*G).kind == UDN) {
        va_start(ap, w);    // 在w后查询首个可变参数
    
        adj = va_arg(ap, VRType);   // 获取权值信息
    
        // 如果边/弧上存在附加信息
        if(IncInfo) {
            info = va_arg(ap, InfoType*);   // 获取附加信息
        }
    
        va_end(ap);
        
        return InsertArc(G, v, w, adj, info);
    } else {
        return ERROR;
    }
}

/*
 * 删除边/弧<v, w>
 *
 * 此删除只是更新边/弧的连通关系
 */
Status DeleteArc_7_15(MGraph* G, VertexType v, VertexType w) {
    return DeleteArc(G, v, w);
}
