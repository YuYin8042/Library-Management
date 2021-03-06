// main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
#include "library.h"
#define FILENAME "Book_info.txt"
#define FILENAME2 "Reader_info.txt"

char Init_p[20] = "12345678";   /*管理员密码*/
char ID[20];            /*记录用户输入ID*/

int main()
{
	system("mode con cols=100 lines=30");
	system("title Library Management");

	BOOK_LIST head;			/*图书链表头指针*/
	READER_LIST head2;      /*读者链表头指针*/
	int index;
	char password_a[20];		/*记录管理员输入密码*/

	head = load();			/*读入文件内容，创建链表*/
	head2 = load2();        /*读入文件内容，创建链表*/


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
			printf("            输入有误，请重新输入 : ");
			scanf_s("%d", &index);
		}

		switch (index) {
		case 1:
			READER_LIST p;
			char pw[20];		//password
			int flag;

			flag = 0;

			system("cls");
			printf("\n\n  请输入您的账号 : ");
			scanf_s("%19s", ID, 20);

			while (1)
			{
				for (p = head2; p != NULL; p = p->next)
				{
					if (strcmp(p->id, ID) == 0)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					printf("\n  此账号不存在!!请重新输入账号 : ");
					scanf_s("%19s", ID, 20);
				}
				else
				{
					printf("\n  请输入您的密码 : ");
					scanf_s("%19s", pw, 20);
					while (1) {
						if (strcmp(p->password, pw) == 0)
						{
							break;
						}
						else
						{
							printf("\n  密码错误!\n");
							printf("  请重新输入密码 : ");
							scanf_s("%19s", pw, 20);
						}
					}	
					break;
				}
			}
			printf("\n\n  密码正确，即将进入用户界面");
			Sleep(500);
			system("cls");
			user_menu(head, head2);				/*打印用户界面*/
			break;
		case 2:
			system("cls");			
			printf("\n\n  请输入密码（共8位）: ");
			scanf_s("%19s", &password_a, 20);

			while (1)
			{
				if (strcmp(Init_p, password_a) == 0)
					break;
				else
				{
					printf("\n  密码错误!\n");
					printf("  请重新输入密码（共8位）: ");
					scanf_s("%19s", &password_a, 20);
				}
			}
			printf("\n\n  密码正确，即将进入管理员界面");
			Sleep(500);
			system("cls");
			admin_menu(head);  //打印管理员界面
			break;
		case 3:
			exit(0);
		}
	}
	return 0;
}

	
/*用户界面函数user_menu：打印用户选择界面*/
void user_menu(BOOK_LIST head, READER_LIST head2)
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
			display_user_info(head2, head);
			break;
		case 4:
			system("cls");
			modify_password(head2);
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

	printf("        输入序号进入对应功能 : ");
	scanf_s("%d", &choice);
	fflush(stdin);

	while (choice < 1 || choice > 5)
	{
		printf("        \n输入有误，请重新输入: ");
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
			printf("\n请输入新密码（共8位）：");
			scanf_s("%19s", Init_p, 20);
			printf("\n修改密码成功！请重新登录。");
			Sleep(500);
			system("cls");
			return;
			break;
		case 7:
			system("cls");
			return;
		case 8:
			exit(0);
		}
	}
}