 #include "head_Use.h" 
 
//删除给定学号
STU *delID(STU *p_head, int *num, int *flg, int Snum)
{
	//1：按学号查找并删除信息
	long long int delid;
	printf("\n请输入要查找的id："); 
	scanf("%lld", &delid);
	 
	//pb:begin开始寻找，pf：find找到 
    STU *pb, *pf;
    //让pb指向头节点
    pb=p_head;
    
    //循环查找要删除的节点
    while(pb->id != delid && pb->next != NULL)
    {
        pf=pb;
        pb=pb->next;
    }
    //找到了一个节点的id和delnum相等
    if(pb->id == delid)
    {
    	//找到的节点是头节点
        if(pb == p_head)
        {
            p_head = pb->next;
        }
        //找到的节点是普通节点
        else
        {
            pf->next = pb->next;
        }
        free(pb);
        (*num)--;
    }
    //没有找到要删除的节点
    else 
    {
    	(*flg)--;
    	printf("\n*****************************");
    	printf("\n没有找到您要删除的学生信息!\n");
    	printf("*****************************\n");
    	system("pause");
	}        
	 
	 // 若删除后链表为空 
	if (*num == 0)
	{
		STU *p = (STU*) malloc(sizeof (STU));
		p->id = 0;
		strcpy(p->name, "空");
		strcpy(p->sid, "空");
		strcpy(p->scid, "空\t");
		int i;
		//需要科目数量！！！ 
		for(i = 0;i < Snum; i++)
			p->s[i] = 0 ; 
		p->ave = 0; 
		return p;
	 } 
	 
    return p_head;
}

//删除给定名字 
STU *delName(STU *p_head, int *num, int *flg, int Snum)
{
	//按姓名查找并删除信息
	char delname[L];
	printf("\n请输入要查找的名字："); 
	scanf("%s", delname);
	 
	//pb:begin开始寻找，pf：find找到 
    STU *pb, *pf;
    //让pb指向头节点
    pb=p_head;
    
    //循环查找要删除的节点
    while(strcmp(pb->name, delname) != 0 && pb->next != NULL)
    {
        pf=pb;
        pb=pb->next;
    }
    //找到了一个节点的id和delnum相等
    if(strcmp(pb->name, delname) == 0)
    {
    	//找到的节点是头节点
        if(pb == p_head)
        {
            p_head = pb->next;
        }
        //找到的节点是普通节点
        else
        {
            pf->next = pb->next;
        }
    	free(pb);
        (*num)--;
    }
    //没有找到要删除的节点
    else
    {
    	(*flg)--;
    	printf("\n*****************************");
    	printf("\n没有找到您要删除的学生信息!\n");
    	printf("*****************************\n");
    	system("pause");
	}
	
	 // 若删除后链表为空 
	if (*num == 0)
	{
		STU *p = (STU*) malloc(sizeof (STU));
		p->id = 0;
		strcpy(p->name, "空");
		strcpy(p->sid, "空");
		strcpy(p->scid, "空\t");
		int i;
		//需要科目数量！！！ 
		for(i = 0;i < Snum; i++)
			p->s[i] = 0 ; 
		p->ave = 0; 
		return p;
 	} 
 	
 	return p_head;	
}
		

