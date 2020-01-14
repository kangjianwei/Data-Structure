#include <stdio.h>
#include <string.h>
#include <stdarg.h> // 提供宏va_list、va_start、va_arg、va_end
#include <ctype.h>  // 提供isprint原型

/*
 * 这是自定义的数据录入函数，用于从文件fp中读取格式化的输入
 * 与fscanf不同之处在于此函数只会读取西文字符，对于中文字符，则会跳过
 *
 * 注：
 * 1. 这里约定所有格式串为简单形式，如：%d%c%s等，而不是%2d%5s等
 * 2. 读取字符串时，遇到空格或非打印字符会停止读取
 */
int ReadData(FILE* fp, char* format, ...) {
    int* i;     // 存储读取到的整型
    float* f;   // 存储读取到的浮点型
    char* ch;   // 存储读取到的字符型
    char* s;    // 存储读取到的字符串型
    
    int n;      // 遍历存储字符串的字符数组
    
    int len;    // 格式串format的长度
    int k;      // 遍历格式串时的游标
    
    int tmp;    // 暂存从文件中读取到的字符
    
    va_list ap; // 可变参数指针，指向存储数据的变量
    
    // 累计成功读取到的字符数
    int count = 0;
    
    
    /*
     * 获取格式串的长度
     * 这里预设格式串仅由简单
     */
    len = strlen(format);
    
    // ap指向首个可变参数
    va_start(ap, format);
    
    // 只遍历奇数索引，因为偶数索引下都是%
    for(k = 1; k <= len; k = k + 2) {
        // 跳过所有非西文字符
        while((tmp = getc(fp)) != EOF) {
            // 遇到首个西文字符，将此西文字符重新放入输入流
            if((tmp >= 0 && tmp <= 127)) {
                ungetc(tmp, fp);
                break;
            }
        }
        
        // 如果已读到文件结尾，结束读取
        if(tmp == EOF) {
            break;
        }
        
        // 遇到了"%c"，应该读取字符
        if(format[k] == 'c') {
            ch = va_arg(ap, char*);
            
            count += fscanf(fp, "%c", ch);
        }
        
        // 遇到了"%d"，应该读取整型
        if(format[k] == 'd') {
            i = va_arg(ap, int*);
            
            while((tmp = getc(fp)) != EOF) {
                // 寻找整数区域
                if((tmp >= '0' && tmp <= '9') || tmp == '-' || tmp == '+') {
                    ungetc(tmp, fp);
                    break;
                }
            }
            
            if(tmp != EOF) {
                count += fscanf(fp, "%d", i);
            }
        }
        
        // 读取浮点型，一律存储为double类型
        if(format[k] == 'f') {
            f = va_arg(ap, float*);
            
            while((tmp = getc(fp)) != EOF) {
                if((tmp >= '0' && tmp <= '9') || tmp == '-' || tmp == '+' || tmp == '.') {
                    ungetc(tmp, fp);
                    break;
                }
            }
            
            if(tmp != EOF) {
                count += fscanf(fp, "%f", f);
            }
        }
        
        // 读取字符串
        if(format[k] == 's') {
            s = va_arg(ap, char*);
            
            n = 0;
            
            // 查找排除空格的可打印字符
            while((tmp = getc(fp)) != EOF && (!isprint(tmp) || tmp == ' ')) {
            }
            
            // 如果未到文件结尾
            if(!feof(fp)) {
                
                // 将上面读到的字符重新放入流中
                ungetc(tmp, fp);
                
                while((tmp = getc(fp)) != EOF) {
                    // 存储排除空格的可打印字符
                    if(isprint(tmp) && tmp != ' ') {
                        s[n++] = tmp;
                    } else {
                        ungetc(tmp, fp);
                        break;
                    }
                }
                
                count++;
            }
            
            // 字符串最后一个字符为空字符
            s[n] = '\0';
        }
    }// for
    
    va_end(ap);
    
    return count;
}

// 摁下回车键以继续运行
void PressEnterToContinue() {
    int debug = 1;
    
    fflush(stdin);
    
    printf("\nPress Enter to Continue...");
    
    // 处于测试阶段时，可以让debug=1，自动添加换行，便于测试
    if(debug) {
        printf("\n");
        
        // 发布时，可以让debug=0，手动输入换行，否则让程序暂停下来，观察每一步的输出
    } else {
        getchar();
    }
    
    fflush(stdin);
}

// 函数暂停一段时间，time不代表具体的时间
void Wait(long time) {
    double i;
    
    for(i = 0.01; i <= 100000.0 * time; i += 0.01) {
        // 空循环
    }
}

// 跳过输入端的行分割符，如'\r'、'\n'、'\r\n'
void skipLineSeparator(FILE* fp) {
    int ch;
    
    if(fp == NULL) {
        return;
    }
    
    while((ch = getc(fp)) != EOF) {
        if(ch >= 0 && ch <= 127 && ch != '\r' && ch != '\n') {
            ungetc(ch, fp);
            break;
        }
    }
}
