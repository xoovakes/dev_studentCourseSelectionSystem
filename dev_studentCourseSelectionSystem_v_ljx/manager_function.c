#include "function_prototy.h"
//manager *m_head = NULL;

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

//查看学生数据
void view_s()
{
	ReadStudentDate();
	student *q = s_head;
	system("cls");
	printf("\t*************************************************************\n");
	printf("\t**    广州商学院学生选课系统-管理员端-查看学生账号         **\n");
	printf("\t*************************************************************\n");
	printf("\t\t\t学生学号\t\t学生密码\n");
	printf("\t-------------------------------------------------------------\n");
	while (NULL != q)
	{
		printf("\t\t\t%-20s\t%-20s\n", q->s_number, q->s_password);
		q = q->next;
	}
	printf("\t*************************************************************\n");
	system("pause");
	system("cls");
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

//增加课程
void C_add()
{
	system("cls");
	course course_new;
	int j;		  //用来控制数组下标
	int flag = 0; //用来标记输入的合法性
	printf("\n");
	printf("\t*************************************************************\n");
	printf("\t**    广州商学院学生选课系统-管理员端-增加课程             **\n");
	printf("\t*************************************************************\n");
	printf("\n\t请输入课程信息");
	printf("\n\t1.课程编号:");
	scanf("%d", &course_new.c_num);
	printf("\t2.课程名字:");
	scanf("%s", course_new.c_name);
	printf("\t3.课程学分:");
	scanf("%d", &course_new.c_credit);
	printf("\t4.课程已选人数:");
	scanf("%d", &course_new.c_selected);
	printf("\t5.课程人数上限:");
	scanf("%d", &course_new.c_upper);
	printf("\n");
	readC_data();
	//判断新录入的课程编号或课程名称是否存在
	for (j = 0; j < i; j++)
	{
		if (course_new.c_num == courses[j].c_num || 0 == strcmp(course_new.c_name, courses[j].c_name))
		{
			printf("\n\t对不起，编号或者课程名称已经存在!\n");
			flag = 1; //输入非法标记
			system("pause");
			system("cls");
			break;
		}
	}
	if (0 == flag)
	{
		saveC_data(course_new);
	}
	system("pause");
	system("cls");
}

//查看课程模块
void C_view()
{
	int j;
	readC_data();
	system("cls");
	printf("\n");
	printf("\t*************************************************************\n");
	printf("\t**    广州商学院学生选课系统-管理员端-查看课程             **\n");
	printf("\t*************************************************************\n");
	printf("\tc_id       name        credit        selected           upper\n");
	printf("\t=============================================================\n");
	for (j = 0; j < i; j++)
	{
		printf("\t%-10d  %-10s  %-13d  %-16d  %-10d\n", courses[j].c_num, courses[j].c_name, courses[j].c_credit, courses[j].c_selected, courses[j].c_upper);
	}
	system("pause");
	system("cls");
}

//删除课程模块
void C_delete()
{
	int c_num;
	int j, n, k, flag = 0;
	printf("\n");
	printf("\t*************************************************************\n");
	printf("\t**    广州商学院学生选课系统-管理员端-删除课程             **\n");
	printf("\t*************************************************************\n");
	printf("\t请输入要删除的课程编号:");
	scanf("%d", &c_num);
	printf("\n");
	readC_data();
	FILE *fp = fopen("course.dat", "w");
	if (NULL == fp)
	{
		printf("open file error!");
	}
	for (j = 0; j < i; j++)
	{
		if (courses[j].c_num == c_num)
		{
			for (k = 0; k < j; k++)
			{
				fprintf(fp, "%d,%s,%d,%d,%d\n", courses[k].c_num, courses[k].c_name, courses[k].c_credit, courses[k].c_selected, courses[k].c_upper);
			}
			fclose(fp);
			FILE *f = fopen("course.dat", "a");
			if (NULL == f)
			{
				printf("open file error!");
			}
			for (k = j + 1; k < i; k++)
			{
				fprintf(f, "%d,%s,%d,%d,%d\n", courses[k].c_num, courses[k].c_name, courses[k].c_credit, courses[k].c_selected, courses[k].c_upper);
			}
			fclose(f);
			break;
		}
		else
		{
			flag++;
		}
	}
	printf("i=%d,flag=%d", i, flag);
	if (flag == i)
	{
		printf("课程编号不存在！\n");
		C_delete();
	}
	system("pause");
	system("cls");
}

//查找课程
void C_find()
{
	readC_data();
	char choice;
	int c_num;
	char c_name[MAX];
	int j; //用于循环中控制数组下标
	printf("\n");
	system("cls");
	while (1)
	{
		int flag1 = 0; //判断以学号查询找到标记
		int flag2 = 0; //判断以课程名称找到标记
		printf("\t*************************************************************\n");
		printf("\t**    广州商学院学生选课系统-管理员端-查找课程             **\n");
		printf("\t*************************************************************\n");
		printf("\t1.课程编号查询\n");
		printf("\t2.课程名称查询:\n");
		printf("\t3.退出:\n");
		printf("\t输入选择：");
		choice = getch();
		switch (choice)
		{
		case '1':
			printf("\n\t请输入课程编号:");
			scanf("%d", &c_num);
			printf("\n");
			flag1 = 0;
			for (j = 0; j < i; j++)
			{
				if (courses[j].c_num == c_num)
				{
					printf("\tid          name        credit        selected           upper\n");
					printf("\t=============================================================\n");
					printf("\t%-10d  %-10s  %-13d  %-16d  %-10d\n", courses[j].c_num, courses[j].c_name, courses[j].c_credit, courses[j].c_selected, courses[j].c_upper);
					system("pause");
					system("cls");
					break;
				}
				else
				{
					flag1++;
				}
			}
			if (flag1 == i)
			{
				printf("没有找到相关课程！\n");
				system("pause");
				system("cls");
				break;
			}
			break;
		case '2':
			printf("\n\t请输入课程名称:");
			scanf("%s", &c_name);
			printf("\n");
			flag2 = 0;
			for (j = 0; j < i; j++)
			{
				if (0 == strcmp(courses[j].c_name, c_name))
				{
					printf("\tid          name        credit        selected           upper\n");
					printf("\t=============================================================\n");
					printf("\t%-10d  %-10s  %-13d  %-16d  %-10d\n", courses[j].c_num, courses[j].c_name, courses[j].c_credit, courses[j].c_selected, courses[j].c_upper);
					system("pause");
					system("cls");
					break;
				}
				else
				{
					flag2++;
				}
			}
			if (flag2 == i)
			{
				printf("没有找到相关课程！\n");
				system("pause");
				system("cls");
				break;
			}
			break;
		case '3':
			system("pause");
			system("cls");
			return;
		default:
			printf("输入错误，请重新选择!\n");
			system("pause");
			system("cls");
			break;
		}
	}
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

