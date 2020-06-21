/* 
    ��Դ�ļ���ע��
        manageDate.txt
        studentDate.txt
        course.dat
        c_selected.dat
*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20   //����γ�����
#define MAX_S 30 //����ѡ����������
int i;           //i���ڿγ���������±�

typedef struct student //����ѧ���ṹ��
{
    char s_number[10];   //ѧ��
    char s_password[10]; //����
    int total_credit;    //����ѧ��
    char *next;          //������������
} student;
student *s_head;

typedef struct course //����γ̽ṹ��
{
    int c_num;       //�γ̱��
    char c_name[20]; //�γ�����
    int c_credit;    //�γ�ѧ��
    int c_selected;  //�γ���ѡ����
    int c_upper;     //�γ���������
} course;
course courses[MAX]; //����γ̽ṹ������

typedef struct c_selected //����γ���ѡ�洢�ṹ��
{
    int c_num;         //��Ӧ�γ̱��
    char s_number[10]; //��Ӧѧ��
} c_selected;
c_selected selected[1024];

typedef struct manager //�������Ա�ṹ��
{
    char m_name[10];     //����Ա�˺�
    char m_password[10]; //����Ա����
    char *next;          //������������
} manager;
manager *m_head;

/* main.c ���г���ģ�� */

void Index(); //��ҳ����
void Run();   //�������п���

/* manager_function.c ����Աģ�� */

void Adminlogin();                  //����Ա��¼
void Index_M();                     //����˲˵�
void Index_M_Index();               //����˲˵�����
void Manage_Student();              //�����-ѧ������˵�
void Manage_Class();                //�����-�γ̹���˵�
void InsertAdministrator();         //�������Ա����
void InsertStudent();               //����ѧ������
void ReadStudentDate();             //���ļ��ж�ȡѧ������
void SaveStudentDate();             //����ѧ�����ݵ��ļ�
void S_freeMemory();                //�����������
void view_s();                      //�鿴ѧ������
void C_add();                       //���ӿγ�
void C_view();                      //����γ�
void C_find();                      //���ҿγ�
void C_delete();                    //ɾ���γ�
void C_StuSelected();               //����ĳ�ſ�ѡ�ε�ѧ��ѧ��
void readC_data();                  //��ȡ�γ������ļ�
void saveC_data(course course_new); //����γ������ļ�
void SaveDate();                    //�������Ա����
void ReadDate();                    //��ȡ����Ա����

/* student_funtion ѧ��ģ�� */

void StuLodin();      //ѧ����¼
void Index_S();       //ѧ���˲˵�
void Index_S_Index(); //ѧ���˲˵�����
void C_select();      //ѧ��ѡ��
void C_stuView();     //ѧ������γ�
void C_stufind();     //���ҿγ�
