#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include "list.h"
#define KEY 1999  
/*�Ƿ�ѭ��*/
static bool judge();

void menu1()
{
	printf("********Ӱ������ϵͳ********\n");
	printf("       1.��Ա��¼\n");
	printf("       2.��Աע��\n");
	printf("       3.Ӱ������\n");
	printf("       4.Ӱ����Ϣ�޸�\n");
	printf("       5.Ӱ����Ϣ���\n");
	printf("       6.Ӱ����Ϣ¼��\n");
	printf("       7.�˳�ϵͳ\n");
	printf("***************************\n");
	printf("��ѡ��1-7����");
}
void menu2()
{
	printf("*********��Ա����**********\n");
	printf("      1.��ѯ�˻���Ϣ\n");
	printf("      2.����\n");
	printf("      3.�黹\n");
	printf("      4.�˳���Ա����\n");
	printf("****************************\n");
	printf("��ѡ��1-4����");
}
void user_login()
{
	int flag=1;
	int count = 0;
	FILE *fp;
	int num, i;
	fp = fopen("user_date.txt", "r");
	USER user[MAXN];
	for (num = 0; !feof(fp); num++)
		fscanf(fp, "%s%s", user[num].account, user[num].password);
	fclose(fp);
	USER olduser;
	while (flag)
	{
		printf("�˻���");
		gets_s(olduser.account);
		for (i = 0; i < num; i++)
			if (!strcmp(olduser.account, user[i].account))
			{
				flag = 0; break;
			}
		if (i == num) {
			printf("���˻������ڣ��Ƿ�ע�����û���Y/N����");
			if (judge())
			{
				user_register(); return;
			}
		}
	}
	printf("���룺");
	for (;;) {
		gets_s(olduser.password);
		if (!strcmp(olduser.password, user[i].password))
		{
			printf("���ڵ�½...");
			Sleep(600); 
			return;
		}
		else
		{
			count++;
			if (count >= 3) 
			{ 
				printf("�Ƿ��һ����루Y/N)��");
				if (judge())
				{find_password(olduser.account, i); return;}
			}
			else 
			{
				printf("�˻����������\n");
				printf("�������������룺");
			}
		}
	}	
	
}
void main_user()
{
	char choice;
	int flag = 1;
	while (flag) {
		system("cls");
		menu2();
		choice= getchar_s();
		while (choice > '5' || choice < '1')
		{
			printf("��������ȷ��ѡ��:");
			choice = getchar_s();
		}
		switch (choice)
		{
		case'1':show_user(); break;
		case'2':rent(); break;
		case'3':back(); break;
		case'4':flag = 0; break;
		}
	}
}
void user_register()
{
	USER user[MAXN];
	FILE *fp;
	int flag=1;
	fp = fopen("user_date.txt", "r+");
	USER new_user;
	int num;
	for (num = 0;!feof(fp); num++)
		fscanf(fp, "%s%s", user[num].account, user[num].password);
	printf("�����µ��û�����");
	while(flag) {
		scanf("%s", new_user.account);
		for (int i = 0; i < num; i++)
		{
			if (!strcmp(new_user.account, user[i].account))
			{
				printf("���û����Ѿ����ڣ����������룡"); break;
			}
			else flag = 0;
		}
	}
	printf("�����µ����룺");
	scanf("%s", new_user.password);
	getchar();
	printf("ȷ��ע�ᣨY/N����");
	if (judge())
	{
		fprintf(fp, "%s %s\n", new_user.account, new_user.password);
		fclose(fp);
		printf("ע��ɹ���"); printf("������ת..."); Sleep(700);
	}
	else printf("ע��ʧ�ܣ�");
}
void find_password(char* olduser,int i)
{
	int code;
	FILE* fp;
	char new_password1[MAXN];
	char new_password2[MAXN];
	int num;
	fp = fopen("user_date.txt", "r+");
	USER user[MAXN];
	for (num = 0; !feof(fp); num++)
		fscanf(fp, "%s%s", user[num].account, user[num].password);
	printf("��������֤�룺");
	scanf("%d", &code);
	while (code != KEY) { scanf("%d", &code); printf("��֤�����"); }
	printf("�������µ����룺");
	scanf("%s", new_password1);
	printf("������һ�������룺");
	scanf("%s", new_password2);
	if (strcmp(new_password1,new_password2))printf("�������벻ͬ�����������룺");
	else strcpy(user[i].password , new_password1);
	rewind(fp);
	for (int j = 0; j < num; j++)
		fprintf(fp, "%s %s\n", user[j].account, user[j].password);
	fclose(fp);
	printf("�޸�����ɹ���������ת...");
	Sleep(500);
	return;
}
void Addfilm()
{
	FILM newfilm;
	FILE *fp;
	for (;;)
	{
		printf("������Ӱ�����ƣ�");
		scanf("%s", newfilm.name);
		printf("��������ң�");
		scanf("%s", newfilm.national);
		printf("����������:1-���� 2-������");
		scanf("%d", &newfilm.type);
		printf("������������");
		scanf("%d", &newfilm.account);
		printf("�����뵼�ݣ�");
		scanf("%s", newfilm.dir);
		printf("��������ӳʱ�䣺");
		scanf("%d", &newfilm.year);
		getchar();
		printf("�Ƿ񱣴��Ӱ����Ϣ��Y/N����");
		if (judge())
		{
			fp = fopen("film_date.txt", "a");
			fprintf(fp, "%s %s %d %d %s %d\n", newfilm.name, newfilm.national, newfilm.type, newfilm.account, newfilm.dir, newfilm.year);
			fclose(fp);
			printf("����ɹ�!\n");
		}
		else printf("δ���棡\n");
		printf("�Ƿ��������?��Y/N����");
		if (judge())continue;
		else return;
	}
}
void show()
{
	FILE *fp;
	int num=0;
	FILM filmlist[MAXN];
	fp = fopen("film_date.txt", "r");
	while (!feof(fp))
	{
		fscanf(fp, "%s%s%d%d%s%d", filmlist[num].name, filmlist[num].national, &filmlist[num].type, &filmlist[num].account, filmlist[num].dir, &filmlist[num].year);
		num++;
	}
	fclose(fp);
	if (num == 0)printf("��ǰ���Ϊ��");
	else {
		printf("*****************ͼ����Ϣ*****************\n");
		printf("Ӱ����     ����  ����  ����  ����  ��ӳʱ��\n");
		num--;
		while (num--)
			printf("%-10s%5s%5d%5d%10s%5d\n", filmlist[num].name, filmlist[num].national, filmlist[num].type, filmlist[num].account, filmlist[num].dir, filmlist[num].year);
	}
	printf("��������˳����");
	getchar();
}
void find()
{
	char choice;
	FILM find_film;
	FILE *fp;
	FILM filmlist[MAXN];
	int num = 0,flag=1;
	fp = fopen("film_date.txt", "r+");
	while (!feof(fp))
	{
		fscanf(fp, "%s%s%d%d%s%d", filmlist[num].name, filmlist[num].national, &filmlist[num].type, &filmlist[num].account, filmlist[num].dir, &filmlist[num].year);
		num++;
	}
	fclose(fp);
	for (;;)
	{
		printf("��ѡ���ѯ����(1-���� 2-����)��\n");
		choice = getchar_s();
		printf("�������ѯ��Ϣ��");
		switch (choice)
		{
		case'1':gets_s(find_film.name); flag = 0; break;
		case'2':gets_s(find_film.dir); flag = 0; break;
		default:
			printf("�����루1-2����");
			getchar_s();
		}
		int flag = 0;
		switch (choice)
		{

		case '1':
			printf("*****************ͼ����Ϣ*****************\n");
			printf("Ӱ����     ����  ����  ����  ����  ��ӳʱ��\n");
			for (int i = 0; i < num; i++)
			{

				if (strcmp(find_film.name, filmlist[i].name) == 0)
				{
					printf("%-10s%5s%5d%5d%10s%5d\n", filmlist[i].name, filmlist[i].national, filmlist[i].type, filmlist[i].account, filmlist[i].dir, filmlist[i].year);
					flag = 1;
				}
			}
			if (flag == 0)printf("û�з��������ĵ�Ӱ��"); break;
		case '2':
			printf("*****************ͼ����Ϣ*****************\n");
			printf("Ӱ����     ����  ����  ����  ����  ��ӳʱ��\n");
			for (int i = 0; i < num; i++)
			{
				if (strcmp(find_film.dir, filmlist[i].dir) == 0)
				{
					printf("%-10s%5s%5d%5d%10s%5d\n", filmlist[i].name, filmlist[i].national, filmlist[i].type, filmlist[i].account, filmlist[i].dir, filmlist[i].year);
					flag = 1;
				}
			}
			if (flag == 0)printf("û�з��������ĵ�Ӱ��"); break;
		default:
			break;
		}
		printf("\n�Ƿ������ѯ��Y/N����");
		if (judge())continue;
		else { printf("��������˳�����"); getchar(); return; }
	}
}
void show_user()
{
	char user[MAXN];
	FILE *fp;
	fp = fopen("user.txt", "r");


}
void rent() 
{
	FILM filmlist[MAXN];
	int num = 0;
	int select;
	FILE *fp = fopen("film_date.txt", "a+");
	while (!feof(fp))
	{
		fscanf(fp, "%s%s%d%d%s%d", filmlist[num].name, filmlist[num].national, &filmlist[num].type, &filmlist[num].account, filmlist[num].dir, &filmlist[num].year);
		num++;
	}
	fclose(fp);
	printf("��ǰ�ɽ��Ӱ����\n");
	int count = 1;
	printf("���   Ӱ����    ���\n");
	for (int i = 0; i<num - 1; i++)
	{
		if(filmlist[i].account==0)
			printf("%-6d%-11s%-5d���ɽ�\n",i+1, filmlist[i].name, filmlist[i].account);
		else printf("%-6d%-11s%-5d�ɽ�\n", i + 1, filmlist[i].name, filmlist[i].account);
	}
	puts("���Ĺ���ÿ��5Ԫ");
	printf("����������ĵĵ�Ӱ���:\n");
	for (;;) {
		scanf("%d", &select);
		getchar();
		if ( select>num-1  ||  select< 1)
			printf("��������ȷ�ı��:");
		else {
			while (filmlist[select-1].account == 0)
			{
				printf("��Ӱ�����ɽ裡\n���������룺");
				scanf("%d", &select);
				getchar();
			}
			printf("ȷ�Ͻ��ģ�Y/N)");
			if (judge()) {
				filmlist[(select) - 1].account--;
				fp = fopen("film_date.txt","w");
				for (int i = 0; i<num - 1; i++)
					fprintf(fp,"%s %s %d %d %s %d\n",filmlist[i].name, filmlist[i].national, filmlist[i].type, filmlist[i].account, filmlist[i].dir, filmlist[i].year);
				fclose(fp);
				printf("���ĳɹ�!");
				printf("�������ģ�Y/N����");
				if (judge())continue;
				else { printf("��������˳����ģ�"); getchar(); return; }
			}
			else { printf("����ʧ�ܣ�"); return; }
		}
	}
}
void back()
{
	int y1, m1, d1, y, m, d;
	time_t t;
	struct tm * lt;
	time(&t);			//��ȡUnixʱ���
	lt = localtime(&t); //תΪʱ��ṹ
	y1 = y = lt->tm_year + 1900;
	m1 = m = lt->tm_mon + 1;
	d1 = d = lt->tm_mday;
	int time;
	scanf("%d", &time);
	switch (time)
	{
	case 1:d = d1 + 7; break;
	case 2:d = d1 + 14; break;
	case 3:m = m1 + 1;	break;
	}
	if (d>30)
	{
		d -= 30;
		m++;
	}
	if (m>12)
	{
		m = 1;
		y++;
	}
	printf("�黹����Ϊ��%d��%d��%d��\n", y, m, d);
}
void alter()
{
	FILE *fp;
	int num = 0;
	FILM filmlist[MAXN];
	fp = fopen("film_date.txt", "r+");
	while (!feof(fp))
	{
		num++;
		fscanf(fp, "%s%s%d%d%s%d", filmlist[num].name, filmlist[num].national, &filmlist[num].type, &filmlist[num].account, filmlist[num].dir, &filmlist[num].year);
	}
	num--;
	printf("*******************ͼ����Ϣ***********************\n");
	printf("���  Ӱ����     ����  ����  ���  ����  ��ӳʱ��\n");
	for (int i = 1; i <= num; i++)
		printf("%-5d%-10s%5s%5d%5d%10s%5d\n", i, filmlist[i].name, filmlist[i].national, filmlist[i].type, filmlist[i].account, filmlist[i].dir, filmlist[i].year);
	int choice1, choice2;
	printf("��ѡ��Ӱ�����(1-%d)���޸�����(1-��� 2-��ӳʱ��)��\n", num);
	int flag = 1;
	for (;;)
	{
		do {
			flag = 1;
			scanf("%d%d", &choice1, &choice2);
			switch (choice2)
			{
			case 1:printf("ԭ���ݣ�%s %d\n", filmlist[choice1].name, filmlist[choice1].account);
				printf("�������µĿ�棺"); scanf("%d", &filmlist[choice1].account); break;
			case 2:printf("ԭ���ݣ�%s %d\n", filmlist[choice1].name, filmlist[choice1].year);
				printf("�������µ���ӳʱ�䣺"); scanf("%d", &filmlist[choice1].year); break;
			default:printf("���������룺"); flag = 0; break;
			}
		} while (flag == 0);
		if (judge())continue;
		else break;
	}
	rewind(fp);
	for (int j = 1; j <= num; j++)
		fprintf(fp, "%s %s %d %d %s %d\n", filmlist[j].name, filmlist[j].national, filmlist[j].type, filmlist[j].account, filmlist[j].dir, filmlist[j].year);
	fclose(fp);
	printf("�޸ĳɹ���"); printf("������ת..."); Sleep(700);
	getchar();
}
char getchar_s()
{
	char ret_val;
	ret_val = getchar();
	while (getchar() != '\n')
		continue;
	return ret_val;
}
bool judge()
{
	char choice;
	choice = getchar_s();
	if (choice == 'y' || choice == 'Y')return true;
	else return false;
}