#pragma once
#include "Activities.h" // ��� ������ � ������������
#include "DataBase.h"  // ��� ������ � ����� ������
#include <vector>      // ��� �������� ��������� �����������

class ActivitiesDelete
{
	private:
		DataBase& db; // ������ �� ���� ������
		void deleteByIdUI(); // ����� ��� �������� ���������� �� ID
		void deleteAllUI(); // ����� ��� �������� ���� �����������
	public:
		explicit ActivitiesDelete(DataBase& database); // �����������, ����������� ������ �� ���� ������

		bool deleteActivityById(int id); // �������� ���������� �� ID
		bool deleteAllActivities(); // �������� ���� �����������
		void runDeleteUI(); // ������ ����������������� ���������� ��� �������� �����������
};

