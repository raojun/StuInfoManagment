#ifndef __INDEX__H__
#define __INDEX__H__

//头文件
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


//宏定义
#define BACKSPACE  8
#define BELL    7

//数据类型定义
typedef struct tagSTUINFO
{
	//数据域
	int sNum;		//学号	4
	char sName[8];	//姓名	8
	char sSex[2];	//性别	2
	int sAge;		//年龄	4
	char sClass[20];//班级	20
	float sScore;	//成绩	4
	
	
	//指针域
	tagSTUINFO *pNext;	
}STUINFO;


//函数声明
int userLogin();//登录

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