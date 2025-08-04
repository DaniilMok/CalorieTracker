#pragma once
#include "DataBase.h" // ���������� ������������ ���� DataBase.h

class ActivitiesDeleter
{
	private:
		DataBase& db; // ������ �� ������ ���� ������
		void deleteByIdUI(); // ����� ��� ����������������� ���������� �������� ���������� �� ID
		void deleteAllUI(); // ����� ��� ����������������� ���������� �������� ���� �����������
	public:
		explicit ActivitiesDeleter(DataBase& db); // �����������, ����������� ������ �� ������ ���� ������
		bool deleteActivityById(int id); //
		bool deleteAllActivities(); // ����� ��� �������� ���� ����������� �� ���� ������
		void runDeleteUI(); // ����� ��� ������� ����������������� ���������� �������� �����������
};

