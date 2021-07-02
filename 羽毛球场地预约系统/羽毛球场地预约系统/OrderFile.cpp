#include "OrderFile.h"
#include<fstream>
#include"globalFile.h"
#include<string>
#include<map>

using namespace std;
class Student;

OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	if (!ifs.is_open()) {

		cout << "预约表打开失败！" << endl;
		system("pause");
		system("cls");
		return;
	}

	string date;
	string interval;
	string stuId;
	string stuName;
	string courtId;
	string status;
	this->m_size = 0;

	while (ifs>>date && ifs>>interval &&ifs>>stuId && ifs>>stuName && ifs>>courtId  && ifs>>status) {
		string key;
		string value;
		map<string, string>m;

		int pos = date.find(":");
		if (pos != -1) {
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuId.find(":");
		if (pos != -1) {
			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = courtId.find(":");
		if (pos != -1) {
			key = courtId.substr(0, pos);
			value = courtId.substr(pos + 1, courtId.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		this->m_orderData.insert(make_pair(this->m_size, m));
		this->m_size ++;
		
	}
	ifs.close();
	
	
	


	/*for (auto it = m_orderdata.begin(); it != m_orderdata.end(); it++) {
		cout << "第" << it->first << "行记录:" << endl;
		for (auto ii = it->second.begin(); ii != it->second.end(); ii++) {
			cout <<"key="<<ii->first <<"      value="<< ii->second << endl;
		}测试代码
	}*/

	
}


//更新预约记录
void OrderFile::updateOrder() {
	if (this->m_size == 0) {
		return;
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);

	for (int i = 0; i < m_size; i++) {
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "courtId:" << this->m_orderData[i]["courtId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] <<endl;
	}
	ofs.close();
}
