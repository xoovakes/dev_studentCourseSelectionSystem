#include "struct.h"

/* main.c 运行程序模块 */

void Run();   //程序运行控制

/* 菜单界面显示模块 */ 

void Index();          //首页界面
void Index_M_Index();  //管理端菜单界面
void Index_S_Index();  //学生端菜单界面

/* 管理员业务模块 */

void AdminLogin(int);               //管理员登录
void Index_M();                     //管理端菜单
void Manage_Student();              //管理端-学生管理菜单
void Manage_Class();                //管理端-课程管理菜单
void InsertAdministrator();         //插入管理员数据
void InsertStudent();               //插入学生数据
void S_freeMemory();                //清空学生链表数据
void M_freeMemory();                //清空管理员链表数据
void C_StuSelected();               //查找某门课选课的学生学号

/* 管理员操作模块 */

void view_s();                      //查看学生数据
void C_add();                       //增加课程
void C_view();                      //浏览课程
void C_find();                      //查找课程
void C_delete();                    //删除课程

/* 学生业务模块 */

void StuLogin(int);   //学生登录
void Index_S();       //学生端菜单


/* 学生操作模块 */

void C_select();      //学生选课
void C_stuView();     //学生浏览课程
void C_stufind();     //查找课程

/* 文件操作模块 */

void ReadStudentDate();             //从文件中读取学生数据
void SaveStudentDate();             //保存学生数据到文件
void readC_data();                  //读取课程数据文件
void saveC_data(course course_new); //保存课程数据文件
void SaveDate();                    //保存管理员数据
void ReadDate();                    //读取管理员数据
