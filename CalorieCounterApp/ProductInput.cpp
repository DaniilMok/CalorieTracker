#include "ProductInput.h"
#include "InputHelper.h"
#include <iostream>
#include <string>

Product ProductInput::inputProduct() { // Функция для ввода информации о продукте
    std::string name;
    std::cin.ignore();
    std::cout << "Название: ";
    std::getline(std::cin, name);
	while (name.empty()) { // Проверка на пустое название
        std::cout << "Название не может быть пустым. Введите название: ";
        std::getline(std::cin, name);
    }

	// Ввод питательных веществ, с проверкой ввода
    double kcal = inputPositiveNumber<double>("Ккал: ");
    double protein = inputPositiveNumber<double>("Белки: ");
    double fat = inputPositiveNumber<double>("Жиры: ");
    double carbs = inputPositiveNumber<double>("Углеводы: ");

    return Product(name, kcal, protein, fat, carbs);
}
