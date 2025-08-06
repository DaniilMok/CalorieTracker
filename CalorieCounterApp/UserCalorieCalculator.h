// �����������!!!

#pragma once
#include "DataBase.h"
#include <string>


class UserCalorieCalculator
{
	private:
		DataBase& db; // ������ �� ������ ���� ������
		int userId; // ID ������������
		std::string userName; // ��� ������������
		int userCalories; // ������� ������������
		int userWeight; // ��� ������������
		std::string activityType; // ��� ���������� ������������
		std::string foodType; // ��� ������� ������������
		bool addFoodToUser(int userId, const std::string& foodName, int foodCalories); // ������� ��� ���������� �������� � ������������
		bool addActivityToUser(int userId, const std::string& activityName, int activityCalories); // ������� ��� ���������� ���������� � ������������
	public:
		explicit UserCalorieCalculator(DataBase& db); // �����������, ����������� ������ �� ������ ���� ������
		void calculateCalories(); // ������� ��� ������� ������� ������������
		void showUserInfo(); // ������� ��� ����������� ���������� � ������������
		void updateUserInfo(); // ������� ��� ���������� ���������� � ������������
		void runCalculatorUI(); // ������� ��� ������� ����������������� ���������� ������������ �������
};

