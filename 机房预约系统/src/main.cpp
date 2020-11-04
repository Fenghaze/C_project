#include<iostream>
#include"globalfile.h"
#include"itentity.h"
#include"student.h"
#include"Teacher.h"
#include"Admin.h"
#include<fstream>
using namespace std;

//����Ա�˵�
void adminMenu(Identity*& person)	
{
	while (true)
	{
		person->menu();		//��̬��ʵ�֣�����ָ��or����ȥ�����麯��
		Admin* admin = (Admin*)person;	//ǿתΪAdmin����
		int choice=0;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "����˺�" << endl;
			admin->addUsers();
			break;
		case 2:
			cout << "�鿴�˺�" << endl;
			admin->showUsers();
			break;
		case 3:
			cout << "�鿴����" << endl;
			admin->showComputers();
			break;
		case 4:
			cout << "���ԤԼ" << endl;
			admin->cleanOrder();
			break;
		case 0:
			delete admin;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

//ѧ���˵�
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
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
			break;
		case 2:
			cout << "�鿴�ҵ�ԤԼ" << endl;
			stu->showMyOrder();
			break;
		case 3:
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
			break;
		case 4:
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
			break;
		case 0:
			delete stu;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

//��ʦ�˵�
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
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
			break;
		case 2:
			cout << "���ԤԼ" << endl;
			stu->validOrder();
			break;
		case 0:
			delete stu;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
			break;
		default:
			break;
		}
	}
}

//��ҳ��¼��֤����
void login(string filename, int type)
{
	Identity* person = nullptr;
	ifstream ifs;
	ifs.open(filename, ios::in);	//��ȡ�ļ�
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id;			//���
	string name;	//����
	string pwd;		//����
	if (type == 1)	//ѧ��
	{
		cout << "����ѧ�ţ�";
		cin >> id;
	}
	else if(type==2)//��ʦ
	{
		cout << "����ְ���ţ�";
		cin >> id;
	}
	cout << "�������û���:";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;

	//��¼��֤
	if (type==1)
	{
		int fid;
		string fname;
		string fpwd;
		while (ifs >> fid, ifs >> fname, ifs>> fpwd)
		{
			if (fid ==id && fname ==name && fpwd ==pwd)
			{
				cout << "ѧ����¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���˵�
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
				cout << "��ʦ��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�˵�
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
				cout << "����Ա��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				person = new Admin(name, pwd);
				//�������Ա�˵�
				adminMenu(person);
				return;
			}
		}
	}
	cout << "�û������������" << endl;
	system("pause");
	system("cls");
	return;
}

int main(int argc, char** argv)
{
	int select = 0;
	while (true)
	{
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
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
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}
