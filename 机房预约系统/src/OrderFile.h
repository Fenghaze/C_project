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
	map<int, map<string, string>> m_orderData;	//预约信息：<预约记录数，预约信息>
	int m_Size;	//预约记录数
};

