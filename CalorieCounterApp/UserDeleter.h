#pragma once
#include "DataBase.h"

class UserDeleter
{
	private:
		DataBase& db; // ������ �� ������ ���� ������
	public:
		UserDeleter(DataBase& database) : db(database) {} // �����������
		int runDeleteUI(int& choiceUserMenu); // ������� ��� ����������������� ���������� �������� ������������
};

