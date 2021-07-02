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
		cout << "打开羽毛球场地文件发生错误" << endl;
		return;
	}
	badmintonCourt b;

	while (ifs >> b.m_courtId && ifs >> b.courtType) {
		vCourt.push_back(b);
	}
	cout << "当前羽毛球场地数量为：" << vCourt.size() << endl;
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



//初始化容器
void Manager::initVector() {
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "打开学生文件发生错误" << endl;
		return;
	}
	vStu.clear();
	vAss.clear();

	Student s;

	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();

	
	ifs.open(ASSISTANT_FILE, ios::in);

	if (!ifs.is_open()) {
		cout << "打开助理文件发生错误" << endl;
		return;
	}
	Assistant a;

	while (ifs >> a.m_EmId && ifs >> a.m_Name && ifs >> a.m_Pwd) {
		vAss.push_back(a);
	}
	cout << "当前助理数量为：" << vAss.size() << endl;
	ifs.close();

	
	



}


//显示菜单
void Manager::operateMenu() {
	
	cout << "欢迎管理员:"<<this->m_Name<<"登录！"<< endl;
	cout << "\t\t -----------------------------\n";
	cout << "\t\t |       1.添加账号           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       2.查看账号           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       3.查看羽毛球场地     |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       4.清空预约           |\n";
	cout << "\t\t |                            |\n";
	cout << "\t\t |       0.注销登录           |\n";
	cout << "\t\t -----------------------------\n";
	cout << "输入您的选择：";
	
}



//添加账号
void Manager::addAccount() {
	
	cout << "请输入添加账号类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加学生助理" << endl;

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

	cout << "请输入学号：" << endl;
	cin >> id;

	

	while(checkReapeat(id)) {
		cout << "你所输入的学号重复，请重新输入" << endl;
		cin >> id;
	}

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd<<endl;
	cout << "添加成功!" << endl;

	this->initVector();

	ofs.close();

	system("pause");
	system("cls");

	return;




}

void printStu(Student &s) {
	cout << "学号:" << s.m_Id << "   名字:" << s.m_Name << "   密码:" << s.m_Pwd<<endl;
}
void printAss(Assistant &a) {
	cout << "学号:" << a.m_EmId<< "   名字:" << a.m_Name << "   密码:" << a.m_Pwd<<endl;
}

//查看账号
void Manager::showAccount() {
	cout << "请输入查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有助理" << endl;

	int select = 0;
	cin >> select;
	
	if (select == 1) {
		cout << "所有学生信息如下:" << endl;
		for_each(vStu.begin(), vStu.end(), printStu);
	}
	else if (select== 2) {
		cout << "所有学生助理信息如下:" << endl;
		for_each(vAss.begin(), vAss.end(), printAss);
	}
	system("pause");
	system("cls");
	return;



}

void printCourt(badmintonCourt &b) {
	cout << "场地号:" <<b.m_courtId<<"  场地类型："<<b.courtType<<endl;
}

//查看羽毛球场地信息
void Manager::showBadmintonCourt() {
	cout << "羽毛球场地信息如下：" << endl;
	cout << "woodland--木地" << "   rubberFloor--胶地" << endl;
	for_each(vCourt.begin(), vCourt.end(), printCourt);

	system("pause");
	system("cls");
	return;

}

//清空场地预约记录
void Manager::cleanOrderFile() {
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空预约成功" << endl;
	system("pause");
	system("cls");
	return;


}
