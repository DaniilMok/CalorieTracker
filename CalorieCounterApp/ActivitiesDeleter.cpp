#include "ActivitiesDeleter.h"
#include <iostream>
#include <limits>

ActivitiesDeleter::ActivitiesDeleter(DataBase& db) : db(db) {} // �����������, ����������� ������ �� ������ ���� ������

bool ActivitiesDeleter::deleteActivityById(int id) { // ������� ���������� ID ���������� ��� ��������
	return db.deleteActivityById(id);
}

bool ActivitiesDeleter::deleteAllActivities() { // ������� ��� �������� ���� ����������� �� ���� ������
	return db.deleteAllActivities();
}

void ActivitiesDeleter::runDeleteUI() { // ������� ��� ������� ���������� �������� �����������
	std::cout << "1 - ������� ���������� �� ID\n";
	std::cout << "2 - ������� ��� ����������\n";
	int choice = 0;
	while (true) { // ���� ��� ������ ��������
		std::cout << "�����: ";
		std::cin >> choice;
		if (std::cin.fail()) { // �������� �� ���� ������������ ������
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�� �� ����� ������. ����������, �������� ������� �� ����.\n";
			continue; 
		}
		if (choice == 1) {
			deleteByIdUI(); // ����� �������� ��� �������� ���������� �� ID
			break;
		}
		else if (choice == 2) {
			deleteAllUI(); // ����� �������� ��� �������� ���� �����������
			break;
		}
		else {
			std::cout << "�������� �����. ����������, �������� 1 ��� 2.\n";
		}
	}
}

void ActivitiesDeleter::deleteByIdUI() { // ������� ��� �������� ���������� �� ID ����� ���������������� ���������
	int passed = 0; // ���������� ��� ������������ ��������� ���������� �������� 
	do {
		int id;
		std::cout << "������� ID ��� ��������: ";
		std::cin >> id;
		if (std::cin.fail()) { // �������� �� ���� ������������ ������
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�� �� ����� ������.\n";
			continue;
		}
		if (deleteActivityById(id)) // ����� �������� ��� �������� ���������� �� ID
			std::cout << "�������.\n";
		else
			std::cout << "���������� � ����� ID �� �������.\n";
		passed = 1;
	} while (passed != 1);
}

void ActivitiesDeleter::deleteAllUI() { // ������� ��� �������� ���� ����������� ����� ���������������� ���������
	int passed = 0; // ���������� ��� ������������ ��������� ���������� ��������
	do {
		std::cout << "�� �������, ��� ������ ������� ��� ����������? (y/n): ";
		char confirm;
		std::cin >> confirm;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�� �� ����� ������.\n";
			continue;
		}
		if (confirm == 'y' || confirm == 'Y') { // �������� �� ������������� ��������
			if (deleteAllActivities()) // ����� �������� ��� �������� ���� �����������
				std::cout << "��� ���������� �������.\n";
			else
				std::cout << "������ ��� �������� �����������.\n";
		}
		passed = 1;
	} while (passed != 1);
}
