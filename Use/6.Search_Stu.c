#include "head_Use.h" 

//查询给定学号的学生信息
void SearchID (char *Subjectfilename, STU *p)
{
	int num;
 	//获取科目信息 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
	int flag = 1;
	long long int findid;
	printf("\n请输入要查找的学号："); 
	scanf("%lld", &findid);
	
	while (p != NULL)
	{
		
		if(p->id == findid)
		{
			if (flag == 1)
  		{
  			flag = 0;
			printf("*****************************"); 
  			fprintf(stdout, "\n学号为%lld的学生信息已找到\n\n", findid);
			fprintf(stdout, "学号\t姓名\t性别\t学院\t\t");
			int i;
			for(i = 0; i < num; i++)
				printf("%s\t", (q + i)->s);
			printf("平均成绩\n");
  		}
			//输出到屏幕 
			outputScreen(p, num, q); 
		}
		p = p->next;
	}
	
	if(flag == 1)
		fprintf(stdout,"\n学号为%lld的学生信息未能找到！\n", findid);	
	
	return;
}

//查询给定姓名的学生信息
void SearchName (char *Subjectfilename, STU *p)
{
	int num;
 	//获取科目信息 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
 	char findname[L];
	printf("\n请输入要查找的名字："); 
	scanf("%s", findname);
	
	int flag = 1;
	
	while (p != NULL)
	{
		if(strcmp(p->name, findname) == 0)
		{
			if (flag == 1)
		{
			flag = 0; 
			printf("*****************************\n");
			fprintf(stdout, "姓名为%s的学生信息已找到\n\n", findname);
			fprintf(stdout, "学号\t姓名\t性别\t学院\t\t");
			int i;
			for(i = 0; i < num; i++)
				printf("%s\t", (q + i)->s);
			printf("平均成绩\n");
		}
		    //输出到屏幕 
			outputScreen(p, num, q);
		}
		p = p->next;
	}
	if(flag == 1)
		fprintf(stdout,"\n姓名为%s的学生信息未能找到！\n", findname);
	 
	return; 
}
