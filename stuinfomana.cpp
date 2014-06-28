#include "function.h"

//添加学生信息
void stu_Info_Create(STUINFO *pHead)
{
	STUINFO *pCurrent=pHead;
	while(pCurrent->pNext!=NULL)
	{
		pCurrent=pCurrent->pNext;
	}

	int i=0;
	
	while(1)
	{
		i++;
		//1.开辟空间
		STUINFO *pNewStu=(STUINFO *)malloc(sizeof(STUINFO));
		memset(pNewStu,0,sizeof(STUINFO));

		//2.填充数据域
		printf("请输入第%d个学生的信息：\n",i);
		printf("  请输入学号(0表示退出):");
		scanf("%d",&pNewStu->sNum);
		fflush(stdin);
		if(pNewStu->sNum==0)//退出
		{	
			free(pNewStu);
			system("cls");
			break;
		}
		printf("\n");

		printf("  请输入姓名：\t\t");
		scanf("%s",pNewStu->sName);
		fflush(stdin);
		printf("\n");
		
		printf("  请输入性别：\t\t");
		scanf("%s",pNewStu->sSex);
		fflush(stdin);
		printf("\n");
		
		printf("  请输入年龄：\t\t");
		scanf("%d",&pNewStu->sAge);
		fflush(stdin);
		printf("\n");
		
		printf("  请输入班级：\t\t");
		scanf("%s",pNewStu->sClass);
		fflush(stdin);
		printf("\n");
		
		printf("  请输入成绩：\t\t");
		scanf("%f",&pNewStu->sScore);
		fflush(stdin);
		printf("\n");
		
		//填充指针域
		pCurrent->pNext=pNewStu;
		pCurrent=pNewStu;
		pCurrent->pNext=NULL;		
	}
	saveStuInfo(pHead);
}

//按学号查询学生信息
void selectInfoByNum(STUINFO *pHead,int sNum)
{
	if(pHead->pNext==NULL)
	{
		printf("一个学生都没有!");
		return ;//没有找到
	}
	
	STUINFO *pCurrent=pHead->pNext;
	while(pCurrent!=NULL)
	{	
		if(pCurrent->sNum==sNum)
		{	
			printf("\t学号\t姓名\t性别\t年龄\t班级\t成绩\t\n\n");
			printf("--------------------------------------------------------\n");
			printf("\t%d\t%s\t%s\t%d\t%s\t%.2f\n",pCurrent->sNum,pCurrent->sName,pCurrent->sSex,pCurrent->sAge,pCurrent->sClass,pCurrent->sScore);
			printf("--------------------------------------------------------\n");
			return ;
		}
		pCurrent=pCurrent->pNext;
	}

	printf("没有找到该学号的相关信息!");
	return ;
}

//查找所有学生信息
void selectInfoByAll(STUINFO *pHead)
{
	if(pHead->pNext==NULL)
	{
		printf("一个学生都没有!");
		return ;//没有找到
	}

	printf("\t学号\t姓名\t性别\t年龄\t班级\t成绩\t\n\n");
	printf("--------------------------------------------------------\n");
	STUINFO *pCurrent=pHead->pNext;
	while(pCurrent!=NULL)
	{				
		
		printf("\t%d\t%s\t%s\t%d\t%s\t%.2f\n",pCurrent->sNum,pCurrent->sName,pCurrent->sSex,pCurrent->sAge,pCurrent->sClass,pCurrent->sScore);				
		pCurrent=pCurrent->pNext;
	}
	printf("--------------------------------------------------------\n");

}



//删除学生信息
int stu_Info_Delete(STUINFO *pHead,int sNum)
{
	//1.没有记录
	if(pHead->pNext==NULL)
	{
		printf("没有找到该学生信息!");
		return -1;
	}
	//2.删除的是第一个学生的信息
	if(pHead->pNext->sNum==sNum)
	{
		STUINFO *pTemp=pHead->pNext;
		pHead->pNext=pHead->pNext->pNext;
		free(pTemp);
		saveStuInfo(pHead);
		return 0;
	}
	//3.删除的是中间或最后一个学生的信息
	STUINFO *pCurrent=pHead->pNext;
	STUINFO *pPrev=pHead;
	while(pCurrent!=NULL)
	{
		if(pCurrent->sNum==sNum)
		{
			STUINFO *pTemp=pCurrent->pNext;
			pPrev->pNext=pCurrent->pNext;
			free(pTemp);
			saveStuInfo(pHead);
			return 0;
		}
		else
		{
			pPrev = pCurrent;
			pCurrent = pCurrent->pNext;
		}
	}
	return -1;
}


