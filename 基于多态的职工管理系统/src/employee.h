#pragma once
#include"worker.h"

//��ͨԱ����
//��λְ����ɾ�����������
class Employee:public Worker
{
public:
	Employee(int id, string name, int dId)
	{
		this->m_Id = id;
		this->m_Name = name;
		this->m_Dept = dId;
	}

	virtual void showInfo()
	{
		cout << "ְ����ţ�" << this->m_Id
			<< " \tְ�������� " << this->m_Name
			<< " \t��λ��" << this->getDeptName()
			<< " \t��λְ����ɾ�����������" << endl;
	}

	virtual string getDeptName()
	{
		return string("��ͨԱ��");
	}
};