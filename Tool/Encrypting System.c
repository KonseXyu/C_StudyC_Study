#include "head_tool.h" 

//����ϵͳ 
void EncryptingPassword(char *p)
{
	//���ܷ�ʽ�����ּ�3,Сд��ĸ���д����д��ĸ��3  
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
