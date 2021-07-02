#pragma once
#include<iostream>
#include<string>
using namespace std;
class Identity
{
public:
	virtual void operateMenu() = 0;

	string m_Name;
	string m_Pwd;
};

