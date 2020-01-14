#include <stdio.h>
#include "MPList.h" //**▲05 数组和广义表**//

int main(int argc, char** argv) {
    MPList P;
    char *s = "z((2,y((3,x((10,1),(6,2))),(2,x((5,3))))),(1,y((4,x((4,1),(3,6))),(1,x((0,2))))),(0,5))";

    printf("创建三元多项式...\n");
    CreateMPList(&P, s, "zxy");
    PrintMPList(P);
}

