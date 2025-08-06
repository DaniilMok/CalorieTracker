#pragma once
#include <iostream>
#include <limits>
#include <string>

template<typename T> // Функция для ввода положительного числа с проверкой
T inputPositiveNumber(const std::string& prompt) { // Шаблонная функция для ввода положительного числа
	T value; // Переменная для хранения введенного значения
    while (true) {
        std::cout << prompt;
        std::cin >> value;
		if (std::cin.fail() || value < 0) { // Проверяем, не произошла ли ошибка при вводе и является ли значение отрицательным
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка ввода, введите положительное число.\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистить остаток строки
            return value;
        }
    }
}