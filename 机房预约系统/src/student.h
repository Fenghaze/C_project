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
	//ѧ���˵�
	virtual void menu();
	//����ԤԼ
	void applyOrder();
	//�鿴����ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
public:
	int m_Id;	//ѧ�����
	vector<ComputerRoom> vRoom;		//������Ϣ
};

