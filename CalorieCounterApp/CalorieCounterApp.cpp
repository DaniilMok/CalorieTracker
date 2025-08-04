#include "ActivitiesDeleter.h"
#include "ActivitiesInput.h"
#include "DataBase.h" // Указывает относительный путь к DataBase.h
#include "ProductDeleter.h"
#include "ProductInput.h"
#include "UserInput.h" // Указывает относительный путь к UserInput.h
#include "UserDeleter.h" // Указывает относительный путь к UserDeleter.h
#include <chrono>
#include <format> // Указывает относительный путь к format для работы с форматированием дат
#include <iostream>
#include <limits>
#include <sstream>// Указывает относительный путь к sstream для работы со строками

void showMainMenu() { // Функция для отображения меню
	std::cout << "Калькулятор калорий\n";
	std::cout << "\n1 - Открыть меню управления пользователями\n";
	std::cout << "2 - Рассчитать калории\n";
	std::cout << "3 - Открыть меню управления продуктами\n";
	std::cout << "4 - Открыть меню управления активностями\n";
	std::cout << "0 - Выход\n";
	std::cout << "Выбор: ";
}

void showAddUserMenu() {
	std::cout << "Меню управления пользователями\n";
	std::cout << "\n1 - Изменить данные пользователя\n";
	std::cout << "2 - Удалить пользователя\n";
	std::cout << "0 - Выход\n";
	std::cout << "Выбор: ";
}

void showCalorieCalculatorMenu() {
	std::cout << "Меню расчета калорий\n";
	std::cout << "\n1 - Рассчитать калории для пользователя\n";
	std::cout << "2 - Показать информацию о пользователе\n";
	std::cout << "3 - Изменить информацию о пользователе\n";
	std::cout << "0 - Выход\n";
	std::cout << "Выбор: ";
}

void showProductMenu() {
	std::cout << "Меню управления продуктами\n";
	std::cout << "\n1 - Добавить продукт\n";
	std::cout << "2 - Показать все продукты\n";
	std::cout << "3 - Удалить продукт из базы\n";
	std::cout << "0 - Выход\n";
	std::cout << "Выбор: ";
}

void showActivitiesMenu() {
	std::cout << "Меню управления активностями\n";
	std::cout << "\n1 - Добавить активность\n";
	std::cout << "2 - Посмотреть все активности\n";
	std::cout << "3 - Удалить активность из базы\n";
	std::cout << "0 - Выход\n";
	std::cout << "Выбор: ";
}

int main() { // Главная функция программы
	setlocale(LC_ALL, "Russian");

	DataBase db("calories.db"); // Создаем объект базы данных с именем файла "calories.db"
	ProductDeleter productDeleter(db); // Создаем объект ProductDeleter
	ActivitiesDeleter activitiesDeleter(db); // Создаем объект ActivitiesDeleter
	UserDeleter userDeleter(db); // Создаем объект UserDeleter для удаления пользователей
	UserInput input; // Создаем объект UserInput для ввода пользователя


	if (!db.createTableProducts()) return 1; // Создаем таблицу продуктов
	if (!db.createTableActivities()) return 1; // Создаем таблицу активностей
	if (!db.createTableUsers()) return 1; // Создаем таблицу пользователей
	if (!db.createTableInfoUsers()) return 1; // Создаем таблицу информации о пользователях
	if (!db.createTableUserActivities()) return 1; // Создаем таблицу активностей пользователей
	if (!db.createTableUserProducts()) return 1; // Создаем таблицу продуктов пользователей

	// Создание переменной с датой (без времени) для того чтобы определять когда пошел новый день , сбрасывать данные о калориях и добавлять дни в счетчик успешно выполненных дней
	std::chrono::system_clock::time_point currentDate = std::chrono::system_clock::now(); // Текущая дата и время
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<int, std::ratio<86400>>> currentDay = std::chrono::time_point_cast<std::chrono::duration<int, std::ratio<86400>>>(currentDate); // Текущий день без времени

	int userId = 0; // Переменная для хранения ID пользователя
	db.isUserExists(userId); // Проверяем, существует ли пользователь с данным ID
	// Проверка добавлен ли пользователь
	if (userId == 0) {
		std::cout << "Добавление пользователя\n";
		// Код для добавления нового пользователя
		User user = input.inputUser(); // Считываем данные пользователя
		db.addUser(user); // Добавляем пользователя в базу данных
	}
	else if (userId > 1) {
		std::cout << "Добавлено несколько пользователей, нужно выбрать только одного!\n";
		// Код для выбора пользователя
		std::cout << "Пожалуйста, выберите пользователя из списка, второй пользователь будет удален\n";
	}
	else if (userId < 0) {
		std::cout << "Произошла ошибка при добавлении пользователя, попробуйте еще раз.\n";
		return 1; // Завершаем программу с ошибкой
	}
	std::string userName = ""; // Переменная для хранения имени пользователя
	int userCalories = 0; // Переменная для хранения калорий пользователя
	int userWeight = 0; // Переменная для хранения веса пользователя
	std::string activityType = ""; // Переменная для хранения типа активности пользователя
	std::string foodType = ""; // Переменная для хранения типа питания пользователя

	int choiceMainMenu; // Переменная для выбора действия в меню
	do {
		do
		{
			showMainMenu(); // Отображаем меню
			std::cin >> choiceMainMenu; // Считываем выбор пользователя
			if (std::cin.fail()) {  // Проверяем, не произошла ли ошибка при вводе
				std::cin.clear(); // Сбрасываем состояние потока
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем ввод
				std::cout << "Вы не ввели ничего или ввели иной символ. Пожалуйста, выберите вариант из меню.\n";
				continue; // Продолжаем цикл для повторного ввода
			}
			else
				break; // Выходим из цикла, если введено корректное значение
		} while (true);

		int choiceActivitiesMenu;
		int choiceProductMenu;

		switch (choiceMainMenu) { // Преобразуем строку в целое число для обработки выбора пользователя
			case 1: {
				int choiceAddUserMenu;
				do
				{
					do
					{
						showAddUserMenu(); // Отображаем меню добавления пользователя
						std::cin >> choiceAddUserMenu; // Считываем выбор пользователя
						if (std::cin.fail()) {  // Проверяем, не произошла ли ошибка при вводе
							std::cin.clear(); // Сбрасываем состояние потока
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем ввод
							std::cout << "Вы не ввели ничего или ввели иной символ. Пожалуйста, выберите вариант из меню.\n";
							continue; // Продолжаем цикл для повторного ввода
						}
						else
							break; // Выходим из цикла, если введено корректное значение
					} while (true);
					switch (choiceAddUserMenu) {
					case 1: {
						break;
					}
					case 2: {
						// Код для удаления пользователя
						userDeleter.runDeleteUI(); // Запускаем пользовательский интерфейс удаления пользователя
						break;
					}
					default: { // Если пользователь ввел неверный вариант
						if (choiceAddUserMenu != 0) { // Если пользователь не выбрал выход из программы
							std::cout << "Неверный выбор. Пожалуйста, выберите вариант из меню.\n"; // Выводим сообщение об ошибке
							choiceAddUserMenu = -1; // Сбрасываем выбор пользователя
							continue; // Продолжаем цикл для повторного выбора действия
						}
						break;
					}
					}
				} while (choiceAddUserMenu != 0); // Продолжаем цикл до тех пор, пока пользователь не выберет выход из программы
				break; // Выходим из цикла, если пользователь выбрал выход из программы
			}

			case 2: {
				int choiceCalorieCalculatorMenu = 0;
				do
				{
					do
					{
						showCalorieCalculatorMenu(); // Отображаем меню
						std::cin >> choiceCalorieCalculatorMenu; // Считываем выбор пользователя
						if (std::cin.fail()) {  // Проверяем, не произошла ли ошибка при вводе
							std::cin.clear(); // Сбрасываем состояние потока
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем ввод
							std::cout << "Вы не ввели ничего или ввели иной символ. Пожалуйста, выберите вариант из меню.\n";
							continue; // Продолжаем цикл для повторного ввода
						}
						else
							break; // Выходим из цикла, если введено корректное значение
					} while (true);
					switch (choiceCalorieCalculatorMenu) {
					case 1: { // Рассчитать калории для пользователя
						break;
					}
					case 2: { // Показать информацию о пользователе
						// Код для показа информации о пользователе
						break;
					}
					case 3: { // Изменить информацию о пользователе
						// Код для изменения информации о пользователе
						break;
					}
					default: { // Если пользователь ввел неверный вариант
						if (choiceCalorieCalculatorMenu != 0) { // Если пользователь не выбрал выход из программы
							std::cout << "Неверный выбор. Пожалуйста, выберите вариант из меню.\n"; // Выводим сообщение об ошибке
							choiceCalorieCalculatorMenu = -1;
							continue; // Продолжаем цикл для повторного выбора действия
						}
					} while (true);

						   break;
					}
				} while (choiceCalorieCalculatorMenu != 0); // Продолжаем цикл до тех пор, пока пользователь не выберет выход из программы
			}

			case 3: {
				do
				{
					do
					{
						showProductMenu(); // Отображаем меню
						std::cin >> choiceProductMenu; // Считываем выбор пользователя
						if (std::cin.fail()) {  // Проверяем, не произошла ли ошибка при вводе
							std::cin.clear(); // Сбрасываем состояние потока
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем ввод
							std::cout << "Вы не ввели ничего или ввели иной символ. Пожалуйста, выберите вариант из меню.\n";
							continue; // Продолжаем цикл для повторного ввода
						}
						else
							break; // Выходим из цикла, если введено корректное значение
					} while (true);

					switch (choiceProductMenu)
					{
					case 1: { // Добавление продукта
						ProductInput input;
						Product p = input.inputProduct();
						db.addProduct(p);
						break;
					}
					case 2: { // Показать все продукты
						auto list = db.getAllProducts(); // Получаем список всех продуктов из базы данных
						for (const auto& p : list) { // Перебираем все продукты в списке
							p.printProducts(); // Выводим информацию о каждом продукте
						}
						break;
					}
					case 3: { // Удаление продукта
						productDeleter.runDeleteUI();
						break;
					}

					default:
						if (choiceProductMenu != 0) { // Если пользователь не выбрал выход из программы
							std::cout << "Неверный выбор. Пожалуйста, выберите вариант из меню.\n"; // Выводим сообщение об ошибке
							choiceProductMenu = -1; // Сбрасываем выбор пользователя
							continue; // Продолжаем цикл для повторного выбора действия
						}
						break; // Выходим из цикла, если пользователь выбрал выход из программы
					}

					break;

				} while (choiceProductMenu != 0);
				break;
			}

			case 4: {
				do
				{
					do
					{
						showActivitiesMenu(); // Отображаем меню
						std::cin >> choiceActivitiesMenu; // Считываем выбор пользователя
						if (std::cin.fail()) {  // Проверяем, не произошла ли ошибка при вводе
							std::cin.clear(); // Сбрасываем состояние потока
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем ввод
							std::cout << "Вы не ввели ничего или ввели иной символ. Пожалуйста, выберите вариант из меню.\n";
							continue; // Продолжаем цикл для повторного ввода
						}
						else
							break; // Выходим из цикла, если введено корректное значение
					} while (true);

					switch (choiceActivitiesMenu)
					{
					case 1: {
						ActivitiesInput input; // Создаем объект ActivitiesInput для ввода активности
						Activities a = input.inputActivities(); // Считываем данные об активности
						db.addActivities(a); // Добавляем активность в базу данных
						break;
					}

					case 2: {
						auto list = db.getAllActivities();
						for (const auto& a : list) { // Перебираем все активности в списке
							a.printActivities(); // Выводим информацию о каждой активности
						}
						break;
					}
					case 3: {
						activitiesDeleter.runDeleteUI(); // Запускаем пользовательский интерфейс удаления активностей
						break;
					}
					default: {
						if (choiceActivitiesMenu != 0) { // Если пользователь не выбрал выход из программы
							std::cout << "Неверный выбор. Пожалуйста, выберите вариант из меню.\n"; // Выводим сообщение об ошибке
							choiceActivitiesMenu = -1; // Сбрасываем выбор пользователя
							continue; // Продолжаем цикл для повторного выбора действия
						}
						break; // Выходим из цикла, если пользователь выбрал выход из программы
					}

						   break;

					}
				} while (choiceActivitiesMenu != 0);
				break;
			}

			default: {// Если пользователь ввел неверный вариант
				if (choiceMainMenu != 0) { // Если пользователь не выбрал выход из программы
					std::cout << "Неверный выбор. Пожалуйста, выберите вариант из меню.\n"; // Выводим сообщение об ошибке
					choiceMainMenu = -1; // Сбрасываем выбор пользователя
					continue; // Продолжаем цикл для повторного выбора действия
				}
				break; // Выходим из цикла, если пользователь выбрал выход из программы
			}
		}
	} while (choiceMainMenu != 0); // Продолжаем цикл до тех пор, пока пользователь не выберет выход из программы
	// Закрываем базу данных перед выходом из программы
	db.~DataBase(); // Вызываем деструктор базы данных для закрытия соединения с базой данных
	std::cout << "Вы вышли из программы.\n"; // Выводим сообщение о выходе из программы
	return 0;
}
