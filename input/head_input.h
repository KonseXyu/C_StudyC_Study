#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 1024

//ѧ����Ϣ
typedef struct student
{
	//ѧ�� �Ա� ѧԺ���� ���� 10�Ƴɼ� ƽ���� 
	long long int  id;
	char sid[L], scid[L];
	char name[L];
	int s[10];
	float ave ;
	struct student *next;
}STU; 

//�Ա����
typedef struct STUsid
{
	//�Ա���� 
	char nm[L];
	//�Ա�����Ӧ�Ա� 
	char s[L];
}SID;

//ѧԺ���� 
typedef struct STUscid
{
	//ѧԺ����
	char nm[L];
	//ѧԺ�����Ӧ�Ա� 
	char s[L];
}SCID;

//��Ŀ��Ϣ
typedef struct KMID
{
	//��Ŀ����
	char nm[L];
	//��Ŀ�����Ӧ�Ա� 
	char s[L];
}KMID;

//�����Ŀ��Ϣ�����ļ� 
KMID *Subjectfile(char *filename, int *num);
