#include "manage.h"
student *s_head = NULL;

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
		case '5':
			exit(0);
		default:
			printf("�����������������:");
			break;
		}
	}
}

//ѧ���˲˵�����
void Index_S_Index()
{
	printf("\n");
	printf("\t*************************************************************\n");
	printf("\t**             ������ѧԺѧ��ѡ��ϵͳ-ѧ����               **\n");
	printf("\t*************************************************************\n");
	printf("\t                    1.ѧ��ѡ��                               \n");
	printf("\t                    2.�γ����                               \n");
	printf("\t                    3.�γ̲�ѯ                               \n");
	printf("\t                    4.������ҳ                               \n");
	printf("\t                    5.�˳�                                   \n");
	printf("\t-------------------------------------------------------------\n");
	printf("����������ѡ��:");
}

//ѧ��ѡ��
void C_select()
{
	char s_num[10];		 //ѧ��ѧ��
	char s_password[10]; //����
	int c_num;			 //�γ̺�
	int flag = 0;		 //�Ƿ��ҵ��γ̱�ŵı��
	char c_name[MAX];	 //�γ�����
	int j;
	student *p = s_head;
	system("cls");
	printf("\t*************************************************************\n");
	printf("\t**    ������ѧԺѧ��ѡ��ϵͳ-ѧ����-ѡ�γ�               **\n");
	printf("\t*************************************************************\n");
	readC_data();
	printf("\tid          name        credit        selected           upper\n");
	printf("\t=============================================================\n");
	for (j = 0; j < i; j++)
	{
		printf("\t%-10d  %-10s  %-13d  %-16d  %-10d\n", courses[j].c_num, courses[j].c_name, courses[j].c_credit, courses[j].c_selected, courses[j].c_upper);
	}
	printf("\t=============================================================\n");
	printf("\t������ѧ�ţ�");
	scanf("%s", &s_num);
	printf("\t����������:");
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
			for (j = 0; j < i; j++)
			{
				if (p->total_credit + courses[j].c_credit > 60)
				{
					printf("ѧ�ֽ���������");
					return;
				}
				if (courses[j].c_num == c_num && courses[j].c_selected < courses[j].c_upper)
				{
					courses[j].c_selected++;
					//��д�γ��ļ�
					//������д��γ������ļ�
					FILE *fp = fopen("course.dat", "w");

					int k;
					if ((NULL == fp))
					{
						return;
					}
					else
					{
						//	fwrite(&course_new,sizeof(course),1,f);
						for (k = 0; k < i; k++)
						{
							//				        	printf("%d,%s,%d,%d,%d\n",courses[k].c_num,courses[k].c_name,courses[k].c_credit,courses[k].c_selected,courses[k].c_upper);
							fprintf(fp, "%d,%s,%d,%d,%d\n", courses[k].c_num, courses[k].c_name, courses[k].c_credit, courses[k].c_selected, courses[k].c_upper);
							p->total_credit += courses[k].c_credit;
						}
					}
					fclose(fp);
					FILE *f = fopen("c_selected.dat", "a");
					if (NULL == f)
					{
						printf("");
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
				printf("�ÿγ̲����ڣ�\n");
				break;
			}
			break;
		}
		p = p->next;
	}
	if (NULL == p)
	{
		printf("ѧ�Ż������������");
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
		printf("\t                    3.�˳�                                   \n");
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
