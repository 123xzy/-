#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"
int main()
{
	char choice;
	for (;;)
	{
		system("cls");
		Menu1();
		choice = getchar_s();
		while (choice > '6' || choice < '1')
		{
			printf("��������ȷ��ѡ��1-6��:");
			choice = getchar_s();
		}
		if (choice == '1')
		{
			Users_Login();
			UI();
		}
		else if (choice == '2')
		{
			if(Users_Regis()) UI();
		}
		else if (choice == '3')
			Find_Film();
		else if (choice == '4')
		{
			Film_Infor();
			printf("��������˳����"); 
			getchar();
		}
		else if (choice == '5')
		{
			Admin_Login();
			AdminI();
		}
		else if (choice == '6')
		{
			printf("��������˳�ϵͳ");
			getchar();
			exit(1); 
		}
	}
	return 0;
}