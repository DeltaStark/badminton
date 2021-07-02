#pragma once
#include "Identity.h"
#include"Student.h"
#include"Assistant.h"
#include"badmintonCourt.h"
#include<vector>
class Manager :public Identity
{
public:
	Manager();

	Manager(std::string name, std::string pwd);

	virtual void operateMenu();//显示菜单

	void addAccount();//添加账号

	void showAccount();//查看账号

	void showBadmintonCourt();//查看羽毛球场地信息

	void cleanOrderFile();//清空场地预约记录

	void initVector();//初始化容器

	vector<Student>vStu;//学生容器

	vector<Assistant>vAss;//助理容器

	vector<badmintonCourt>vCourt;


	bool checkReapeat(int id);
private:
	string m_Name;
	string m_Pwd;
};

