#include "head_Use.h" 

//����ѧ����Ϣ(��ͷ) 
STU *addIdUp (STU *head, int *num, char *Sidfilename, char *Scidfilename, char *Subjectfilename)
{
	int Snum;
 	//��ȡ��Ŀ��Ϣ 
 	KMID *p = Subjectfile(Subjectfilename, &Snum);
 	
	//������Ϊ�� 
	if (*num == 0)
	{
		(*num)++;
		STU *q = (STU *) malloc(sizeof (STU));
		if(q == NULL)
		{
			printf("malloc(addid) fail!");
			return NULL;
		}
	
		//�����µ�ѧ����Ϣ 
		printf("����������ѧ����ѧ�ţ�"); 
	    scanf("%lld", &q->id);
	    printf("����������ѧ����������"); 
	    scanf("%s", q->name);
	    printf("����������ѧ�����Ա�"); 
	    scanf("%s", q->sid);
	    //����Ƿ���Ҫ���Ա���� 
   		sidnameOne(Sidfilename, q);
	    printf("����������ѧ����ѧԺ���֣�"); 
	    //����Ƿ���Ҫ��ѧԺ���� 
    	scidnameOne(Scidfilename, q);
	    scanf("%s", q->scid);
	    int i;
	    for(i = 0; i < Snum; i++)
	    {
	    	printf("����������ѧ����%s�ɼ���", (p + i)->s); 
	    	scanf("%d", &q->s[i]);
		}
		averageOne(q, Subjectfilename);
		return q;
	}	
	
    (*num)++;
    
    //�����µĴ���ѧ����Ϣ�Ŀռ� 
	STU *q = (STU *) malloc(sizeof (STU));
	if(q == NULL)
	{
		printf("malloc(addidUp) fail!");
		return NULL;
	}
	
	//�����µ�ѧ����Ϣ 
	printf("����������ѧ����ѧ�ţ�"); 
    scanf("%lld", &q->id);
    printf("����������ѧ����������"); 
    scanf("%s", q->name);
    printf("����������ѧ�����Ա�"); 
    scanf("%s", q->sid);
    //����Ƿ���Ҫ���Ա���� 
    sidnameOne(Sidfilename, q);
    printf("����������ѧ����ѧԺ���֣�"); 
    scanf("%s", q->scid);
    //����Ƿ���Ҫ��ѧԺ���� 
    scidnameOne(Scidfilename, q);
    
    int i;
    for(i = 0; i < Snum; i++)
    {
    	printf("����������ѧ����%s�ɼ���", (p + i)->s);  
    	scanf("%d", &q->s[i]);
	}
	averageOne(q, Subjectfilename);
	
	//ʹ��q�������p�Ŀ�ͷ 
	q->next = head;
	head = q;

	return head;
 } 

//����ѧ����Ϣ ����β�� 
//�½�һ���ڵ㲢��ӵ�����ĩβ����������ӽڵ��������ͷָ��
 STU *addIdDown (STU *head, int *num, char *Sidfilename, char *Scidfilename, char *Subjectfilename)
{
	int Snum;
 	//��ȡ��Ŀ��Ϣ 
 	KMID *p_s = Subjectfile(Subjectfilename, &Snum);
 	
	//������Ϊ�� 
	if (*num == 0)
	{
		(*num)++;
		STU *q = (STU *) malloc(sizeof (STU));
		if(q == NULL)
		{
			printf("malloc(addid) fail!");
			return NULL;
		}
	
		//�����µ�ѧ����Ϣ 
		printf("����������ѧ����ѧ�ţ�"); 
	    scanf("%lld", &q->id);
	    printf("����������ѧ����������"); 
	    scanf("%s", q->name);
	    printf("����������ѧ�����Ա�"); 
	    scanf("%s", q->sid);
	    //����Ƿ���Ҫ���Ա���� 
   		sidnameOne(Sidfilename, q);
	    printf("����������ѧ����ѧԺ���֣�"); 
	    //����Ƿ���Ҫ��ѧԺ���� 
    	scidnameOne(Scidfilename, q);
	    scanf("%s", q->scid);
	    int i;
	    for(i = 0; i < Snum; i++)
	    {
	    	printf("����������ѧ����%s�ɼ���", (p_s + i)->s); 
	    	scanf("%d", &q->s[i]);
		}
		averageOne(q, Subjectfilename);
		return q;
	}	
	
    (*num)++;
    
    STU *q = head;
    //��δ����β�����ƶ�prֱ��prָ���β
    while (q->next != NULL)    
    	//��prָ����һ���ڵ�
 		q = q->next;  

    //��pָ���½ڵ� 
    STU *p = (STU *)malloc(sizeof(STU));
    if(p == NULL)
	{
		printf("malloc(addid) Fail!");
		return NULL;
	}
	
	//�����µ�ѧ����Ϣ 
	printf("����������ѧ����ѧ�ţ�"); 
    scanf("%lld", &p->id);
    printf("����������ѧ����������"); 
    scanf("%s", p->name);
    printf("����������ѧ�����Ա�"); 
    scanf("%s", p->sid);
    //����Ƿ���Ҫ���Ա���� 
    sidnameOne(Sidfilename, p);
    printf("����������ѧ����ѧԺ���֣�"); 
    scanf("%s", p->scid);
    //����Ƿ���Ҫ��ѧԺ���� 
    scidnameOne(Scidfilename, p);
    
    int i;
    for(i = 0; i < Snum; i++)
    {
    	printf("����������ѧ����%s�ɼ���", (p_s + i)->s); 
    	scanf("%d", &p->s[i]);
	}
	averageOne(p, Subjectfilename);
	
	//��ĩ�ڵ��ָ����ָ���½��ڵ�        
    q->next = p;               
    p->next = NULL;
    
    return head;
}
