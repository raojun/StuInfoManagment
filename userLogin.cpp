#include "function.h"

//���봦��
int doPasswd(char szUserName[8],char szPasswd[8])
{
	printf("\n\n\n\n");
	printf("\t\t��ӭ����ѧ����Ϣ����ϵͳ���������û���������\n\n\n");
	printf("\t\t\t    �û�����");
	fflush(stdin);
	scanf("%s",szUserName);	
	printf("\n");
	if(sizeof(szUserName)>8)
	{
		printf("\t\t�û�������,���������룺");
		memset(szUserName,0,sizeof(szUserName));
		scanf("%s",szUserName);
	}
	
	printf("\t\t\t    ��  �룺");
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

//�û�У��
int userCheck(char szUserName[8],char szPasswd[8])
{
	int iCount=0;//У�����
	int iLogin=0;//����Ƿ��¼�ɹ�

	while(iCount<3)
	{	
		iCount++;	

		//���ļ�
		FILE *fp=fopen("user.txt","r");
		if(fp==NULL)
		{
			printf("�ļ���ʧ��!");
			exit(-1);
		}		
		
		doPasswd(szUserName,szPasswd);

		//�ļ���ȡ
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
			printf("�û��������������������������!\n");
			system("pause");
			system("cls");
			fclose(fp);
			continue;
		}

		if(iCount==3&&iLogin==0)
		{
			system("cls");
			printf("����������������˳�ϵͳ!\n");
			system("pause");
			system("cls");
			fclose(fp);
			exit(-1);
		}
		if(iLogin==1)
		{
			system("cls"); 			

			printf("��¼�ɹ�����ӭʹ��ѧ����Ϣ����ϵͳ!\n");		 	
			system("pause");
			system("cls");

			//�ļ��ر�
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