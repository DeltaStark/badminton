#pragma once
#include "Identity.h"
#include<vector>
#include"badmintonCourt.h"

class Student :public Identity
{
public:
	Student();

	Student(int id, std::string name,std::string pwd);

	virtual void operateMenu();

	void applyOrder();//申请预约

	void showMyOrder();//查看我的预约

	void showAllOrder();//查看所有预约


	void cancelAllOrder();//取消预约

	vector<badmintonCourt>vCourt;

	vector<string>v;
	
	

	int m_Id;



private:

};

