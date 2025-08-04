#include "ActivitiesDelete.h"
#include <iostream>
#include <limits>

ActivitiesDelete::ActivitiesDelete(DataBase& database) : db(database) {}

bool ActivitiesDelete::deleteActivityById(int id) {
	return db.deleteActivityById(id);
}

bool ActivitiesDelete::deleteAllActivities() {
	return db.deleteAllActivities();
}

void ActivitiesDelete::runDeleteUI() {
	std::cout << "1 - Удалить активность по ID\n";
	std::cout << "2 - Удалить все активности\n";
	int choice = 0;
	while (true) {
		std::cout << "Выбор: ";
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Вы не ввели ничего. Пожалуйста, выберите вариант из меню.\n";
			continue;
		}
		if (choice == 1) {
			deleteByIdUI();
			break;
		} else if (choice == 2) {
			deleteAllUI();
			break;
		} else {
			std::cout << "Неверный выбор. Пожалуйста, выберите 1 или 2.\n";
		}
	}
}

void ActivitiesDelete::deleteByIdUI() {
	int passed = 0;
	do
	{
		int id;
		std::cout << "Введите ID для удаления: ";
		std::cin >> id;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Вы не ввели ничего.\n";
			continue;
		}
		if (deleteActivityById(id)) {
			std::cout << "Активность успешно удалена.\n";
			passed = 1; // Успешное удаление
		} else {
			std::cout << "Активность с таким ID не найдена.\n";
			passed = 0; // Неудачное удаление
		}
		std::string confirm;
		while (true) {
			std::cout << "Хотите удалить еще одну активность? (y/n): ";
			std::cin >> confirm;
			if (confirm.empty()) {
				std::cout << "Выбор не может быть пустым. Пожалуйста, введите 'y' или 'n'.\n";
				continue;
			}
			if (confirm == "y" || confirm == "Y") {
				passed = 0; // Продолжаем цикл
				break;
			} else if (confirm == "n" || confirm == "N") {
				passed = 1; // Завершаем цикл
				break;
			} else {
				std::cout << "Неверный выбор. Пожалуйста, введите 'y' или 'n'.\n";
			}
		}
	} while (passed != 1);
}

void ActivitiesDelete::deleteAllUI() {
	std::string confirm;
	while (true) {
		std::cout << "Вы уверены, что хотите удалить все активности? (y/n): ";
		std::cin >> confirm;
		if (confirm.empty()) {
			std::cout << "Выбор не может быть пустым. Пожалуйста, введите 'y' или 'n'.\n";
			continue;
		}
		if (confirm == "y") {
			if (deleteAllActivities()) {
				std::cout << "Все активности успешно удалены.\n";
			} else {
				std::cout << "Ошибка при удалении всех активностей.\n";
			}
		} else if (confirm == "n") {
			std::cout << "Удаление всех активностей отменено.\n";
		} else {
			std::cout << "Неверный выбор. Пожалуйста, введите 'y' или 'n'.\n";
		}
	}
}