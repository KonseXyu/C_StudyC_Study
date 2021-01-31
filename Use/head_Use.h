#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define L 1024

//学生信息
typedef struct student
{
	//学号 性别 学院代码 名字 10科成绩 平均分 
	long long int id;
	char sid[L], scid[L];
	char name[L];
	int s[10];
	float ave ;
	struct student *next;
}STU; 

//性别代码
typedef struct STUsid
{
	//性别代码 
	char nm[L];
	//性别代码对应性别 
	char s[L];
}SID;

//学院代码 
typedef struct STUscid
{
	//学院代码
	char nm[L];
	//学院代码对应性别 
	char s[L];
}SCID;

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

//计算单人的十次成绩平均值 
void averageOne(STU *p, char *Subjectfilename);
 
//将单个人的学院id代码转换成对应的学院信息 
void scidnameOne(char *filename, STU *p);

//将一个人的性别的id代码转换成对应的性别 
void sidnameOne(char *filename, STU *p); 

//输出到屏幕 
void outputScreen (STU *p, int Snum, KMID *Sub);
