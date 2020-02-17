/*=================================
 * 图的数组(邻接矩阵)存储表示
 *
 * 包含算法: 7.1、7.2、7.4、7.5、7.6
 ==================================*/

#include "MGraph.h"     //**▲07 图**//

// 录入数据的源文件；fp为null时，说明需要从控制台录入
static FILE* fp = NULL;

/*
 * IncInfo指示该图/网的边/弧上是否存在附加信息。
 * 如果其值不为0，则表示无附加信息，否则，表示存在附加信息。
 */
Boolean IncInfo = FALSE;


/*
 * ████████ 算法7.1 ████████
 *
 * 创建图/表
 *
 *【备注】
 *
 * 教材中默认从控制台读取数据。
 * 这里为了方便测试，避免每次运行都手动输入数据，
 * 因而允许选择从预设的文件path中读取测试数据。
 *
 * 如果需要从控制台读取数据，则path为NULL，或path[kind]为""。
 * 如果需要从文件中读取数据，则需要在path中填写文件名信息。
 */
Status CreateGraph(MGraph* G, char* path[]) {
    int readFromConsole;    // 是否从控制台读取数据
    int kind;
    Status flag;
    
    // ★★★此处固定为有向图
    kind = 0;
    
    // 如果没有文件路径信息，则从控制台读取输入
    readFromConsole = (path == NULL) || strcmp(path[kind], "") == 0;
    
    // 需要从文件读取
    if(readFromConsole) {
        (*G).kind = kind;   // 记录图/网的类型
    } else {
        // 打开文件，准备读取测试数据
        fp = fopen(path[kind], "r");
        if(fp == NULL) {
            return ERROR;
        }
        
        // 录入图的类型
        ReadData(fp, "%d", &((*G).kind));
    }
    
    // 随机创建有向图/网或无向图/网的一种
    switch((*G).kind) {
        case DG:
            flag = CreateDG(G);
            break;
        default:
            flag = ERROR;
            break;
    }
    
    if(fp != NULL) {
        fclose(fp);
        fp = NULL;
    }
    
    return flag;
}

/*
 * 构造有向图
 */
static Status CreateDG(MGraph* G) {
    int i, j, k;
    ArcCell arcs = {0, NULL};   // 有向图每条边的初始值
    VertexType v1, v2;
    
    if(fp == NULL) {
        printf("请输入有向图的顶点数：");
        scanf("%d", &((*G).vexnum));
        printf("请输入有向图的弧数：");
        scanf("%d", &((*G).arcnum));
        printf("该有向图的弧上是否包含其他附加信息(0-不包含│1-包含)：");
        scanf("%d", &IncInfo);
        
        // 录入顶点集
        printf("请录入 %d 个顶点，不同顶点之间用空格隔开：", (*G).vexnum);
        for(i = 0; i < (*G).vexnum; i++) {
            // 跳过空白，寻找下一个"可读"符号
            skipBlank(stdin);
            scanf("%c", &((*G).vexs[i]));
        }
    } else {
        ReadData(fp, "%d", &((*G).vexnum)); // 录入顶点数
        ReadData(fp, "%d", &((*G).arcnum)); // 录入弧数
        ReadData(fp, "%d", &IncInfo);       // 判断弧上是否包含附加信息
        
        // 录入顶点集
        for(i = 0; i < (*G).vexnum; i++) {
            // 跳过空白，寻找下一个"可读"符号
            skipBlank(fp);
            ReadData(fp, "%c", &((*G).vexs[i]));
        }
    }
    
    // 初始化有向图的邻接矩阵
    for(i = 0; i < (*G).vexnum; i++) {
        for(j = 0; j < (*G).vexnum; j++) {
            (*G).arcs[i][j] = arcs;
        }
    }
    
    // 仅在控制台录入信息时输出此提示
    if(fp == NULL && (*G).arcnum != 0) {
        printf("请为有向图依次录入 %d 条弧的信息，顶点之间用空格隔开：\n", (*G).arcnum);
    }
    
    // 录入弧的信息
    for(k = 0; k < (*G).arcnum; k++) {
        if(fp == NULL) {
            printf("第 %2d 条弧：", k + 1);
            skipBlank(stdin);   // 跳过空白，寻找下一个可读符号
            scanf("%c", &v1);
            skipBlank(stdin);   // 跳过空白，寻找下一个可读符号
            scanf("%c", &v2);
        } else {
            // 跳过空白，寻找下一个可读符号
            skipBlank(fp);
            ReadData(fp, "%c%c", &v1, &v2);
        }
        
        i = LocateVex(*G, v1);  // 获取顶点v1在顶点集中的位置
        j = LocateVex(*G, v2);  // 获取顶点v2在顶点集中的位置
        
        // 将指定的顶点关系设置为1，指示这两个顶点是直接连接的(注：这里没有验证下标是否越界)
        (*G).arcs[i][j].adj = 1;
        
        // 如果需要录入弧的其他附加信息
        if(IncInfo) {
            // 最后录入附加信息
            Input(*G, &((*G).arcs[i][j].info));
        }
    }
    
    // 从文件中读取数据时，最后其实应当判断一下是否读到了足够的信息
    return OK;
}

/*
 * 录入边/弧的相关附加信息
 */
static void Input(MGraph G, InfoType** info) {
    //录入边/弧的信息，本测试涉及到的边/弧默认无其他附加信息
}

/*
 * 查找
 *
 * 返回顶点u在图/网中的位置
 */
int LocateVex(MGraph G, VertexType u) {
    int i;
    
    for(i = 0; i < G.vexnum; i++) {
        if(G.vexs[i] == u) {
            return i;
        }
    }
    
    return -1;
}

/*
 * 取值
 *
 * 返回索引v处的顶点值
 */
VertexType GetVex(MGraph G, int v) {
    if(v < 0 || v >= G.vexnum) {
        return '\0';    // 指定的顶点不存在
    }
    
    return G.vexs[v];
}

/*
 * 首个邻接点
 *
 * 返回顶点v的首个邻接点
 */
int FirstAdjVex(MGraph G, VertexType v) {
    int kv, j;
    VRType adj;
    
    kv = LocateVex(G, v);
    if(kv == -1) {
        return -1;    // 指定的顶点不存在
    }
    
    // 确定一个非连通标记
    if(G.kind == DG || G.kind == UDG) {
        adj = 0;            // 图
    } else if(G.kind == DN || G.kind == UDN) {
        adj = INFINITE;     // 网
    } else {
        return -1;
    }
    
    // 从头开始查找
    for(j = 0; j < G.vexnum; j++) {
        // 找到与v直接连接的顶点
        if(G.arcs[kv][j].adj != adj) {
            return j;
        }
    }
    
    return -1;
}

/*
 * 下一个邻接点
 *
 * 返回顶点v的(相对于w的)下一个邻接点
 */
int NextAdjVex(MGraph G, VertexType v, VertexType w) {
    int kv, kw, j;
    VRType adj;
    
    kv = LocateVex(G, v);
    if(kv == -1) {
        return -1;    // 指定的顶点不存在
    }
    
    kw = LocateVex(G, w);
    if(kw == -1) {
        return -1;    // 指定的顶点不存在
    }
    
    // 确定一个非连通标记
    if(G.kind == DG || G.kind == UDG) {
        adj = 0;        // 图
    } else if(G.kind == DN || G.kind == UDN) {
        adj = INFINITE; // 网
    } else {
        return -1;
    }
    
    // 从顶点w后开始查找
    for(j = kw + 1; j < G.vexnum; j++) {
        // 找到与v直接连接的顶点
        if(G.arcs[kv][j].adj != adj) {
            return j;
        }
    }
    
    return -1;
}

/*
 * 以图形化形式输出当前结构
 *
 * 注：在网中，使用"-"来表示两顶点不直接连通
 */
void PrintGraph(MGraph G) {
    int i, j;
    
    if(G.vexnum == 0) {
        printf("空图，无需打印！\n");
        return;
    }
    
    printf("当前图/网包含 %2d 个顶点， %2d 条边/弧...\n", G.vexnum, G.arcnum);
    
    printf("  ");
    for(i = 0; i < G.vexnum; i++) {
        printf("  %c", G.vexs[i]);
    }
    printf("\n");
    
    for(i = 0; i < G.vexnum; i++) {
        printf("%c ", G.vexs[i]);
        
        for(j = 0; j < G.vexnum; j++) {
            if(((G.kind == DG || G.kind == UDG) && G.arcs[i][j].adj == 0) || ((G.kind == DN || G.kind == UDN) && G.arcs[i][j].adj == INFINITE)) {
                printf("  -");
            } else {
                printf("%3d", G.arcs[i][j].adj);
            }
        }
        
        printf("\n");
    }
}
