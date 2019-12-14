/**************************************
 *							          *
 * �ļ���: ��06 ���Ͷ�����\11 NQueens *
 * 							          *
 * �ļ���: NQueens-main.c             *
 * 							          *
 * ��  ��: N�ʺ�������غ�����        *
 *                                    *
 *************************************/

#include <stdio.h>
#include "NQueens.c" 										//**��06 ���Ͷ�����**//

int main(int argc, char *argv[])
{
	ChessBoard c[N][N];
	
	printf("��1\n������ InitChessBoard_CB ����...\n");		//1.����InitChessBoard_CB����
	{
		printf("��ʼ��һ�� %2d * %-2d �Ŀ�����...\n", N, N);
		InitChessBoard_CB(c);
		printf("\n");
	}
	PressEnter;	

	printf("��4\n������ Output_CB ����...\n");				//4.����Output_CB����
	{ 
		printf("չʾ��ǰ�����еĻʺ󲼾�...\n");
		Output_CB(c);
		printf("\n");
	}
	PressEnter;	

	printf("��2��3\n������ Trial_CB�� ����...\n");			//2��3.����Trial_CB��Layout_CB����
	{
		printf("����N�ʺ�����ĸ���...\n");
		Trial_CB(1, c);
		printf("\n");
	}
	PressEnter;
}
