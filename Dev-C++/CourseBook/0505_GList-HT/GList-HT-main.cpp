#include <stdio.h>
#include "GList-HT.h"        //**��05 ����͹����**//

void PrintElem(AtomType e);                //��ӡ�����ԭ��

int main(int argc, char** argv) {
    GList Tmp, G;
    GList g1, g2, g3;
    SString S1, S2, S3;

    printf("���������������� ���� InitGList \n");
    {
        printf("�� �����յĹ���� Tmp ...\n");
        InitGList(&Tmp);
    }
    PressEnterToContinue();

    printf("���������������� ���� GListEmpty \n");
    {
        int tag;

        tag = GListEmpty(Tmp);
        tag ? printf("�� Tmp Ϊ�գ�\n") : printf("�� Tmp ��Ϊ�գ���\n");
    }
    PressEnterToContinue();

    printf("���������������� ���� CreateGList \n");
    {
        char* s1 = "()";
        char* s2 = "(e)";
        char* s3 = "(a,(b,c,d))";

        printf("�� ���������S1: %s ...\n", s1);
        StrAssign(S1, s1);
        CreateGList(&g1, S1);

        printf("�� ���������S2: %s ...\n", s2);
        StrAssign(S2, s2);
        CreateGList(&g2, S2);

        printf("�� ���������S3: %s ...\n", s3);
        StrAssign(S3, s3);
        CreateGList(&g3, S3);
    }
    PressEnterToContinue();

    printf("���������������� ���� InsertFirst \n");
    {
        printf("�� �� S3��S2��S1 ���β��뵽 Tmp ���׸�λ��...\n");
        InsertFirst(&Tmp, g3);
        InsertFirst(&Tmp, g2);
        InsertFirst(&Tmp, g1);
    }
    PressEnterToContinue();

    printf("���������������� ���� Traverse \n");
    {
        printf("�� ����������ԭ�� Tmp = ");
        Traverse(Tmp, PrintElem);
        printf("\n");
    }
    PressEnterToContinue();

    printf("���������������� ���� PrintGraph \n");
    {
        printf("�� �������������� Tmp = ");
        PrintGraph(Tmp);
    }
    PressEnterToContinue();

    printf("���������������� ���� CopyGList \n");
    {
        printf("�� ���� Tmp �� G = ");
        CopyGList(&G, Tmp);
        PrintGraph(G);
    }
    PressEnterToContinue();

    printf("���������������� ���� DeleteFirst \n");
    {
        GList h;

        printf("�� ɾ������� Tmp �ı�ͷ��");

        DeleteFirst(&Tmp, &h);
        PrintGraph(h);

        printf("�� Tmp = ");
        PrintGraph(Tmp);
    }
    PressEnterToContinue();

    printf("���������������� ���� GListLength \n");
    {
        printf("�� ����� G �ĳ���Ϊ�� %d \n", GListLength(G));
    }
    PressEnterToContinue();

    printf("���������������� ���� GListDepth \n");
    {
        printf("�� ����� G �����Ϊ�� %d\n", GListDepth(G));
    }
    PressEnterToContinue();

    printf("���������������� ���� GetHead \n");
    {
        GList H;

        printf("�� ����� G �ı�ͷ H = ");
        H = GetHead(G);
        PrintGraph(H);
    }
    PressEnterToContinue();

    printf("���������������� ���� GetTail \n");
    {
        GList T;

        printf("�� ����� G �ı�β T = ");
        T = GetTail(G);
        PrintGraph(T);
    }
    PressEnterToContinue();

    printf("���������������� ���� DestroyGList \n");
    {
        printf("�� ���� G ǰ��");
        G ? printf(" G ���ڣ�\n") : printf(" G �����ڣ���\n");

        DestroyGList(&G);

        printf("�� ���� G ��");
        G ? printf(" G ���ڣ�\n") : printf(" G �����ڣ���\n");
    }
    PressEnterToContinue();
    
    return 0;
}

void PrintElem(AtomType e) {
    printf("%c ", e);
}
