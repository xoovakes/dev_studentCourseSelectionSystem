/* 
    资源文件备注：
        manageDate.txt
        studentDate.txt
        course.dat
        c_selected.dat
*/

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
    int total_credit;    //已修学分
    char *next;          //用来建立链表
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

/* main.c 运行程序模块 */

void Index(); //首页界面
void Run();   //程序运行控制

/* manager_function.c 管理员模块 */

void Adminlogin();                  //管理员登录
void Index_M();                     //管理端菜单
void Index_M_Index();               //管理端菜单界面
void Manage_Student();              //管理端-学生管理菜单
void Manage_Class();                //管理端-课程管理菜单
void InsertAdministrator();         //插入管理员数据
void InsertStudent();               //插入学生数据
void ReadStudentDate();             //从文件中读取学生数据
void SaveStudentDate();             //保存学生数据到文件
void S_freeMemory();                //清空链表数据
void view_s();                      //查看学生数据
void C_add();                       //增加课程
void C_view();                      //浏览课程
void C_find();                      //查找课程
void C_delete();                    //删除课程
void C_StuSelected();               //查找某门课选课的学生学号
void readC_data();                  //读取课程数据文件
void saveC_data(course course_new); //保存课程数据文件
void SaveDate();                    //保存管理员数据
void ReadDate();                    //读取管理员数据

/* student_funtion 学生模块 */

void StuLodin();      //学生登录
void Index_S();       //学生端菜单
void Index_S_Index(); //学生端菜单界面
void C_select();      //学生选课
void C_stuView();     //学生浏览课程
void C_stufind();     //查找课程
