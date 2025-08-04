#include "ActivitiesDeleter.h"
#include <iostream>
#include <limits>

using namespace std;

ActivitiesDeleter::ActivitiesDeleter(DataBase& db) : db(db) {} 

bool ActivitiesDeleter::deleteActivityById(int id) {
	return db.deleteActivityById(id);
}

bool ActivitiesDeleter::deleteAllActivities() {
	return db.deleteAllActivities();
}

void ActivitiesDeleter::runDeleteUI() {
	cout << "1 - Удалить активность по ID\n";
	cout << "2 - Удалить все активности\n";
	int choice = 0;
	while (true) {
		cout << "Выбор: ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Вы не ввели ничего. Пожалуйста, выберите вариант из меню.\n";
			continue;
		}
		if (choice == 1) {
			deleteByIdUI();
			break;
		}
		else if (choice == 2) {
			deleteAllUI();
			break;
		}
		else {
			cout << "Неверный выбор. Пожалуйста, выберите 1 или 2.\n";
		}
	}
}

void ActivitiesDeleter::deleteByIdUI() {
	int passed = 0;
	do {
		int id;
		cout << "Введите ID для удаления: ";
		cin >> id;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Вы не ввели ничего.\n";
			continue;
		}
		if (deleteActivityById(id))
			cout << "Удалено.\n";
		else
			cout << "Активность с таким ID не найдена.\n";
		passed++;
	} while (passed < 1);
}

void ActivitiesDeleter::deleteAllUI() {
	int passed = 0;
	do {
		cout << "Вы уверены, что хотите удалить все активности? (y/n): ";
		char confirm;
		cin >> confirm;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Вы не ввели ничего.\n";
			continue;
		}
		if (confirm == 'y' || confirm == 'Y') {
			if (deleteAllActivities())
				cout << "Все активности удалены.\n";
			else
				cout << "Ошибка при удалении активностей.\n";
		}
		passed++;
	} while (passed < 1);
}
