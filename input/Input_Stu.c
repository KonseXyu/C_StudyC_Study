#include "head_input.h" 

//信息读入（创建动态链表） 
STU *inputSTU(char *filename, int *num)
{
	FILE *fp = fopen (filename, "r");
	if(fp == NULL)
	{
		printf("fopen(r2) Error\n");
		return NULL;
	}
	
	//检查注释行 
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
	//返回num值
	*num = n; 
	
	//开辟空间p 
	STU *p = (STU *)malloc( sizeof(STU));
	//每一个确保空间后，需要确认 
	if(p == NULL)
	{
		printf("malloc p, Error\n");
		return NULL;
	}
	
	//若链表为空 
	if (n == 0)
	{
		p->id = 0;
		strcpy(p->name, "空");
		strcpy(p->sid, "空");
		strcpy(p->scid, "空\t");
		int i;
		//需要科目数量！！！ 
		for(i = 0;i < 4; i++)
			p->s[i] = 0 ; 
		p->ave = 0; 
		return p;
	}
	
	fscanf(fp, "%lld%s%s%s", &p->id, p->name, p->sid, p->scid);
	int i;
	//需要科目数量！！！ 
	for(i = 0;i < 4; i++)
		fscanf(fp, "%d", &p->s[i]);
	if(p->id == 0)
		{
			printf ("Fscanf Nothing!");
			exit (1);
		}
		
	STU *q = (STU *)malloc( sizeof(STU));
	//每一个确保空间后，需要确认 
	if(q == NULL)
	{
		printf("malloc q, Error\n");
		return NULL;
	}
	//头指针 
	STU *head = p;
		
	while(p->id != 0)
	{
		//使前一个q的next指向下一个p节点 
		q->next = p;
		//q更新 
		q = p;
		//p开辟新空间 
		p = (STU *)malloc( sizeof(STU));
		fscanf(fp, "%lld%s%s%s", &p->id, p->name, p->sid, p->scid);
		int i;
		//需要科目数量！！！
		for(i = 0;i < 4; i++)
			fscanf(fp, "%d", &p->s[i]);
	}
	
	q->next = NULL; 
	fclose(fp); 
	return head; 
}
