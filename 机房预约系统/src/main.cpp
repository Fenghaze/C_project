#include<iostream>
#include"globalfile.h"
#include"itentity.h"
#include"student.h"
#include"Teacher.h"
#include"Admin.h"
#include<fstream>
using namespace std;

//管理员菜单
void adminMenu(Identity*& person)	
{
	while (true)
	{
		person->menu();		//多态的实现，父类指针or引用去调用虚函数
		Admin* admin = (Admin*)person;	//强转为Admin类型
		int choice=0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "添加账号" << endl;
			admin->addUsers();
			break;
		case 2:
			cout << "查看账号" << endl;
			admin->showUsers();
			break;
		case 3:
			cout << "查看机房" << endl;
			admin->showComputers();
			break;
		case 4:
			cout << "清空预约" << endl;
			admin->cleanOrder();
			break;
		case 0:
			delete admin;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

//学生菜单
void studentMenu(Identity *&person)
{	
	while (true)
	{
		person->menu();
		Student* stu = (Student*)person;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "申请预约" << endl;
			stu->applyOrder();
			break;
		case 2:
			cout << "查看我的预约" << endl;
			stu->showMyOrder();
			break;
		case 3:
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
			break;
		case 4:
			cout << "取消预约" << endl;
			stu->cancelOrder();
			break;
		case 0:
			delete stu;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

//教师菜单
void teacherMenu(Identity*& person)
{
	while (true)
	{
		person->menu();
		Teacher* stu = (Teacher*)person;
		int choice = 0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
			break;
		case 2:
			cout << "审核预约" << endl;
			stu->validOrder();
			break;
		case 0:
			delete stu;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

//首页登录验证函数
void login(string filename, int type)
{
	Identity* person = nullptr;
	ifstream ifs;
	ifs.open(filename, ios::in);	//读取文件
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id;			//编号
	string name;	//姓名
	string pwd;		//密码
	if (type == 1)	//学生
	{
		cout << "输入学号：";
		cin >> id;
	}
	else if(type==2)//教师
	{
		cout << "输入职工号：";
		cin >> id;
	}
	cout << "请输入用户名:";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;

	//登录验证
	if (type==1)
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid, ifs >> fname, ifs>> fpwd)
		{
			if (fid ==id && fname ==name && fpwd ==pwd)
			{
				cout << "学生登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type==2)
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid, ifs >> fname, ifs >> fpwd)
		{
			if (fid == id && fname == name && fpwd == pwd)
			{
				cout << "教师登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师菜单
				teacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3)
	{
		string fname;
		string fpwd;
		while (ifs >> fname, ifs >> fpwd)
		{
			if (fname == name && fpwd == pwd)
			{
				cout << "管理员登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Admin(name, pwd);
				//进入管理员菜单
				adminMenu(person);
				return;
			}
		}
	}
	cout << "用户名或密码错误" << endl;
	system("pause");
	system("cls");
	return;
}

int main(int argc, char** argv)
{
	int select = 0;
	while (true)
	{
		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 1://student
			login(STUDENT_FILE, 1);
			break;
		case 2://teacher
			login(TEACHER_FILE, 2);
			break;
		case 3://admin
			login(ADMIN_FILE, 3);
			break;
		case 0://exit
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}
