#include "function_prototy.h"


//管理员登录
void AdminLogin(int count)
{
	int j, k;
	char AdminID[10];
	char pass[10];
	ReadDate();
	printf("\n\t请输入管理员账号：");
	scanf("%s", &AdminID);
	printf("\t请输入管理密码:");
	//	scanf("%s",&password);
	for (j = 0; j <= 6; j++)
	{
		pass[j] = getch();
		if (pass[j] == '\r')
		{
			pass[j] = '\0';
			break;
		}
		printf("*");
	}
	count++;
	manager *p = m_head;
	while (NULL != p)
	{
		if (0 == strcmp(AdminID, p->m_name) && 0 == strcmp(pass, p->m_password))
		{
			Index_M();
			break;
		}
		p = p->next;
	}
	if (NULL == p)
	{
		printf("\n\t账号与密码不匹配!\n");
		//printf("\t输入错误次数：%d",count);
		if (count == 3)
		{
			printf("\t您的输入次数超过3次！\n");
			printf("\t退出登录程序!\n");
			system("pause");
			system("cls");
			return;
		}
		AdminLogin(count);
		//count++;
	}
}

//管理端菜单
void Index_M()
{
	system("cls");
	printf("\n\n");
	char input;
	while (1)
	{
		Index_M_Index();
		input = getch();
		switch (input)
		{
		case '1':
			Manage_Student();
			break;
		case '2':
			Manage_Class();
			break;
		case '3':
			system("cls");
			return;
			break;
		case '4':
			exit(0);
			break;
		default:
			printf("输入错误，请重新输入：\n");
			system("pause");
			system("cls");
			break;
		}
	}
}



//管理端-学生管理菜单
void Manage_Student()
{
	system("cls");
	printf("\n\n");
	char input;
	while (1)
	{
		printf("\t*************************************************************\n");
		printf("\t**      广州商学院学生选课系统-管理员端-学生管理            **\n");
		printf("\t*************************************************************\n");
		printf("\t**                1.新建学生账号                           **\n");
		printf("\t**                2.查看学生账号                           **\n");
		printf("\t**                3.查看选课学生                           **\n");
		printf("\t**                4.返回上页                               **\n");
		printf("\t**                5.退出                                   **\n");
		printf("\t-------------------------------------------------------------\n");
		printf("\n\t请输入选择:");
		input = getch();
		switch (input)
		{
		case '1':
			InsertStudent();
			break;
		case '2':
			view_s();
			break;
		case '3':
			C_StuSelected();
			break;
		case '4':
			system("cls");
			return;
			break;
		case '5':
			exit(0);
			break;
		default:
			printf("输入错误，请重新输入：\n");
			system("pause");
			system("cls");
			break;
		}
	}
}

//管理端-课程管理菜单
void Manage_Class()
{
	system("cls");
	printf("\n\n");
	char input;
	while (1)
	{
		printf("\t*************************************************************\n");
		printf("\t**      广州商学院学生选课系统-管理员端-课程管理            **\n");
		printf("\t*************************************************************\n");
		printf("\t**                1.新增课程                               **\n");
		printf("\t**                2.查看课程                               **\n");
		printf("\t**                3.查找课程                               **\n");
		printf("\t**                4.删除课程                               **\n");
		printf("\t**                5.返回首页                               **\n");
		printf("\t**                6.退出                                   **\n");
		printf("\t-------------------------------------------------------------\n");
		printf("\n\t请输入选择:");
		input = getch();
		switch (input)
		{
		case '1':
			C_add();
			break;
		case '2':
			C_view();
			break;
		case '3':
			C_find();
			break;
		case '4':
			C_delete();
			break;
		case '5':
			system("cls");
			return;
			break;
		case '6':
			exit(0);
			break;
		default:
			printf("输入错误，请重新输入：\n");
			system("pause");
			system("cls");
			break;
		}
	}
}

//插入学生数据
void InsertStudent()
{
	ReadStudentDate();
	student *new_account = (student *)malloc(sizeof(student)); //去内存开辟一块空间存储新的结点
	//这里是头插法的链表实现
	if (NULL == s_head)
	{
		s_head = new_account;	  //让头结点指向新插入的结点
		new_account->next = NULL; //让新结点的下一个结点指向空
	}
	else
	{
		new_account->next = s_head;
		s_head = new_account;
	}
	printf("\n\t请输入学号:");
	scanf("%s", &new_account->s_number);
	printf("\t请输入密码：");
	scanf("%s", &new_account->s_password);
	system("pause");
	system("cls");
	SaveStudentDate();
}

//清空学生链表
void S_freeMemory()
{
	student *p;
	p = s_head;
	while (NULL != p)
	{
		p = p->next;
		free(s_head);
		s_head = p;
	}
}

//清空管理员链表
void M_freeMemory()
{
	manager *p;
	p = m_head;
	while (NULL != p)
	{
		p = p->next;
		free(m_head);
		m_head = p;
	}
}

//插入管理员数据
void InsertAdministrator()
{
	ReadDate();
	manager *new_account = (manager *)malloc(sizeof(manager)); //去内存开辟一块空间存储新的结点
	//这里是头插法的链表实现
	if (NULL == m_head)
	{
		m_head = new_account;	  //让头结点指向新插入的结点
		new_account->next = NULL; //让新结点的下一个结点指向空
	}
	else
	{
		new_account->next = m_head;
		m_head = new_account;
	}
	printf("请输入管理员账号：\n");
	scanf("%s", &new_account->m_name);
	printf("请输入密码：\n");
	scanf("%s", &new_account->m_password);
	system("pause");
	system("cls");
	SaveDate();
}

//查找某门课选课的学生学号
void C_StuSelected()
{
	int c_num;
	int j, k;
	int flag = 0; //定义找到课程编号标记
	readC_data();
	system("cls");
	printf("\t*************************************************************\n");
	printf("\t**    广州商学院学生选课系统-管理员端-查看选课学生         **\n");
	printf("\t*************************************************************\n");
	printf("\n\t请输入课程编号：");
	scanf("%d", &c_num);
	printf("\n");
	int count = 0; //计数器
	for (j = 0; j < i; j++)
	{
		if (c_num == courses[j].c_num)
		{
			for (k = 0; k < courses[j].c_selected; k++)
			{
				if (courses[j].c_num != 0)
				{
					count++;
				}
			}
			break;
		}
		else
		{
			flag++;
		}
	}
	if (flag == i)
	{
		printf("输入的课程编号不存在！\n");
	}
	else
	{
		printf("\t\t课程编号\t\t学号\n");
		printf("\t=============================================================\n");
		FILE *f = fopen("c_selected.dat", "r");
		if (NULL == f)
		{
			printf("");
		}
		else
		{
			rewind(f);
			char ch = getc(f);
			if (ch == EOF)
			{
				printf("\t没有课程数据\n");
			}
			else
			{
				int k = 0;
				rewind(f);
				while (!feof(f))
				{
					fscanf(f, "%d,%s\n", &selected[k].c_num, &selected[k].s_number);
					if (selected[k].c_num == courses[j].c_num)
					{
						printf("\t\t%d       \t\t%s\n", courses[j].c_num, selected[k].s_number);
					}
					k++;
				}
				fclose(f);
			}
		}
		printf("\t=============================================================\n");
		printf("\t选修课程总人数为:%d\n", count);
	}
	system("pause");
	system("cls");
}

