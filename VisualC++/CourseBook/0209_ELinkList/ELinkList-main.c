#include <stdio.h>
#include "ELinkList.h"                            //**��02 ���Ա�**//

// �ж�data>e�Ƿ����
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    ELinkList L;
    Link p, q, s;
    Position r;
    int i;
    ElemType e;
    
    printf("���������������� InitList \n");
    {
        printf("�� ��ʼ����չ���������� L ...\n");
        InitList(&L);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListEmpty \n");
    {
        ListEmpty(L) ? printf("�� L Ϊ�գ���\n") : printf("�� L ��Ϊ�գ�\n");
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListInsert \n");
    {
        for(i = 1; i <= 8; i++) {
            printf("�� �� L �� %d ��λ�ò��� \"%d\" ...\n", i, 2 * i);
            ListInsert(&L, i, 2 * i);
        }
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListTraverse \n");
    {
        printf("�� L �е�Ԫ��Ϊ��L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListLength \n");
    {
        printf("�� L �ĳ���Ϊ %d \n", ListLength(L));
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListDelete \n");
    {
        printf("�� ɾ��ǰ��Ԫ�أ�L = ");
        ListTraverse(L, PrintElem);
    
        printf("�� ����ɾ�� L �е� 6 ��Ԫ��...\n");
    
        if(ListDelete(&L, 6, &e) == OK) {
            printf("�� ɾ���ɹ�����ɾ��Ԫ���ǣ�\"%d\"\n", e);
        } else {
            printf("�� ɾ��ʧ�ܣ��� 6 ��Ԫ�ز����ڣ�\n");
        }
    
        printf("�� ɾ�����Ԫ�أ�L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� LocateElem \n");
    {
        r = LocateElem(L, 7, CmpGreater);
        printf("�� L �е�һ��Ԫ��ֵ���� \"7\" ��Ԫ���� \"%d\" \n", r->data);
    }
    PressEnterToContinue();
    
    
    printf("���������������� PriorElem \n");
    {
        Position pre = PriorPos(L, r);
        
        if(pre !=NULL) {
            printf("�� Ԫ�� \"%d\" ��ǰ��Ϊ \"%d\" \n", r->data, pre->data);
        } else {
            printf("�� Ԫ�� \"%d\" ��ǰ�������ڣ�\n", r->data);
        }
    }
    PressEnterToContinue();
    
    
    printf("���������������� NextElem \n");
    {
        Position next = NextPos(L, r);
        
        if(next !=NULL) {
            printf("�� Ԫ�� \"%d\" �ĺ��Ϊ \"%d\" \n", r->data, next->data);
        } else {
            printf("�� Ԫ�� \"%d\" �ĺ�̲����ڣ�\n", r->data);
        }
    }
    PressEnterToContinue();
    
    
    printf("���������������� MakeNode \n");
    {
        printf("�� ������� \"100\" ...\n");
        MakeNode(&p, 100);
        printf("�� ������� \"200\" ...\n");
        MakeNode(&q, 200);
        printf("�� ������� \"300\" ...\n");
        MakeNode(&s, 300);
    }
    PressEnterToContinue();
    
    
    printf("���������������� InsFirst \n");
    {
        printf("�� ��Ԫ�� \"%d\" ���뵽Ԫ�� \"%d\" ֮��...\n", s->data, r->data);
        InsFirst(&L, r, s);
        printf("�� L �е�Ԫ��Ϊ��L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� DelFirst \n");
    {
        printf("�� ɾ��Ԫ�� \"%d\" ֮���Ԫ��...\n", r->data);
        DelFirst(&L, r, &s);
        printf("�� ��ɾ����Ԫ��Ϊ��\"%d\"\n", s->data);
        printf("�� L �е�Ԫ��Ϊ��L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue();


    printf("���������������� InsBefore \n");
    {
        Link t = r;
        
        printf("�� ��Ԫ�� \"%d\" ���뵽Ԫ�� \"%d\" ֮ǰ...\n", p->data, t->data);
        InsBefore(&L, &t, p);
        printf("�� L �е�Ԫ��Ϊ��L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue();


    printf("���������������� InsAfter \n");
    {
        Link t = r;
        
        printf("�� ��Ԫ�� \"%d\" ���뵽Ԫ�� \"%d\" ֮��...\n", q->data, t->data);
        InsAfter(&L, &t, q);
        printf("�� L �е�Ԫ��Ϊ��L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� Append \n");
    {
        printf("�� ������� \"400\" ...\n");
        MakeNode(&s, 400);
        
        printf("�� ��Ԫ�� %d ���뵽�������...\n", s->data);
        Append(&L, s);
        printf("�� L �е�Ԫ��Ϊ��L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue();


    printf("���������������� Remove \n");
    {
        printf("�� ���������ɾ��Ԫ��...\n");
        Remove(&L, &s);
        printf("�� ��ɾ����Ԫ��Ϊ��\"%d\"\n", s->data);
        printf("�� L �е�Ԫ��Ϊ��L = ");
        ListTraverse(L, PrintElem);
    }
    PressEnterToContinue();

    
    printf("���������������� ClearList \n");
    {
        printf("��� L ǰ��");
        ListEmpty(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");

        ClearList(&L);

        printf("��� L ��");
        ListEmpty(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
    }
    PressEnterToContinue();
    
    
    printf("���������������� DestroyList \n");
    {
        printf("���� L ǰ��");
        L.head != NULL && L.tail != NULL ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
        
        DestroyList(&L);
        
        printf("���� L ��");
        L.head != NULL && L.tail != NULL ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
        
    }
    PressEnterToContinue();
    
    return 0;
}

