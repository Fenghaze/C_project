#pragma once
#include"worker.h"

//经理类
//岗位职责：完成老板交给的任务,并下发任务给员工
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
		cout << "职工编号：" << this->m_Id
			<< " \t职工姓名： " << this->m_Name
			<< " \t岗位：" << this->getDeptName()
			<< " \t岗位职责：完成老板交给的任务,并下发任务给员工" << endl;
	}

	virtual string getDeptName()
	{
		return string("经理");
	}
};