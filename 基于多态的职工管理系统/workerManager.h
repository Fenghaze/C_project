#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#define  FILENAME "info.txt"
using namespace std;

/*
职工管理类，实现以下功能：
（1）菜单展示
（2）退出管理系统
（3）添加员工
（4）显示员工信息
（4）删除员工
（5）修改员工信息
（6）查找员工
（7）按照编号排序
（8）清空所有文档
*/
class WorkerManager
{
public:
	WorkerManager():workers_number(0){}

	//菜单展示
	void showMenu()
	{
		cout << "********************************************" << endl;
		cout << "*********  欢迎使用职工管理系统！ **********" << endl;
		cout << "*************  0.退出管理程序  *************" << endl;
		cout << "*************  1.增加职工信息  *************" << endl;
		cout << "*************  2.显示职工信息  *************" << endl;
		cout << "*************  3.删除离职职工  *************" << endl;
		cout << "*************  4.修改职工信息  *************" << endl;
		cout << "*************  5.查找职工信息  *************" << endl;
		cout << "*************  6.按照编号排序  *************" << endl;
		cout << "*************  7.清空所有文档  *************" << endl;
		cout << "********************************************" << endl;
		cout << endl;
	}
	//退出管理程序
	void exitSystem()
	{
		cout << "退出职工管理系统..." << endl;
		system("pause");
		exit(0);
	}
	//将员工添加到vector
	void add2vector(int id, string name, int dept)
	{
		Worker* worker = nullptr;
		switch (dept)
		{
		case 1://普通员工
			worker = new Employee(id, name, dept);
			break;
		case 2://经理
			worker = new Manager(id, name, dept);
			break;
		case 3://老板
			worker = new Boss(id, name, dept);
			break;
		default:
			break;
		}
		worker_lsts.push_back(worker);
	}
	//添加员工：使用一个数组保存员工信息，并将数据存储在文件中
	void addPerson()
	{
		cout << "输入需要添加的员工数量：";
		cin >> workers_number;
		int i = 0;
		int id;
		string name;
		int dept;
		while (workers_number> i)
		{
			cout << "输入第" << i+1 << "个员工的编号、姓名、岗位：" << endl;
			cin >> id >> name >> dept;
			add2vector(id, name, dept);
			i++;
		}
		cout << "成功添加" << workers_number << "个员工" << endl;
		saveInfo();
		system("pause");
		system("cls");
	}
	//保存员工信息
	void saveInfo()
	{
		cout << "保存信息到 " + string(FILENAME) << endl;
		ofstream ofs;
		//如果文件不存在，则创建一个新的文件
		if (!ofs.is_open())
		{
			this->workers_number = 0;	
			ofs.open(FILENAME, ios::out);

		}
		//如果文件存在，则追加
		else
		{
			ofs.open(FILENAME, ios::app);
		}
		for (auto worker : worker_lsts)
		{
			ofs << worker->m_Id << " "
				<< worker->m_Name << " "
				<< worker->m_Dept << endl;
		}
		ofs.close();
	}
	//读取文件，显示员工信息
	void showInfo()
	{
		ifstream ifs;
		ifs.open(FILENAME, ios::in);
		int id;
		string name;
		int dept;

		//文件不存在
		if (!ifs.is_open())
		{
			cout << "员工信息文件不存在，需要添加员工" << endl;
			this->workers_number = 0;
		}
		//文件存在，提取信息并保存在vector
		else
		{
			append = true;
			if (append)
			{
				worker_lsts.clear();
			}
			if (ifs.eof())
			{
				cout << "员工数为0，需要添加员工" << endl;
				ifs.close();
				return;
			}
			while (ifs >> id && ifs>>name && ifs>>dept)
			{
				add2vector(id, name, dept);
			}
			for (auto worker : worker_lsts)
			{
				worker->showInfo();
			}
		}
		ifs.close(); //关闭文件
		system("pause");
		system("cls");
	}

private:
	vector<Worker*> worker_lsts;	//员工信息
	int workers_number;		//员工人数
	bool append = false;
};