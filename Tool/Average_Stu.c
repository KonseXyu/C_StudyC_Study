#include "head_tool.h" 

//计算单人的十次成绩平均值 （需要科目数量！） 
void averageOne(STU *p, char *Subjectfilename)
{
	int num, i;
 	//获取科目信息 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
 	double sum = 0;
	for(i = 0; i < num; i++)
		sum += p->s[i];
	p->ave = sum / num;
	
	return; 
} 

//计算每个人的十次成绩平均值 （需要科目数量！） 
void average(STU *p, char *Subjectfilename)
{
	int num, i;
 	//获取科目信息 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
	while (p != NULL)
	{
		//求每个学生的平均值 
		double sum = 0;
		for(i = 0; i < num; i++)
		sum += p->s[i];
		p->ave = sum / num;
		
		p = p->next;	
	}
	return;
}
