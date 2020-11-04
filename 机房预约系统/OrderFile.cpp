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
	//读取预约文件，保存到容器中
	while (ifs >> date && ifs >>interval && ifs>>stuId && ifs>>stuName && ifs>>roomId && ifs>>status)
	{
		string key;
		string value;
		map<string, string> mp;
		
		//将date字段插入到mp中
		int pos = date.find(":");
		if (pos!=-1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			mp.insert(make_pair(key, value));
		}
		//将interval字段插入到mp中
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			mp.insert(make_pair(key, value));
		}
		//将stuId字段插入到mp中
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			mp.insert(make_pair(key, value));
		}
		//将stuName字段插入到mp中
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			mp.insert(make_pair(key, value));
		}
		//将roomId字段插入到mp中
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1);
			mp.insert(make_pair(key, value));
		}
		//将status字段插入到mp中
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
//更新预约信息，输出到文件中
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
//查看所有预约
void OrderFile::showFile()
{
	if (this->m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (size_t i = 0; i < this->m_Size; i++)
	{
		cout << i + 1 << "、 ";

		cout << "预约日期： 周" << this->m_orderData[i]["date"];
		cout << " 时段：" << (this->m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号：" << this->m_orderData[i]["stuId"];
		cout << " 姓名：" << this->m_orderData[i]["stuName"];
		cout << " 机房：" << this->m_orderData[i]["roomId"];
		string status = " 状态： ";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
		if (this->m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (this->m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (this->m_orderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
}
