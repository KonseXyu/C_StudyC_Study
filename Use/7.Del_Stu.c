 #include "head_Use.h" 
 
//ɾ������ѧ��
STU *delID(STU *p_head, int *num, int *flg, int Snum)
{
	//1����ѧ�Ų��Ҳ�ɾ����Ϣ
	long long int delid;
	printf("\n������Ҫ���ҵ�id��"); 
	scanf("%lld", &delid);
	 
	//pb:begin��ʼѰ�ң�pf��find�ҵ� 
    STU *pb, *pf;
    //��pbָ��ͷ�ڵ�
    pb=p_head;
    
    //ѭ������Ҫɾ���Ľڵ�
    while(pb->id != delid && pb->next != NULL)
    {
        pf=pb;
        pb=pb->next;
    }
    //�ҵ���һ���ڵ��id��delnum���
    if(pb->id == delid)
    {
    	//�ҵ��Ľڵ���ͷ�ڵ�
        if(pb == p_head)
        {
            p_head = pb->next;
        }
        //�ҵ��Ľڵ�����ͨ�ڵ�
        else
        {
            pf->next = pb->next;
        }
        free(pb);
        (*num)--;
    }
    //û���ҵ�Ҫɾ���Ľڵ�
    else 
    {
    	(*flg)--;
    	printf("\n*****************************");
    	printf("\nû���ҵ���Ҫɾ����ѧ����Ϣ!\n");
    	printf("*****************************\n");
    	system("pause");
	}        
	 
	 // ��ɾ��������Ϊ�� 
	if (*num == 0)
	{
		STU *p = (STU*) malloc(sizeof (STU));
		p->id = 0;
		strcpy(p->name, "��");
		strcpy(p->sid, "��");
		strcpy(p->scid, "��\t");
		int i;
		//��Ҫ��Ŀ���������� 
		for(i = 0;i < Snum; i++)
			p->s[i] = 0 ; 
		p->ave = 0; 
		return p;
	 } 
	 
    return p_head;
}

//ɾ���������� 
STU *delName(STU *p_head, int *num, int *flg, int Snum)
{
	//���������Ҳ�ɾ����Ϣ
	char delname[L];
	printf("\n������Ҫ���ҵ����֣�"); 
	scanf("%s", delname);
	 
	//pb:begin��ʼѰ�ң�pf��find�ҵ� 
    STU *pb, *pf;
    //��pbָ��ͷ�ڵ�
    pb=p_head;
    
    //ѭ������Ҫɾ���Ľڵ�
    while(strcmp(pb->name, delname) != 0 && pb->next != NULL)
    {
        pf=pb;
        pb=pb->next;
    }
    //�ҵ���һ���ڵ��id��delnum���
    if(strcmp(pb->name, delname) == 0)
    {
    	//�ҵ��Ľڵ���ͷ�ڵ�
        if(pb == p_head)
        {
            p_head = pb->next;
        }
        //�ҵ��Ľڵ�����ͨ�ڵ�
        else
        {
            pf->next = pb->next;
        }
    	free(pb);
        (*num)--;
    }
    //û���ҵ�Ҫɾ���Ľڵ�
    else
    {
    	(*flg)--;
    	printf("\n*****************************");
    	printf("\nû���ҵ���Ҫɾ����ѧ����Ϣ!\n");
    	printf("*****************************\n");
    	system("pause");
	}
	
	 // ��ɾ��������Ϊ�� 
	if (*num == 0)
	{
		STU *p = (STU*) malloc(sizeof (STU));
		p->id = 0;
		strcpy(p->name, "��");
		strcpy(p->sid, "��");
		strcpy(p->scid, "��\t");
		int i;
		//��Ҫ��Ŀ���������� 
		for(i = 0;i < Snum; i++)
			p->s[i] = 0 ; 
		p->ave = 0; 
		return p;
 	} 
 	
 	return p_head;	
}
		

