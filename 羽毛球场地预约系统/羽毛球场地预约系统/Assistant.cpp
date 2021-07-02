#include "Assistant.h"
#include<string>
#include"OrderFile.h"
#include<iostream>

using namespace std;


Assistant::Assistant() {

}

Assistant::Assistant(int empId, std::string name, std::string pwd) {
	this->m_EmId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//显示菜单
void Assistant::operateMenu() {
	cout << "欢迎学生助理:" << this->m_Name << "登录！" << endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       1.查看所有预约       |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       2.审核预约           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       0.注销登录           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t -----------------------------\n";
	cout << "输入您的选择：";
}

//查看所有预约
void Assistant::showAllOrder() {
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

//审核预约
void Assistant::validOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "待审核的记录如下：" << endl;
	vector<int>ret;
	int num;
	string time;
	int index = 1;
	for (int i = 0; i < of.m_size; i++) {
		
			if (of.m_orderData[i]["status"] == "1") {
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
	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0;
	int choice = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= ret.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "请输入审核结果：" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				cin >> choice;
				if (choice == 1) {
					of.m_orderData[ret[select - 1]]["status"] = "2";
				}
				else if (choice == 2) {
					of.m_orderData[ret[select - 1]]["status"] = "-1";
				}

				of.updateOrder();
				cout << "审核完毕！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入" << endl;

	}


	system("pause");
	system("cls");
	return;



}
