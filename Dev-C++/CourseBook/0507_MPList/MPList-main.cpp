#include <stdio.h>
#include "MPList.h" //**��05 ����͹����**//

int main(int argc, char** argv) {
    MPList P;
    char *s = "z((2,y((3,x((10,1),(6,2))),(2,x((5,3))))),(1,y((4,x((4,1),(3,6))),(1,x((0,2))))),(0,5))";

    printf("������Ԫ����ʽ...\n");
    CreateMPList(&P, s, "zxy");
    PrintGraph(P);
}

