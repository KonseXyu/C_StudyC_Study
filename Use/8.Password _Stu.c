#include "head_Use.h" 

//判断是否输入范围是否正确 
int Password_Right(char *p)
{
	//输入长度小于六或大于16 
	if(strlen(p) < 6 || strlen(p) > 16) 
		return 1;
		
	while(*p != '\0')
	{
		//是否在规定范围内(大小写字母和数字） 
		if( (strcmp(p,"@") > 0 && strcmp(p,"[") < 0) || (strcmp(p,"`") > 0 && strcmp(p,"{") < 0) || (strcmp(p,"/") > 0 && strcmp(p,":") < 0) )
			p++;
		else return 1;
	}
	return 0;
}

//未存在密码，进行密码创建 
void PasswordCreate(char *Passwordname)
{
	FILE *fpPassW = fopen (Passwordname, "w");
	if(fpPassW == NULL)
	{
		printf("fpPassW PasswordCreate[w] Error");
		return;
	 } 
	 
	 //flag：判断两次输入是否一致 
	int flag;
	printf("密码未设置,");
	do
	{
		flag = 0;
		char password[L] ,password2[L];
		
		//fg：判断输入范围是否正确 
		int fg;
		do
		{
			//设置登录密码 
			printf("请设置登录密码(6-16位,可包括数字0-9,字母A-Z,a-z)："); 
			scanf("%s",password);
			//fg == 1输入的与要求有误，fg == 0 输入正确！ 
			fg = Password_Right(password);
			
			if (fg == 1)
			{
				printf("\n***************************\n");
				printf("\n输入与要求有误！请重新输入!\n");
				printf("\n***************************\n");
			}			 
			
		}while(fg == 1);
		
		printf("\n请再次输入以确认登录密码："); 
		scanf("%s",password2);
		//判断两次输入的密码是否一致 
		if (strcmp(password, password2) == 0)
		{
			//密码加密 
			EncryptingPassword(password);
			
			fprintf(fpPassW, "%s", password);
			printf("\n**************\n");
			printf("\n密码设置成功！\n");
			printf("\n**************\n");
		}
		else
		{
			printf("\n********************************\n");
			printf("\n两次输入的密码不一致！请重新输入!\n");
			printf("\n********************************\n");
			flag = 1; 
		}
	}while(flag == 1);
	
	fclose(fpPassW);
	return;
} 

//已存在密码，进行密码登入 
void PasswordLoading(char *Passwordname,  FILE *fpPass)
{
	char password[L] ,loading[L];
	//从密码文件中获取密码信息 password 
	fgets(password, 1000, fpPass);
	int flag;
	do
	{
		printf("请输入登录密码：");
		flag = 0;
		scanf("%s", loading);
		
		//通过加密系统进行密码核对 
		EncryptingPassword(loading);
		
		//判断登入密码与系统文件中的密码信息是否一致 
		if(strcmp(password, loading) == 0)
		{
			printf("\n**************\n");
			printf("\n系统登入成功！\n");
			printf("\n**************\n");
		} 
		else 
		{
			printf("\n**************\n");
			printf("\n密码错误！\n");
			printf("\n**************\n");
			flag = 1;
		}	
	}while(flag == 1);
	
	fclose(fpPass);
	return;
}

//密码修改 
void PasswordChange(char *Passwordname) 
{
	//确认旧密码 
	FILE *fpPassR = fopen (Passwordname, "r");
	if(fpPassR == NULL)
	{
		printf("fpPassR PasswordChange[r] Error");
		return;
	 } 
	 
	char pw[L] ,loading[L];
	//在密码文件中获取密码信息PW 
	fgets(pw, 1000, fpPassR);
	//flag1：确认旧密码是否正确，flag2：确认新密码是否设置成功 
	int flag1,flag2;
	do
	{
		printf("\n请输入原登录密码（取消修改请输入0）：");
		flag1 = 0;
		scanf("%s", loading);
		
		//保存原密码信息用于比较新旧密码是否一致 
		char cmp[L];
		strcpy(cmp, loading);
		
		//取消修改 
		if (strcmp(loading, "0") == 0) 
		{
			printf("\n************\n");
			printf("\n修改已取消！\n"); 
			printf("\n*************\n");
			return;
		}
		
		//在密码文件信息中进行密码核对 
		EncryptingPassword(loading);
		
		if(strcmp(pw, loading) == 0)
		{	
			do
			{
				flag1 = 0; 
				flag2 = 0;
				
				//fg：判断输入范围是否正确 
				int fg;
				char password[L] ,password2[L];
				do
				{
					printf("\n请输入修改后的登录密码(6-16位,可包括数字0-9,字母A-Z,a-z)：");
					scanf("%s",password);
					
					//fg ==1 输入与要求有误，fg == 0 输入正常 
					fg = Password_Right(password);
					
					if (fg == 1)
					{
						printf("\n***************************\n");
						printf("\n输入与要求有误！请重新输入!\n");
						printf("\n***************************\n");
					}
						
						
					//判断与旧密码是否一致 
					if(strcmp(password, cmp) == 0)
					{
						printf("\n***********************************\n");
						printf("\n新密码不能与旧密码一致！请重新输入!\n");
						printf("\n***********************************\n");
						fg = 1; 
					 } 
				}while(fg == 1);
				
				
				printf("\n请再次输入修改后的登录密码以确认："); 
				scanf("%s",password2);
				
				//核对两次输入的密码是否一致 
				if (strcmp(password, password2) == 0)
				{
					fclose(fpPassR);
					
					//密码加密 
					EncryptingPassword(password);
					//输出新密码 
					FILE *fpPassC = fopen (Passwordname, "w");
					if(fpPassC == NULL)
					{
						printf("fpPassC PasswordChange[w] Error");
						return;
					 } 
					 
					fprintf(fpPassC, "%s", password);
					printf("\n**************\n");
					printf("\n密码修改成功！\n");
					printf("\n**************\n");
					
					fclose(fpPassC);
				}
				else
				{
					printf("\n*********************************\n");
					printf("\n两次输入的密码不一致！请重新输入!\n");
					printf("\n*********************************\n");
					flag1 = 1; 
				}
			}while(flag1 == 1);
		}
		else
		{
			printf("\n***************************\n");
			printf("\n原密码输入有误！请重新输入!\n");
			printf("\n***************************\n");
			flag2 = 1; 
		} 
	}while(flag2 == 1); 

	return;
} 
