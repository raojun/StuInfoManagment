#include "function.h"

void stu_form()
{
	printf("************************************************\n");
	printf("****                                        ****\n");
	printf("****            学生信息管理系统            ****\n");
	printf("****                                        ****\n");
	printf("************************************************\n");
}

int stu_index()
{
	
	int iNum=-1;
	while(iNum<0||iNum>4)
	{
		printf("1.添加学生信息\n");
		printf("2.查找学生信息\n");
		printf("3.修改学生信息\n");
		printf("4.删除学生信息\n");
		printf("0.退出系统\n");	
		printf("请输入您的选择：");
		scanf("%d", &iNum);
		fflush(stdin);
		system("cls");
	}
	return iNum;
}

