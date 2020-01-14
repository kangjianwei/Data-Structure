#include <stdio.h>
#include "MPList.h" //**▲05 数组和广义表**//

/*
 * 求m元多项式P中第一变元的偏导函数PD。
 *
 * 这里预设第一元为最外部的项
 */
Status Algo_5_28(MPList P, MPList* PD);

/*
 * 将指数exp乘到多项式P的原子结点的系数上
 */
static void HandleExp(MPList P, int exp);

/*
 * 多项式加法：R = P + Q
 */
Status Algo_5_29(MPList P, MPList Q, MPList* R);

/*
 * 对非空的对多项式P和Q相加，P和Q指向的是各元列表的头结点。
 */
static void AddMpList(MPList P, MPList Q, MPList* R);

/*
 * 视需求创建一个新结点。
 * 如果tp不为NULL，为原子结点添加一个头结点，否则，为子表结点添加头结点。
 * 变量v作为所创建的头结点的元标记
 */
static MPList VirtualNode(int v, MPList tp, MPList hp);


int main(int argc, char* argv[]) {
    MPList P, Q;
    MPList PD, QD;
    MPList R;
    char *p = "z((3,y((1,x((3, 1))))),(2,y((2,1))),(0,3))";
    char *q = "z((4,1),(3,y((1,x((3,-1))))),(2,x((1,1))),(0,y((1,1),(0,4))))";

    printf("创建三元多项式...\n");
    CreateMPList(&P, p, "zyx");
    printf("P = ");
    PrintMPList(P);
    CreateMPList(&Q, q, "zyx");
    printf("Q = ");
    PrintMPList(Q);
    
    // 求第一元的偏导数
    printf("P' = ");
    Algo_5_28(P, &PD);
    PrintMPList(PD);
    printf("Q' = ");
    Algo_5_28(Q, &QD);
    PrintMPList(QD);

    // 多项式加法
    printf("R = ");
    Algo_5_29(P, Q, &R);
    PrintMPList(R);
}


/*
 * 求m元多项式P中第一变元的偏导函数PD。
 *
 * 这里预设第一元为最外部的项
 */
Status Algo_5_28(MPList P, MPList* PD) {
    MPList r, rd, s;
    int count;
    
    if(P == NULL || PD == NULL) {
        return ERROR;
    }
    
    // 创建多项式
    *PD = (MPList) malloc(sizeof(MPNode));
    (*PD)->tag = List;
    (*PD)->exp = P->exp;
    (*PD)->tp = NULL;
    
    // 创建头结点
    (*PD)->Node.hp = (MPList) malloc(sizeof(MPNode));
    (*PD)->Node.hp->tag = P->Node.hp->tag;
    (*PD)->Node.hp->exp = P->Node.hp->exp;
    (*PD)->Node.hp->Node.hp = P->Node.hp->Node.hp;
    
    r = P->Node.hp;         // 指向P的头结点
    rd = (*PD)->Node.hp;    // 指向PD的头结点
    count = 0;
    
    // 遍历第一元的列表
    while(r->tp != NULL) {
        r = r->tp;
    
        // 如果没有遇到"常数"结点，或者，多项式P仅有一个"常数"结点
        if(r->exp!=0 || count==0) {
            rd->tp = (MPList) malloc(sizeof(MPNode));
            rd = rd->tp;
        }
        
        /*
         * 遇到"常数"结点，则求导后变为0
         * 注："常数"结点指数为0，其排在最后
         */
        if(r->exp == 0) {
            // 如果多项式P仅有一个"常数"结点
            if(count==0) {
                rd->tag = Atom;
                rd->exp = 0;
                rd->Node.coef = 0;
            }
    
            break;
        }
        
        rd->tag = r->tag;
        rd->exp = r->exp - 1;
    
        // 如果是原子结点，直接计算新系数
        if(r->tag==Atom) {
            rd->Node.coef = r->Node.coef * r->exp;    // 指数域系数相乘
    
            // 如果是子表结点，需要将指数乘到合适的位置
        } else {
            Copy(r->Node.hp, &(rd->Node.hp));
    
            // 指数为1时，是没必要乘的
            if(r->exp!=1) {
                // 将指数exp乘到多项式P的原子结点的系数上
                HandleExp(rd->Node.hp, r->exp);
            }
        }
        
        count++;
    }
    
    rd->tp = NULL;
    
    return OK;
}

/*
 * 将指数exp乘到多项式P的原子结点的系数上
 */
static void HandleExp(MPList P, int exp) {
    MPList r;
    
    if(P == NULL) {
        return;
    }
    
    for(r = P->tp; r != NULL; r = r->tp) {
        if(r->tag == Atom) {
            r->Node.coef *= exp;
        } else {
            HandleExp(r->Node.hp, exp);
        }
    }
}

/*
 * 多项式加法：R = P + Q
 */
Status Algo_5_29(MPList P, MPList Q, MPList* R) {
    MPList r;
    
    // 要求两个多项式的元相等
    if(P == NULL || Q == NULL || R==NULL || P->exp != Q->exp) {
        return ERROR;
    }
    
    // 创建多项式
    *R = (MPList) malloc(sizeof(MPNode));
    if(*R == NULL) {
        exit(OVERFLOW);
    }
    (*R)->tag = List;
    (*R)->exp = P->exp;     // 多项式的元数量不变
    (*R)->tp = NULL;
    
    AddMpList(P->Node.hp, Q->Node.hp, &r);
    
    if(r->tp == NULL) {
        r->tp = (MPList) malloc(sizeof(MPNode));
        r->tp->tag = Atom;
        r->tp->exp = 0;
        r->tp->Node.coef = 0.0f;
        r->tp->tp = NULL;
    }
    
    (*R)->Node.hp = r;
    
    return OK;
}

/*
 * 对非空的对多项式P和Q相加，P和Q指向的是各元列表的头结点。
 */
static void AddMpList(MPList P, MPList Q, MPList* R) {
    MPList p, q, h, r;
    MPList t;
    MPList tp;
    float sum;
    int a, b;
    int v;
    
    // 如果不是同一个元
    if(P->exp!=Q->exp) {
        
        a = (int)(strchr(Var, P->exp)-Var);
        b = (int)(strchr(Var, Q->exp)-Var);
        
        if(a<b) {
            Q = VirtualNode(P->exp, NULL, Q);
            v = P->exp;
        }
        
        if(a>b) {
            P = VirtualNode(Q->exp, NULL, P);
            v = Q->exp;
        }
    } else {
        v = P->exp;
    }
    
    // 创建头结点
    *R = (MPList) malloc(sizeof(MPNode));
    (*R)->tag = List;
    (*R)->exp = v;
    (*R)->Node.hp =NULL;
    
    h = *R;
    
    p = P->tp;
    q = Q->tp;
    
    while(p!=NULL && q!=NULL){
        if(p->exp>q->exp) {
            tp = p->tp;
            p->tp = NULL;
            Copy(p, &(h->tp));
            p->tp = tp;
            p = p->tp;
            h = h->tp;
        } else if(p->exp<q->exp) {
            tp = q->tp;
            q->tp = NULL;
            Copy(q, &(h->tp));
            q->tp = tp;
            q = q->tp;
            h = h->tp;
            
            // 指数相同
        } else {
            sum = 0.0f;     // 初始化系数和，不一定用得上
            r = NULL;
            
            if(p->tag==Atom && q->tag==List) {
                t = VirtualNode(q->Node.hp->exp, p, NULL);
                tp = p->tp;
                p->tp = NULL;
                AddMpList(t, q->Node.hp, &r);
                p->tp = tp;
            } else if(p->tag==List && q->tag==Atom) {
                t = VirtualNode(p->Node.hp->exp, q, NULL);
                tp = q->tp;
                q->tp = NULL;
                AddMpList(p->Node.hp, t, &r);
                q->tp = tp;
                
                // 都是子表
            } else if(p->tag==List && q->tag==List) {
                AddMpList(p->Node.hp, q->Node.hp, &r);
                
                // 都是原子的话，可以直接相加
            } else if(p->tag==Atom && q->tag==Atom) {
                sum = p->Node.coef + q->Node.coef;
            }
    
            if(sum!=0.0f || (r!=NULL && r->tp!=NULL)) {
                h->tp = (MPList) malloc(sizeof(MPNode));
                h = h->tp;
                h->exp = p->exp;
                
                if(sum!=0.0f) {
                    h->tag = Atom;
                    h->Node.coef = sum;
                } else {
                    h->tag = List;
                    h->Node.hp = r;
                }
            }
            
            p = p->tp;
            q = q->tp;
        }
    }
    
    h->tp = NULL;
    
    if(p!=NULL){
        Copy(p, &(h->tp));
    }
    
    if(q!=NULL){
        Copy(q, &(h->tp));
    }
}

/*
 * 视需求创建一个新结点。
 * 如果tp不为NULL，为原子结点添加一个头结点，否则，为子表结点添加头结点。
 * 变量v作为所创建的头结点的元标记
 */
static MPList VirtualNode(int v, MPList tp, MPList hp){
    MPList P;
    
    P = (MPList) malloc(sizeof(MPNode));
    P->tag = List;
    P->exp = v;
    P->Node.hp = NULL;
    
    if(tp!=NULL) {
        P->tp = tp;
    } else {
        P->tp = (MPList) malloc(sizeof(MPNode));
        P->tp->exp = 0;
        P->tp->tag = List;
        P->tp->Node.hp = hp;
        P->tp->tp = NULL;
    }
    
    return P;
}
