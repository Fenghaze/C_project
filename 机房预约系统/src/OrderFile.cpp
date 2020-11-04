#include "OrderFile.h"
#include<fstream>
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;
	string stuId;
	string stuName;
	string roomId;
	string status;

	this->m_Size = 0;
	//��ȡԤԼ�ļ������浽������
	while (ifs >> date && ifs >>interval && ifs>>stuId && ifs>>stuName && ifs>>roomId && ifs>>status)
	{
		string key;
		string value;
		map<string, string> mp;
		
		//��date�ֶβ��뵽mp��
		int pos = date.find(":");
		if (pos!=-1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			mp.insert(make_pair(key, value));
		}
		//��interval�ֶβ��뵽mp��
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			mp.insert(make_pair(key, value));
		}
		//��stuId�ֶβ��뵽mp��
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			mp.insert(make_pair(key, value));
		}
		//��stuName�ֶβ��뵽mp��
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			mp.insert(make_pair(key, value));
		}
		//��roomId�ֶβ��뵽mp��
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			mp.insert(make_pair(key, value));
		}
		//��status�ֶβ��뵽mp��
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			mp.insert(make_pair(key, value));
		}
		this->m_orderData.insert(make_pair(this->m_Size, mp));
		this->m_Size++;
	}
	ifs.close();
}
//����ԤԼ��Ϣ��������ļ���
void OrderFile::updateFile()
{
	if (this->m_Size == 0)
	{
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (size_t i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}
//�鿴����ԤԼ
void OrderFile::showFile()
{
	if (this->m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (size_t i = 0; i < this->m_Size; i++)
	{
		cout << i + 1 << "�� ";

		cout << "ԤԼ���ڣ� ��" << this->m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (this->m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << this->m_orderData[i]["stuId"];
		cout << " ������" << this->m_orderData[i]["stuName"];
		cout << " ������" << this->m_orderData[i]["roomId"];
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
		if (this->m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (this->m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (this->m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
}
