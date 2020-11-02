#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"workerManager.h"
using namespace std;

//测试职工类
void test01()
{
	Worker* worker1 = new Employee(1, "Mary", 3);
	worker1->showInfo();
	Worker* worker2 = new Boss(3, "Bob", 3);
	worker2->showInfo();
}

//测试菜单功能
void test02()
{
	WorkerManager manager;
	manager.showMenu();
}

int main()
{
	WorkerManager wm;
	int choice = 0;
	while (1)
	{
		wm.showMenu();
		cout << "请输入编号：";
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			wm.exitSystem();
			break;
		case 1://添加员工
			wm.addPerson();
			break;
		case 2://显示员工信息
			wm.showInfo();
			break;
		case 3://删除员工
			break;
		case 4://修改员工信息
			break;
		case 5://查找员工
			break;
		case 6://排序
			break;
		case 7://清空文件
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}