#include "head_tool.h" 



//�������Ļ 
void outputScreen (STU *p, int Snum)
{
	fprintf(stdout, "%lld\t%s\t%s\t%s   \t", p->id, p->name, p->sid, p->scid);
	int i; 
	for(i = 0; i < Snum; i++)
	   	fprintf(stdout, "%d\t", p->s[i]);
	fprintf(stdout, "%-.2f\n", p->ave);
	return ;
}

//������ļ�
void outputFile (FILE *fp, STU *p, int Snum)
{
	fprintf(fp, "%lld\t%s\t%s\t%-s        \t", p->id, p->name, p->sid, p->scid);
	int i; 
	for(i = 0; i < Snum; i++)
	   	fprintf(fp, "%d\t", p->s[i]);
	fprintf(fp, "%-.2f\n", p->ave);
	return ;
 } 
 
 //�����������Ļ��ģ�� 
void outputcaseS (STU *p, int Snum, KMID *Sub)
{
	fprintf(stdout, "ѧ��\t����\t�Ա�\tѧԺ\t\t");
	int i;
	for(i = 0; i < Snum; i++)
		printf("%s\t", (Sub + i)->s);
	printf("ƽ���ɼ�\n");
	int n = 0;
	while(p != NULL)
	  {
	  	//������ֺ���ͣ 
	  	n++;
	  	if (n % 19 == 0) 
		  {
		  	printf("\n�鿴��һҳ��");
		  	system("pause");
		  	fprintf(stdout, "ѧ��\t����\t�Ա�\tѧԺ\t\t");
			int i;
			for(i = 0; i < Snum; i++)
				printf("%s\t", (Sub + i)->s);
			printf("ƽ���ɼ�\n");
		  }
		  
 	 	//�������Ļ������ 
 	 	outputScreen(p, Snum);
		p = p->next;
	  }
	
	return;
}

 //����������ļ���ģ�� 
void outputcaseF (STU *p, FILE *fp, int Snum, KMID *Sub)
{
	fprintf(fp, "\n#ѧ��\t����\t�Ա�\tѧԺ\t\t");
	int i;
	for(i = 0; i < Snum; i++)
		fprintf(fp, "%s\t", (Sub + i)->s);
	fprintf(fp,"ƽ���ɼ�\n");
	while(p != NULL)
	  { 
 	 	//������ļ� 
 	 	outputFile(fp, p, Snum);
		p = p->next;
	  }
	
	return;
}

 
//�����������Ļ���ļ���ģ�� 
void outputcaseSF (STU *p, FILE *fp, int Snum, KMID *Sub)
{
	fprintf(stdout, "ѧ��\t����\t�Ա�\tѧԺ\t\t");
	fprintf(fp, "\n#ѧ��\t����\t�Ա�\tѧԺ\t\t");
	int i;
	for(i = 0; i < Snum; i++)
	{
		printf("%s\t", (Sub + i)->s);
		fprintf(fp, "%s\t", (Sub + i)->s);	
	}
	printf("ƽ���ɼ�\n");
	fprintf(fp,"ƽ���ɼ�\n");
	
	int n = 0;
	while(p != NULL)
	  {
	  	//������ֺ���ͣ 
	  	n++;
	  	if (n % 19 == 0) 
		  {
		  	printf("\n�鿴��һҳ��");
		  	system("pause");
		  	fprintf(stdout, "ѧ��\t����\t�Ա�\tѧԺ\t\t");
			int i;
			for(i = 0; i < Snum; i++)
				printf("%s\t", (Sub + i)->s);
			printf("ƽ���ɼ�\n");
		  }
	  	//������ļ� 
	  	outputFile (fp, p, Snum);
	  	
 	 	//�������Ļ������ 
 	 	outputScreen(p, Snum);
		p = p->next;
	  }
	
	fclose(fp); 
	return;
}

/*
//��ȡ�ļ�����ʾѧ����Ϣ
void outputcase1 (char *filename, STU *p)
{
	fprintf(stdout, "\n��ȡ����ѧ����Ϣ:\n\n");
	
	outputcaseS (filename, p);
	
	return;
}
*/

//��������������ʾ��Ϣ 
void outputcase1 (char *filename, STU *p, int choose, int Snum, KMID *Sub)
 {
	//�������Ļ������ 
	
	if (choose == 1)
		fprintf(stdout, "�����ֽ���������ѧ����Ϣ:\n\n");
	else if (choose == 2)
		fprintf(stdout, "����������������ѧ����Ϣ:\n\n");
	
	outputcaseS (p, Snum, Sub);

	return ;
 }
 
//���տ�Ŀ�ɼ�������ʾ��Ϣ
void outputcase2_Subject (char *filename, STU *p, int num, char *subjuctname, int Snum, KMID *Sub)
 {
	//�������Ļ������	 
	if (num == 1)
		fprintf(stdout, "��%s�ɼ�����������ѧ����Ϣ:\n\n", subjuctname);
	else if (num == 2)
		fprintf(stdout, "��%s�ɼ�����������ѧ����Ϣ:\n\n", subjuctname);
	
	outputcaseS (p, Snum, Sub);
	
	return ;
 }
 
 //����ƽ���ɼ�������ʾ��Ϣ
void outputcase2_Average (char *filename, STU *p, int num, int Snum, KMID *Sub)
 {
	//�������Ļ������	 
	if (num == 3)
		fprintf(stdout, "��ƽ���ɼ�����������ѧ����Ϣ:\n\n");
	else if (num == 4)
		fprintf(stdout, "��ƽ���ɼ�����������ѧ����Ϣ:\n\n");
	
	outputcaseS (p, Snum, Sub);
	
	return ;
 }
  
//addѧ������е����ļ���� 
void outputcase4_File(char *filename, STU *p, int num, int Snum, KMID *Sub)
{
	//��write�ķ�ʽ�� 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase4 fopen(w) Error");
		return;
	}

	fprintf(fp,"#��Ӳ����ɹ���");

	fprintf(fp,"\n#Ŀǰ���ڵ�ѧ��������%d\n", num);

	//������ļ� 
	fprintf(fp, "#Ŀǰ����ѧ����ѧ����Ϣ��");
	
	outputcaseF (p, fp, Snum, Sub);

	fclose(fp);
	return ;
 }
 
 //addѧ���������� 
 void outputcase4(char *filename, STU *p, int num, int Snum, KMID *Sub)
{
	//��write�ķ�ʽ�� 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase4 fopen(w) Error");
		return;
	}
	
	printf("\n��Ӳ����ɹ�!\n");
	fprintf(fp,"#��Ӳ����ɹ���");
	
	printf("\nĿǰ���ڵ�ѧ��������%d\n\n", num);
	fprintf(fp,"\n#Ŀǰ���ڵ�ѧ��������%d\n", num);
	
	//�������Ļ 
	fprintf(stdout, "Ŀǰ����ѧ����ѧ����Ϣ��\n");
	
	//������ļ� 
	fprintf(fp, "#Ŀǰ����ѧ����ѧ����Ϣ��");
	
	outputcaseSF (p, fp, Snum, Sub);

	fclose(fp);
	return ;
 }

//�޸�ѧ����Ϣ����е����ļ���� 
void outputcase5_File(char *filename, STU *p, int Snum, KMID *Sub)
{
	//��write�ķ�ʽ�� 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase5_File fopen(w) Error");
		return;
	}
	
	fprintf(fp,"#�޸ĳɹ�!\n");
	//������ļ� 
	fprintf(fp, "#�޸ĺ��ѧ����Ϣ��");
	
	outputcaseF (p, fp, Snum, Sub);
	
	fclose(fp);
	return ;
}

//�޸�ѧ����Ϣ�������� 
void outputcase5(char *filename, STU *p, int Snum, KMID *Sub)
{
	//��write�ķ�ʽ�� 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase5 fopen(w) Error");
		return;
	}
	
	printf("\n�޸ĳɹ�!\n\n");
	fprintf(fp,"#�޸ĳɹ�!\n");
	
	//�������Ļ 
	fprintf(stdout, "�޸ĺ��ѧ����Ϣ��\n\n");
	
	//������ļ� 
	fprintf(fp, "#�޸ĺ��ѧ����Ϣ��");
	
	outputcaseSF (p, fp, Snum, Sub);
	
	fclose(fp);
	return ;
}

//ɾ��������ɺ���е������ļ���� 
void outputcase7_File(char *filename, STU *p, int num, int Snum, KMID *Sub)
{
	//��write�ķ�ʽ�� 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase7_File fopen(w) Error");
		return;
	}
	
	fprintf(fp,"#ɾ�������ɹ���");
	
	fprintf(fp,"\n#Ŀǰ���ڵ�ѧ��������%d\n", num);
	
	//������ļ� 
	fprintf(fp, "#����ѧ����ѧ����Ϣ��");
	
	outputcaseF (p, fp, Snum, Sub);
	
	fclose(fp);
	return;
 } 

//ɾ��������ɺ������� 
void outputcase7(char *filename, STU *p, int num, int Snum, KMID *Sub)
{
	//��write�ķ�ʽ�� 
 	FILE *fp = fopen(filename, "w");
 	if(fp == NULL)
	{
		printf("outputcase7 fopen(w) Error");
		return;
	}
	
	fprintf(fp,"#ɾ�������ɹ���");
	
	printf("\nĿǰ���ڵ�ѧ��������%d\n\n", num);
	fprintf(fp,"\n#Ŀǰ���ڵ�ѧ��������%d\n", num);
	
	//�������Ļ 
	fprintf(stdout, "����ѧ����ѧ����Ϣ��\n");
	
	//������ļ� 
	fprintf(fp, "#����ѧ����ѧ����Ϣ��");
	
	outputcaseSF (p, fp, Snum, Sub);
	
	fclose(fp);
	return;
 } 


