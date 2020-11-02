#pragma once
#include<iostream>
#include<string>
#include<vector>
#include <fstream>
#define  FILENAME "info.txt"
using namespace std;

/*
ְ�������࣬ʵ�����¹��ܣ�
��1���˵�չʾ
��2���˳�����ϵͳ
��3�����Ա��
��4����ʾԱ����Ϣ
��4��ɾ��Ա��
��5���޸�Ա����Ϣ
��6������Ա��
��7�����ձ������
��8����������ĵ�
*/
class WorkerManager
{
public:
	WorkerManager():workers_number(0){}

	//�˵�չʾ
	void showMenu()
	{
		cout << "********************************************" << endl;
		cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
		cout << "*************  0.�˳��������  *************" << endl;
		cout << "*************  1.����ְ����Ϣ  *************" << endl;
		cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
		cout << "*************  3.ɾ����ְְ��  *************" << endl;
		cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
		cout << "*************  5.����ְ����Ϣ  *************" << endl;
		cout << "*************  6.���ձ������  *************" << endl;
		cout << "*************  7.��������ĵ�  *************" << endl;
		cout << "********************************************" << endl;
		cout << endl;
	}
	//�˳��������
	void exitSystem()
	{
		cout << "�˳�ְ������ϵͳ..." << endl;
		system("pause");
		exit(0);
	}
	//��Ա����ӵ�vector
	void add2vector(int id, string name, int dept)
	{
		Worker* worker = nullptr;
		switch (dept)
		{
		case 1://��ͨԱ��
			worker = new Employee(id, name, dept);
			break;
		case 2://����
			worker = new Manager(id, name, dept);
			break;
		case 3://�ϰ�
			worker = new Boss(id, name, dept);
			break;
		default:
			break;
		}
		worker_lsts.push_back(worker);
	}
	//���Ա����ʹ��һ�����鱣��Ա����Ϣ���������ݴ洢���ļ���
	void addPerson()
	{
		cout << "������Ҫ��ӵ�Ա��������";
		cin >> workers_number;
		int i = 0;
		int id;
		string name;
		int dept;
		while (workers_number> i)
		{
			cout << "�����" << i+1 << "��Ա���ı�š���������λ��" << endl;
			cin >> id >> name >> dept;
			add2vector(id, name, dept);
			i++;
		}
		cout << "�ɹ����" << workers_number << "��Ա��" << endl;
		saveInfo();
		system("pause");
		system("cls");
	}
	//����Ա����Ϣ
	void saveInfo()
	{
		cout << "������Ϣ�� " + string(FILENAME) << endl;
		ofstream ofs;
		//����ļ������ڣ��򴴽�һ���µ��ļ�
		if (!ofs.is_open())
		{
			this->workers_number = 0;	
			ofs.open(FILENAME, ios::out);

		}
		//����ļ����ڣ���׷��
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
	//��ȡ�ļ�����ʾԱ����Ϣ
	void showInfo()
	{
		ifstream ifs;
		ifs.open(FILENAME, ios::in);
		int id;
		string name;
		int dept;

		//�ļ�������
		if (!ifs.is_open())
		{
			cout << "Ա����Ϣ�ļ������ڣ���Ҫ���Ա��" << endl;
			this->workers_number = 0;
		}
		//�ļ����ڣ���ȡ��Ϣ��������vector
		else
		{
			append = true;
			if (append)
			{
				worker_lsts.clear();
			}
			if (ifs.eof())
			{
				cout << "Ա����Ϊ0����Ҫ���Ա��" << endl;
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
		ifs.close(); //�ر��ļ�
		system("pause");
		system("cls");
	}

private:
	vector<Worker*> worker_lsts;	//Ա����Ϣ
	int workers_number;		//Ա������
	bool append = false;
};