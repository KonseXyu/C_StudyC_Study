#include "head_input.h" 

//将一个人的性别的id代码转换成对应的性别 
 void sidnameOne(char *filename, STU *p)
 {
	//以只读的方式打开 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[sidnameOne] Error\n");
		return ;
	}
	
	char ps[L];
	int n = 0; 
	while( fgets(ps, 100, fp) != NULL)
	{
		//跳过'#'的注释行 
		if (ps[0] == '#') continue; 
		else 
		{	//获取注释行后数据数的长度 
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

	//xb:性别代码sid格式: num name 
	SID *xb = (SID *) malloc(sizeof(SID) * n);
	if(xb == NULL)
	{
		printf("sidnameOne *xb malloc Error");
		return ;
	 } 
	
	//保存xb的头指针 
	SID *head = xb;
	int t = n;
	//读入性别代码文件的信息 
	while(t--)
	{
		fscanf(fp, "%s%s",xb->nm, xb->s);
		xb++;
	}
	fclose(fp);
	
	int i, j;
	xb = head;
	
	//进行sid的代号转换
	for(j = 0; j < n; j++)
		if(strcmp(p->sid, (xb + j)->nm) == 0)
			strcpy(p->sid , (xb + j)->s);
			
	return;	
} 

//将所有学生的性别id代码转换成对应的性别 
void sidname(char *filename, STU *p, int num)
 {
	//以只读的方式打开 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[sidname] Error\n");
		return ;
	}
	
	char ps[L];
	int n = 0; 
	while( fgets(ps, 100, fp) != NULL)
	{
		//跳过'#'的注释行 
		if (ps[0] == '#') continue; 
		else 
		{	//获取注释行后数据数的长度 
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
	printf("读入的性别信息个数：%d。\n",n);
	
	//xb:性别代码sid格式: num name 
	SID *xb = (SID *) malloc(sizeof(SID) * n);
	if(xb == NULL)
	{
		printf("sidname *xb malloc Error");
		return ;
	 } 
	
	//保存xb的头指针 
	SID *head = xb;
	int t = n;
	//读入性别代码文件的信息 
	while(t--)
	{
		fscanf(fp, "%s%s",xb->nm, xb->s);
		xb++;
	}
	fclose(fp);
	int i, j;
	xb = head;
	
	//进行学生信息文件中sid的代号转换 
	while(num--)
	{	
		for(j = 0; j < n; j++)
			if(strcmp(p->sid, (xb + j)->nm) == 0)
				strcpy(p->sid , (xb + j)->s);
		p = p->next;
	}
	
	printf("性别代码转换已完成！\n\n");
	return;	
 } 
