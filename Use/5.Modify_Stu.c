 #include "head_Use.h" 
 
//��ѧ���޸�ѧ����Ϣ 
void ModifyID(STU *p, int *flag, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back)
{
	int num;
 	//��ȡ��Ŀ��Ϣ 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
	long long int findid;
	printf("\n��������Ҫ���ĵ�ѧ����Ϣ��id��");
	scanf("%lld", &findid);
	
	while (p != NULL)
	{
		//Ѱ��ƥ���id 
		if(p->id == findid)
		{
			if (*flag == 1)
  			{
	  			*flag = 0; 
	  			printf("\n*****************************");
	  			fprintf(stdout, "\nѧ��Ϊ%lld��ѧ����Ϣ���ҵ�\n", findid);
	  			printf("*****************************\n");
	  			//ag �����Ҫ���ĵ�change����Ƿ����� 
				int change, ag;
				do
				{
					ag = 0;
					printf("\n����ѧ��������1����������������2�������Ա�������3,\n\n����ѧԺ��Ϣ������4�����ĳɼ�������5��");
					scanf("%d", &change);
					if(change == 1)
					{
						int again;
						do
						{
							printf("\n*****************************");
							printf("\n��������ĵ�id��Ϣ��");
							
							long long int cid;
							scanf("%lld", &cid);
							p->id = cid;
							
							printf("\n*****************************\n");	
							printf("\n���ĳɹ���\n\n*****************************\n");
							printf("���¸����밴0���������ĸ�ѧ����Ϣ�밴1,������ĺ����Ϣ�밴2,�������򷵻����˵�:"); 
							scanf("%d",&again);
							
							if (again == 1)
								ag = 1; 
							//����2 back == 2������������ĺ����Ϣ 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 } 
					 else if(change == 2)
					{
						int again;
						do
						{
							printf("\n*****************************");
							printf("\n��������ĺ�������Ϣ��");
							
							char cname[L];
							scanf("%s", cname);
							strcpy(p->name, cname);
							
							printf("\n*****************************\n");	
							printf("\n���ĳɹ���\n\n*****************************\n");
							printf("���¸����밴0���������ĸ�ѧ����Ϣ�밴1,������ĺ����Ϣ�밴2,�������򷵻����˵�:"); 
							scanf("%d",&again);
								
							if (again == 1)
								ag = 1; 
							//����2 back == 2������������ĺ����Ϣ 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					  else if(change == 3)
					{
						int again;
						do
						{
							printf("\n*****************************");
							printf("\n��������ĵ��Ա���Ϣ��");
							scanf("%s", p->sid);
							
							//����������Ա���������ת��
							sidnameOne(Sidfilename, p);
							
							printf("\n*****************************\n");	
							printf("\n���ĳɹ���\n\n*****************************\n");
							printf("���¸����밴0���������ĸ�ѧ����Ϣ�밴1,������ĺ����Ϣ�밴2,�������򷵻����˵�:"); 
							scanf("%d",&again);
							
							if (again == 1)
								ag = 1; 
							//����2 back == 2������������ĺ����Ϣ 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					  else if(change == 4)
					{
						int again;
						do
						{
							printf("\n*****************************");
							printf("\n��������ĵ�ѧԺ��Ϣ��");
							scanf("%s", p->scid);
							
							//���������ѧԺ���������ת�� 
							scidnameOne(Scidfilename, p);
							
							printf("\n*****************************\n");	
							printf("\n���ĳɹ���\n\n*****************************\n");
							printf("���¸����밴0���������ĸ�ѧ����Ϣ�밴1,������ĺ����Ϣ�밴2,�������򷵻����˵�:"); 
							scanf("%d",&again);
								
							if (again == 1)
								ag = 1; 
							//����2 back == 2������������ĺ����Ϣ 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					 else if(change == 5)
					{
						int again;
						do
						{
						Cnum:printf("\n**********��Ŀ��Ϣ************\n\n");
							int i;
							for( i = 0; i < num; i++)
								printf("%s��%s\n", (q + i)->nm, (q + i)->s);
							printf("\n*****************************\n");
							printf("\n������Ҫ���ĵĳɼ���Ŀ���(1-%d)��", num);
							int cnum;
							scanf("%d", &cnum);
							if (cnum >= 1 && cnum <= num)
							{
								printf("\n��������ĺ��%s�ɼ���", (q + cnum - 1)->s);
								scanf("%d", &p->s[cnum - 1]);
								averageOne(p, Subjectfilename);
							 } 
							 else
							 {
							 	 printf("\n���������������������룡\n");
								 goto Cnum;
							 }
							 
							printf("\n*****************************\n");	
							printf("\n���ĳɹ���\n\n*****************************\n");
							printf("���¸����밴0���������ĸ�ѧ����Ϣ�밴1,������ĺ����Ϣ�밴2,�������򷵻����˵�:"); 
							scanf("%d",&again);
							
							if (again == 1)
								ag = 1; 
							//����2 back == 2������������ĺ����Ϣ 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					 else 
					 {
					 	printf("\n*****************************");
					 	printf("\n���������������������룡\n");
					 	printf("*****************************\n");
					 	system("pause");
						 ag = 1;
					}	
				}while (ag == 1);
			}
			break; 
		}
		p = p->next;
	}
	if(*flag == 1)
	{
		printf("\n*****************************");
		fprintf(stdout,"\nѧ��Ϊ%lld��ѧ����Ϣδ���ҵ���\n", findid);
		printf("*****************************\n");
		system("pause");
	 }	
}
	
//�������޸�ѧ����Ϣ 
void ModifyName(STU *p, int *flag, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back)
{
	int num;
 	//��ȡ��Ŀ��Ϣ 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
	char findname[L];
	printf("\n������Ҫ���ҵ����֣�"); 
	scanf("%s", findname);

	while (p != NULL)
	{
		if(strcmp(p->name, findname) == 0)
		{ 
			if (*flag == 1)
  			{
	  			*flag = 0; 
	  			printf("\n*****************************");
	  			fprintf(stdout, "\n����Ϊ%s��ѧ����Ϣ���ҵ�\n", findname);
	  			printf("*****************************\n");
				int change, ag;
				do
				{
					ag = 0;
					printf("\n����ѧ��������1����������������2�������Ա�������3,\n\n����ѧԺ��Ϣ������4�����ĳɼ�������5��");
					scanf("%d", &change);
					if(change == 1)
					{
						int again;
						do
						{
							printf("\n*****************************");
							printf("\n��������ĵ�id��Ϣ��");
							long long int cid;
							scanf("%lld", &cid);
							p->id = cid;
							
							printf("\n*****************************\n");	
							printf("\n���ĳɹ���\n\n*****************************\n");
							printf("���¸����밴0���������ĸ�ѧ����Ϣ�밴1,������ĺ����Ϣ�밴2,�������򷵻����˵�:"); 
							scanf("%d",&again);
							
							if (again == 1)
								ag = 1; 
							//����2 back == 2������������ĺ����Ϣ 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 } 
					 else if(change == 2)
					{
						int again;
						do
						{
							printf("\n*****************************");
							printf("\n��������ĺ�������Ϣ��");
							char cname[L];
							scanf("%s", cname);
							strcpy(p->name, cname);
							
							printf("\n*****************************\n");	
							printf("\n���ĳɹ���\n\n*****************************\n");
							printf("���¸����밴0���������ĸ�ѧ����Ϣ�밴1,������ĺ����Ϣ�밴2,�������򷵻����˵�:"); 
							scanf("%d",&again);	
							
							if (again == 1)
								ag = 1; 
							//����2 back == 2������������ĺ����Ϣ 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					  else if(change == 3)
					{
						int again;
						do
						{
							printf("\n*****************************");
							printf("\n��������ĵ��Ա���Ϣ��");
							scanf("%s", p->sid);
							
							//����������Ա���������ת��
							sidnameOne(Sidfilename, p);
							
							printf("\n*****************************\n");	
							printf("\n���ĳɹ���\n\n*****************************\n");
							printf("���¸����밴0���������ĸ�ѧ����Ϣ�밴1,������ĺ����Ϣ�밴2,�������򷵻����˵�:"); 
							scanf("%d",&again);
							
							if (again == 1)
								ag = 1; 
							//����2 back == 2������������ĺ����Ϣ 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					  else if(change == 4)
					{
						int again;
						do
						{
							printf("\n*****************************");
							printf("\n��������ĵ�ѧԺ��Ϣ��");
							scanf("%s", p->scid);
							
							//���������ѧԺ���������ת�� 
							scidnameOne(Scidfilename, p);
							
							printf("\n*****************************\n");	
							printf("\n���ĳɹ���\n\n*****************************\n");
							printf("���¸����밴0���������ĸ�ѧ����Ϣ�밴1,������ĺ����Ϣ�밴2,�������򷵻����˵�:"); 
							scanf("%d",&again);
								
							if (again == 1)
								ag = 1; 
							//����2 back == 2������������ĺ����Ϣ 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					 else if(change == 5)
					{
						int again;
						do
						{
						Cnum2:printf("\n**********��Ŀ��Ϣ************\n\n");
							int i;
							for( i = 0; i < num; i++)
								printf("%s��%s\n", (q + i)->nm, (q + i)->s);
							printf("\n*****************************\n");
							printf("\n������Ҫ���ĵĳɼ���Ŀ���(1-%d)��", num);
							int cnum;
							scanf("%d", &cnum);
							if (cnum >= 1 && cnum <= 4)
							{
								printf("\n��������ĺ��%s�ɼ���", (q + cnum - 1)->s);
								scanf("%d", &p->s[cnum - 1]);
								averageOne(p, Subjectfilename);
							 } 
							 else
							 {
							 	 printf("\n���������������������룡\n");
								 goto Cnum2;
							 }
							 
							printf("\n*****************************\n");	
							printf("\n���ĳɹ���\n\n*****************************\n");
							printf("���¸����밴0���������ĸ�ѧ����Ϣ�밴1,������ĺ����Ϣ�밴2,�������򷵻����˵�:"); 
							scanf("%d",&again);	
							
							if (again == 1)
								ag = 1; 
							//����2 back == 2������������ĺ����Ϣ 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					 else 
					 {
					 	printf("\n*****************************");
					 	printf("\n���������������������룡\n");
					 	printf("*****************************\n");
					 	system("pause");
						 ag = 1;
					}	
				}while (ag == 1);
			}
			break; 
		}
		p = p->next;
	}
	if(*flag == 1)
	{
		printf("\n*****************************");
		fprintf(stdout,"\n����Ϊ%s��ѧ����Ϣδ���ҵ���\n", findname);
		printf("\n*****************************\n");
		system("pause");
	 }	
}	

