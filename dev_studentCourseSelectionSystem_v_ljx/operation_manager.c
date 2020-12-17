#include "function_prototy.h"

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

