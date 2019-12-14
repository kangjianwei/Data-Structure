#include <stdio.h>
#include "MPList.h" //**��05 ����͹����**//

/*
 * ��mԪ����ʽP�е�һ��Ԫ��ƫ������PD��
 *
 * ����Ԥ���һԪΪ���ⲿ����
 */
Status Algo_5_28(MPList P, MPList* PD);

/*
 * ��ָ��exp�˵�����ʽP��ԭ�ӽ���ϵ����
 */
static void HandleExp(MPList P, int exp);

/*
 * ����ʽ�ӷ���R = P + Q
 */
Status Algo_5_29(MPList P, MPList Q, MPList* R);

/*
 * �ԷǿյĶԶ���ʽP��Q��ӣ�P��Qָ����Ǹ�Ԫ�б��ͷ��㡣
 */
static void AddMpList(MPList P, MPList Q, MPList* R);

/*
 * �����󴴽�һ���½�㡣
 * ���tp��ΪNULL��Ϊԭ�ӽ�����һ��ͷ��㣬����Ϊ�ӱ������ͷ��㡣
 * ����v��Ϊ��������ͷ����Ԫ���
 */
static MPList VirtualNode(int v, MPList tp, MPList hp);


int main(int argc, char* argv[]) {
    MPList P, Q;
    MPList PD, QD;
    MPList R;
    char *p = "z((3,y((1,x((3, 1))))),(2,y((2,1))),(0,3))";
    char *q = "z((4,1),(3,y((1,x((3,-1))))),(2,x((1,1))),(0,y((1,1),(0,4))))";

    printf("������Ԫ����ʽ...\n");
    CreateMPList(&P, p, "zyx");
    printf("P = ");
    PrintGraph(P);
    CreateMPList(&Q, q, "zyx");
    printf("Q = ");
    PrintGraph(Q);
    
    // ���һԪ��ƫ����
    printf("P' = ");
    Algo_5_28(P, &PD);
    PrintGraph(PD);
    printf("Q' = ");
    Algo_5_28(Q, &QD);
    PrintGraph(QD);

    // ����ʽ�ӷ�
    printf("R = ");
    Algo_5_29(P, Q, &R);
    PrintGraph(R);
}


/*
 * ��mԪ����ʽP�е�һ��Ԫ��ƫ������PD��
 *
 * ����Ԥ���һԪΪ���ⲿ����
 */
Status Algo_5_28(MPList P, MPList* PD) {
    MPList r, rd, s;
    int count;
    
    if(P == NULL || PD == NULL) {
        return ERROR;
    }
    
    // ��������ʽ
    *PD = (MPList) malloc(sizeof(MPNode));
    (*PD)->tag = List;
    (*PD)->exp = P->exp;
    (*PD)->tp = NULL;
    
    // ����ͷ���
    (*PD)->Node.hp = (MPList) malloc(sizeof(MPNode));
    (*PD)->Node.hp->tag = P->Node.hp->tag;
    (*PD)->Node.hp->exp = P->Node.hp->exp;
    (*PD)->Node.hp->Node.hp = P->Node.hp->Node.hp;
    
    r = P->Node.hp;         // ָ��P��ͷ���
    rd = (*PD)->Node.hp;    // ָ��PD��ͷ���
    count = 0;
    
    // ������һԪ���б�
    while(r->tp != NULL) {
        r = r->tp;
    
        // ���û������"����"��㣬���ߣ�����ʽP����һ��"����"���
        if(r->exp!=0 || count==0) {
            rd->tp = (MPList) malloc(sizeof(MPNode));
            rd = rd->tp;
        }
        
        /*
         * ����"����"��㣬���󵼺��Ϊ0
         * ע��"����"���ָ��Ϊ0�����������
         */
        if(r->exp == 0) {
            // �������ʽP����һ��"����"���
            if(count==0) {
                rd->tag = Atom;
                rd->exp = 0;
                rd->Node.coef = 0;
            }
    
            break;
        }
        
        rd->tag = r->tag;
        rd->exp = r->exp - 1;
    
        // �����ԭ�ӽ�㣬ֱ�Ӽ�����ϵ��
        if(r->tag==Atom) {
            rd->Node.coef = r->Node.coef * r->exp;    // ָ����ϵ�����
    
            // ������ӱ��㣬��Ҫ��ָ���˵����ʵ�λ��
        } else {
            Copy(r->Node.hp, &(rd->Node.hp));
    
            // ָ��Ϊ1ʱ����û��Ҫ�˵�
            if(r->exp!=1) {
                // ��ָ��exp�˵�����ʽP��ԭ�ӽ���ϵ����
                HandleExp(rd->Node.hp, r->exp);
            }
        }
        
        count++;
    }
    
    rd->tp = NULL;
    
    return OK;
}

/*
 * ��ָ��exp�˵�����ʽP��ԭ�ӽ���ϵ����
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
 * ����ʽ�ӷ���R = P + Q
 */
Status Algo_5_29(MPList P, MPList Q, MPList* R) {
    MPList r;
    
    // Ҫ����������ʽ��Ԫ���
    if(P == NULL || Q == NULL || R==NULL || P->exp != Q->exp) {
        return ERROR;
    }
    
    // ��������ʽ
    *R = (MPList) malloc(sizeof(MPNode));
    if(*R == NULL) {
        exit(OVERFLOW);
    }
    (*R)->tag = List;
    (*R)->exp = P->exp;     // ����ʽ��Ԫ��������
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
 * �ԷǿյĶԶ���ʽP��Q��ӣ�P��Qָ����Ǹ�Ԫ�б��ͷ��㡣
 */
static void AddMpList(MPList P, MPList Q, MPList* R) {
    MPList p, q, h, r;
    MPList t;
    MPList tp;
    float sum;
    int a, b;
    int v;
    
    // �������ͬһ��Ԫ
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
    
    // ����ͷ���
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
            
            // ָ����ͬ
        } else {
            sum = 0.0f;     // ��ʼ��ϵ���ͣ���һ���õ���
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
                
                // �����ӱ�
            } else if(p->tag==List && q->tag==List) {
                AddMpList(p->Node.hp, q->Node.hp, &r);
                
                // ����ԭ�ӵĻ�������ֱ�����
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
 * �����󴴽�һ���½�㡣
 * ���tp��ΪNULL��Ϊԭ�ӽ�����һ��ͷ��㣬����Ϊ�ӱ������ͷ��㡣
 * ����v��Ϊ��������ͷ����Ԫ���
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
