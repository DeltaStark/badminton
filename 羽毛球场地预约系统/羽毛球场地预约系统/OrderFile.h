#pragma once
#include"globalFile.h"
#include<iostream>
#include<vector>
#include<map>

using namespace std;
class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������ key-��¼������  value-�����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>>m_orderData;

	//ԤԼ��¼����
	int m_size;

	
};

