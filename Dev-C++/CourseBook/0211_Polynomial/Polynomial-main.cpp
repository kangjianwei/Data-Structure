#include "Polynomial.h"         //**▲02 线性表**//

int main(int argc, char **argv) {
    Polynomial Pa, Pb;
    int m, n;

    m = 5;
    n = 6;

    printf("████████ CreatPolyn \n");
    {
        printf("█ 作为示范，创建项数为 %d 的多项式Pa...\n", m);
        CreatPolyn(&Pa, m, "TestData_Pa.txt");

        printf("█ 作为示范，创建项数为 %d 的多项式Pb...\n", n);
        CreatPolyn(&Pb, n, "TestData_Pb.txt");
    }
    PressEnterToContinue(debug);


    printf("████████ PrintPolyn \n");
    {
        printf("█ 一元多项式 Pa = ");
        PrintPolyn(Pa);

        printf("█ 一元多项式 Pb = ");
        PrintPolyn(Pb);
    }
    PressEnterToContinue(debug);


    printf("████████ PolynLength \n");
    {
        printf("█ La 的项数为 %d ，Lb 的项数为 %d\n", PolynLength(Pa), PolynLength(Pb));
    }
    PressEnterToContinue(debug);


    printf("████████ AddPolyn \n");
    {
        CreatPolyn(&Pa, m, "TestData_Pa.txt");
        CreatPolyn(&Pb, n, "TestData_Pb.txt");

        AddPolyn(&Pa, &Pb);

        printf("█ Pa = Pa + Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue(debug);


    printf("████████ SubtractPolyn \n");
    {
        CreatPolyn(&Pa, m, "TestData_Pa.txt");
        CreatPolyn(&Pb, n, "TestData_Pb.txt");

        SubtractPolyn(&Pa, &Pb);

        printf("█ Pa = Pa - Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue(debug);


    printf("████████ MultiplyPolyn \n");
    {
        CreatPolyn(&Pa, m, "TestData_Pa.txt");
        CreatPolyn(&Pb, n, "TestData_Pb.txt");

        MultiplyPolyn(&Pa, &Pb);

        printf("█ Pa = Pa * Pb = ");
        PrintPolyn(Pa);
    }
    PressEnterToContinue(debug);

    return 0;
}

