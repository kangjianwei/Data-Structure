/**********************************
 *                                *
 * �ļ���: ��03 ջ�Ͷ���\06 Hanoi *
 *                                *
 * �ļ���: Hanoi.c                *
 *                                *
 * ��  ��: 3.5                    * 
 *                                *
 **********************************/

#ifndef HANOI_C
#define HANOI_C

#include "Hanoi.h"						//**03 ջ�Ͷ���**//

/*�T�T�T�T�[
�U �㷨3.5�U 
�^�T�T�T�T*/
void hanoi(int n, char x, char y, char z)
{
	if(n==1)							//���ƶ�n��Բ�̣������ƶ����ϵ�n-1��Բ�� 
		move(x, 1, z);					//�����Ϊ1��Բ�̴�x�Ƶ�z 
	else
	{
		hanoi(n-1, x, z, y);			//��x�ϱ��Ϊ1��n-1��Բ���Ƶ�y��z�������� 
		move(x, n, z);					//�����Ϊn��Բ�̴�x�Ƶ�z 
		hanoi(n-1, y, x, z);			//��y�ϱ��Ϊ1��n-1��Բ���ƶ���z��x�������� 
	}	
} 

void move(char x, int n, char z)
{
	gStep++;							//stepΪȫ�ֱ�������main����֮�ⶨ�� 
	printf("��%2d�������� %d ��Բ�̴� %c �Ƶ� %c \n", gStep, n, x, z); 
} 

#endif
