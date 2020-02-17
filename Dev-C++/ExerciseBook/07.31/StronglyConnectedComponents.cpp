/*==================
 * 有向图的强连通分量
 ===================*/

#include "StronglyConnectedComponents.h"


/* 全局变量 */
static int count;      // 对访问过的结点计数

// Kosaraju算法
static Boolean visited[MAX_VERTEX_NUM];    // 访问标志数组，记录访问过的顶点
static int finished[MAX_VERTEX_NUM];       // 存储深度优先遍历中访问到的元素

// Tarjan算法
static int dfs[MAX_VERTEX_NUM];    // 深度优先遍历时依次访问到的元素(的序号)
static int low[MAX_VERTEX_NUM];    // low[v]  ==> 元素v可以回溯到的最早祖先
static int stack[MAX_VERTEX_NUM];  // 存储遍历过程中遇到的结点


/*
 * (1) Tarjan算法求取强连通分量
 *
 * 核心思想是深度优先遍历+回溯，与本章第8节求关节点的算法有类似之处
 */
void Tarjan(OLGraph G) {
    int i;
    
    count = -1;  // 初始化计数
    
    // 初始化顶点为尚未访问
    for(i = 0; i < G.vexnum; i++) {
        dfs[i] = -1;
        low[i] = -1;
    }
    
    printf("打印当前有向图中的各组强连通分量：\n");
    
    for(i = 0; i < G.vexnum; i++) {
        if(dfs[i] == -1) {
            DFS_Tarjan(G, i);
        }
    }
}

/*
 * 深度优先遍历顶点v可达的所有元素，并尝试找出其中的强连通分量
 */
static void DFS_Tarjan(OLGraph G, int v) {
    int min;
    int w;
    int i;
    
    ++count;
    
    // 记录访问次序
    dfs[v] = min = count;
    
    // 记录遇到的结点
    stack[count] = v;
    
    // 深度遍历v起始的图
    for(w = FirstAdjVex(G, G.xlist[v].data); w >= 0; w = NextAdjVex(G, G.xlist[v].data, G.xlist[w].data)) {
        // 如果w结点未访问
        if(dfs[w] == -1) {
            DFS_Tarjan(G, w);  // 对尚未访问的顶点调用DFS
            
            if(low[w] < min) {
                min = low[w];
            }
            
            // 遇到已访问过的结点
        } else {
            // 如果w已被访问过，且w是v在生成树上的祖先
            if(dfs[w] < min) {
                min = dfs[w];
            }
        }
    }
    
    // 如果"祖先"结点还没有确定回溯祖先，则只记录"祖先"结点上的访问次序
    if(low[stack[min]]==-1) {
        low[v] = min;
    } else {
        // 获取"祖先"结点上的可回溯祖先
        low[v] = low[stack[min]];
    }
    
    // 获取当前已搜索到的强连通子集
    if(low[v] == dfs[v]) {
        for(i = count; i >= 0; i--) {
            if(low[stack[i]] == dfs[v]) {
                printf("%c ", GetVex(G, stack[i]));
                count--;
            } else {
                break;
            }
        }
        printf("\n");
    }
}


/*
 * (2) Kosaraju算法求取强连通分量，这是教材中提到的算法
 *
 * 核心思想是：
 * 1.从某顶点出发，深度遍历有向图，得到一个访问序列；
 * 2.逆置有向图；
 * 3.遍历上面得出的访问序列，对其中的每个顶点进行深度优先遍历。
 */
void Kosaraju(OLGraph G) {
    int i, v;
    
    count = 0;  // 初始化计数
    
    // 1.从某顶点出发，深度遍历有向图，得到一个访问序列
    DFSTraverse(G, StoreElem);
    
    // 2.逆置有向图
    InverseGraph(&G);
    
    // 访问标志数组初始化
    for(i = 0; i < G.vexnum; i++) {
        visited[i] = FALSE;
    }
    
    printf("打印当前有向图中的各组强连通分量：\n");
    
    // 3.遍历上面得出的访问序列，对其中的每个顶点进行深度优先遍历
    for(i = 0; i < count; i++) {
        v = LocateVex(G, finished[i]);
        
        if(visited[v] == TRUE) {
            continue;
        }
        
        DFS_Inverse(G, v);
        printf("\n");
    }
}

/*
 * 逆置有向图（十字链表存储结构），即将所有弧的方向逆置
 *
 * 核心思想是：
 * 1.创建一个不包含任何弧的空图；
 * 2.依次遍历每个顶点的每条入弧；
 * 3.摘下遇到的入弧，将其插入到空图中变成出弧。
 */
static void InverseGraph(OLGraph* G) {
    OLGraph newG = *G;
    int i;
    ArcBox* r;
    ArcBox* pre, * p;
    int tmp;
    
    for(i = 0; i < newG.vexnum; i++) {
        newG.xlist[i].firstin = NULL;
        newG.xlist[i].firstout = NULL;
    }
    
    for(i = 0; i < (*G).vexnum; i++) {
        while((*G).xlist[i].firstin != NULL) {
            // 摘下遇到的指向顶点i的入弧
            r = (*G).xlist[i].firstin;
            (*G).xlist[i].firstin = r->hlink;
            
            // 逆置弧的方向
            tmp = r->headvex;
            r->headvex = r->tailvex;
            r->tailvex = tmp;
            
            r->hlink = NULL;
            r->tlink = NULL;
            
            // 插入到新图的纵向上
            pre = newG.xlist[r->headvex].firstin;
            if(pre == NULL) {
                newG.xlist[r->headvex].firstin = r;
            } else {
                if(r->tailvex < pre->tailvex) {
                    r->hlink = newG.xlist[r->headvex].firstin;
                    newG.xlist[r->headvex].firstin = r;
                } else if(r->tailvex > pre->tailvex) {
                    p = pre->hlink;
                    
                    while(p != NULL && r->tailvex > p->tailvex) {
                        pre = p;
                        p = p->hlink;
                    }
                    
                    if(p == NULL || r->tailvex < p->tailvex) {
                        r->hlink = p;
                        pre->hlink = r;
                    }
                } else {
                    // 等于时不处理
                }
            }
            
            // 插入到新图的横向上
            pre = newG.xlist[r->tailvex].firstout;
            if(pre == NULL) {
                newG.xlist[r->tailvex].firstout = r;
            } else {
                if(r->headvex < pre->headvex) {
                    r->tlink = newG.xlist[r->tailvex].firstout;
                    newG.xlist[r->tailvex].firstout = r;
                } else if(r->headvex > pre->headvex) {
                    p = pre->tlink;
                    
                    while(p != NULL && r->headvex > p->headvex) {
                        pre = p;
                        p = p->tlink;
                    }
                    
                    if(p == NULL || r->headvex < p->headvex) {
                        r->tlink = p;
                        pre->tlink = r;
                    }
                } else {
                    // 等于时不处理
                }
            }
        }
    }
    
    *G = newG;
}

/*
 * 存储深度优先遍历中访问到的元素
 */
static Status StoreElem(VertexType c) {
    finished[count++] = c;
    return OK;
}

/*
 * 深度遍历已经逆置后的图
 */
static void DFS_Inverse(OLGraph G, int v) {
    int w;
    
    // 如果已访问过，直接返回
    if(visited[v] == TRUE) {
        return;
    }
    
    // 从第v个顶点出发递归地深度优先遍历图G
    visited[v] = TRUE;
    
    // 打印访问到的顶点
    printf("%c ", GetVex(G, v));
    
    for(w = FirstAdjVex(G, G.xlist[v].data);
        w >= 0;
        w = NextAdjVex(G, G.xlist[v].data, G.xlist[w].data)) {
        DFS_Inverse(G, w);  // 对尚未访问的顶点调用DFS
    }
}
