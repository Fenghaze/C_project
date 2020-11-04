#pragma once
#include "itentity.h"
class Teacher :
	public Identity
{
public:
	Teacher();
	Teacher(int id, string name, string pwd);
	//教师菜单
	virtual void menu();
	//显示所有预约
	void showAllOrder();
	//审核预约
	void validOrder();
	int m_EmpId;	//教师编号
};

