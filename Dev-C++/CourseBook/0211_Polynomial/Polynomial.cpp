/*========================
 * һԪ����ʽ(������������)
 *
 * �����㷨: 2.22��2.23
 =========================*/

#include "Polynomial.h"


/*�������������������������������������������� һԪ����ʽ���� ��������������������������������������������*/

/*
 * ���������������� �㷨2.22 ����������������
 *
 * ����
 *
 * ���������ϵ����ָ������������Ϊm��һԪ����ʽ
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
void CreatPolyn(Polynomial* P, int m, char* path) {
    int i;
    ElemType e;
    Position h, q;
    Link s;
    FILE* fp;
    int readFromConsole;    // �Ƿ�ӿ���̨��ȡ����

    // ���û���ļ�·����Ϣ����ӿ���̨��ȡ����
    readFromConsole = path == NULL || strcmp(path, "") == 0;

    // ��ʼ��һ������������һԪ����ʽ
    InitList(P);

    // ��ȡ����ʽͷָ��
    h = GetHead(*P);

    // Ϊͷ����������
    e.coef = 0.0f;
    e.expn = -1;
    SetCurElem(h, e);

    if(!readFromConsole) {
        // ���ļ���׼����ȡ��������
        fp = fopen(path, "r");
        if(fp == NULL) {
            exit(ERROR);
        }
    }

    if(readFromConsole) {
        printf("������ %d ��Ԫ�أ�\n", m);
    }

    // ����¼��m����Ч��
    for(i = 1; i <= m; i++) {
        // ��ȡϵ����ָ����Ϣ����ʱ����e
        if(readFromConsole) {
            printf("������� %d ��ϵ����ָ����", i);
            scanf("%f%d", &(e.coef), &(e.expn));
        } else {
            ReadData(fp, "%f%d", &(e.coef), &(e.expn));
        }

        // �����ǰ�����в����ڸ�ָ����
        if(LocateElem(*P, e, &q, Cmp) == FALSE && q != NULL) {
            // �����½��
            if(MakeNode(&s, e) == OK) {
                // ��q���֮�����s
                InsFirst(P, q, s);
            }
        }
    }

    if(!readFromConsole) {
        fclose(fp);
    }
}

/*
 * ����
 *
 * ����һԪ����ʽ��
 */
void DestroyPolyn(Polynomial* P) {
    DestroyList(P);
}

/*
 * ����
 *
 * ����һԪ����ʽ��������
 */
int PolynLength(Polynomial P) {
    return ListLength(P);
}

/*
 * ���������������� �㷨2.23 ����������������
 *
 * �ӷ�
 *
 * һԪ����ʽ�ӷ�Pa=Pa+Pb��
 * ������ɺ󣬼������浽Pa�У�����Pb���١�
 */
void AddPolyn(Polynomial* Pa, Polynomial* Pb) {
    Position ha, hb;
    Position qa, qb;
    ElemType a, b;
    float sum;

    // ha��hb�ֱ�ָ��Pa��Pbͷ���
    ha = GetHead(*Pa);
    hb = GetHead(*Pb);

    // qa��qb�ֱ�ָ��Pa��Pb�ĵ�ǰ���
    qa = NextPos(*Pa, ha);
    qb = NextPos(*Pb, hb);

    // qa��qb���ǿ�
    while(qa && qb) {
        // a��bΪ�����е�ǰ�Ƚ�Ԫ��
        a = GetCurElem(qa);
        b = GetCurElem(qb);

        //�Ƚϵ�ǰԪ�ص�ָ����С
        switch(Cmp(a, b)) {
            // ����ʽPa�е�ǰ����ָ��ֵ��С
            case -1: {
                ha = qa;
                qa = NextPos(*Pa, qa);
            }
                break;

                // ������ֵ���
            case 0: {
                sum = a.coef + b.coef;

                // ��Ӳ��ܵ���ʱ����Pa����ϵ��ֵ
                if(sum != 0.0) {
                    // ������SetCurElem()�����ʣ�����ֱ�Ӹ�ֵ
                    qa->data.coef = sum;
                    // ha����
                    ha = qa;

                    //��ӵ���ʱ��ɾ��Pa�е�ǰ���
                } else {
                    // ɾ��ha����Ľ�㣨��ʵɾ�ľ���qa��
                    DelFirst(Pa, ha, &qa);
                    // �ͷű�ɾ�������ռ�ռ�
                    FreeNode(&qa);
                }

                // ɾ��Pb��ɨ����Ľ��
                DelFirst(Pb, hb, &qb);
                // �ͷű�ɾ�������ռ�ռ�
                FreeNode(&qb);

                // qa��qb������
                qa = NextPos(*Pa, ha);
                qb = NextPos(*Pb, hb);
            }
                break;

                // ����ʽPb�е�ǰ����ָ��ֵ��С
            case 1: {
                // ժ��Pb��ǰ���
                DelFirst(Pb, hb, &qb);

                // ��ժ�½������Pa��
                InsFirst(Pa, ha, qb);

                ha = NextPos(*Pa, ha);
                qb = NextPos(*Pb, hb);
            }
                break;
        }//switch
    }//while

    // ��Pb��δɨ���꣬��ʣ�������ӵ�Pa��
    if(qb != NULL) {
        Append(Pa, qb);
    }

    // �ͷ�Pbͷ���
    FreeNode(&hb);

    // ����PbΪ����״̬
    (*Pb).head = (*Pb).tail = NULL;
    (*Pb).len = 0;
}

/*
 * ����
 *
 * һԪ����ʽ����Pa=Pa-Pb��
 * ������ɺ󣬼������浽Pa�У�����Pb���١�
 */
void SubtractPolyn(Polynomial* Pa, Polynomial* Pb) {
    Position ha, hb;
    Position qa, qb;
    Position r;
    ElemType a, b;
    float sum;

    // ha��hb�ֱ�ָ��Pa��Pbͷ���
    ha = GetHead(*Pa);
    hb = GetHead(*Pb);

    // qa��qb�ֱ�ָ��Pa��Pb�ĵ�ǰ���
    qa = NextPos(*Pa, ha);
    qb = NextPos(*Pb, hb);

    // qa��qb���ǿ�
    while(qa && qb) {
        // a��bΪ�����е�ǰ�Ƚ�Ԫ��
        a = GetCurElem(qa);
        b = GetCurElem(qb);

        // �Ƚϵ�ǰԪ�ص�ָ����С
        switch(Cmp(a, b)) {
            // ����ʽPa�е�ǰ����ָ��ֵ��С
            case -1: {
                ha = qa;
                qa = NextPos(*Pa, ha);
            }
                break;

                // ������ֵ���
            case 0: {
                sum = a.coef - b.coef;

                // ������ܵ���ʱ����Pa����ϵ��ֵ
                if(sum != 0.0) {
                    // ����ϵ��
                    qa->data.coef = sum;
                    // ha����
                    ha = qa;

                    // �������ʱ��ɾ��Pa�е�ǰ���
                } else {
                    // ɾ��ha����Ľ�㣨��ʵɾ�ľ���qa��
                    DelFirst(Pa, ha, &qa);
                    // �ͷű�ɾ�������ռ�ռ�
                    FreeNode(&qa);
                }

                // ɾ��Pb��ɨ����Ľ��
                DelFirst(Pb, hb, &qb);
                // �ͷű�ɾ�������ռ�ռ�
                FreeNode(&qb);

                // qa��qb������
                qa = NextPos(*Pa, ha);
                qb = NextPos(*Pb, hb);
            }
                break;

                // ����ʽPb�е�ǰ����ָ��ֵ��С
            case 1: {
                // ժ��Pb��ǰ���
                DelFirst(Pb, hb, &qb);

                // �ı䵱ǰ������
                qb->data.coef = -qb->data.coef;

                // ��ժ�½������Pa��
                InsFirst(Pa, ha, qb);

                ha = NextPos(*Pa, ha);
                qb = NextPos(*Pb, hb);
            }
                break;
        }//switch
    }//while

    // ��Pb��δɨ���꣬��ʣ�����ϵ��ȡ�������ӵ�Pa��
    if(qb != NULL) {
        // �ı�ʣ����ķ���
        for(r = qb = 0; r != NULL; r = r->next) {
            r->data.coef = -r->data.coef;
        }

        Append(Pa, qb);
    }

    // �ͷ�Pbͷ���
    FreeNode(&hb);

    // ����PbΪ����״̬
    (*Pb).head = (*Pb).tail = NULL;
    (*Pb).len = 0;
}

/*
 * �˷�
 *
 * һԪ����ʽ�˷�Pa=Pa*Pb��
 * ������ɺ󣬼������浽Pa�У�����Pb���١�
 */
void MultiplyPolyn(Polynomial* Pa, Polynomial* Pb) {
    Polynomial Pc, Ptmp;
    int i, j, la, lb;
    Position ha, hb;
    Position qa, qb;
    Link s;
    ElemType e;

    // ��ȡ��������ʽ�ĳ���
    la = PolynLength(*Pa);
    lb = PolynLength(*Pb);

    // ha��hb�ֱ�ָ��Pa��Pbͷ���
    ha = GetHead(*Pa);
    hb = GetHead(*Pb);

    // �ۼӼ�����
    InitList(&Pc);

    // ����Pa�е�Ԫ��
    for(i = 1; i <= la; i++) {
        // �洢��ʱ������
        InitList(&Ptmp);

        // ���ժ��Pa�еĽ��
        DelFirst(Pa, ha, &qa);

        // ����Pb�����н�㣬��Pa��ժ�µĽ���������
        for(j = 1, qb = NextPos(*Pb, hb); j <= lb; j++, qb = NextPos(*Pb, qb)) {
            e.coef = qa->data.coef * qb->data.coef;    //ϵ�����
            e.expn = qa->data.expn + qb->data.expn;    //ָ�����

            // �����½��洢������
            MakeNode(&s, e);

            // ��ӵ���ʱ����ʽ
            Append(&Ptmp, s);
        }

        // ���µĶ���ʽ�ۼӵ�Pc��
        AddPolyn(&Pc, &Ptmp);
    }

    // �����н����ӵ�Pa��
    AddPolyn(Pa, &Pc);

    // ���ٶ���ʽPb
    DestroyPolyn(Pb);
}


/*�������������������������������������������� �������� ��������������������������������������������*/

/*
 * ���
 *
 * ��ӡ���һԪ����ʽ��
 */
void PrintPolyn(Polynomial P) {
    int i;
    Link p;

    p = P.head->next;
    for(i = 1; i <= P.len; i++) {
        if(p->data.coef == 0.0f) {
            continue;
        }

        if(i == 1) {
            printf("%g", p->data.coef);
        } else {
            if(p->data.coef > 0) {
                printf(" + ");
                printf("%g", p->data.coef);
            } else {
                printf(" - ");
                printf("%g", -p->data.coef);
            }
        }

        if(p->data.expn) {
            printf("x");

            if(p->data.expn != 1) {
                printf("^%d", p->data.expn);
            }
        }

        p = p->next;
    }

    printf("\n");
}

/*
 * �Ƚ�
 *
 * �Ƚ�c1���c2��ָ����С��
 */
int Cmp(ElemType c1, ElemType c2) {
    // ����ָ����
    int i = c1.expn - c2.expn;

    if(i < 0) {
        return -1;
    } else if(i == 0) {
        return 0;
    } else {
        return 1;
    }
}

