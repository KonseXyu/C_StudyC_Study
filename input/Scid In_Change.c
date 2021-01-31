#include "head_input.h" 

//����ѧԺ�����ļ�����Ϣ
SCID *Scidfile (char *filename, int *num) 
{
	//��ֻ���ķ�ʽ�� 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[scidname] Error\n");
		return ;
	}
	
	char ps[L];
	int n = 0; 
	while( fgets(ps, 100, fp) != NULL)
	{	
		//����'#'��ע����  
		if (ps[0] == '#') continue; 
		else 
		{
			//��ȡע���к��������ĳ��� 
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
	
	//���ض���ĸ��� 
	*num = n;
	
	//xy:ѧԺ����scid��ʽ: num name 
	SCID *xy = (SCID *) malloc(sizeof(SCID) * n);
	SCID *head = xy;
	if(xy == NULL)
	{
		printf("Scidfile *xy malloc Error");
		return ;
	 } 
	 
	 while(n--)
	{
		fscanf(fp, "%s%s", xy->nm, xy->s);
		xy++;
	}
	
	fclose(fp);
	//xy = head;
	return head; 
}

//�������˵�ѧԺid����ת���ɶ�Ӧ��ѧԺ��Ϣ 
void scidnameOne(char *filename, STU *p)
 {
	//��ֻ���ķ�ʽ�� 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[scidname] Error\n");
		return ;
	}
	
	char ps[L];
	int n = 0; 
	while( fgets(ps, 100, fp) != NULL)
	{	
		//����'#'��ע����  
		if (ps[0] == '#') continue; 
		else 
		{
			//��ȡע���к��������ĳ��� 
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

	//xy:ѧԺ����scid��ʽ: num name 
	SCID *xy = (SCID *) malloc(sizeof(SCID) * n);
	if(xy == NULL)
	{
		printf("scidnameOne *xy malloc Error");
		return ;
	 } 
	 
	 //����xy��ͷָ�� 
	SCID *head = xy;
	int t = n;
	//����ѧԺ�����ļ�����Ϣ 
	while(t--)
	{
		fscanf(fp, "%s%s",xy->nm, xy->s);
		xy++;
	}
	fclose(fp);
	int j;
	xy = head;
	
	//����ѧ����Ϣ�ļ���scid�Ĵ���ת�� 
	for(j = 0; j < n; j++)
	{
		if(strcmp(p->scid, (xy + j)->nm) == 0)
		{	
			strcpy(p->scid , (xy + j)->s);
		}
	}

	return;	
 } 
 
 //������ѧ����ѧԺid����ת���ɶ�Ӧ��ѧԺ��Ϣ 
 void scidname(char *filename, STU *p, int num)
 {
	//��ֻ���ķ�ʽ�� 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[scidname] Error\n");
		return ;
	}
	
	char ps[L];
	int n = 0; 
	while( fgets(ps, 100, fp) != NULL)
	{	
		//����'#'��ע����  
		if (ps[0] == '#') continue; 
		else 
		{
			//��ȡע���к��������ĳ��� 
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
	printf("�����ѧԺ��Ϣ������%d��\n",n);
	
	//xy:ѧԺ����scid��ʽ: num name 
	SCID *xy = (SCID *) malloc(sizeof(SCID) * n);
	if(xy == NULL)
	{
		printf("scidname *xy malloc Error");
		return ;
	 } 
	 
	 //����xy��ͷָ�� 
	SCID *head = xy;
	int t = n;
	//����ѧԺ�����ļ�����Ϣ 
	while(t--)
	{
		fscanf(fp, "%s%s",xy->nm, xy->s);
		xy++;
	}
	fclose(fp);
	int j;
	xy = head;
	
	//����ѧ����Ϣ�ļ���scid�Ĵ���ת�� 
	while(num--)
	{	
		for(j = 0; j < n; j++)
		{
			if(strcmp(p->scid, (xy + j)->nm) == 0)
			{	
				strcpy(p->scid , (xy + j)->s);
			}
		}
		p = p->next;
	}
	printf("ѧԺ����ת������ɣ�\n\n");
	
	return;	
 } 
