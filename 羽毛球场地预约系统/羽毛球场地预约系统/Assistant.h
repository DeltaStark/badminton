#pragma once
#include "Identity.h"

class Assistant :public Identity
{
public:
	Assistant();

	Assistant(int empId, std::string name, std::string pwd);

	virtual void operateMenu();//显示菜单

	void showAllOrder();//查看所有预约
		
	void validOrder();//审核预约

	int m_EmId;
};

