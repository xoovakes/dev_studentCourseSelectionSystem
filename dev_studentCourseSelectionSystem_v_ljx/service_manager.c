#include "function_prototy.h"


//����Ա��¼
void AdminLogin(int count)
{
	int j, k;
	char AdminID[10];
	char pass[10];
	ReadDate();
	printf("\n\t���������Ա�˺ţ�");
	scanf("%s", &AdminID);
	printf("\t�������������:");
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
		printf("\n\t�˺������벻ƥ��!\n");
		//printf("\t������������%d",count);
		if (count == 3)
		{
			printf("\t���������������3�Σ�\n");
			printf("\t�˳���¼����!\n");
			system("pause");
			system("cls");
			return;
		}
		AdminLogin(count);
		//count++;
	}
}

//����˲˵�
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
			printf("����������������룺\n");
			system("pause");
			system("cls");
			break;
		}
	}
}



//�����-ѧ������˵�
void Manage_Student()
{
	system("cls");
	printf("\n\n");
	char input;
	while (1)
	{
		printf("\t*************************************************************\n");
		printf("\t**      ������ѧԺѧ��ѡ��ϵͳ-����Ա��-ѧ������            **\n");
		printf("\t*************************************************************\n");
		printf("\t**                1.�½�ѧ���˺�                           **\n");
		printf("\t**                2.�鿴ѧ���˺�                           **\n");
		printf("\t**                3.�鿴ѡ��ѧ��                           **\n");
		printf("\t**                4.������ҳ                               **\n");
		printf("\t**                5.�˳�                                   **\n");
		printf("\t-------------------------------------------------------------\n");
		printf("\n\t������ѡ��:");
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
			printf("����������������룺\n");
			system("pause");
			system("cls");
			break;
		}
	}
}

//�����-�γ̹���˵�
void Manage_Class()
{
	system("cls");
	printf("\n\n");
	char input;
	while (1)
	{
		printf("\t*************************************************************\n");
		printf("\t**      ������ѧԺѧ��ѡ��ϵͳ-����Ա��-�γ̹���            **\n");
		printf("\t*************************************************************\n");
		printf("\t**                1.�����γ�                               **\n");
		printf("\t**                2.�鿴�γ�                               **\n");
		printf("\t**                3.���ҿγ�                               **\n");
		printf("\t**                4.ɾ���γ�                               **\n");
		printf("\t**                5.������ҳ                               **\n");
		printf("\t**                6.�˳�                                   **\n");
		printf("\t-------------------------------------------------------------\n");
		printf("\n\t������ѡ��:");
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
			printf("����������������룺\n");
			system("pause");
			system("cls");
			break;
		}
	}
}

//����ѧ������
void InsertStudent()
{
	ReadStudentDate();
	student *new_account = (student *)malloc(sizeof(student)); //ȥ�ڴ濪��һ��ռ�洢�µĽ��
	//������ͷ�巨������ʵ��
	if (NULL == s_head)
	{
		s_head = new_account;	  //��ͷ���ָ���²���Ľ��
		new_account->next = NULL; //���½�����һ�����ָ���
	}
	else
	{
		new_account->next = s_head;
		s_head = new_account;
	}
	printf("\n\t������ѧ��:");
	scanf("%s", &new_account->s_number);
	printf("\t���������룺");
	scanf("%s", &new_account->s_password);
	system("pause");
	system("cls");
	SaveStudentDate();
}

//���ѧ������
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

//��չ���Ա����
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

//�������Ա����
void InsertAdministrator()
{
	ReadDate();
	manager *new_account = (manager *)malloc(sizeof(manager)); //ȥ�ڴ濪��һ��ռ�洢�µĽ��
	//������ͷ�巨������ʵ��
	if (NULL == m_head)
	{
		m_head = new_account;	  //��ͷ���ָ���²���Ľ��
		new_account->next = NULL; //���½�����һ�����ָ���
	}
	else
	{
		new_account->next = m_head;
		m_head = new_account;
	}
	printf("���������Ա�˺ţ�\n");
	scanf("%s", &new_account->m_name);
	printf("���������룺\n");
	scanf("%s", &new_account->m_password);
	system("pause");
	system("cls");
	SaveDate();
}

//����ĳ�ſ�ѡ�ε�ѧ��ѧ��
void C_StuSelected()
{
	int c_num;
	int j, k;
	int flag = 0; //�����ҵ��γ̱�ű��
	readC_data();
	system("cls");
	printf("\t*************************************************************\n");
	printf("\t**    ������ѧԺѧ��ѡ��ϵͳ-����Ա��-�鿴ѡ��ѧ��         **\n");
	printf("\t*************************************************************\n");
	printf("\n\t������γ̱�ţ�");
	scanf("%d", &c_num);
	printf("\n");
	int count = 0; //������
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
		printf("����Ŀγ̱�Ų����ڣ�\n");
	}
	else
	{
		printf("\t\t�γ̱��\t\tѧ��\n");
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
				printf("\tû�пγ�����\n");
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
		printf("\tѡ�޿γ�������Ϊ:%d\n", count);
	}
	system("pause");
	system("cls");
}

