/*
   ѧ��ѡ��ϵͳ
*/
#include "function_prototy.h"

int main()
{
	Run();
	system("pause");
	return 0;
}

//�����������
void Run()
{
	char input;
	int count = 0; //��¼�������
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
			printf("\t����������������룡\n");
			system("pause");
			system("cls");
			break;
		}
	}
	system("cls");
}
