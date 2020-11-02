#include<iostream>
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include"workerManager.h"
using namespace std;

//����ְ����
void test01()
{
	Worker* worker1 = new Employee(1, "Mary", 3);
	worker1->showInfo();
	Worker* worker2 = new Boss(3, "Bob", 3);
	worker2->showInfo();
}

//���Բ˵�����
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
		cout << "�������ţ�";
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1://���Ա��
			wm.addPerson();
			break;
		case 2://��ʾԱ����Ϣ
			wm.showInfo();
			break;
		default:
			system("cls");
			break;
		}
	}
	return 0;
}