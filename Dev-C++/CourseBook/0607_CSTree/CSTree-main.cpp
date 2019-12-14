#include <stdio.h>
#include "Status.h"     //**��01 ����**//
#include "CSTree.h"      //**��06 ���Ͷ�����**//

// ���Ժ�������ӡԪ��
Status PrintElem(TElemType c) {
    printf("%c", c);
    return OK;
}


int main(int argc, char* argv[]) {
    CSTree T;
    
    printf("���������������� InitTree \n");
    {
        printf("�� ��ʼ������ T ...\n");
        InitTree(&T);
    }
    PressEnterToContinue();
    
    
    printf("���������������� CreateTree \n");
    {
        printf("�� ���������д����� T ...\n");
        CreateTree(&T, "TestData_T.txt");
    }
    PressEnterToContinue();
    
    
    printf("���������������� TreeDepth \n");
    {
        printf("�� �� T �����Ϊ��%d \n", TreeDepth(T));
    }
    PressEnterToContinue();
    
    
    printf("���������������� PrintGraph \n");
    {
        printf("�� �����Ľṹ��ӡ�� T ...\n");
        printf("�� T = \n");
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    
    printf("���������������� PreOrderTraverse \n");
    {
        printf("�� ǰ������� T = ");
        PreOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� PostOrderTraverse \n");
    {
        printf("�� ��������� T = ");
        PostOrderTraverse(T, PrintElem);
    }
    PressEnterToContinue();
    
    
    printf("���������������� LevelOrderTraverse \n");
    {
        printf("�� ��������� T = ");
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
        printf("�� ����� %c ��ֵΪ %c ...\n", e, value);
        Assign(T, e, value);
        printf("�� T = \n");
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
    
    
    printf("���������������� ChildCount \n");
    {
        TElemType e = 'X';
        printf("�� ��� %c �� %d ������\n", e, ChildCount(T, e));
    }
    PressEnterToContinue();
    
    
    printf("���������������� Child \n");
    {
        TElemType e = 'X';
        int i = 2;
        printf("�� ��� %c �ĵ� %d �����ӽ��ֵΪ��%c \n", e, i, Child(T, e, i));
    }
    PressEnterToContinue();
    
    
    printf("���������������� LeftSibling \n");
    {
        TElemType e = 'H';
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
        CSTree c;
        TElemType p = 'C';
        int i = 2;
        
        printf("�� �������� c ...\n");
        InitTree(&c);
        CreateTree(&c, "TestData_c.txt");
        printf("�� c = \n");
        PrintGraph(c);
        
        printf("�� ������ c ����Ϊ�� T �� %c ���ĵ� %d ������ ...\n", p, i);
        InsertChild(&T, p, i, c);
        printf("�� T = \n");
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    
    printf("���������������� DeleteChild \n");
    {
        TElemType p = 'C';
        int i = 1;
        
        printf("�� ɾ���� T �� %c ���ĵ� %d ������ ...\n", p, i);
        DeleteChild(&T, p, i);
        printf("�� T = \n");
        PrintGraph(T);
    }
    PressEnterToContinue();
    
    
    printf("���������������� ClearTree��TreeEmpty \n");
    {
        printf("�� ���ǰ��");
        TreeEmpty(T) ? printf("T Ϊ�գ�\n") : printf("T ��Ϊ�գ�\n");
        
        ClearTree(&T);
        
        printf("�� ��պ�");
        TreeEmpty(T) ? printf("T Ϊ�գ�\n") : printf("T ��Ϊ�գ�\n");
    }
    PressEnterToContinue();
    
    return 0;
}
