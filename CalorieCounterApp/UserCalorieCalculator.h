#pragma once
#include "DataBase.h"
#include <string>


class UserCalorieCalculator
{
	private:
		DataBase& db; // Ссылка на объект базы данных
		int userId; // ID пользователя
		std::string userName; // Имя пользователя
		int userCalories; // Калории пользователя
		int userWeight; // Вес пользователя
		std::string activityType; // Тип активности пользователя
		std::string foodType; // Тип питания пользователя
		bool addFoodToUser(int userId, const std::string& foodName, int foodCalories); // Метод для добавления продукта к пользователю
		bool addActivityToUser(int userId, const std::string& activityName, int activityCalories); // Метод для добавления активности к пользователю
	public:
		explicit UserCalorieCalculator(DataBase& db); // Конструктор, принимающий ссылку на объект базы данных
		void calculateCalories(); // Метод для расчета калорий пользователя
		void showUserInfo(); // Метод для отображения информации о пользователе
		void updateUserInfo(); // Метод для обновления информации о пользователе
		void runCalculatorUI(); // Метод для запуска пользовательского интерфейса калькулятора калорий
};

