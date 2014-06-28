#include "function.h"

STUINFO *loadStuInfo(STUINFO *pHead)
{
	STUINFO *pCurrent=pHead->pNext;

	//加载学生信息
	FILE *fp=fopen("userdata.dat","rb");
	if(fp==NULL)
	{
		fp=fopen("userdata.dat","wb");
	}
		
	while(!feof(fp))
	{	
		STUINFO *pNewStu=(STUINFO *)malloc(sizeof(STUINFO));
		memset(pNewStu,0,sizeof(STUINFO));

		fread(pNewStu,sizeof(STUINFO),1,fp);
		
		if(pNewStu->sNum==0)
		{
			break;
		}
		if(pHead->pNext==NULL)
		{
			pHead->pNext=pNewStu;
			pCurrent=pNewStu;
			pCurrent->pNext=NULL;
		}
		else
		{
			pCurrent->pNext=pNewStu;
			pCurrent=pNewStu;
			pCurrent->pNext=NULL;
		}		
	}
	fclose(fp);
	return pHead;
}

