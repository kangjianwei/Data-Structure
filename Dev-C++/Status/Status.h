/*
 * 注：
 * 本次修订的目的包括降低耦合，争取每个模块都可以单独运行
 * 但是Status这个模块会被所有其他模块引用，引用次数很多。
 * 如果直接将Status模块复制到其它模块中，则会导致太多重复代码，
 * 因此这里生成一个公共静态库让其它模块共享比较划算
 */

#ifndef STATUS_H
#define STATUS_H

#include <stdio.h>

/* 状态码 */
#define TRUE        1   // 真/是
#define FALSE       0   // 假/否
#define OK          1   // 通过/成功
#define ERROR       0   // 错误/失败

//系统中已有此状态码定义，要防止冲突
#ifndef OVERFLOW
#define OVERFLOW    -2  //堆栈上溢
#endif

//系统中已有此状态码定义，要防止冲突
#ifndef NULL
#define NULL ((void*)0)
#endif

/* 状态码类型 */
typedef int Status;

/* 布尔类型 */
typedef int Boolean;


/* 全局变量*/
extern Boolean debug;   // 是否使用debug模式


/*
 * 从文件中读取预设的英文符号
 *
 * 这是自定义的数据录入函数，用于从文件fp中读取格式化的输入，
 * 与fscanf的不同之处在于此函数只会读取英文字符，对于中文字符，则直接跳过。
 *
 * 注：
 * 1. 这里约定所有格式串为简单形式，如：%d%c%s等，而不是%2d%5s等
 * 2. 读取字符串时，遇到空格或非打印字符会停止读取
 */
int ReadData(FILE* fp, char* format, ...);

/*
 * 摁下回车键以继续运行。
 *
 * 通常在测试阶段时，需要让每一步测试都暂停下来，以观察其输出，此时可以让debug=TRUE。
 * 在发布时，可以让debug=FALSE，此时各个测试块将不会暂停。
 */
void PressEnterToContinue(Boolean debug);

/*
 * 函数暂停一段时间。
 *
 * time不代表具体的时间，只是代表一段时间间隔，
 * 通过调节time的大小，可以使程序暂停适当的时间后继续运行。
 */
void Wait(long time);

/*
 * 跳过空白，寻找下一个"可读"符号。
 *
 * 此方法常用在读取字符的语句之前，这会跳过遇到目标字符之前的空白符号，
 * 比如跳过'\r'、'\n'、'\r\n'、' '、'\t'、'\f'。
 */
void skipBlank(FILE* fp);

#endif

