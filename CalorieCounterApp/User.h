#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>

class User {
	public:
		int id; // ID пользователя
        std::string name;
        std::string gender;
        double years;
        double growth;
        double weight;
        std::string activity_type;
        std::string food_type;

    User(std::string name, std::string gender, double years, double growth, double weight, std::string activity_type, std::string food_type);
	User(int id, std::string name, std::string gender, double years, double growth, double weight, std::string activity_type, std::string food_type);

    void printUser() const; // Функция для вывода информации о пользователе
};

#endif