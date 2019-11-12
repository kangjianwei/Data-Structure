#include <stdio.h>
#include <stdlib.h>
#include "SString.h"    //**▲04 串**//

/*
 * 统计字符串S中不同字符总数与每种字符的个数，返回统计结果
 */
int* Algo_4_18(SString S);


int main(int argc, char* argv[]) {
    char* s = "dbasydujhge638940[gptokljrsehgadcsbnmv,c.b'ng[p098437eywdghswqdecxvghju";
    SString S;
    int* total;
    int i;
    
    StrAssign(S, s);
    printf("S = ");
    StrPrint(S);
    
    total = Algo_4_18(S);
    printf(" S 中不同的字符共计 %d 个：\n", total[0]);
    for(i = 1; i <= 127; i++) {
        if(total[i] != 0) {
            printf("字符 \'%c\' 有 %d 个.\n", i, total[i]);
        }
    }
    printf("统计完毕...\n");
    
    return 0;
}


/*
 * 统计字符串S中不同字符总数与每种字符的个数，返回统计结果
 */
int* Algo_4_18(SString S) {
    int i;
    int* total;
    
    /*
     * total长度设为128，
     * 0号单元存储不同字符的总数，
     * 其他单元存储各种不同字符的数量。
     *
     * 注：不统计空字符'\0'
     */
    total = (int*) malloc(128 * sizeof(int));
    memset(total, 0, 128 * sizeof(int));
    
    for(i = 1; i <= S[0]; i++) {
        // 如果遇到了新字符，则统计不同字符的数量
        if(total[S[i]] == 0) {
            total[0]++;
        }
        
        // 统计遇到的字符数量
        total[S[i]]++;
    }
    
    return total;
}
