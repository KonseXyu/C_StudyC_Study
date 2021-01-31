#include "head_Use.h" 

//查找指定学院的学生信息
void searchScid (STU *p, char *scidname, char *Subjectfilename)
 {
 	
 	int num;
 	//获取科目信息 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
 	//flag = 1:首次检查到与查找名字相等  
	int flag = 1;
	
 	while(p != NULL)   
	  {
	  	if (strcmp(p->scid, scidname) == 0)
	  	{
	  		if (flag == 1)
	  		{
	  			flag = 0; 
	  			fprintf(stdout, "\n%s的学生信息:\n\n", p->scid);
				fprintf(stdout, "学号\t姓名\t性别\t学院\t\t");
				int i;
				for(i = 0; i < num; i++)
					printf("%s\t", (q + i)->s);
				printf("平均成绩\n");
	  		}

 	 		//输出到屏幕做反馈 
 	 		outputScreen (p, num, q);
		}
		p = p->next;
	  } 

	return;
 }
