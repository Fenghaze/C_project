#pragma once
#include<iostream>
#include<map>
using namespace std;
#include"globalfile.h"
class OrderFile
{
public:
	OrderFile();
	void updateFile();
	void showFile();
	map<int, map<string, string>> m_orderData;	//ԤԼ��Ϣ��<ԤԼ��¼����ԤԼ��Ϣ>
	int m_Size;	//ԤԼ��¼��
};

