#include "head_input.h" 

//�����Ŀ��Ϣ�ļ������������� 
KMID *Subjectfile(char *filename, int *num)
{
	//��ֻ���ķ�ʽ�� 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[Sujectname] Error\n");
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
	
	//subject:��Ŀ����KMID��ʽ: num name 
	KMID *subject = (KMID *) malloc(sizeof(KMID) * n);
	
	KMID *head = subject;
	if(subject == NULL)
	{
		printf("SubjectFile *subject malloc Error");
		return ;
	 } 
	 
	 while(n--)
	{
		fscanf(fp, "%s%s", subject->nm, subject->s);
		subject++;
	}
	
	fclose(fp);
	//subject = head;
	return head; 
}
