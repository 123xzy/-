#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include<time.h>
#include "list.h"
#define KEY "1999"  

/*�Ƿ�ѭ��*/
static bool judge();

/*�����������*/
static int Total_Days(int year, int month, int days);
static int Sum(int, int, int);
static void alter(char*, int);

FILM filmlist[MAXN];  //����Ӱ����Ϣ
FILE *fp;
USER user[MAXN];      //�����û���Ϣ
USER User;            //��ǰ�û���Ϣ
Userfilm user_film[MAXN];//�û�������Ϣ

void Menu1()
{
	printf("********Ӱ������ϵͳ********\n");
	printf("       1.��Ա��¼\n");
	printf("       2.��Աע��\n");
	printf("       3.Ӱ������\n");
	printf("       4.Ӱ����Ϣ���\n");
	printf("       5.����Ա��¼\n");
	printf("       6.�˳�ϵͳ\n");
	printf("***************************\n");
	printf("��ѡ��1-6����");
}
void Menu2()
{
	printf("*********��Ա����**********\n");
	printf("      1.��ѯ�˻���Ϣ\n");
	printf("      2.����Ӱ��\n");
	printf("      3.�黹Ӱ��\n");
	printf("      4.�˳���Ա����\n");
	printf("****************************\n");
	printf("��ѡ��1-4����");
}
void Menu3()
{
	printf("*********����Ա����**********\n");
	printf("      1.Ӱ����Ϣ�޸�\n");
	printf("      2.Ӱ����Ϣ¼��\n");
	printf("      3.��ѯ������Ϣ\n");
	printf("      4.�˳�����Ա����\n");
	printf("****************************\n");
	printf("��ѡ��1-4����");
}
void Users_Login()
{
	int num;
	fp = fopen("user_date.txt", "r");
	for (num = 1; !feof(fp); num++)
		fscanf(fp, "%s%s", user[num].account, user[num].password);

	int flag=1;
	int count = 0;
	int i;

	//�����˻�
	while (flag)
	{
		
		printf("�˻���");
		gets_s(User.account);
		for (i = 1; i <= num; i++)
			if (!strcmp(User.account, user[i].account))
			{
				flag = 0; break;
			}
		
		//�û�������ʱ��ѡ��ע��
		if (i == ++num)
		{
			printf("���˻������ڣ��Ƿ�ע�����û���Y/N����");
			if (judge())
			{
				Users_Regis(); return;
			}
		}
	}
	//��������
	for (;;) {
		printf("���룺");
		gets_s(User.password);
		if (!strcmp(User.password, user[i].password))
		{
			printf("���ڵ�½...");
			Sleep(600); 
			return;
		}
		
		//���������������ʱ��ѡ���һ�����
		else
		{
			count++;
			if (count >= 3) 
			{ 
				printf("�Ƿ��һ����루Y/N)��");
				if (judge())
				{PassW_Retri(i); return;}
			}
			else 
			{
				printf("�˻����������\n");
				printf("�������������룺");
			}
		}
	}	
	
}
void Admin_Login()
{
	char code[MAXN];
	printf("����KEY��");
	gets_s(code);
	while (strcmp(code,KEY)) { printf("��֤��������������룺");gets_s(code);  }
	printf("��¼�ɹ���������ת...");
	Sleep(500);
	return;
}
void UI()
{
	char choice;
	for(;;){
		system("cls");
		Menu2();
		choice= getchar_s();
		while (choice > '5' || choice < '1')
		{
			printf("��������ȷ��ѡ��:");
			choice = getchar_s();
		}
		switch (choice)
		{
		case'1':User_Infor(User.account); break;
		case'2':Rent_Film(); break;
		case'3':Return_Film(); break;
		case'4':return;
		}
	}
}
void AdminI()
{
	char choice;
	for (;;) {
		system("cls");
		Menu3();
		choice = getchar_s();
		while (choice > '4' || choice < '1')
		{
			printf("��������ȷ��ѡ��:");
			choice = getchar_s();
		}
		switch (choice)
		{
		case'1':Alter_Film(); break;
		case'2':Addfilm(); break;
		case'3':User_Infor("Admin"); break;
		case'4':printf("��������˳�����Աϵͳ");getchar(); return;
		}
	}
}
bool Users_Regis()
{
	int num;
	fp = fopen("user_date.txt", "r+");
	for (num = 1; !feof(fp); num++)
		fscanf(fp, "%s%s", user[num].account, user[num].password);
	printf("�����µ��û�����");
	for(;;) {
		int i;
		scanf("%s", User.account);
		for (i = 1; i <= num; i++)
		{
			//�ظ�ע��
			if (!strcmp(User.account, user[i].account))
			{
				printf("���û����Ѿ����ڣ����������룺"); 
				break;
			}
		}
		if (i > num)break;
	}
	printf("�����µ����룺");
	scanf("%s", User.password);
	getchar();
	printf("ȷ��ע�ᣨY/N����");
	if (judge())
	{
		fprintf(fp, "%s %s\n", User.account,User.password);
		printf("ע��ɹ���");
		fclose(fp);
		printf("������ת..."); Sleep(700); return true;
	}
	else { printf("ע��ʧ�ܣ�"); Sleep(500); fclose(fp); return false; }
}
void PassW_Retri(int i)
{
	int code;
	char new_password1[MAXN];
	char new_password2[MAXN];
	int  num;
	fp = fopen("user_date.txt", "r+");
	for (num = 1; !feof(fp); num++)
		fscanf(fp, "%s%s", user[num].account, user[num].password);
	
	//��֤���ε�����
	printf("�������µ����룺");
	fgets(new_password1, MAXN, stdin);
	printf("������һ�������룺");
	fgets(new_password2, MAXN, stdin);
	while (strcmp(new_password1, new_password2)) 
	{ 
		printf("�������벻ͬ��\n");
		printf("�������µ����룺");
		fgets(new_password1, MAXN, stdin);
		printf("������һ�������룺");
		fgets(new_password2, MAXN, stdin);
	}

	strcpy(user[i].password , new_password1);
	rewind(fp);
	for (int j = 1; j <=num; j++)
		fprintf(fp, "%s %s\n", user[j].account, user[j].password);
	fclose(fp);
	printf("�޸�����ɹ���������ת...");
	Sleep(500);
	return;
}
void Addfilm()
{
	FILM newfilm;
	int  num;
	for (;;)
	{
		fp = fopen("film_date.txt", "a+");
		printf("������Ӱ�����ƣ�");
		scanf("%s", newfilm.name);
		printf("��������ң�");
		scanf("%s", newfilm.national);
		printf("����������1.Comedy 2.Action 3.Romance 4.Sci-Fi 5.Horror 6.Documentary");
		scanf("%d", &newfilm.type);
		printf("������������");
		scanf("%d", &newfilm.quantity);
		printf("�����뵼�ݣ�");
		scanf("%s", newfilm.dir);
		printf("��������ӳʱ�䣺");
		scanf("%d", &newfilm.year);
		getchar();
		printf("�Ƿ񱣴��Ӱ����Ϣ��Y/N����");
		if (judge())
		{
			fprintf(fp, "%s %s %d %d %s %d\n", newfilm.name, newfilm.national, newfilm.type, newfilm.quantity, newfilm.dir, newfilm.year);
			printf("����ɹ�!\n");fclose(fp);
		}
		else printf("δ���棡\n");
		printf("�Ƿ��������?��Y/N����");
		if (judge())continue;
		else  return; 
	}
}
void Film_Infor()
{
	FILM* p=filmlist;
	int i,num=1;
	FILE*fp = fopen("film_date.txt", "r");
	if (fp == NULL) 
	{
		printf("fialed"); exit(1);
	}

	//��ȡ�ļ�
	for (i=0; !feof(fp);i++)
		fscanf(fp, "%s%s%d%d%s%d\n", filmlist[i].name, filmlist[i].national, &filmlist[i].type, &filmlist[i].quantity, filmlist[i].dir, &filmlist[i].year);
	
	printf("���  Ӱ����   ����    ����     ����  ����  ��ӳʱ��\n");
	for (num,p=filmlist; p < filmlist + i; p++,num++)
	{
		printf("%-5d%-8s%5s", num,p->name, p->national);
		switch (p->type)
		{
		case 1:
			printf("   Comedy  ");
			break;
		case 2:
			printf("   Action  ");
			break;
		case 3:
			printf("   Romance ");
			break;
		case 4: 
			printf("   Sci-Fi  ");
			break;
		case 5:
			printf("   Horror  ");
			break;
		case 6:
			printf("Documentary");
			break;
		}
		printf("%5d%8s%6d\n", p->quantity, p->dir, p->year);
	}
	fclose(fp);
	return;
}
void Find_Film()
{
	char choice;
	FILM find_film;
	int flag=1,num;
	fp = fopen("film_date.txt", "r");
	for (num = 1; !feof(fp); num++)
		fscanf(fp, "%s%s%d%d%s%d\n", filmlist[num].name, filmlist[num].national, &filmlist[num].type, &filmlist[num].quantity, filmlist[num].dir, &filmlist[num].year);
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
					printf("%-10s%5s%5d%5d%10s%5d\n", filmlist[i].name, filmlist[i].national, filmlist[i].type, filmlist[i].quantity, filmlist[i].dir, filmlist[i].year);
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
					printf("%-10s%5s%5d%5d%10s%5d\n", filmlist[i].name, filmlist[i].national, filmlist[i].type, filmlist[i].quantity, filmlist[i].dir, filmlist[i].year);
					flag = 1;
				}
			}
			if (flag == 0)printf("û�з��������ĵ�Ӱ��"); break;
		default:
			break;
		}
		printf("\n�Ƿ������ѯ��Y/N����");
		if (judge())continue;
		else 
		{ 
			fclose(fp); 
			printf("��������˳�����"); getchar();return;
		}
	}
}
void User_Infor(char *Account)
{
	FILE*fp = fopen("rent_back.txt", "rb");
	struct userfilm*head=NULL,*current,*prev;
	int num = 0;

	//���ļ���������Ϣ�γ�����
	while(!feof(fp))//�����ļ���β
	{
		current = (userfilm*)malloc(sizeof(userfilm));
		if(fread(current, sizeof(userfilm), 1, fp)==0)break;
		if(head ==NULL)head=current;  
		else prev->next=current;   
		current->next = NULL;    //���������������һ��                
		prev = current;          //current���ʹ��������Ϊ��һ��                
	}

	current = head;
	//�Թ���Ա��ݽ���
	if (!strcmp("Admin", Account))
	{
		while (current != NULL)
		{
			printf("%d %s %s %d��%d��%d��\n", ++num, current->account, current->name, current->year, current->month, current->day);
			current = current->next;
		}
	}
	//�����ǰ�û��Ľ�����Ϣ 
	else while (current != NULL)
	{
		if (!strcmp(current->account, Account))
			printf("%d %s %s %d��%d��%d��\n", ++num, current->account, current->name, current->year, current->month, current->day);
		current = current->next;
	}
	if (num == 0)printf("δ�����κ��鼮��");
	fclose(fp);
	printf("��������˳�");
	getchar();
	return;
}
void Rent_Film() 
{
	//��ȡ��ǰʱ��
	time_t t;
	struct tm * lt;
	time(&t);
	lt = localtime(&t);
	int y = lt->tm_year + 1900;
	int m = lt->tm_mon + 1;
	int d = lt->tm_mday;

	//չʾ��Ӱ����
	Film_Infor();
	
	//�ݴ���ĵ�Ӱ
	userfilm User_film; 
	
	struct userfilm*current;
	
	//�򿪵�Ӱ�ļ�
	int num=0;
	fp = fopen("film_date.txt", "r+");
	while (!feof(fp))
	{
		num++;
		fscanf(fp, "%s%s%d%d%s%d\n", filmlist[num].name, filmlist[num].national, &filmlist[num].type, &filmlist[num].quantity, filmlist[num].dir, &filmlist[num].year);
	}

	//�򿪽����ļ�
	FILE* rent_back = fopen("rent_back.txt", "a+");
	
	printf("ÿ����Ԫ\n");
	for(;;)
	{
		
		printf("����������ĵĵ�Ӱ��ţ�");
		int seqnum;//���ĵ�Ӱ���
		current= (userfilm*)malloc(sizeof(userfilm));
		strcpy(current->account, User.account);
		scanf("%d", &seqnum);
		getchar();
		strcpy(current->name, filmlist[seqnum].name);
		filmlist[seqnum].quantity--;
		current->year = y;
		current->month= m;
		current->day= d;
		fwrite(current, sizeof(userfilm), 1, rent_back);//���ṹ����Ϣд���ļ�
		printf("���ĳɹ�!");
		printf("�Ƿ�������ģ�Y/N����");
		if (judge())continue;
		else break;
	}
	fclose(rent_back);
	rewind(fp);
	for (int j = 1; j <= num; j++)
		fprintf(fp, "%s %s %d %d %s %d\n", filmlist[j].name, filmlist[j].national, filmlist[j].type, filmlist[j].quantity, filmlist[j].dir, filmlist[j].year);
	fclose(fp);
	return;
} 
void Return_Film()
{
	int num = 0, filmc = 0;

	//����ǰ�û��������û���Ϣ�ֳ���������
	struct userfilm*head1 = NULL,*prev1;
	struct userfilm*head2 = NULL,*prev2;
	struct userfilm* current;

	for (;;)
	{
		//�򿪵�Ӱ�ļ�
		fp = fopen("film_date.txt", "r+");
		while (!feof(fp))
		{
			filmc++;
			fscanf(fp, "%s%s%d%d%s%d\n", filmlist[filmc].name, filmlist[filmc].national, &filmlist[filmc].type, &filmlist[filmc].quantity, filmlist[filmc].dir, &filmlist[filmc].year);
		}

		FILE*fp2 = fopen("rent_back.txt", "rb+");
		while (!feof(fp2))//�����ļ���β,�����пӣ�feof����һ��
		{
			current = (userfilm*)malloc(sizeof(userfilm));
			if (fread(current, sizeof(userfilm), 1, fp2) == 0)break;
			if (!strcmp(current->account, User.account))
			{
				if (head1 == NULL)head1 = current;
				else prev1->next = current;
				current->next = NULL;//���������������һ��                  
				prev1 = current;//current���ʹ��������Ϊ��һ��                          
			}
			else
			{
				if (head2 == NULL)head2 = current;
				else prev2->next = current;
				current->next = NULL;
				prev2 = current;
			}
		}
		fclose(fp2);

		int choice;

		//�����ǰ�û��Ľ�����Ϣ
		current = head1; num = 0;
		while (current != NULL){
			if (!strcmp(current->account, User.account))
				printf("%d %s %s %d��%d��%d��\n", ++num, current->account, current->name, current->year, current->month, current->day);
			current = current->next;
		} 
		
		//ѡ��黹
		if (num == 0)
		{
			printf("δ�����鼮��"); return;
		}
		else {
			printf("ѡ��黹(1-%d):", num);
			scanf("%d", &choice);
		}

		//����ѡ���ж�
		while (choice<1 && choice>num)
		{
			printf("��������ѡ��:");
			scanf("%d", &choice);
		}

		int j = 1; current = head1;
		while (current != NULL)
		{
			//ѡ��黹��һ����ֱ�Ӹı��ͷ
			if (choice == 1) {
				for (int i = 1; i <= filmc; i++)
				{
					if (!strcmp(head1->name, filmlist[i].name))
					{
						filmlist[i].quantity++; break;
					}
				}
				printf("���Ѿ�����%d��\n", Total_Days(head1->year, head1->month, head1->day));
				head1 = current->next; break;
			}
			else {
				for (int i = 1; i <= filmc; i++)
				{
					if (!strcmp(head1->name, filmlist[i].name))
					{
						filmlist[i].quantity++; break;
					}
				}
				if ((choice - 1) == j) {
					printf("���Ѿ�����%d��\n", Total_Days(current->next->year, current->next->month, current->next->day));
					current->next = current->next->next; break;
				}
				else  current = current->next;
			}
			j++;
		}

		//��Ӵﵽ����ļ���Ŀ��
		fp2 = fopen("rent_back.txt", "w");
	
		//����ǰ�û���Ϣ�浵
		current = head1;
		while (current != NULL)
		{
			fwrite(current, sizeof(userfilm), 1, fp2);
			current = current->next;
		}

		//�������û���Ϣ�浵
		current = head2;
		while (current != NULL)
		{
			fwrite(current, sizeof(userfilm), 1, fp2);
			current = current->next;
		}
		fclose(fp2);

		//����Ӱ��Ϣ�黹
		rewind(fp);
		for (int j = 1; j <= num; j++)
			fprintf(fp, "%s %s %d %d %s %d\n", filmlist[j].name, filmlist[j].national, filmlist[j].type, filmlist[j].quantity, filmlist[j].dir, filmlist[j].year);
		fclose(fp);
		
		//�Ƿ����
		printf("�黹�ɹ����Ƿ�����黹��Y/N��:");
		getchar();
		if (judge())continue;
		else break;
	}
	printf("������ת...");
	Sleep(300);
	return;
}
void Alter_Film()
{
	int num=0;
	fp = fopen("film_date.txt", "r+");
	while (!feof(fp))
	{
		num++;
		fscanf(fp, "%s%s%d%d%s%d\n", filmlist[num].name, filmlist[num].national, &filmlist[num].type, &filmlist[num].quantity, filmlist[num].dir, &filmlist[num].year);
	}
	/*printf("*******************ͼ����Ϣ***********************\n");
	printf("���  Ӱ����     ����  ����  ���  ����  ��ӳʱ��\n");
	for (int i = 1; i <= num; i++)
		printf("%-5d%-10s%5s%5d%5d%10s%5d\n", i, filmlist[i].name, filmlist[i].national, filmlist[i].type, filmlist[i].quantity, filmlist[i].dir, filmlist[i].year);
	*/
	int choice1, choice2;
	
	int flag = 1;
	for (;;)
	{
		printf("��ѡ�����޸ĵ�Ӱ�����(1-%d)���޸�����(1-��� 2-��ӳʱ��)��\n", num);
		do {
			flag = 1;
			scanf("%d%d", &choice1, &choice2);
			switch (choice2)
			{
			case 1:printf("ԭ���ݣ�%s %d\n", filmlist[choice1].name, filmlist[choice1].quantity);
				printf("�������µĿ�棺");
				scanf("%d", &filmlist[choice1].quantity); getchar(); break;
			case 2:printf("ԭ���ݣ�%s %d\n", filmlist[choice1].name, filmlist[choice1].year);
				printf("�������µ���ӳʱ�䣺"); 
				scanf("%d", &filmlist[choice1].year); getchar(); break;
			default:printf("���������룺"); flag = 0; break;
			}
		} while (flag == 0);
		printf("�Ƿ�����޸ģ�Y/N����");
		if (judge())continue;
		else break;
	}
	rewind(fp);
	for (int j = 1; j <= num; j++)
		fprintf(fp, "%s %s %d %d %s %d\n", filmlist[j].name, filmlist[j].national, filmlist[j].type, filmlist[j].quantity, filmlist[j].dir, filmlist[j].year);
	fclose(fp);
	printf("�޸ĳɹ���������ת...");
	Sleep(700);
	return;
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
int Sum(int y, int m, int d)
{
	int a = 0, k = 0, i;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		k = 1;
	}

	for (i = 1; i<m; i++)
	{

		if (i == 2 && k == 1)
			a += 29;
		else if (i == 2)
			a += 28;
		else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
			a += 31;
		else
			a += 30;
	}
	a += d;
	return a;
}
int Total_Days(int year, int month, int days)
{

	time_t t; int y, m, d, s, k = 365;
	struct tm * lt;
	time(&t);
	lt = localtime(&t);
	y = lt->tm_year + 1900;
	m = lt->tm_mon + 1;
	d = lt->tm_mday;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		k = 366;
	}
	s = Sum(y, m, d) - Sum(year, month, days) + (y - year)*k;
	return s;
}