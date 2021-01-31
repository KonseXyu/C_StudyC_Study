#include "head_Use.h"
//输出每个挂科人的信息
void Lowpoint(STU *p, int *back) 
{
	//Nobody:检查是否有人挂科，num进行计数 
	int Nobody = 1, num = 0;
	while (p != NULL) 
	{
		int flag = 0;
		//遍历科目
		int i;
		//需要科目数量！！！ 
		for (i = 0; i < 4; i++) 
		{	
			//判断是否挂科
			if (p->s[i] < 60) 
			{
				if (Nobody == 1)
					printf("\n挂科的学生信息：\n");
					 
				//存在人挂科	
				Nobody = 0;		
				
				//flag = 0输出此人挂科信息（只需输出一次） 
				if (flag == 0) 
				{
					//挂科人数加1 
					num++;		
					if (num % 4 == 0)
						system ("pause");
						
					printf("\n学号\t姓名\t性别\t学院\n");
							
					//输出个人信息
					printf("%lld\t%s\t%s\t%s\n",p->id, p->name, p->sid, p->scid);		
						
					flag = 1;
				}
				
				//输出挂科的科目和成绩 
				printf("挂科的科目是成绩%d，分数为：%d\n", i + 1, p->s[i]);	
				
			}
		}
		p = p->next;
	}
	
	if (Nobody == 1) 
	{
		printf("\n*******************************\n");
		printf ("\n读入的学生信息中没有学生挂科！\n");
		printf("\n*******************************\n");
	}
		
	else
	{
		printf("\n*****************************\n");
		printf("\n总共挂科的人数为：%d\n", num);
		
		printf("\n*****************************");
		printf("\n返回上一步请输入1，返回主菜单请输入2或其它，退出请输入0：");
		int t;
		scanf("%d",&t);	
		*back = t;
	 } 
	return; 
}

 //返回指定学院的挂科学生信息
void ScidLowpoint (STU *p, char *scidname)
 {
 	//Nobody:检查是否有人挂科，num进行计数 
	int Nobody = 1, num = 0;
	while (p != NULL) 
	{
		int flag = 0;
		//遍历科目
		int i;
		//需要科目数量！！！ 
		for (i = 0; i < 4; i++) 
		{	
			//判断是否挂科
			if (p->s[i] < 60 && strcmp(p->scid, scidname) == 0) 
			{
				if (Nobody == 1)
					printf("\n挂科的学生信息：\n");
					 
				//存在人挂科	
				Nobody = 0;		
				
				//flag = 0输出此人挂科信息（只需输出一次） 
				if (flag == 0) 
				{
					//挂科人数加1 
					num++;		
					if (num % 4 == 0)
						system ("pause");
						
					printf("\n学号\t姓名\t性别\n");
							
					//输出个人信息
					printf("%lld\t%s\t%s\n",p->id, p->name, p->sid);		
						
					flag = 1;
				}
				
				//输出挂科的科目和成绩 
				printf("挂科的科目是成绩%d，分数为：%d\n", i + 1, p->s[i]);	
				
			}
		}
		p = p->next;
	}
	
	if (Nobody == 1) 
	{
		printf("\n***********************\n");
		printf ("\n%s没有学生挂科！\n", scidname);
		printf("\n***********************\n");
	}
		
	else
	{
		printf("\n*****************************\n");
		printf("\n%s总共挂科的人数为：%d\n", scidname, num);
	}
	

		
	
	return; 
	
 }
