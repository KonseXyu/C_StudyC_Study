#include "head_Use.h" 

//����ָ��ѧԺ��ѧ����Ϣ
void searchScid (STU *p, char *scidname, char *Subjectfilename)
 {
 	
 	int num;
 	//��ȡ��Ŀ��Ϣ 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
 	//flag = 1:�״μ�鵽������������  
	int flag = 1;
	
 	while(p != NULL)   
	  {
	  	if (strcmp(p->scid, scidname) == 0)
	  	{
	  		if (flag == 1)
	  		{
	  			flag = 0; 
	  			fprintf(stdout, "\n%s��ѧ����Ϣ:\n\n", p->scid);
				fprintf(stdout, "ѧ��\t����\t�Ա�\tѧԺ\t\t");
				int i;
				for(i = 0; i < num; i++)
					printf("%s\t", (q + i)->s);
				printf("ƽ���ɼ�\n");
	  		}

 	 		//�������Ļ������ 
 	 		outputScreen (p, num, q);
		}
		p = p->next;
	  } 

	return;
 }
