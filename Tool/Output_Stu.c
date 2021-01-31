#include "head_tool.h" 



//输出到屏幕 
void outputScreen (STU *p, int Snum)
{
	fprintf(stdout, "%lld\t%s\t%s\t%s   \t", p->id, p->name, p->sid, p->scid);
	int i; 
	for(i = 0; i < Snum; i++)
	   	fprintf(stdout, "%d\t", p->s[i]);
	fprintf(stdout, "%-.2f\n", p->ave);
	return ;
}

//输出到文件
void outputFile (FILE *fp, STU *p, int Snum)
{
	fprintf(fp, "%lld\t%s\t%s\t%-s        \t", p->id, p->name, p->sid, p->scid);
	int i; 
	for(i = 0; i < Snum; i++)
	   	fprintf(fp, "%d\t", p->s[i]);
	fprintf(fp, "%-.2f\n", p->ave);
	return ;
 } 
 
 //单独输出到屏幕的模板 
void outputcaseS (STU *p, int Snum, KMID *Sub)
{
	fprintf(stdout, "学号\t姓名\t性别\t学院\t\t");
	int i;
	for(i = 0; i < Snum; i++)
		printf("%s\t", (Sub + i)->s);
	printf("平均成绩\n");
	int n = 0;
	while(p != NULL)
	  {
	  	//输出部分后暂停 
	  	n++;
	  	if (n % 19 == 0) 
		  {
		  	printf("\n查看下一页，");
		  	system("pause");
		  	fprintf(stdout, "学号\t姓名\t性别\t学院\t\t");
			int i;
			for(i = 0; i < Snum; i++)
				printf("%s\t", (Sub + i)->s);
			printf("平均成绩\n");
		  }
		  
 	 	//输出到屏幕做反馈 
 	 	outputScreen(p, Snum);
		p = p->next;
	  }
	
	return;
}

 //单独输出到文件的模板 
void outputcaseF (STU *p, FILE *fp, int Snum, KMID *Sub)
{
	fprintf(fp, "\n#学号\t姓名\t性别\t学院\t\t");
	int i;
	for(i = 0; i < Snum; i++)
		fprintf(fp, "%s\t", (Sub + i)->s);
	fprintf(fp,"平均成绩\n");
	while(p != NULL)
	  { 
 	 	//输出到文件 
 	 	outputFile(fp, p, Snum);
		p = p->next;
	  }
	
	return;
}

 
//单独输出到屏幕及文件的模板 
void outputcaseSF (STU *p, FILE *fp, int Snum, KMID *Sub)
{
	fprintf(stdout, "学号\t姓名\t性别\t学院\t\t");
	fprintf(fp, "\n#学号\t姓名\t性别\t学院\t\t");
	int i;
	for(i = 0; i < Snum; i++)
	{
		printf("%s\t", (Sub + i)->s);
		fprintf(fp, "%s\t", (Sub + i)->s);	
	}
	printf("平均成绩\n");
	fprintf(fp,"平均成绩\n");
	
	int n = 0;
	while(p != NULL)
	  {
	  	//输出部分后暂停 
	  	n++;
	  	if (n % 19 == 0) 
		  {
		  	printf("\n查看下一页，");
		  	system("pause");
		  	fprintf(stdout, "学号\t姓名\t性别\t学院\t\t");
			int i;
			for(i = 0; i < Snum; i++)
				printf("%s\t", (Sub + i)->s);
			printf("平均成绩\n");
		  }
	  	//输出到文件 
	  	outputFile (fp, p, Snum);
	  	
 	 	//输出到屏幕做反馈 
 	 	outputScreen(p, Snum);
		p = p->next;
	  }
	
	fclose(fp); 
	return;
}

/*
//读取文件并显示学生信息
void outputcase1 (char *filename, STU *p)
{
	fprintf(stdout, "\n读取到的学生信息:\n\n");
	
	outputcaseS (filename, p);
	
	return;
}
*/

//按照姓名排序并显示信息 
void outputcase1 (char *filename, STU *p, int choose, int Snum, KMID *Sub)
 {
	//输出到屏幕做反馈 
	
	if (choose == 1)
		fprintf(stdout, "按名字降序排序后的学生信息:\n\n");
	else if (choose == 2)
		fprintf(stdout, "按名字升序排序后的学生信息:\n\n");
	
	outputcaseS (p, Snum, Sub);

	return ;
 }
 
//按照科目成绩排序并显示信息
void outputcase2_Subject (char *filename, STU *p, int num, char *subjuctname, int Snum, KMID *Sub)
 {
	//输出到屏幕做反馈	 
	if (num == 1)
		fprintf(stdout, "按%s成绩升序排序后的学生信息:\n\n", subjuctname);
	else if (num == 2)
		fprintf(stdout, "按%s成绩降序排序后的学生信息:\n\n", subjuctname);
	
	outputcaseS (p, Snum, Sub);
	
	return ;
 }
 
 //按照平均成绩排序并显示信息
void outputcase2_Average (char *filename, STU *p, int num, int Snum, KMID *Sub)
 {
	//输出到屏幕做反馈	 
	if (num == 3)
		fprintf(stdout, "按平均成绩升序排序后的学生信息:\n\n");
	else if (num == 4)
		fprintf(stdout, "按平均成绩降序排序后的学生信息:\n\n");
	
	outputcaseS (p, Snum, Sub);
	
	return ;
 }
  
//add学生后进行单独文件输出 
void outputcase4_File(char *filename, STU *p, int num, int Snum, KMID *Sub)
{
	//以write的方式打开 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase4 fopen(w) Error");
		return;
	}

	fprintf(fp,"#添加操作成功！");

	fprintf(fp,"\n#目前表内的学生人数：%d\n", num);

	//输出到文件 
	fprintf(fp, "#目前存在学生的学生信息：");
	
	outputcaseF (p, fp, Snum, Sub);

	fclose(fp);
	return ;
 }
 
 //add学生后进行输出 
 void outputcase4(char *filename, STU *p, int num, int Snum, KMID *Sub)
{
	//以write的方式打开 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase4 fopen(w) Error");
		return;
	}
	
	printf("\n添加操作成功!\n");
	fprintf(fp,"#添加操作成功！");
	
	printf("\n目前表内的学生人数：%d\n\n", num);
	fprintf(fp,"\n#目前表内的学生人数：%d\n", num);
	
	//输出到屏幕 
	fprintf(stdout, "目前存在学生的学生信息：\n");
	
	//输出到文件 
	fprintf(fp, "#目前存在学生的学生信息：");
	
	outputcaseSF (p, fp, Snum, Sub);

	fclose(fp);
	return ;
 }

//修改学生信息后进行单独文件输出 
void outputcase5_File(char *filename, STU *p, int Snum, KMID *Sub)
{
	//以write的方式打开 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase5_File fopen(w) Error");
		return;
	}
	
	fprintf(fp,"#修改成功!\n");
	//输出到文件 
	fprintf(fp, "#修改后的学生信息：");
	
	outputcaseF (p, fp, Snum, Sub);
	
	fclose(fp);
	return ;
}

//修改学生信息后进行输出 
void outputcase5(char *filename, STU *p, int Snum, KMID *Sub)
{
	//以write的方式打开 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase5 fopen(w) Error");
		return;
	}
	
	printf("\n修改成功!\n\n");
	fprintf(fp,"#修改成功!\n");
	
	//输出到屏幕 
	fprintf(stdout, "修改后的学生信息：\n\n");
	
	//输出到文件 
	fprintf(fp, "#修改后的学生信息：");
	
	outputcaseSF (p, fp, Snum, Sub);
	
	fclose(fp);
	return ;
}

//删除操作完成后进行单独的文件输出 
void outputcase7_File(char *filename, STU *p, int num, int Snum, KMID *Sub)
{
	//以write的方式打开 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase7_File fopen(w) Error");
		return;
	}
	
	fprintf(fp,"#删除操作成功！");
	
	fprintf(fp,"\n#目前表内的学生人数：%d\n", num);
	
	//输出到文件 
	fprintf(fp, "#余下学生的学生信息：");
	
	outputcaseF (p, fp, Snum, Sub);
	
	fclose(fp);
	return;
 } 

//删除操作完成后进行输出 
void outputcase7(char *filename, STU *p, int num, int Snum, KMID *Sub)
{
	//以write的方式打开 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase7 fopen(w) Error");
		return;
	}
	
	fprintf(fp,"#删除操作成功！");
	
	printf("\n目前表内的学生人数：%d\n\n", num);
	fprintf(fp,"\n#目前表内的学生人数：%d\n", num);
	
	//输出到屏幕 
	fprintf(stdout, "余下学生的学生信息：\n");
	
	//输出到文件 
	fprintf(fp, "#余下学生的学生信息：");
	
	outputcaseSF (p, fp, Snum, Sub);
	
	fclose(fp);
	return;
 } 


