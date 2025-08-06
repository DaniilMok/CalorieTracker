#include "UserDeleter.h"
#include <iostream>
#include <limits>
#include <string>

int UserDeleter::runDeleteUI(int& choiceUserMenu) { // ������� ��� ����������������� ���������� �������� ������������
	std::cout << "���� �������� ������������\n";
	std::cout << "\n1 - ������� ������������\n";
	std::cout << "0 - �����\n";
	int choice; // ���������� ��� ������ �������� � ���� �������� ������������
	while (true) 
	{
		std::cin >> choice;
		if (std::cin.fail()) { // ���������, �� ��������� �� ������ ��� �����
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�� �� ����� ������. ����������, �������� ������� �� ����.\n";
			continue;
		}
		if (choice == 1) {
			db.deleteUser(); // ������� ������������ �� ���� ������
			std::cout << "������������ ������� ������.\n";
			std::cout << "�� ������ �������� ������ ������������.\n";
			std::cout << "����������� � ������� ����.\n";
			choice = 0;
			choiceUserMenu = 0;	// ���������� ����� ���� ������������
			return 0; // ���������� 0, ���� ������������ ������� ������
			break;
		}

		if (choice == 0) {
			std::cout << "����� �� ����\n";
			break;
		}
	}
}
