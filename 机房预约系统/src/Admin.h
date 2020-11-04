#pragma once
#include "itentity.h"
#include"student.h"
#include"Teacher.h"
#include<vector>
#include "ComputerRoom.h"
class Admin :
	public Identity
{
public:
	Admin();
	Admin(string name, string pwd);
	//管理员菜单
	virtual void menu();
	//添加用户
	void addUsers();
	//显示用户
	void showUsers();
	//显示机房信息
	void showComputers();
	//清空预约记录
	void cleanOrder();
	
	//初始化容器
	void initVecotr();

	//编号去重
	bool checkRepeat(int id, int type);

	vector<Student> vStu;	//存放学生用户
	vector<Teacher> vTea;	//存储教师用户

	vector<ComputerRoom> vRoom;	//存储机房信息
};

