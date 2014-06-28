#include "function.h"



//�޸�ѧ����Ϣ
int stu_Info_Alter(STUINFO *pHead,int sNum)
{
	if(pHead->pNext==NULL)
	{
		printf("û�и�����Ϣ!");
		return -1;
	}
	
	STUINFO *pCurrent=pHead->pNext;

	while(pCurrent!=NULL)
	{
		if(pCurrent->sNum==sNum)
		{
			printf("�޸�ѧ��Ϊ%d��ѧ����Ϣ\n",pCurrent->sNum);
			printf("����:");
			strcpy(pCurrent->sName,getString(pCurrent->sName,16));
			printf("\n");

			printf("�Ա�:");
			strcpy(pCurrent->sSex,getString(pCurrent->sSex,8));
			printf("\n");

			printf("����:");
			pCurrent->sAge=getInt(pCurrent->sAge);
			printf("\n");

			printf("�༶:");
			strcpy(pCurrent->sClass,getString(pCurrent->sClass,20));
			printf("\n");

			printf("�ɼ�:");
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
		printf("û���ҵ�Ҫ�޸�ѧ����ѧ��!\n");
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
	printf("%s",pBuf);//��ӡԭ��Ϣ

	int i=strlen(pBuf);
	char ch='\0';
	while((ch=getch())!='\r'&&i<iLen)
	{
		if(ch==BACKSPACE)//�˸�
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