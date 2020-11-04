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
	initVecotr();	//���ļ���Ϣ���浽vector
}
//����Ա�˵�
void Admin::menu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� ";
}
//����û�
void Admin::addUsers()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;
	string filename;
	string tip, errortip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	switch (select)
	{
	case 1:
		filename = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errortip = "ѧ���ظ�������������";
		break;
	case 2:
		filename = TEACHER_FILE;
		tip = "������ְ����:";
		errortip = "ְ�����ظ������������룺";
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
	cout << "�������û�����";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;
	system("pause");
	system("cls");
	ofs.close();
	initVecotr();
}
//��ӡѧ���û�
void printStu(const Student& stu)
{
	cout << "ѧ�ţ�" << stu.m_Id << "\t";
	cout << "�û�����" << stu.m_Name << "\t";
	cout << "���룺" << stu.m_Pwd << endl;
}
//��ӡ��ʦ�û�
void printTea(const Teacher& tea)
{
	cout << "ְ���ţ�" << tea.m_EmpId << "\t";
	cout << "�û�����" << tea.m_Name << "\t";
	cout << "���룺" << tea.m_Pwd << endl;
}
//��ʾ�û�
void Admin::showUsers()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select = 0;

	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£� " << endl;
		for_each(vStu.begin(), vStu.end(), printStu);
	}
	else
	{
		cout << "���н�ʦ��Ϣ���£� " << endl;
		for_each(vTea.begin(), vTea.end(), printTea);
	}
	system("pause");
	system("cls");
}
//��ʾ������Ϣ
void Admin::showComputers()
{
	cout << "������Ϣ���£�" << endl;
	for (auto item : vRoom)
	{
		cout << "������ţ�" << item.room_number << "\t";
		cout << "���������" << item.maxnum << endl;
	}
	system("pause");
	system("cls");
}
//���ԤԼ��¼�����ԤԼ��¼�ļ� order.txt
void Admin::cleanOrder()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

void Admin::initVecotr()
{
	//��ȡѧ���ļ���Ϣ�������浽vector��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student stu;
	while (ifs >> stu.m_Id && ifs>>stu.m_Name && ifs>>stu.m_Pwd)
	{
		vStu.push_back(stu);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ�ļ���Ϣ�������浽vector��
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Teacher teacher;
	while (ifs >> teacher.m_EmpId&& ifs >> teacher.m_Name&& ifs >> teacher.m_Pwd)
	{
		vTea.push_back(teacher);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();

	//��ȡ������Ϣ�������浽vector
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}
	ComputerRoom c;
	while (ifs >> c.room_number && ifs >> c.maxnum)
	{
		vRoom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vRoom.size() << endl;
	ifs.close();
}

bool Admin::checkRepeat(int id, int type)
{
	if (type == 1)	//ѧ��
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
