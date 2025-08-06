#include "ActivitiesDeleter.h"
#include <iostream>
#include <limits>

ActivitiesDeleter::ActivitiesDeleter(DataBase& db) : db(db) {} // Конструктор, принимающий ссылку на объект базы данных

bool ActivitiesDeleter::deleteActivityById(int id) { // Функция передающий ID активности для удаления
	return db.deleteActivityById(id);
}

bool ActivitiesDeleter::deleteAllActivities() { // Функция для удаления всех активностей из базы данных
	return db.deleteAllActivities();
}

void ActivitiesDeleter::runDeleteUI() { // Функция для запуска интерфейса удаления активностей
	std::cout << "1 - Удалить активность по ID\n";
	std::cout << "2 - Удалить все активности\n";
	int choice = 0;
	while (true) { // Цикл для выбора действия
		std::cout << "Выбор: ";
		std::cin >> choice;
		if (std::cin.fail()) { // Проверка на ввод некорректных данных
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Вы не ввели ничего. Пожалуйста, выберите вариант из меню.\n";
			continue; 
		}
		if (choice == 1) {
			deleteByIdUI(); // Вызов Функцияа для удаления активности по ID
			break;
		}
		else if (choice == 2) {
			deleteAllUI(); // Вызов Функцияа для удаления всех активностей
			break;
		}
		else {
			std::cout << "Неверный выбор. Пожалуйста, выберите 1 или 2.\n";
		}
	}
}

void ActivitiesDeleter::deleteByIdUI() { // Функция для удаления активности по ID через пользовательский интерфейс
	int passed = 0; // Переменная для отслеживания успешного выполнения операции 
	do {
		int id;
		std::cout << "Введите ID для удаления: ";
		std::cin >> id;
		if (std::cin.fail()) { // Проверка на ввод некорректных данных
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Вы не ввели ничего.\n";
			continue;
		}
		if (deleteActivityById(id)) // Вызов Функцияа для удаления активности по ID
			std::cout << "Удалено.\n";
		else
			std::cout << "Активность с таким ID не найдена.\n";
		passed = 1;
	} while (passed != 1);
}

void ActivitiesDeleter::deleteAllUI() { // Функция для удаления всех активностей через пользовательский интерфейс
	int passed = 0; // Переменная для отслеживания успешного выполнения операции
	do {
		std::cout << "Вы уверены, что хотите удалить все активности? (y/n): ";
		char confirm;
		std::cin >> confirm;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Вы не ввели ничего.\n";
			continue;
		}
		if (confirm == 'y' || confirm == 'Y') { // Проверка на подтверждение удаления
			if (deleteAllActivities()) // Вызов Функцияа для удаления всех активностей
				std::cout << "Все активности удалены.\n";
			else
				std::cout << "Ошибка при удалении активностей.\n";
		}
		passed = 1;
	} while (passed != 1);
}
