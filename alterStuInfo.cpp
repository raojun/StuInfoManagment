#include "function.h"



//修改学生信息
int stu_Info_Alter(STUINFO *pHead,int sNum)
{
	if(pHead->pNext==NULL)
	{
		printf("没有该条信息!");
		return -1;
	}
	
	STUINFO *pCurrent=pHead->pNext;

	while(pCurrent!=NULL)
	{
		if(pCurrent->sNum==sNum)
		{
			printf("修改学号为%d的学生信息\n",pCurrent->sNum);
			printf("姓名:");
			strcpy(pCurrent->sName,getString(pCurrent->sName,16));
			printf("\n");

			printf("性别:");
			strcpy(pCurrent->sSex,getString(pCurrent->sSex,8));
			printf("\n");

			printf("年龄:");
			pCurrent->sAge=getInt(pCurrent->sAge);
			printf("\n");

			printf("班级:");
			strcpy(pCurrent->sClass,getString(pCurrent->sClass,20));
			printf("\n");

			printf("成绩:");
			pCurrent->sScore=getFloat(pCurrent->sScore);
			printf("\n");
			break;
		}
		else
		{
			pCurrent=pCurrent->pNext;
		}
	}
	if(pCurrent==NULL)
	{
		printf("没有找到要修改学生的学号!\n");
		return -1;
	}
	else
	{
		saveStuInfo(pHead);
		return 0;
	}
}

char* getString(char *sz,int iLen)
{
	char *pBuf=new char[iLen];
	sprintf(pBuf,"%s",sz);
	printf("%s",pBuf);//打印原信息

	int i=strlen(pBuf);
	char ch='\0';
	while((ch=getch())!='\r'&&i<iLen)
	{
		if(ch==BACKSPACE)//退格
		{
			if(i>0)
			{
				pBuf[--i]='\0';
				putchar(BACKSPACE);
				putchar(' ');
				putchar(BACKSPACE);
			}
			else
			{
				putchar(BELL);
			}
		}
		else
		{
			pBuf[i++]=ch;
			putchar(ch);
		}
	}

	pBuf[i]='\0';
	return pBuf;
}

int getInt(int iAge)
{
	char *pBuf=new char[5];
	sprintf(pBuf,"%d",iAge);
	printf("%s",pBuf);
	
	int i=strlen(pBuf);
	char ch='\0';
	while((ch=getch())!='\r'&&i<5)
	{
		if(ch==BACKSPACE)
		{
			if(i>0)
			{
				pBuf[--i]='\0';
				putchar(BACKSPACE);
				putchar(' ');
				putchar(BACKSPACE);
			}
			else
			{
				putchar(BELL);
			}
		}
		else
		{
			pBuf[i++]=ch;
			putchar(ch);
		}
	}
	
	pBuf[i]='\0';
	return atoi(pBuf);
}

float getFloat(float sScore)
{
	char *pBuf=new char[10];
	sprintf(pBuf,"%.2f",sScore);
	printf("%s",pBuf);
	
	int i=strlen(pBuf);
	char ch='\0';
	while((ch=getch())!='\r'&&i<10)
	{
		if(ch==BACKSPACE)
		{
			if(i>0)
			{
				pBuf[--i]='\0';
				putchar(BACKSPACE);
				putchar(' ');
				putchar(BACKSPACE);
			}
			else
			{
				putchar(BELL);
			}
		}
		else
		{
			pBuf[i++]=ch;
			putchar(ch);
		}
	}
	
	pBuf[i]='\0';
	return (float)atof(pBuf);
}