/*============================
 * ������ͷβ����洢��ʾ
 *
 * �����㷨: 5.5��5.6��5.7��5.8
 =============================*/

#include "GList-HT.h"                        //**��05 ����͹����**//

/*
 * ��ʼ��
 *
 * ��ʼ���յĹ��������Ϊ0�����Ϊ1��
 *
 *��ע��
 * ��Ҫ��ÿһ��ȥ�����ſ���
 */
Status InitGList(GList* L) {
    if(L == NULL) {
        return ERROR;
    }
    
    *L = NULL;
    
    return OK;
}

/*
 * ���������������� �㷨5.7 ����������������
 *
 * ����
 *
 * ���ַ���S���������L��
 */
Status CreateGList(GList* L, SString S) {
    SString emp;        // ����չ������ַ���
    SString hsub, sub;
    GList p, q;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // �����ַ���S�еĿհף����������ɴ�ӡ�ַ�������ո�
    ClearBlank(S);
    
    if(StrEmpty(S)) {
        return ERROR;
    }
    
    StrAssign(emp, "()");
    
    /*
     * ������봮Ϊ()���������Ҫ�����յĹ����
     *
     *��ע��
     * �̲�����Ĵ�����������ġ�
     * StrCompare�ķ���ֵָʾ���������ַ����Ĵ�С��������ָʾ�����ַ����Ƿ���ȡ�
     * ���������S��()��ȣ�����ֵӦ����0��
     */
    if(!StrCompare(S, emp)) {
        *L = NULL;
    } else {
        *L = (GList) malloc(sizeof(GLNode));
        if(*L == NULL) {
            exit(OVERFLOW);
        }
        
        // ����ԭ��
        if(StrLength(S) == 1) {
            (*L)->tag = Atom;
            (*L)->Node.atom = S[1];
        } else {
            (*L)->tag = List;
            
            p = *L;
            
            // ȥ�����������
            SubString(sub, S, 2, StrLength(S) - 2);
            
            // �ظ���n���ӱ�
            do {
                // ��sub�з������ͷ��hsub��������ɺ�subҲ�ᷢ���仯
                sever(hsub, sub);
                
                // �ݹ鴴�������
                CreateGList(&(p->Node.ptr.hp), hsub);
                
                q = p;
                
                // �����β��Ϊ�գ���Ҫ���������β
                if(!StrEmpty(sub)) {
                    p = (GList) malloc(sizeof(GLNode));
                    if(p == NULL) {
                        exit(OVERFLOW);
                    }
                    
                    p->tag = List;
                    
                    q->Node.ptr.tp = p;
                }
            } while(!StrEmpty(sub));
            
            q->Node.ptr.tp = NULL;
        }
    }
    
    return OK;
}

/*
 * ����
 *
 * �ͷŹ������ռ�ڴ档
 */
Status DestroyGList(GList* L) {
    GList head, tail;
    
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    // ɾ��ԭ�ӽ��
    if((*L)->tag == Atom) {
        free(*L);
        *L = NULL;
        
        // ɾ���ӱ���
    } else {
        head = (*L)->Node.ptr.hp;
        tail = (*L)->Node.ptr.tp;
        free(*L);
        *L = NULL;
        DestroyGList(&head);
        DestroyGList(&tail);
    }
    
    return OK;
}

/*
 * ���������������� �㷨5.6 ����������������
 *
 * ����
 *
 * �ɹ����L���Ƶõ������T��
 */
Status CopyGList(GList* T, GList L) {
    if(T == NULL) {
        return ERROR;
    }
    
    if(L == NULL) {
        *T = NULL;
    } else {
        // �½��������
        *T = (GList) malloc(sizeof(GLNode));
        if(*T == NULL) {
            exit(OVERFLOW);
        }
        
        (*T)->tag = L->tag;
        
        // ���Ƶ�ԭ��
        if(L->tag == Atom) {
            (*T)->Node.atom = L->Node.atom;
            
            // ���Ʊ�ͷ�ͱ�β
        } else {
            CopyGList(&((*T)->Node.ptr.hp), L->Node.ptr.hp);
            CopyGList(&((*T)->Node.ptr.tp), L->Node.ptr.tp);
        }
    }
    
    return OK;
}

/*
 * ����
 *
 * ���ع����ĳ��ȡ�
 */
int GListLength(GList L) {
    int count;
    
    for(count = 0; L != NULL; count++, L = L->Node.ptr.tp) {
    }
    
    return count;
}

/*
 * ���������������� �㷨5.5 ����������������
 *
 * ���
 *
 * ���ع��������
 */
int GListDepth(GList L) {
    int max, deep;
    GList p;
    
    // �ձ����Ϊ1
    if(L == NULL) {
        return 1;
    }
    
    // ԭ�����Ϊ0
    if(L->tag == Atom) {
        return 0;
    }
    
    // �ݹ����ӱ����
    for(max = 0, p = L; p != NULL; p = p->Node.ptr.tp) {
        deep = GListDepth(p->Node.ptr.hp);
        if(deep > max) {
            max = deep;
        }
    }
    
    // �ǿձ������Ǹ���Ԫ�������ȼ�һ
    return max + 1;
}

/*
 * �п�
 *
 * �жϹ�����Ƿ�Ϊ�ա�
 */
Status GListEmpty(GList L) {
    return L == NULL ? TRUE : FALSE;
}

/*
 * ��ͷ
 */
GList GetHead(GList L) {
    GList p;
    
    // �ձ��ޱ�ͷ�����ﲻ�ܷ���NULL����Ȼ�ֲ�����ʧ���˻��Ƿ����˿ձ�
    if(L == NULL) {
        exit(ERROR);
    }
    
    CopyGList(&p, L->Node.ptr.hp);
    
    return p;
}

/*
 * ��β
 */
GList GetTail(GList L) {
    GList p;
    
    // �ձ��ޱ�β�����ﲻ�ܷ���NULL����Ȼ�ֲ�����ʧ���˻��Ƿ����˿ձ�
    if(L == NULL) {
        exit(ERROR);
    }
    
    CopyGList(&p, L->Node.ptr.tp);
    
    return p;
}

/*
 * ����
 *
 * ��Ԫ��e����Ϊ�����L�ĵ�һ��Ԫ�ء�
 */
Status InsertFirst(GList* L, GList e) {
    GList g;
    
    if(L == NULL) {
        return ERROR;
    }
    
    g = (GList) malloc(sizeof(GLNode));
    if(g == NULL) {
        exit(OVERFLOW);
    }
    
    g->tag = List;
    g->Node.ptr.hp = e;
    g->Node.ptr.tp = *L;
    *L = g;
    
    return OK;
}

/*
 * ɾ��
 *
 * �������L�ĵ�һ��Ԫ��ɾ��������e���ء�
 */
Status DeleteFirst(GList* L, GList* e) {
    GList p;
    
    // �ձ��޷�ɾ��
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    p = *L;
    *L = (*L)->Node.ptr.tp;
    
    CopyGList(e, p->Node.ptr.hp);
    
    free(p);
    
    return OK;
}

/*
 * ����
 *
 * ��visit�������ʹ����L��
 */
void Traverse(GList L, void(Visit)(AtomType)) {
    
    if(L == NULL) {
        return;
    }
    
    if(L->tag == Atom) {
        Visit(L->Node.atom);
    } else {
        Traverse(L->Node.ptr.hp, Visit);
        Traverse(L->Node.ptr.tp, Visit);
    }
    
}

/*
 * ͼ�λ����
 *
 * ��������������L��
 */
void PrintGraph(GList L) {
    Print(L, Head);
    printf("\n");
}

/*
 * ͼ�λ�������ڲ�ʵ�֣�mark��ͼ�λ������ǡ�
 */
static void Print(GList L, Mark mark) {
    // LΪ��
    if(L == NULL) {
        if(mark == Head) {
            printf("(");
        }
        
        printf(")");
        
        // L��Ϊ��ʱ
    } else {
        // ����ԭ�ӽ�㣬���ԭ��
        if(L->tag == Atom) {
            printf("%c", L->Node.atom);
            
            // �����ӱ��㣬Ҫ�Ա�ͷ����β�ֱ�����
        } else {
            if(mark == Head) {
                printf("(");
            } else {
                printf(",");
            }
            
            Print(L->Node.ptr.hp, Head);
            Print(L->Node.ptr.tp, Tail);
        }
    }
}

/*
 * ���������������� �㷨5.8 ����������������
 *
 * ���ǿմ�str�ָ�������֣�hsubΪ��һ��','֮ǰ���Ӵ���strΪ��һ��','֮����Ӵ���
 *
 *��ע��
 * 1.��������ַ���str������ȷ�������޿հ׷��ţ���str���Ѿ���ȥ��������š���
 * 2.������ɺ�strҲ�ᷢ���仯
 */
static void sever(SString hstr, SString str) {
    int i, k, n;
    SString ch;
    
    n = StrLength(str);
    
    i = 0;  // �����ַ���ʱ���α�
    k = 0;  // ���������δ�����������
    
    do {
        ++i;
        
        // ��ȡstr��һ���ַ�
        SubString(ch, str, i, 1);
        
        if(ch[1] == '(') {
            ++k;
        }
        
        if(ch[1] == ')') {
            --k;
        }
    } while(i < n && (ch[1] != ',' || k != 0));
    
    // ������ڶ���������
    if(i < n) {
        SubString(hstr, str, 1, i - 1);
        SubString(str, str, i + 1, n - i);
        
        // ֻ��һ���������
    } else {
        StrCopy(hstr, str);
        ClearString(str);
    }
}
