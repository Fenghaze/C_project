#pragma once
#include"worker.h"

//普通员工类
//岗位职责：完成经理交给的任务
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
		cout << "职工编号：" << this->m_Id
			<< " \t职工姓名： " << this->m_Name
			<< " \t岗位：" << this->getDeptName()
			<< " \t岗位职责：完成经理交给的任务" << endl;
	}

	virtual string getDeptName()
	{
		return string("普通员工");
	}
};