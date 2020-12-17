#include "function_prototy.h"

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

