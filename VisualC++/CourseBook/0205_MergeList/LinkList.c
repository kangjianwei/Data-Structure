/*===============================
 * ���Ա����ʽ�洢�ṹ������
 *
 * �����㷨: 2.8��2.9��2.10��2.11
 ================================*/

#include "LinkList.h"   //**��02 ���Ա�**//

/*
 * ����
 *
 * ��visit������������L
 */
void ListTraverse(LinkList L, void(Visit)(ElemType)) {
    LinkList p;
    
    // ȷ���������
    if(L == NULL || L->next == NULL) {
        return;
    }
    
    p = L->next;
    
    while(p != NULL) {
        Visit(p->data);
        p = p->next;
    }
    
    printf("\n");
}

/*
 * ���������������� �㷨2.11 ����������������
 *
 * ͷ�巨��������
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����Ϊ�մ���
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
Status CreateList_Head(LinkList* L, int n, char* path) {
    int i;
    LinkList p;
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
        
        printf("������%d������Ԫ�أ�", n);
        
        for(i = 1; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));
            
            // ������ݣ������뵽������
            scanf("%d", &(p->data));
            
            p->next = (*L)->next;
            (*L)->next = p;
        }
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        
        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
        
        for(i = 1; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));
            
            // ������ݣ������뵽������
            ReadData(fp, "%d", &(p->data));
            
            p->next = (*L)->next;
            (*L)->next = p;
        }
        
        fclose(fp);
    }
    
    return OK;
}

/*
 * β�巨��������
 *
 *
 *����ע��
 *
 * �̲���Ĭ�ϴӿ���̨��ȡ���ݡ�
 * ����Ϊ�˷�����ԣ�����ÿ�����ж��ֶ��������ݣ�
 * �������ѡ���Ԥ����ļ�path�ж�ȡ�������ݡ�
 *
 * �����Ҫ�ӿ���̨��ȡ���ݣ���pathΪNULL����Ϊ�մ���
 * �����Ҫ���ļ��ж�ȡ���ݣ�����Ҫ��path����д�ļ�����Ϣ��
 */
Status CreateList_Tail(LinkList* L, int n, char* path) {
    int i;
    LinkList p, q;
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
        
        printf("������%d������Ԫ�أ�", n);
        
        for(i = 1, q = *L; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));
            
            // ������ݣ������뵽������
            scanf("%d", &(p->data));
            
            q->next = p;
            q = q->next;
        }
        
        q->next = NULL;
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        
        // ����ͷ���
        *L = (LinkList) malloc(sizeof(LNode));
        (*L)->next = NULL;
        
        for(i = 1, q = *L; i <= n; ++i) {
            // �����½��
            p = (LinkList) malloc(sizeof(LNode));
            
            // ������ݣ������뵽������
            ReadData(fp, "%d", &(p->data));
            
            q->next = p;
            q = q->next;
        }
        
        q->next = NULL;
        
        fclose(fp);
    }
    
    return OK;
}
