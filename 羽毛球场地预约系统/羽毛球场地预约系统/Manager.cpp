#include "Manager.h"
#include"globalFile.h"
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;


Manager::Manager() {

}

Manager::Manager(std::string name, std::string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();

	ifstream ifs;
	ifs.open(COURT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "����ë�򳡵��ļ���������" << endl;
		return;
	}
	badmintonCourt b;

	while (ifs >> b.m_courtId && ifs >> b.courtType) {
		vCourt.push_back(b);
	}
	cout << "��ǰ��ë�򳡵�����Ϊ��" << vCourt.size() << endl;
	ifs.close();

}

bool Manager::checkReapeat(int id) {
	for (auto it = vStu.begin(); it != vStu.end(); it++) {
		if (it->m_Id == id) return true;
	}

	for (auto it = vAss.begin(); it != vAss.end(); it++) {
		if (it->m_EmId == id) return true;
	}

	return false;

}



//��ʼ������
void Manager::initVector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "��ѧ���ļ���������" << endl;
		return;
	}
	vStu.clear();
	vAss.clear();

	Student s;

	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	
	ifs.open(ASSISTANT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "�������ļ���������" << endl;
		return;
	}
	Assistant a;

	while (ifs >> a.m_EmId && ifs >> a.m_Name && ifs >> a.m_Pwd) {
		vAss.push_back(a);
	}
	cout << "��ǰ��������Ϊ��" << vAss.size() << endl;
	ifs.close();

	
	



}


//��ʾ�˵�
void Manager::operateMenu() {
	
	cout << "��ӭ����Ա:"<<this->m_Name<<"��¼��"<< endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t |       1.����˺�           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       2.�鿴�˺�           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       3.�鿴��ë�򳡵�     |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       4.���ԤԼ           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       0.ע����¼           |\n";
	cout << "\t\t -----------------------------\n";
	cout << "��������ѡ��";
	
}



//����˺�
void Manager::addAccount() {
	
	cout << "����������˺�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�����ѧ������" << endl;

	ofstream ofs;
	string filename;
	//string tip;

	int select = 0;
	cin >> select;

	if (select == 1) {
		filename = STUDENT_FILE;

	}
	else if (select == 2) {
		filename = ASSISTANT_FILE;
	}

	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;

	cout << "������ѧ�ţ�" << endl;
	cin >> id;

	

	while(checkReapeat(id)) {
		cout << "���������ѧ���ظ�������������" << endl;
		cin >> id;
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd<<endl;
	cout << "��ӳɹ�!" << endl;

	this->initVector();

	ofs.close();

	system("pause");
	system("cls");

	return;




}

void printStu(Student &s) {
	cout << "ѧ��:" << s.m_Id << "   ����:" << s.m_Name << "   ����:" << s.m_Pwd<<endl;
}
void printAss(Assistant &a) {
	cout << "ѧ��:" << a.m_EmId<< "   ����:" << a.m_Name << "   ����:" << a.m_Pwd<<endl;
}

//�鿴�˺�
void Manager::showAccount() {
	cout << "������鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴��������" << endl;

	int select = 0;
	cin >> select;
	
	if (select == 1) {
		cout << "����ѧ����Ϣ����:" << endl;
		for_each(vStu.begin(), vStu.end(), printStu);
	}
	else if (select== 2) {
		cout << "����ѧ��������Ϣ����:" << endl;
		for_each(vAss.begin(), vAss.end(), printAss);
	}
	system("pause");
	system("cls");
	return;



}

void printCourt(badmintonCourt &b) {
	cout << "���غ�:" <<b.m_courtId<<"  �������ͣ�"<<b.courtType<<endl;
}

//�鿴��ë�򳡵���Ϣ
void Manager::showBadmintonCourt() {
	cout << "��ë�򳡵���Ϣ���£�" << endl;
	cout << "woodland--ľ��" << "   rubberFloor--����" << endl;
	for_each(vCourt.begin(), vCourt.end(), printCourt);

	system("pause");
	system("cls");
	return;

}

//��ճ���ԤԼ��¼
void Manager::cleanOrderFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "���ԤԼ�ɹ�" << endl;
	system("pause");
	system("cls");
	return;


}
