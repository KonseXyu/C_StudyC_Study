#include "head_Use.h" 

 //���������֣����룩 
STU *sortStunameDown (STU *head)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//��ȡ��head->nextΪNULL��ֹͣѭ�� 
    while (first != NULL)   
    {  
    	//qҪ������Ǹ�ֵ�������жϣ���q��ֵ����p��qָ����һ����ֱ���ҵ�Ҫ�����λ�á� 
        for (t = first, q = head; (q != NULL && strcmp(q->name , t->name) < 0); p = q, q = q->next) ;   
		
		//firstָ����һ�����鿴head���¸�next�Ƿ�ΪNULL 
        first = first->next;
		//��forѭ����q��ȻΪheadλ�ã����ʱq->aveΪ���������ֱ��ָ����һλ�� 
        if (q == head)    
            head = t; 
		//������Ҫ����λ�û��� 
        else
            p->next = t;
			  
        t->next = q;
    }
    printf("\n�����ֽ�������ɹ���\n\n"); 
    
    return head;
}


 //�����������֣����룩 
STU *sortStunameUp (STU *head)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//��ȡ��head->nextΪNULL��ֹͣѭ�� 
    while (first != NULL)   
    {  
    	//qҪ������Ǹ�ֵ�������жϣ���q��ֵ����p��qָ����һ����ֱ���ҵ�Ҫ�����λ�á� 
        for (t = first, q = head; (q != NULL && strcmp(q->name , t->name) > 0); p = q, q = q->next) ;   
		
		//firstָ����һ�����鿴head���¸�next�Ƿ�ΪNULL 
        first = first->next;
		//��forѭ����q��ȻΪheadλ�ã����ʱq->aveΪ���������ֱ��ָ����һλ�� 
        if (q == head)    
            head = t; 
		//������Ҫ����λ�û��� 
        else
            p->next = t;
			  
        t->next = q;
    }
    printf("\n��������������ɹ���\n\n"); 
    
    return head;
}


//������ave�����룩 
STU *sortStuscoreDown (STU *head)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//��ȡ��head->nextΪNULL��ֹͣѭ�� 
    while (first != NULL)   
    {  
    	//qҪ������Ǹ�ֵ�������жϣ���q��ֵ����p��qָ����һ����ֱ���ҵ�Ҫ�����λ�á� 
        for (t = first, q = head; ((q != NULL) && (q->ave > t->ave)); p = q, q = q->next) ;   
		
		//firstָ����һ�����鿴head���¸�next�Ƿ�ΪNULL 
        first = first->next;
		//��forѭ����q��ȻΪheadλ�ã����ʱq->aveΪ���������ֱ��ָ����һλ�� 
        if (q == head)    
            head = t; 
		//������Ҫ����λ�û��� 
        else
            p->next = t;
			  
        t->next = q;
    }
	printf("\n��ƽ���ɼ���������ɹ���\n\n"); 
	
    return head;  
}


//��������ave�����룩 
STU *sortStuscoreUp (STU *head)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//��ȡ��head->nextΪNULL��ֹͣѭ�� 
    while (first != NULL)   
    {  
    	//qҪ������Ǹ�ֵ�������жϣ���q��ֵ����p��qָ����һ����ֱ���ҵ�Ҫ�����λ�á� 
        for (t = first, q = head; ((q != NULL) && (q->ave < t->ave)); p = q, q = q->next) ;   
		
		//firstָ����һ�����鿴head���¸�next�Ƿ�ΪNULL 
        first = first->next;
		//��forѭ����q��ȻΪheadλ�ã����ʱq->aveΪ���������ֱ��ָ����һλ�� 
        if (q == head)    
            head = t; 
		//������Ҫ����λ�û��� 
        else
            p->next = t;
			  
        t->next = q;
    }
	printf("\n��ƽ���ɼ���������ɹ���\n\n"); 
	
    return head;  
}

// ���������Ŀ�����룩 
STU *Subject_Sort_Up(STU *head, int num)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//��ȡ��head->nextΪNULL��ֹͣѭ�� 
    while (first != NULL)   
    {  
    	//qҪ������Ǹ�ֵ�������жϣ���q��ֵ����p��qָ����һ����ֱ���ҵ�Ҫ�����λ�á� 
        for (t = first, q = head; ((q != NULL) && (q->s[num] < t->s[num])); p = q, q = q->next) ;   
		
		//firstָ����һ�����鿴head���¸�next�Ƿ�ΪNULL 
        first = first->next;
		//��forѭ����q��ȻΪheadλ�ã����ʱq->aveΪ���������ֱ��ָ����һλ�� 
        if (q == head)    
            head = t; 
		//������Ҫ����λ�û��� 
        else
            p->next = t;
			  
        t->next = q;
    }
	printf("\n���˿�Ŀ�ɼ���������ɹ���\n\n"); 
	
    return head;  
}

// �������Ŀ�����룩
STU *Subject_Sort_Down(STU *head, int num)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//��ȡ��head->nextΪNULL��ֹͣѭ�� 
    while (first != NULL)   
    {  
    	//qҪ������Ǹ�ֵ�������жϣ���q��ֵ����p��qָ����һ����ֱ���ҵ�Ҫ�����λ�á� 
        for (t = first, q = head; ((q != NULL) && (q->s[num] > t->s[num])); p = q, q = q->next) ;   
		
		//firstָ����һ�����鿴head���¸�next�Ƿ�ΪNULL 
        first = first->next;
		//��forѭ����q��ȻΪheadλ�ã����ʱq->aveΪ���������ֱ��ָ����һλ�� 
        if (q == head)    
            head = t; 
		//������Ҫ����λ�û��� 
        else
            p->next = t;
			  
        t->next = q;
    }
	printf("\n���˿�Ŀ��������ɹ���\n\n"); 
	
    return head;  
}
