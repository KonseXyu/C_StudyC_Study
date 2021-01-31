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

//密码修改 
void PasswordChange(char *Passwordname); 

//学生信息读入 
STU *inputSTU(char *filename, int *num); 
 
//计算每个人的十次成绩平均值 
void average(STU *p, char *Subjectfilename);

//读入科目信息代码文件 
KMID *Subjectfile(char *filename, int *num);

//读入学院代码文件的信息
SCID *Scidfile (char *filename, int *num);

//将所有学生的性别id代码转换成对应的性别 
void sidname(char *filename, STU *p, int num);

//将所有学生的学院id代码转换成对应的学院信息 
void scidname(char *filename, STU *p, int num); 

//按名字排序子菜单 
STU *Menu_Name (STU *p, int *choose);

//排序降序名字（插入） 
STU *sortStunameDown (STU *head);

//排序升序名字（插入） 
STU *sortStunameUp (STU *head);

//按成绩排序子菜单 
STU *Menu_Score (STU *p, int *choose, int *back, char *KMidfilename, char *Outfilename, int Snum, KMID *Sub);

//科目升序排序子菜单 
STU *Subject_Up_Menu (STU *p, char *KMidfilename, char *Outfilename, int *back); 

//科目降序排序子菜单
STU *Subject_Down_Menu (STU *p, char *KMidfilename, char *Outfilename, int *back);

//排序降序科目（插入）
STU *Subject_Sort_Down(STU *head, int num);

//排序升序科目（插入） 
STU *Subject_Sort_Up(STU *head, int num);

//排序降序average（插入） 
STU *sortStuscoreDown (STU *head);

//排序升序average（插入） 
STU *sortStuscoreUp (STU *head);

//寻找指定学院子菜单 
void Menu_Scidfind (STU *p, int *choose, char *Scidfilename, char *Subjectfilename, int donum); 

//查找指定学院的学生信息
void searchScid (STU *p, char *scidname, char *Subjectfilename); 

//寻找学生信息子菜单 
void Menu_SearchStu (STU *p, char *Subjectfilename, int *choose); 

//查询给定学号的学生信息
void SearchID (char *Subjectfilename, STU *p);

//查询给定姓名的学生信息
void SearchName (char *Subjectfilename, STU *p);

//删除学生信息子菜单 
STU *Menu_Del (STU *p, int *choose, int *num, int *flg, int Snum, int *back); 

//删除学生信息 (通过ID） 
STU *delID(STU *p_head, int *num, int *flg, int Snum);

//删除给定名字 
STU *delName(STU *p_head, int *num, int *flg, int Snum);

//add学生子菜单 
STU *Menu_Add (STU *p, int *choose, int *num, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back);

//增加学生信息(表头) 
STU *addIdUp (STU *head, int *num, char *Sidfilename, char *Scidfilename, char *Subjectfilename);

//增加学生信息 （表尾） 
STU *addIdDown (STU *head, int *num, char *Sidfilename, char *Scidfilename, char *Subjectfilename);

//修改学生信息子菜单 
void Menu_Modify (STU *p, int *choose, int *flag, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back);

//按学号修改学生信息 
void ModifyID(STU *p, int *flag, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back);

//按名字修改学生信息 
void ModifyName(STU *p, int *flag, char *Sidfilename, char *Scidfilename, char *Subjectfilename, int *back);

//挂科信息子菜单 
void Menu_LowPoint (STU *p, int *choose, char *Scidfilename, char *Subjectfilename, int donum);

//输出每个挂科人的信息
void Lowpoint(STU *p, int *back);

//返回指定学院的挂科学生信息
void ScidLowpoint (STU *p, char *scidname);

//输出到屏幕 
void outputScreen (STU *p, int Snum, KMID Sub);

//输出到文件
void outputFile (FILE *fp, STU *p, int Snum, KMID *Sub);

//输出到屏幕单次模板 
void outputcaseS (STU *p, int Snum, KMID *Sub);

 //单独输出到文件的模板 
void outputcaseF (STU *p, FILE *fp, int Snum, KMID *Sub);

//输出到屏幕和文件单次模板 
void outputcaseSF (STU *p, FILE *fp, int Snum, KMID *Sub);

//按照姓名排序并显示信息 
void outputcase1 (char *filename, STU *p, int choose, int Snum, KMID *Sub);

//按照科目成绩排序并显示信息
void outputcase2_Subject (char *filename, STU *p, int num, char *subjuctname, int Snum, KMID *Sub);

 //按照平均成绩排序并显示信息
void outputcase2_Average (char *filename, STU *p, int num, int Snum, KMID *Sub); 

//add学生后进行单独文件输出 
void outputcase4_File(char *filename, STU *p, int num, int Snum, KMID *Sub);
 
//add学生后进行输出 
void outputcase4(char *filename, STU *p, int num, int Snum, KMID *Sub);
 
//修改学生信息后进行输出 
void outputcase5(char *filename, STU *p, int Snum, KMID *Sub); 

//修改学生信息后进行单独文件输出 
void outputcase5_File(char *filename, STU *p, int Snum, KMID *Sub);

//删除操作完成后进行输出 
void outputcase7(char *filename, STU *p, int num, int Snum, KMID *Sub);
