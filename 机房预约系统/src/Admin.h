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
	//����Ա�˵�
	virtual void menu();
	//����û�
	void addUsers();
	//��ʾ�û�
	void showUsers();
	//��ʾ������Ϣ
	void showComputers();
	//���ԤԼ��¼
	void cleanOrder();
	
	//��ʼ������
	void initVecotr();

	//���ȥ��
	bool checkRepeat(int id, int type);

	vector<Student> vStu;	//���ѧ���û�
	vector<Teacher> vTea;	//�洢��ʦ�û�

	vector<ComputerRoom> vRoom;	//�洢������Ϣ
};

