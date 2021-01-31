#include "head_Use.h" 

 //排序降序名字（插入） 
STU *sortStunameDown (STU *head)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//读取到head->next为NULL则停止循环 
    while (first != NULL)   
    {  
    	//q要插入的那个值，进行判断，将q的值赋个p，q指向下一个，直到找到要插入的位置。 
        for (t = first, q = head; (q != NULL && strcmp(q->name , t->name) < 0); p = q, q = q->next) ;   
		
		//first指向下一个，查看head的下个next是否为NULL 
        first = first->next;
		//若for循环后q仍然为head位置，则此时q->ave为数据中最大，直接指向下一位。 
        if (q == head)    
            head = t; 
		//否则与要插入位置互换 
        else
            p->next = t;
			  
        t->next = q;
    }
    printf("\n按名字降序排序成功！\n\n"); 
    
    return head;
}


 //排序升序名字（插入） 
STU *sortStunameUp (STU *head)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//读取到head->next为NULL则停止循环 
    while (first != NULL)   
    {  
    	//q要插入的那个值，进行判断，将q的值赋个p，q指向下一个，直到找到要插入的位置。 
        for (t = first, q = head; (q != NULL && strcmp(q->name , t->name) > 0); p = q, q = q->next) ;   
		
		//first指向下一个，查看head的下个next是否为NULL 
        first = first->next;
		//若for循环后q仍然为head位置，则此时q->ave为数据中最大，直接指向下一位。 
        if (q == head)    
            head = t; 
		//否则与要插入位置互换 
        else
            p->next = t;
			  
        t->next = q;
    }
    printf("\n按名字升序排序成功！\n\n"); 
    
    return head;
}


//排序降序ave（插入） 
STU *sortStuscoreDown (STU *head)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//读取到head->next为NULL则停止循环 
    while (first != NULL)   
    {  
    	//q要插入的那个值，进行判断，将q的值赋个p，q指向下一个，直到找到要插入的位置。 
        for (t = first, q = head; ((q != NULL) && (q->ave > t->ave)); p = q, q = q->next) ;   
		
		//first指向下一个，查看head的下个next是否为NULL 
        first = first->next;
		//若for循环后q仍然为head位置，则此时q->ave为数据中最大，直接指向下一位。 
        if (q == head)    
            head = t; 
		//否则与要插入位置互换 
        else
            p->next = t;
			  
        t->next = q;
    }
	printf("\n按平均成绩降序排序成功！\n\n"); 
	
    return head;  
}


//排序升序ave（插入） 
STU *sortStuscoreUp (STU *head)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//读取到head->next为NULL则停止循环 
    while (first != NULL)   
    {  
    	//q要插入的那个值，进行判断，将q的值赋个p，q指向下一个，直到找到要插入的位置。 
        for (t = first, q = head; ((q != NULL) && (q->ave < t->ave)); p = q, q = q->next) ;   
		
		//first指向下一个，查看head的下个next是否为NULL 
        first = first->next;
		//若for循环后q仍然为head位置，则此时q->ave为数据中最大，直接指向下一位。 
        if (q == head)    
            head = t; 
		//否则与要插入位置互换 
        else
            p->next = t;
			  
        t->next = q;
    }
	printf("\n按平均成绩升序排序成功！\n\n"); 
	
    return head;  
}

// 排序升序科目（插入） 
STU *Subject_Sort_Up(STU *head, int num)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//读取到head->next为NULL则停止循环 
    while (first != NULL)   
    {  
    	//q要插入的那个值，进行判断，将q的值赋个p，q指向下一个，直到找到要插入的位置。 
        for (t = first, q = head; ((q != NULL) && (q->s[num] < t->s[num])); p = q, q = q->next) ;   
		
		//first指向下一个，查看head的下个next是否为NULL 
        first = first->next;
		//若for循环后q仍然为head位置，则此时q->ave为数据中最大，直接指向下一位。 
        if (q == head)    
            head = t; 
		//否则与要插入位置互换 
        else
            p->next = t;
			  
        t->next = q;
    }
	printf("\n按此科目成绩升序排序成功！\n\n"); 
	
    return head;  
}

// 排序降序科目（插入）
STU *Subject_Sort_Down(STU *head, int num)
{
	STU *first, *t, *p, *q;
	first = head->next;   
    head->next = NULL;
	//读取到head->next为NULL则停止循环 
    while (first != NULL)   
    {  
    	//q要插入的那个值，进行判断，将q的值赋个p，q指向下一个，直到找到要插入的位置。 
        for (t = first, q = head; ((q != NULL) && (q->s[num] > t->s[num])); p = q, q = q->next) ;   
		
		//first指向下一个，查看head的下个next是否为NULL 
        first = first->next;
		//若for循环后q仍然为head位置，则此时q->ave为数据中最大，直接指向下一位。 
        if (q == head)    
            head = t; 
		//否则与要插入位置互换 
        else
            p->next = t;
			  
        t->next = q;
    }
	printf("\n按此科目降序排序成功！\n\n"); 
	
    return head;  
}
