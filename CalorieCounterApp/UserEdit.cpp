#include "UserEdit.h"
#include "DataBase.h"

DataBase db("calorie_counter.db"); // ������� ������ ���� ������
UserEdit userEdit; // ������� ������ UserEdit ��� �������������� ������������


void UserEdit::showEditUserMenu() { // ������� ��� ����������� ���� �������������� ������������
	std::cout << "���� �������������� ������������\n";
	std::cout << "\n1 - �������� ��� ������������\n";
	std::cout << "2 - �������� ������� ������������\n";
	std::cout << "3 - �������� ��� ������������\n";
	std::cout << "4 - �������� ���� ������������\n";
	std::cout << "5 - �������� ��� ������������\n";
	std::cout << "6 - �������� ��� �������\n";
	std::cout << "7 - �������� ��� ����������\n";
	std::cout << "0 - �����\n";
	std::cout << "�����: ";
}
void UserEdit::choiceEditUser() { // ������� ��� ������ �������� � ���� �������������� ������������
	int choiceEditUserMenu = 0;
	do {
		do {
			showEditUserMenu(); // ���������� ���� �������������� ������������
			std::cin >> choiceEditUserMenu; 
			if (std::cin.fail()) {  // ���������, �� ��������� �� ������ ��� �����
				std::cin.clear(); // ���������� ��������� ������
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ����
				std::cout << "�� �� ����� ������ ��� ����� ���� ������. ����������, �������� ������� �� ����.\n";
				continue; // ���������� ���� ��� ���������� �����
			}
			else {
				break; // ������� �� �����, ���� ������� ���������� ��������
			}
		} while (true);
		switch (choiceEditUserMenu) {
		case 1: {
			std::string newName;
			std::cout << "������� ����� ��� ������������: ";
			std::cin >> newName;
			userEdit.editUserName(newName); // �������� ��� ������������
			break;
		}
		// �������� ��������� 
		}
	} while (choiceEditUserMenu != 0); // ������� �� �����, ���� ������������ ������ ����� �� ���������
}

void UserEdit::editUserName(std::string& newName) { // ������� ��� ��������� ����� ������������
	std::string name;
	db.editUser("name", newName); // ����� ������� �������������� ����� ������������ � ���� ������
	std::cout << "��� ������������ �������� ��: " << newName << std::endl;
}
