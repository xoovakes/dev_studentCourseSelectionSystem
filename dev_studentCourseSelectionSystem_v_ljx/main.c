/*
   学生选课系统
*/
#include "function_prototy.h"

int main()
{
	Run();
	system("pause");
	return 0;
}

//程序整体控制
void Run()
{
	char input;
	int count = 0; //记录错误次数
	while (1)
	{
		Index();
		input = getch();
		switch (input)
		{
		case '1':
			StuLogin(count);
			break;
		case '2':
			AdminLogin(count);
			break;
		case '3':
			exit(0);
		default:
			printf("\t输入错误，请重新输入！\n");
			system("pause");
			system("cls");
			break;
		}
	}
	system("cls");
}
