#include <stdio.h>
#include "function.h"

int main()
{

	userLogin();

	stu_form();	
	
	
	STUINFO *pHead=(STUINFO *)malloc(sizeof(STUINFO));
	memset(pHead,0,sizeof(STUINFO));
	
	//����ѧ����Ϣ
	
	pHead=loadStuInfo(pHead);
	
	char cNum='\0';
	while(1)
	{
		int iNum=stu_index();
		switch(iNum)
		{
		case 0:
			printf("��ȷ��Ҫ�˳�ϵͳ��(Y/N)?\n");
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
			printf("���ѧ����Ϣ\n");
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
					printf("��ѧ�Ų���ѧ����Ϣ\n");
					printf("��������Ҫ��ѯ��ѧ�ţ�");
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
					printf("����ѧ����Ϣ\n");
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
				printf("�޸�ѧ����Ϣ\n");
				printf("����������Ҫ�޸�ѧ����Ϣ��ѧ��:");
				fflush(stdin);
				scanf("%d",&sNum);
				if(stu_Info_Alter(pHead,sNum)==-1)
				{
					printf("�޸�ʧ��!");
				}
				else
				{
					printf("�޸ĳɹ�!");
				}
				system("pause");
				system("cls");		
				break;
			}			
		case 4:
			{
				int sNum;
				printf("ɾ��ѧ����Ϣ\n");
				printf("����������Ҫɾ��ѧ����Ϣ��ѧ��:");
				scanf("%d",&sNum);
				if(stu_Info_Delete(pHead,sNum)==-1)
				{
					printf("ɾ��ʧ��!\n");
				}
				else
				{
					printf("ɾ���ɹ�!");
				}
				system("pause");
				system("cls");
				break;
			}			
		}
	}
	return 0;
}