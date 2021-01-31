#include "head_tool.h" 

//加密系统 
void EncryptingPassword(char *p)
{
	//加密方式：数字加3,小写字母变大写，大写字母减3  
	while(*p != '\0')
	{
		if(strcmp(p,"/") > 0 && strcmp(p,":") < 0)
		{
			(*p) += 3;	
		}
		else if(strcmp(p,"`") > 0 && strcmp(p,"{") < 0)
		{
			(*p) -= 32;	
		} 
		else if(strcmp(p,"@") > 0 && strcmp(p,"[") < 0)
		{
			(*p) -= 3;	
		} 
		p++;	
	}
}
