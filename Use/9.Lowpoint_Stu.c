#include "head_Use.h"
//���ÿ���ҿ��˵���Ϣ
void Lowpoint(STU *p, int *back) 
{
	//Nobody:����Ƿ����˹ҿƣ�num���м��� 
	int Nobody = 1, num = 0;
	while (p != NULL) 
	{
		int flag = 0;
		//������Ŀ
		int i;
		//��Ҫ��Ŀ���������� 
		for (i = 0; i < 4; i++) 
		{	
			//�ж��Ƿ�ҿ�
			if (p->s[i] < 60) 
			{
				if (Nobody == 1)
					printf("\n�ҿƵ�ѧ����Ϣ��\n");
					 
				//�����˹ҿ�	
				Nobody = 0;		
				
				//flag = 0������˹ҿ���Ϣ��ֻ�����һ�Σ� 
				if (flag == 0) 
				{
					//�ҿ�������1 
					num++;		
					if (num % 4 == 0)
						system ("pause");
						
					printf("\nѧ��\t����\t�Ա�\tѧԺ\n");
							
					//���������Ϣ
					printf("%lld\t%s\t%s\t%s\n",p->id, p->name, p->sid, p->scid);		
						
					flag = 1;
				}
				
				//����ҿƵĿ�Ŀ�ͳɼ� 
				printf("�ҿƵĿ�Ŀ�ǳɼ�%d������Ϊ��%d\n", i + 1, p->s[i]);	
				
			}
		}
		p = p->next;
	}
	
	if (Nobody == 1) 
	{
		printf("\n*******************************\n");
		printf ("\n�����ѧ����Ϣ��û��ѧ���ҿƣ�\n");
		printf("\n*******************************\n");
	}
		
	else
	{
		printf("\n*****************************\n");
		printf("\n�ܹ��ҿƵ�����Ϊ��%d\n", num);
		
		printf("\n*****************************");
		printf("\n������һ��������1���������˵�������2���������˳�������0��");
		int t;
		scanf("%d",&t);	
		*back = t;
	 } 
	return; 
}

 //����ָ��ѧԺ�Ĺҿ�ѧ����Ϣ
void ScidLowpoint (STU *p, char *scidname)
 {
 	//Nobody:����Ƿ����˹ҿƣ�num���м��� 
	int Nobody = 1, num = 0;
	while (p != NULL) 
	{
		int flag = 0;
		//������Ŀ
		int i;
		//��Ҫ��Ŀ���������� 
		for (i = 0; i < 4; i++) 
		{	
			//�ж��Ƿ�ҿ�
			if (p->s[i] < 60 && strcmp(p->scid, scidname) == 0) 
			{
				if (Nobody == 1)
					printf("\n�ҿƵ�ѧ����Ϣ��\n");
					 
				//�����˹ҿ�	
				Nobody = 0;		
				
				//flag = 0������˹ҿ���Ϣ��ֻ�����һ�Σ� 
				if (flag == 0) 
				{
					//�ҿ�������1 
					num++;		
					if (num % 4 == 0)
						system ("pause");
						
					printf("\nѧ��\t����\t�Ա�\n");
							
					//���������Ϣ
					printf("%lld\t%s\t%s\n",p->id, p->name, p->sid);		
						
					flag = 1;
				}
				
				//����ҿƵĿ�Ŀ�ͳɼ� 
				printf("�ҿƵĿ�Ŀ�ǳɼ�%d������Ϊ��%d\n", i + 1, p->s[i]);	
				
			}
		}
		p = p->next;
	}
	
	if (Nobody == 1) 
	{
		printf("\n***********************\n");
		printf ("\n%sû��ѧ���ҿƣ�\n", scidname);
		printf("\n***********************\n");
	}
		
	else
	{
		printf("\n*****************************\n");
		printf("\n%s�ܹ��ҿƵ�����Ϊ��%d\n", scidname, num);
	}
	

		
	
	return; 
	
 }
