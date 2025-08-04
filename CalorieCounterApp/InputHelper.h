#pragma once
#include <iostream>
#include <limits>
#include <string>

template<typename T>
T inputPositiveNumber(const std::string& prompt) {
    T value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || value < 0) {
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

/*void inputIdUser(int& userId) {
    while (true)
    {
        if (userId == 0) {
            cout << "Пожалуйста, выберите пользователя перед показом информации.\n";
            continue; // Пропускаем дальнейшие действия, если пользователь не выбран
        }
    }
}*/
