#include "head_input.h" 

//读入学院代码文件的信息
SCID *Scidfile (char *filename, int *num) 
{
	//以只读的方式打开 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[scidname] Error\n");
		return ;
	}
	
	char ps[L];
	int n = 0; 
	while( fgets(ps, 100, fp) != NULL)
	{	
		//跳过'#'的注释行  
		if (ps[0] == '#') continue; 
		else 
		{
			//获取注释行后数据数的长度 
			int x = strlen(ps);
			int i;
			for(i = 0; i < x-1 ;i++)
			{
				//求得读取数据数n个 
				n *= 10;
				n += ps[i] - '0';
			}
			break;	
		}
	}
	
	//传回读入的个数 
	*num = n;
	
	//xy:学院代码scid格式: num name 
	SCID *xy = (SCID *) malloc(sizeof(SCID) * n);
	SCID *head = xy;
	if(xy == NULL)
	{
		printf("Scidfile *xy malloc Error");
		return ;
	 } 
	 
	 while(n--)
	{
		fscanf(fp, "%s%s", xy->nm, xy->s);
		xy++;
	}
	
	fclose(fp);
	//xy = head;
	return head; 
}

//将单个人的学院id代码转换成对应的学院信息 
void scidnameOne(char *filename, STU *p)
 {
	//以只读的方式打开 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[scidname] Error\n");
		return ;
	}
	
	char ps[L];
	int n = 0; 
	while( fgets(ps, 100, fp) != NULL)
	{	
		//跳过'#'的注释行  
		if (ps[0] == '#') continue; 
		else 
		{
			//获取注释行后数据数的长度 
			int x = strlen(ps);
			int i;
			for(i = 0; i < x-1 ;i++)
			{
				//求得读取数据数n个 
				n *= 10;
				n += ps[i] - '0';
			}
			break;	
		}
	}

	//xy:学院代码scid格式: num name 
	SCID *xy = (SCID *) malloc(sizeof(SCID) * n);
	if(xy == NULL)
	{
		printf("scidnameOne *xy malloc Error");
		return ;
	 } 
	 
	 //保存xy的头指针 
	SCID *head = xy;
	int t = n;
	//读入学院代码文件的信息 
	while(t--)
	{
		fscanf(fp, "%s%s",xy->nm, xy->s);
		xy++;
	}
	fclose(fp);
	int j;
	xy = head;
	
	//进行学生信息文件中scid的代号转换 
	for(j = 0; j < n; j++)
	{
		if(strcmp(p->scid, (xy + j)->nm) == 0)
		{	
			strcpy(p->scid , (xy + j)->s);
		}
	}

	return;	
 } 
 
 //将所有学生的学院id代码转换成对应的学院信息 
 void scidname(char *filename, STU *p, int num)
 {
	//以只读的方式打开 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[scidname] Error\n");
		return ;
	}
	
	char ps[L];
	int n = 0; 
	while( fgets(ps, 100, fp) != NULL)
	{	
		//跳过'#'的注释行  
		if (ps[0] == '#') continue; 
		else 
		{
			//获取注释行后数据数的长度 
			int x = strlen(ps);
			int i;
			for(i = 0; i < x-1 ;i++)
			{
				//求得读取数据数n个 
				n *= 10;
				n += ps[i] - '0';
			}
			break;	
		}
	}
	printf("读入的学院信息个数：%d。\n",n);
	
	//xy:学院代码scid格式: num name 
	SCID *xy = (SCID *) malloc(sizeof(SCID) * n);
	if(xy == NULL)
	{
		printf("scidname *xy malloc Error");
		return ;
	 } 
	 
	 //保存xy的头指针 
	SCID *head = xy;
	int t = n;
	//读入学院代码文件的信息 
	while(t--)
	{
		fscanf(fp, "%s%s",xy->nm, xy->s);
		xy++;
	}
	fclose(fp);
	int j;
	xy = head;
	
	//进行学生信息文件中scid的代号转换 
	while(num--)
	{	
		for(j = 0; j < n; j++)
		{
			if(strcmp(p->scid, (xy + j)->nm) == 0)
			{	
				strcpy(p->scid , (xy + j)->s);
			}
		}
		p = p->next;
	}
	printf("学院代码转换已完成！\n\n");
	
	return;	
 } 
