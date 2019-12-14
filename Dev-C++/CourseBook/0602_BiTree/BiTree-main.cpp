#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "BiTree.h"     //**��06 ���Ͷ�����**//

// ���Ժ�������ӡԪ��
Status PrintElem(TElemType c) {
    printf("%c", c);
    return OK;
}


int main(int argc, char* argv[]) {
    BiTree T;
    
    printf("���������������� InitBiTree \n");
    {
        printf("�� ��ʼ���ն����� T ...\n");
        InitBiTree(&T);
    }
    PressEnterToContinue();
    
    
    printf("���������������� CreateBiTree \n");
    {
        printf("�� ���������д��������� T ...\n");
        CreateBiTree(&T, "TestData_Pre.txt");
    }
    PressEnterToContinue();
    
    
    printf("���������������� BiTreeDepth \n");
    {
        printf("�� ������ T �����Ϊ��%d \n", BiTreeDepth(T));
    }
    PressEnterToContinue();
    
    
    printf("���������������� PrintGraph \n");
    {
        printf("�� ���������Ľṹ��ӡ�� T ...\n");
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    
    printf("���������������� PreOrderTraverse \n");
    {
        printf("�� ǰ����������� T = ");
        PreOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� InOrderTraverse \n");
    {
        printf("�� ������������� T = ");
        InOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� PostOrderTraverse \n");
    {
        printf("�� ������������� T = ");
        PostOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� LevelOrderTraverse \n");
    {
        printf("�� ������������� T = ");
        LevelOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� Value \n");
    {
        TElemType e = 'F';
        printf("�� ��� %c ��ֵΪ %c\n", e, Value(T, e));
    }
    PressEnterToContinue();
    
    
    printf("���������������� Assign \n");
    {
        TElemType e = 'F';
        TElemType value = 'X';
        printf("�� ����� %c ��ֵΪ %c ��T = \n", e, value);
        Assign(T, e, value);
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    
    printf("���������������� Root \n");
    {
        printf("�� T �ĸ����Ϊ %c\n", Root(T));
    }
    PressEnterToContinue();
    
    
    printf("���������������� Parent \n");
    {
        TElemType e = 'E';
        printf("�� ��� %c ��˫��Ϊ��%c \n", e, Parent(T, e));
    }
    PressEnterToContinue();
    
    
    printf("���������������� LeftChild��RightChild \n");
    {
        TElemType e = 'E';
        printf("�� ��� %c �����ӽ��ֵΪ��%c ���Һ��ӽ��ֵΪ��%c\n", e, LeftChild(T, e), RightChild(T, e));
    }
    PressEnterToContinue();
    
    
    printf("���������������� LeftSibling \n");
    {
        TElemType e = 'I';
        printf("�� ��� %c �����ֵ�Ϊ��%c\n", e, LeftSibling(T, e));
    }
    PressEnterToContinue();
    
    
    printf("���������������� RightSibling \n");
    {
        TElemType e = 'H';
        printf("�� ��� %c �����ֵ�Ϊ��%c\n", e, RightSibling(T, e));
    }
    PressEnterToContinue();
    
    
    printf("���������������� InsertChild \n");
    {
        BiTree c1, c2;
        TElemType p1 = 'D';
        TElemType p2 = 'E';
        
        printf("�� �������� c1 ...\n");
        InitBiTree(&c1);
        CreateBiTree(&c1, "TestData_c1.txt");
        PrintGraph(c1);
        
        printf("�� �������� c2 ...\n");
        InitBiTree(&c2);
        CreateBiTree(&c2, "TestData_c2.txt");
        PrintGraph(c2);
        
        printf("�� ������ c1 ����Ϊ������ T �� %c ���������� ...\n", p1);
        InsertChild(T, p1, 1, c1);
        PrintGraph(T);
        
        printf("�� ������ c2 ����Ϊ������ T �� %c ���������� ...\n", p2);
        InsertChild(T, p2, 0, c2);
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    
    printf("���������������� DeleteChild \n");
    {
        TElemType p1 = 'D';
        TElemType p2 = 'E';
        
        printf("�� ɾ�������� T �� %c ���������� ...\n", p1);
        DeleteChild(T, p1, 1);
        PrintGraph(T);
        
        printf("�� ɾ�������� T �� %c ���������� ...\n", p2);
        DeleteChild(T, p2, 0);
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ClearBiTree��BiTreeEmpty \n");
    {
        printf("�� ���ǰ��");
        BiTreeEmpty(T) ? printf("T Ϊ�գ�\n") : printf("T ��Ϊ�գ�\n");
        
        ClearBiTree(&T);
        
        printf("�� ��պ�");
        BiTreeEmpty(T) ? printf("T Ϊ�գ�\n") : printf("T ��Ϊ�գ�\n");
    }
    PressEnterToContinue();
    
    return 0;
}
