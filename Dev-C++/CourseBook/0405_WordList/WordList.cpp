/*===========================================
 * ������
 *
 * �����㷨: 4.9��4.10��4.11��4.12��4.13��4.14
 ============================================*/

#include "WordList.h"   //**��04 ��**//

/*
 * ���������������� �㷨4.9 ����������������
 *
 * ���ļ�bookinfo�ж�ȡ��Ŀ��Ϣ�������˴�����Ӧ�Ĺؼ���������Ȼ��������д���ļ�bookidx��
 */
void Main(char* bookinfo, char* bookidx) {
    FILE* f, * g;
    char head[MaxLineLen];      // ��Ŀ�ı�ͷ��Ϣ��δʹ�ã�
    IdxListType idxlist;        // �ؼ���������
    ElemType bno;               // ���
    int count;
    
    // �ԡ�ֻ����ģʽ����Ŀ�ļ�
    if((f = fopen(bookinfo, "r")) != NULL) {
        
        // �ԡ�ֻд��ģʽ�������ļ�
        if((g = fopen(bookidx, "w")) != NULL) {
            
            // ��ʼ��������
            InitIdxList(&idxlist);
            
            // �����ļ���һ��
            fgets(head, MaxLineLen, f);
            
            count = 0;
            
            // ���δ���ļ���β����һֱ���ļ�
            while(feof(f) == FALSE && count < MaxBookNum) {
                
                // ���ļ�f����һ����Ŀ��Ϣ����Ŀ������gBuf
                GetLine(f);
                
                // ��gBuf��ȡ�ؼ��ʵ��ʱ�gWdList����Ŵ���bno
                ExtractKeyWord(&bno);
                
                // ����ż���Ӧ�Ĺؼ��ʲ���������idxlist
                InsIdxList(&idxlist, bno);
                
                count++;
            }
            
            // ���ļ�g��д������������
            PutText(g, idxlist);
            
            fclose(g);
        }
        
        fclose(f);
    }
}

/*
 * ��ʼ��������
 *
 *��ע��
 * �̲��н��������ͷ��Ϊ�մ����������趨��һ��������ı�ͷ
 */
void InitIdxList(IdxListType* idxlist) {
    // ������ı�ͷ��Ϣ
    char* chars = "�ؼ���            �������";
    IdxTermType e;
    
    // ��ʼ����ͷ��Ϣ
    StrAssign(&(e.key), chars);
    
    // ��ʼ�������������
    InitList(&(e.bnolist));
    
    (*idxlist).item[0] = e;
    
    // ��ͷΪ��0����Ϣ
    (*idxlist).last = 0;
}

/*
 * ���ļ�f�ж�ȡһ����Ŀ��Ϣ������Ŀ������gBuf��
 */
void GetLine(FILE* f) {
    // ��ȡһ�����ݣ����뻺����gBuf
    fgets(gBuf, MaxLineLen, f);
}

/*
 * �ӻ�����gBuf����ȡ�����ؼ��ʵ��ʱ�gWdList����Ŵ���bno��
 */
void ExtractKeyWord(ElemType* bno) {
    char delim[] = {'-', ' ', '\r', '\n', '\t'};  // �ָ���
    char* title;    // ����
    char* token;    // �������зֽ���Ĺؼ���
    
    // �ֽ���Ŀ�ַ���������Ŵ���bno(ʮ����)������titleָ��ʣ�µ��ַ���(����)
    *bno = (int) strtol(gBuf, &title, 10);
    
    // ���������ɴ�д��Сд
    strlwr(title);
    
    // ��չؼ��ʴʱ�
    gWdList.last = 0;
    
    // �ֽ�ؼ���
    for(token = strtok(title, delim); token != NULL; token = strtok(NULL, delim)) {
        // ����ùؼ����ǳ��ôʣ��������
        if(isCommonWords(token) == TRUE) {
            continue;
        }
        
        // ���´���������ȡ�Ĺؼ���
        gWdList.item[gWdList.last++] = token;
    }
}

/*
 * ���������������� �㷨4.10 ����������������
 *
 * �����bno��Ӧ�������еĹؼ��ʰ��ʵ�˳����뵽������idxlist��
 */
Status InsIdxList(IdxListType* idxlist, int bno) {
    int i, j;
    Boolean boo;
    HString wd;
    
    if(gWdList.last <= 0) {
        return ERROR;
    }
    
    // �������bno��Ӧ�������е����йؼ���
    for(i = 0; i < gWdList.last; i++) {
        // ��ȡ������Ĺؼ���
        GetWord(i, &wd);
        
        // �жϸùؼ����Ƿ��Ѿ�λ����������
        j = Locate(*idxlist, wd, &boo);
        
        // ����ùؼ��ʲ����������У�����Ҫ����ؼ���
        if(boo == FALSE) {
            // ���ؼ���wd���뵽������
            InsertNewKey(idxlist, j, wd);
        }
        
        // �ڹؼ����Ѵ��ڵ������£��������
        if(!InsertBook(idxlist, j, bno)) {
            return ERROR;
        }
    }
    
    return OK;
}

/*
 * ���������������� �㷨4.11 ����������������
 *
 * ��wd���شʱ�gWdList�е�i���ؼ��ʡ�
 */
void GetWord(int i, HString* wd) {
    if(i < 0 || i > gWdList.last - 1) {
        StrAssign(wd, "");
    } else {
        StrAssign(wd, gWdList.item[i]);
    }
}

/*
 * ���������������� �㷨4.12 ����������������
 *
 * ��ѯ��������idxlist���Ƿ������wd��ȵĹؼ��ʡ�
 * �����ڣ��򷵻�wd�ڴʱ��е�λ�ã�����bΪTRUE��
 * �������ڣ��򷵻�wdӦ�����λ�ã�����bΪFALSE��
 */
int Locate(IdxListType idxlist, HString wd, Boolean* b) {
    int i, m = -1;
    
    /*
     * ��������idxlist�в��ҹؼ���wd�Ƿ����
     * ע��0�ŵ�Ԫ�洢�˱�ͷ��Ϣ
     */
    for(i = idxlist.last; i > 0 && (m = StrCompare(idxlist.item[i].key, wd)) > 0; i--) {
    }
    
    // ����ҵ��˹ؼ���wd
    if(m == 0) {
        *b = TRUE;
        return i;
    } else {
        *b = FALSE;
        return i + 1;
    }
}

/*
 * ���������������� �㷨4.13 ����������������
 *
 * �������������i(>=0)������ؼ���wd������ʼ���������������Ϊ�ձ�
 */
void InsertNewKey(IdxListType* idxlist, int i, HString wd) {
    int j;
    
    /*
     * ���������
     * ע��0�ŵ�Ԫ�洢�˱�ͷ��Ϣ
     */
    for(j = (*idxlist).last; j >= i; j--) {
        (*idxlist).item[j + 1] = (*idxlist).item[j];
    }
    
    // ����������
    StrCopy(&((*idxlist).item[i].key), wd);
    
    // ��ʼ�������������
    InitList(&((*idxlist).item[i].bnolist));
    
    // ������Ŀ��һ
    (*idxlist).last++;
}

/*
 * ���������������� �㷨4.14 ����������������
 *
 * Ϊ������������i(>0)���Ĺؼ��ʲ�����š�
 */
Status InsertBook(IdxListType* idxlist, int i, ElemType bno) {
    Link p;
    
    // �ڴ����ʧ��
    if(MakeNode(&p, bno) == FALSE) {
        return ERROR;
    }
    
    // �����µ��������
    Append(&((*idxlist).item[i].bnolist), p);
    
    return OK;
}

/*
 * �����ɵ�������idxlist������ļ�g��
 */
void PutText(FILE* g, IdxListType idxlist) {
    int i, j, m, n;
    Link p;
    HString S;
    ELinkList L;
    
    if(idxlist.last <= 0) {
        return;
    }
    
    // �������ͷ��Ϣ
    S = idxlist.item[0].key;
    for(m = 0; m < S.length; m++) {
        fprintf(g, "%c", S.ch[m]);
    }
    fprintf(g, "\n");
    
    // ���������Ϣ
    for(i = 1; i <= idxlist.last; i++) {
        // 1.����ؼ���
        S = idxlist.item[i].key;
        for(m = 0; m < S.length; m++) {
            fprintf(g, "%c", S.ch[m]);
        }
        
        // 2.����ո�
        for(j = 1; j <= 18 - idxlist.item[i].key.length; j++) {
            fprintf(g, " ");
        }
        
        // 3.����������
        L = idxlist.item[i].bnolist;
        for(n = 1, p = L.head->next; n <= L.len; n++) {
            fprintf(g, "%03d", p->data);
            p = p->next;
            if(p) {
                fprintf(g, "��");
            }
        }
        
        // 4.�������
        fprintf(g, "\n");
    }
    
}

// �ж�str�Ƿ�Ϊ���ô�
static Status isCommonWords(char* str) {
    int i;
    
    // ���ôʴʱ���Щ�ʻ�ᱻ�ų��ڹؼ���֮��
    WordListType words = {{"a", "an", "the", "of", "and", "is", "to", "as", "in", "for"}, 10};
    
    // ��ѯ���ôʴʱ�
    for(i = 0; i < words.last; i++) {
        // �����ַ������к��Դ�Сд�ıȽ�
        if(strcmpi(str, words.item[i]) == 0) {
            // ������ַ����ǳ��ôʣ��򷵻�TRUE
            return TRUE;
        }
    }
    
    return FALSE;
}
