#include "head_menu.h" 

//按名字排序子菜单 
STU *Menu_Name (STU *p, int *choose)
{
	int again,ch;
	do
	{
		again = 0;
		
		printf("\n******学生成绩系统菜单*******\n\n"); 
		printf("学生名字信息排序：\n\n"); 
		printf("1：按名字降序排序\n");
		printf("2：按名字升序排序\n");
		printf("0：返回上一级\n");
		printf("\n*****************************\n\n");
		printf("请输入需要执行的步骤："); 
		
		char n[L];
		//清除缓冲区 
		fflush(stdin);
		//输入 
		gets(n);
		
		//判断是否正确输入数字 
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
				//name降序排序 
				p = sortStunameDown(p);
				break; 
			}
			
			case 2:
			{
				//name升序排序 
				p = sortStunameUp(p);
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n您的输入有误！请重新输入！\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
	}while (again == 1);
	
	return  p;
}

//按成绩排序子菜单 
STU *Menu_Score (STU *p, int *choose, int *back, char *KMidfilename, char *Outfilename, int Snum, KMID *Sub)
{
	int again,ch;
	do
	{
		again = 0;
		
		printf("\n******学生成绩系统菜单*******\n\n");
		printf("学生成绩排序：\n\n");
		printf("1：成绩排序(按科目)升序：\n");  
		printf("2：成绩排序(按科目)降序：\n");  
		printf("********************\n");
		printf("3：成绩排序(按平均成绩)升序：\n"); 
		printf("4：成绩排序(按平均成绩)降序：\n"); 
		printf("\n0：返回上一级\n");
		printf("\n*****************************\n\n");
		printf("请输入需要执行的步骤："); 

		char n[L];
		//清除缓冲区 
		fflush(stdin);
		//输入 
		gets(n);
		
		//判断是否正确输入数字 
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
				//科目升序排序 
				p = Subject_Up_Menu (p, KMidfilename, Outfilename, back);
				//back = 1 -> 返回上一级->again = 1进行本循环 
				if (*back == 1)
				{
					//重复本do while 
					again = 1;
				}
				else if(*back == 0)
				{
					//back == 0 && choose == 0退出系统 
					*choose = 0;
					again = 0; 
				}
				//back 不为0和1 (== 2)
				else 
				{
					//choose != 0 返回主菜单
					*choose = 1;
					again = 0;
				}
				
				break; 
			}
			
			case 2:
			{
				//科目降序排序 
				p = Subject_Down_Menu (p, KMidfilename, Outfilename, back);
				//back = 1 -> 返回上一级->again = 1进行本循环 
				if (*back == 1)
				{
					//重复本do while 
					again = 1;
				}
				else if(*back == 0)
				{
					//back == 0 && choose == 0退出系统 
					*choose = 0;
					again = 0; 
				}
				//back 不为0和1 
				else 
				{
					//choose != 0 返回主菜单
					*choose = 1;
					again = 0;
				}
				break; 
			}
			
			case 3:
			{
				//平均成绩升序排序 （== 3） 
				p = sortStuscoreUp(p);
				outputcase2_Average(Outfilename, p, 3, Snum, Sub);
				
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
				
				break; 
			}
			
			case 4:
			{
				//平均成绩降序排序 （== 4） 
				p = sortStuscoreDown(p);
				outputcase2_Average(Outfilename, p, 4, Snum, Sub);
				
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
				break; 
			}
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n您的输入有误！请重新输入！\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
	}while (again == 1);
	
	return  p;
}

//寻找指定学院子菜单（donum == 1） 或 挂科按学院查询（donum == 2） 
void Menu_Scidfind (STU *p, int *choose, char *Scidfilename, char *Subjectfilename, int donum)
{
	int num = 0, i;
	SCID *q = Scidfile (Scidfilename, &num);
	
	int again, ch = 0;
	do
	{
		again = 0;
		
		printf("\n******学生成绩系统菜单*******\n\n");
		printf("寻找相关学院的学生信息：\n\n"); 
		//依次读入文件中的学院代码和学院名字 
		for(i = 0; i < num; i++)
			printf("%s：%s\n", (q + i)->nm, (q + i)->s);
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
			printf("\n*****************************\n");
		 	printf("\n您的输入有误！请重新输入！\n");
		 	printf("\n*****************************\n");
			system("pause"); 
			again = 1;	
		}
		//donum == 1：学院学生查找操作 
		else if (donum == 1)
		{
			*choose = ch;
			//ch -  1 :对应文件中的位置 q + 1 -1 为文件中的第一个 
			searchScid (p, (q + ch - 1)->s, Subjectfilename);
		}
		//donum == 2：学院挂科学生信息查找操作
		else if (donum == 2) 
		{
			*choose = ch;
			if(*choose != 0)
			{
				ScidLowpoint (p, (q + ch - 1)->s);  
				printf("\n*****************************");
				printf("\n返回上一步请输入1，返回主菜单请输入2或其它，退出请输入0：");
				scanf("%d",&again);
				//choose == -1退出系统 
				*choose = again - 1; 
			}
			else again = 0;
		}
		
	}while(again == 1);
	
	return;	
}

//add学生子菜单 
STU *Menu_Add (STU *p, int *choose, int *num, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back)
{
	int again,ch;
	do
	{
		again = 0;
		
		printf("\n******学生成绩系统菜单*******\n\n");
		printf("增加学生信息：\n\n");  
		printf("1：在表的开头增加学生信息\n");
		printf("2：在表的结尾增加学生信息\n");
		printf("0：返回上一级\n");
		printf("\n*****************************\n\n");
		printf("请输入需要执行的步骤：");
		
		char n[L];
		//清除缓冲区 
		fflush(stdin);
		//输入 
		gets(n);
		
		//判断是否正确输入数字 
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
				//在表头增加 
				p = addIdUp(p, num, Sidfilename, Scidfilename, Subjectfilename);
				printf("\n*****************************");
				printf("\n继续增加请输入1输出增加后的信息请按2,按其它则返回主菜单:");
				scanf("%d",&again);
					//back == 2 输出增加后信息 
					if (again == 2)
						*back = 2;
				break; 
			}
			
			case 2:
			{
				//在表尾增加 
				p = addIdDown(p, num, Sidfilename, Scidfilename, Subjectfilename);
				printf("\n*****************************");
				printf("\n继续增加请输入1,输出增加后的信息请按2,按其它则返回主菜单:");
				scanf("%d",&again);
					//back == 2 输出增加后信息 
					if (again == 2)
						*back = 2;
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n您的输入有误！请重新输入！\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
		
	}while (again == 1);
	
	return  p;
}

//修改学生信息子菜单 
void Menu_Modify (STU *p, int *choose, int *flag, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back) 
{
	int again, ch;
	do
	{
		again = 0;
		printf("\n******学生成绩系统菜单*******\n\n"); 
		printf("修改学生信息：\n\n"); 
		printf("1：按学号修改信息\n");
		printf("2：按姓名修改信息\n");
		printf("0：返回上一级\n");
		printf("\n*****************************\n\n");
		printf("请输入需要执行的步骤：");
		
		char n[L];
		//清除缓冲区 
		fflush(stdin);
		//输入 
		gets(n);
		
		//判断是否正确输入数字 
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
				//指定id修改 
				ModifyID(p, flag, Sidfilename, Scidfilename, Subjectfilename, back);
				break; 
			}
			
			case 2:
			{ 
				//指定姓名修改 
				ModifyName(p, flag, Sidfilename, Scidfilename, Subjectfilename, back);
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n您的输入有误！请重新输入！\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}
			
	}while (again == 1);

	return;
} 

//寻找学生信息子菜单 
void Menu_SearchStu (STU *p, char *Subjectfilename, int *choose) 
{
	int again, ch;
	do
	{
		again = 0; 
		
		printf("\n******学生成绩系统菜单*******\n\n");
		printf("寻找学生信息：\n\n"); 
		printf("1：按学号查找学生信息\n");
		printf("2：按姓名查找学生信息\n");
		printf("0：返回上一级\n");
		printf("\n*****************************\n\n");
		printf("请输入需要执行的步骤：");
		
		char n[L];
		//清除缓冲区 
		fflush(stdin);
		//输入 
		gets(n);
		
		//判断是否正确输入数字 
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
				//查询给定学号的学生信息
				SearchID (Subjectfilename, p);
				printf("\n*****************************");
				printf("\n返回上一步请输入1，返回主菜单请输入2或其它，退出请输入0：");
				scanf("%d",&again);	
				if (again == 0)
					*choose = -1;
				break; 
			}
			
			case 2:
			{
				//查询给定名字的学生信息
				SearchName (Subjectfilename, p);
				printf("\n*****************************");
				printf("\n返回上一步请输入1，返回主菜单请输入2或其它，退出请输入0：");
				scanf("%d",&again);	
				if (again == 0)
					*choose = -1;
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n您的输入有误！请重新输入！\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
	}while (again == 1);
	
	return;
}

//删除学生信息子菜单 
STU *Menu_Del (STU *p, int *choose, int *num, int *flg, int Snum, int *back) 
{
	int again, ch;
	do
	{
		again = 0;
		
		printf("\n******学生成绩系统菜单*******\n\n");
		printf("删除学生信息：\n\n");  
		printf("1：按学号查找并删除信息\n");
		printf("2：按姓名查找并删除信息\n");
		printf("0：返回上一级\n");
		printf("\n*****************************\n\n");
		printf("请输入需要执行的步骤："); 
		
		char n[L];
		//清除缓冲区 
		fflush(stdin);
		//输入 
		gets(n);
		
		//判断是否正确输入数字 
		if(strlen(n) > 1 || strcmp(n, "0") < 0 || strcmp(n, "9") > 0)
			ch = -1;
		else
			ch = n[0] - '0'; 
			 
		printf("\n*****************************\n");
		
		//若test = num否没进行过删除操作 
		int test = *num;
		*choose = ch;
		switch (ch)
		{
			case 0: break;
			
			case 1:
			{
				//删除指定id 
				p = delID(p, num, flg, Snum);
				if (*flg == 0)
				{
					printf("\n********************\n");
					printf("返回上一步请按1,按其它则返回主菜单:");
					scanf("%d",&again);
					//back == 0 ,返回主菜单 
					if (again == 1)
						(*flg)++; 
					else if (test == *num) 
						*back = 0; 
				}
				else
				{
					printf("\n********************\n");
					printf("删除操作成功！"); 
					printf("\n********************\n");
					printf("\n继续删除请按1,输出删除后的信息请按2,按其它则返回主菜单:");
					scanf("%d",&again);
					//back == 2 输出删除后信息 
					if (again == 2)
						*back = 2;
				}
				
				break; 
			}
			
			case 2:
			{
				//删除指定姓名 
				p = delName(p, num, flg, Snum);
				
				if (*flg == 0)
				{
					
					printf("\n*****************************\n");
					printf("返回上一步请按1,按其它则返回主菜单:");
					scanf("%d",&again);
					//back == 0 ,返回主菜单 
					if (again == 1)
						(*flg)++; 
					else if (test == *num) 
						*back = 0; 
				}
				else
				{
					printf("\n********************\n");
					printf("删除操作成功！"); 
					printf("\n********************\n");
					printf("\n继续删除请按1,输出删除后的信息请按2,按其它则返回主菜单:");
					scanf("%d",&again);
					//back == 2 输出删除后信息 
					if (again == 2)
						*back = 2; 
				}
				
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n您的输入有误！请重新输入！\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
	}while (again == 1);
	
	return  p;
} 

//查找挂科学生子菜单 
void Menu_LowPoint (STU *p, int *choose, char *Scidfilename, char *Subjectfilename, int donum)
{
	int again, ch;
	do
	{
		again = 0;
		
		printf("\n******学生成绩系统菜单*******\n\n");
		printf("挂科学生信息：\n\n");  
		printf("1：输出全部挂科学生信息\n");
		printf("2：按学院查找挂科学生信息\n");
		printf("0：返回上一级\n");
		printf("\n*****************************\n\n");
		printf("请输入需要执行的步骤："); 
		
		char n[L];
		//清除缓冲区 
		fflush(stdin);
		//输入 
		gets(n);
		
		//判断是否正确输入数字 
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
				//输出每个挂科人的信息
				Lowpoint(p, &back);
				//再次进行这里的dowhile 
				if (back == 1) 
				{
					again = 1;
				}
				//back == 0退出系统 
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
				//指定学院的学生信息 
				Menu_Scidfind (p, choose, Scidfilename, Subjectfilename, donum);
				break; 
			}
			
			default : 
			{
				printf("\n*****************************\n");
			 	printf("\n您的输入有误！请重新输入！\n");
			 	printf("\n*****************************\n");
				system("pause"); 
				again = 1;
				break;
			}
		}	
	}while (again == 1);
}

