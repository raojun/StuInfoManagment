#include "function.h"

//���ѧ����Ϣ
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
		//1.���ٿռ�
		STUINFO *pNewStu=(STUINFO *)malloc(sizeof(STUINFO));
		memset(pNewStu,0,sizeof(STUINFO));

		//2.���������
		printf("�������%d��ѧ������Ϣ��\n",i);
		printf("  ������ѧ��(0��ʾ�˳�):");
		scanf("%d",&pNewStu->sNum);
		fflush(stdin);
		if(pNewStu->sNum==0)//�˳�
		{	
			free(pNewStu);
			system("cls");
			break;
		}
		printf("\n");

		printf("  ������������\t\t");
		scanf("%s",pNewStu->sName);
		fflush(stdin);
		printf("\n");
		
		printf("  �������Ա�\t\t");
		scanf("%s",pNewStu->sSex);
		fflush(stdin);
		printf("\n");
		
		printf("  ���������䣺\t\t");
		scanf("%d",&pNewStu->sAge);
		fflush(stdin);
		printf("\n");
		
		printf("  ������༶��\t\t");
		scanf("%s",pNewStu->sClass);
		fflush(stdin);
		printf("\n");
		
		printf("  ������ɼ���\t\t");
		scanf("%f",&pNewStu->sScore);
		fflush(stdin);
		printf("\n");
		
		//���ָ����
		pCurrent->pNext=pNewStu;
		pCurrent=pNewStu;
		pCurrent->pNext=NULL;		
	}
	saveStuInfo(pHead);
}

//��ѧ�Ų�ѯѧ����Ϣ
void selectInfoByNum(STUINFO *pHead,int sNum)
{
	if(pHead->pNext==NULL)
	{
		printf("һ��ѧ����û��!");
		return ;//û���ҵ�
	}
	
	STUINFO *pCurrent=pHead->pNext;
	while(pCurrent!=NULL)
	{	
		if(pCurrent->sNum==sNum)
		{	
			printf("\tѧ��\t����\t�Ա�\t����\t�༶\t�ɼ�\t\n\n");
			printf("--------------------------------------------------------\n");
			printf("\t%d\t%s\t%s\t%d\t%s\t%.2f\n",pCurrent->sNum,pCurrent->sName,pCurrent->sSex,pCurrent->sAge,pCurrent->sClass,pCurrent->sScore);
			printf("--------------------------------------------------------\n");
			return ;
		}
		pCurrent=pCurrent->pNext;
	}

	printf("û���ҵ���ѧ�ŵ������Ϣ!");
	return ;
}

//��������ѧ����Ϣ
void selectInfoByAll(STUINFO *pHead)
{
	if(pHead->pNext==NULL)
	{
		printf("һ��ѧ����û��!");
		return ;//û���ҵ�
	}

	printf("\tѧ��\t����\t�Ա�\t����\t�༶\t�ɼ�\t\n\n");
	printf("--------------------------------------------------------\n");
	STUINFO *pCurrent=pHead->pNext;
	while(pCurrent!=NULL)
	{				
		
		printf("\t%d\t%s\t%s\t%d\t%s\t%.2f\n",pCurrent->sNum,pCurrent->sName,pCurrent->sSex,pCurrent->sAge,pCurrent->sClass,pCurrent->sScore);				
		pCurrent=pCurrent->pNext;
	}
	printf("--------------------------------------------------------\n");

}



//ɾ��ѧ����Ϣ
int stu_Info_Delete(STUINFO *pHead,int sNum)
{
	//1.û�м�¼
	if(pHead->pNext==NULL)
	{
		printf("û���ҵ���ѧ����Ϣ!");
		return -1;
	}
	//2.ɾ�����ǵ�һ��ѧ������Ϣ
	if(pHead->pNext->sNum==sNum)
	{
		STUINFO *pTemp=pHead->pNext;
		pHead->pNext=pHead->pNext->pNext;
		free(pTemp);
		saveStuInfo(pHead);
		return 0;
	}
	//3.ɾ�������м�����һ��ѧ������Ϣ
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


