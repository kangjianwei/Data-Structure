#include <stdio.h>
#include "LineEdit.h"                    //**��03 ջ�Ͷ���**//

int main(int argc, char* argv[]) {
    char* buf = "whli##ilr#e(s#*s)\noutcha@    putchar(*s=#++);";   //��Ҫ¼�������
    
    printf("��Ϊʾ�����û�������ı�����Ϊ��\n");
    printf("%s\n\n", buf);
    
    printf("�����б༭����...\n\n");
    
    printf("������ţ�'#' ����ɾ����һԪ�ء�'@' ����ɾ����ǰ������\n");
    printf("         '\\n'���������������'\\0'�����������\n");
    printf("���մ洢������Ϊ��\n");
    LineEdit(buf);
    
    return 0;
}
