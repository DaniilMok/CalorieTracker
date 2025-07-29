#include "Activities.h" // Указывает относительный путь к Activities.h
#include<string> // Указывает относительный путь к string
#include <iostream> // Указывает относительный путь к iostream для ввода-вывода

using namespace std; // Используем пространство имен std для удобства

Activities::Activities(string name, double calBurn) // Конструктор для создания активности с именем и калориями, сжигаемыми за минуту
	: id(0), name(name), calories_burned_per_minute(calBurn) { // Инициализация полей id, name и calories_burned_per_minute
}

Activities::Activities(int id, string name, double calBurn) // Конструктор для создания активности с ID, именем и калориями, сжигаемыми за минуту
	: id(id), name(name), calories_burned_per_minute(calBurn) { // Инициализация полей id, name и calories_burned_per_minute
}

void Activities::printActivities() const { // Метод для вывода информации об активности
	cout << "ID: " << id << "\n" // Вывод ID активности
		<< "Активность: " << name << "\n" // Вывод названия активности
		<< "Калории сжигает в минуту: " << calories_burned_per_minute << "\n" // Вывод калорий, сжигаемых за минуту
		<< "---------------------------\n"; // Разделитель для удобства чтения
}
