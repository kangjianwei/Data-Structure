/*===========================
 * ��������չ��������洢��ʾ
 ============================*/

#include "GList-E.h"            //**��05 ����͹����**//

/*
 * ��ʼ��
 *
 * ��ʼ���յĹ��������Ϊ0�����Ϊ1��
 *
 *��ע��
 * ��Ҫ��ÿһ��������ſ���
 */
Status InitGList(GList* L) {
    if(L == NULL) {
        return ERROR;
    }
    
    *L = (GList) malloc(sizeof(GLNode));
    if(!*L) {
        exit(OVERFLOW);
    }
    
    (*L)->tag = List;
    (*L)->Node.hp = NULL;
    (*L)->tp = NULL;
    
    return OK;
}

/*
 * ����
 *
 * ���ַ���S���������L��
 */
Status CreateGList(GList* L, SString S) {
    SString emp, hsub, sub, tmp;
    
    if(L == NULL) {
        return ERROR;
    }
    
    // �����ַ���S�еĿհף����������ɴ�ӡ�ַ�������ո�
    ClearBlank(S);
    
    if(StrEmpty(S)) {
        return ERROR;
    }
    
    // ������Ϊ�˲��ƻ�S
    StrCopy(sub, S);
    
    /*
     * ����ִ�е���ʱ����������������
     * �ٴ�ִ�е���ʱ���Ѿ���ȥ���������
     */
    sever(hsub, sub);
    
    *L = (GList) malloc(sizeof(GLNode));
    if(*L == NULL) {
        exit(OVERFLOW);
    }
    
    StrAssign(emp, "()");
    
    if(!StrCompare(hsub, emp)) {
        (*L)->tag = List;
        (*L)->Node.hp = NULL;
    } else {
        if(StrLength(hsub) == 1) {
            (*L)->tag = Atom;
            (*L)->Node.atom = hsub[1];
        } else {
            (*L)->tag = List;
            
            SubString(tmp, hsub, 2, StrLength(hsub) - 2);
            
            CreateGList(&((*L)->Node.hp), tmp);
        }
    }
    
    // ��������ڶ�β�����˳�����ݹ�
    if(StrEmpty(sub)) {
        (*L)->tp = NULL;
    } else {
        // �����ݹ����β
        CreateGList(&((*L)->tp), sub);
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
    
    // �����ӱ���
    if((*L)->tag == List) {
        head = (*L)->Node.hp;  // ��ͷ
        tail = (*L)->tp;       // ��β
        
        free(*L);
        *L = NULL;
        
        // �ݹ鴦���ͷ
        if(head != NULL) {
            DestroyGList(&head);
        }
        
        // �ݹ鴦���β
        if(tail != NULL) {
            DestroyGList(&tail);
        }
        
        // ����ԭ�ӽ��
    } else {
        tail = (*L)->tp;    // ��β
        
        free(*L);
        *L = NULL;
        
        if(tail != NULL) {
            DestroyGList(&tail);
        }
    }
    
    return OK;
}

/*
 * ����
 *
 * �ɹ����L���Ƶõ������T��
 */
Status CopyGList(GList* T, GList L) {
    
    if(L == NULL) {
        return ERROR;
    }
    
    *T = (GList) malloc(sizeof(GLNode));
    if(*T == NULL) {
        exit(OVERFLOW);
    }
    
    // ����ԭ��
    if(L->tag == Atom) {
        (*T)->tag = Atom;
        (*T)->Node.atom = L->Node.atom;
        
        // �����ӱ�
    } else {
        (*T)->tag = List;
        
        // ���Ʊ�ͷ
        if(L->Node.hp != NULL) {
            CopyGList(&((*T)->Node.hp), L->Node.hp);
        } else {
            (*T)->Node.hp = NULL;
        }
    }
    
    // ���Ʊ�β
    if(L->tp != NULL) {
        CopyGList(&((*T)->tp), L->tp);
    } else {
        (*T)->tp = NULL;
    }
    
    return OK;
}

/*
 * ����
 *
 * ���ع����ĳ��ȡ�
 */
int GListLength(GList L) {
    int count = 0;
    GList p;
    
    // ���������
    if(L == NULL) {
        return -1;
    }
    
    p = L->Node.hp;
    
    while(p != NULL) {
        ++count;
        p = p->tp;
    }
    
    return count;
}

/*
 * ���
 *
 * ���ع��������
 */
int GListDepth(GList L) {
    int max, deep;
    GList p;
    
    max = 0;
    
    // ���������
    if(L == NULL) {
        return -1;
    }
    
    // �ձ����Ϊ1
    if(L->tag == List && !L->Node.hp) {
        return 1;
    }
    
    // ԭ�����Ϊ0
    if(L->tag == Atom) {
        return 0;
    }
    
    // �ݹ����ӱ����
    for(p = L->Node.hp; p != NULL; p = p->tp) {
        // ����pΪͷָ����ӱ����
        deep = GListDepth(p);
        if(deep > max) {
            max = deep;
        }
    }
    
    return max + 1;
}

/*
 * �п�
 *
 * �жϹ�����Ƿ�Ϊ�ա�
 */
Status GListEmpty(GList L) {
    // ���������
    if(L == NULL) {
        return ERROR;
    }
    
    if(L->tag == List && L->Node.hp == NULL && L->tp == NULL) {
        return TRUE;
    } else {
        return ERROR;
    }
}

/*
 * ��ͷ
 */
GList GetHead(GList L) {
    GList p, q;
    
    // ��������ڻ�����Ϊ�ձ��޷���ȡ��ͷ
    if(L == NULL || L->Node.hp == NULL) {
        return NULL;
    }
    
    q = L->Node.hp->tp;         // ��ʱ����L�ı�β��Ϣ
    L->Node.hp->tp = NULL;      // ��ȥL�ı�β����
    
    CopyGList(&p, L->Node.hp);  // ���Ʊ�ͷ��Ϣ�������α�β��
    
    L->Node.hp->tp = q;         // �ָ�L�ı�β��Ϣ
    
    return p;
}

/*
 * ��β
 */
GList GetTail(GList L) {
    GList p, q;
    
    // ��������ڻ�����Ϊ�ձ��޷���ȡ��β
    if(L == NULL || L->Node.hp == NULL) {
        return NULL;
    }
    
    q = L->Node.hp;         // ��ʱ����L�ı�ͷ��Ϣ
    L->Node.hp = q->tp;     // ժ��L�ı�ͷ����
    
    CopyGList(&p, L);       // ���Ʊ�β��Ϣ�������α�ͷ��
    
    q->tp = L->Node.hp;     // �ָ�L�ı�ͷ��Ϣ
    L->Node.hp = q;
    
    return p;
}

/*
 * ����
 *
 * ��Ԫ��e����Ϊ�����L�ĵ�һ��Ԫ�ء�
 */
Status InsertFirst(GList* L, GList e) {
    
    // ���������
    if(L == NULL || *L == NULL) {
        return ERROR;
    }
    
    if(e == NULL) {
        return ERROR;
    }
    
    e->tp = (*L)->Node.hp;
    (*L)->Node.hp = e;
    
    return OK;
}

/*
 * ɾ��
 *
 * �������L�ĵ�һ��Ԫ��ɾ��������e���ء�
 */
Status DeleteFirst(GList* L, GList* e) {
    GList p;
    
    // ��������ڻ�����Ϊ�ձ����޷�ɾ����ͷ
    if(*L == NULL || (*L)->Node.hp == NULL) {
        return ERROR;
    }
    
    p = (*L)->Node.hp;
    (*L)->Node.hp = p->tp;
    p->tp = NULL;
    
    *e = p;
    
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
    
    if(L->tag == List) {
        Traverse(L->Node.hp, Visit);
    } else {
        Visit(L->Node.atom);
    }
    
    Traverse(L->tp, Visit);
}

/*
 * ͼ�λ����
 *
 * ��������������L��
 */
void PrintGraph(GList L) {
    Print(L);
    printf("\n");
}

/*
 * ͼ�λ�������ڲ�ʵ�֡�
 */
static void Print(GList L) {
    if(L == NULL) {
        return;
    }
    
    // �������
    if(L->tag == List) {
        printf("(");
        
        if(L->Node.hp) {
            Print(L->Node.hp);
        }
        
        if(L->tp) {
            printf("),");
            Print(L->tp);
        } else {
            printf(")");
        }
        
        // ����ԭ�ӽ��
    } else {
        printf("%c", L->Node.atom);
        if(L->tp) {
            printf(",");
            Print(L->tp);
        }
    }
}

/*
 * ���ǿմ�str�ָ�������֣�hsubΪ��һ��','֮ǰ���Ӵ���strΪ��һ��','֮����Ӵ���
 *
 *��ע��
 * 1.��������ַ���str������ȷ�������޿հ׷��ţ�
 *   ��str�������ſ�����ȥ��Ҳ����δ��ȥ��
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
    
    if(i < n) {
        SubString(hstr, str, 1, i - 1);
        SubString(str, str, i + 1, n - i);
    } else {
        StrCopy(hstr, str);
        ClearString(str);
    }
}
