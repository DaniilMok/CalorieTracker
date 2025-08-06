#pragma once
#include <string>

class UserEdit
{
public:
	static void showEditUserMenu(); // ������� ��� ����������� ���� �������������� ������������
	void choiceEditUser(); // ������� ��� ������ �������� � ���� �������������� ������������
	void editUserName(std::string& newName); // ������� ��� ��������� ����� ������������
	void editUserAge(int newAge);
	void editUserWeight(float newWeight);
	void editUserHeight(float newHeight);
	void editUserGender(const std::string& newGender);
	void editUserDietType(const std::string& newDietType);
	void editUserActivityLevel(const std::string& newActivityLevel);
};

