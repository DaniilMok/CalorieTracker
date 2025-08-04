#include "ActivitiesInput.h"
#include "ActivitiesInput.h"
#include "InputHelper.h"
#include <iostream>
#include <string>

Activities ActivitiesInput::inputActivities() {
    std::string name;
    std::cin.ignore();
    std::cout << "�������� ����������: ";
    std::getline(std::cin, name);
    while (name.empty()) {
        std::cout << "�������� �� ����� ���� ������.\n������� �������� ����������: ";
        std::getline(std::cin, name);
    }

    double calories = inputPositiveNumber<double>("������� ������� � ������: ");

    return Activities(name, calories);
}
