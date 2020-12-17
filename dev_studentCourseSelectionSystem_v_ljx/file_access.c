#include "struct.h"

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
			printf("û�пγ�����!\n");
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

//�������Ա����
void SaveDate()
{
	manager *p = m_head;
	FILE *fp = fopen("manageDate.dat", "w");
	if (NULL == fp)
	{
		printf("���ļ�ʧ�ܣ�\n");
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

//��ȡ����Ա����
void ReadDate()
{
	manager *p = m_head;
	FILE *fp = fopen("manageDate.dat", "r");
	if (NULL == fp)
	{
		printf("openfile error!\n");
	}
	else
	{
		M_freeMemory();
		rewind(fp);
		char ch = getc(fp);
		if (ch == EOF)
		{
			printf("û�й���Ա����!\n");
		}
		else
		{
			rewind(fp);
			while (!feof(fp))
			{
				manager *node = (manager *)malloc(sizeof(manager));
				if (NULL == m_head)
				{
					m_head = node;
					p = m_head;
					p->next = NULL;
				}
				else
				{
					p->next = node;
					p = p->next;
					p->next = NULL;
				}
				//fread(&courses[i],sizeof(course),1,fp);
				fscanf(fp, "%s\t%s\n", &node->m_name, &node->m_password);
				//printf("%d,%s,%d,%d,%d\n",courses[i].c_num,courses[i].c_name,courses[i].c_credit,courses[i].c_selected,courses[i].c_selected,courses[i].c_upper);
			}
		}
		fclose(fp);
	}
}

//���ļ��ж�ȡѧ��������β�巨�Ľṹ�γ�����
void ReadStudentDate()
{
	FILE *fp = fopen("studentDate.dat", "r");
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
			printf("û������!\n");
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

//����ѧ������
void SaveStudentDate()
{
	student *p = s_head;
	FILE *fp = fopen("studentDate.dat", "w");
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
