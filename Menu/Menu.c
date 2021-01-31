#include "head_menu.h" 

void Menu()
{
	//输入文件名字 
	char *Inputfilename = "Stu_Info.txt"; 
	
	//姓名代码文件名字 
	char *Sidfilename = "S_Info2.txt" ;
	
	 //学院代码文件名字 
	char *Scidfilename = "C_Code.txt";
	
	//科目代码文件名字 
	char *Subjectfilename = "KM_info.txt"; 
	
	//输出文件名字 
	char *Outfilename = "Stu_Info_Output.txt" ;	
	
	//密码信息 
	char *Passwordname = "Password_Stu" ;
	
	//进行登录 
	FILE *fpPass = fopen (Passwordname, "r");
	
	//若不在密匙文件或者密匙文件为空 
	if(fpPass == NULL || fgetc(fpPass) == EOF)
	{
		fclose(fpPass);
		//未存在密码 
		PasswordCreate(Passwordname);
	}
	else
	{
		//密匙文件不为空，移动指针位置到开头读取密匙文件 
		rewind(fpPass);
		//已存在密码 
		PasswordLoading(Passwordname, fpPass);
		fclose(fpPass);
	}
	 
	int num = 0, again = 1;
	
	//信息读入 
 	STU *p = inputSTU(Inputfilename, &num); 
 	if(p == NULL)
	{
	 	printf("inputSTU Error");
		 return; 
	}
	printf("读入的学生个数：%d。\n\n",num);
	
	//求average 
	average(p, Subjectfilename);
	
	//性别代码转换 
	sidname(Sidfilename, p, num);
	 
	//学院代码转换 
	scidname(Scidfilename, p, num);
	

	int Snum;
 	//获取科目信息 
 	KMID *Sub = Subjectfile(Subjectfilename, &Snum);
 	
	printf("文件“Stu_Info3.txt”的信息已全部读入！！\n");
	
	do
	{
		printf("\n******学生成绩系统菜单*******\n\n");
		printf("1：按照姓名排序并显示信息\n"); 
		printf("2：按照平均成绩排序并显示信息\n"); 
		printf("3：显示给定学院的学生信息\n"); 
		printf("4：增加学生信息\n"); //表头增加或表尾增加 
		printf("5：修改学生信息\n"); //给定学号或姓名
		printf("6：查询学生信息\n"); //给定学号或姓名
		printf("7：删除学生信息\n"); //给定学号或姓名
		printf("8：修改系统密码\n"); 
		printf("9：输出挂科学生信息\n"); 
		printf("0：退出系统\n"); //返回上一级菜单
		printf("\n*****************************\n\n");    
		printf("请输入需要执行的步骤："); 

		int flag;
		
		char n[L];
		//清除缓冲区 
		fflush(stdin);
		//输入 
		gets(n);
		
		//判断是否正确输入数字 
		if(strlen(n) > 1 || strcmp(n, "0") < 0 || strcmp(n, "9") > 0)
			flag = -1;
		else
			flag = n[0] - '0'; 
			
		switch (flag)
		{
			case 0: 
			{
				//退出系统 
				again = 0; 
				break ;	
			}
			//姓名排序 
			case 1: 
			{
				//若读入的学生为空 
				if(num == 0)
				{
					printf("\n学生信息为空！无法进行排序操作！\n");
					printf("\n*****************************");
					printf("\n返回菜单请输入任意数，退出请输入0：");
					scanf("%d",&again); 
					break;
				}
				
				int choose = 0;
				p = Menu_Name (p ,&choose);
				//1：按名字降序排序，2：按名字升序排序 
				if(choose == 1 || choose == 2)
				{
					outputcase1(Outfilename, p, choose, Snum, Sub);
					printf("\n*****************************"); 
					printf("\n返回菜单请输入任意数，退出请输入0：");
					scanf("%d",&again);
				}
				//0：返回上一级菜单
				else again = 1;
				
				break;  
			}
			//成绩排序		
			case 2: 
			{
				//若读入的学生为空
				if(num == 0)
				{
					printf("\n学生信息为空！无法进行排序操作！\n");
					printf("\n*****************************");
					printf("\n返回菜单请输入任意数，退出请输入0：");
					scanf("%d",&again); 
					break;
				}
				
				int choose = 0, back = 1;
				p = Menu_Score (p , &choose, &back, Subjectfilename, Outfilename, Snum, Sub);
				//back == 0 && choose == 0退出系统 
				if(back == 0 && choose == 0)
					again = 0;
				//否则进行本循环 
				else if (choose == 1) 
					again = 1; 
				
				break;	
			}	
						
			case 3:
			{
				if(num == 0)
				{
					printf("\n学生信息为空！无法进行查询操作！\n");
					printf("\n*****************************");
					printf("\n返回菜单请输入任意数，退出请输入0：");
					scanf("%d",&again); 
					break;
				}
				
				int choose = 0, again2, donum = 1;
				do
				{
					//指定学院的学生信息 
					Menu_Scidfind (p, &choose, Scidfilename, Subjectfilename, donum);
				
					if(choose != 0)
					{
						printf("\n*****************************");
						printf("\n返回上一步请输入1，返回主菜单请输入2或其它，退出请输入0：");
						scanf("%d",&again2);
						if(again2 == 0)
							again = 0;
						else if (again2 != 1) 
							again = 1;
					}
					//0：返回上一级菜单
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
				//增加指定的学生 
				int choose, back = 1;
				p = Menu_Add (p, &choose, &num, Sidfilename, Scidfilename, Subjectfilename, &back);
				//0：返回上一级菜单
				if(choose == 0)	
					again = 1;
				else if (back == 2)
				{
					outputcase4 (Outfilename, p, num, Snum, Sub);
					printf("\n*****************************");
					printf("\n返回菜单请输入任意数，退出请输入0：");
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
					printf("\n学生信息为空！无法进行修改操作！\n");
					printf("\n*****************************");
					printf("\n返回菜单请输入任意数，退出请输入0：");
					scanf("%d",&again); 
					break;
				}
				//flag：判断是否找到要寻找的学生信息 
				int flag = 1, choose =0, back = 0;
				
				//修改指定的学生信息
				Menu_Modify (p, &choose, &flag, Sidfilename, Scidfilename, Subjectfilename, &back);
				
				if (choose == 1 || choose == 2) 
				{
					//若找到对应的学生信息进行修改则进行输出 
					if(flag == 0 && back == 2)
					{
						outputcase5(Outfilename, p, Snum, Sub); 
						printf("\n*****************************");
						printf("\n返回菜单请输入任意数，退出请输入0：");
						scanf("%d",&again);
					}
					else if (back != 2)
					{
						//修改学生信息后进行单独文件输出 
						outputcase5_File(Outfilename, p, Snum, Sub); 
						again = 1;
					}
				}
				//0：返回上一级菜单
				else
				   again = 1;
				
					
				break; 	
			} 	
						
			case 6: 
			{
				if(num == 0)
				{
					printf("\n学生信息为空！无法进行查询操作！\n");
					printf("\n*****************************");
					printf("\n返回菜单请输入任意数，退出请输入0：");
					scanf("%d",&again); 
					break;
				}
				int choose = 0;
				
				//寻找指定的学生 
				Menu_SearchStu (p, Subjectfilename, &choose);
				
				//choose == -1 退出系统，否则进行此do while 
				if (choose == -1)
					again = 0;
				 else 
				 	again = 1;
				break; 
			} 

			case 7: 
			{
				//删除指定的学生 
				//若学生为空 
				if(num == 0)
				{
					printf("\n学生信息为空！无法进行删除操作！\n");
					printf("\n*****************************");
					printf("\n返回菜单请输入任意数，退出请输入0：");
					scanf("%d",&again); 
					break;
				}
				
				int flg = 1, choose = 0, back = 1;
				//删除操作 
				p = Menu_Del (p, &choose, &num, &flg, Snum, &back);
				if(choose != 0)
				{
					//back == 0 ,返回主菜单 back == 2 输出删除后信息 
					if (back == 0)
					{
						again = 1;
					}
					else if (back == 2)
					{
						outputcase7 (Outfilename, p, num, Snum, Sub);
						printf("\n*****************************");
						printf("\n返回菜单请输入任意数，退出请输入0：");
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
				//密码修改 
				PasswordChange(Passwordname);
				printf("\n*****************************");
				printf("\n返回菜单请输入任意数，退出请输入0：");
				scanf("%d",&again);
				break;
			} 
			case 9: 
			{
				//挂科学生搜索 
				if(num == 0)
				{
					printf("\n学生信息为空！无法进行操作！\n");
					printf("\n*****************************");
					printf("\n返回菜单请输入任意数，退出请输入0：");
					scanf("%d",&again); 
					break;
				}
				
				int choose = 0, donum = 2;
				
				//挂科学生信息子菜单 
				Menu_LowPoint (p, &choose, Scidfilename, Subjectfilename, donum);
				
				//choose == -1退出系统
				if (choose == -1)
					again = 0;
				else if(choose != 0)
					again = 1;
				
				
				break;
			}		

			default: 
			{
				printf("\n*****************************");
			 	printf("\n您的输入有误！请重新输入！\n");
			 	printf("*****************************\n");
				system("pause");
			}
		 }	
	 } while (again != 0);
	 free(p); 
	 printf("\n****************************\n\n");
	 printf("\n\t系统已退出！\n");
	 printf("\n\n****************************\n");
	 return;
}

