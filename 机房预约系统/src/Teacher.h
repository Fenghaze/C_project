#pragma once
#include "itentity.h"
class Teacher :
	public Identity
{
public:
	Teacher();
	Teacher(int id, string name, string pwd);
	//��ʦ�˵�
	virtual void menu();
	//��ʾ����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();
	int m_EmpId;	//��ʦ���
};

