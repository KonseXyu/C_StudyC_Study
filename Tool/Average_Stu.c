#include "head_tool.h" 

//���㵥�˵�ʮ�γɼ�ƽ��ֵ ����Ҫ��Ŀ�������� 
void averageOne(STU *p, char *Subjectfilename)
{
	int num, i;
 	//��ȡ��Ŀ��Ϣ 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
 	double sum = 0;
	for(i = 0; i < num; i++)
		sum += p->s[i];
	p->ave = sum / num;
	
	return; 
} 

//����ÿ���˵�ʮ�γɼ�ƽ��ֵ ����Ҫ��Ŀ�������� 
void average(STU *p, char *Subjectfilename)
{
	int num, i;
 	//��ȡ��Ŀ��Ϣ 
 	KMID *q = Subjectfile(Subjectfilename, &num);
 	
	while (p != NULL)
	{
		//��ÿ��ѧ����ƽ��ֵ 
		double sum = 0;
		for(i = 0; i < num; i++)
		sum += p->s[i];
		p->ave = sum / num;
		
		p = p->next;	
	}
	return;
}
