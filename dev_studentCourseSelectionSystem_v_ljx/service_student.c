#include "function_prototy.h"
//student *s_head = NULL;

//ѧ����¼
void StuLogin(int count)
{
	int j, k;
	ReadStudentDate();
	char stuID[10];
	char pass[10];
	printf("\n\t������ѧ��:");
	scanf("%s", &stuID);
	printf("\t����������:");
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
		printf("\n\t�˺������벻ƥ��!\n");
		//		printf("\t������������%d",count);
		if (count == 3)
		{
			printf("\t���������������3�Σ�\n");
			printf("\t�˳���¼����!\n");
			system("pause");
			system("cls");
			return;
		}
		StuLogin(count);
		//count++;
	}
}

//ѧ���˲˵�
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
			printf("�����������������:");
			system("pause");
			system("cls");
			break;
		}
	}
}

