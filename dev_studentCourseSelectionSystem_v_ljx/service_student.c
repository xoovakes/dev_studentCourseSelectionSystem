#include "function_prototy.h"
//student *s_head = NULL;

//学生登录
void StuLogin(int count)
{
	int j, k;
	ReadStudentDate();
	char stuID[10];
	char pass[10];
	printf("\n\t请输入学号:");
	scanf("%s", &stuID);
	printf("\t请输入密码:");
	for (j = 0; j <= 6; j++)
	{
		pass[j] = getch();
		if (pass[j] == '\r')
		{
			pass[j] = '\0';
		}
		if (j < 6)
		{
			printf("*");
		}
	}
	count++;
	student *p = s_head;
	while (NULL != p)
	{
		if (0 == strcmp(stuID, p->s_number) && 0 == strcmp(pass, p->s_password))
		{
			Index_S();
			break;
		}
		p = p->next;
	}
	if (NULL == p)
	{
		printf("\n\t账号与密码不匹配!\n");
		//		printf("\t输入错误次数：%d",count);
		if (count == 3)
		{
			printf("\t您的输入次数超过3次！\n");
			printf("\t退出登录程序!\n");
			system("pause");
			system("cls");
			return;
		}
		StuLogin(count);
		//count++;
	}
}

//学生端菜单
void Index_S()
{
	system("cls");
	printf("\n\n");
	char input;
	while (1)
	{
		Index_S_Index();
		input = getch();
		switch (input)
		{
		case '1':
			C_select();
			break;
		case '2':
			C_stuView();
			break;
		case '3':
			C_stufind();
			break;
		case '4':
			system("cls");
			return;
			break;
		case '5':
			exit(0);
		default:
			printf("输入错误，请重新输入:");
			system("pause");
			system("cls");
			break;
		}
	}
}

