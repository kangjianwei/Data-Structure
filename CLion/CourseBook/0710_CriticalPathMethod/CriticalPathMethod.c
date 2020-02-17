/*=======================
 * AOE-网(有向网)的关键路径
 *
 * 包含算法: 7.13、7.14
 ========================*/

#include "CriticalPathMethod.h"

/* 全局变量 */
static int ve[MAX_VERTEX_NUM];  // 各事件（顶点）的最早发生时间(越早越好)
static int vl[MAX_VERTEX_NUM];  // 各事件（顶点）的最晚发生时间(越晚越好)

/*
 * ████████ 算法7.14 ████████
 *
 * 计算有向网G的关键路径
 *
 * 注：有向网顶点序列中最后一个顶点必须为事件终点
 */
Status CriticalPath(ALGraph G) {
    int i, j, k;
    ArcNode* p;
    SqStack T;  // 拓扑序列顶点栈
    int dut;    // 活动持续时间
    int ee, el;
    char tag;
    int count;
    
    int path[MAX_VERTEX_NUM];           // 存储拓扑序列，跟T中存储的信息一致
    Boolean P[MAX_VERTEX_NUM]= {FALSE}; // 存储关键路径信息，只是为了最后的展示
    
    // 如果有向网存在回路，则无法计算其拓扑序列，进而也无法得出该有向网的关键路径
    if(!TopologicalOrder(G, &T)) {
        printf("异常退出：给定的有向网中存在回路，故无法生成完整的拓扑序列...\n");
        return ERROR;
    } else {
        printf("有向网的拓扑序列构建成功...\n");
        // 复制拓扑序列到path中以便后续输出
        for(i=0; i<StackLength(T); i++) {
            path[i] = T.base[i];
        }
    }
    
    // 初始化各事件的最晚发生时间为所有事件中最晚出现的那个最早发生时间(拓扑序列上最后一个事件的最早发生时间)
    for(i = 0; i < G.vexnum; i++) {
        vl[i] = ve[G.vexnum-1]; // ve[G.vexnum-1]代表终点的最早发生时间
    }
    
    // 逆序遍历拓扑序列顶点栈(将栈中顶点出栈即可达到逆序的目的)
    while(!StackEmpty(T)) {
        // 获取一个顶点
        Pop(&T, &j);
        
        // 遍历j顶点的邻接点
        for(p = G.vertices[j].firstarc; p != NULL; p = p->nextarc) {
            k = p->adjvex;              // 顶点j的邻接点序号
            dut = (*(p->info)).weight;  // j->k的权值，即事件j->k的持续时间
            
            // 将事件j的最晚发生时间提前
            if(vl[k] - dut < vl[j]) {
                vl[j] = vl[k] - dut;
            }
        }
    }
    
    count = 0;
    
    printf("计算有向网的关键路径信息...\n");
    
    // 遍历所有顶点
    for(j = 0; j < G.vexnum; j++) {
        // 遍历j顶点的邻接点
        for(p = G.vertices[j].firstarc; p != NULL; p = p->nextarc) {
            k = p->adjvex;
            dut = (*(p->info)).weight;
            
            ee = ve[j];         // 事件j的最早发生时间
            el = vl[k] - dut;   // 事件j的最晚发生时间
            
            // 用*标记关键路径
            tag = (ee == el) ? '*' : ' ';
            
            printf("%c-%c  a%-2d=%2d  (%2d, %2d)  %c\n", G.vertices[j].data, G.vertices[k].data, count++, dut, ee, el, tag);
    
            // 记录哪些顶点加入到了关键路径中
            if(tag=='*') {
                P[j] = TRUE;
                P[k] = TRUE;
            }
        }
    }
    
    
    /*
     * 注：教材中没有后续步骤
     * 此处增加这些步骤是为了更直观地显示关键路径信息
     */
    printf("\n");
    printf("当前有向网的关键路径为：");
    for(i = 0; i < G.vexnum; i++) {
        if(P[path[i]] == TRUE) {
            printf("%c ", G.vertices[path[i]].data);
        }
    }
    printf("\n");
    
    return OK;
}

/*
 * ████████ 算法7.13 ████████
 *
 * 如果有向网G无回路，则寻找它的一个拓扑序列存储到拓扑序列栈T中，并返回OK；否则，返回FALSE。
 * 拓扑序列通常不唯一，但是必须保证某些关键节点的先后次序。
 */
static Status TopologicalOrder(ALGraph G, SqStack* T) {
    int i, j, k, count;
    int indegree[MAX_VERTEX_NUM + 1];
    SqStack S;
    ArcNode* p;
    
    // 对各顶点求入度
    FindInDegree(G, indegree);
    
    // 初始化零入度顶点栈
    InitStack(&S);
    
    // 初始化拓扑序列顶点栈
    InitStack(T);
    
    // 建立入度为0的顶点栈
    for(i = 0; i < G.vexnum; i++) {
        // 将入度为0的顶点添加到栈中
        if(indegree[i] == 0) {
            Push(&S, i);
        }
        
        // 初始化零入度顶点(事件)的最早发生时间为0
        ve[i] = 0;
    }
    
    // 对拓扑序列中的顶点计数
    count = 0;
    
    // 遍历顶点栈
    while(!StackEmpty(S)) {
        // 获取一个零入度顶点
        Pop(&S, &j);
        
        // 将该顶点加入到拓扑序列顶点栈中
        Push(T, j);
        
        count++;
        
        // 遍历i号顶点的邻接点
        for(p = G.vertices[j].firstarc; p != NULL; p = p->nextarc) {
            // 将j号顶点每个邻接点的入度减一，这相当于切段j号顶点到其它邻接点的联系
            k = p->adjvex;
            
            // 如果出现了新的入度为0的顶点，继续将其入栈
            if((--indegree[k]) == 0) {
                Push(&S, k);
            }
            
            // 计算邻接点事件的最早发生时间
            if(ve[j] + (*(p->info)).weight > ve[k]) {
                ve[k] = ve[j] + (*(p->info)).weight;
            }
        }
    }
    
    // 如果遇到了回路，则返回ERROR
    if(count < G.vexnum) {
        return ERROR;
    } else {
        return OK;
    }
}

/*
 * 计算各顶点的入度
 */
static void FindInDegree(ALGraph G, int indegree[MAX_VERTEX_NUM]) {
    int i;
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
}
