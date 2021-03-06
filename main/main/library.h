#pragma once

/************结构体定义************/


/*---------------------------图书信息---------------------------*/

/*----------图书节点------------*/
typedef struct book_node {

	int num;						//图书序号   
	char name[40];             //图书名称    
	char author[20];           //作者      
	char publish[40];               //出版社  
	char publish_date[20];				//出版日期（年、月、日）  
	int status;						//借阅状态（两种状态：已借阅为1、未借阅为0）
	char readerID[20];				//借阅人ID
	struct book_node *next;			//节点指针
} BOOK;

typedef BOOK *BOOK_LIST;		//重新命名链表指针为 BOOK_LIST



/*-----------------------用户信息---------------------*/                //最大借书数量？？
/*---------用户节点----------*/
typedef struct reader_node {
	char id[20];					//账号   
	char password[20];			//密码  
	struct reader_node *next;
} READER;

typedef READER *READER_LIST;		//重新命名链表指针为 READER_LIST




/*************函数声明************/


void admin_menu(BOOK_LIST head);
void user_menu(BOOK_LIST head, READER_LIST head2);


/*-----------load函数：加载文件----------*/
BOOK_LIST load(void);

/*-----------load2函数：加载读者文件（返回值为链表指针）（尾插法创建链表）----------*/
READER_LIST load2(void);



/*-----查看图书信息选择界面display_book_info：打印查看界面-----*/
void display_book_info(BOOK_LIST head);

/*-----查看个人信息display_user_info----*/
void display_user_info(READER_LIST head2, BOOK_LIST head);
/*-----修改用户密码modify_password--------*/
READER_LIST modify_password(READER_LIST head2);

/*--------------------图书信息录入--------------------*/
/*函数input：录入图书信息*/
BOOK_LIST input(BOOK_LIST head);

/*--------------------查找图书------------------------*/
/*函数search_book：进入后输入书名或书号，进行查找*/
void search_book(BOOK_LIST head);
/*----函数search_by_num：按书号查询----*/
void search_by_num(BOOK_LIST head);
/*----函数search_by_num：按书名查询----*/
void search_by_name(BOOK_LIST head);

/*函数display_all：查看所有图书信息*/
void display_all(BOOK_LIST head);

/*--------------------筛选图书------------------*/
/*函数display_unborrowed：查看所有未借阅书籍信息*/
void display_unborrowed(BOOK_LIST head);
/*函数display_borrowed：查看所有已借阅图书信息*/
void display_borrowed(BOOK_LIST head);

/*-------------------借阅图书-------------------*/
/*函数borrow_book：借阅图书*/
void borrow_book(BOOK_LIST head);

/*-------------------修改图书-------------------*/
/*函数change_book_info：修改图书信息*/
void change_book_info(BOOK_LIST head);

/*-------------------删除图书-------------------*/
/*函数delete_book：删除图书信息*/
BOOK_LIST delete_book(BOOK_LIST head);

/*-------------将链表数据写入文件---------------*/
BOOK_LIST data_to_file(BOOK_LIST head);

READER_LIST data_to_file2(READER_LIST head2);
