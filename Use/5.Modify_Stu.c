 #include "head_Use.h" 
 
//按学号修改学生信息 
void ModifyID(STU *p, int *flag, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back)
{
	int num;
 	//获取科目信息 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
	long long int findid;
	printf("\n请输入你要更改的学生信息的id：");
	scanf("%lld", &findid);
	
	while (p != NULL)
	{
		//寻找匹配的id 
		if(p->id == findid)
		{
			if (*flag == 1)
  			{
	  			*flag = 0; 
	  			printf("\n*****************************");
	  			fprintf(stdout, "\n学号为%lld的学生信息已找到\n", findid);
	  			printf("*****************************\n");
	  			//ag ：检查要更改的change序号是否有误 
				int change, ag;
				do
				{
					ag = 0;
					printf("\n更改学号请输入1，更改姓名请输入2，更改性别请输入3,\n\n更改学院信息请输入4，更改成绩请输入5：");
					scanf("%d", &change);
					if(change == 1)
					{
						int again;
						do
						{
							printf("\n*****************************");
							printf("\n请输入更改的id信息：");
							
							long long int cid;
							scanf("%lld", &cid);
							p->id = cid;
							
							printf("\n*****************************\n");	
							printf("\n更改成功！\n\n*****************************\n");
							printf("重新更改请按0，继续更改该学生信息请按1,输出更改后的信息请按2,按其它则返回主菜单:"); 
							scanf("%d",&again);
							
							if (again == 1)
								ag = 1; 
							//输入2 back == 2；进行输出更改后的信息 
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
							printf("\n请输入更改后姓名信息：");
							
							char cname[L];
							scanf("%s", cname);
							strcpy(p->name, cname);
							
							printf("\n*****************************\n");	
							printf("\n更改成功！\n\n*****************************\n");
							printf("重新更改请按0，继续更改该学生信息请按1,输出更改后的信息请按2,按其它则返回主菜单:"); 
							scanf("%d",&again);
								
							if (again == 1)
								ag = 1; 
							//输入2 back == 2；进行输出更改后的信息 
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
							printf("\n请输入更改的性别信息：");
							scanf("%s", p->sid);
							
							//若输入的是性别代码则进行转换
							sidnameOne(Sidfilename, p);
							
							printf("\n*****************************\n");	
							printf("\n更改成功！\n\n*****************************\n");
							printf("重新更改请按0，继续更改该学生信息请按1,输出更改后的信息请按2,按其它则返回主菜单:"); 
							scanf("%d",&again);
							
							if (again == 1)
								ag = 1; 
							//输入2 back == 2；进行输出更改后的信息 
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
							printf("\n请输入更改的学院信息：");
							scanf("%s", p->scid);
							
							//若输入的是学院代码则进行转换 
							scidnameOne(Scidfilename, p);
							
							printf("\n*****************************\n");	
							printf("\n更改成功！\n\n*****************************\n");
							printf("重新更改请按0，继续更改该学生信息请按1,输出更改后的信息请按2,按其它则返回主菜单:"); 
							scanf("%d",&again);
								
							if (again == 1)
								ag = 1; 
							//输入2 back == 2；进行输出更改后的信息 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					 else if(change == 5)
					{
						int again;
						do
						{
						Cnum:printf("\n**********科目信息************\n\n");
							int i;
							for( i = 0; i < num; i++)
								printf("%s：%s\n", (q + i)->nm, (q + i)->s);
							printf("\n*****************************\n");
							printf("\n请输入要更改的成绩科目序号(1-%d)：", num);
							int cnum;
							scanf("%d", &cnum);
							if (cnum >= 1 && cnum <= num)
							{
								printf("\n请输入更改后的%s成绩：", (q + cnum - 1)->s);
								scanf("%d", &p->s[cnum - 1]);
								averageOne(p, Subjectfilename);
							 } 
							 else
							 {
							 	 printf("\n您的输入有误！请重新输入！\n");
								 goto Cnum;
							 }
							 
							printf("\n*****************************\n");	
							printf("\n更改成功！\n\n*****************************\n");
							printf("重新更改请按0，继续更改该学生信息请按1,输出更改后的信息请按2,按其它则返回主菜单:"); 
							scanf("%d",&again);
							
							if (again == 1)
								ag = 1; 
							//输入2 back == 2；进行输出更改后的信息 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					 else 
					 {
					 	printf("\n*****************************");
					 	printf("\n您的输入有误！请重新输入！\n");
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
		fprintf(stdout,"\n学号为%lld的学生信息未能找到！\n", findid);
		printf("*****************************\n");
		system("pause");
	 }	
}
	
//按名字修改学生信息 
void ModifyName(STU *p, int *flag, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back)
{
	int num;
 	//获取科目信息 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
	char findname[L];
	printf("\n请输入要查找的名字："); 
	scanf("%s", findname);

	while (p != NULL)
	{
		if(strcmp(p->name, findname) == 0)
		{ 
			if (*flag == 1)
  			{
	  			*flag = 0; 
	  			printf("\n*****************************");
	  			fprintf(stdout, "\n姓名为%s的学生信息已找到\n", findname);
	  			printf("*****************************\n");
				int change, ag;
				do
				{
					ag = 0;
					printf("\n更改学号请输入1，更改姓名请输入2，更改性别请输入3,\n\n更改学院信息请输入4，更改成绩请输入5：");
					scanf("%d", &change);
					if(change == 1)
					{
						int again;
						do
						{
							printf("\n*****************************");
							printf("\n请输入更改的id信息：");
							long long int cid;
							scanf("%lld", &cid);
							p->id = cid;
							
							printf("\n*****************************\n");	
							printf("\n更改成功！\n\n*****************************\n");
							printf("重新更改请按0，继续更改该学生信息请按1,输出更改后的信息请按2,按其它则返回主菜单:"); 
							scanf("%d",&again);
							
							if (again == 1)
								ag = 1; 
							//输入2 back == 2；进行输出更改后的信息 
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
							printf("\n请输入更改后姓名信息：");
							char cname[L];
							scanf("%s", cname);
							strcpy(p->name, cname);
							
							printf("\n*****************************\n");	
							printf("\n更改成功！\n\n*****************************\n");
							printf("重新更改请按0，继续更改该学生信息请按1,输出更改后的信息请按2,按其它则返回主菜单:"); 
							scanf("%d",&again);	
							
							if (again == 1)
								ag = 1; 
							//输入2 back == 2；进行输出更改后的信息 
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
							printf("\n请输入更改的性别信息：");
							scanf("%s", p->sid);
							
							//若输入的是性别代码则进行转换
							sidnameOne(Sidfilename, p);
							
							printf("\n*****************************\n");	
							printf("\n更改成功！\n\n*****************************\n");
							printf("重新更改请按0，继续更改该学生信息请按1,输出更改后的信息请按2,按其它则返回主菜单:"); 
							scanf("%d",&again);
							
							if (again == 1)
								ag = 1; 
							//输入2 back == 2；进行输出更改后的信息 
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
							printf("\n请输入更改的学院信息：");
							scanf("%s", p->scid);
							
							//若输入的是学院代码则进行转换 
							scidnameOne(Scidfilename, p);
							
							printf("\n*****************************\n");	
							printf("\n更改成功！\n\n*****************************\n");
							printf("重新更改请按0，继续更改该学生信息请按1,输出更改后的信息请按2,按其它则返回主菜单:"); 
							scanf("%d",&again);
								
							if (again == 1)
								ag = 1; 
							//输入2 back == 2；进行输出更改后的信息 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					 else if(change == 5)
					{
						int again;
						do
						{
						Cnum2:printf("\n**********科目信息************\n\n");
							int i;
							for( i = 0; i < num; i++)
								printf("%s：%s\n", (q + i)->nm, (q + i)->s);
							printf("\n*****************************\n");
							printf("\n请输入要更改的成绩科目序号(1-%d)：", num);
							int cnum;
							scanf("%d", &cnum);
							if (cnum >= 1 && cnum <= 4)
							{
								printf("\n请输入更改后的%s成绩：", (q + cnum - 1)->s);
								scanf("%d", &p->s[cnum - 1]);
								averageOne(p, Subjectfilename);
							 } 
							 else
							 {
							 	 printf("\n您的输入有误！请重新输入！\n");
								 goto Cnum2;
							 }
							 
							printf("\n*****************************\n");	
							printf("\n更改成功！\n\n*****************************\n");
							printf("重新更改请按0，继续更改该学生信息请按1,输出更改后的信息请按2,按其它则返回主菜单:"); 
							scanf("%d",&again);	
							
							if (again == 1)
								ag = 1; 
							//输入2 back == 2；进行输出更改后的信息 
							else if (again == 2)
								*back = 2;
						}while (again == 0);
					 }
					 else 
					 {
					 	printf("\n*****************************");
					 	printf("\n您的输入有误！请重新输入！\n");
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
		fprintf(stdout,"\n姓名为%s的学生信息未能找到！\n", findname);
		printf("\n*****************************\n");
		system("pause");
	 }	
}	

