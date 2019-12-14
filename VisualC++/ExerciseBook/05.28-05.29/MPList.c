/*==========
 * mԪ����ʽ
 ===========*/

#include "MPList.h"

// �μ�ͷ�ļ��е�����
char Var[27];

/*
 * ����
 *
 * ���ַ���S����mԪ����P��
 * ����У��S�Ƿ���д��ȷ��
 *
 * P   : �����Ķ���ʽ
 * S   : ����ʽ�ַ���
 * vars: �����б��ӵ�һԪ��ʼ���У�����xyz������Ԫ����ʽ�е�δ֪�����
 */
Status CreateMPList(MPList* P, char* S, char* vars) {
    if(P == NULL) {
        return ERROR;
    }
    
    // �����ַ���S�еĿհף����������ɴ�ӡ�ַ�������ո�
    ClearBlank(&S);
    
    if(strlen(S) == 0) {
        *P = NULL;
        return ERROR;
    }
    
    // ��ʼ��Ԫ��Ϣ
    strcpy(Var, vars);
    
    *P = (MPList) malloc(sizeof(MPNode));
    if(*P == NULL) {
        exit(OVERFLOW);
    }
    
    (*P)->tag = List;
    (*P)->exp = (int) strlen(vars);
    (*P)->tp = NULL;
    
    Create(&(*P)->Node.hp, S);
    
    return OK;
}

/*
 * mԪ����ʽ��������
 */
static Status Create(MPList* P, char* S) {
    char* Sc;
    char* hhstr, * hstr, * str;
    char* sub;
    MPList r;
    float f;
    
    // ��ȡS��һ������
    SubString(&Sc, S, 1, (int) strlen(S));
    
    *P = (MPList) malloc(sizeof(MPNode));
    if(*P == NULL) {
        exit(OVERFLOW);
    }
    
    (*P)->tag = List;
    (*P)->exp = (int) Sc[0];  // ����δ֪����ǣ�����x��y��z
    (*P)->Node.hp = NULL;
    (*P)->tp = NULL;
    
    StrDelete(&Sc, 1, 1);                           // ɾ��δ֪�����
    SubString(&str, Sc, 2, (int) strlen(Sc) - 2);   // ��ȥ���������
    
    r = *P;
    
    while(!StrEmpty(str)) {
        // ���
        sever(&hstr, &str);
        
        SubString(&sub, hstr, 2, (int) strlen(hstr) - 2);   // ��ȥ���������
        sever(&hhstr, &sub);
        
        // �����ӽ��
        r->tp = (MPList) malloc(sizeof(MPNode));
        if(r->tp == NULL) {
            exit(OVERFLOW);
        }
        GetElem(hhstr, 1, &f);
        r->tp->exp = (int) f;  // ��ȡָ��
        r->tp->tp = NULL;
        
        if(ElemCount(sub) == 1) {
            r->tp->tag = Atom;
            GetElem(sub, 1, &f);
            r->tp->Node.coef = f;
        } else {
            r->tp->tag = List;
            Create(&(r->tp->Node.hp), sub);
        }
        
        r = r->tp;
    }
    
    return OK;
}

/*
 * ͼ�λ����
 *
 * ���������mԪ����P��
 */
void PrintGraph(MPList P) {
    if(P == NULL) {
        printf("\n");
        return;
    }
    Print(P->Node.hp);
    printf("\n");
}

/*
 * ͼ�λ�������ڲ�ʵ��
 */
static void Print(MPList head) {
    MPList p;
    
    if(head == NULL) {
        return;
    }
    
    printf("%c(", head->exp);
    
    p = head->tp;
    
    while(p != NULL) {
        printf("(%d,", p->exp);
        
        if(p->tag == List) {
            Print(p->Node.hp);
        } else {
            printf("%.2f", p->Node.coef);
        }
        
        printf(")");
        
        p = p->tp;
        
        if(p != NULL) {
            printf(",");
        }
    }
    
    printf(")");
}

/*
 * ���ǿմ�str�ָ�������֣�hsubΪ��һ��','֮ǰ���Ӵ���strΪ��һ��','֮����Ӵ���
 *
 *��ע��
 * 1.��������ַ���str������ȷ�������޿հ׷��ţ���str���Ѿ���ȥ��������š���
 * 2.������ɺ�strҲ�ᷢ���仯
 */
static void sever(char** hstr, char** str) {
    int i, k, n;
    
    char* head, * tail;
    
    // strΪ��ʱ��hstrҲΪ��
    if(strlen(*str) == 0) {
        *hstr = NULL;
        return;
    }
    
    n = (int) strlen(*str);
    
    i = 0;  // �����ַ���ʱ���α�
    k = 0;  // ���������δ�����������
    
    do {
        if((*str)[i] == '(') {
            ++k;
        }
        
        if((*str)[i] == ')') {
            --k;
        }
        
        i++;
    } while(i < n && ((*str)[i] != ',' || k != 0));
    
    if(i < n) {
        head = (char*) malloc((i + 1) * sizeof(char));
        tail = (char*) malloc((n - i - 1 + 1) * sizeof(char));
        
        strncpy(head, *str, i);
        head[i] = '\0';
        
        strncpy(tail, (*str + i + 1), n - i - 1);
        tail[n - i - 1] = '\0';
    } else {
        head = *str;
        tail = (char*) malloc(sizeof(char));
        tail[0] = '\0';
    }
    
    *hstr = head;
    *str = tail;
}


/*
 * ���ƶ���ʽ����P���Ƶ�Q
 */
void Copy(MPList P, MPList* Q) {
    if(P == NULL) {
        *Q = NULL;
        return;
    }
    
    *Q = (MPList) malloc(sizeof(MPNode));
    (*Q)->tag = P->tag;
    (*Q)->exp = P->exp;
    
    if(P->tag == List) {
        Copy(P->Node.hp, &((*Q)->Node.hp));
    } else {
        (*Q)->Node.coef = P->Node.coef;
    }
    
    Copy(P->tp, &((*Q)->tp));
}
