#include "function.h"

int stuChildMenu()
{
	int iChoose=-1;
	while(iChoose<0||iChoose>5)
	{
		printf("����ѧ����\n");
		printf("0.�����ϼ��˵�\n");
		printf("1.��ѧ�Ų���ѧ����Ϣ\n");	
		printf("2.����������ѧ����Ϣ\n");
		printf("3.���Ա����ѧ����Ϣ\n");
		printf("4.���༶����ѧ����Ϣ\n");
		printf("5.��������ѧ����Ϣ\n");
		printf("��������Ĳ�ѯ��ʽ(0-5)");
		scanf("%d",&iChoose);
		fflush(stdin);
		system("cls");
	}
	return iChoose;
}