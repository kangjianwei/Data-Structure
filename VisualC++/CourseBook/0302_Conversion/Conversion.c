/*==============
 * 进制转换
 *
 * 包含算法: 3.1
 ===============*/

#include "Conversion.h"                    //**▲03 栈和队列**//

/*
 * ████████ 算法3.1 ████████
 *
 * 进制转换：将指定的非负十进制整数，转换为八进制后输出。
 *
 *【注】
 * 教材使用的是控制台输入，这里为了便于测试，直接改为从形参接收参数
 */
void conversion(int i) {
    SqStack S;
    SElemType e;
    
    InitStack(&S);
    
    // 八进制数前面加0
    printf("十进制数 %d 转换为八进制数后为：0", i);
    
    while(i!=0) {
        Push(&S, i % 8);    // 进栈时从低位到高位
        i = i / 8;
    }
    
    while(StackEmpty(S)==FALSE) {
        Pop(&S, &e);        // 出栈时从高位到低位
        printf("%d", e);
    }

	printf("\n");
}
