#include "function.h"

void stu_form()
{
	printf("************************************************\n");
	printf("****                                        ****\n");
	printf("****            ѧ����Ϣ����ϵͳ            ****\n");
	printf("****                                        ****\n");
	printf("************************************************\n");
}

int stu_index()
{
	
	int iNum=-1;
	while(iNum<0||iNum>4)
	{
		printf("1.���ѧ����Ϣ\n");
		printf("2.����ѧ����Ϣ\n");
		printf("3.�޸�ѧ����Ϣ\n");
		printf("4.ɾ��ѧ����Ϣ\n");
		printf("0.�˳�ϵͳ\n");	
		printf("����������ѡ��");
		scanf("%d", &iNum);
		fflush(stdin);
		system("cls");
	}
	return iNum;
}

