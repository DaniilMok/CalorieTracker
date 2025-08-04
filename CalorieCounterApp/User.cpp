#include "User.h"
#include <iostream>
#include <limits>


using namespace std;

User::User(string name, string gender, double years, double growth, double weight, string activity_type, string food_type)
	: name(name), gender(gender), years(years), growth(growth), weight(weight), activity_type(activity_type), food_type(food_type) {
}
User::User(int id, string name, string gender, double years, double growth, double weight, string activity_type, string food_type)
	: name(name), gender(gender), years(years), growth(growth), weight(weight), activity_type(activity_type), food_type(food_type) {
	this->id = id; // Инициализация ID пользователя
}
void User::printUser() const { // Метод для вывода информации о пользователе
	cout << "ID: " << id << "\n"
		<< "Имя: " << name << "\n"
		<< "Пол: " << gender << "\n"
		<< "Возраст: " << years << " лет\n"
		<< "Рост: " << growth << " см\n"
		<< "Вес: " << weight << " кг\n"
		<< "Тип активности: " << activity_type << "\n"
		<< "Тип питания: " << food_type << "\n"
		<< "---------------------------\n"; // Разделитель для удобства чтения
}