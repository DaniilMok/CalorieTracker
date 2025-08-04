#include "UserDeleter.h"
#include <iostream>
#include <limits>
#include <string>

int UserDeleter::runDeleteUI() {
	std::cout << "���� �������� ������������\n";
	std::cout << "\n1 - ������� ������������\n";
	std::cout << "0 - �����\n";
	int choice;
	while (true)
	{
		std::cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�� �� ����� ������. ����������, �������� ������� �� ����.\n";
			continue;
		}
		if (choice == 1) {
			db.deleteUser();
			std::cout << "������������ ������� ������.\n";
			return 0; // ���������� 0, ���� ������������ ������� ������
		}

		if (choice == 0) {
			std::cout << "����� �� ����\n";
			break;
		}
	}
}
