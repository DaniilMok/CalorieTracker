#include "ActivitiesDelete.h"
#include <iostream>
#include <limits>

ActivitiesDelete::ActivitiesDelete(DataBase& database) : db(database) {}

bool ActivitiesDelete::deleteActivityById(int id) {
	return db.deleteActivityById(id);
}

bool ActivitiesDelete::deleteAllActivities() {
	return db.deleteAllActivities();
}

void ActivitiesDelete::runDeleteUI() {
	std::cout << "1 - ������� ���������� �� ID\n";
	std::cout << "2 - ������� ��� ����������\n";
	int choice = 0;
	while (true) {
		std::cout << "�����: ";
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�� �� ����� ������. ����������, �������� ������� �� ����.\n";
			continue;
		}
		if (choice == 1) {
			deleteByIdUI();
			break;
		} else if (choice == 2) {
			deleteAllUI();
			break;
		} else {
			std::cout << "�������� �����. ����������, �������� 1 ��� 2.\n";
		}
	}
}

void ActivitiesDelete::deleteByIdUI() {
	int passed = 0;
	do
	{
		int id;
		std::cout << "������� ID ��� ��������: ";
		std::cin >> id;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "�� �� ����� ������.\n";
			continue;
		}
		if (deleteActivityById(id)) {
			std::cout << "���������� ������� �������.\n";
			passed = 1; // �������� ��������
		} else {
			std::cout << "���������� � ����� ID �� �������.\n";
			passed = 0; // ��������� ��������
		}
		std::string confirm;
		while (true) {
			std::cout << "������ ������� ��� ���� ����������? (y/n): ";
			std::cin >> confirm;
			if (confirm.empty()) {
				std::cout << "����� �� ����� ���� ������. ����������, ������� 'y' ��� 'n'.\n";
				continue;
			}
			if (confirm == "y" || confirm == "Y") {
				passed = 0; // ���������� ����
				break;
			} else if (confirm == "n" || confirm == "N") {
				passed = 1; // ��������� ����
				break;
			} else {
				std::cout << "�������� �����. ����������, ������� 'y' ��� 'n'.\n";
			}
		}
	} while (passed != 1);
}

void ActivitiesDelete::deleteAllUI() {
	std::string confirm;
	while (true) {
		std::cout << "�� �������, ��� ������ ������� ��� ����������? (y/n): ";
		std::cin >> confirm;
		if (confirm.empty()) {
			std::cout << "����� �� ����� ���� ������. ����������, ������� 'y' ��� 'n'.\n";
			continue;
		}
		if (confirm == "y") {
			if (deleteAllActivities()) {
				std::cout << "��� ���������� ������� �������.\n";
			} else {
				std::cout << "������ ��� �������� ���� �����������.\n";
			}
		} else if (confirm == "n") {
			std::cout << "�������� ���� ����������� ��������.\n";
		} else {
			std::cout << "�������� �����. ����������, ������� 'y' ��� 'n'.\n";
		}
	}
}