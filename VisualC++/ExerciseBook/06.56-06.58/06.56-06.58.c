#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "BiThrTree.h"  //**��06 ���Ͷ�����**//

/*
 * ��������������������Ѱ�ҽ��p�ĺ��
 */
BiThrTree Algo_6_56(BiThrTree p);

// ���Է���Algo_6_56�����������������
void PreTraverse(BiThrTree Thrt);


/*
 * �ں�����������������Ѱ�ҽ��p�ĺ��
 */
BiThrTree Algo_6_57(BiThrTree p);

// ���Է���Algo_6_57��������ĺ�������
void PosTraverse(BiThrTree Thrt);


/*
 * �������Ϊx���ҽ��xֻ��������������ȫ��������������Ϊ���p����������
 * ���У����p���ڵ���Ҳ������ȫ������������Thrxָ������������x��ͷ��㡣
 * ע��������p�Ѿ�����������������������ժ�£��޽�Ϊ�����x��������
 */
Status Algo_6_58(BiThrTree p, BiThrTree x, BiThrTree Thrx);


// �������������T����������������
Status PreOrderThreading(BiThrTree* Thrt, BiThrTree T);

// ���������������ڲ�ʵ��
void PreTheading(BiThrTree p);

// ��������������������������������ǵݹ��㷨��
Status PreOrderTraverse_Thr(BiThrTree Thrt, Status(Visit)(TElemType));


// �������������T������������������˳����ʼ��parent��
Status PosOrderThreading(BiThrTree* Thrt, BiThrTree T);

// ���������������ڲ�ʵ�֣�������������ı�����ʽ��
void PosTheading(BiThrTree p);

// �Ժ������������������к���������ǵݹ��㷨��
Status PosOrderTraverse_Thr(BiThrTree Thrt, Status(Visit)(TElemType));


// ���Ժ�������ӡԪ��
Status PrintElem(TElemType c);



int main(int argc, char* argv[]) {
    
    printf("�������� 6.56 ��֤...������\n");
    {
        BiThrTree T;    // ������
        BiThrTree Thr;  // ����������������
        
        printf("�� ����������(ABDG^^^EH^^I^^CF^J^^^)����������...\n");
        CreateBiTree(&T, "TestData_T.txt");
        
        printf("�� �Զ���������������������...\n");
        PreOrderThreading(&Thr, T);
        
        printf("�� �������������������������");
        PreOrderTraverse_Thr(Thr, PrintElem);
    
        printf("�� ���Է���Algo_6_56����������������У�");
        PreTraverse(Thr);
    }
    PressEnterToContinue();
    
    
    printf("�������� 6.57 ��֤...������\n");
    {
        BiThrTree T;    // ������
        BiThrTree Thr;  // ����������������
        
        printf("�� ����������(ABDG^^^EH^^I^^CF^J^^^)����������...\n");
        CreateBiTree(&T, "TestData_T.txt");
        
        printf("�� �Զ��������к�����������...\n");
        PosOrderThreading(&Thr, T);
        
        printf("�� �������������������������");
        PosOrderTraverse_Thr(Thr, PrintElem);
    
        printf("�� ���Է���Algo_6_57��������ĺ������У�");
        PosTraverse(Thr);
    }
    PressEnterToContinue();
    
    
    printf("�������� 6.58 ��֤...������\n");
    {
        BiThrTree T;    // ������
        BiThrTree Thr;  // ����ȫ����������
    
        BiThrTree Tx;       // ������Ķ�����
        BiThrTree Thrx;     // �����������ȫ����������
    
        BiThrTree p;
        
        printf("�� ����������(ABDG^^^EH^^I^^CF^J^^^)����������...\n");
        CreateBiTree(&T, "TestData_T.txt");
        
        printf("�� �Զ�������������ȫ������...\n");
        InOrderThreading(&Thr, T);
        
        printf("�� �����������ȫ������������");
        InOrderTraverse_Thr(Thr, PrintElem);
    
        printf("�� ===============================================\n");
    
        printf("�� ����������(012^47^^^35^^68^^9^^^)����������...\n");
        CreateBiTree(&Tx, "TestData_x.txt");
    
        printf("�� �Զ�������������ȫ������...\n");
        InOrderThreading(&Thrx, Tx);
    
        printf("�� �����������ȫ������������");
        InOrderTraverse_Thr(Thrx, PrintElem);
    
        printf("�� ===============================================\n");
    
        p = T->lchild->rchild;
        printf("�� �������⣬������ x ���뵽�� T �� %c �����...\n", p->data);
        Algo_6_58(p, Tx, Thrx);
    
        printf("�� ������ɺ������ȫ����������Ϊ��");
        InOrderTraverse_Thr(Thr, PrintElem);
    }
    PressEnterToContinue();
    
}



/*
 * ��������������������Ѱ�ҽ��p�ĺ��
 */
BiThrTree Algo_6_56(BiThrTree p) {
    if(p == NULL) {
        return NULL;
    }
    
    // ������ں��������ֱ�ӻ�ȡ�����Ϣ
    if(p->RTag == Thread) {
        p = p->rchild;
    } else {
        if(p->lchild != NULL) {
            p = p->lchild;
        } else {
            p = p->rchild;
        }
    }
    
    return p;
}

// ���Է���Algo_6_56�����������������
void PreTraverse(BiThrTree Thrt) {
    BiThrTree p = Thrt->rchild;
    
    while(p != Thrt) {
        printf("%c", p->data);
        p = Algo_6_56(p);
    }
    
    printf("\n");
}


/*
 * �ں�����������������Ѱ�ҽ��p�ĺ��
 */
BiThrTree Algo_6_57(BiThrTree p) {
    if(p == NULL) {
        return NULL;
    }
    
    // ������ں��������ֱ�ӻ�ȡ�����Ϣ
    if(p->RTag == Thread) {
        p = p->rchild;
    } else {
        // �����ǰ���������
        if(p == p->parent->rchild) {
            p = p->parent;
        } else {
            // ��������û���Һ���
            if(p->parent->rchild == NULL || p->parent->RTag == Thread) {
                p = p->parent;
            } else {
                p = p->parent->rchild;
                
                /* �������ֵܽ��������������Ҷ� */
                
                while(p->lchild != NULL) {
                    p = p->lchild;
                }
                
                while(p->rchild != NULL && p->RTag == Link) {
                    p = p->rchild;
                }
            }
        }
    }
    
    return p;
}

// ���Է���Algo_6_57��������ĺ�������
void PosTraverse(BiThrTree Thrt) {
    BiThrTree p = Thrt->rchild;
    
    while(p != Thrt) {
        printf("%c", p->data);
        p = Algo_6_57(p);
    }
    
    printf("\n");
}


/*
 * �������Ϊx���ҽ��xֻ��������������ȫ��������������Ϊ���p����������
 * ���У����p���ڵ���Ҳ������ȫ������������Thrxָ������������x��ͷ��㡣
 * ע��������p�Ѿ�����������������������ժ�£��޽�Ϊ�����x��������
 */
Status Algo_6_58(BiThrTree p, BiThrTree x, BiThrTree Thrx) {
    BiThrTree pPre; // ���p��ǰ��
    
    BiThrTree xFirst;    // ��x���������еĵ�һ�����
    BiThrTree xLast;     // ��x���������е����һ�����
    
    BiThrTree lt;       // p��������
    BiThrTree ltFirst;  // ����lt���������еĵ�һ�����
    
    if(p==NULL || x==NULL) {
        return ERROR;
    }
    
    // x��㲻��������Һ���
    if(x->RTag==Link) {
        return ERROR;
    }
    
    // ��ȡ��x���������еĵ�һ���������һ�����
    xFirst = Thrx->lchild;
    // ���������������һֱ�������
    while(xFirst->LTag==Link){
        xFirst = xFirst->lchild;
    }
    xLast = Thrx->rchild;
    
    // ������p������������
    if(p->LTag==Thread) {
        pPre = p->lchild;   // ֱ�ӻ�ȡp��ǰ��
        
        p->LTag = Link;     // �޸�p��������Ϊ����
        p->lchild = x;      // ��������x
        
        xFirst->lchild = pPre;  // ����xFirst��������
        xLast->rchild = p;      // ����xLast��������
        
        // ������p����������
    } else {
        // ָ����p��������
        lt = p->lchild;
    
        // ��������lt���������еĵ�һ�����
        ltFirst = lt;
        // ����������ӣ���һֱ�������
        while(ltFirst->LTag==Link){
            ltFirst = ltFirst->lchild;
        }
        
        x->RTag = Link;     // ��lt����Ϊx��������
        x->rchild = lt;
    
        xFirst->lchild = ltFirst->lchild;   // �ӹ�����lt��������
        ltFirst->lchild = x;                // ����lt��������ָ��x
    
        p->lchild = x;  // ����p��������
    }
    
    // ��x��Thrx���Ƴ�
    Thrx->lchild = Thrx->rchild = Thrx;
    
    return OK;
}


// �������������T����������������
Status PreOrderThreading(BiThrTree* Thrt, BiThrTree T) {
    *Thrt = (BiThrTree) malloc(sizeof(BiThrNode));
    if(*Thrt == NULL) {
        exit(OVERFLOW);
    }
    
    (*Thrt)->data = '\0';
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = NULL;
    
    // ����ֻ������ͷ���
    if(!T) {
        (*Thrt)->lchild = (*Thrt)->rchild = *Thrt;
    } else {
        (*Thrt)->lchild = T;
        pre = *Thrt;    // ָ��ͷ���
        
        PreTheading(T); // ��ʼ������
        
        pre->RTag = Thread;     // ���һ�����������
        pre->rchild = *Thrt;    // ���һ�����ָ��ͷ���
        
        (*Thrt)->rchild = T;    // ͷ���ָ���һ����㣬������ѭ������ϵ
    }
    
    return OK;
}

// ���������������ڲ�ʵ��
void PreTheading(BiThrTree p) {
    if(p == NULL) {
        return;
    }
    
    // Ϊ��һ����������������������
    if(pre->rchild == NULL) {
        pre->RTag = Thread;
        pre->rchild = p;
    } else {
        // �����������Ϊ�գ������Link���
        pre->RTag = Link;
    }
    
    // pre��ǰŲһ��
    pre = p;
    
    // ������������
    PreTheading(p->lchild);
    
    // ���������������������������
    if(p->rchild != NULL && p->RTag == Link) {
        PreTheading(p->rchild);
    }
}

// ��������������������������������������ǵݹ��㷨��
Status PreOrderTraverse_Thr(BiThrTree Thrt, Status(Visit)(TElemType)) {
    BiThrTree p = Thrt;     // pָ��������������
    
    while(p->rchild != Thrt) {
        // ��������ʣ�ֱ����ͷ
        while(p->lchild != NULL) {
            p = p->lchild;
            if(Visit(p->data) == ERROR) {
                return ERROR;
            }
        }
        
        // ������ʵ�ͷ�������ҷ��ʣ�ͨ��������
        if(p->rchild != Thrt) {
            p = p->rchild;
            if(Visit(p->data) == ERROR) {
                return ERROR;
            }
        }
    }
    
    printf("\n");
    
    return OK;
}


// �������������T������������������˳����ʼ��parent��
Status PosOrderThreading(BiThrTree* Thrt, BiThrTree T) {
    *Thrt = (BiThrTree) malloc(sizeof(BiThrNode));
    if(*Thrt == NULL) {
        exit(OVERFLOW);
    }
    
    (*Thrt)->data = '\0';
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    (*Thrt)->rchild = *Thrt;
    
    if(T == NULL) {
        (*Thrt)->lchild = (*Thrt)->rchild = *Thrt;
    } else {
        (*Thrt)->lchild = T;
        pre = *Thrt;    // ָ��ͷ���
        
        T->parent = *Thrt;
        
        PosTheading(T); // ��ʼ������
        
        (*Thrt)->rchild = pre;    // ͷ����������ָ������һ����㣬������ѭ������ϵ
    }
    
    return OK;
}

// ���������������ڲ�ʵ�֣�������������ı�����ʽ��
void PosTheading(BiThrTree p) {
    if(p == NULL) {
        return;
    }
    
    // Ϊ��ǰ��������������������
    if(p->rchild == NULL) {
        p->RTag = Thread;
        p->rchild = pre;
    } else {
        // �����������Ϊ�գ������Link���
        p->RTag = Link;
    }
    
    // pre������˳����Ϊ��һ�����
    pre = p;
    
    // ������������
    if(p->RTag != Thread) {
        if(p->rchild != NULL) {
            p->rchild->parent = p;
        }
        
        PosTheading(p->rchild);
    }
    
    if(p->lchild != NULL) {
        p->lchild->parent = p;
    }
    
    // ������������
    PosTheading(p->lchild);
}

// �������Ժ������������������к���������ǵݹ��㷨��
Status PosOrderTraverse_Thr(BiThrTree Thrt, Status(Visit)(TElemType)) {
    BiThrTree r = Thrt->rchild; // pָ������һ�����
    BiThrTree p;
    
    // ����Ϊ��
    while(r != Thrt) {
        if(Visit(r->data) == ERROR) {
            return ERROR;
        }
        
        // ���ں������
        if(r->RTag == Thread) {
            r = r->rchild;
        } else {
            p = r->parent;
            if(p == Thrt) {
                break;  // �Ѿ��������
            }
            
            // �����ǰ������Һ���
            if(r == p->rchild) {
                r = p;
                
                // �����ǰ���������
            } else {
                // �������Һ���ΪNULL
                if(p->rchild == NULL || p->RTag == Thread) {
                    r = p;
                } else {
                    r = p->rchild;
                    
                    /* ����r��������������Ҷ� */
                    
                    while(r->lchild != NULL) {
                        r = r->lchild;
                    }
                    
                    while(r->rchild != NULL && r->RTag == Link) {
                        r = r->rchild;
                    }
                }
            }
        }
    }
    
    printf("\n");
    
    return OK;
}


// ���Ժ�������ӡԪ��
Status PrintElem(TElemType c) {
    printf("%c", c);
    return OK;
}
