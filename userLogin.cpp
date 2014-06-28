#include "function.h"

//密码处理
int doPasswd(char szUserName[8],char szPasswd[8])
{
	printf("\n\n\n\n");
	printf("\t\t欢迎来到学生信息管理系统，请输入用户名和密码\n\n\n");
	printf("\t\t\t    用户名：");
	fflush(stdin);
	scanf("%s",szUserName);	
	printf("\n");
	if(sizeof(szUserName)>8)
	{
		printf("\t\t用户名过长,请重新输入：");
		memset(szUserName,0,sizeof(szUserName));
		scanf("%s",szUserName);
	}
	
	printf("\t\t\t    密  码：");
	fflush(stdin);
	
	int i=0;
	char ch='\0';
	while((ch=getch())!='\r'&&i<8)
	{
		if(ch==BACKSPACE)
		{
			if(i>0)
			{
				szPasswd[--i]='\0';
				putchar('\b');
				putchar(' ');
				putchar('\b');
			}
			else
			{
				putchar(BELL);
			}
		}
		else
		{
			printf("*");
			szPasswd[i] = ch;
			i++;
		}
	}
	szPasswd[i] = '\0';
	printf("\n");
	system("cls");
	
	return 0;
}

//用户校验
int userCheck(char szUserName[8],char szPasswd[8])
{
	int iCount=0;//校验次数
	int iLogin=0;//标记是否登录成功

	while(iCount<3)
	{	
		iCount++;	

		//打开文件
		FILE *fp=fopen("user.txt","r");
		if(fp==NULL)
		{
			printf("文件打开失败!");
			exit(-1);
		}		
		
		doPasswd(szUserName,szPasswd);

		//文件读取
		while(!feof(fp))
		{
			char szU[8]={'\0'};
			char szP[8]={'\0'};
			
			fscanf(fp,"%s%s",szU,szP);
			if(strcmp(szU,szUserName) == 0 && strcmp(szP,szPasswd) == 0 )
			{
				iLogin=1;
				break;
			}
		}

		if( iCount<3 && iLogin==0 )
		{
			
			system("cls");
			printf("用户名或密码输入错误，请重新输入!\n");
			system("pause");
			system("cls");
			fclose(fp);
			continue;
		}

		if(iCount==3&&iLogin==0)
		{
			system("cls");
			printf("您已三次输入错误，退出系统!\n");
			system("pause");
			system("cls");
			fclose(fp);
			exit(-1);
		}
		if(iLogin==1)
		{
			system("cls"); 			

			printf("登录成功，欢迎使用学生信息管理系统!\n");		 	
			system("pause");
			system("cls");

			//文件关闭
			fclose(fp);
			break;
		}	
	}

	return 0;
}

int userLogin()
{
	char szUserName[8]={'\0'};
	char szPasswd[8]={'\0'};

	userCheck(szUserName,szPasswd);
	return -1;
}