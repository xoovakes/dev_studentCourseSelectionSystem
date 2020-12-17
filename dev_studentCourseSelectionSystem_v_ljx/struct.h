#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20   //定义课程总数
#define MAX_S 30 //定义选课人数上限
int i;           //i用于课程数的最大下标

typedef struct student //定义学生结构体
{
    char s_number[10];   //学号
    char s_password[10]; //密码
    char *next;          //用来建立链表
    // int total_credit;    //已修学分
} student;
student *s_head;

typedef struct course //定义课程结构体
{
    int c_num;       //课程编号
    char c_name[20]; //课程名称
    int c_credit;    //课程学分
    int c_selected;  //课程已选人数
    int c_upper;     //课程人数上限
} course;
course courses[MAX]; //定义课程结构体数组

typedef struct c_selected //定义课程已选存储结构体
{
    int c_num;         //对应课程编号
    char s_number[10]; //对应学号
} c_selected;
c_selected selected[1024];

typedef struct manager //定义管理员结构体
{
    char m_name[10];     //管理员账号
    char m_password[10]; //管理员密码
    char *next;          //用来建立链表
} manager;
manager *m_head;
