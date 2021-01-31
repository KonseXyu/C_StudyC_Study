#include "head_input.h" 

//读入科目信息文件（包括个数） 
KMID *Subjectfile(char *filename, int *num)
{
	//以只读的方式打开 
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r)[Sujectname] Error\n");
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
	
	//subject:科目代码KMID格式: num name 
	KMID *subject = (KMID *) malloc(sizeof(KMID) * n);
	
	KMID *head = subject;
	if(subject == NULL)
	{
		printf("SubjectFile *subject malloc Error");
		return ;
	 } 
	 
	 while(n--)
	{
		fscanf(fp, "%s%s", subject->nm, subject->s);
		subject++;
	}
	
	fclose(fp);
	//subject = head;
	return head; 
}
