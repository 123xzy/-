#ifndef FILM_H
#include<stdio.h>
#define MAXN 105
typedef struct film    /*Ӱ����Ϣ*/
{
	char name[MAXN];    //Ӱ������
	char national[MAXN];//����
	int  type;           //����
	int  account;        //����
	char dir[MAXN];     //����
	int  year;       //��ӳ���
}FILM;

typedef struct user
{
	char account[MAXN];
	char password[MAXN];
	
}USER;

;

/*��¼���棺��ʾ�û���¼��Ӱ���޸ģ��˳�ϵͳ*/
void menu1();

/*�û����棺��ʾ���ң����ģ��黹���˳�*/
void menu2();

/*��Ա��¼�����������û���������*/
void user_login();

/*�û�*/
void main_user();

/*ע���û���Ϣ*/
void user_register();

/*�һ�����*/
void find_password(char*,int);

/*���Ӱ����Ϣ*/
void Addfilm();

/*�������Ӱ����Ϣ*/
void show();

/*����������ͼ�����Ʋ�ѯ�йص�Ӱ*/
void find();

/*չ���û���Ϣ�����룬����ͼ�飩*/
void show_user();

/*����*/
void rent();

/*����*/
void back();

/*�޸�Ӱ����Ϣ*/
void alter();

/*ɾ��Ӱ��,��������*/
void del();

/*�Զ���getchar()����*/
char getchar_s();

#endif // !LIST_H

#pragma once
