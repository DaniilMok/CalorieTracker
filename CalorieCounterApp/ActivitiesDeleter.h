#pragma once
#include "DataBase.h"

class ActivitiesDeleter
{
	private:
		DataBase& db;
		void deleteByIdUI(); 
		void deleteAllUI();
	public:
		explicit ActivitiesDeleter(DataBase& db); // �����������, ����������� ������ �� ������ ���� ������
		bool deleteActivityById(int id); // ������� ��� �������� ���������� �� ID
		bool deleteAllActivities(); // ������� ��� �������� ���� ����������� �� ���� ������
		void runDeleteUI(); // ������� ��� ������� ����������������� ���������� �������� �����������
};

