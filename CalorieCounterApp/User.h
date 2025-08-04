#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>

using namespace std;

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

    User(string name, string gender, double years, double growth, double weight, string activity_type, string food_type);
	User(int id, string name, string gender, double years, double growth, double weight, string activity_type, string food_type);

    void printUser() const; // Метод для вывода информации о пользователе
};

#endif