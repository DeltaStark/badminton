#pragma once
#include "Identity.h"

class Assistant :public Identity
{
public:
	Assistant();

	Assistant(int empId, std::string name, std::string pwd);

	virtual void operateMenu();//��ʾ�˵�

	void showAllOrder();//�鿴����ԤԼ
		
	void validOrder();//���ԤԼ

	int m_EmId;
};

