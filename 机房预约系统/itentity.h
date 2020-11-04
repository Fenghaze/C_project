#pragma once
#include<string>
using namespace std;
class Identity
{
public:
	virtual void menu() = 0;	//纯虚函数，抽象类
	
	string m_Name;	//姓名
	string m_Pwd;	//密码
};