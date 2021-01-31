#include "head_Use.h" 

//�ж��Ƿ����뷶Χ�Ƿ���ȷ 
int Password_Right(char *p)
{
	//���볤��С���������16 
	if(strlen(p) < 6 || strlen(p) > 16) 
		return 1;
		
	while(*p != '\0')
	{
		//�Ƿ��ڹ涨��Χ��(��Сд��ĸ�����֣� 
		if( (strcmp(p,"@") > 0 && strcmp(p,"[") < 0) || (strcmp(p,"`") > 0 && strcmp(p,"{") < 0) || (strcmp(p,"/") > 0 && strcmp(p,":") < 0) )
			p++;
		else return 1;
	}
	return 0;
}

//δ�������룬�������봴�� 
void PasswordCreate(char *Passwordname)
{
	FILE *fpPassW = fopen (Passwordname, "w");
	if(fpPassW == NULL)
	{
		printf("fpPassW PasswordCreate[w] Error");
		return;
	 } 
	 
	 //flag���ж����������Ƿ�һ�� 
	int flag;
	printf("����δ����,");
	do
	{
		flag = 0;
		char password[L] ,password2[L];
		
		//fg���ж����뷶Χ�Ƿ���ȷ 
		int fg;
		do
		{
			//���õ�¼���� 
			printf("�����õ�¼����(6-16λ,�ɰ�������0-9,��ĸA-Z,a-z)��"); 
			scanf("%s",password);
			//fg == 1�������Ҫ������fg == 0 ������ȷ�� 
			fg = Password_Right(password);
			
			if (fg == 1)
			{
				printf("\n***************************\n");
				printf("\n������Ҫ����������������!\n");
				printf("\n***************************\n");
			}			 
			
		}while(fg == 1);
		
		printf("\n���ٴ�������ȷ�ϵ�¼���룺"); 
		scanf("%s",password2);
		//�ж���������������Ƿ�һ�� 
		if (strcmp(password, password2) == 0)
		{
			//������� 
			EncryptingPassword(password);
			
			fprintf(fpPassW, "%s", password);
			printf("\n**************\n");
			printf("\n�������óɹ���\n");
			printf("\n**************\n");
		}
		else
		{
			printf("\n********************************\n");
			printf("\n������������벻һ�£�����������!\n");
			printf("\n********************************\n");
			flag = 1; 
		}
	}while(flag == 1);
	
	fclose(fpPassW);
	return;
} 

//�Ѵ������룬����������� 
void PasswordLoading(char *Passwordname,  FILE *fpPass)
{
	char password[L] ,loading[L];
	//�������ļ��л�ȡ������Ϣ password 
	fgets(password, 1000, fpPass);
	int flag;
	do
	{
		printf("�������¼���룺");
		flag = 0;
		scanf("%s", loading);
		
		//ͨ������ϵͳ��������˶� 
		EncryptingPassword(loading);
		
		//�жϵ���������ϵͳ�ļ��е�������Ϣ�Ƿ�һ�� 
		if(strcmp(password, loading) == 0)
		{
			printf("\n**************\n");
			printf("\nϵͳ����ɹ���\n");
			printf("\n**************\n");
		} 
		else 
		{
			printf("\n**************\n");
			printf("\n�������\n");
			printf("\n**************\n");
			flag = 1;
		}	
	}while(flag == 1);
	
	fclose(fpPass);
	return;
}

//�����޸� 
void PasswordChange(char *Passwordname) 
{
	//ȷ�Ͼ����� 
	FILE *fpPassR = fopen (Passwordname, "r");
	if(fpPassR == NULL)
	{
		printf("fpPassR PasswordChange[r] Error");
		return;
	 } 
	 
	char pw[L] ,loading[L];
	//�������ļ��л�ȡ������ϢPW 
	fgets(pw, 1000, fpPassR);
	//flag1��ȷ�Ͼ������Ƿ���ȷ��flag2��ȷ���������Ƿ����óɹ� 
	int flag1,flag2;
	do
	{
		printf("\n������ԭ��¼���루ȡ���޸�������0����");
		flag1 = 0;
		scanf("%s", loading);
		
		//����ԭ������Ϣ���ڱȽ��¾������Ƿ�һ�� 
		char cmp[L];
		strcpy(cmp, loading);
		
		//ȡ���޸� 
		if (strcmp(loading, "0") == 0) 
		{
			printf("\n************\n");
			printf("\n�޸���ȡ����\n"); 
			printf("\n*************\n");
			return;
		}
		
		//�������ļ���Ϣ�н�������˶� 
		EncryptingPassword(loading);
		
		if(strcmp(pw, loading) == 0)
		{	
			do
			{
				flag1 = 0; 
				flag2 = 0;
				
				//fg���ж����뷶Χ�Ƿ���ȷ 
				int fg;
				char password[L] ,password2[L];
				do
				{
					printf("\n�������޸ĺ�ĵ�¼����(6-16λ,�ɰ�������0-9,��ĸA-Z,a-z)��");
					scanf("%s",password);
					
					//fg ==1 ������Ҫ������fg == 0 �������� 
					fg = Password_Right(password);
					
					if (fg == 1)
					{
						printf("\n***************************\n");
						printf("\n������Ҫ����������������!\n");
						printf("\n***************************\n");
					}
						
						
					//�ж���������Ƿ�һ�� 
					if(strcmp(password, cmp) == 0)
					{
						printf("\n***********************************\n");
						printf("\n�����벻���������һ�£�����������!\n");
						printf("\n***********************************\n");
						fg = 1; 
					 } 
				}while(fg == 1);
				
				
				printf("\n���ٴ������޸ĺ�ĵ�¼������ȷ�ϣ�"); 
				scanf("%s",password2);
				
				//�˶���������������Ƿ�һ�� 
				if (strcmp(password, password2) == 0)
				{
					fclose(fpPassR);
					
					//������� 
					EncryptingPassword(password);
					//��������� 
					FILE *fpPassC = fopen (Passwordname, "w");
					if(fpPassC == NULL)
					{
						printf("fpPassC PasswordChange[w] Error");
						return;
					 } 
					 
					fprintf(fpPassC, "%s", password);
					printf("\n**************\n");
					printf("\n�����޸ĳɹ���\n");
					printf("\n**************\n");
					
					fclose(fpPassC);
				}
				else
				{
					printf("\n*********************************\n");
					printf("\n������������벻һ�£�����������!\n");
					printf("\n*********************************\n");
					flag1 = 1; 
				}
			}while(flag1 == 1);
		}
		else
		{
			printf("\n***************************\n");
			printf("\nԭ����������������������!\n");
			printf("\n***************************\n");
			flag2 = 1; 
		} 
	}while(flag2 == 1); 

	return;
} 
