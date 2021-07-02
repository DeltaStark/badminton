#include "Student.h"
#include<fstream>
#include"globalFile.h"
#include"OrderFile.h"

Student::Student() {

}

Student::Student(int id, std::string name, std::string pwd) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs;
	ifs.open(COURT_FILE, ios::in);

	badmintonCourt b;
	while (ifs >> b.m_courtId && ifs >> b.courtType) {
		vCourt.push_back(b);
	}
	ifs.close();

	
	for (int i = 0; i < vCourt.size(); i++) {
		v.push_back((vCourt[i].courtType == "woodland") ? "木地" : "胶地");
	}



}

void Student::operateMenu() {
	cout << "欢迎学生:" << this->m_Name << "登录！" << endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t |       1.申请预约           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       2.查看我的预约       |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       3.查看所有预约       |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       4.取消预约           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       0.注销登录           |\n";
	cout << "\t\t -----------------------------\n";
	cout << "输入您的选择：";

}

//申请预约
void Student::applyOrder() {
	cout << "羽毛球场地开放时间为周一到周六！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	cout << "6、周六" << endl;

	int date = 0;
	int interval = 0;
	int courtId = 0;

	while (1) {
		cin >> date;
		if (date >= 1 && date <= 6) break;
		cout << "输入有误，请重新输入！" << endl;
	}

	cout << "请输入申请的时间段：" << endl;
	cout << "1、9：00-11：00" << endl;
	cout << "2、13：00-15：00" << endl;
	cout << "3、15：00-17;00" << endl;
	cout << "4、17：00-19：00" << endl;
	cout << "5、19：00-21：00" << endl;

	while (1) {
		cin >> interval;
		if (interval >= 1 && interval <= 5) break;
		cout << "输入有误，请重新输入！" << endl;
	}
	
	
	cout << "请输入场地：" << endl;
	cout << "1号场地:"<<v[0]<<endl;
	cout << "2号场地:"<<v[1] <<endl;
	cout << "3号场地:"<<v[2] <<endl;
	cout << "4号场地:"<<v[3] <<endl;
	cout << "5号场地:"<<v[4] <<endl;
	cout << "6号场地:"<<v[5] <<endl;
	cout << "7号场地:"<<v[6] <<endl;
	cout << "8号场地:"<<v[7] <<endl;
	cout << "9号场地:"<<v[8] <<endl;

	while(1) {
		cin >> courtId;
		if (courtId >= 1 && courtId <= 9) break;
		cout << "输入有误，请重新输入！" << endl;

	}
	cout << "预约成功 审核中！" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);

	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "courtId:" << courtId << " ";
	ofs << "status:" << 1 << " ";

	ofs.close();
	system("pause");
	system("cls");
	return;
	
}

//查看我的预约
void Student::showMyOrder() {

	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	int num;
	string time;
	for (int i = 0; i < of.m_size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			cout << "预约日期：周" << of.m_orderData[i]["date"]<<" ";
			num = atoi(of.m_orderData[i]["interval"].c_str());
			if (num == 1) {
				time = "9：00-11：00";
			}
			else if (num == 2) {
				time = "13：00-15：00";
			}
			else if (num == 3) {
				time = "15：00-17;00";
			}
			else if (num == 4) {
				time = "17：00-19：00";
			}
			else if (num == 5) {
				time = "19：00-21：00";
			}
			cout << "时段：" << time << " ";
			cout << "场地号：" << of.m_orderData[i]["courtId"] << " ";
			string status = "状态： ";// 0 取消的预约  1 审核中   2已预约   -1预约失败
			if (of.m_orderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "审核未通过，预约失败";
			}
			else {
				status += "预约已取消";
			}
			cout << status << endl;
		}

	}
	system("pause");
	system("cls");
	return;

}

//查看所有预约
void Student::showAllOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	int num;
	string time;
	for (int i = 0; i < of.m_size; i++) {
		    cout << i + 1 << " ";
		    cout << "学号：" << of.m_orderData[i]["stuId"] << " ";
		    cout << "姓名：" << of.m_orderData[i]["stuName"] << " ";
			cout << "预约日期：周" << of.m_orderData[i]["date"] << " ";
			num = atoi(of.m_orderData[i]["interval"].c_str());
			if (num == 1) {
				time = "9：00-11：00";
			}
			else if (num == 2) {
				time = "13：00-15：00";
			}
			else if (num == 3) {
				time = "15：00-17;00";
			}
			else if (num == 4) {
				time = "17：00-19：00";
			}
			else if (num == 5) {
				time = "19：00-21：00";
			}
			cout << "时段：" << time << " ";
		
			
			cout << "场地号：" << of.m_orderData[i]["courtId"] << " ";
			string status = "状态： ";// 0 取消的预约  1 审核中   2已预约   -1预约失败
			if (of.m_orderData[i]["status"] == "1") {
				status += "审核中";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "预约成功";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "审核未通过，预约失败";
			}
			else {
				status += "预约已取消";
			}
			cout << status << endl;
		

	}
	system("pause");
	system("cls");
	return;
}

//取消预约
void Student::cancelAllOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或者预约成功的记录可以取消，请输入取消的记录" << endl;
	vector<int>ret;
	int num;
	string time;
	int index = 1;
	for (int i = 0; i < of.m_size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				ret.push_back(i);
				cout << index++ << " ";
				cout << "预约日期：周" << of.m_orderData[i]["date"] << " ";
				num = atoi(of.m_orderData[i]["interval"].c_str());
				if (num == 1) {
					time = "9：00-11：00";
				}
				else if (num == 2) {
					time = "13：00-15：00";
				}
				else if (num == 3) {
					time = "15：00-17;00";
				}
				else if (num == 4) {
					time = "17：00-19：00";
				}
				else if (num == 5) {
					time = "19：00-21：00";
				}
				cout << "时段：" << time << " ";
				cout << "场地号：" << of.m_orderData[i]["courtId"] << " ";
				string status = "状态： ";// 0 取消的预约  1 审核中   2已预约   -1预约失败
				if (of.m_orderData[i]["status"] == "1") {
					status += "审核中";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "预约成功";
				}
				
				cout << status << endl;
			}

			
		}

	}
	cout << "请输入取消的记录，0代表返回" << endl;
	int select = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <=ret.size()) {
			if (select == 0) {
				break;
			}
			else {
				of.m_orderData[ret[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "已经取消预约！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;
		
	}


	system("pause");
	system("cls");
	return;

}
