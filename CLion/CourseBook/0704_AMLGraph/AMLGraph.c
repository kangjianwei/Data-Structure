/*=====================
 * 图的邻接多重表存储表示
 ======================*/

#include "AMLGraph.h"

// 录入数据的源文件；fp为null时，说明需要从控制台录入
static FILE* fp = NULL;

/*
 * IncInfo指示该图的边上是否存在附加信息。
 * 如果其值不为0，则表示无附加信息，否则，表示存在附加信息。
 */
Boolean IncInfo = FALSE;

// 访问标志数组，记录访问过的顶点
static Boolean visited[MAX_VERTEX_NUM];

// 函数变量
static Status (* VisitFunc)(VertexType e);


/*
 * 创建
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
Status CreateGraph(AMLGraph* G, char* path[]) {
    int readFromConsole;    // 是否从控制台读取数据
    int kind;
    Status flag;
    
    printf("请输入图的类型(2-无向图 │ 3-无向网)：");
    scanf("%d", &kind);
    
    // 类型不合规(只接受无向的图/网)
    if(kind < 2 || kind > 3) {
        return ERROR;
    }
    
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
    
    // 随机创建无向图或无向网的一种
    switch((*G).kind) {
        case UDG:
            flag = CreateUDG(G);
            break;
        case UDN:
            flag = CreateUDN(G);
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
 * 构造无向图
 */
static Status CreateUDG(AMLGraph* G) {
    int i, k;
    int vexnum, arcnum;
    VertexType v1, v2;
    InfoType* info = NULL;
    
    (*G).vexnum = (*G).edgenum = 0;
    
    if(fp == NULL) {
        printf("请输入无向图的顶点数：");
        scanf("%d", &vexnum);
        printf("请输入无向图的边数：");
        scanf("%d", &arcnum);
        printf("该无向图的边上是否包含其他附加信息(0-不包含│1-包含)：");
        scanf("%d", &IncInfo);
    
        // 录入顶点集
        printf("请录入 %d 个顶点，不同顶点之间用空格隔开：", vexnum);
        for(i = 0; i < vexnum; i++) {
            // 跳过空白，寻找下一个"可读"符号
            skipBlank(stdin);
            scanf("%c", &((*G).adjmulist[i].data));
            (*G).adjmulist[i].firstedge = NULL;
            (*G).vexnum++;
        }
    } else {
        ReadData(fp, "%d", &vexnum); // 录入顶点数
        ReadData(fp, "%d", &arcnum); // 录入边数
        ReadData(fp, "%d", &IncInfo);// 判断边上是否包含附加信息
        
        // 录入顶点集
        for(i = 0; i < vexnum; i++) {
            // 跳过空白，寻找下一个"可读"符号
            skipBlank(fp);
            ReadData(fp, "%c", &((*G).adjmulist[i].data));
            (*G).adjmulist[i].firstedge = NULL;
            (*G).vexnum++;
        }
    }
    
    // 仅在控制台录入信息时输出此提示
    if(fp == NULL && arcnum != 0) {
        printf("请为无向图依次录入 %d 条边的信息，顶点之间用空格隔开：\n", arcnum);
    }
    
    // 录入边的信息
    for(k = 0; k < arcnum; k++) {
        if(fp == NULL) {
            printf("第 %2d 条边：", k + 1);
            skipBlank(stdin);   // 跳过空白，寻找下一个可读符号
            scanf("%c", &v1);
            skipBlank(stdin);   // 跳过空白，寻找下一个可读符号
            scanf("%c", &v2);
        } else {
            // 跳过空白，寻找下一个可读符号
            skipBlank(fp);
            ReadData(fp, "%c%c", &v1, &v2);
        }
        
        // 如果需要录入边的其他附加信息
        if(IncInfo) {
            // 最后录入附加信息
            Input(*G, &info);
        }
        
        // 插入边<v1, v2>
        InsertArc(G, v1, v2, info);
    }
    
    // 从文件中读取数据时，最后其实应当判断一下是否读到了足够的信息
    return OK;
}

/*
 * 构造无向网
 */
static Status CreateUDN(AMLGraph* G) {
    int i, k;
    int vexnum, arcnum;
    VertexType v1, v2;
    InfoType* info = NULL;
    
    (*G).vexnum = (*G).edgenum = 0;
    
    if(fp == NULL) {
        printf("请输入无向网的顶点数：");
        scanf("%d", &vexnum);
        printf("请输入无向网的边数：");
        scanf("%d", &arcnum);
        printf("该无向网的边上必须包含其他附加信息，因为此处的权值需要存储到附加信息中...\n");
        IncInfo = 1;
    
        // 录入顶点集
        printf("请录入 %d 个顶点，不同顶点之间用空格隔开：", vexnum);
        for(i = 0; i < vexnum; i++) {
            // 跳过空白，寻找下一个"可读"符号
            skipBlank(stdin);
            scanf("%c", &((*G).adjmulist[i].data));
            (*G).adjmulist[i].firstedge = NULL;
            (*G).vexnum++;
        }
    } else {
        ReadData(fp, "%d", &vexnum); // 录入顶点数
        ReadData(fp, "%d", &arcnum); // 录入边数
        ReadData(fp, "%d", &IncInfo);// 判断边上是否包含附加信息
        IncInfo = 1;    // 强制将权值录入到附加信息中
        
        // 录入顶点集
        for(i = 0; i < vexnum; i++) {
            // 跳过空白，寻找下一个"可读"符号
            skipBlank(fp);
            ReadData(fp, "%c", &((*G).adjmulist[i].data));
            (*G).adjmulist[i].firstedge = NULL;
            (*G).vexnum++;
        }
    }
    
    // 仅在控制台录入信息时输出此提示
    if(fp == NULL && arcnum != 0) {
        printf("请为无向网依次录入 %d 条边(带权值)的信息，顶点及权值之间用空格隔开：\n", arcnum);
    }
    
    // 录入边的信息
    for(k = 0; k < arcnum; k++) {
        if(fp == NULL) {
            printf("第 %2d 条边及其权值：", k + 1);
            skipBlank(stdin);   // 跳过空白，寻找下一个可读符号
            scanf("%c", &v1);
            skipBlank(stdin);   // 跳过空白，寻找下一个可读符号
            scanf("%c", &v2);
        } else {
            // 跳过空白，寻找下一个可读符号
            skipBlank(fp);
            ReadData(fp, "%c%c", &v1, &v2);
        }
    
        // 如果需要录入边的其他附加信息
        if(IncInfo) {
            // 最后录入附加信息(此处需要录入网的权值)
            Input(*G, &info);
        }
    
        // 插入边<v1, v2>
        InsertArc(G, v1, v2, info);
    }
    
    // 从文件中读取数据时，最后其实应当判断一下是否读到了足够的信息
    return OK;
}

/*
 * 录入边的相关附加信息
 */
static void Input(AMLGraph G, InfoType** info) {
    int weight;
    
    // 在"网"的情形下需要录入权值信息
    if(G.kind == UDN) {
        *info = (InfoType*) malloc(sizeof(InfoType));
        
        if(fp == NULL) {
            scanf("%d", &weight);
        } else {
            ReadData(fp, "%d", &weight);
        }
        
        (*info)->weight = weight;
    }
}

/*
 * 销毁
 *
 * 邻接表存储的图需要释放内存。
 */
Status DestroyGraph(AMLGraph* G) {
    int k, other;
    EBox* p, * r;
    
    // 逆序遍历
    for(k = G->vexnum-1; k >=0; k--) {
        p = NULL;
        r = G->adjmulist[k].firstedge;
        
        // 删除ivex处为k的边，保留jvex处为k的边
        while(r != NULL) {
            if(r->ivex == k) {
                other = r->jvex;
            } else if(r->jvex==k) {
                other = r->ivex;
            } else {
                // 不会至此
            }
    
            // 暂时保存这条边
            if(other<k) {
                p = r;
                
                if(r->ivex == k) {
                    r = r->ilink;
                } else if(r->jvex==k) {
                    r = r->jlink;
                } else {
                    // 不会至此
                }
                
                // 删除这条边
            } else {
                if(p==NULL) {
                    if(r->ivex == k) {
                        G->adjmulist[k].firstedge = r->ilink;
                    } else if(r->jvex==k) {
                        G->adjmulist[k].firstedge = r->jlink;
                    } else {
                        // 不会至此
                    }
                    
                    free(r);
                    r = G->adjmulist[k].firstedge;
                } else {
                    if(p->ivex==k) {
                        if(r->ivex == k) {
                            p->ilink = r->ilink;
                        } else if(r->jvex==k) {
                            p->ilink = r->jlink;
                        } else {
                            // 不会至此
                        }
    
                        free(r);
                        r = p->ilink;
                    } else if(p->jvex==k) {
                        if(r->ivex == k) {
                            p->jlink = r->ilink;
                        } else if(r->jvex==k) {
                            p->jlink = r->jlink;
                        } else {
                            // 不会至此
                        }
    
                        free(r);
                        r = p->jlink;
                    } else {
                        // 不会至此
                    }
                }
            }
        }
    }
    
    (*G).vexnum = 0;
    (*G).edgenum = 0;
    IncInfo = 0;
    
    return OK;
}

/*
 * 查找
 *
 * 返回顶点u在图/网中的位置
 */
int LocateVex(AMLGraph G, VertexType u) {
    int i;
    
    for(i = 0; i < G.vexnum; i++) {
        if(G.adjmulist[i].data == u) {
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
VertexType GetVex(AMLGraph G, int v) {
    if(v < 0 || v >= G.vexnum) {
        return '\0';    // 指定的顶点不存在
    }
    
    return G.adjmulist[v].data;
}

/*
 * 赋值
 *
 * 将顶点v赋值为value
 */
Status PutVex(AMLGraph* G, VertexType v, VertexType value) {
    int k;
    
    // 首先需要判断该顶点是否存在
    k = LocateVex((*G), v);
    if(k == -1) {
        return ERROR;    // 指定的顶点不存在
    }
    
    // 替换头结点
    (*G).adjmulist[k].data = value;
    
    /* 链表中的元素存储的是顶点的位置，所以无需遍历链表来替换目标值 */
    
    return OK;
}

/*
 * 首个邻接点
 *
 * 返回顶点v的首个邻接点
 */
int FirstAdjVex(AMLGraph G, VertexType v) {
    int k;
    EBox* r;
    
    // 首先需要判断该顶点是否存在
    k = LocateVex(G, v);
    if(k == -1) {
        return -1;    // 指定的顶点不存在
    }
    
    r = G.adjmulist[k].firstedge;
    if(r == NULL) {
        return -1;
    } else {
        if(r->ivex == k) {
            return r->jvex;
        } else if(r->jvex==k) {
            return r->ivex;
        } else {
            return -1;  // 不会至此
        }
    }
}

/*
 * 下一个邻接点
 *
 * 返回顶点v的(相对于w的)下一个邻接点
 */
int NextAdjVex(AMLGraph G, VertexType v, VertexType w) {
    int kv, kw;
    EBox* r;
    
    // 首先需要判断该顶点是否存在
    kv = LocateVex(G, v);
    if(kv == -1) {
        return -1;    // 指定的顶点不存在
    }
    
    // 首先需要判断该顶点是否存在
    kw = LocateVex(G, w);
    if(kw == -1) {
        return -1;    // 指定的顶点不存在
    }
    
    r = G.adjmulist[kv].firstedge;
    if(r == NULL) {
        return -1;    // 链表为空
    }
    
    // 在链表中查找w
    while(r != NULL) {
        if(r->ivex == kv && r->jvex < kw) {
            r = r->ilink;
        } else if(r->jvex == kv && r->ivex < kw) {
            r = r->jlink;
        } else {
            break;
        }
    }
    
    // 如果没找到w
    if(r == NULL) {
        return -1;
    }
    
    // 如果找到了w，但是w后面没有别的顶点，那么也无法返回邻接点
    if(r->ivex == kv && r->jvex == kw && r->ilink!=NULL) {
        r = r->ilink;
    } else if(r->jvex == kv && r->ivex == kw && r->jlink!=NULL) {
        r = r->jlink;
    } else {
        return -1;
    }
    
    // 向相邻的边中获取到相邻顶点
    if(r->ivex==kv) {
        return r->jvex;
    } else if(r->jvex==kv) {
        return r->ivex;
    } else {
        return -1;  // 不会至此
    }
}

/*
 * 插入顶点
 *
 * 将指定的顶点v追加到顶点集中，未建立该顶点与其他顶点的关系
 */
Status InsertVex(AMLGraph* G, VertexType v) {
    int k;
    
    // 顶点数过多
    if((*G).vexnum == MAX_VERTEX_NUM) {
        return ERROR;
    }
    
    // 首先需要判断该顶点是否存在
    k = LocateVex(*G, v);
    if(k >= 0) {
        return ERROR;    // 指定的顶点存在时，无需重复添加
    }
    
    G->adjmulist[(*G).vexnum].data = v;
    G->adjmulist[(*G).vexnum].firstedge = NULL;
    
    (*G).vexnum++;
    
    return OK;
}

/*
 * 删除顶点
 *
 * 从顶点集中删除指定的顶点v，注意需要更新相关的顶点关系
 */
Status DeleteVex(AMLGraph* G, VertexType v) {
    int i, k, other;
    EBox* p;
    EBox* pre, * r;
    
    // 首先需要判断该顶点是否存在
    k = LocateVex(*G, v);
    if(k == -1) {
        return ERROR;    // 指定的顶点不存在
    }
    
    while((p = G->adjmulist[k].firstedge) != NULL) {
        if(p->ivex == k) {
            G->adjmulist[k].firstedge = p->ilink;
            other = p->jvex;
        } else if(p->jvex == k) {
            G->adjmulist[k].firstedge = p->jlink;
            other = p->ivex;
        } else {
            // 没有其他可能
        }
        
        pre = NULL;
        r = G->adjmulist[other].firstedge;
        
        // 查找边<other, k>，肯定能找到
        while(r != NULL) {
            if(r->ivex == other && r->jvex < k) {
                pre = r;
                r = r->ilink;
            } else if(r->jvex == other && r->ivex < k) {
                pre = r;
                r = r->jlink;
            } else {
                break;
            }
        }
        
        if(r != NULL && r->ivex == other && r->jvex == k) {
            if(pre == NULL) {
                G->adjmulist[other].firstedge = r->ilink;
            } else {
                if(pre->ivex == other) {
                    pre->ilink = r->ilink;
                } else if(pre->jvex == other) {
                    pre->jlink = r->ilink;
                } else {
                    // 没有其他可能
                }
            }
        } else if(r != NULL && r->jvex == other && r->ivex == k) {
            if(pre == NULL) {
                G->adjmulist[other].firstedge = r->jlink;
            } else {
                if(pre->ivex == other) {
                    pre->ilink = r->jlink;
                } else if(pre->jvex == other) {
                    pre->jlink = r->jlink;
                } else {
                    // 没有其他可能
                }
            }
        } else {
            // 不会至此，因为肯定能找到
        }
        
        free(p);
        
        (*G).edgenum--;  // 边数减一
    }
    
    // 下标超过k的顶点，需要递减其下标
    for(i = k + 1; i < (*G).vexnum; i++) {
        r = G->adjmulist[i].firstedge;
    
        while(r!=NULL){
            if(r->ivex==i) {
                r->ivex--;
                r = r->ilink;
            } else if(r->jvex==i) {
                r->jvex--;
                r = r->jlink;
            } else {
                // 不会至此
            }
        }
    }
    
    // 顶点集前移
    for(i = k + 1; i < (*G).vexnum; i++) {
        G->adjmulist[i - 1] = G->adjmulist[i];
    }
    
    // 顶点数递减
    (*G).vexnum--;
    
    return OK;
}

/*
 * 构造一个边结点(仅限内部使用)
 */
static EBox* newEBoxPtr(VisitIf mark, int ivex, int jvex, EBox* ilink, EBox* jlink, InfoType* info) {
    EBox* p = (EBox*) malloc(sizeof(EBox));
    if(!p) {
        exit(OVERFLOW);
    }
    
    p->mark = mark;
    
    p->ivex = ivex;
    p->jvex = jvex;
    
    p->ilink = ilink;
    p->jlink = jlink;
    
    p->info = info;
    
    return p;
}

/*
 * 插入边<v, w>
 *
 * 当前图/网是无向的，且由于特殊的结构，使得插入一条边时只需要增加一对顶点关系，边的数量依然增一。
 * 对于图/网来说，可以在可变参数中列出边的附加信息。
 *
 * 注：此处接收的参数与MGraph有些不一样：网的附加信息中包含了各条边的权值。
 */
Status InsertArc(AMLGraph* G, VertexType v, VertexType w, ...) {
    int tail, head, k;
    EBox* p;
    EBox* pre;
    EBox* r;
    Boolean overlay = FALSE;   // 是否为覆盖添加
    InfoType* info = NULL;     // 边的附加信息
    va_list ap;
    
    tail = LocateVex(*G, v); // 获取顶点v在顶点集中的位置
    if(tail == -1) {
        return ERROR;  // 指定的顶点不存在
    }
    
    head = LocateVex(*G, w); // 获取顶点w在顶点集中的位置
    if(head == -1) {
        return ERROR;  // 指定的顶点不存在
    }
    
    // 拒绝环
    if(tail == head) {
        return ERROR;
    }
    
    // 如果边上存在附加信息
    if(IncInfo) {
        va_start(ap, w);                // 在w后查询首个可变参数
        info = va_arg(ap, InfoType*);   // 获取附加信息
        va_end(ap);
    }
    
    /* 接下来，需要查找合适的插入位置 */
    
    pre = NULL;
    r = G->adjmulist[tail].firstedge;
    
    while(r != NULL) {
        if(r->ivex == tail && r->jvex < head) {
            pre = r;
            r = r->ilink;
        } else if(r->jvex == tail && r->ivex < head) {
            pre = r;
            r = r->jlink;
        } else {
            break;
        }
    }
    
    if(r != NULL && r->ivex == tail && r->jvex == head) {
        r->info = info; // 复用该结点
        overlay = TRUE; // 发生了覆盖
    } else if(r != NULL && r->jvex == tail && r->ivex == head) {
        r->info = info; // 复用该结点
        overlay = TRUE; // 发生了覆盖
    } else {
        p = newEBoxPtr(unvisit, tail, head, r, NULL, info);
        
        if(pre == NULL) {
            G->adjmulist[tail].firstedge = p;
        } else {
            if(pre->ivex == tail) {
                pre->ilink = p;
            } else if(pre->jvex == tail) {
                pre->jlink = p;
            } else {
                // 没有其他可能
            }
        }
    }
    
    if(!overlay) {
        pre = NULL;
        r = G->adjmulist[head].firstedge;
        
        while(r != NULL) {
            if(r->ivex == head && r->jvex < tail) {
                pre = r;
                r = r->ilink;
            } else if(r->jvex == head && r->ivex < tail) {
                pre = r;
                r = r->jlink;
            } else {
                break;
            }
        }
        
        p->jlink = r;
        
        if(pre == NULL) {
            G->adjmulist[head].firstedge = p;
        } else {
            if(pre->ivex == head) {
                pre->ilink = p;
            } else if(pre->jvex == head) {
                pre->jlink = p;
            } else {
                // 没有其他可能
            }
        }
    }
    
    (*G).edgenum++;  // 边数增一
    
    return OK;
}

/*
 * 删除边<v, w>
 */
Status DeleteArc(AMLGraph* G, VertexType v, VertexType w) {
    int tail, head;
    EBox* r;
    EBox* pre;
    
    tail = LocateVex(*G, v);
    if(tail == -1) {
        return ERROR;    // 指定的顶点不存在
    }
    
    head = LocateVex(*G, w);
    if(head == -1) {
        return ERROR;    // 指定的顶点不存在
    }
    
    pre = NULL;
    r = G->adjmulist[tail].firstedge;
    
    while(r != NULL) {
        if(r->ivex == tail && r->jvex < head) {
            pre = r;
            r = r->ilink;
        } else if(r->jvex == tail && r->ivex < head) {
            pre = r;
            r = r->jlink;
        } else {
            break;
        }
    }
    
    if(r != NULL && r->ivex == tail && r->jvex == head) {
        if(pre == NULL) {
            G->adjmulist[tail].firstedge = r->ilink;
        } else {
            if(pre->ivex == tail) {
                pre->ilink = r->ilink;
            } else if(pre->jvex == tail) {
                pre->jlink = r->ilink;
            } else {
                // 没有其他可能
            }
        }
    } else if(r != NULL && r->jvex == tail && r->ivex == head) {
        if(pre == NULL) {
            G->adjmulist[tail].firstedge = r->jlink;
        } else {
            if(pre->ivex == tail) {
                pre->ilink = r->jlink;
            } else if(pre->jvex == tail) {
                pre->jlink = r->jlink;
            } else {
                // 没有其他可能
            }
        }
    } else {
        return ERROR;   // 未找到
    }
    
    
    pre = NULL;
    r = G->adjmulist[head].firstedge;
    
    while(r != NULL) {
        if(r->ivex == head && r->jvex < tail) {
            pre = r;
            r = r->ilink;
        } else if(r->jvex == head && r->ivex < tail) {
            pre = r;
            r = r->jlink;
        } else {
            break;
        }
    }
    
    if(r != NULL && r->ivex == head && r->jvex == tail) {
        if(pre == NULL) {
            G->adjmulist[head].firstedge = r->ilink;
        } else {
            if(pre->ivex == head) {
                pre->ilink = r->ilink;
            } else if(pre->jvex == head) {
                pre->jlink = r->ilink;
            } else {
                // 没有其他可能
            }
        }
    } else if(r != NULL && r->jvex == head && r->ivex == tail) {
        if(pre == NULL) {
            G->adjmulist[head].firstedge = r->jlink;
        } else {
            if(pre->ivex == head) {
                pre->ilink = r->jlink;
            } else if(pre->jvex == head) {
                pre->jlink = r->jlink;
            } else {
                // 没有其他可能
            }
        }
    } else {
        // 不会至此，因为前面找到了，此处肯定也能找到
    }
    
    free(r); // 释放内存
    
    (*G).edgenum--;  // 边数减一
    
    return OK;
}

/*
 * 深度优先遍历(此处借助递归实现)
 */
void DFSTraverse(AMLGraph G, Status(Visit)(VertexType)) {
    int v;
    
    // 使用全局变量VisitFunc，使得DFS不必设置函数指针参数
    VisitFunc = Visit;
    
    // 访问标志数组初始化
    for(v = 0; v < G.vexnum; v++) {
        visited[v] = FALSE;
    }
    
    // 此处需要遍历的原因是并不能保证所有顶点都连接在了一起
    for(v = 0; v < G.vexnum; v++) {
        if(!visited[v]) {
            DFS(G, v);  // 对尚未访问的顶点调用DFS
        }
    }
}

/*
 * 深度优先遍历核心函数
 */
static void DFS(AMLGraph G, int v) {
    int w;
    
    // 从第v个顶点出发递归地深度优先遍历图G
    visited[v] = TRUE;
    
    // 访问第v个顶点
    VisitFunc(G.adjmulist[v].data);
    
    for(w = FirstAdjVex(G, G.adjmulist[v].data);
        w >= 0;
        w = NextAdjVex(G, G.adjmulist[v].data, G.adjmulist[w].data)) {
        if(!visited[w]) {
            DFS(G, w);  // 对尚未访问的顶点调用DFS
        }
    }
}

/*
 * 广度优先遍历(此处借助队列实现)
 */
void BFSTraverse(AMLGraph G, Status(Visit)(VertexType)) {
    int v, w;
    LinkQueue Q;
    QElemType u;
    
    // 初始化为未访问
    for(v = 0; v < G.vexnum; v++) {
        visited[v] = FALSE;
    }
    
    // 置空辅助队列
    InitQueue(&Q);
    
    for(v = 0; v < G.vexnum; v++) {
        // 如果该顶点已访问过，则直接忽略
        if(visited[v]) {
            continue;
        }
        
        // 标记该顶点已访问
        visited[v] = TRUE;
        
        // 访问顶点
        Visit(G.adjmulist[v].data);
        
        EnQueue(&Q, v);
        
        while(!QueueEmpty(Q)) {
            DeQueue(&Q, &u);
            
            // 先集中访问顶点v的邻接顶点，随后再访问邻接顶点的邻接顶点
            for(w = FirstAdjVex(G, G.adjmulist[u].data);
                w >= 0;
                w = NextAdjVex(G, G.adjmulist[u].data, G.adjmulist[w].data)) {
                if(!visited[w]) {
                    visited[w] = TRUE;
                    Visit(G.adjmulist[w].data);
                    EnQueue(&Q, w);
                }
            }
        }
    }
}

/*
 * 以图形化形式输出当前结构
 */
void PrintGraph(AMLGraph G) {
    int i, cur, pos;
    EBox* p;
    
    if(G.vexnum == 0) {
        printf("空图，无需打印！\n");
        return;
    }
    
    printf("当前图/网包含 %2d 个顶点， %2d 条边...\n", G.vexnum, G.edgenum);
    
    for(i = 0; i < G.vexnum; i++) {
        printf("%c ===> ", G.adjmulist[i].data);
        
        cur = 0;
        p = G.adjmulist[i].firstedge;
        
        while(p != NULL) {
            if(p->ivex == i) {
                pos = p->jvex;
            } else {
                pos = p->ivex;
            }
            
            if(cur < pos) {
                if(IncInfo == 0) {
                    printf(" ");
                    
                    // 对于网，会从其附加信息中获取到权值
                } else {
                    printf("     ");
                }
            } else {
                if(IncInfo == 0) {
                    printf("%c", G.adjmulist[pos].data);
                    
                    // 对于网，会从其附加信息中获取到权值
                } else {
                    printf("%c[%2d]", G.adjmulist[pos].data, p->info->weight);
                }
                
                if(p->ivex == i) {
                    p = p->ilink;
                } else {
                    p = p->jlink;
                }
            }
            
            cur++;
            
            if(p != NULL) {
                printf("  ");
            }
        }
        
        printf("\n");
    }
}
