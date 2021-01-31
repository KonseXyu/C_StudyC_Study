#include "head_menu.h" 

void Menu()
{
	//�����ļ����� 
	char *Inputfilename = "Stu_Info.txt"; 
	
	//���������ļ����� 
	char *Sidfilename = "S_Info2.txt" ;
	
	 //ѧԺ�����ļ����� 
	char *Scidfilename = "C_Code.txt";
	
	//��Ŀ�����ļ����� 
	char *Subjectfilename = "KM_info.txt"; 
	
	//����ļ����� 
	char *Outfilename = "Stu_Info_Output.txt" ;	
	
	//������Ϣ 
	char *Passwordname = "Password_Stu" ;
	
	//���е�¼ 
	FILE *fpPass = fopen (Passwordname, "r");
	
	//�������ܳ��ļ������ܳ��ļ�Ϊ�� 
	if(fpPass == NULL || fgetc(fpPass) == EOF)
	{
		fclose(fpPass);
		//δ�������� 
		PasswordCreate(Passwordname);
	}
	else
	{
		//�ܳ��ļ���Ϊ�գ��ƶ�ָ��λ�õ���ͷ��ȡ�ܳ��ļ� 
		rewind(fpPass);
		//�Ѵ������� 
		PasswordLoading(Passwordname, fpPass);
		fclose(fpPass);
	}
	 
	int num = 0, again = 1;
	
	//��Ϣ���� 
 	STU *p = inputSTU(Inputfilename, &num); 
 	if(p == NULL)
	{
	 	printf("inputSTU Error");
		 return; 
	}
	printf("�����ѧ��������%d��\n\n",num);
	
	//��average 
	average(p, Subjectfilename);
	
	//�Ա����ת�� 
	sidname(Sidfilename, p, num);
	 
	//ѧԺ����ת�� 
	scidname(Scidfilename, p, num);
	

	int Snum;
 	//��ȡ��Ŀ��Ϣ 
 	KMID *Sub = Subjectfile(Subjectfilename, &Snum);
 	
	printf("�ļ���Stu_Info3.txt������Ϣ��ȫ�����룡��\n");
	
	do
	{
		printf("\n******ѧ���ɼ�ϵͳ�˵�*******\n\n");
		printf("1����������������ʾ��Ϣ\n"); 
		printf("2������ƽ���ɼ�������ʾ��Ϣ\n"); 
		printf("3����ʾ����ѧԺ��ѧ����Ϣ\n"); 
		printf("4������ѧ����Ϣ\n"); //��ͷ���ӻ��β���� 
		printf("5���޸�ѧ����Ϣ\n"); //����ѧ�Ż�����
		printf("6����ѯѧ����Ϣ\n"); //����ѧ�Ż�����
		printf("7��ɾ��ѧ����Ϣ\n"); //����ѧ�Ż�����
		printf("8���޸�ϵͳ����\n"); 
		printf("9������ҿ�ѧ����Ϣ\n"); 
		printf("0���˳�ϵͳ\n"); //������һ���˵�
		printf("\n*****************************\n\n");    
		printf("��������Ҫִ�еĲ��裺"); 

		int flag;
		
		char n[L];
		//��������� 
		fflush(stdin);
		//���� 
		gets(n);
		
		//�ж��Ƿ���ȷ�������� 
		if(strlen(n) > 1 || strcmp(n, "0") < 0 || strcmp(n, "9") > 0)
			flag = -1;
		else
			flag = n[0] - '0'; 
			
		switch (flag)
		{
			case 0: 
			{
				//�˳�ϵͳ 
				again = 0; 
				break ;	
			}
			//�������� 
			case 1: 
			{
				//�������ѧ��Ϊ�� 
				if(num == 0)
				{
					printf("\nѧ����ϢΪ�գ��޷��������������\n");
					printf("\n*****************************");
					printf("\n���ز˵����������������˳�������0��");
					scanf("%d",&again); 
					break;
				}
				
				int choose = 0;
				p = Menu_Name (p ,&choose);
				//1�������ֽ�������2���������������� 
				if(choose == 1 || choose == 2)
				{
					outputcase1(Outfilename, p, choose, Snum, Sub);
					printf("\n*****************************"); 
					printf("\n���ز˵����������������˳�������0��");
					scanf("%d",&again);
				}
				//0��������һ���˵�
				else again = 1;
				
				break;  
			}
			//�ɼ�����		
			case 2: 
			{
				//�������ѧ��Ϊ��
				if(num == 0)
				{
					printf("\nѧ����ϢΪ�գ��޷��������������\n");
					printf("\n*****************************");
					printf("\n���ز˵����������������˳�������0��");
					scanf("%d",&again); 
					break;
				}
				
				int choose = 0, back = 1;
				p = Menu_Score (p , &choose, &back, Subjectfilename, Outfilename, Snum, Sub);
				//back == 0 && choose == 0�˳�ϵͳ 
				if(back == 0 && choose == 0)
					again = 0;
				//������б�ѭ�� 
				else if (choose == 1) 
					again = 1; 
				
				break;	
			}	
						
			case 3:
			{
				if(num == 0)
				{
					printf("\nѧ����ϢΪ�գ��޷����в�ѯ������\n");
					printf("\n*****************************");
					printf("\n���ز˵����������������˳�������0��");
					scanf("%d",&again); 
					break;
				}
				
				int choose = 0, again2, donum = 1;
				do
				{
					//ָ��ѧԺ��ѧ����Ϣ 
					Menu_Scidfind (p, &choose, Scidfilename, Subjectfilename, donum);
				
					if(choose != 0)
					{
						printf("\n*****************************");
						printf("\n������һ��������1���������˵�������2���������˳�������0��");
						scanf("%d",&again2);
						if(again2 == 0)
							again = 0;
						else if (again2 != 1) 
							again = 1;
					}
					//0��������һ���˵�
					else if (choose == 0)
					{
						again = 1; 
						break;
					}
					
				}while (again2 == 1);
				
				break;
			} 	
					
			case 4:
			{
				//����ָ����ѧ�� 
				int choose, back = 1;
				p = Menu_Add (p, &choose, &num, Sidfilename, Scidfilename, Subjectfilename, &back);
				//0��������һ���˵�
				if(choose == 0)	
					again = 1;
				else if (back == 2)
				{
					outputcase4 (Outfilename, p, num, Snum, Sub);
					printf("\n*****************************");
					printf("\n���ز˵����������������˳�������0��");
					scanf("%d",&again);
				}
				else
				{
					outputcase4_File (Outfilename, p, num, Snum, Sub);	
					again = 1;
				}
				
				
				break;
			}
					
			case 5:
			{
				if(num == 0)
				{
					printf("\nѧ����ϢΪ�գ��޷������޸Ĳ�����\n");
					printf("\n*****************************");
					printf("\n���ز˵����������������˳�������0��");
					scanf("%d",&again); 
					break;
				}
				//flag���ж��Ƿ��ҵ�ҪѰ�ҵ�ѧ����Ϣ 
				int flag = 1, choose =0, back = 0;
				
				//�޸�ָ����ѧ����Ϣ
				Menu_Modify (p, &choose, &flag, Sidfilename, Scidfilename, Subjectfilename, &back);
				
				if (choose == 1 || choose == 2) 
				{
					//���ҵ���Ӧ��ѧ����Ϣ�����޸��������� 
					if(flag == 0 && back == 2)
					{
						outputcase5(Outfilename, p, Snum, Sub); 
						printf("\n*****************************");
						printf("\n���ز˵����������������˳�������0��");
						scanf("%d",&again);
					}
					else if (back != 2)
					{
						//�޸�ѧ����Ϣ����е����ļ���� 
						outputcase5_File(Outfilename, p, Snum, Sub); 
						again = 1;
					}
				}
				//0��������һ���˵�
				else
				   again = 1;
				
					
				break; 	
			} 	
						
			case 6: 
			{
				if(num == 0)
				{
					printf("\nѧ����ϢΪ�գ��޷����в�ѯ������\n");
					printf("\n*****************************");
					printf("\n���ز˵����������������˳�������0��");
					scanf("%d",&again); 
					break;
				}
				int choose = 0;
				
				//Ѱ��ָ����ѧ�� 
				Menu_SearchStu (p, Subjectfilename, &choose);
				
				//choose == -1 �˳�ϵͳ��������д�do while 
				if (choose == -1)
					again = 0;
				 else 
				 	again = 1;
				break; 
			} 

			case 7: 
			{
				//ɾ��ָ����ѧ�� 
				//��ѧ��Ϊ�� 
				if(num == 0)
				{
					printf("\nѧ����ϢΪ�գ��޷�����ɾ��������\n");
					printf("\n*****************************");
					printf("\n���ز˵����������������˳�������0��");
					scanf("%d",&again); 
					break;
				}
				
				int flg = 1, choose = 0, back = 1;
				//ɾ������ 
				p = Menu_Del (p, &choose, &num, &flg, Snum, &back);
				if(choose != 0)
				{
					//back == 0 ,�������˵� back == 2 ���ɾ������Ϣ 
					if (back == 0)
					{
						again = 1;
					}
					else if (back == 2)
					{
						outputcase7 (Outfilename, p, num, Snum, Sub);
						printf("\n*****************************");
						printf("\n���ز˵����������������˳�������0��");
						scanf("%d",&again);
					}
					else
					{
						outputcase7_File (Outfilename, p, num, Snum, Sub);	
						again = 1;
					}
				}
				else
					again = 1;
				
				break; 
			} 
				
			case 8:
			{
				//�����޸� 
				PasswordChange(Passwordname);
				printf("\n*****************************");
				printf("\n���ز˵����������������˳�������0��");
				scanf("%d",&again);
				break;
			} 
			case 9: 
			{
				//�ҿ�ѧ������ 
				if(num == 0)
				{
					printf("\nѧ����ϢΪ�գ��޷����в�����\n");
					printf("\n*****************************");
					printf("\n���ز˵����������������˳�������0��");
					scanf("%d",&again); 
					break;
				}
				
				int choose = 0, donum = 2;
				
				//�ҿ�ѧ����Ϣ�Ӳ˵� 
				Menu_LowPoint (p, &choose, Scidfilename, Subjectfilename, donum);
				
				//choose == -1�˳�ϵͳ
				if (choose == -1)
					again = 0;
				else if(choose != 0)
					again = 1;
				
				
				break;
			}		

			default: 
			{
				printf("\n*****************************");
			 	printf("\n���������������������룡\n");
			 	printf("*****************************\n");
				system("pause");
			}
		 }	
	 } while (again != 0);
	 free(p); 
	 printf("\n****************************\n\n");
	 printf("\n\tϵͳ���˳���\n");
	 printf("\n\n****************************\n");
	 return;
}

