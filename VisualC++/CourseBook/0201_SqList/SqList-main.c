#include <stdio.h>
#include "SqList.h"                                //**02 ���Ա�**//

// �ж�data>e�Ƿ����
Status CmpGreater(ElemType data, ElemType e) {
    return data > e ? TRUE : FALSE;
}

// ���Ժ�������ӡԪ��
void PrintElem(ElemType e) {
    printf("%d ", e);
}


int main(int argc, char** argv) {
    SqList L;   // ��������˳���
    
    int i;
    ElemType e;
    
    printf("���������������� InitList \n");
    {
        printf("�� ��ʼ��˳��� L ...\n");
        InitList(&L);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListEmpty \n");
    {
        if(ListEmpty(L) == TRUE) {
            printf("�� L Ϊ�գ���\n");
        } else {
            printf("�� L ��Ϊ�գ�\n");
        }
    }
    PressEnterToContinue();
    
    
    printf("���������������� ListInsert \n");
    {
        for(i = 1; i <= 8; i++) {
            printf("�� ��Ϊʾ������ L �� %d ��λ�ò��� \"%d\"...\n", i, 2 * i);
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
        i = ListLength(L);
        printf("�� L �ĳ���Ϊ %d \n", i);
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
    
    
    printf("���������������� GetElem \n");
    {
        GetElem(L, 4, &e);
        printf("�� L �е� 4 ��λ�õ�Ԫ��Ϊ \"%d\" \n", e);
    }
    PressEnterToContinue();
    
    
    printf("���������������� LocateElem \n");
    {
        i = LocateElem(L, 7, CmpGreater);
        printf("�� L �е�һ��Ԫ��ֵ���� \"7\" ��Ԫ���� \"%d\" \n", L.elem[i - 1]);
    }
    PressEnterToContinue();
    
    
    printf("���������������� PriorElem \n");
    {
        ElemType cur_e = 6;
        
        if(PriorElem(L, cur_e, &e) == OK) {
            printf("�� Ԫ�� \"%d\" ��ǰ��Ϊ \"%d\" \n", cur_e, e);
        } else {
            printf("�� Ԫ�� \"%d\" ��ǰ�������ڣ�\n", cur_e);
        }
    }
    PressEnterToContinue();
    
    
    printf("���������������� NextElem \n");
    {
        ElemType cur_e = 6;
        
        if(NextElem(L, cur_e, &e) == OK) {
            printf("�� Ԫ�� \"%d\" �ĺ��Ϊ \"%d\" \n", cur_e, e);
        } else {
            printf("�� Ԫ�� \"%d\" �ĺ�̲����ڣ�\n", cur_e);
        }
    }
    PressEnterToContinue();
    
    
    printf("���������������� ClearList \n");
    {
        printf("�� ��� L ǰ��");
        if(ListEmpty(L) == TRUE) {
            printf(" L Ϊ�գ���\n");
        } else {
            printf(" L ��Ϊ�գ�\n");
        }
        
        ClearList(&L);
        
        printf("�� ��� L ��");
        if(ListEmpty(L) == TRUE) {
            printf(" L Ϊ�գ���\n");
        } else {
            printf(" L ��Ϊ�գ�\n");
        }
    }
    PressEnterToContinue();
    
    
    printf("���������������� DestroyList \n");
    {
        printf("�� ���� L ǰ��");
        if(L.elem != NULL) {
            printf(" L ���ڣ�\n");
        } else {
            printf(" L �����ڣ���\n");
        }
        
        DestroyList(&L);
        
        printf("�� ���� L ��");
        if(L.elem != NULL) {
            printf(" L ���ڣ�\n");
        } else {
            printf(" L �����ڣ���\n");
        }
    }
    PressEnterToContinue();
    
    
    return 0;
}
