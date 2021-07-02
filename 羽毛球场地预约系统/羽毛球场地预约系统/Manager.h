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

	virtual void operateMenu();//��ʾ�˵�

	void addAccount();//����˺�

	void showAccount();//�鿴�˺�

	void showBadmintonCourt();//�鿴��ë�򳡵���Ϣ

	void cleanOrderFile();//��ճ���ԤԼ��¼

	void initVector();//��ʼ������

	vector<Student>vStu;//ѧ������

	vector<Assistant>vAss;//��������

	vector<badmintonCourt>vCourt;


	bool checkReapeat(int id);
private:
	string m_Name;
	string m_Pwd;
};

