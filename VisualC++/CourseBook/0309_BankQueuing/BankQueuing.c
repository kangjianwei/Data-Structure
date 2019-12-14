/*==================
 * ģ�������Ŷ�
 *
 * �����㷨: 3.6��3.7
 ===================*/

#ifndef BANKQUEUING_C
#define BANKQUEUING_C

#include "BankQueuing.h"                //**��03 ջ�Ͷ���**//

/*
 * ���������������� �㷨3.6 ����������������
 *
 * ����ҵ��ģ�⣬ͳ��һ���ڿͻ������ж�����ƽ��ʱ��
 */
void Bank_Simulation_1()
{
    char eventType;
    
    OpenForDay();                       // ���п���
    
    // ����¼���Ϊ��
    while(MoreEvent()) {
        EventDrived(&eventType);        // �¼�����
        
        switch(eventType) {
            case 'A':
                CustomerArrived();      // ����ͻ������¼�
                break;
            case 'D':
                CustomerDeparture();    // ����ͻ��뿪�¼�
                break;
            default :
                Invalid();
        }
    }
    
    CloseForDay();
}

/*
 * ���������������� �㷨3.7 ����������������
 *
 * ����ҵ��ģ�⣬ͳ��һ���ڿͻ������ж�����ƽ��ʱ��
 * �㷨������3.7�����Ƶ�
 */
void Bank_Simulation_2() {
    OpenForDay();                       // ���п���
    
    while(!ListEmpty(gEv)) {
        ListDelete(gEv, 1, &gEn);
        
        if(gEn.NType == Arrive) {
            CustomerArrived();          // ����ͻ������¼�
        } else {
            CustomerDeparture();        // ����ͻ��뿪�¼�
        }
    }
    
    CloseForDay();                      // ���й���
}

/*
 * ���п��ţ���ʼ�����л���
 */
void OpenForDay() {
    int i;
    
    // ����ʱ��,��������ÿ��Ӫҵ8Сʱ��480��
    gCloseTime = 480;
    
    // ��ʼ���ۼ�ʱ��Ϳͻ���Ϊ0
    gTotalTime = 0;
    gCustomerNum = 0;
    
    // ��ʼ���¼�����Ϊ�ձ�
    InitList(&gEv);
    
    // �趨��һ���ͻ������¼�
    gEn.OccurTime = 0;
    gEn.NType = Arrive;
    
    // �����¼���
    OrderInsert(gEv, gEn, cmp);
    
    // ��ʼ��4���ն���
    for(i = 1; i <= N; ++i) {
        InitQueue(&gQ[i]);
    }
    
    Show();
}

/*
 * ���й���
 *
 * �ͷ���Դ����ӡͳ����Ϣ
 */
void CloseForDay() {
    printf("�����ܹ���%d���ͻ���ƽ������ʱ��Ϊ%d���ӡ�\n", gCustomerNum, gTotalTime / gCustomerNum);
}

/*
 * �ж��¼����Ƿ�Ϊ�ա�
 * ���Ƿ����δ������¼���
 */
Status MoreEvent() {
    return !ListEmpty(gEv);
}

/*
 * ���������¼����¼������Ƴ����������¼��洢��ȫ�ֱ���gEn�С�
 * event�����洢���¼�������
 */
void EventDrived(char* eventType) {
    // ���¼����л�ȡ�������¼�
    ListDelete(gEv, 1, &gEn);
    
    // ʶ���¼�����
    if(gEn.NType == Arrive) {
        *eventType = 'A';
    } else {
        *eventType = 'D';
    }
}

/*
 * ����ͻ������¼���gEn.NType=0
 */
void CustomerArrived() {
    Event en;               // �¼�
    QElemType customer;     // �ͻ���¼
    
    int durtime;    // ��ǰ�ͻ�����ҵ����Ҫ��ʱ��
    
    int intertime;  // ��һ���ͻ��ﵽʱ����
    int t;          // ��һ���ͻ�����ʱ��
    
    int i;          // ���б��
    
    // �ܿͻ�����һ
    ++gCustomerNum;
    
    // ���ɵ�ǰ�ͻ�����ҵ����Ҫ��ʱ�����һ���ͻ��ﵽʱ����
    Random(&durtime, &intertime);
    
    // ��һ���ͻ�����ʱ��
    t = gEn.OccurTime + intertime;
    
    // ���������δ���ţ�����һ�ͻ�"����"�¼������¼���
    if(t < gCloseTime) {
        en.OccurTime = t;   // ��һ�ͻ��ĵ���ʱ��
        en.NType = Arrive;  // "����"�¼�����
        OrderInsert(gEv, en, cmp);  // "����"�¼������¼���
    }
    
    // ��ȡ��ǰ������̵Ķ��б��
    i = Minimum();
    
    // ��¼��ǰ�ͻ���Ϣ
    customer.ArrivedTime = gEn.OccurTime;   // ����ʱ��
    customer.Duration = durtime;            // ����ҵ������ʱ��
    customer.Count = gCustomerNum;          // �ͻ����
    
    // ��ǰ�ͻ�������̶����Ŷ�
    EnQueue(&gQ[i], customer);
    printf("��%3d���ͻ������� %d ���Ŷ�...\n", customer.Count, i);
    Show();
    
    /*
     * �����ǰ������ֻ����һ���ͻ��Ŷӣ�����Ҫ�������뿪ʱ�䣬
     * ������һ��"�뿪"�¼����뵽�¼�����
     */
    if(QueueLength(gQ[i]) == 1) {
        en.OccurTime = gEn.OccurTime + durtime; // ��ǰ�ͻ����뿪ʱ��
        en.NType     = i;                       // "�뿪"�¼����ͣ�ֵΪ1-4��ָʾ�ӵڼ����������뿪
        OrderInsert(gEv, en, cmp);  // "�뿪"�¼������¼���
    }
}

/*
 * ����ͻ��뿪�¼���gEn.NType>0
 */
void CustomerDeparture() {
    Event en;               // �¼�
    QElemType customer;     // �ͻ���¼
    int i = gEn.NType;      // ���б��
    
    // ��i�����еĶ�ͷ�ͻ����ҵ�񲢳���
    DeQueue(&gQ[i], &customer);
    printf("��%3d���ͻ��Ӷ��� %d ���뿪...\n", customer.Count, i);
    Show();
    
    // �ۼƿͻ�����ʱ��
    gTotalTime += gEn.OccurTime - customer.ArrivedTime;
    
    /*
     * �����ǰ��������Ȼ�����ŶӵĿͻ�������Ҫ����ö����ж�ͷ�ͻ����뿪ʱ��
     * ע��֮������������㣬����Ϊֻ����һ���ͻ��뿪�ˣ���һ���ͻ����뿪ʱ��Ż�������
     */
    if(!QueueEmpty(gQ[i])) {
        // ��ȡ��ͷ�ͻ�
        GetHead(gQ[i], &customer);
        en.OccurTime = gEn.OccurTime + customer.Duration;   // "�뿪"�¼�������ʱ��
        en.NType     = i;                                   // "�뿪"�¼�����
        OrderInsert(gEv, en, cmp);  // "�뿪"�¼������¼���
    }
}

/*
 * ������������Ч���¼�
 */
void Invalid() {
    printf("���д���");
    exit(OVERFLOW);
}

/*
 * ���¼�en���뵽�¼���ev�У�ev�ǰ�����ʱ����絽�����е��¼���
 * cmp�����Ƚ������¼�����������en����Ϊ�ڶ���ʵ�δ���ȥ
 */
Status OrderInsert(EventList ev, Event en, int(cmp)(Event, Event)) {
    EventList p, pre, s;
    
    if(ev == NULL) {
        return ERROR;
    }
    
    for(pre = ev; pre->next != NULL && cmp(pre->next->data, en) < 0; pre = pre->next) {
        // ����
    }
    
    s = (LinkList) malloc(sizeof(LNode));
    if(s == NULL) {
        exit(OVERFLOW);
    }
    s->data = en;
    
    s->next = pre->next;
    pre->next = s;
    
    return OK;
}

/*
 * �Ƚ����¼���������
 */
int cmp(Event a, Event b) {
    if(a.OccurTime < b.OccurTime) {
        return -1;      // a�����Ƚ���
    } else if(a.OccurTime > b.OccurTime) {
        return 1;       // a�����Ƚ���
    } else {
        return 0;       // ͬʱ����
    }
}

/*
 * ���������
 *
 * durtime  ����ǰ�ͷ�����ҵ������ʱ��
 * intertime����һ�ͻ���������ʱ��
 */
void Random(int* durtime, int* intertime) {
    srand((unsigned) time(NULL));
    *durtime = rand() % DurationTime + 1;       // ��ҵ��ʱ�����1��20����
    *intertime = rand() % IntervalTime + 1;     // ��һ���˿͵�����ʱ��Ϊ���1��10����
}

/*
 * ���س�����̵Ķ��е����
 */
int Minimum() {
    int i1 = QueueLength(gQ[1]);
    int i2 = QueueLength(gQ[2]);
    int i3 = QueueLength(gQ[3]);
    int i4 = QueueLength(gQ[4]);
    
    if(i1 <= i2 && i1 <= i3 && i1 <= i4) {
        return 1;
    }
    
    if(i2 < i1 && i2 <= i3 && i2 <= i4) {
        return 2;
    }
    
    if(i3 < i1 && i3 < i2 && i3 <= i4) {
        return 3;
    }
    
    if(i4 < i1 && i4 < i2 && i4 < i3) {
        return 4;
    }
    
    return 0;
}

/*
 * ��ʾ���пͻ����е��Ŷ����
 */
void Show() {
    int i;
    QueuePtr p;     // ��¼�����Ŀͻ��ǵڼ���
    
    // �������пͻ�����
    for(i = 1; i <= N; i++) {
        for(p = gQ[i].front; p; p = p->next) {
            if(p == gQ[i].front) {
                if(i == 1) {
                    printf("��̨�١�");
                }
                if(i == 2) {
                    printf("��̨�ڡ�");
                }
                if(i == 3) {
                    printf("��̨�ۡ�");
                }
                if(i == 4) {
                    printf("��̨�ܡ�");
                }
            } else {
                printf("��%03d��", p->data.Count);
            }
            
            
            if(p == gQ[i].rear) {
                printf("\n");
            }
        }
    }
    
    printf("\n");
    
    Wait(SleepTime);
}

#endif
