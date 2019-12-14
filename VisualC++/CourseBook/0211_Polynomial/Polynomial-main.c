#include "Polynomial.h"         //**��02 ���Ա�**//

int main(int argc, char **argv) {
    Polynomial Pa, Pb;
    int m, n;
    
    m = 5;
    n = 6;
    
    printf("���������������� CreatPolyn \n");
    {
        printf("�� ��Ϊʾ������������Ϊ %d �Ķ���ʽPa...\n", m);
        CreatPolyn(&Pa, m, "TestData_Pa.txt");
        
        printf("�� ��Ϊʾ������������Ϊ %d �Ķ���ʽPb...\n", n);
        CreatPolyn(&Pb, n, "TestData_Pb.txt");
    }
    PressEnterToContinue();
    
    
    printf("���������������� PrintPolyn \n");
    {
        printf("�� һԪ����ʽ Pa = ");
        PrintPolyn(Pa);
        
        printf("�� һԪ����ʽ Pb = ");
        PrintPolyn(Pb);
    }
    PressEnterToContinue();
    
    
    printf("���������������� PolynLength \n");
    {
        printf("�� La ������Ϊ %d ��Lb ������Ϊ %d\n", PolynLength(Pa), PolynLength(Pb));
    }
    PressEnterToContinue();

    
    printf("���������������� AddPolyn \n");
    {
        CreatPolyn(&Pa, m, "TestData_Pa.txt");
        CreatPolyn(&Pb, n, "TestData_Pb.txt");
        
        AddPolyn(&Pa, &Pb);
        
        printf("�� Pa = Pa + Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue();
    
    
    printf("���������������� SubtractPolyn \n");
    {
        CreatPolyn(&Pa, m, "TestData_Pa.txt");
        CreatPolyn(&Pb, n, "TestData_Pb.txt");

        SubtractPolyn(&Pa, &Pb);

        printf("�� Pa = Pa - Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue();

    
    printf("���������������� MultiplyPolyn \n");
    {
        CreatPolyn(&Pa, m, "TestData_Pa.txt");
        CreatPolyn(&Pb, n, "TestData_Pb.txt");

        MultiplyPolyn(&Pa, &Pb);

        printf("�� Pa = Pa * Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue();
    
    return 0;
}

