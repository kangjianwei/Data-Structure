/*===========================================
 * ������
 *
 * �����㷨: 4.9��4.10��4.11��4.12��4.13��4.14
 ============================================*/

#ifndef WORDLIST_H
#define WORDLIST_H

#include <stdio.h>      // �ṩfopen��fclose��feof��fgetsԭ��
#include <stdlib.h>     // �ṩexit��strtolԭ��
#include <string.h>     // �ṩstrlen��strcmpi��strlwrԭ��
#include "Status.h"     //**��01 ����**//
#include "ELinkList.h"  //**��02 ���Ա�**//
#include "HString.h"    //**��04 ��**//

/* �궨�� */
#define MaxBookNum 1000     // ����������Ŀ�����������ֻ��1000���齨������
#define MaxKeyNum  2500     // �������������(���������������ֵ)
#define MaxLineLen 500      // ��Ŀ��(��)����󳤶�
#define MaxWordNum 100      // �ʱ���������

/* ���Ͷ��� */

// ��������
typedef Status Boolean;

// �ʱ�����(˳���)
typedef struct {
    char* item[MaxWordNum];  // �ʱ���
    int last;                // �ʱ�ĳ���
} WordListType;

// ���������ͣ���������У�
typedef struct {
    HString key;        // �ؼ���
    ELinkList bnolist;  // ����������������
} IdxTermType;

/*
 * ����������
 *
 *��ע��
 * 0�ŵ�Ԫ�洢��ͷ��Ϣ����һ����̲�������ͬ
 */
typedef struct {
    IdxTermType item[MaxKeyNum + 1];    // ������ļ���
    int last;                           // �������а�������������Ŀ
} IdxListType;

/* ȫ�ֱ�������������ǰ�涼����g��ǣ� */

// ��Ŀ������
static char gBuf[MaxLineLen];

// �ؼ��ʴʱ�(��ͨ�ʱ�)���Ѿ��ų��˳��ô�
static WordListType gWdList;


/*
 * ���������������� �㷨4.9 ����������������
 *
 * ���ļ�bookinfo�ж�ȡ��Ŀ��Ϣ�������˴�����Ӧ�Ĺؼ���������Ȼ��������д���ļ�bookidx��
 */
void Main(char* bookinfo, char* bookidx);

/*
 * ��ʼ��������
 *
 *��ע��
 * �̲��н��������ͷ��Ϊ�մ����������趨��һ��������ı�ͷ
 */
void InitIdxList(IdxListType* idxlist);

/*
 * ���ļ�f�ж�ȡһ����Ŀ��Ϣ������Ŀ������gBuf��
 */
void GetLine(FILE* f);

/*
 * �ӻ�����gBuf����ȡ�����ؼ��ʵ��ʱ�gWdList����Ŵ���bno��
 */
void ExtractKeyWord(ElemType* bno);

/*
 * ���������������� �㷨4.10 ����������������
 *
 * �����bno��Ӧ�������ؼ��ʰ��ʵ�˳����뵽������idxlist��
 */
Status InsIdxList(IdxListType* idxlist, int bno);

/*
 * ���������������� �㷨4.11 ����������������
 *
 * ��wd���شʱ�gWdList�е�i���ؼ��ʡ�
 */
void GetWord(int i, HString* wd);

/*
 * ���������������� �㷨4.12 ����������������
 *
 * ��ѯ��������idxlist���Ƿ������wd��ȵĹؼ��ʡ�
 * �����ڣ��򷵻�wd�ڴʱ��е�λ�ã�����bΪTRUE��
 * �������ڣ��򷵻�wdӦ�����λ�ã�����bΪFALSE��
 */
int Locate(IdxListType idxlist, HString wd, Boolean* b);

/*
 * ���������������� �㷨4.13 ����������������
 *
 * �������������i(>=0)������ؼ���wd������ʼ���������������Ϊ�ձ�
 */
void InsertNewKey(IdxListType* idxlist, int i, HString wd);

/*
 * ���������������� �㷨4.14 ����������������
 *
 * Ϊ������������i(>0)���Ĺؼ��ʲ�����š�
 */
Status InsertBook(IdxListType* idxlist, int i, int bno);

/*
 * �����ɵ�������idxlist������ļ�g��
 */
void PutText(FILE* g, IdxListType idxlist);

// �ж�str�Ƿ�Ϊ���ô�
static Status isCommonWords(char* str);

#endif
