#pragma once
#include<string>
using namespace std;
class Identity
{
public:
	virtual void menu() = 0;	//���麯����������
	
	string m_Name;	//����
	string m_Pwd;	//����
};