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

//��ʾ�˵�
void Assistant::operateMenu() {
	cout << "��ӭѧ������:" << this->m_Name << "��¼��" << endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       1.�鿴����ԤԼ       |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       2.���ԤԼ           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       0.ע����¼           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t -----------------------------\n";
	cout << "��������ѡ��";
}

//�鿴����ԤԼ
void Assistant::showAllOrder() {
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

//���ԤԼ
void Assistant::validOrder() {
	OrderFile of;
	if (of.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "����˵ļ�¼���£�" << endl;
	vector<int>ret;
	int num;
	string time;
	int index = 1;
	for (int i = 0; i < of.m_size; i++) {
		
			if (of.m_orderData[i]["status"] == "1") {
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
	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;
	int choice = 0;
	while (true) {
		cin >> select;
		if (select >= 0 && select <= ret.size()) {
			if (select == 0) {
				break;
			}
			else {
				cout << "��������˽����" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> choice;
				if (choice == 1) {
					of.m_orderData[ret[select - 1]]["status"] = "2";
				}
				else if (choice == 2) {
					of.m_orderData[ret[select - 1]]["status"] = "-1";
				}

				of.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "������������������" << endl;

	}


	system("pause");
	system("cls");
	return;



}
