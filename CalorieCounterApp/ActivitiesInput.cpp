#include "ActivitiesInput.h"
#include "ActivitiesInput.h"
#include "InputHelper.h"
#include <iostream>
#include <string>

Activities ActivitiesInput::inputActivities() {
    std::string name;
    std::cin.ignore();
    std::cout << "Название активности: ";
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cout << "Название не может быть пустым.\nВведите название активности: ";
        std::getline(std::cin, name);
    }

    double calories = inputPositiveNumber<double>("Калорий сгорает в минуту: ");

    return Activities(name, calories);
}
