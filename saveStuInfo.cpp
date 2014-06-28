#include "function.h"

void saveStuInfo(STUINFO *pHead)
{
	
	FILE *fp=fopen("userdata.dat","wb");
	
	if(fp==NULL)
	{
		exit(0);
	}
	
	if(pHead->pNext==NULL)
	{
		//printf("û���κ�����!");
		return ;
	}

	STUINFO *pCurrent=pHead->pNext;
	while(pCurrent!=NULL)
	{
		fwrite(pCurrent,sizeof(STUINFO),1,fp);
		pCurrent=pCurrent->pNext;
	}
	fclose(fp);
}