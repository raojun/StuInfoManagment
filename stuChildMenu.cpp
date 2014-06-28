#include "function.h"

int stuChildMenu()
{
	int iChoose=-1;
	while(iChoose<0||iChoose>5)
	{
		printf("查找学生信\n");
		printf("0.返回上级菜单\n");
		printf("1.按学号查找学生信息\n");	
		printf("2.按姓名查找学生信息\n");
		printf("3.按性别查找学生信息\n");
		printf("4.按班级查找学生信息\n");
		printf("5.查找所有学生信息\n");
		printf("请输入你的查询方式(0-5)");
		scanf("%d",&iChoose);
		fflush(stdin);
		system("cls");
	}
	return iChoose;
}