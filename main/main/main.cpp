// main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include "library.h"
#define FILENAME "Book_info.txt"


int main()
{
	system("mode con cols=100 lines=30");
	system("title Library Management");

	BOOK_LIST head;			/*图书链表头指针*/
	int index;

	head = load();			/*读入文件内容，创建链表*/

	while (1)
	{
		printf("\n\n");
		printf("        +---------------------------------------------------------+\n");
		printf("        |                                                         |\n");
		printf("        |                        图书管理系统                     |\n");
		printf("        |                                                         |\n");
		printf("        +---------------------------------------------------------+\n");
		printf("        |                                                         |\n");
		printf("        |                        1.用户模式                       |\n");
		printf("        |                        2.管理员模式                     |\n");
		printf("        |                        3.退出系统                       |\n");
		printf("        |                                                         |\n");
		printf("        +---------------------------------------------------------+\n");
		printf("\n");
		printf("         输入序号进入对应功能 : ");
		fflush(stdin);
		scanf_s("%d", &index);
		while (index < 1 || index > 3)
		{
			printf("            输入有误，请重新输入: ");
			scanf_s("%d", &index);
		}

		switch (index) {
		case 1:
			system("cls");
			auth_password_u();			/*用户密码验证*/
			user_menu(head);				/*打印用户界面*/
			break;
		case 2:
			system("cls");
			auth_password_a();			/*管理员密码验证*/
			admin_menu(head);				/*打印管理员界面*/
			break;
		case 3:
			exit(0);
		}
	}
	return 0;
}

	
/*用户界面函数user_menu：打印用户选择界面*/
void user_menu(BOOK_LIST head)
{
	int choice = 0;
	while (1)
	{
		printf("\n");
		printf("  +---------------------------------------------------------+\n");
		printf("  |                        用户界面                         |\n");
		printf("  +---------------------------------------------------------+\n");
		printf("  |                                                         |\n");
		printf("  |                        1.查看图书信息                   |\n");
		printf("  |                        2.借阅书籍                       |\n");
		printf("  |                        3.查看个人信息                   |\n");
		printf("  |                        4.修改密码                       |\n");
		printf("  +---------------------------------------------------------+\n");
		printf("  |                        5.退出登录                       |\n");
		printf("  |                        6.退出系统                       |\n");
		printf("  |                                                         |\n");
		printf("  +---------------------------------------------------------+\n\n");

		printf("    输入序号进入对应功能 : ");
		scanf_s("%d", &choice);
		fflush(stdin);

		while (choice < 1 || choice > 6)
		{
			printf("    输入有误，请重新输入: ");
			scanf_s("%d", &choice);
		}

		switch (choice)
		{
		case 1:
			system("cls");
			display_book_info(head);
			break;
		case 2:
			system("cls");
			borrow_book(head);
			break;
		case 3:
			system("cls");
			display_user_info();
			break;
		case 4:
			system("cls");
			modify_password();
			break;
		case 5:
			system("cls");
			return;
		case 6:
			exit(0);
		}
	}
}


/*-----查看图书信息选择界面display：打印查看界面-----*/
void display_book_info(BOOK_LIST head)
{
	int choice = 0;
	printf("\n");
	printf("       +---------------------------------------------------------+\n");
	printf("       |                        查看图书信息                     |\n");
	printf("       +---------------------------------------------------------+\n");
	printf("       |                                                         |\n");
	printf("       |                     1.查看所有图书信息                  |\n");
	printf("       |                     2.查看已借阅图书信息                |\n");
	printf("       |                     3.查看未借阅图书信息                |\n");
	printf("       +---------------------------------------------------------+\n");
	printf("       |                     4.返回上一界面                      |\n");
	printf("       |                     5.退出系统                          |\n");
	printf("       |                                                         |\n");
	printf("       +---------------------------------------------------------+\n\n");

	printf("         输入序号进入对应功能 : ");
	scanf_s("%d", &choice);
	fflush(stdin);

	while (choice < 1 || choice > 5)
	{
		printf("           输入有误，请重新输入: ");
		scanf_s("%d", &choice);
	} 

	switch (choice)
	{
	case 1:
		system("cls");
		display_all(head);
		break;
	case 2:
		system("cls");
		display_borrowed(head);
		break;
	case 3:
		system("cls");
		display_unborrowed(head);
		break;
	case 4:
		system("cls");
		return;
		break;
	case 5:
		exit(0);
	}
}


/*----------管理员界面函数admin_menu：打印管理员界面-------------*/
void admin_menu(BOOK_LIST head)
{
	int choice = 0;
	while (1)
	{
		printf("\n");
		printf("  +---------------------------------------------------------+\n");
		printf("  |                        管理员界面                       |\n");
		printf("  +---------------------------------------------------------+\n");
		printf("  |                                                         |\n");
		printf("  |                       1.查找图书                        |\n");
		printf("  |                       2.查看图书信息                    |\n");
		printf("  |                       3.修改图书信息                    |\n");
		printf("  |                       4.录入图书                        |\n");
		printf("  |                       5.删除图书                        |\n");
		printf("  |                       6.修改密码                        |\n");
		printf("  +---------------------------------------------------------+\n");
		printf("  |                       7.退出登录                        |\n");
		printf("  |                       8.退出系统                        |\n");
		printf("  |                                                         |\n");
		printf("  +---------------------------------------------------------+\n\n");

		printf("    输入序号进入对应功能 : ");
		scanf_s("%d", &choice);
		fflush(stdin);

		while (choice < 1 || choice > 8)
		{
			printf("    输入有误，请重新输入: ");
			scanf_s("%d", &choice);
		}

		switch (choice)
		{
		case 1:
			system("cls");
			search_book(head);
			break;
		case 2:
			system("cls");
			display_book_info(head);
			break;
		case 3:
			system("cls");
			change_book_info(head);
			break;
		case 4:
			system("cls");
			input(head);
			break;
		case 5:
			system("cls");
			delete_book(head);
			break;
		case 6:
			system("cls");
			modify_password();
			break;
		case 7:
			system("cls");
			return;
		case 8:
			exit(0);
		}
	}
}