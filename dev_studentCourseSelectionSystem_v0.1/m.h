#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h> 
#define MAX 20//����γ����� 
#define MAX_S 30//����ѡ���������� 
int i;//���ڿγ���������±� 
 //����ѧ���ṹ��
typedef struct student
{
 char s_number[10];//ѧ�� 
 char s_password[10];//���� 
 char *next;//������������ 
}student;
student *s_head;
//����γ̽ṹ��
typedef struct course
{
    int c_num;//�γ̱�� 
    char c_name[20];//�γ����� 
    int c_credit;//�γ�ѧ�� 
    int c_selected;//�γ���ѡ����
    int c_upper;//�γ���������
}course;
course courses[MAX];//����γ̽ṹ������ 
//����ѡ�νṹ�� 
typedef struct c_selected
{
	int c_num;
	char s_number[10];
}c_selected;
c_selected selected[1024];
//�������Ա�ṹ�� 
typedef struct manager
{
 char m_name[10];//����Ա�˺� 
 char m_password[10];//����Ա���� 
 char *next;//������������ 
}manager;
manager *m_head;
//����ѧ��ѡ������ 
typedef struct s_selected
{
	char s_number[10];
	int c_num;
	int total_credit;
}s_selected;
s_selected s_select[1024];

//���º���Ϊ�����г���ģ�� 
void Index();//��ҳ���� 
void Run();//�������п��� 
//���º���Ϊ����Աģ�� 
void Adminlogin();//����Ա��¼ 
void Index_M();//����������� 
void InsertAdministrator();//�������Ա���� 
void InsertStudent();//����ѧ������ 
void ReadStudentDate();//���ļ��ж�ȡѧ������ 
void SaveStudentDate();//����ѧ�����ݵ��ļ� 
void S_freeMemory();//����������� 
void view_s();//�鿴ѧ������ 
void C_add();//���ӿγ�
void C_view();//����γ� 
void C_find();//���ҿγ� 
void C_delete();//ɾ���γ� 
void C_StuSelected();//����ĳ�ſ�ѡ�ε�ѧ��ѧ�� 
void readC_data();//��ȡ�γ������ļ�
void saveC_data(course course_new);//����γ������ļ� 
//void SaveDate();
//void ReadDate();
//���º���Ϊѧ��ģ�� 
void StuLodin();//ѧ����¼ 
void Index_S();//ѧ����¼�˵� 
void C_select();//ѧ��ѡ�� 
void C_stuView();//ѧ������γ� 
void C_stufind();//���ҿγ� 
