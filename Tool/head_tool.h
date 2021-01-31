#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 1024

//学生信息
typedef struct student
{
	//学号 性别 学院代码 名字 10科成绩 平均分 
	long long int  id;
	char sid[L], scid[L];
	char name[L];
	int s[10];
	float ave ;
	struct student *next;
}STU; 

//科目信息
typedef struct KMID
{
	//科目代码
	char nm[L];
	//科目代码对应性别 
	char s[L];
}KMID;

//读入科目信息代码文件 
KMID *Subjectfile(char *filename, int *num);
