#include "User.h"
#include <iostream>
#include <limits>

User::User(std::string name, std::string gender, double years, double growth, double weight, std::string activity_type, std::string food_type) // Конструктор для создания пользователя
	: name(name), gender(gender), years(years), growth(growth), weight(weight), activity_type(activity_type), food_type(food_type) {
}
User::User(int id, std::string name, std::string gender, double years, double growth, double weight, std::string activity_type, std::string food_type) // Конструктор для создания пользователя с ID
	: name(name), gender(gender), years(years), growth(growth), weight(weight), activity_type(activity_type), food_type(food_type) {
	this->id = id; // Инициализация ID пользователя
}
void User::printUser() const { // Функция для вывода информации о пользователе
	std::cout << "ID: " << id << "\n"
		<< "Имя: " << name << "\n"
		<< "Пол: " << gender << "\n"
		<< "Возраст: " << years << " лет\n"
		<< "Рост: " << growth << " см\n"
		<< "Вес: " << weight << " кг\n"
		<< "Тип активности: " << activity_type << "\n"
		<< "Тип питания: " << food_type << "\n"
		<< "---------------------------\n";
}