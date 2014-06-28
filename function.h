#ifndef __INDEX__H__
#define __INDEX__H__

//ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


//�궨��
#define BACKSPACE  8
#define BELL    7

//�������Ͷ���
typedef struct tagSTUINFO
{
	//������
	int sNum;		//ѧ��	4
	char sName[8];	//����	8
	char sSex[2];	//�Ա�	2
	int sAge;		//����	4
	char sClass[20];//�༶	20
	float sScore;	//�ɼ�	4
	
	
	//ָ����
	tagSTUINFO *pNext;	
}STUINFO;


//��������
int userLogin();//��¼

void stu_form();
int stu_index();
void stu_management();

void stu_Info_Create(STUINFO *pHead);
void selectInfoByNum(STUINFO *pHead,int sNum);
void selectInfoByAll(STUINFO *pHead);
int stu_Info_Alter(STUINFO *pHead,int sNum);
int stu_Info_Delete(STUINFO *pHead,int sNum);
char* getString(char *sz,int iLen);
int getInt(int iAge);
float getFloat(float sScore);

int stuChildMenu();

STUINFO *loadStuInfo(STUINFO *pHead);
void saveStuInfo(STUINFO *pHead);


#endif