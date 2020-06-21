#include "m.h"
manager *m_head = NULL;
int count = 0; //�����ۼƹ���Ա��¼�������

//����Ա��¼
void Adminlogin()
{
	int j, k;
	char name[10];
	char password[10];
	char pass[10];
	printf("\n\t���������Ա�˺ţ�");
	scanf("%s", &name);
	printf("\t�������������:");
	//	scanf("%s",&password);
	for (j = 0; j <= 6; j++)
	{
		pass[j] = getch();
		if (pass[j] == '\r')
		{
			pass[j] = '\0';
		}
		if (j < 5)
		{
			printf("*");
		}
	}
	for (k = 0; k < 6; k++)
	{
		password[k] = pass[k];
	}
	count++;
	if (0 == strcmp("admin", name) && 0 == strcmp("admin", password))
	{
		Index_M();
	}
	else
	{
		printf("\n\t�˺������벻ƥ��!\n");
		if (count == 3)
		{
			printf("\t���������������3�Σ�\n");
			printf("\t�˳���¼����!\n");
			system("pause");
			system("cls");
			return;
		}
		Adminlogin();
		// count++;
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
			break;
		}
	}
}

//����˲˵�����
void Index_M_Index()
{
	printf("\t*************************************************************\n");
	printf("\t**            ������ѧԺѧ��ѡ��ϵͳ-����Ա��              **\n");
	printf("\t*************************************************************\n");
	printf("\t**                1.ѧ������                               **\n");
	printf("\t**                2.�γ̹���                               **\n");
	printf("\t**                3.������ҳ                               **\n");
	printf("\t**                4.�˳�                                   **\n");
	printf("\t-------------------------------------------------------------\n");
	printf("\n\t������ѡ��:");
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
		printf("\t**                1.��ʼ��ѧ���˺�                         **\n");
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
		Index_M_Index();
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

//���ļ��ж�ȡѧ��������β�巨�Ľṹ�γ�����
void ReadStudentDate()
{
	FILE *fp = fopen("studentDate.txt", "r");
	student *p = s_head;
	if (NULL == fp)
	{
		return;
	}
	else
	{
		S_freeMemory();
		char ch;
		rewind(fp);
		ch = fgetc(fp);
		if (ch == EOF)
		{
			//			printf("û������!\n");
			fclose(fp);
		}
		else
		{
			rewind(fp);
			while (!feof(fp))
			{
				student *node = (student *)malloc(sizeof(student));
				if (NULL == s_head)
				{
					s_head = node;
					p = s_head;
					p->next = NULL;
				}
				else
				{
					p->next = node;
					p = p->next;
					p->next = NULL;
				}
				fscanf(fp, "%[^,],%s\n", &node->s_number, &node->s_password);
			}
			fclose(fp);
		}
	}
}

//���ѧ������
void S_freeMemory()
{
	student *p;
	p = s_head;
	while (NULL != p)
	{
		free(s_head);
		p = p->next;
		s_head = p;
	}
}

//����ѧ������
void SaveStudentDate()
{
	student *p = s_head;
	FILE *fp = fopen("studentDate.txt", "w");
	if (NULL == fp)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return;
	}
	else
	{
		while (NULL != p)
		{
			fprintf(fp, "%s,%s\n", p->s_number, p->s_password);
			p = p->next;
		}
		fclose(fp);
	}
}

//�鿴ѧ������
void view_s()
{
	ReadStudentDate();
	student *q = s_head;
	system("cls");
	printf("\t*************************************************************\n");
	printf("\t**    ������ѧԺѧ��ѡ��ϵͳ-����Ա��-�鿴ѧ���˺�         **\n");
	printf("\t*************************************************************\n");
	printf("\t\t\tѧ��ѧ��\t\tѧ������\n");
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

//�������Ա����
// void InsertAdministrator()
// {
// 	//	ReadDate();
// 	manager *new_account = (manager *)malloc(sizeof(manager)); //ȥ�ڴ濪��һ��ռ�洢�µĽ��
// 	//������ͷ�巨������ʵ��
// 	if (NULL == m_head)
// 	{
// 		m_head = new_account;	  //��ͷ���ָ���²���Ľ��
// 		new_account->next = NULL; //���½�����һ�����ָ���
// 	}
// 	else
// 	{
// 		new_account->next = m_head;
// 		m_head = new_account;
// 	}
// 	printf("���������Ա�˺ţ�\n");
// 	scanf("%s", &new_account->m_name);
// 	printf("���������룺\n");
// 	scanf("%s", &new_account->m_password);
// 	system("pause");
// 	system("cls");
// 	SaveDate();
// }

//�������Ա����
void SaveDate()
{
	manager *p = m_head;
	FILE *fp = fopen("manageDate.txt", "w");
	if (NULL == fp)
	{
		//		printf("���ļ�ʧ�ܣ�\n");
		return;
	}
	else
	{
		while (NULL != p)
		{
			fprintf(fp, "%s\t%s\n", p->m_name, p->m_password);
			p = p->next;
		}
		fclose(fp);
	}
}

//���ӿγ�
void C_add()
{
	system("cls");
	course course_new;
	int j;		  //�������������±�
	int flag = 0; //�����������ĺϷ���
	printf("\n");
	printf("\t*************************************************************\n");
	printf("\t**    ������ѧԺѧ��ѡ��ϵͳ-����Ա��-���ӿγ�             **\n");
	printf("\t*************************************************************\n");
	printf("\n\t������γ���Ϣ");
	printf("\n\t1.�γ̱��:");
	scanf("%d", &course_new.c_num);
	printf("\t2.�γ�����:");
	scanf("%s", course_new.c_name);
	printf("\t3.�γ�ѧ��:");
	scanf("%d", &course_new.c_credit);
	printf("\t4.�γ���ѡ����:");
	scanf("%d", &course_new.c_selected);
	printf("\t5.�γ���������:");
	scanf("%d", &course_new.c_upper);
	printf("\n");
	readC_data();
	//�ж���¼��Ŀγ̱�Ż�γ������Ƿ����
	for (j = 0; j < i; j++)
	{
		if (course_new.c_num == courses[j].c_num || 0 == strcmp(course_new.c_name, courses[j].c_name))
		{
			printf("\n\t�Բ��𣬱�Ż��߿γ������Ѿ�����!\n");
			flag = 1; //����Ƿ����
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

//��ȡ�γ������ļ�
void readC_data()
{
	i = 0; //�������������±�
	//�򿪿γ������ļ�
	FILE *fp = fopen("course.dat", "r");
	memset(&courses, 0, sizeof(courses)); //���ṹ�������е���������
	if (NULL == fp)
	{
		printf("openfile error!\n");
	}
	else
	{
		rewind(fp);
		char ch = getc(fp);
		if (ch == EOF)
		{
			//			printf("û�пγ�����!\n");
			printf("");
		}
		else
		{
			rewind(fp);
			while (!feof(fp))
			{
				//fread(&courses[i],sizeof(course),1,fp);
				fscanf(fp, "%d,%[^,],%d,%d,%d\n", &courses[i].c_num, &courses[i].c_name, &courses[i].c_credit, &courses[i].c_selected, &courses[i].c_upper);
				i = i + 1;
				//printf("%d,%s,%d,%d,%d\n",courses[i].c_num,courses[i].c_name,courses[i].c_credit,courses[i].c_selected,courses[i].c_selected,courses[i].c_upper);
			}
		}
		fclose(fp);
	}
}

//����γ������ļ�
void saveC_data(course course_new)
{
	//������д��γ������ļ�
	FILE *f = fopen("course.dat", "a");
	int j;
	if ((NULL == f))
	{
		return;
	}
	else
	{
		//	fwrite(&course_new,sizeof(course),1,f);
		fprintf(f, "%d,%s,%d,%d,%d\n", course_new.c_num, course_new.c_name, course_new.c_credit, course_new.c_selected, course_new.c_upper);
		fclose(f);
	}
}

//�鿴�γ�ģ��
void C_view()
{
	int j;
	readC_data();
	system("cls");
	printf("\n");
	printf("\t*************************************************************\n");
	printf("\t**    ������ѧԺѧ��ѡ��ϵͳ-����Ա��-�鿴�γ�             **\n");
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

//ɾ���γ�ģ��
void C_delete()
{
	int c_num;
	int j, n, k, flag = 0;
	printf("\n");
	printf("\t*************************************************************\n");
	printf("\t**    ������ѧԺѧ��ѡ��ϵͳ-����Ա��-ɾ���γ�             **\n");
	printf("\t*************************************************************\n");
	printf("\t������Ҫɾ���Ŀγ̱��:");
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
		printf("�γ̱�Ų����ڣ�\n");
		C_delete();
	}
	system("pause");
	system("cls");
}

//���ҿγ�
void C_find()
{
	readC_data();
	char choice;
	int c_num;
	char c_name[MAX];
	int j; //����ѭ���п��������±�
	printf("\n");
	system("cls");
	while (1)
	{
		int flag1 = 0; //�ж���ѧ�Ų�ѯ�ҵ����
		int flag2 = 0; //�ж��Կγ������ҵ����
		printf("\t*************************************************************\n");
		printf("\t**    ������ѧԺѧ��ѡ��ϵͳ-����Ա��-���ҿγ�             **\n");
		printf("\t*************************************************************\n");
		printf("\t1.�γ̱�Ų�ѯ\n");
		printf("\t2.�γ����Ʋ�ѯ:\n");
		printf("\t3.�˳�:\n");
		printf("\t����ѡ��");
		choice = getch();
		switch (choice)
		{
		case '1':
			printf("\n\t������γ̱��:");
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
				printf("û���ҵ���ؿγ̣�\n");
				system("pause");
				system("cls");
				break;
			}
			break;
		case '2':
			printf("\n\t������γ�����:");
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
				printf("û���ҵ���ؿγ̣�\n");
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
			printf("�������������ѡ��!\n");
			system("pause");
			system("cls");
			break;
		}
	}
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
				printf("");
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
