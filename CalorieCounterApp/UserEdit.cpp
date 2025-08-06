#include "UserEdit.h"
#include "DataBase.h"

DataBase db("calorie_counter.db"); // Создаем объект базы данных
UserEdit userEdit; // Создаем объект UserEdit для редактирования пользователя


void UserEdit::showEditUserMenu() { // Функция для отображения меню редактирования пользователя
	std::cout << "Меню редактирования пользователя\n";
	std::cout << "\n1 - Изменить имя пользователя\n";
	std::cout << "2 - Изменить возраст пользователя\n";
	std::cout << "3 - Изменить вес пользователя\n";
	std::cout << "4 - Изменить рост пользователя\n";
	std::cout << "5 - Изменить пол пользователя\n";
	std::cout << "6 - Изменить тип питания\n";
	std::cout << "7 - Изменить тип активности\n";
	std::cout << "0 - Выход\n";
	std::cout << "Выбор: ";
}
void UserEdit::choiceEditUser() { // Функция для выбора действия в меню редактирования пользователя
	int choiceEditUserMenu = 0;
	do {
		do {
			showEditUserMenu(); // Отображаем меню редактирования пользователя
			std::cin >> choiceEditUserMenu; 
			if (std::cin.fail()) {  // Проверяем, не произошла ли ошибка при вводе
				std::cin.clear(); // Сбрасываем состояние потока
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем ввод
				std::cout << "Вы не ввели ничего или ввели иной символ. Пожалуйста, выберите вариант из меню.\n";
				continue; // Продолжаем цикл для повторного ввода
			}
			else {
				break; // Выходим из цикла, если введено корректное значение
			}
		} while (true);
		switch (choiceEditUserMenu) {
		case 1: {
			std::string newName;
			std::cout << "Введите новое имя пользователя: ";
			std::cin >> newName;
			userEdit.editUserName(newName); // Изменяем имя пользователя
			break;
		}
		// Добавить остальные 
		}
	} while (choiceEditUserMenu != 0); // Выходим из цикла, если пользователь выбрал выход из программы
}

void UserEdit::editUserName(std::string& newName) { // Функция для изменения имени пользователя
	std::string name;
	db.editUser("name", newName); // Вызов функции редактирования имени пользователя в базе данных
	std::cout << "Имя пользователя изменено на: " << newName << std::endl;
}
