#include <stdio.h>         // �ṩsystemԭ��
#include "WordList.h"       //**��04 ��**//

int main(int argc, char** argv) {
    FILE* fp;
    char line[MaxLineLen];
    
    char* bookinfo = "TestData.txt";    // ��Ŀ�ļ���
    char* bookidx  = "BookIdx.txt";     // �ؼ��������ļ���
    
    // ����������
    Main(bookinfo, bookidx);
    
    // ��ʾ��������Ļ
    if((fp = fopen(bookidx, "r"))!=NULL) {
        printf("---------���������ɹ���---------\n\n");
    
        while(feof(fp)==FALSE) {
            fgets(line, MaxLineLen, fp);
            printf("%s", line);
        }
    } else {
        printf("---------δ����������---------\n");
    }
    
    return 0;
}
