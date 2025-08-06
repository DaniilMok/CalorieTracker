#pragma once
#include<string> 

class Activities // Класс для представления активности
{
public: 
	int id; // ID активности
	std::string name; // Название активности
	double calories_burned_per_minute; // Количество калорий, сжигаемых за минуту

	Activities(std::string name, double calBurn); // Конструктор для создания активности с именем и калориями, сжигаемыми за минуту
	Activities(int id, std::string name, double calBurn); // Конструктор для создания активности с ID, именем и калориями, сжигаемыми за минуту

	void printActivities() const; // Функция для вывода информации об активности
};
