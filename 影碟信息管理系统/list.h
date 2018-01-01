#ifndef FILM_H
#include<stdio.h>
#define MAXN 105
/*Ӱ����Ϣ*/
typedef struct film    
{
	char name[MAXN];    //Ӱ������
	char national[MAXN];//����
	int  type;           //����
	int  quantity;        //����
	char dir[MAXN];     //����
	int  year;       //��ӳ���
}FILM;

/*�û���Ϣ*/
typedef struct user
{
	char account[MAXN];
	char password[MAXN];
	
}USER;

/*������Ϣ*/
typedef struct userfilm
{
	char account[MAXN];
	char name[MAXN];
	int year;
	int month;
	int day;
	struct userfilm* next;
}Userfilm;

/*��¼����*/
void Menu1();

/*�û����棺���ң����ģ��黹*/
void Menu2();

/*����Ա���棺Ӱ���޸ģ�¼��*/
void Menu3();

/*�û���¼�����������û���������*/
void Users_Login();

/*����Ա��¼����*/
void Admin_Login();

/*�û�����*/
void UI();

/*����Ա����*/
void AdminI();

/*ע���û���Ϣ*/
void Users_Regis();

/*�һ�����*/
void PassW_Retri(int);

/*���Ӱ����Ϣ*/
void Addfilm();

/*�������Ӱ����Ϣ*/
void Film_Infor();

/*����������Ӱ�����Ʋ�ѯ�йص�Ӱ*/
void Find_Film();

/*չ���û���Ϣ�����룬����Ӱ����*/
void User_Infor();

/*����Ӱ��*/
void Rent_Film();

/*�黹Ӱ��*/
void Return_Film();

/*�޸�Ӱ����Ϣ*/
void Alter_Film();

/*�Զ���getchar()����*/
char getchar_s();

#endif // !LIST_H

#pragma once
