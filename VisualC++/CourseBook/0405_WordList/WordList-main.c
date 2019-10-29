#include <stdio.h>         // 提供system原型
#include "WordList.h"       //**▲04 串**//

int main(int argc, char** argv) {
    FILE* fp;
    char line[MaxLineLen];
    
    char* bookinfo = "TestData.txt";    // 书目文件名
    char* bookidx  = "BookIdx.txt";     // 关键词索引文件名
    
    // 创建索引表
    Main(bookinfo, bookidx);
    
    // 显示索引表到屏幕
    if((fp = fopen(bookidx, "r"))!=NULL) {
        printf("---------索引表生成功！---------\n\n");
    
        while(feof(fp)==FALSE) {
            fgets(line, MaxLineLen, fp);
            printf("%s", line);
        }
    } else {
        printf("---------未发现索引表！---------\n");
    }
    
    return 0;
}
