#include "head_menu.h" 

//��Ŀ���������Ӳ˵� 
STU *Subject_Up_Menu (STU *p, char *KMidfilename, char *Outfilename, int *back) 
{
	int num = 0, i;
	KMID *q = Subjectfile(KMidfilename, &num);
	
	int again,ch;
	do
	{
		again = 0;
		
		printf("\n******ѧ���ɼ�ϵͳ�˵�*******\n\n");
		printf("ѧ���ɼ�����(��Ŀ)��\n\n");  
		//���ζ����ļ��еĿ�Ŀ����Ϳ�Ŀ���� 
		for(i = 0; i < num; i++)
			printf("%s��%s\n",(q + i)->nm, (q + i)->s);
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
			printf("\n���������������������룡\n\n");
			system("pause"); 
			again = 1;	
		}
		//������һ�� 
		else if (ch == 0)
		{	
			again = 0;
			//back == 1������һ��
			*back = 1; 
		}
		else
		{
			//��Ŀch - 1�������� 
			p = Subject_Sort_Up(p, ch - 1);
			//��� ����1 ����2 
			outputcase2_Subject(Outfilename, p, 1, (q + ch - 1)->s, num, q);
			printf("\n*****************************");
			printf("\n������һ��������1���������˵�������2���������˳�������0��");
			scanf("%d", &again);
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
		}	
					
	}while (again == 1);
	
	return p;
}

//��Ŀ���������Ӳ˵�
STU *Subject_Down_Menu (STU *p, char *KMidfilename, char *Outfilename, int *back) 
{
	int num = 0, i;
	KMID *q = Subjectfile(KMidfilename, &num);
	
	int again,ch;
	do
	{
		again = 0;
		
		printf("\n******ѧ���ɼ�ϵͳ�˵�*******\n\n");
		printf("ѧ���ɼ�����(��Ŀ)��\n\n");  
		//���ζ����ļ��еĿ�Ŀ����Ϳ�Ŀ���� 
		for(i = 0; i < num; i++)
			printf("%s��%s\n",(q + i)->nm, (q + i)->s);
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
			printf("\n���������������������룡\n\n");
			system("pause"); 
			again = 1;	
		}
		//������һ�� 
		else if (ch == 0)
		{	
			again = 0;
			//back == 1������һ�� 
			*back = 1;
		}
		else
		{
			//��Ŀch - 1�������� 
			p = Subject_Sort_Down(p, ch - 1);
			//��� ����1 ����2 
			outputcase2_Subject(Outfilename, p, 1, (q + ch - 1)->s, num, q);
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
		}	
			
	}while (again == 1);
	
	return p;
}
