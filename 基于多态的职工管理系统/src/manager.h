#pragma once
#include"worker.h"

//������
//��λְ������ϰ彻��������,���·������Ա��
class Manager :public Worker
{
public:
	Manager(int id, string name, int dId)
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
			<< " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
	}

	virtual string getDeptName()
	{
		return string("����");
	}
};