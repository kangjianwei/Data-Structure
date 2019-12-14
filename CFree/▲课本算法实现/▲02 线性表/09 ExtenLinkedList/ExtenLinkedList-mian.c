/************************************
 *						            *
 * �ļ���: ��02 ���Ա�              *
 * 						            *
 * ��  ��: ��չ�ĵ�������غ������� *
 *                                  *
 ************************************/

#include <stdio.h>
#include "ExtenLinkedList.c" 							//**��02 ���Ա�**//

/* ����ԭ�� */
Status CmpGreater(LElemType_E e, LElemType_E data);		//�ж�data�Ƿ����e //��data>e������TRUE
void PrintElem(LElemType_E e);							//���Ժ�������ӡ����
	
int main(int argc, char **argv)
{
	ELinkList L;
	Link p, q, s;
	PositionPtr r;
	int i;
	LElemType_E e;
		
	printf("��3\n������ InitList_E ����...\n");			//3.����InitList_E����
	{
		printf("��ʼ����չ�ĵ����� L ...\n");	
		InitList_E(&L);
		printf("\n");
	} 
	PressEnter;
	
	printf("��14\n������ ListEmpty_E ����...\n");		//14.����ListEmpty_E����
	{
		ListEmpty_E(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("��23\n������ ListInsert_L_E ����...\n");	//23.����ListInsert_L_E����
	{
		for(i=1; i<=6; i++)
		{
			printf("�� L �� %d ��λ�ò��� \"%d\" ...\n", i, 2*i);
			ListInsert_L_E(&L, i, 2*i);
		}
		printf("\n");
	} 
	PressEnter;
	
	printf("��22\n������ ListTraverse_E ����...\n");	//22.����ListTraverse_E����
	{
		printf(" L �е�Ԫ��Ϊ��L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��15\n������ ListLength_E ����...\n");		//15.����ListLength_E����
	{
		i = ListLength_E(L);
		printf(" L �ĳ���Ϊ %d \n", i);
		printf("\n");
	} 
	PressEnter;
	
	printf("��24\n������ ListDelete_E ����...\n");		//24.����ListDelete_L_E����
	{
		ListDelete_L_E(&L, 6, &e);
		printf("ɾ�� L �е� 6 ��Ԫ�� \"%d\" ...\n", e);
		printf(" L �е�Ԫ��Ϊ��L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;	

	printf("��20\n������ LocatePos_E ����...\n");		//20.����LocatePos_E����
	{
		LocatePos_E(L, 3, &p);
		printf(" L �е� 3 ��Ԫ�� \"%d\" �ĵ�ַΪ 0x%x \n", p->data, p);
		printf("\n");
	} 
	PressEnter;
	
	printf("��18\n������ PriorPos_E ����...\n");		//18.����PriorPos_E����
	{
		r = PriorPos_E(L, p);
		printf("ָ�� p ָ���Ԫ�� \"%d\" ��ǰ��Ԫ��Ϊ \"%d\" \n", p->data, r->data);
		printf("\n");
	} 
	PressEnter;
	
	printf("��19\n������ NextPos_E ����...\n");			//19.����NextPos_E����
	{
		r = NextPos_E(p);
		printf("ָ�� p ָ���Ԫ�� \"%d\" �ĺ��Ԫ��Ϊ \"%d\" \n", p->data, r->data);
		printf("\n");
	} 
	PressEnter;
	
	printf("��21\n������ LocateElem_E ����...\n");		//21.����LocateElem_E����
	{
		r = LocateElem_E(L, 7, CmpGreater);
		printf(" L �е�һ��Ԫ��ֵ���� 7 ��Ԫ�� \"%d\" �ĵ�ַΪ 0x%x \n", r->data, r);
		printf("\n");
	} 
	PressEnter;
	
	printf("��1\n������ MakeNode_E ����...\n");			//1.����MakeNode_E����
	{
		printf("������� p ...\n");
		MakeNode_E(&p, 101);
		printf("������� q ...\n");
		MakeNode_E(&q, 202);
		printf("\n"); 
	} 
	PressEnter;
	
	printf("��13\n������ GetCurElem_E ����...\n");		//13.����GetCurElem_E����
	{
		e = GetCurElem_E(p);
		printf("��� p ��ֵΪ \"%d\" \n", e);
		e = GetCurElem_E(q);
		printf("��� q ��ֵΪ \"%d\" \n", e);
		printf("\n");
	} 
	PressEnter;
	
	printf("��12\n������ SetCurElem_E ����...\n");		//12.����SetCurElem_E����
	{
		printf("�� 888 �滻 p ����е�ֵ...\n"); 
		SetCurElem_E(p, 888);
		printf("��� p ��ֵΪ \"%d\" \n", p->data);
		printf("\n");
	} 
	PressEnter;
	
	printf("��2\n������ FreeNode_E ����...\n");			//2.����FreeNode_E����
	{
		printf("���ٽ�� p ǰ��");
		p ? printf(" p ���ڣ�\n") : printf(" p �����ڣ���\n");
		FreeNode_E(&p);
		printf("���ٽ�� p ��");
		p ? printf(" p ���ڣ�\n") : printf(" p �����ڣ���\n");
		printf("\n");
	} 
	PressEnter;
	 
	printf("��8\n������ Append_E ����...\n");			//8.����Append_E����
	{
		printf("�� q ������ L ���һ�����֮��...\n");
		Append_E(&L, q);
		printf(" L �е�Ԫ��Ϊ��L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��9\n������ Remove_E ����...\n");			//9.����Remove_E����
	{
		printf("ɾ�� L �����һ����㣬�� p ����ɾ���Ľ��...\n");
		Remove_E(&L, &p);
		printf(" L �е�Ԫ��Ϊ��L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
		
	printf("��6\n������ InsFirst_E ����...\n");			//6.����InsFirst_E����
	{
		printf("����ֵΪ 303 �Ľ�� p ...\n");
		MakeNode_E(&p, 303);
		printf("�� q ָ�� L �е� 4 ��Ԫ��...\n");
		LocatePos_E(L, 4, &q);
		printf("�� p �����뵽�� q ��ͷ��������ĵ�һ�����֮ǰ...\n");
		InsFirst_E(&L, q, p);
		printf(" L �е�Ԫ��Ϊ��L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��7\n������ DelFirst_E ����...\n");			//7.����DelFirst_E����
	{
		printf("ɾ�� L ���Ե�4����� q Ϊͷ��������ĵ�һ�����...\n");
		DelFirst_E(&L, q, &p);
		printf("��ǰ L ��ֵΪ��L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;

	printf("��16\n������ GetHead_E ����...\n");			//16.����GetHead_E����
	{
		p = GetHead_E(L);
		printf(" L ͷָ��Ϊ p = L.head = 0x%x \n", p);
		printf("\n");
	} 
	PressEnter;

	printf("��17\n������ GetLast_E ����...\n");			//17.����GetLast_E����
	{
		q = GetLast_E(L);
		printf(" L βָ��Ϊ q = L.tail = 0x%x \n", q);	
		printf("\n");
	} 
	PressEnter;
			
	printf("��10\n������ InsBefore_E ����...\n");		//10.����InsBefore_E����
	{			
		printf("����ֵΪ 404 �Ľ�� s ...\n");						
		MakeNode_E(&s, 404);
		printf("����� s ���뵽β��� q ֮ǰ...\n");
		InsBefore(&L, &q, s);
		printf("��ǰ L ��ֵΪ��L = ");						 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
		
	printf("��11\n������ InsAfter_E ����...\n");		//11.����InsAfter_E����
	{	
		printf("����ֵΪ 505 �Ľ�� s ...\n");						
		MakeNode_E(&s, 505);
		printf("����� s ���뵽ͷ��� p ֮��...\n");
		InsAfter(&L, &p, s);
		printf(" L �е�Ԫ��Ϊ��L = ");			 
		ListTraverse_E(L, PrintElem);
		printf("\n\n");
	} 
	PressEnter;
	
	printf("��4\n������ ClearList_E ����...\n");		//4.����ClearList_E����
	{
		printf("��� L ǰ��");
		ListEmpty_E(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		ClearList_E(&L);
		printf("��� L ��");
		ListEmpty_E(L) ? printf(" L Ϊ�գ���\n") : printf(" L ��Ϊ�գ�\n");
		printf("\n");
	} 
	PressEnter;
	
	printf("��5\n������ DestroyList_E ����...\n");		//5.����DestroyList_E����
	{
		printf("���� L ǰ��");
		L.head!=NULL && L.tail!=NULL ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
		DestroyList_E(&L);
		printf("���� L ��");
		L.head!=NULL && L.tail!=NULL ? printf(" L ���ڣ�\n") : printf(" L �����ڣ���\n");
		printf("\n");
	} 
	PressEnter;
	
	return 0; 
}

Status CmpGreater(LElemType_E e, LElemType_E data)
{
	return data>e ? TRUE : FALSE;
}

void PrintElem(LElemType_E e)
{
	printf("%d ", e);
}
