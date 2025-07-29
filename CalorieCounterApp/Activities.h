#pragma once
#include<string> // Указывает относительный путь к string

using namespace std; // Используем пространство имен std для удобства

class Activities // Класс для представления активности
{
public: 
	int id; // ID активности
	string name; // Название активности
	double calories_burned_per_minute; // Количество калорий, сжигаемых за минуту

	Activities(string name, double calBurn); // Конструктор для создания активности с именем и калориями, сжигаемыми за минуту
	Activities(int id, string name, double calBurn); // Конструктор для создания активности с ID, именем и калориями, сжигаемыми за минуту

	void printActivities() const; // Метод для вывода информации об активности
};

