#include <stdio.h>
#include "MFSet.h"      //**��06 ���Ͷ�����**//

// �����Ԫ��ϵ��
void PrintRelation(Relation R){
    int k;
    
    for(k=0; k<R.n; k++) {
        printf("(%d, %d) ", R.pairs[k].i, R.pairs[k].j);
    }
    
    printf("\n");
}


int main(int argc, char* argv[]) {
    MFSet S;
    Relation R1, R2;
    
    printf("���������������� initial_mfset��initial_relation \n");
    {
        printf("�� ��ʼ������ S ...\n");
        initial_mfset(&S, "TestData_S.txt");
        
        printf("�� ��ʼ����Ԫ��ϵ R1 ...\n");
        initial_relation(&R1, "TestData_R1.txt");
    
        printf("�� ��ʼ����Ԫ��ϵ R2 ...\n");
        initial_relation(&R2, "TestData_R2.txt");
    }
    PressEnterToContinue();
    
    
    printf("���������������� PrintGraph \n");
    {
        printf("�� ������� S ...\n");
        PrintGraph(S);
    }
    PressEnterToContinue();
    
    
    // ����һ
    printf("���������������� find_mfset��merge_mfset \n");
    {
        printf("�� �Լ���Ӧ�ö�Ԫ��ϵ R1�� ");
        build_mfset(&S, R1);
        PrintRelation(R1);

        printf("�� ������� S ...\n");
        PrintGraph(S);


        printf("�� �Լ���Ӧ�ö�Ԫ��ϵ R2�� ");
        build_mfset(&S, R2);
        PrintRelation(R2);

        printf("�� ������� S ...\n");
        PrintGraph(S);
    }
    PressEnterToContinue();
    
    
    // ������
//    printf("���������������� fix_mfset��mix_mfset \n");
//    {
//        printf("�� �Լ���Ӧ�ö�Ԫ��ϵ R1�� ");
//        bix_mfset(&S, R1);
//        PrintRelation(R1);
//
//        printf("�� ������� S ...\n");
//        PrintGraph(S);
//
//
//        printf("�� �Լ���Ӧ�ö�Ԫ��ϵ R2�� ");
//        bix_mfset(&S, R2);
//        PrintRelation(R2);
//
//        printf("�� ������� S ...\n");
//        PrintGraph(S);
//    }
//    PressEnterToContinue();
    
    return OK;
}
