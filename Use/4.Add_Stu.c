#include "head_Use.h" 

//增加学生信息(表头) 
STU *addIdUp (STU *head, int *num, char *Sidfilename, char *Scidfilename, char *Subjectfilename)
{
	int Snum;
 	//获取科目信息 
 	KMID *p = Subjectfile(Subjectfilename, &Snum);
 	
	//若链表为空 
	if (*num == 0)
	{
		(*num)++;
		STU *q = (STU *) malloc(sizeof (STU));
		if(q == NULL)
		{
			printf("malloc(addid) fail!");
			return NULL;
		}
	
		//输入新的学生信息 
		printf("请输入增加学生的学号："); 
	    scanf("%lld", &q->id);
	    printf("请输入增加学生的姓名："); 
	    scanf("%s", q->name);
	    printf("请输入增加学生的性别："); 
	    scanf("%s", q->sid);
	    //检查是否需要换性别代码 
   		sidnameOne(Sidfilename, q);
	    printf("请输入增加学生的学院名字："); 
	    //检查是否需要换学院代码 
    	scidnameOne(Scidfilename, q);
	    scanf("%s", q->scid);
	    int i;
	    for(i = 0; i < Snum; i++)
	    {
	    	printf("请输入增加学生的%s成绩：", (p + i)->s); 
	    	scanf("%d", &q->s[i]);
		}
		averageOne(q, Subjectfilename);
		return q;
	}	
	
    (*num)++;
    
    //开辟新的储存学生信息的空间 
	STU *q = (STU *) malloc(sizeof (STU));
	if(q == NULL)
	{
		printf("malloc(addidUp) fail!");
		return NULL;
	}
	
	//输入新的学生信息 
	printf("请输入增加学生的学号："); 
    scanf("%lld", &q->id);
    printf("请输入增加学生的姓名："); 
    scanf("%s", q->name);
    printf("请输入增加学生的性别："); 
    scanf("%s", q->sid);
    //检查是否需要换性别代码 
    sidnameOne(Sidfilename, q);
    printf("请输入增加学生的学院名字："); 
    scanf("%s", q->scid);
    //检查是否需要换学院代码 
    scidnameOne(Scidfilename, q);
    
    int i;
    for(i = 0; i < Snum; i++)
    {
    	printf("请输入增加学生的%s成绩：", (p + i)->s);  
    	scanf("%d", &q->s[i]);
	}
	averageOne(q, Subjectfilename);
	
	//使得q加入加入p的开头 
	q->next = head;
	head = q;

	return head;
 } 

//增加学生信息 （表尾） 
//新建一个节点并添加到链表末尾，并返回添加节点后的链表的头指针
 STU *addIdDown (STU *head, int *num, char *Sidfilename, char *Scidfilename, char *Subjectfilename)
{
	int Snum;
 	//获取科目信息 
 	KMID *p_s = Subjectfile(Subjectfilename, &Snum);
 	
	//若链表为空 
	if (*num == 0)
	{
		(*num)++;
		STU *q = (STU *) malloc(sizeof (STU));
		if(q == NULL)
		{
			printf("malloc(addid) fail!");
			return NULL;
		}
	
		//输入新的学生信息 
		printf("请输入增加学生的学号："); 
	    scanf("%lld", &q->id);
	    printf("请输入增加学生的姓名："); 
	    scanf("%s", q->name);
	    printf("请输入增加学生的性别："); 
	    scanf("%s", q->sid);
	    //检查是否需要换性别代码 
   		sidnameOne(Sidfilename, q);
	    printf("请输入增加学生的学院名字："); 
	    //检查是否需要换学院代码 
    	scidnameOne(Scidfilename, q);
	    scanf("%s", q->scid);
	    int i;
	    for(i = 0; i < Snum; i++)
	    {
	    	printf("请输入增加学生的%s成绩：", (p_s + i)->s); 
	    	scanf("%d", &q->s[i]);
		}
		averageOne(q, Subjectfilename);
		return q;
	}	
	
    (*num)++;
    
    STU *q = head;
    //若未到表尾，则移动pr直到pr指向表尾
    while (q->next != NULL)    
    	//让pr指向下一个节点
 		q = q->next;  

    //让p指向新节点 
    STU *p = (STU *)malloc(sizeof(STU));
    if(p == NULL)
	{
		printf("malloc(addid) Fail!");
		return NULL;
	}
	
	//输入新的学生信息 
	printf("请输入增加学生的学号："); 
    scanf("%lld", &p->id);
    printf("请输入增加学生的姓名："); 
    scanf("%s", p->name);
    printf("请输入增加学生的性别："); 
    scanf("%s", p->sid);
    //检查是否需要换性别代码 
    sidnameOne(Sidfilename, p);
    printf("请输入增加学生的学院名字："); 
    scanf("%s", p->scid);
    //检查是否需要换学院代码 
    scidnameOne(Scidfilename, p);
    
    int i;
    for(i = 0; i < Snum; i++)
    {
    	printf("请输入增加学生的%s成绩：", (p_s + i)->s); 
    	scanf("%d", &p->s[i]);
	}
	averageOne(p, Subjectfilename);
	
	//让末节点的指针域指向新建节点        
    q->next = p;               
    p->next = NULL;
    
    return head;
}
