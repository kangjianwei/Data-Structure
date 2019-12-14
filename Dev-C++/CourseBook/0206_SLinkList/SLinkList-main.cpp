#include <stdio.h>
#include "Status.h"
#include "SLinkList.h"                        //**��02 ���Ա�**//

// �ж�data>e�Ƿ����
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    SLinkList space;    // ���ÿռ�
    int S;              // ��̬����ͷ�������
    
    int i;
    ElemType e;
    
    printf("���������������� InitList \n");
    {
        printf("�� ��ʼ�������� S ...\n");
        InitList(space, &S);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListEmpty \n");
    {
        ListEmpty(space, S) ? printf("�� S Ϊ�գ���\n") : printf("�� S ��Ϊ�գ�\n");
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListInsert \n");
    {
        for(i = 1; i <= 8; i++) {
            printf("�� �� S �� %d ��λ�ò��� \"%d\" ...\n", i, 2 * i);
            ListInsert(space, S, i, 2 * i);
        }
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListTraverse \n");
    {
        printf("�� S �е�Ԫ��Ϊ��S = ");
        ListTraverse(space, S, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListLength \n");
    {
        printf("�� S �ĳ���Ϊ %d \n", ListLength(space, S));
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListDelete \n");
    {
        printf("�� ɾ��ǰ��Ԫ�أ�S = ");
        ListTraverse(space, S, PrintElem);
        
        printf("�� ����ɾ�� S �е� 6 ��Ԫ��...\n");
        
        if(ListDelete(space, S, 6, &e) == OK) {
            printf("�� ɾ���ɹ�����ɾ��Ԫ���ǣ�\"%d\"\n", e);
        } else {
            printf("�� ɾ��ʧ�ܣ��� 6 ��Ԫ�ز����ڣ�\n");
        }
        
        printf("�� ɾ�����Ԫ�أ�S = ");
        ListTraverse(space, S, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� GetElem \n");
    {
        GetElem(space, S, 4, &e);
        printf("�� S �е� 4 ��λ�õ�Ԫ��Ϊ \"%d\" \n", e);
    }
    PressEnterToContinue();
    
    
    printf("���������������� LocateElem \n");
    {
        i = LocateElem(space, S, 7, CmpGreater);
        GetElem(space, S, i, &e);
        printf("�� S �е�һ��Ԫ��ֵ���� \"7\" ��Ԫ���� \"%d\" \n", e);
    }
    PressEnterToContinue();
    
    
    printf("���������������� PriorElem \n");
    {
        ElemType cur_e = 6;
        
        if(PriorElem(space, S, cur_e, &e) == OK) {
            printf("�� Ԫ�� \"%d\" ��ǰ��Ϊ \"%d\" \n", cur_e, e);
        } else {
            printf("�� Ԫ�� \"%d\" ��ǰ�������ڣ�\n", cur_e);
        }
    }
    PressEnterToContinue();
    
    
    printf("���������������� NextElem \n");
    {
        ElemType cur_e = 6;
        
        if(NextElem(space, S, cur_e, &e) == OK) {
            printf("�� Ԫ�� \"%d\" �ĺ��Ϊ \"%d\" \n", cur_e, e);
        } else {
            printf("�� Ԫ�� \"%d\" �ĺ�̲����ڣ�\n", cur_e);
        }
    }
    PressEnterToContinue();
    
    
    printf("���������������� ClearList \n");
    {
        printf("�� ��� S ǰ��");
        ListEmpty(space, S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
        
        ClearList(space, S);
        
        printf("�� ��� S ��");
        ListEmpty(space, S) ? printf(" S Ϊ�գ���\n") : printf(" S ��Ϊ�գ�\n");
    }
    PressEnterToContinue();
    
    
    printf("���������������� DestroyList \n");
    {
        printf("�� ���� S ǰ��");
        S!=0 ? printf(" S ���ڣ�\n") : printf(" S �����ڣ���\n");
        
        DestroyList(space, &S);
        
        printf("�� ���� S ��");
        S!=0 ? printf(" S ���ڣ�\n") : printf(" S �����ڣ���\n");
    }
    PressEnterToContinue();
    
    return 0;
}

