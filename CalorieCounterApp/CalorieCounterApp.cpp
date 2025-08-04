#include "ActivitiesDeleter.h"
#include "ActivitiesInput.h"
#include "DataBase.h" // ��������� ������������� ���� � DataBase.h
#include "ProductDeleter.h"
#include "ProductInput.h"
#include "UserInput.h" // ��������� ������������� ���� � UserInput.h
#include "UserDeleter.h" // ��������� ������������� ���� � UserDeleter.h
#include <chrono>
#include <format> // ��������� ������������� ���� � format ��� ������ � ��������������� ���
#include <iostream>
#include <limits>
#include <sstream>// ��������� ������������� ���� � sstream ��� ������ �� ��������

void showMainMenu() { // ������� ��� ����������� ����
	std::cout << "����������� �������\n";
	std::cout << "\n1 - ������� ���� ���������� ��������������\n";
	std::cout << "2 - ���������� �������\n";
	std::cout << "3 - ������� ���� ���������� ����������\n";
	std::cout << "4 - ������� ���� ���������� ������������\n";
	std::cout << "0 - �����\n";
	std::cout << "�����: ";
}

void showAddUserMenu() {
	std::cout << "���� ���������� ��������������\n";
	std::cout << "\n1 - �������� ������ ������������\n";
	std::cout << "2 - ������� ������������\n";
	std::cout << "0 - �����\n";
	std::cout << "�����: ";
}

void showCalorieCalculatorMenu() {
	std::cout << "���� ������� �������\n";
	std::cout << "\n1 - ���������� ������� ��� ������������\n";
	std::cout << "2 - �������� ���������� � ������������\n";
	std::cout << "3 - �������� ���������� � ������������\n";
	std::cout << "0 - �����\n";
	std::cout << "�����: ";
}

void showProductMenu() {
	std::cout << "���� ���������� ����������\n";
	std::cout << "\n1 - �������� �������\n";
	std::cout << "2 - �������� ��� ��������\n";
	std::cout << "3 - ������� ������� �� ����\n";
	std::cout << "0 - �����\n";
	std::cout << "�����: ";
}

void showActivitiesMenu() {
	std::cout << "���� ���������� ������������\n";
	std::cout << "\n1 - �������� ����������\n";
	std::cout << "2 - ���������� ��� ����������\n";
	std::cout << "3 - ������� ���������� �� ����\n";
	std::cout << "0 - �����\n";
	std::cout << "�����: ";
}

int main() { // ������� ������� ���������
	setlocale(LC_ALL, "Russian");

	DataBase db("calories.db"); // ������� ������ ���� ������ � ������ ����� "calories.db"
	ProductDeleter productDeleter(db); // ������� ������ ProductDeleter
	ActivitiesDeleter activitiesDeleter(db); // ������� ������ ActivitiesDeleter
	UserDeleter userDeleter(db); // ������� ������ UserDeleter ��� �������� �������������
	UserInput input; // ������� ������ UserInput ��� ����� ������������


	if (!db.createTableProducts()) return 1; // ������� ������� ���������
	if (!db.createTableActivities()) return 1; // ������� ������� �����������
	if (!db.createTableUsers()) return 1; // ������� ������� �������������
	if (!db.createTableInfoUsers()) return 1; // ������� ������� ���������� � �������������
	if (!db.createTableUserActivities()) return 1; // ������� ������� ����������� �������������
	if (!db.createTableUserProducts()) return 1; // ������� ������� ��������� �������������

	// �������� ���������� � ����� (��� �������) ��� ���� ����� ���������� ����� ����� ����� ���� , ���������� ������ � �������� � ��������� ��� � ������� ������� ����������� ����
	std::chrono::system_clock::time_point currentDate = std::chrono::system_clock::now(); // ������� ���� � �����
	std::chrono::time_point<std::chrono::system_clock, std::chrono::duration<int, std::ratio<86400>>> currentDay = std::chrono::time_point_cast<std::chrono::duration<int, std::ratio<86400>>>(currentDate); // ������� ���� ��� �������

	int userId = 0; // ���������� ��� �������� ID ������������
	db.isUserExists(userId); // ���������, ���������� �� ������������ � ������ ID
	// �������� �������� �� ������������
	if (userId == 0) {
		std::cout << "���������� ������������\n";
		// ��� ��� ���������� ������ ������������
		User user = input.inputUser(); // ��������� ������ ������������
		db.addUser(user); // ��������� ������������ � ���� ������
	}
	else if (userId > 1) {
		std::cout << "��������� ��������� �������������, ����� ������� ������ ������!\n";
		// ��� ��� ������ ������������
		std::cout << "����������, �������� ������������ �� ������, ������ ������������ ����� ������\n";
	}
	else if (userId < 0) {
		std::cout << "��������� ������ ��� ���������� ������������, ���������� ��� ���.\n";
		return 1; // ��������� ��������� � �������
	}
	std::string userName = ""; // ���������� ��� �������� ����� ������������
	int userCalories = 0; // ���������� ��� �������� ������� ������������
	int userWeight = 0; // ���������� ��� �������� ���� ������������
	std::string activityType = ""; // ���������� ��� �������� ���� ���������� ������������
	std::string foodType = ""; // ���������� ��� �������� ���� ������� ������������

	int choiceMainMenu; // ���������� ��� ������ �������� � ����
	do {
		do
		{
			showMainMenu(); // ���������� ����
			std::cin >> choiceMainMenu; // ��������� ����� ������������
			if (std::cin.fail()) {  // ���������, �� ��������� �� ������ ��� �����
				std::cin.clear(); // ���������� ��������� ������
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����
				std::cout << "�� �� ����� ������ ��� ����� ���� ������. ����������, �������� ������� �� ����.\n";
				continue; // ���������� ���� ��� ���������� �����
			}
			else
				break; // ������� �� �����, ���� ������� ���������� ��������
		} while (true);

		int choiceActivitiesMenu;
		int choiceProductMenu;

		switch (choiceMainMenu) { // ����������� ������ � ����� ����� ��� ��������� ������ ������������
			case 1: {
				int choiceAddUserMenu;
				do
				{
					do
					{
						showAddUserMenu(); // ���������� ���� ���������� ������������
						std::cin >> choiceAddUserMenu; // ��������� ����� ������������
						if (std::cin.fail()) {  // ���������, �� ��������� �� ������ ��� �����
							std::cin.clear(); // ���������� ��������� ������
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����
							std::cout << "�� �� ����� ������ ��� ����� ���� ������. ����������, �������� ������� �� ����.\n";
							continue; // ���������� ���� ��� ���������� �����
						}
						else
							break; // ������� �� �����, ���� ������� ���������� ��������
					} while (true);
					switch (choiceAddUserMenu) {
					case 1: {
						break;
					}
					case 2: {
						// ��� ��� �������� ������������
						userDeleter.runDeleteUI(); // ��������� ���������������� ��������� �������� ������������
						break;
					}
					default: { // ���� ������������ ���� �������� �������
						if (choiceAddUserMenu != 0) { // ���� ������������ �� ������ ����� �� ���������
							std::cout << "�������� �����. ����������, �������� ������� �� ����.\n"; // ������� ��������� �� ������
							choiceAddUserMenu = -1; // ���������� ����� ������������
							continue; // ���������� ���� ��� ���������� ������ ��������
						}
						break;
					}
					}
				} while (choiceAddUserMenu != 0); // ���������� ���� �� ��� ���, ���� ������������ �� ������� ����� �� ���������
				break; // ������� �� �����, ���� ������������ ������ ����� �� ���������
			}

			case 2: {
				int choiceCalorieCalculatorMenu = 0;
				do
				{
					do
					{
						showCalorieCalculatorMenu(); // ���������� ����
						std::cin >> choiceCalorieCalculatorMenu; // ��������� ����� ������������
						if (std::cin.fail()) {  // ���������, �� ��������� �� ������ ��� �����
							std::cin.clear(); // ���������� ��������� ������
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����
							std::cout << "�� �� ����� ������ ��� ����� ���� ������. ����������, �������� ������� �� ����.\n";
							continue; // ���������� ���� ��� ���������� �����
						}
						else
							break; // ������� �� �����, ���� ������� ���������� ��������
					} while (true);
					switch (choiceCalorieCalculatorMenu) {
					case 1: { // ���������� ������� ��� ������������
						break;
					}
					case 2: { // �������� ���������� � ������������
						// ��� ��� ������ ���������� � ������������
						break;
					}
					case 3: { // �������� ���������� � ������������
						// ��� ��� ��������� ���������� � ������������
						break;
					}
					default: { // ���� ������������ ���� �������� �������
						if (choiceCalorieCalculatorMenu != 0) { // ���� ������������ �� ������ ����� �� ���������
							std::cout << "�������� �����. ����������, �������� ������� �� ����.\n"; // ������� ��������� �� ������
							choiceCalorieCalculatorMenu = -1;
							continue; // ���������� ���� ��� ���������� ������ ��������
						}
					} while (true);

						   break;
					}
				} while (choiceCalorieCalculatorMenu != 0); // ���������� ���� �� ��� ���, ���� ������������ �� ������� ����� �� ���������
			}

			case 3: {
				do
				{
					do
					{
						showProductMenu(); // ���������� ����
						std::cin >> choiceProductMenu; // ��������� ����� ������������
						if (std::cin.fail()) {  // ���������, �� ��������� �� ������ ��� �����
							std::cin.clear(); // ���������� ��������� ������
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����
							std::cout << "�� �� ����� ������ ��� ����� ���� ������. ����������, �������� ������� �� ����.\n";
							continue; // ���������� ���� ��� ���������� �����
						}
						else
							break; // ������� �� �����, ���� ������� ���������� ��������
					} while (true);

					switch (choiceProductMenu)
					{
					case 1: { // ���������� ��������
						ProductInput input;
						Product p = input.inputProduct();
						db.addProduct(p);
						break;
					}
					case 2: { // �������� ��� ��������
						auto list = db.getAllProducts(); // �������� ������ ���� ��������� �� ���� ������
						for (const auto& p : list) { // ���������� ��� �������� � ������
							p.printProducts(); // ������� ���������� � ������ ��������
						}
						break;
					}
					case 3: { // �������� ��������
						productDeleter.runDeleteUI();
						break;
					}

					default:
						if (choiceProductMenu != 0) { // ���� ������������ �� ������ ����� �� ���������
							std::cout << "�������� �����. ����������, �������� ������� �� ����.\n"; // ������� ��������� �� ������
							choiceProductMenu = -1; // ���������� ����� ������������
							continue; // ���������� ���� ��� ���������� ������ ��������
						}
						break; // ������� �� �����, ���� ������������ ������ ����� �� ���������
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
						showActivitiesMenu(); // ���������� ����
						std::cin >> choiceActivitiesMenu; // ��������� ����� ������������
						if (std::cin.fail()) {  // ���������, �� ��������� �� ������ ��� �����
							std::cin.clear(); // ���������� ��������� ������
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����
							std::cout << "�� �� ����� ������ ��� ����� ���� ������. ����������, �������� ������� �� ����.\n";
							continue; // ���������� ���� ��� ���������� �����
						}
						else
							break; // ������� �� �����, ���� ������� ���������� ��������
					} while (true);

					switch (choiceActivitiesMenu)
					{
					case 1: {
						ActivitiesInput input; // ������� ������ ActivitiesInput ��� ����� ����������
						Activities a = input.inputActivities(); // ��������� ������ �� ����������
						db.addActivities(a); // ��������� ���������� � ���� ������
						break;
					}

					case 2: {
						auto list = db.getAllActivities();
						for (const auto& a : list) { // ���������� ��� ���������� � ������
							a.printActivities(); // ������� ���������� � ������ ����������
						}
						break;
					}
					case 3: {
						activitiesDeleter.runDeleteUI(); // ��������� ���������������� ��������� �������� �����������
						break;
					}
					default: {
						if (choiceActivitiesMenu != 0) { // ���� ������������ �� ������ ����� �� ���������
							std::cout << "�������� �����. ����������, �������� ������� �� ����.\n"; // ������� ��������� �� ������
							choiceActivitiesMenu = -1; // ���������� ����� ������������
							continue; // ���������� ���� ��� ���������� ������ ��������
						}
						break; // ������� �� �����, ���� ������������ ������ ����� �� ���������
					}

						   break;

					}
				} while (choiceActivitiesMenu != 0);
				break;
			}

			default: {// ���� ������������ ���� �������� �������
				if (choiceMainMenu != 0) { // ���� ������������ �� ������ ����� �� ���������
					std::cout << "�������� �����. ����������, �������� ������� �� ����.\n"; // ������� ��������� �� ������
					choiceMainMenu = -1; // ���������� ����� ������������
					continue; // ���������� ���� ��� ���������� ������ ��������
				}
				break; // ������� �� �����, ���� ������������ ������ ����� �� ���������
			}
		}
	} while (choiceMainMenu != 0); // ���������� ���� �� ��� ���, ���� ������������ �� ������� ����� �� ���������
	// ��������� ���� ������ ����� ������� �� ���������
	db.~DataBase(); // �������� ���������� ���� ������ ��� �������� ���������� � ����� ������
	std::cout << "�� ����� �� ���������.\n"; // ������� ��������� � ������ �� ���������
	return 0;
}
