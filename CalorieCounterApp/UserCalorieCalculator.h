// Реализовать!!!

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
		bool addFoodToUser(int userId, const std::string& foodName, int foodCalories); // Функция для добавления продукта к пользователю
		bool addActivityToUser(int userId, const std::string& activityName, int activityCalories); // Функция для добавления активности к пользователю
	public:
		explicit UserCalorieCalculator(DataBase& db); // Конструктор, принимающий ссылку на объект базы данных
		void calculateCalories(); // Функция для расчета калорий пользователя
		void showUserInfo(); // Функция для отображения информации о пользователе
		void updateUserInfo(); // Функция для обновления информации о пользователе
		void runCalculatorUI(); // Функция для запуска пользовательского интерфейса калькулятора калорий
};

