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
		v.push_back((vCourt[i].courtType == "woodland") ? "ľ��" : "����");
	}



}

void Student::operateMenu() {
	cout << "��ӭѧ��:" << this->m_Name << "��¼��" << endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t |       1.����ԤԼ           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       2.�鿴�ҵ�ԤԼ       |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       3.�鿴����ԤԼ       |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       4.ȡ��ԤԼ           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       0.ע����¼           |\n";
	cout << "\t\t -----------------------------\n";
	cout << "��������ѡ��";

}

//����ԤԼ
void Student::applyOrder() {
	cout << "��ë�򳡵ؿ���ʱ��Ϊ��һ��������" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	cout << "6������" << endl;

	int date = 0;
	int interval = 0;
	int courtId = 0;

	while (1) {
		cin >> date;
		if (date >= 1 && date <= 6) break;
		cout << "�����������������룡" << endl;
	}

	cout << "�����������ʱ��Σ�" << endl;
	cout << "1��9��00-11��00" << endl;
	cout << "2��13��00-15��00" << endl;
	cout << "3��15��00-17;00" << endl;
	cout << "4��17��00-19��00" << endl;
	cout << "5��19��00-21��00" << endl;

	while (1) {
		cin >> interval;
		if (interval >= 1 && interval <= 5) break;
		cout << "�����������������룡" << endl;
	}
	
	
	cout << "�����볡�أ�" << endl;
	cout << "1�ų���:"<<v[0]<<endl;
	cout << "2�ų���:"<<v[1] <<endl;
	cout << "3�ų���:"<<v[2] <<endl;
	cout << "4�ų���:"<<v[3] <<endl;
	cout << "5�ų���:"<<v[4] <<endl;
	cout << "6�ų���:"<<v[5] <<endl;
	cout << "7�ų���:"<<v[6] <<endl;
	cout << "8�ų���:"<<v[7] <<endl;
	cout << "9�ų���:"<<v[8] <<endl;

	while(1) {
		cin >> courtId;
		if (courtId >= 1 && courtId <= 9) break;
		cout << "�����������������룡" << endl;

	}
	cout << "ԤԼ�ɹ� ����У�" << endl;

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

//�鿴�ҵ�ԤԼ
void Student::showMyOrder() {

	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	int num;
	string time;
	for (int i = 0; i < of.m_size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"]<<" ";
			num = atoi(of.m_orderData[i]["interval"].c_str());
			if (num == 1) {
				time = "9��00-11��00";
			}
			else if (num == 2) {
				time = "13��00-15��00";
			}
			else if (num == 3) {
				time = "15��00-17;00";
			}
			else if (num == 4) {
				time = "17��00-19��00";
			}
			else if (num == 5) {
				time = "19��00-21��00";
			}
			cout << "ʱ�Σ�" << time << " ";
			cout << "���غţ�" << of.m_orderData[i]["courtId"] << " ";
			string status = "״̬�� ";// 0 ȡ����ԤԼ  1 �����   2��ԤԼ   -1ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1") {
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "���δͨ����ԤԼʧ��";
			}
			else {
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}

	}
	system("pause");
	system("cls");
	return;

}

//�鿴����ԤԼ
void Student::showAllOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	int num;
	string time;
	for (int i = 0; i < of.m_size; i++) {
		    cout << i + 1 << " ";
		    cout << "ѧ�ţ�" << of.m_orderData[i]["stuId"] << " ";
		    cout << "������" << of.m_orderData[i]["stuName"] << " ";
			cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << " ";
			num = atoi(of.m_orderData[i]["interval"].c_str());
			if (num == 1) {
				time = "9��00-11��00";
			}
			else if (num == 2) {
				time = "13��00-15��00";
			}
			else if (num == 3) {
				time = "15��00-17;00";
			}
			else if (num == 4) {
				time = "17��00-19��00";
			}
			else if (num == 5) {
				time = "19��00-21��00";
			}
			cout << "ʱ�Σ�" << time << " ";
		
			
			cout << "���غţ�" << of.m_orderData[i]["courtId"] << " ";
			string status = "״̬�� ";// 0 ȡ����ԤԼ  1 �����   2��ԤԼ   -1ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1") {
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2") {
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1") {
				status += "���δͨ����ԤԼʧ��";
			}
			else {
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		

	}
	system("pause");
	system("cls");
	return;
}

//ȡ��ԤԼ
void Student::cancelAllOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л���ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>ret;
	int num;
	string time;
	int index = 1;
	for (int i = 0; i < of.m_size; i++) {
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id) {
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2") {
				ret.push_back(i);
				cout << index++ << " ";
				cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"] << " ";
				num = atoi(of.m_orderData[i]["interval"].c_str());
				if (num == 1) {
					time = "9��00-11��00";
				}
				else if (num == 2) {
					time = "13��00-15��00";
				}
				else if (num == 3) {
					time = "15��00-17;00";
				}
				else if (num == 4) {
					time = "17��00-19��00";
				}
				else if (num == 5) {
					time = "19��00-21��00";
				}
				cout << "ʱ�Σ�" << time << " ";
				cout << "���غţ�" << of.m_orderData[i]["courtId"] << " ";
				string status = "״̬�� ";// 0 ȡ����ԤԼ  1 �����   2��ԤԼ   -1ԤԼʧ��
				if (of.m_orderData[i]["status"] == "1") {
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2") {
					status += "ԤԼ�ɹ�";
				}
				
				cout << status << endl;
			}

			
		}

	}
	cout << "������ȡ���ļ�¼��0������" << endl;
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
				cout << "�Ѿ�ȡ��ԤԼ��" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
		
	}


	system("pause");
	system("cls");
	return;

}
