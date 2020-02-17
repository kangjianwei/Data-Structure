#include <stdio.h>
#include "SqStack.h"
#include "ALGraph.h"

// 缓存已找到的权值和最大的路径的权值和
static int MAX = -1;


/*
 * 求取有向网中的关键路径(CPM)
 *
 * 此处利用深度优先遍历的思想来求取关键路径，其基本原理是：关键路径 = 权值和最大的路径
 *
 * 注：教材中应该是笔误，不是求有向图的关键路径，而是求有向网的最长路径
 */
void Algo_7_41(ALGraph G);

/*
 * 查找关键路径上的源点
 *
 * 此处使用另外一种方式求源点，而不是像之前一样通过入度信息求源点，
 * 不过这两种方法是殊途同归的。
 */
static int FindBegin_7_41(ALGraph G);

/*
 * 通过深度优先遍历查找图中从顶点v出发的权值最长的路径(关键路径)。
 *
 * sum和S用来缓存路径权值和与已经找到的路径，
 * path用来记录当前找到的权值和最大的路径，path[0]上存储顶点数量。
 */
static void FindPath_7_41(ALGraph G, int v, int sum, SqStack* S, int path[MAX_VERTEX_NUM + 1]);


int main(int argc, char* argv[]) {
    ALGraph G;
    
    printf("████████ 创建并打印有向网... \n");
    {
        char* path[4];
        
        path[0] = "";
        path[1] = "TestData_DN.txt";
        path[2] = "";
        path[3] = "";
        
        CreateGraph(&G, path);
        PrintGraph(G);
    }
    PressEnterToContinue(debug);
    
    printf("████████ 求取有向网的关键路径... \n");
    {
        Algo_7_41(G);
    }
    PressEnterToContinue(debug);
    
    return 0;
}


/*
 * 求取有向网中的关键路径(CPM)
 *
 * 此处利用深度优先遍历的思想来求取关键路径，其基本原理是：关键路径 = 权值和最大的路径
 *
 * 注：教材中应该是笔误，不是求有向图的关键路径，而是求有向网的最长路径
 */
void Algo_7_41(ALGraph G) {
    int i;
    int begin;  // 关键路径上的源点
    int path[MAX_VERTEX_NUM + 1] = {-1}; // 存储权值和最大的路径，0好单元存储权值和
    SqStack S;
    
    // 查找关键路径上的源点
    begin = FindBegin_7_41(G);
    
    InitStack(&S);
    
    FindPath_7_41(G, begin, 0, &S, path);
    
    printf("已找到的权值和最大的路径(关键路径)为：");
    for(i = 1; i <= path[0]; i++) {
        printf("%c ", G.vertices[path[i]].data);
    }
    printf("\n");
}

/*
 * 查找关键路径上的源点
 *
 * 此处使用另外一种方式求源点，而不是像之前一样通过入度信息求源点，
 * 不过这两种方法是殊途同归的。
 */
static int FindBegin_7_41(ALGraph G) {
    int k;
    ArcNode* p;
    Boolean isAdj[MAX_VERTEX_NUM] = {FALSE};   // 记录哪些顶点做了邻接点
    
    // 找到所有邻接点
    for(k = 0; k < G.vexnum; k++) {
        for(p = G.vertices[k].firstarc; p != NULL; p = p->nextarc) {
            isAdj[p->adjvex] = TRUE;
        }
    }
    
    // 关键路径上的源点没有入弧，所以也不会成为别的顶点的邻接点
    for(k = 0; k < G.vexnum; k++) {
        if(isAdj[k] == FALSE) {
            return k;
        }
    }
    
    return -1;
}

/*
 * 通过深度优先遍历查找图中从顶点v出发的权值最长的路径(关键路径)。
 *
 * sum和S用来缓存路径权值和与已经找到的路径，
 * path用来记录当前找到的权值和最大的路径，path[0]上存储顶点数量。
 */
static void FindPath_7_41(ALGraph G, int v, int sum, SqStack* S, int path[MAX_VERTEX_NUM + 1]) {
    int i;
    ArcNode* p;
    SElemType e;
    
    // 将遇到的顶点暂存到路径栈
    Push(S, v);
    
    // 深度优先遍历
    for(p = G.vertices[v].firstarc; p != NULL; p = p->nextarc) {
        sum += p->info->weight;
        FindPath_7_41(G, p->adjvex, sum, S, path);
        sum -= p->info->weight;
    }
    
    /*
     * 至此，此路径已遍历到了尽头，
     * 如果该路径的权值和比之前找到的路径权值和更大，则需要把该路径完整地保存到path中，
     * 保存完成后，将当前顶点v退栈
     */
    
    // 如果该顶点是终点(表现为没有邻接点)
    if(G.vertices[v].firstarc == NULL) {
        // 发现了权值和更大的路径
        if(sum > MAX) {
            MAX = sum;
            
            path[0] = StackLength(*S);
            
            // 将栈中保存的路径复制到path中
            for(i = 0; i < StackLength(*S); i++) {
                path[i + 1] = S->base[i];
            }
        }
    }
    
    Pop(S, &e);
}
