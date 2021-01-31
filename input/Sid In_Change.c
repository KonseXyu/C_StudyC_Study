#include "head_input.h" 

//��һ���˵��Ա��id����ת���ɶ�Ӧ���Ա� 
 void sidnameOne(char *filename, STU *p)
 {
	//��ֻ���ķ�ʽ�� 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[sidnameOne] Error\n");
		return ;
	}
	
	char ps[L];
	int n = 0; 
	while( fgets(ps, 100, fp) != NULL)
	{
		//����'#'��ע���� 
		if (ps[0] == '#') continue; 
		else 
		{	//��ȡע���к��������ĳ��� 
			int x = strlen(ps);
			int i;
			for(i = 0; i < x-1 ;i++)
			{
				//��ö�ȡ������n�� 
				n *= 10;
				n += ps[i] - '0';
			}
			break;	
		}
	} 

	//xb:�Ա����sid��ʽ: num name 
	SID *xb = (SID *) malloc(sizeof(SID) * n);
	if(xb == NULL)
	{
		printf("sidnameOne *xb malloc Error");
		return ;
	 } 
	
	//����xb��ͷָ�� 
	SID *head = xb;
	int t = n;
	//�����Ա�����ļ�����Ϣ 
	while(t--)
	{
		fscanf(fp, "%s%s",xb->nm, xb->s);
		xb++;
	}
	fclose(fp);
	
	int i, j;
	xb = head;
	
	//����sid�Ĵ���ת��
	for(j = 0; j < n; j++)
		if(strcmp(p->sid, (xb + j)->nm) == 0)
			strcpy(p->sid , (xb + j)->s);
			
	return;	
} 

//������ѧ�����Ա�id����ת���ɶ�Ӧ���Ա� 
void sidname(char *filename, STU *p, int num)
 {
	//��ֻ���ķ�ʽ�� 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[sidname] Error\n");
		return ;
	}
	
	char ps[L];
	int n = 0; 
	while( fgets(ps, 100, fp) != NULL)
	{
		//����'#'��ע���� 
		if (ps[0] == '#') continue; 
		else 
		{	//��ȡע���к��������ĳ��� 
			int x = strlen(ps);
			int i;
			for(i = 0; i < x-1 ;i++)
			{
				//��ö�ȡ������n�� 
				n *= 10;
				n += ps[i] - '0';
			}
			break;	
		}
	} 
	printf("������Ա���Ϣ������%d��\n",n);
	
	//xb:�Ա����sid��ʽ: num name 
	SID *xb = (SID *) malloc(sizeof(SID) * n);
	if(xb == NULL)
	{
		printf("sidname *xb malloc Error");
		return ;
	 } 
	
	//����xb��ͷָ�� 
	SID *head = xb;
	int t = n;
	//�����Ա�����ļ�����Ϣ 
	while(t--)
	{
		fscanf(fp, "%s%s",xb->nm, xb->s);
		xb++;
	}
	fclose(fp);
	int i, j;
	xb = head;
	
	//����ѧ����Ϣ�ļ���sid�Ĵ���ת�� 
	while(num--)
	{	
		for(j = 0; j < n; j++)
			if(strcmp(p->sid, (xb + j)->nm) == 0)
				strcpy(p->sid , (xb + j)->s);
		p = p->next;
	}
	
	printf("�Ա����ת������ɣ�\n\n");
	return;	
 } 
