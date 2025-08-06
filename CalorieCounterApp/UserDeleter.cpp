#include "UserDeleter.h"
#include <iostream>
#include <limits>
#include <string>

int UserDeleter::runDeleteUI(int& choiceUserMenu) { // Функция для пользовательского интерфейса удаления пользователя
	std::cout << "Меню удаления пользователя\n";
	std::cout << "\n1 - Удалить пользователя\n";
	std::cout << "0 - Выход\n";
	int choice; // Переменная для выбора действия в меню удаления пользователя
	while (true) 
	{
		std::cin >> choice;
		if (std::cin.fail()) { // Проверяем, не произошла ли ошибка при вводе
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Вы не ввели ничего. Пожалуйста, выберите вариант из меню.\n";
			continue;
		}
		if (choice == 1) {
			db.deleteUser(); // Удаляем пользователя из базы данных
			std::cout << "Пользователь успешно удален.\n";
			std::cout << "Вы можете добавить нового пользователя.\n";
			std::cout << "Возвращение в главное меню.\n";
			choice = 0;
			choiceUserMenu = 0;	// Сбрасываем выбор меню пользователя
			return 0; // Возвращаем 0, если пользователь успешно удален
			break;
		}

		if (choice == 0) {
			std::cout << "Выход из меню\n";
			break;
		}
	}
}
