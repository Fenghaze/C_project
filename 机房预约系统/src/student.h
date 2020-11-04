#pragma once
#include"itentity.h"
#include<vector>
#include"ComputerRoom.h"
class Student :
	public Identity
{
public:
	Student();
	Student(int id, string name, string pwd);
	//学生菜单
	virtual void menu();
	//申请预约
	void applyOrder();
	//查看个人预约
	void showMyOrder();
	//查看所有预约
	void showAllOrder();
	//取消预约
	void cancelOrder();
public:
	int m_Id;	//学生编号
	vector<ComputerRoom> vRoom;		//机房信息
};

