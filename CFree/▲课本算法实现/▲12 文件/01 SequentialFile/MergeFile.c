/***********************
 *                     *
 * �ļ���: ��12 �ļ�   *
 *                     *
 * �ļ���: MergeFile.c *
 *                     *
 * ��  ��: 12.1        *
 *                     *
 ***********************/

#ifndef MERGEFILE_C
#define MERGEFILE_C

#include "MergeFile.h" 								//**��12 �ļ�**//

void InitFile(FILE *f, FILE *g)
{
	MainFile fr[7] = {1,50,5,78,12,100,14,95,15,360,18,200,20,510};					//���ļ� 
	AffairFile gr[5] = {'I',8,+100,'U',12,-25,'U',14,+38,'D',18,-200,'I',21,+60};	//�����ļ�
	
	fwrite(&fr[0], sizeof(fr[0]), 7, f);
	fwrite(&gr[0], sizeof(AffairFile), 5, g);
		
	fclose(f);
	fclose(g);
}

int Situation(MainFile fr, AffairFile gr)
{
	if(fr.key<gr.key)		//����1������"��"���ļ��еļ�¼ 
		return 1;
	
	if(fr.key==gr.key)
	{
		if(gr.code=='D')	//����2��ɾ��"��"���ļ���¼���������� 
			return 2;
		
		if(gr.code=='U')	//����3������"��"���ļ��м�¼ 
			return 3;
	}
	
	if(fr.key>gr.key)
	{
		if(gr.code=='I')	//����4�������������ļ� 
			return 4;
	}
	
	return 0;				//�������Σ����ش��� 
}

MainFile P(AffairFile gr)
{
	MainFile tmp;
	
	tmp.key = gr.key;
	tmp.balance = gr.money;
	
	return tmp;
}

MainFile Q(MainFile fr, AffairFile gr)
{
	MainFile tmp;
	
	tmp.key = fr.key;
	tmp.balance = fr.balance + gr.money;
	
	return tmp;
}

void Error(AffairFile gr, FILE *log)			//�����ļ��������� 
{
	log = fopen("ErrorLog.file","a+");
	fwrite(&gr, sizeof(AffairFile), 1, log);	//����������д����־
	fclose(log);
}

/*�T�T�T�T�[
�U�㷨12.1�U 
�^�T�T�T�T*/
void MergeFile(FILE *f, FILE *g, FILE *h, FILE *log)
{
	int tag, ftag, gtag;
	MainFile fr, tmp;											//���ļ� 
	AffairFile gr;												//�����ļ� 
	
	ftag = gtag = 0;

	ftag = fread(&fr, sizeof(MainFile), 1, f);
	gtag = fread(&gr, sizeof(AffairFile), 1, g);

	while(ftag==1&&gtag==1)										//��ȡ�ɹ� 
	{			
		tag = Situation(fr, gr);
		
		switch(tag)
		{
			case 1:												//����"��"���ļ��м�¼
				fwrite(&fr, sizeof(MainFile), 1, h);
				ftag = fread(&fr, sizeof(MainFile), 1, f);
				break;		 

			case 2:												//ɾ��"��"���ļ���¼����������
				ftag = fread(&fr, sizeof(MainFile), 1, f);
				gtag = fread(&gr, sizeof(AffairFile), 1, g);
				break;

			case 3:												//����"��"���ļ��м�¼ 
				tmp = Q(fr,gr);
				fwrite(&tmp, sizeof(MainFile), 1, h);			//����Q��fr��gr�鲢��һ��h�ṹ�ļ�¼
				ftag = fread(&fr, sizeof(MainFile), 1, f);
				gtag = fread(&gr, sizeof(AffairFile), 1, g); 
				break;

			case 4:												//���룬����P��gr�ӹ�Ϊh�Ľṹ 
				tmp = P(gr);
				fwrite(&tmp, sizeof(MainFile), 1, h);
				gtag = fread(&gr, sizeof(AffairFile), 1, g);
				break;
			
			default:
				Error(gr, log);
				gtag = fread(&gr, sizeof(AffairFile), 1, g); 	//��ȡ��һ������ 
		}
	}
	
	while(ftag==0&&gtag==1)										//���ļ����� 
	{
		if(gr.code=='I')										//ֻ����"����"�������� 
		{
			tmp = P(gr);
			fwrite(&tmp, sizeof(MainFile), 1, h);		
		}
		else
			Error(gr, log);
		
		gtag = fread(&gr, sizeof(AffairFile), 1, g); 			//��ȡ��һ������
	}

	while(ftag==1&&gtag==0)										//�����ļ����� 
	{
		fwrite(&fr, sizeof(MainFile), 1, h);
		ftag = fread(&fr, sizeof(MainFile), 1, f);	
	}
	
	fclose(f);
	fclose(g);
	fclose(h);
}

void Print(FILE *fp, int mark)
{
	MainFile fr;
	AffairFile gr;
	
	if(mark==0)			//����ļ���¼ 
	{
		while(fread(&fr, sizeof(MainFile), 1, fp)==1)
			printf("(%d��%d) ", fr.key, fr.balance);
	}
	else				//��������¼ 
	{
		while(fread(&gr, sizeof(AffairFile), 1, fp)==1)
			printf("(%d��%d��%c) ", gr.key, gr.money, gr.code);	
	}

	fclose(fp);
			
	printf("\n");
}

#endif
