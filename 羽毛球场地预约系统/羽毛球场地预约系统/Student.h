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

	void applyOrder();//����ԤԼ

	void showMyOrder();//�鿴�ҵ�ԤԼ

	void showAllOrder();//�鿴����ԤԼ


	void cancelAllOrder();//ȡ��ԤԼ

	vector<badmintonCourt>vCourt;

	vector<string>v;
	
	

	int m_Id;



private:

};

