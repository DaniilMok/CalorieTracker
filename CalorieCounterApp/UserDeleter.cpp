#include "UserDeleter.h"
#include <iostream>
#include <limits>
#include <string>

int UserDeleter::runDeleteUI() {
	std::cout << "Меню удаления пользователя\n";
	std::cout << "\n1 - Удалить пользователя\n";
	std::cout << "0 - Выход\n";
	int choice;
	while (true)
	{
		std::cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Вы не ввели ничего. Пожалуйста, выберите вариант из меню.\n";
			continue;
		}
		if (choice == 1) {
			db.deleteUser();
			std::cout << "Пользователь успешно удален.\n";
			return 0; // Возвращаем 0, если пользователь успешно удален
		}

		if (choice == 0) {
			std::cout << "Выход из меню\n";
			break;
		}
	}
}
