/*==================
 * ������˳��洢�ṹ
 ===================*/

#include "SqBiTree.h"   //**��06 ���Ͷ�����**//

/*
 * ��ʼ��
 *
 * ����ն�������
 */
Status InitBiTree(SqBiTree T) {
    // ʹ�ÿ��ַ�����������˳��ṹ
    memset(T, '\0', sizeof(SqBiTree));
    
    return OK;
}

/*
 * ����
 *
 * �ͷŶ�������ռ�ڴ档
 *
 *��ע��
 * ��������˳��洢�ṹ�޷����١�
 */
Status DestroyBiTree(SqBiTree T) {
    // ��������˳��洢�ṹ�޷�����
    return ERROR;
}

/*
 * �ÿ�
 *
 * ����������е����ݣ�ʹ���Ϊ������
 */
Status ClearBiTree(SqBiTree T) {
    // ʹ�ÿ��ַ�����������˳��ṹ
    memset(T, '\0', sizeof(SqBiTree));
    
    return OK;
}

/*
 * ����
 *
 * ����Ԥ��Ķ�����������������
 * ����Լ��ʹ�á��������С���������������
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
Status CreateBiTree(SqBiTree T, char* path) {
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����
    
    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;
    
    if(readFromConsole) {
        printf("��������������������У����û���ӽ�㣬ʹ��^���棺");
        CreateTree(T, 0, NULL);
    } else {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            return ERROR;
        }
        CreateTree(T, 0, fp);
        fclose(fp);
    }
    
    return OK;
}

/*
 * �п�
 *
 * �ж϶������Ƿ�Ϊ������
 */
Status BiTreeEmpty(SqBiTree T) {
    return T[0] == '\0' ? TRUE : FALSE;
}

/*
 * ����
 *
 * ���ض���������ȣ���������
 */
int BiTreeDepth(SqBiTree T) {
    return TreeDepth(T, 0);
}

/*
 * ȡֵ
 *
 * ���ض�������ָ������ֵ��
 */
TElemType Value(SqBiTree T, TElemType e) {
    int index;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e������
    index = EIndex(T, e, 0);
    
    // ���û���ҵ�Ԫ��e
    if(index == -1) {
        return '\0';
    } else {
        return T[index];
    }
}

/*
 * ��ֵ
 *
 * Ϊ������ָ���Ľ�㸳ֵ��
 */
Status Assign(SqBiTree T, TElemType e, TElemType value) {
    int index;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return ERROR;
    }
    
    // ��ȡ���e������
    index = EIndex(T, e, 0);
    
    // ���û���ҵ�Ԫ��e
    if(index == -1) {
        return ERROR;
    } else {
        // ���и�ֵ
        T[index] = value;
        return OK;
    }
}

/*
 * ��
 *
 * ���ض������ĸ���㡣
 */
TElemType Root(SqBiTree T) {
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    return T[0];
}

/*
 * ˫��
 *
 * ���ض������н��e��˫�׽�㡣
 */
TElemType Parent(SqBiTree T, TElemType e) {
    int index;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e������
    index = EIndex(T, e, 0);
    
    // ���û���ҵ�Ԫ��e
    if(index == -1) {
        return '\0';
        
        // ���e�Ǹ����
    } else if(index == 0) {
        return '\0';
    } else {
        // ���ظ����
        return T[(index - 1) / 2];
    }
}

/*
 * ����
 *
 * ���ض������н��e�����ӽ�㡣
 */
TElemType LeftChild(SqBiTree T, TElemType e) {
    int index;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e������
    index = EIndex(T, e, 0);
    
    // ���û���ҵ�Ԫ��e
    if(index == -1) {
        return '\0';
    } else {
        // ��������
        return T[2 * index + 1];
    }
}

/*
 * �Һ���
 *
 * ���ض������н��e���Һ��ӽ�㡣
 */
TElemType RightChild(SqBiTree T, TElemType e) {
    int index;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e������
    index = EIndex(T, e, 0);
    
    // ���û���ҵ�Ԫ��e
    if(index == -1) {
        return '\0';
    } else {
        // �����Һ���
        return T[2 * index + 2];
    }
}

/*
 * ���ֵ�
 *
 * ���ض������н��e�����ֵܽ�㡣
 */
TElemType LeftSibling(SqBiTree T, TElemType e) {
    int index, p;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e������
    index = EIndex(T, e, 0);
    
    // ���û���ҵ�Ԫ��e
    if(index == -1) {
        return '\0';
        
        // ���e�Ǹ����
    } else if(index == 0) {
        return '\0';
    } else {
        // ��ȡ����������
        p = (index - 1) / 2;
        
        // ������e���Һ��ӣ��򷵻������ֵ�
        if(T[2 * p + 2] == e) {
            return T[2 * p + 1];
        } else {
            return '\0';
        }
    }
}

/*
 * ���ֵ�
 *
 * ���ض������н��e�����ֵܽ�㡣
 */
TElemType RightSibling(SqBiTree T, TElemType e) {
    int index, p;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        return '\0';
    }
    
    // ��ȡ���e������
    index = EIndex(T, e, 0);
    
    // ���û���ҵ�Ԫ��e
    if(index == -1) {
        return '\0';
        
        // ���e�Ǹ����
    } else if(index == 0) {
        return '\0';
    } else {
        // ��ȡ����������
        p = (index - 1) / 2;
        
        // ������e�����ӣ��򷵻������ֵ�
        if(T[2 * p + 1] == e) {
            return T[2 * p + 2];
        } else {
            return '\0';
        }
    }
}

/*
 * ����
 *
 * ��֪cΪ��T���ཻ�ķǿն���������c��������Ϊ�գ�
 * ����LR��ȡֵ(0��1)����c����ΪT�н��p��������/��������
 * ���ң���p���ԭ�е�������/�������޽�Ϊ������c����������
 */
Status InsertChild(SqBiTree T, TElemType p, int LR, SqBiTree c) {
    int index;
    
    // ������������Ϊ�����������������
    if(BiTreeEmpty(c)) {
        return ERROR;
    }
    
    // ��ȡ���p������
    index = EIndex(T, p, 0);
    
    // ���p��㲻���ڣ��򷵻ش�����ʾ
    if(index == -1) {
        return ERROR;
    }
    
    // ��c����Ϊp��������
    if(LR==0) {
        // ���p������������
        if(T[2*index+1]!='\0') {
            // ��p������������Ϊc��������
            Transfer(T, 2*index+1, c, 2);
        }
    
        Transfer(c, 0, T, 2*index+1);
        
        // ��c����Ϊp��������
    } else {
        // ���p������������
        if(T[2*index+2]!='\0') {
            // ��p������������Ϊc��������
            Transfer(T, 2*index+2, c, 2);
        }
    
        Transfer(c, 0, T, 2*index+2);
    }
    
    return OK;
}

/*
 * ɾ��
 *
 * ����LR��ȡֵ(0��1)��ɾ�����p��������/��������
 */
Status DeleteChild(SqBiTree T, TElemType p, int LR) {
    int index;
    
    // �����ɾ������Ϊ�����������������
    if(BiTreeEmpty(T)) {
        return ERROR;
    }
    
    // ��ȡ���p������
    index = EIndex(T, p, 0);
    
    // �����ɾ����㲻���ڣ��򷵻ش�����ʾ
    if(index == -1) {
        return ERROR;
    }
    
    // �����Ҫɾ��p��������
    if(LR == 0) {
        Delete(T, 2 * index + 1);
        
        // �����Ҫɾ��p��������
    } else {
        Delete(T, 2 * index + 2);
    }
    
    return OK;
}

/*
 * �������
 */
Status PreOrderTraverse(SqBiTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = PreTraverse(T, Visit, 0);
    printf("\n");
    
    return status;
}

/*
 * �������
 */
Status InOrderTraverse(SqBiTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = InTraverse(T, Visit, 0);
    printf("\n");
    
    return status;
}

/*
 * �������
 */
Status PostOrderTraverse(SqBiTree T, Status(Visit)(TElemType)) {
    Status status;
    
    status = PostTraverse(T, Visit, 0);
    printf("\n");
    
    return status;
}

/*
 * �������
 */
Status LevelOrderTraverse(SqBiTree T, Status(Visit)(TElemType)) {
    int i;
    int deep;
    int len;
    
    // ����������
    deep = BiTreeDepth(T);
    if(deep == 0) {
        return OK;
    }
    
    // ������Ԫ�����������ֵ��
    len = (int) pow(2, deep) - 1;
    
    for(i = 0; i < len; i++) {
        if(T[i] != '\0') {
            if(!Visit(T[i])) {
                // ����������ʴ��󣬻ἴʱ����
                return ERROR;
            }
        }
    }
    
    printf("\n");
    
    return OK;
}


/*�������������������������������������������� �����ڲ�ʹ�õĺ��� ��������������������������������������������*/

// �������������ڲ�����
static void CreateTree(SqBiTree T, int i, FILE* fp) {
    char ch;
    
    // ��ȡ��ǰ����ֵ
    if(fp == NULL) {
        scanf("%c", &ch);
    } else {
        ReadData(fp, "%c", &ch);
    }
    
    if(ch == '^') {
        T[i] = '\0';
    } else {
        T[i] = ch;
        CreateTree(T, 2 * i + 1, fp); // ����������
        CreateTree(T, 2 * i + 2, fp); // ����������
    }
}

// ���������ȵ��ڲ�����
static int TreeDepth(SqBiTree T, int i) {
    int ld, rd;     // ��¼�������������
    
    if(T[i] == '\0') {
        return 0;
    } else {
        ld = TreeDepth(T, 2 * i + 1);
        rd = TreeDepth(T, 2 * i + 2);
        
        return (ld >= rd ? ld : rd) + 1;
    }
}

// ���ض��������e�������ţ�i�ǽ��p��������
static int EIndex(SqBiTree T, TElemType e, int i) {
    int cl, cr;
    
    // �Ѿ�Խ��
    if(i >= MAX_TREE_SIZE) {
        return -1;
    }
    
    // e��ֵ���Ϲ�
    if(e == '\0') {
        return -1;
    }
    
    // �ҵ���Ԫ��e
    if(T[i] == e) {
        return i;
    }
    
    // ���������в���
    cl = EIndex(T, e, 2 * i + 1);
    if(cl != -1) {
        return cl;
    }
    
    // ���������в���
    cr = EIndex(T, e, 2 * i + 2);
    if(cr != -1) {
        return cr;
    }
    
    return -1;
}

// ժ�¶�����T�е�����i���������Ϊ������R������j
static void Transfer(SqBiTree T, int i, SqBiTree R, int j) {
    R[j] = T[i];
    
    if(T[i] != '\0') {
        Transfer(T, 2 * i + 1, R, 2 * j + 1);
        Transfer(T, 2 * i + 2, R, 2 * j + 2);
        T[i] = '\0';
    }
}

// ɾ��������T�е�����i
static void Delete(SqBiTree T, int i) {
    if(T[i] != '\0') {
        T[i] = '\0';
        Delete(T, 2 * i + 1);
        Delete(T, 2 * i + 2);
    }
}

// ����������ڲ�ʵ��
static Status PreTraverse(SqBiTree T, Status(Visit)(TElemType), int i) {
    // Խ��
    if(i >= MAX_TREE_SIZE) {
        return ERROR;
    }
    
    if(T[i]) {
        if(Visit(T[i])) {
            if(PreTraverse(T, Visit, 2 * i + 1)) {
                if(PreTraverse(T, Visit, 2 * i + 2)) {
                    return OK;
                }
            }
        }
    
        return ERROR;
    
        // ���������������������
    } else {
        return OK;
    }
}

// ����������ڲ�ʵ��
static Status InTraverse(SqBiTree T, Status(Visit)(TElemType), int i) {
    // Խ��
    if(i >= MAX_TREE_SIZE) {
        return ERROR;
    }
    
    if(T[i]) {
        if(InTraverse(T, Visit, 2 * i + 1)) {
            if(Visit(T[i])) {
                if(InTraverse(T, Visit, 2 * i + 2)) {
                    return OK;
                }
            }
            
        }
        
        return ERROR;
        
        // ���������������������
    } else {
        return OK;
    }
}

// ����������ڲ�ʵ��
static Status PostTraverse(SqBiTree T, Status(Visit)(TElemType), int i) {
    // Խ��
    if(i >= MAX_TREE_SIZE) {
        return ERROR;
    }
    
    if(T[i]) {
        if(PostTraverse(T, Visit, 2 * i + 1)) {
            if(PostTraverse(T, Visit, 2 * i + 2)) {
                if(Visit(T[i])) {
                    return OK;
                }
                
            }
        }
        
        return ERROR;
        
        // ���������������������
    } else {
        return OK;
    }
}


/*�������������������������������������������� ͼ�λ���� ��������������������������������������������*/

void PrintGraph(SqBiTree T) {
    int level, width;
    int i, j, k, w;
    int begin;
    int distance;
    TElemType** tmp;
    
    // ���������������������
    if(BiTreeEmpty(T)) {
        printf("\n");
        return;
    }
    
    level = BiTreeDepth(T);         // ����ȫ���������ṹ�߶�
    width = (int)pow(2, level)-1;   // ����ȫ���������ṹ���
    
    // ��̬������
    tmp = (TElemType**)malloc(level* sizeof(TElemType*));
    
    // ��̬������
    for(i = 0; i < level; i++) {
        tmp[i] = (TElemType*)malloc(width* sizeof(TElemType));
    
        // ��ʼ���ڴ�ֵΪ���ַ�
        memset(tmp[i], '\0', width);
    }
    
    // ������������Ԫ�أ����䰲�ŵ���ά����tmp�к��ʵ�λ��
    for(i = 0; i < level; i++) {
        w        = (int) pow(2, i);             // ��������ǰ��Ŀ��
        distance = width / w;                   // ��������ǰ���Ԫ�ؼ��
        begin    = width / (int) pow(2, i + 1); // ��������ǰ���׸�Ԫ��֮ǰ�Ŀո���
        
        for(k = 0; k < w; k++) {
            j = begin + k * (1 + distance);
            tmp[i][j] = T[(int) pow(2, i) + k - 1];
        }
    }

    for(i = 0; i < level; i++) {
        for(j = 0; j < width; j++) {
            if(tmp[i][j] != '\0') {
                printf("%c", tmp[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}
