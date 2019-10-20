#include "Polynomial.h"         //**▲02 线性表**//

int main(int argc, char **argv) {
    Polynomial Pa, Pb;
    int m, n;
    
    m = 5;
    n = 6;
    
    printf("████████ CreatPolyn \n");
    {
        printf("█ 作为示范，创建项数为 %d 的多项式Pa...\n", m);
        CreatPolyn("TestData_Pa.txt", &Pa, m);
        
        printf("█ 作为示范，创建项数为 %d 的多项式Pb...\n", n);
        CreatPolyn("TestData_Pb.txt", &Pb, n);
    }
    PressEnterToContinue();
    
    
    printf("████████ PrintPolyn \n");
    {
        printf("█ 一元多项式 Pa = ");
        PrintPolyn(Pa);
        
        printf("█ 一元多项式 Pb = ");
        PrintPolyn(Pb);
    }
    PressEnterToContinue();
    
    
    printf("████████ PolynLength \n");
    {
        printf("█ La 的项数为 %d ，Lb 的项数为 %d\n", PolynLength(Pa), PolynLength(Pb));
    }
    PressEnterToContinue();

    
    printf("████████ AddPolyn \n");
    {
        CreatPolyn("TestData_Pa.txt", &Pa, m);
        CreatPolyn("TestData_Pb.txt", &Pb, n);
        
        AddPolyn(&Pa, &Pb);
        
        printf("█ Pa = Pa + Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue();
    
    
    printf("████████ SubtractPolyn \n");
    {
        CreatPolyn("TestData_Pa.txt", &Pa, m);
        CreatPolyn("TestData_Pb.txt", &Pb, n);

        SubtractPolyn(&Pa, &Pb);

        printf("█ Pa = Pa - Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue();

    
    printf("████████ MultiplyPolyn \n");
    {
        CreatPolyn("TestData_Pa.txt", &Pa, m);
        CreatPolyn("TestData_Pb.txt", &Pb, n);

        MultiplyPolyn(&Pa, &Pb);

        printf("█ Pa = Pa * Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue();
    
    return 0;
}

