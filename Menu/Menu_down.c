#include "head_menu.h" 

//�����������Ӳ˵� 
STU *Menu_Name (STU *p, int *choose)
{
	int again,ch;
	do
	{
		again = 0;
		
		printf("\n******ѧ���ɼ�ϵͳ�˵�*******\n\n"); 
		printf("ѧ��������Ϣ����\n\n"); 
		printf("1�������ֽ�������\n");
		printf("2����������������\n");
		printf("0��������һ��\n");
		printf("\n*****************************\n\n");
		printf("��������Ҫִ�еĲ��裺"); 
		
		char n[L];
		//��������� 
		fflush(stdin);
		//���� 
		gets(n);
		
		//�ж��Ƿ���ȷ�������� 
		if(strlen(n) > 1 || strcmp(n, "0") < 0 || strcmp(n, "9") > 0)
			ch = -1;
		else
			ch = n[0] - '0'; 
			 
		printf("\n*****************************\n");
		
		*choose = ch;
		switch (ch)
		{
			case 0: break;
			 
			case 1:
			{
				//name�������� 
				p = sortStunameDown(p);
				break; 
			}
			
			case 2:
			{
				//name�������� 
				p = sortStunameUp(p);
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n���������������������룡\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
	}while (again == 1);
	
	return  p;
}

//���ɼ������Ӳ˵� 
STU *Menu_Score (STU *p, int *choose, int *back, char *KMidfilename, char *Outfilename, int Snum, KMID *Sub)
{
	int again,ch;
	do
	{
		again = 0;
		
		printf("\n******ѧ���ɼ�ϵͳ�˵�*******\n\n");
		printf("ѧ���ɼ�����\n\n");
		printf("1���ɼ�����(����Ŀ)����\n");  
		printf("2���ɼ�����(����Ŀ)����\n");  
		printf("********************\n");
		printf("3���ɼ�����(��ƽ���ɼ�)����\n"); 
		printf("4���ɼ�����(��ƽ���ɼ�)����\n"); 
		printf("\n0��������һ��\n");
		printf("\n*****************************\n\n");
		printf("��������Ҫִ�еĲ��裺"); 

		char n[L];
		//��������� 
		fflush(stdin);
		//���� 
		gets(n);
		
		//�ж��Ƿ���ȷ�������� 
		if(strlen(n) > 1 || strcmp(n, "0") < 0 || strcmp(n, "9") > 0)
			ch = -1;
		else
			ch = n[0] - '0'; 
			
		printf("\n*****************************\n");
		
		switch (ch)
		{
			case 0: break;
			 
			case 1:
			{
				//��Ŀ�������� 
				p = Subject_Up_Menu (p, KMidfilename, Outfilename, back);
				//back = 1 -> ������һ��->again = 1���б�ѭ�� 
				if (*back == 1)
				{
					//�ظ���do while 
					again = 1;
				}
				else if(*back == 0)
				{
					//back == 0 && choose == 0�˳�ϵͳ 
					*choose = 0;
					again = 0; 
				}
				//back ��Ϊ0��1 (== 2)
				else 
				{
					//choose != 0 �������˵�
					*choose = 1;
					again = 0;
				}
				
				break; 
			}
			
			case 2:
			{
				//��Ŀ�������� 
				p = Subject_Down_Menu (p, KMidfilename, Outfilename, back);
				//back = 1 -> ������һ��->again = 1���б�ѭ�� 
				if (*back == 1)
				{
					//�ظ���do while 
					again = 1;
				}
				else if(*back == 0)
				{
					//back == 0 && choose == 0�˳�ϵͳ 
					*choose = 0;
					again = 0; 
				}
				//back ��Ϊ0��1 
				else 
				{
					//choose != 0 �������˵�
					*choose = 1;
					again = 0;
				}
				break; 
			}
			
			case 3:
			{
				//ƽ���ɼ��������� ��== 3�� 
				p = sortStuscoreUp(p);
				outputcase2_Average(Outfilename, p, 3, Snum, Sub);
				
				printf("\n*****************************");
				printf("\n������һ��������1���������˵�������2���������˳�������0��");
				
				scanf("%d",&again);
				//again == 1�ظ���do while 
				if (again == 0)
				{
					//back == 0,�˳� 
					*back = 0;
				} 
				else if (again != 1)
				{
					//back == 2,�������˵� 
					*back = 2; 
				}
				
				break; 
			}
			
			case 4:
			{
				//ƽ���ɼ��������� ��== 4�� 
				p = sortStuscoreDown(p);
				outputcase2_Average(Outfilename, p, 4, Snum, Sub);
				
				printf("\n*****************************");
				printf("\n������һ��������1���������˵�������2���������˳�������0��");
				
				scanf("%d",&again);
				//again == 1�ظ���do while 
				if (again == 0)
				{
					//back == 0,�˳� 
					*back = 0;
				} 
				else if (again != 1)
				{
					//back == 2,�������˵� 
					*back = 2; 
				}
				break; 
			}
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n���������������������룡\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
	}while (again == 1);
	
	return  p;
}

//Ѱ��ָ��ѧԺ�Ӳ˵���donum == 1�� �� �ҿư�ѧԺ��ѯ��donum == 2�� 
void Menu_Scidfind (STU *p, int *choose, char *Scidfilename, char *Subjectfilename, int donum)
{
	int num = 0, i;
	SCID *q = Scidfile (Scidfilename, &num);
	
	int again, ch = 0;
	do
	{
		again = 0;
		
		printf("\n******ѧ���ɼ�ϵͳ�˵�*******\n\n");
		printf("Ѱ�����ѧԺ��ѧ����Ϣ��\n\n"); 
		//���ζ����ļ��е�ѧԺ�����ѧԺ���� 
		for(i = 0; i < num; i++)
			printf("%s��%s\n", (q + i)->nm, (q + i)->s);
		printf("0��������һ��\n");
		printf("\n*****************************\n\n");
		printf("��������Ҫִ�еĲ��裺"); 
		
		char n[L];
		//��������� 
		fflush(stdin);
		
		//���� 
		gets(n);
		
		int x = strlen (n);
		ch = 0;
		
		//�ж��Ƿ���ȷ�������� ��ѧԺ����С��100�� 
		if(x > 2 || n[0] < '0' || n[0] > '9')
			ch = -1;
			
		//��ȷ������ת�������� 
		if (ch == 0 && x == 1) 
			ch = n[0] - '0'; 
		else if (ch == 0 && x == 2) 
			ch = (n[0] - '0') * 10 + (n[1] - '0'); 

		printf("\n*****************************\n");

		if (ch < 0 || ch > num)
		{
			printf("\n*****************************\n");
		 	printf("\n���������������������룡\n");
		 	printf("\n*****************************\n");
			system("pause"); 
			again = 1;	
		}
		//donum == 1��ѧԺѧ�����Ҳ��� 
		else if (donum == 1)
		{
			*choose = ch;
			//ch -  1 :��Ӧ�ļ��е�λ�� q + 1 -1 Ϊ�ļ��еĵ�һ�� 
			searchScid (p, (q + ch - 1)->s, Subjectfilename);
		}
		//donum == 2��ѧԺ�ҿ�ѧ����Ϣ���Ҳ���
		else if (donum == 2) 
		{
			*choose = ch;
			if(*choose != 0)
			{
				ScidLowpoint (p, (q + ch - 1)->s);  
				printf("\n*****************************");
				printf("\n������һ��������1���������˵�������2���������˳�������0��");
				scanf("%d",&again);
				//choose == -1�˳�ϵͳ 
				*choose = again - 1; 
			}
			else again = 0;
		}
		
	}while(again == 1);
	
	return;	
}

//addѧ���Ӳ˵� 
STU *Menu_Add (STU *p, int *choose, int *num, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back)
{
	int again,ch;
	do
	{
		again = 0;
		
		printf("\n******ѧ���ɼ�ϵͳ�˵�*******\n\n");
		printf("����ѧ����Ϣ��\n\n");  
		printf("1���ڱ�Ŀ�ͷ����ѧ����Ϣ\n");
		printf("2���ڱ�Ľ�β����ѧ����Ϣ\n");
		printf("0��������һ��\n");
		printf("\n*****************************\n\n");
		printf("��������Ҫִ�еĲ��裺");
		
		char n[L];
		//��������� 
		fflush(stdin);
		//���� 
		gets(n);
		
		//�ж��Ƿ���ȷ�������� 
		if(strlen(n) > 1 || strcmp(n, "0") < 0 || strcmp(n, "9") > 0)
			ch = -1;
		else
			ch = n[0] - '0'; 
			
		printf("\n*****************************\n");
		
		*choose = ch;
		switch (ch)
		{
			case 0: break;
			 
			case 1:
			{
				//�ڱ�ͷ���� 
				p = addIdUp(p, num, Sidfilename, Scidfilename, Subjectfilename);
				printf("\n*****************************");
				printf("\n��������������1������Ӻ����Ϣ�밴2,�������򷵻����˵�:");
				scanf("%d",&again);
					//back == 2 ������Ӻ���Ϣ 
					if (again == 2)
						*back = 2;
				break; 
			}
			
			case 2:
			{
				//�ڱ�β���� 
				p = addIdDown(p, num, Sidfilename, Scidfilename, Subjectfilename);
				printf("\n*****************************");
				printf("\n��������������1,������Ӻ����Ϣ�밴2,�������򷵻����˵�:");
				scanf("%d",&again);
					//back == 2 ������Ӻ���Ϣ 
					if (again == 2)
						*back = 2;
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n���������������������룡\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
		
	}while (again == 1);
	
	return  p;
}

//�޸�ѧ����Ϣ�Ӳ˵� 
void Menu_Modify (STU *p, int *choose, int *flag, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back) 
{
	int again, ch;
	do
	{
		again = 0;
		printf("\n******ѧ���ɼ�ϵͳ�˵�*******\n\n"); 
		printf("�޸�ѧ����Ϣ��\n\n"); 
		printf("1����ѧ���޸���Ϣ\n");
		printf("2���������޸���Ϣ\n");
		printf("0��������һ��\n");
		printf("\n*****************************\n\n");
		printf("��������Ҫִ�еĲ��裺");
		
		char n[L];
		//��������� 
		fflush(stdin);
		//���� 
		gets(n);
		
		//�ж��Ƿ���ȷ�������� 
		if(strlen(n) > 1 || strcmp(n, "0") < 0 || strcmp(n, "9") > 0)
			ch = -1;
		else
			ch = n[0] - '0'; 
			 
		printf("\n*****************************\n");
		
		*choose = ch;
		switch (ch)
		{
			case 0: break;
			 
			case 1:
			{ 
				//ָ��id�޸� 
				ModifyID(p, flag, Sidfilename, Scidfilename, Subjectfilename, back);
				break; 
			}
			
			case 2:
			{ 
				//ָ�������޸� 
				ModifyName(p, flag, Sidfilename, Scidfilename, Subjectfilename, back);
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n���������������������룡\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}
			
	}while (again == 1);

	return;
} 

//Ѱ��ѧ����Ϣ�Ӳ˵� 
void Menu_SearchStu (STU *p, char *Subjectfilename, int *choose) 
{
	int again, ch;
	do
	{
		again = 0; 
		
		printf("\n******ѧ���ɼ�ϵͳ�˵�*******\n\n");
		printf("Ѱ��ѧ����Ϣ��\n\n"); 
		printf("1����ѧ�Ų���ѧ����Ϣ\n");
		printf("2������������ѧ����Ϣ\n");
		printf("0��������һ��\n");
		printf("\n*****************************\n\n");
		printf("��������Ҫִ�еĲ��裺");
		
		char n[L];
		//��������� 
		fflush(stdin);
		//���� 
		gets(n);
		
		//�ж��Ƿ���ȷ�������� 
		if(strlen(n) > 1 || strcmp(n, "0") < 0 || strcmp(n, "9") > 0)
			ch = -1;
		else
			ch = n[0] - '0'; 
			
		printf("\n*****************************\n");
		
		switch (ch)
		{
			case 0: break;
			 
			case 1:
			{
				//��ѯ����ѧ�ŵ�ѧ����Ϣ
				SearchID (Subjectfilename, p);
				printf("\n*****************************");
				printf("\n������һ��������1���������˵�������2���������˳�������0��");
				scanf("%d",&again);	
				if (again == 0)
					*choose = -1;
				break; 
			}
			
			case 2:
			{
				//��ѯ�������ֵ�ѧ����Ϣ
				SearchName (Subjectfilename, p);
				printf("\n*****************************");
				printf("\n������һ��������1���������˵�������2���������˳�������0��");
				scanf("%d",&again);	
				if (again == 0)
					*choose = -1;
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n���������������������룡\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
	}while (again == 1);
	
	return;
}

//ɾ��ѧ����Ϣ�Ӳ˵� 
STU *Menu_Del (STU *p, int *choose, int *num, int *flg, int Snum, int *back) 
{
	int again, ch;
	do
	{
		again = 0;
		
		printf("\n******ѧ���ɼ�ϵͳ�˵�*******\n\n");
		printf("ɾ��ѧ����Ϣ��\n\n");  
		printf("1����ѧ�Ų��Ҳ�ɾ����Ϣ\n");
		printf("2�����������Ҳ�ɾ����Ϣ\n");
		printf("0��������һ��\n");
		printf("\n*****************************\n\n");
		printf("��������Ҫִ�еĲ��裺"); 
		
		char n[L];
		//��������� 
		fflush(stdin);
		//���� 
		gets(n);
		
		//�ж��Ƿ���ȷ�������� 
		if(strlen(n) > 1 || strcmp(n, "0") < 0 || strcmp(n, "9") > 0)
			ch = -1;
		else
			ch = n[0] - '0'; 
			 
		printf("\n*****************************\n");
		
		//��test = num��û���й�ɾ������ 
		int test = *num;
		*choose = ch;
		switch (ch)
		{
			case 0: break;
			
			case 1:
			{
				//ɾ��ָ��id 
				p = delID(p, num, flg, Snum);
				if (*flg == 0)
				{
					printf("\n********************\n");
					printf("������һ���밴1,�������򷵻����˵�:");
					scanf("%d",&again);
					//back == 0 ,�������˵� 
					if (again == 1)
						(*flg)++; 
					else if (test == *num) 
						*back = 0; 
				}
				else
				{
					printf("\n********************\n");
					printf("ɾ�������ɹ���"); 
					printf("\n********************\n");
					printf("\n����ɾ���밴1,���ɾ�������Ϣ�밴2,�������򷵻����˵�:");
					scanf("%d",&again);
					//back == 2 ���ɾ������Ϣ 
					if (again == 2)
						*back = 2;
				}
				
				break; 
			}
			
			case 2:
			{
				//ɾ��ָ������ 
				p = delName(p, num, flg, Snum);
				
				if (*flg == 0)
				{
					
					printf("\n*****************************\n");
					printf("������һ���밴1,�������򷵻����˵�:");
					scanf("%d",&again);
					//back == 0 ,�������˵� 
					if (again == 1)
						(*flg)++; 
					else if (test == *num) 
						*back = 0; 
				}
				else
				{
					printf("\n********************\n");
					printf("ɾ�������ɹ���"); 
					printf("\n********************\n");
					printf("\n����ɾ���밴1,���ɾ�������Ϣ�밴2,�������򷵻����˵�:");
					scanf("%d",&again);
					//back == 2 ���ɾ������Ϣ 
					if (again == 2)
						*back = 2; 
				}
				
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n���������������������룡\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
	}while (again == 1);
	
	return  p;
} 

//���ҹҿ�ѧ���Ӳ˵� 
void Menu_LowPoint (STU *p, int *choose, char *Scidfilename, char *Subjectfilename, int donum)
{
	int again, ch;
	do
	{
		again = 0;
		
		printf("\n******ѧ���ɼ�ϵͳ�˵�*******\n\n");
		printf("�ҿ�ѧ����Ϣ��\n\n");  
		printf("1�����ȫ���ҿ�ѧ����Ϣ\n");
		printf("2����ѧԺ���ҹҿ�ѧ����Ϣ\n");
		printf("0��������һ��\n");
		printf("\n*****************************\n\n");
		printf("��������Ҫִ�еĲ��裺"); 
		
		char n[L];
		//��������� 
		fflush(stdin);
		//���� 
		gets(n);
		
		//�ж��Ƿ���ȷ�������� 
		if(strlen(n) > 1 || strcmp(n, "0") < 0 || strcmp(n, "9") > 0)
			ch = -1;
		else
			ch = n[0] - '0'; 
			 
		printf("\n*****************************\n");

		*choose = ch;
		switch (ch)
		{
			case 0: break;
			 
			case 1:
			{
				int back = 0;
				//���ÿ���ҿ��˵���Ϣ
				Lowpoint(p, &back);
				//�ٴν��������dowhile 
				if (back == 1) 
				{
					again = 1;
				}
				//back == 0�˳�ϵͳ 
				else if (back == 0)
				{
					again = 0;
					*choose = -1;
				} 
				break; 
			}
			
			case 2:
			{
				int donum = 2;
				//ָ��ѧԺ��ѧ����Ϣ 
				Menu_Scidfind (p, choose, Scidfilename, Subjectfilename, donum);
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n���������������������룡\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
	}while (again == 1);
}

