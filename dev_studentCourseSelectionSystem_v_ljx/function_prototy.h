#include "struct.h"

/* main.c ���г���ģ�� */

void Run();   //�������п���

/* �˵�������ʾģ�� */ 

void Index();          //��ҳ����
void Index_M_Index();  //����˲˵�����
void Index_S_Index();  //ѧ���˲˵�����

/* ����Աҵ��ģ�� */

void AdminLogin(int);               //����Ա��¼
void Index_M();                     //����˲˵�
void Manage_Student();              //�����-ѧ������˵�
void Manage_Class();                //�����-�γ̹���˵�
void InsertAdministrator();         //�������Ա����
void InsertStudent();               //����ѧ������
void S_freeMemory();                //���ѧ����������
void M_freeMemory();                //��չ���Ա��������
void C_StuSelected();               //����ĳ�ſ�ѡ�ε�ѧ��ѧ��

/* ����Ա����ģ�� */

void view_s();                      //�鿴ѧ������
void C_add();                       //���ӿγ�
void C_view();                      //����γ�
void C_find();                      //���ҿγ�
void C_delete();                    //ɾ���γ�

/* ѧ��ҵ��ģ�� */

void StuLogin(int);   //ѧ����¼
void Index_S();       //ѧ���˲˵�


/* ѧ������ģ�� */

void C_select();      //ѧ��ѡ��
void C_stuView();     //ѧ������γ�
void C_stufind();     //���ҿγ�

/* �ļ�����ģ�� */

void ReadStudentDate();             //���ļ��ж�ȡѧ������
void SaveStudentDate();             //����ѧ�����ݵ��ļ�
void readC_data();                  //��ȡ�γ������ļ�
void saveC_data(course course_new); //����γ������ļ�
void SaveDate();                    //�������Ա����
void ReadDate();                    //��ȡ����Ա����
