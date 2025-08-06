#include "ProductDeleter.h"
#include <iostream>
#include <limits>

ProductDeleter::ProductDeleter(DataBase& db) : db_(db) {} // Конструктор принимает ссылку на базу данных

bool ProductDeleter::deleteById(int id) { // Функция для удаления продукта по ID
    return db_.deleteProductById(id);
}

bool ProductDeleter::deleteAll() { // Функция для удаления всех продуктов
    return db_.deleteAllProducts();
}

void ProductDeleter::runDeleteUI() { // Функция для запуска пользовательского интерфейса удаления продуктов
    std::cout << "1 - Удалить продукт по ID\n";
    std::cout << "2 - Удалить все продукты\n";
    int choice = 0; 
	while (true) { // Цикл для выбора действия
        std::cout << "Выбор: ";
        std::cin >> choice;
		if (std::cin.fail()) { // Проверка не произошла ли ошибка при вводе
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Вы не ввели ничего. Пожалуйста, выберите вариант из меню.\n";
            continue; 
        }
        if (choice == 1) {
			deleteByIdUI(); // Функция для запуска интерфейса удаления продукта по ID
            break;
        }
        else if (choice == 2) {
			deleteAllUI(); // Функция для запуска интерфейса удаления всех продуктов
            break;
        }
        else {
            std::cout << "Неверный выбор. Пожалуйста, выберите 1 или 2.\n";
        }
    }
}

void ProductDeleter::deleteByIdUI() { // Функция для отображения интерфейса удаления продукта по ID
	int passed = 0; // Переменная для отслеживания
    do {
        int id;
        std::cout << "Введите ID для удаления: ";
        std::cin >> id;
		if (std::cin.fail()) { // Проверка не произошла ли ошибка при вводе
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Вы не ввели ничего.\n";
            continue;
        }
		if (deleteById(id)) // Попытка удалить продукт по ID
            std::cout << "Удалено.\n";
        else
            std::cout << "Продукт с таким ID не найден.\n";

		std::string confirm; // Переменная для подтверждения удаления
		while (true) { // Цикл для подтверждения удаления
            std::cout << "Удалить еще один продукт? (y/n): ";
            std::cin >> confirm;
			if (confirm.empty()) { // Проверка на пустой ввод
                std::cout << "Выбор не может быть пустым. Пожалуйста, введите 'y' или 'n'.\n";
                continue;
            }
            else if (confirm == "y" || confirm == "Y") {
                passed = 0;
                break;
            }
            else if (confirm == "n" || confirm == "N") {
                passed = 1;
                break;
            }
            else {
                std::cout << "Неверный ввод. Пожалуйста, введите 'y' или 'n'.\n";
            }
        }
    } while (passed != 1);
}

void ProductDeleter::deleteAllUI() { // Функция для отображения интерфейса удаления всех продуктов
	std::string confirm; // Переменная для подтверждения удаления
    while (true) {
        std::cout << "Удалить все продукты? (y/n): ";
        std::cin >> confirm;
		if (confirm.empty()) { // Проверка на пустой ввод   
            std::cout << "Выбор не может быть пустым. Пожалуйста, введите 'y' или 'n'.\n";
            continue;
        }
        else if (confirm == "y" || confirm == "Y") {
			if (deleteAll()) // Попытка удалить все продукты    
                std::cout << "Все продукты удалены.\n";
            break;
        }
        else if (confirm == "n" || confirm == "N") {
            std::cout << "Удаление отменено.\n";
            break;
        }
        else {
            std::cout << "Неверный ввод. Пожалуйста, введите 'y' или 'n'.\n";
        }
    }
}