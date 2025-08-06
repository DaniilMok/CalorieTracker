#include "Activities.h" 
#include <iostream> 

Activities::Activities(std::string name, double calBurn) // Конструктор для создания активности с именем и калориями, сжигаемыми за минуту
	: id(0), name(name), calories_burned_per_minute(calBurn) { 
}

Activities::Activities(int id, std::string name, double calBurn) // Конструктор для создания активности с ID, именем и калориями, сжигаемыми за минуту
	: id(id), name(name), calories_burned_per_minute(calBurn) { 
}

void Activities::printActivities() const { // Функция для вывода информации об активности
	std::cout << "ID: " << id << "\n"
		<< "Активность: " << name << "\n" 
		<< "Калории сжигает в минуту: " << calories_burned_per_minute << "\n"
		<< "---------------------------\n";
}
