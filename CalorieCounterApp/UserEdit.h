#pragma once
#include <string>

class UserEdit
{
public:
	static void showEditUserMenu(); // Функция для отображения меню редактирования пользователя
	void choiceEditUser(); // Функция для выбора действия в меню редактирования пользователя
	void editUserName(std::string& newName); // Функция для изменения имени пользователя
	void editUserAge(int newAge);
	void editUserWeight(float newWeight);
	void editUserHeight(float newHeight);
	void editUserGender(const std::string& newGender);
	void editUserDietType(const std::string& newDietType);
	void editUserActivityLevel(const std::string& newActivityLevel);
};

