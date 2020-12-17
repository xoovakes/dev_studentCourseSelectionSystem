#include "function_prototy.h"
//student *s_head = NULL;

//学生选课
void C_select()
{
	char s_num[10];		 //学生学号
	char s_password[10]; //密码
	int c_num;			 //课程号
	int flag = 0;		 //是否找到课程标号的标记
	char c_name[MAX];	 //课程名称
	int total_credit;	 //已修学分
	int j,b;
	student *p = s_head;
	system("cls");
	printf("\t*************************************************************\n");
	printf("\t**    广州商学院学生选课系统-学生端-选择课程               **\n");
	printf("\t*************************************************************\n");
	readC_data();
	printf("\tid          name        credit        selected           upper\n");
	printf("\t=============================================================\n");
	for (j = 0; j < i; j++)
	{
		printf("\t%-10d  %-10s  %-13d  %-16d  %-10d\n", courses[j].c_num, courses[j].c_name, courses[j].c_credit, courses[j].c_selected, courses[j].c_upper);
	}
	printf("\t=============================================================\n");
	printf("\t确认学号：");
	scanf("%s", &s_num);
	printf("\t确认密码:");
	for (j = 0; j <= 6; j++)
	{
		s_password[j] = getch();
		if (s_password[j] == '\r')
		{
			s_password[j] = '\0';
		}
		if (j < 6)
		{
			printf("*");
		}
	}
	printf("\n");
	while (NULL != p)
	{
		if (0 == strcmp(p->s_number, s_num) && 0 == strcmp(p->s_password, s_password))
		{
			printf("\t请输入课程编号:");
			scanf("%d", &c_num);

			/* 查看学生选过课 */
			int ii = 0;
			FILE *fp_c = NULL;
			fp_c = fopen("c_selected.dat", "r");
			memset(&selected, 0, sizeof(selected));
			if ((NULL == fp_c))
			{
				printf("\t_1 openfile error!\n");
				return;
			}
			else
			{
				rewind(fp_c);
				char ch = getc(fp_c);
				if (ch == EOF)
				{
					printf("\t没有课程数据\n");
				}
				else
				{
					rewind(fp_c);
					while (!feof(fp_c))
					{
						fscanf(fp_c, "%d,%s\n", &selected[ii].c_num, &selected[ii].s_number);
						ii++;
					}
				}
				fclose(fp_c);
			}

			/* 统计该同学总学分，并检测有无重复 */
			total_credit = 0;
			for (j = 0; j < ii; j++)
			{
				if (strcmp(s_num, selected[j].s_number) == 0) //selected中找学生选过的课
				{
					if (c_num == selected[j].c_num) //现在选的课之前选过了
					{
						printf("\t这门课你选过了!\n");
						system("pause");
						system("cls");
						return;
					}
					for (b = 0; b < i; b++)
					{
						if (c_num == courses[b].c_num)
							total_credit += courses[b].c_credit;
						if (selected[j].c_num == courses[b].c_num)
							total_credit += courses[b].c_credit;
					}
				}
			}
			if (total_credit > 60)
			{
				printf("\t你选课总学分超过了60!\n");
				system("pause");
				system("cls");
				return;
			}
			printf("选课成功！\n");

			for (j = 0; j < i; j++)
			{
				if (courses[j].c_num == c_num && courses[j].c_selected < courses[j].c_upper)
				{
					courses[j].c_selected++;
					//重写课程文件
					//将数据写入课程数据文件
					FILE *fp = fopen("course.dat", "w");

					int k;
					if ((NULL == fp))
					{
						printf("\t_2 openfile error!\n");
						return;
					}
					else
					{
						//	fwrite(&course_new,sizeof(course),1,f);
						for (k = 0; k < i; k++)
						{
							//printf("%d,%s,%d,%d,%d\n",courses[k].c_num,courses[k].c_name,courses[k].c_credit,courses[k].c_selected,courses[k].c_upper);
							fprintf(fp, "%d,%s,%d,%d,%d\n", courses[k].c_num, courses[k].c_name, courses[k].c_credit, courses[k].c_selected, courses[k].c_upper);
						}
					}
					fclose(fp);
					FILE *f = fopen("c_selected.dat", "a");
					if (NULL == f)
					{
						printf("\t_3 openfile error!\n");
					}
					else
					{
						fprintf(f, "%d,%s\n", c_num, s_num);
					}
					fclose(f);
					break;
				}
				else
				{
					flag++;
				}
			}
			if (flag == i)
			{
				printf("\t该课程不存在！\n");
				break;
			}
			break;
		}
		p = p->next;
	}
	if (NULL == p)
	{
		printf("\t学号或密码输入错误！");
	}
	system("pause");
	system("cls");
}

//学生浏览课程
void C_stuView()
{
	int j;
	readC_data();
	system("cls");
	printf("\n");
	printf("\t*************************************************************\n");
	printf("\t**    广州商学院学生选课系统-学生端-查看课程               **\n");
	printf("\t*************************************************************\n");
	printf("\tc_id       name        credit        selected           upper\n");
	printf("\t=============================================================\n");
	for (j = 0; j < i; j++)
	{
		printf("\t%-10d  %-10s  %-13d  %-16d  %-10d\n", courses[j].c_num, courses[j].c_name, courses[j].c_credit, courses[j].c_selected, courses[j].c_upper);
	}
	printf("\t=============================================================\n");
	system("pause");
	system("cls");
}

//学生查找课程
void C_stufind()
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
		printf("\t**    广州商学院学生选课系统-学生端-查找课程             **\n");
		printf("\t*************************************************************\n");
		printf("\t                    1.课程编号查询                           \n");
		printf("\t                    2.课程名称查询                           \n");
		printf("\t                    3.返回                                   \n");
		printf("\t-------------------------------------------------------------\n");
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

