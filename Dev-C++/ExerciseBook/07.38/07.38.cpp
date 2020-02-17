#include <stdio.h>
#include "SqList.h"
#include "ALGraph.h"

/*
 * 获取存储在有向无环图中的表达式的逆波兰式
 *
 * 注：表达式结构参考教材插图7.23
 */
void Algo_7_38(ALGraph G);

/*
 * 从顶点v出发获取有向图中存储的表达式的逆波兰式。
 * 求取的逆波兰式会存储在RPN中。
 */
static void AntiPolandFormula_7_38(ALGraph G, int v, SqList* RPN);


int main(int argc, char* argv[]) {
    ALGraph G;
    
    printf("████████ 创建并打印有向网... \n");
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
    
    printf("████████ 求取有向网中存储的表达式的逆波兰式... \n");
    {
        Algo_7_38(G);
        printf("\n");
    }
    
    return 0;
}


/*
 * 获取存储在有向无环图中的表达式的逆波兰式
 *
 * 注：表达式结构参考教材插图7.23
 */
void Algo_7_38(ALGraph G) {
    int i, root;
    int indegree[MAX_VERTEX_NUM];   // 所有顶点的入度信息
    ArcNode* p;
    SqList RPN;  // 存储逆波兰表达式
    ElemType e;
    
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
    
    // 查找到根结点
    for(i = 0; i < G.vexnum; i++) {
        if(indegree[i] == 0) {
            root = i;
            break;
        }
    }
    
    // 初始化长度为0的线性表
    InitList(&RPN);
    
    // 从有向无环图的根结点出发，通过尾递归获取到其中存储的表达式的逆波兰式
    AntiPolandFormula_7_38(G, root, &RPN);
    
    for(i = 1; i <= ListLength(RPN); i++) {
        GetElem(RPN, i, &e);
        printf("%c", ops[e]);
    }
    printf("\n");
}

/*
 * 从顶点v出发获取有向图中存储的表达式的逆波兰式。
 * 求取的逆波兰式会存储在RPN中。
 */
void AntiPolandFormula_7_38(ALGraph G, int v, SqList* RPN) {
    ArcNode* r;
    
    // 先遍历邻接点
    for(r = G.vertices[v].firstarc; r != NULL; r = r->nextarc) {
        AntiPolandFormula_7_38(G, r->adjvex, RPN);
    }
    
    // 当没有邻接点可遍历时，存储该顶点
    ListInsert(RPN, ListLength(*RPN) + 1, v);
}
