#include <stdio.h>
#include "function.h"

int main()
{

	userLogin();

	stu_form();	
	
	
	STUINFO *pHead=(STUINFO *)malloc(sizeof(STUINFO));
	memset(pHead,0,sizeof(STUINFO));
	
	//加载学生信息
	
	pHead=loadStuInfo(pHead);
	
	char cNum='\0';
	while(1)
	{
		int iNum=stu_index();
		switch(iNum)
		{
		case 0:
			printf("你确定要退出系统吗(Y/N)?\n");
			fflush(stdin);
			cNum=getchar();
			if(cNum=='Y'||cNum=='y')
				exit(0);
			else
			{
				system("cls");
				break;
			}
			
			
		case 1:
			printf("添加学生信息\n");
			stu_Info_Create(pHead);
			system("pause");
			system("cls");
			
			break;
		case 2:
			{	
				int iChoose=stuChildMenu();
				int sNum=0;
				switch(iChoose)
				{
				case 0:
					break;
				case 1:
					printf("按学号查找学生信息\n");
					printf("请输入想要查询的学号：");
					scanf("%d",&sNum);
					fflush(stdin);
					selectInfoByNum(pHead,sNum);
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					printf("所有学生信息\n");
					selectInfoByAll(pHead);
					break;
				}
				
				system("pause");
				system("cls");
				break;
			}
			
		case 3:
			{
				int sNum;
				printf("修改学生信息\n");
				printf("请输入你想要修改学生信息的学号:");
				fflush(stdin);
				scanf("%d",&sNum);
				if(stu_Info_Alter(pHead,sNum)==-1)
				{
					printf("修改失败!");
				}
				else
				{
					printf("修改成功!");
				}
				system("pause");
				system("cls");		
				break;
			}			
		case 4:
			{
				int sNum;
				printf("删除学生信息\n");
				printf("请输入你想要删除学生信息的学号:");
				scanf("%d",&sNum);
				if(stu_Info_Delete(pHead,sNum)==-1)
				{
					printf("删除失败!\n");
				}
				else
				{
					printf("删除成功!");
				}
				system("pause");
				system("cls");
				break;
			}			
		}
	}
	return 0;
}