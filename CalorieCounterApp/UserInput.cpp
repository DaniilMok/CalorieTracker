#include "UserInput.h"
#include "InputHelper.h"
#include <iostream>
#include <limits>

using namespace std;

User UserInput::inputUser() { // Функция для ввода данных пользователя
	string gender; // Переменная для хранения пола пользователя
	int choice_gender; // Переменная для выбора пола пользователя
	do
	{
		do { // Цикл для ввода пола пользователя
			cout << "Введите пол (1 - мужской, 2 - женский): ";
			cin >> choice_gender;
			if (cin.fail()) {
				cin.clear(); // Сбрасываем состояние потока
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем остаток строки
				cout << "Ошибка ввода. Пожалуйста, введите число от 1 до 3.\n";
				continue; // Продолжаем цикл для повторного ввода
			}
			switch (choice_gender) {
			case 1:
				gender = "Мужской";
				break;
			case 2:
				gender = "Женский";
				break;
			default:
				cout << "Неверный пол. Пожалуйста, введите (1 - мужской, 2 - женский).\n";
				gender.clear(); // Очищаем строку для повторного ввода
				break;
			}
		} while (gender.empty()); // Продолжаем цикл, пока не введен корректный пол
	} while (gender.empty());

	string name; // Переменная для хранения имени пользователя
	cout << "Введите имя пользователя: ";
	cin.ignore();
	getline(cin, name);
	while (name.empty()) {
		cout << "Имя не может быть пустым. Пожалуйста, введите имя: ";
		getline(cin, name);
	}
	// Ввод возраста, роста и веса пользователя
	double years = inputPositiveNumber<double>("Введите возраст (в годах): ");
	double growth = inputPositiveNumber<double>("Введите рост (в см): ");
	double weight = inputPositiveNumber<double>("Введите вес (в кг): ");
	
	string activity_type;
	int choice_activity;
	do
	{
		do { // Цикл для ввода типа активности пользователя
		cout << "Введите тип активности (1 - низкая, 2 - средняя, 3 - высокая): ";
		cin >> choice_activity;
		if (cin.fail()) {
			cin.clear(); // Сбрасываем состояние потока
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем остаток строки
			cout << "Ошибка ввода. Пожалуйста, введите число от 1 до 3.\n";
			continue; // Продолжаем цикл для повторного ввода
		}
		switch (choice_activity) {
			case 1:
				activity_type = "низкая";
				break;
			case 2:
				activity_type = "средняя";
				break;
			case 3:
				activity_type = "высокая";
				break;
			default:
				cout << "Неверный тип активности. Пожалуйста, введите (1 - низкая, 2 - средняя, 3 - высокая).\n";
				activity_type.clear(); // Очищаем строку для повторного ввода
				break;
		}
		} while (activity_type.empty());
	} while (activity_type.empty());

	int choice_food;
	string food_type;
	do
	{
		do { // Цикл для ввода типа питания пользователя
		cout << "Введите тип питания (1 - с мясом, 2 - без мяса): ";
		cin >> choice_food;		
		if (cin.fail()) {
			cin.clear(); // Сбрасываем состояние потока
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем остаток строки
			cout << "Ошибка ввода. Пожалуйста, введите число от 1 до 2.\n";
			continue; // Продолжаем цикл для повторного ввода
		}
		switch (choice_food) {
			case 1:
				food_type = "с мясом";
				break;
			case 2:
				food_type = "без мяса";
				break;
			default:
				cout << "Неверный тип питания. Пожалуйста, введите (1 - с мясом, 2 - без мяса).\n";
				food_type.clear(); // Очищаем строку для повторного ввода
				break;
		}
		} while (food_type.empty());
	} while (food_type.empty());

	return User(name, gender, years, growth, weight, activity_type, food_type);
}
