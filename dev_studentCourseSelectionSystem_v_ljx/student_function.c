#include "function_prototy.h"
//student *s_head = NULL;

//ѧ��ѡ��
void C_select()
{
	char s_num[10];		 //ѧ��ѧ��
	char s_password[10]; //����
	int c_num;			 //�γ̺�
	int flag = 0;		 //�Ƿ��ҵ��γ̱�ŵı��
	char c_name[MAX];	 //�γ�����
	int total_credit;	 //����ѧ��
	int j,b;
	student *p = s_head;
	system("cls");
	printf("\t*************************************************************\n");
	printf("\t**    ������ѧԺѧ��ѡ��ϵͳ-ѧ����-ѡ��γ�               **\n");
	printf("\t*************************************************************\n");
	readC_data();
	printf("\tid          name        credit        selected           upper\n");
	printf("\t=============================================================\n");
	for (j = 0; j < i; j++)
	{
		printf("\t%-10d  %-10s  %-13d  %-16d  %-10d\n", courses[j].c_num, courses[j].c_name, courses[j].c_credit, courses[j].c_selected, courses[j].c_upper);
	}
	printf("\t=============================================================\n");
	printf("\tȷ��ѧ�ţ�");
	scanf("%s", &s_num);
	printf("\tȷ������:");
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
			printf("\t������γ̱��:");
			scanf("%d", &c_num);

			/* �鿴ѧ��ѡ���� */
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
					printf("\tû�пγ�����\n");
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

			/* ͳ�Ƹ�ͬѧ��ѧ�֣�����������ظ� */
			total_credit = 0;
			for (j = 0; j < ii; j++)
			{
				if (strcmp(s_num, selected[j].s_number) == 0) //selected����ѧ��ѡ���Ŀ�
				{
					if (c_num == selected[j].c_num) //����ѡ�Ŀ�֮ǰѡ����
					{
						printf("\t���ſ���ѡ����!\n");
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
				printf("\t��ѡ����ѧ�ֳ�����60!\n");
				system("pause");
				system("cls");
				return;
			}
			printf("ѡ�γɹ���\n");

			for (j = 0; j < i; j++)
			{
				if (courses[j].c_num == c_num && courses[j].c_selected < courses[j].c_upper)
				{
					courses[j].c_selected++;
					//��д�γ��ļ�
					//������д��γ������ļ�
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
				printf("\t�ÿγ̲����ڣ�\n");
				break;
			}
			break;
		}
		p = p->next;
	}
	if (NULL == p)
	{
		printf("\tѧ�Ż������������");
	}
	system("pause");
	system("cls");
}

//ѧ������γ�
void C_stuView()
{
	int j;
	readC_data();
	system("cls");
	printf("\n");
	printf("\t*************************************************************\n");
	printf("\t**    ������ѧԺѧ��ѡ��ϵͳ-ѧ����-�鿴�γ�               **\n");
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

//ѧ�����ҿγ�
void C_stufind()
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
		printf("\t**    ������ѧԺѧ��ѡ��ϵͳ-ѧ����-���ҿγ�             **\n");
		printf("\t*************************************************************\n");
		printf("\t                    1.�γ̱�Ų�ѯ                           \n");
		printf("\t                    2.�γ����Ʋ�ѯ                           \n");
		printf("\t                    3.����                                   \n");
		printf("\t-------------------------------------------------------------\n");
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

