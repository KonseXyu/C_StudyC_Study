#include "head_Use.h" 

//��ѯ����ѧ�ŵ�ѧ����Ϣ
void SearchID (char *Subjectfilename, STU *p)
{
	int num;
 	//��ȡ��Ŀ��Ϣ 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
	int flag = 1;
	long long int findid;
	printf("\n������Ҫ���ҵ�ѧ�ţ�"); 
	scanf("%lld", &findid);
	
	while (p != NULL)
	{
		
		if(p->id == findid)
		{
			if (flag == 1)
  		{
  			flag = 0;
			printf("*****************************"); 
  			fprintf(stdout, "\nѧ��Ϊ%lld��ѧ����Ϣ���ҵ�\n\n", findid);
			fprintf(stdout, "ѧ��\t����\t�Ա�\tѧԺ\t\t");
			int i;
			for(i = 0; i < num; i++)
				printf("%s\t", (q + i)->s);
			printf("ƽ���ɼ�\n");
  		}
			//�������Ļ 
			outputScreen(p, num, q); 
		}
		p = p->next;
	}
	
	if(flag == 1)
		fprintf(stdout,"\nѧ��Ϊ%lld��ѧ����Ϣδ���ҵ���\n", findid);	
	
	return;
}

//��ѯ����������ѧ����Ϣ
void SearchName (char *Subjectfilename, STU *p)
{
	int num;
 	//��ȡ��Ŀ��Ϣ 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
 	char findname[L];
	printf("\n������Ҫ���ҵ����֣�"); 
	scanf("%s", findname);
	
	int flag = 1;
	
	while (p != NULL)
	{
		if(strcmp(p->name, findname) == 0)
		{
			if (flag == 1)
		{
			flag = 0; 
			printf("*****************************\n");
			fprintf(stdout, "����Ϊ%s��ѧ����Ϣ���ҵ�\n\n", findname);
			fprintf(stdout, "ѧ��\t����\t�Ա�\tѧԺ\t\t");
			int i;
			for(i = 0; i < num; i++)
				printf("%s\t", (q + i)->s);
			printf("ƽ���ɼ�\n");
		}
		    //�������Ļ 
			outputScreen(p, num, q);
		}
		p = p->next;
	}
	if(flag == 1)
		fprintf(stdout,"\n����Ϊ%s��ѧ����Ϣδ���ҵ���\n", findname);
	 
	return; 
}
