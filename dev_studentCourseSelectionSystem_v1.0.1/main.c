/*
   ѧ��ѡ��ϵͳ
*/
#include "manage.h"

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

//��ҳ����
void Index()
{
	printf("\n\n");
	printf("\t*************************************************************\n");
	printf("\t**                  ������ѧԺѧ��ѡ��ϵͳ-��ҳ            **\n");
	printf("\t*************************************************************\n");
	printf("\t**                1.ѧ����¼                               **\n");
	printf("\t**                2.����Ա��¼                             **\n");
	printf("\t**                3.�˳�ϵͳ                               **\n");
	printf("\t-------------------------------------------------------------\n");
	printf("\t��ѡ��������:");
}

