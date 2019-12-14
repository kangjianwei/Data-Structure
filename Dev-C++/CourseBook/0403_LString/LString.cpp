/*=============================
 * ���Ŀ�������洢��ʾ����������
 ==============================*/

#include "LString.h"    //**��04 ��**//

/*
 * ��ʼ��
 *
 * ����һ��ֵΪchars�Ĵ�T��
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrAssign(LString* T, const char* chars) {
    int len;        // chars�ĳ���
    int i, count;   // �������������ַ���chars���α�
    int m;          // �ܿ���
    int n;          // �������δ�����Ŀ飬�洢�ÿ��е���ЧԪ������
    Chunk* r;
    
    // ��chars�ĳ���
    len = (int) strlen(chars);
    
    // û����ЧԪ��
    if(len == 0) {
        (*T).head = NULL;
        (*T).tail = NULL;
        (*T).curlen = 0;
        
        return OK;
    }
    
    m = len / CHUNKSIZE;    // �ȼ�����Ҫ�����Ŀ�
    n = len % CHUNKSIZE;    // �������δ�����Ŀ飬����ÿ���������ЧԪ������
    if(n != 0) {
        m++;                // �����ܿ���
    }
    
    // 1.�����������Ľṹ
    for(i = 1; i <= m; i++) {
        // �����¿�
        r = (Chunk*) malloc(sizeof(Chunk));
        if(r == NULL) {
            exit(OVERFLOW);
        }
        r->next = NULL;
        
        // ��һ����
        if(i == 1) {
            (*T).head = (*T).tail = r;
            
            // ���Ӻ���Ŀ�
        } else {
            (*T).tail->next = r;
            (*T).tail = r;
        }
    }
    
    r = (*T).head;
    i = 0;      // ������T���α�
    count = 0;  // ͳ�Ʊ�������Ԫ�أ�˳����Ϊchars���α�
    
    // 2.Ϊ�������������
    while(count < len) {
        r->ch[i] = chars[count];
        
        i = (i + 1) % CHUNKSIZE;
        if(i == 0) {
            r = r->next;    // ָ����һ����
        }
        
        count++;
    }
    
    // 3.�������δ�����Ŀ�
    if(n != 0) {
        // ���Ǵ�ֵ����(����'\0')
        while(i < CHUNKSIZE) {
            (*T).tail->ch[i] = '\0';
            i++;
        }
    }
    
    // 4.��¼������Ϣ
    (*T).curlen = len;
    
    return OK;
}

/*
 * ����
 *
 *��ע��
 * �������Ľṹ�������٣������������ٲ�����
 */
Status DestroyString(LString* S) {
    return OK;
}

/*
 * ���
 *
 * ����S��ա�
 */
Status ClearString(LString* S) {
    Chunk* p, * q;
    
    p = (*S).head;
    
    // �ͷ����д�ռ�õĿռ�
    while(p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    
    (*S).head = NULL;
    (*S).tail = NULL;
    (*S).curlen = 0;
    
    return OK;
}

/*
 * �п�
 *
 * �жϴ�S���Ƿ������Ч���ݡ�
 *
 * ����ֵ��
 * TRUE : ��SΪ��
 * FALSE: ��S��Ϊ��
 */
Status StrEmpty(LString S) {
    return S.curlen == 0 ? TRUE : FALSE;
}

/*
 * ����
 *
 * ���ش�S��Ԫ�صĸ�����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
int StrLength(LString S) {
    return S.curlen;
}

/*
 * ���Ӵ�
 *
 * ��Sub����S[pos, pos+len-1]��
 * ����ֵָʾ�Ƿ��ȡ�ɹ���
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status SubString(LString* Sub, LString S, int pos, int len) {
    int m;      // Sub���ܿ���
    int n;      // ���Sub����δ�����Ŀ飬�洢�ÿ��е���ЧԪ������
    int i, j, count;
    Chunk* r, * p;
    
    if(pos < 1 || pos > S.curlen || len < 0 || pos + len - 1 > S.curlen) {
        return ERROR;
    }
    
    // ����ǽ�ȡ0���ַ�������Ҫ����ռ�
    if(len == 0) {
        (*Sub).head = NULL;
        (*Sub).tail = NULL;
        (*Sub).curlen = 0;
        
        return OK;
    }
    
    m = len / CHUNKSIZE;    // �ȼ�����Ҫ�����Ŀ�
    n = len % CHUNKSIZE;    // ���Sub����δ�����Ŀ飬����ÿ���������ЧԪ������
    if(n != 0) {
        m++;                // ����Sub���ܿ���
    }
    
    // 1.����Sub�Ľṹ
    for(i = 1; i <= m; i++) {
        // �����¿�
        r = (Chunk*) malloc(sizeof(Chunk));
        if(r == NULL) {
            exit(OVERFLOW);
        }
        r->next = NULL;
        
        // ��һ����
        if(i == 1) {
            (*Sub).head = (*Sub).tail = r;
            
            // ���Ӻ���Ŀ�
        } else {
            (*Sub).tail->next = r;
            (*Sub).tail = r;
        }
    }
    
    // ����S�е�pos��Ԫ�����ڵĿ飬����ָ��pָ����
    for(count = 1, p = S.head; pos > count * CHUNKSIZE; count++, p = p->next) {
        // ��ѭ��
    }
    
    r = (*Sub).head;            // ָ��Sub�Ŀ�
    
    i = 0;                      // ������Sub���α�
    j = (pos - 1) % CHUNKSIZE;  // ������S  ���α�
    count = 0;                  // ͳ�Ʊ�������Ԫ��
    
    // 2.Ϊ������Sub�������
    while(count < len) {
        r->ch[i] = p->ch[j];
        
        i = (i + 1) % CHUNKSIZE;
        if(i == 0) {
            r = r->next;    // ָ��Sub����һ����
        }
        
        j = (j + 1) % CHUNKSIZE;
        if(j == 0) {
            p = p->next;    // ָ��S����һ����
        }
        
        count++;
    }
    
    // 3.�������δ�����Ŀ�
    if(n != 0) {
        // ���Ǵ�ֵ����(����'\0')
        while(i < CHUNKSIZE) {
            (*Sub).tail->ch[i] = '\0';
            i++;
        }
    }
    
    // 4.��¼������Ϣ
    (*Sub).curlen = len;
    
    return OK;
}

/*
 * ����
 *
 * ��pos����ʼ����ģʽ��T������S���״γ��ֵ�λ�ã���������ڣ��򷵻�0��
 * ������ҳɹ�������ƥ���λ�á�
 *
 *��ע��
 * 1.��ʵ����Ҫ����������С�����Ӽ�
 * 2.��ʵ�ֱȽϵ�Ч
 */
int Index(LString S, LString T, int pos) {
    int i, s, t;
    LString sub;
    
    if(pos < 1 || pos > S.curlen || StrEmpty(T)) {
        return 0;
    }
    
    s = S.curlen;                //����S����
    t = T.curlen;                //ģʽ��T����
    i = pos;
    
    while(i + t - 1 <= s) {
        // ��ȡS[i, i+m-1]
        SubString(&sub, S, i, t);
        
        // ����Ӵ���ģʽ����ƥ�䣬����Ҫ�����ƽ�
        if(StrCompare(sub, T) != 0) {
            ++i;
        } else {
            return i;
        }
    }
    
    return 0;                        //�Ҳ���ƥ����򷵻�0
}

/*
 * ����
 *
 * ����T���뵽����S��posλ�ô���
 */
Status StrInsert(LString* S, int pos, LString T) {
    Chunk* pre, * p;    // preָ��Ŀ����ǰ����pָ��Ŀ���
    Chunk* h, * t;      // ָ�������Ŀ�����ͷ����β��
    Chunk* r;
    Chunk* s;
    int i, j, count;

    if(pos < 1 || pos > (*S).curlen + 1) {
        return ERROR;
    }

    // ���������Ĵ�Ϊ�գ�����ǰ����
    if(StrEmpty(T)) {
        return OK;
    }

    // ��¼����������ʼ�����ֹ��
    h = t = NULL;

    // ����T�еĿ飨ֻ���ƽṹ��
    for(r = T.head; r != NULL; r = r->next) {
        s = (Chunk*) malloc(sizeof(Chunk));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->next = NULL;

        if(r == T.head) {
            h = t = s;
        } else {
            t->next = s;
            t = s;
        }
    }

    // ����S�е�pos��Ԫ�����ڵĿ飨ע����ΪĿ��飩������ָ��preָ������ǰ��
    if(pos >= 1 && pos <= CHUNKSIZE) {
        pre = NULL;     // ˵����pos��Ԫ�����ڿ�Ϊhead
        p = (*S).head;
    } else {
        for(count = 1, pre = (*S).head; count < (pos - 1) / CHUNKSIZE; count++, pre = pre->next) {
            // ��ѭ��
        }
        p = pre->next;
    }

    /*
     * ����������h��t��Χ�Ŀ���뵽pos���ڵĿ�֮ǰ
     */

    if(pre == NULL) {
        t->next = (*S).head;
        (*S).head = h;
    } else {
        pre->next = h;
        t->next = p;
    }

    if(pre == (*S).tail) {
        (*S).tail = t;
    }

    /*
     * �ƶ�/����Ԫ��
     */

    j = 0;

    // ������뵽��ĳ����ġ��м䡱
    if((pos - 1) % CHUNKSIZE != 0) {
        // �ƶ�Ŀ�����posλ��֮ǰ��Ԫ��
        for(i = 1; i <= (pos - 1) % CHUNKSIZE; i++) {
            h->ch[j++] = p->ch[i - 1];
            p->ch[i - 1] = '\0';
        }
    }

    r = T.head;
    i = 0;

    // ����T�е�Ԫ�ص�S��
    for(count = 1; count <= T.curlen; count++) {
        h->ch[j] = r->ch[i];

        j = (j + 1) % CHUNKSIZE;
        i = (i + 1) % CHUNKSIZE;

        if(j == 0) {
            h = h->next;
        }

        if(i == 0) {
            r = r->next;
        }
    }

    // ���T�����һ�����а���'\0'
    if(T.curlen % CHUNKSIZE != 0) {
        r = p;  // ָ��Ŀ���
        i = (pos - 1) % CHUNKSIZE;

        // �ƶ�Ŀ�����posλ�ü���֮���Ԫ��
        for(count = pos; count <= (*S).curlen; count++) {
            h->ch[j] = r->ch[i];
            r->ch[i] = '\0';

            j = (j + 1) % CHUNKSIZE;
            i = (i + 1) % CHUNKSIZE;

            if(j == 0) {
                h = h->next;
            }

            if(i == 0) {
                r = r->next;
            }
        }
    }

    (*S).curlen += T.curlen;

    return OK;
}

/*
 * ɾ��
 *
 * ɾ��S[pos, pos+len-1]��
 */
Status StrDelete(LString* S, int pos, int len) {
    Chunk* pre;     // ָ��Ԫ��S[pos]���ڵĿ��ǰ��
    Chunk* p;       // ָ��Ԫ��S[pos]���ڵĿ�
    Chunk* q;       // ָ��Ԫ��S[pos+len]���ڵĿ�
    Chunk* r;
    int i, j, count, total;
    
    if(pos < 1 || pos > (*S).curlen || len < 0 || pos + len - 1 > (*S).curlen) {
        return ERROR;
    }
    
    // �����ɾ���ĳ���Ϊ0������ǰ����
    if(len == 0) {
        return OK;
    }
    
    // ����S[pos]���ڵĿ飬����ָ��preָ������ǰ��
    if(pos >= 1 && pos <= CHUNKSIZE) {
        pre = NULL;     // ˵����pos��Ԫ�����ڿ�Ϊhead
        p = (*S).head;
    } else {
        for(count = 1, pre = (*S).head; count < (pos - 1) / CHUNKSIZE; count++, pre = pre->next) {
            // ��ѭ��
        }
        p = pre->next;
    }
    
    // ����S[pos+len]���ڵĿ�
    for(count = (pos - 1) / CHUNKSIZE, q = p; count < (pos + len - 1) / CHUNKSIZE; count++, q = q->next) {
        // ��ѭ��
    }
    
    // ���������Ҫ�ƶ���Ԫ�ظ���
    total = (*S).curlen - (pos + len) + 1;
    
    // �����յĳ����ȶ�����
    (*S).curlen -= len;
    
    i = (pos - 1) % CHUNKSIZE;
    j = (pos + len - 1) % CHUNKSIZE;
    
    if(p != q) {
        // ɾ��p��q֮��Ŀ�
        r = p->next;
        while(r != q) {
            p->next = r->next;
            free(r);
            r = p->next;
        }
        
        if(q == NULL) {
            (*S).tail = p;
        }
        
        // �����Ҫɾ��pָ���������
        if((pos - 1) % CHUNKSIZE == 0) {
            // p�Ѿ�ָ�������ͷ��
            if(pre == NULL) {
                (*S).head = q;
            } else {
                pre->next = q;
            }
            
            free(p);
            p = q;
            
            if(q == NULL) {
                (*S).tail = pre;
            }
        }
    }
    
    // �Ѿ���λ
    if(p == q && i == j) {
        return OK;
    }
    
    for(count = 1; count <= total; count++) {
        // �ƶ�Ԫ��
        p->ch[i] = q->ch[j];
        
        i = (i + 1) % CHUNKSIZE;
        j = (j + 1) % CHUNKSIZE;
        
        if(i == 0) {
            pre = p;
            p = p->next;
        }
        
        if(j == 0) {
            q = q->next;
        }
    }
    
    // ǡ�����������Ŀ�
    if(i == 0) {
        (*S).tail = pre;
        r = p;
    } else {
        (*S).tail = p;
        
        // ʣ�ಿ�����Ǵ�ֵ�ַ�
        while(i < CHUNKSIZE) {
            p->ch[i++] = '\0';
        }
        
        r = p->next;
    }
    
    // �ͷŶ���Ŀռ�
    while(r != NULL) {
        (*S).tail->next = r->next;
        free(r);
        r = (*S).tail->next;
    }
    
    return OK;
}

/*
 * �Ƚ�
 *
 * �Ƚϴ�S�ʹ�T�����رȽϽ����
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
int StrCompare(LString S, LString T) {
    int i;
    Chunk* s = S.head;
    Chunk* t = T.head;
    
    while(s != NULL && t != NULL) {
        for(i = 0; i < CHUNKSIZE; i++) {
            if(s->ch[i] != t->ch[i]) {
                return s->ch[i] - t->ch[i];
            }
        }
        
        s = s->next;
        t = t->next;
    }
    
    if(s != NULL) {
        return 1;
    } else if(t != NULL) {
        return -1;
    } else {
        return 0;
    }
}

/*
 * ����
 *
 * ����S���Ƶ���T��
 */
Status StrCopy(LString* T, LString S) {
    int i;
    Chunk* s, * p;
    
    for(p = S.head; p; p = p->next) {
        s = (Chunk*) malloc(sizeof(Chunk));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->next = NULL;
        
        if(p == S.head) {
            (*T).head = (*T).tail = s;
        } else {
            (*T).tail->next = s;
            (*T).tail = s;
        }
        
        for(i = 0; i < CHUNKSIZE; i++) {
            (*s).ch[i] = (*p).ch[i];
        }
    }
    
    (*T).curlen = S.curlen;
    
    return OK;
}

/*
 * �滻
 *
 * ��V�滻����S�г��ֵ�������T��ȵ��Ҳ��ص����Ӵ���
 *
 *��ע��
 * 1.�ò���������С�����Ӽ�
 * 2.��ʵ�ֱȽϵ�Ч
 */
Status Replace(LString* S, LString T, LString V) {
    int i;
    
    if(StrEmpty(*S) || StrEmpty(T)) {
        return ERROR;
    }
    
    // ������S��Ѱ��ģʽ��T��һ�γ��ֵ�λ��
    i = Index(*S, T, 1);
    
    // �������ƥ����ַ���
    while(i != 0) {
        StrDelete(S, i, StrLength(T));  // ��S��ɾ��T
        StrInsert(S, i, V);             // ��S�в���V
        
        i += StrLength(V);      // i�л�����һ��λ��
        
        i = Index(*S, T, i);    // ������һ��ƥ����ַ���
    }
    
    return OK;
}

/*
 * ������
 *
 * ����S1��S2�����洢��T�з��ء�������Ӻ�ĳ����������ֻ����δ����Ĳ��֡�
 * ����ֵ��ʾ���Ӻ�Ĵ��Ƿ�������
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status Concat(LString* T, LString S1, LString S2) {
    Chunk* p;   // ��������S1��S2
    Chunk* r;   // ����T
    Chunk* s;
    int i, j, count;
    
    // ���㳤����Ϣ
    (*T).curlen = S1.curlen + S2.curlen;
    
    // ������Ҫ�������ٸ���
    count = (*T).curlen / CHUNKSIZE + ((*T).curlen % CHUNKSIZE == 0 ? 0 : 1);
    
    // ����S1�Ľṹ
    for(i = 1; i <= count; i++) {
        s = (Chunk*) malloc(sizeof(Chunk));
        if(s == NULL) {
            exit(OVERFLOW);
        }
        s->next = NULL;
        
        if(i == 1) {
            (*T).head = (*T).tail = s;
        } else {
            (*T).tail->next = s;
            (*T).tail = s;
        }
    }
    
    i = 0;
    r = (*T).head;
    
    // ����S1�е�����
    j = 0;
    p = S1.head;
    for(count = 0; count < S1.curlen; count++) {
        r->ch[i] = p->ch[j];
        
        i = (i + 1) % CHUNKSIZE;
        j = (j + 1) % CHUNKSIZE;
        
        if(i == 0) {
            r = r->next;
        }
        
        if(j == 0) {
            p = p->next;
        }
    }
    
    // ����S2�е�����
    j = 0;
    p = S2.head;
    for(count = 0; count < S2.curlen; count++) {
        r->ch[i] = p->ch[j];
        
        i = (i + 1) % CHUNKSIZE;
        j = (j + 1) % CHUNKSIZE;
        
        if(i == 0) {
            r = r->next;
        }
        
        if(j == 0) {
            p = p->next;
        }
    }
    
    // ����Ŀռ����Ǵ�ֵ�ַ�
    if(i != 0) {
        while(i < CHUNKSIZE) {
            r->ch[i] = '\0';
            i++;
        }
    }
    
    return OK;
}
