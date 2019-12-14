/*=============================
 * ���Ķ���˳��洢��ʾ��˳�򴮣�
 *
 * �����㷨: 4.1��4.2��4.3��4.5
 ==============================*/

#include "SString.h"    //**��04 ��**//

/*
 * ��ʼ��
 *
 * ����һ��ֵΪchars�Ĵ�T��
 *
 *��ע��
 * �ò���������С�����Ӽ�
 */
Status StrAssign(SString T, const char* chars) {
    int i, len;
    
    len = (int) strlen(chars);
    
    // chars����
    if(len > MAXSTRLEN) {
        return ERROR;
    }
    
    T[0] = len;
    for(i = 1; i <= len; i++) {
        T[i] = chars[i - 1];
    }
    
    return OK;
}
