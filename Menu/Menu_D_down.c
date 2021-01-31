#include "head_menu.h" 

//科目升序排序子菜单 
STU *Subject_Up_Menu (STU *p, char *KMidfilename, char *Outfilename, int *back) 
{
	int num = 0, i;
	KMID *q = Subjectfile(KMidfilename, &num);
	
	int again,ch;
	do
	{
		again = 0;
		
		printf("\n******学生成绩系统菜单*******\n\n");
		printf("学生成绩排序(科目)：\n\n");  
		//依次读入文件中的科目代码和科目名字 
		for(i = 0; i < num; i++)
			printf("%s：%s\n",(q + i)->nm, (q + i)->s);
		printf("0：返回上一级\n");
		printf("\n*****************************\n\n");
		printf("请输入需要执行的步骤："); 

		char n[L];
		//清除缓冲区 
		fflush(stdin);
		
		//输入 
		gets(n);
		
		int x = strlen (n);
		ch = 0;
		
		//判断是否正确输入数字 （学院个数小于100） 
		if(x > 2 || n[0] < '0' || n[0] > '9')
			ch = -1;
			
		//正确输入则转换成数字 
		if (ch == 0 && x == 1) 
			ch = n[0] - '0'; 
		else if (ch == 0 && x == 2) 
			ch = (n[0] - '0') * 10 + (n[1] - '0');  
		
		printf("\n*****************************\n");
		
		if (ch < 0 || ch > num)
		{
			printf("\n您的输入有误，请重新输入！\n\n");
			system("pause"); 
			again = 1;	
		}
		//返回上一步 
		else if (ch == 0)
		{	
			again = 0;
			//back == 1返回上一步
			*back = 1; 
		}
		else
		{
			//科目ch - 1升序排序 
			p = Subject_Sort_Up(p, ch - 1);
			//输出 升序：1 降序：2 
			outputcase2_Subject(Outfilename, p, 1, (q + ch - 1)->s, num, q);
			printf("\n*****************************");
			printf("\n返回上一步请输入1，返回主菜单请输入2或其它，退出请输入0：");
			scanf("%d", &again);
			//again == 1重复本do while 
			if (again == 0)
			{
				//back == 0,退出 
				*back = 0;
			} 
			else if (again != 1)
			{
				//back == 2,返回主菜单 
				*back = 2; 
			}
		}	
					
	}while (again == 1);
	
	return p;
}

//科目降序排序子菜单
STU *Subject_Down_Menu (STU *p, char *KMidfilename, char *Outfilename, int *back) 
{
	int num = 0, i;
	KMID *q = Subjectfile(KMidfilename, &num);
	
	int again,ch;
	do
	{
		again = 0;
		
		printf("\n******学生成绩系统菜单*******\n\n");
		printf("学生成绩排序(科目)：\n\n");  
		//依次读入文件中的科目代码和科目名字 
		for(i = 0; i < num; i++)
			printf("%s：%s\n",(q + i)->nm, (q + i)->s);
		printf("0：返回上一级\n");
		printf("\n*****************************\n\n");
		printf("请输入需要执行的步骤："); 

		char n[L];
		//清除缓冲区 
		fflush(stdin);
		
		//输入 
		gets(n);
		
		int x = strlen (n);
		ch = 0;
		
		//判断是否正确输入数字 （学院个数小于100） 
		if(x > 2 || n[0] < '0' || n[0] > '9')
			ch = -1;
			
		//正确输入则转换成数字 
		if (ch == 0 && x == 1) 
			ch = n[0] - '0'; 
		else if (ch == 0 && x == 2) 
			ch = (n[0] - '0') * 10 + (n[1] - '0');  
		
		printf("\n*****************************\n");
		
		if (ch < 0 || ch > num)
		{
			printf("\n您的输入有误，请重新输入！\n\n");
			system("pause"); 
			again = 1;	
		}
		//返回上一步 
		else if (ch == 0)
		{	
			again = 0;
			//back == 1返回上一步 
			*back = 1;
		}
		else
		{
			//科目ch - 1升序排序 
			p = Subject_Sort_Down(p, ch - 1);
			//输出 升序：1 降序：2 
			outputcase2_Subject(Outfilename, p, 1, (q + ch - 1)->s, num, q);
			printf("\n*****************************");
			printf("\n返回上一步请输入1，返回主菜单请输入2或其它，退出请输入0：");
			
			scanf("%d",&again);
			//again == 1重复本do while 
			if (again == 0)
			{
				//back == 0,退出 
				*back = 0;
			} 
			else if (again != 1)
			{
				//back == 2,返回主菜单 
				*back = 2; 
			}
		}	
			
	}while (again == 1);
	
	return p;
}
