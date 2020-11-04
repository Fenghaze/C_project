#include "Admin.h"
#include<iostream>
#include<fstream>
#include"student.h"
#include"Teacher.h"
#include"globalfile.h"
#include<algorithm>
using namespace std;
Admin::Admin()
{

}

Admin::Admin(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	initVecotr();	//将文件信息保存到vector
}
//管理员菜单
void Admin::menu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： ";
}
//添加用户
void Admin::addUsers()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;
	string filename;
	string tip, errortip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		filename = STUDENT_FILE;
		tip = "请输入学号：";
		errortip = "学号重复，请重新输入";
		break;
	case 2:
		filename = TEACHER_FILE;
		tip = "请输入职工号:";
		errortip = "职工号重复，请重新输入：";
		break;
	default:
		break;
	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << errortip;
		}
		else
		{
			break;
		}
	}
	cout << "请输入用户名：";
	cin >> name;
	cout << "请输入密码：";
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功！" << endl;
	system("pause");
	system("cls");
	ofs.close();
	initVecotr();
}
//打印学生用户
void printStu(const Student& stu)
{
	cout << "学号：" << stu.m_Id << "\t";
	cout << "用户名：" << stu.m_Name << "\t";
	cout << "密码：" << stu.m_Pwd << endl;
}
//打印教师用户
void printTea(const Teacher& tea)
{
	cout << "职工号：" << tea.m_EmpId << "\t";
	cout << "用户名：" << tea.m_Name << "\t";
	cout << "密码：" << tea.m_Pwd << endl;
}
//显示用户
void Admin::showUsers()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;

	cin >> select;
	if (select == 1)
	{
		cout << "所有学生信息如下： " << endl;
		for_each(vStu.begin(), vStu.end(), printStu);
	}
	else
	{
		cout << "所有教师信息如下： " << endl;
		for_each(vTea.begin(), vTea.end(), printTea);
	}
	system("pause");
	system("cls");
}
//显示机房信息
void Admin::showComputers()
{
	cout << "机房信息如下：" << endl;
	for (auto item : vRoom)
	{
		cout << "机房编号：" << item.room_number << "\t";
		cout << "最大容量：" << item.maxnum << endl;
	}
	system("pause");
	system("cls");
}
//清空预约记录：清空预约记录文件 order.txt
void Admin::cleanOrder()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}

void Admin::initVecotr()
{
	//读取学生文件信息，并保存到vector中
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student stu;
	while (ifs >> stu.m_Id && ifs>>stu.m_Name && ifs>>stu.m_Pwd)
	{
		vStu.push_back(stu);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();

	//读取老师文件信息，并保存到vector中
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	Teacher teacher;
	while (ifs >> teacher.m_EmpId&& ifs >> teacher.m_Name&& ifs >> teacher.m_Pwd)
	{
		vTea.push_back(teacher);
	}
	cout << "当前老师数量为：" << vTea.size() << endl;
	ifs.close();

	//读取机房信息，并保存到vector
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.room_number && ifs >> c.maxnum)
	{
		vRoom.push_back(c);
	}
	cout << "当前机房数量为：" << vRoom.size() << endl;
	ifs.close();
}

bool Admin::checkRepeat(int id, int type)
{
	if (type == 1)	//学生
	{
		for (auto item : vStu)
		{
			if (id == item.m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (auto item : vTea)
		{
			if (id == item.m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}
