#include "ActivitiesInput.h"
#include "InputHelper.h"
#include <iostream>
#include <string>

Activities ActivitiesInput::inputActivities() { // Функция для ввода активности
    std::string name;
    std::cin.ignore();
    std::cout << "Название активности: ";
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cout << "Название не может быть пустым.\nВведите название активности: ";
        std::getline(std::cin, name);
    }

    double calories = inputPositiveNumber<double>("Калорий сгорает в минуту: "); // Передача данных Функцияу с проверкой ввода

    return Activities(name, calories);
}
