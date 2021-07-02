#include<iostream>
#include<string>
#include <fstream>
#include"Identity.h"
#include"globalFile.h"
#include"Student.h"
#include"Assistant.h"
#include"Manager.h"
#include<iostream>
using namespace std;

//进入管理员子菜单界面
void managerMenu(Identity * &manager) {
	while (true) {
		manager->operateMenu();

		Manager *man = (Manager *)manager;
		int select = 0;

		cin >> select;
		if (select == 1) {//添加账号
			man->addAccount();
		}
		else if (select == 2) {//查看账号
			man->showAccount();
		}
		else if (select == 3) {//查看羽毛球场地
			man->showBadmintonCourt();
		}
		else if (select == 4) {//清空预约
			man->cleanOrderFile();
		}
		else if(select==0){//注销登录
			delete manager;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入学生子菜单界面
void studentMenu(Identity * &student) {
	while (true) {
		student->operateMenu();

		Student *stu = (Student *)student;
		int select = 0;

		cin >> select;
		if (select == 1) {//申请预约
			stu->applyOrder();
		}
		else if (select == 2) {//查看我的预约
			stu->showMyOrder();
		}
		else if (select == 3) {//查看所有人的预约
			stu->showAllOrder();
		}
		else if (select == 4) {//取消预约
			stu->cancelAllOrder();
		}
		else if (select == 0) {//注销登录
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//进入学生助理子菜单界面
void assistantMenu(Identity * &assistant) {
	while (true) {
		assistant->operateMenu();

		Assistant *ass = (Assistant *)assistant;
		int select = 0;

		cin >> select;
		if (select == 1) {//查看所有预约
			ass->showAllOrder();
		}
		else if (select == 2) {//审核预约
			ass->validOrder();
		}
		
		else if (select == 0) {//注销登录
			delete assistant;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录
void LoginIn(string fileName, int type) {
	Identity *person = NULL;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在
	if (!ifs.is_open()) {

		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;

	if (type == 1 || type == 2) {
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	cout << "请输入你的用户名：" << endl;
	cin >> name;

	cout << "请输入你的密码：" << endl;
	cin >> pwd;

	if (type == 1) {
		//学生登录验证
		int SId;
		string SName;
		string SPwd;

		while (ifs >> SId && ifs >> SName && ifs >> SPwd) {
		
			//cout << SId << SName << SPwd << endl;
			if (SId == id && SName == name && SPwd == pwd) {
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);

				return;
			}
		}
	}
	else if (type == 2) {
		//学生助理登录验证
		int SId;
		string SName;
		string SPwd;

		while (ifs >> SId && ifs >> SName && ifs >> SPwd) {

			//cout << SId << SName << SPwd << endl;
			if (SId == id && SName == name && SPwd == pwd) {
				cout << "学生助理验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Assistant(id, name, pwd);
				assistantMenu(person);

				return;
			}
		}
	}
	else if (type == 3) {
		//管理员登录验证
		
		string SName;
		string SPwd;

		while (ifs >> SName && ifs >> SPwd) {

			//cout << SId << SName << SPwd << endl;
			if (SName == name && SPwd == pwd) {
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);

				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;

	system("pause");
	system("cls");
	return ;

}

int main() {
	int select = 0;
	while (true) {
		cout << "=======================欢迎来到羽毛球预约系统=======================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -----------------------------\n";
		cout << "\t\t |                            |\n";
		cout << "\t\t |       1.学生               |\n";
		cout << "\t\t |                            |\n";
		cout << "\t\t |       2.学生助理           |\n";
		cout << "\t\t |                            |\n";
		cout << "\t\t |       3.管理员             |\n";
		cout << "\t\t |                            |\n";
		cout << "\t\t |       0.退出               |\n";
		cout << "\t\t |                            |\n";
		cout << "\t\t -----------------------------\n";
		cout << "输入您的选择：";
		cin >> select;

		switch (select)
		{
		case 1://学生身份
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2://学生助理
			LoginIn(ASSISTANT_FILE, 2);
			break;
		case 3://管理员
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	

	system("pause");
	return 0;
}