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
    char *next;          //������������
    // int total_credit;    //����ѧ��
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
