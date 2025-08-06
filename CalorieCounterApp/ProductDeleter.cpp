#include "ProductDeleter.h"
#include <iostream>
#include <limits>

ProductDeleter::ProductDeleter(DataBase& db) : db_(db) {} // ����������� ��������� ������ �� ���� ������

bool ProductDeleter::deleteById(int id) { // ������� ��� �������� �������� �� ID
    return db_.deleteProductById(id);
}

bool ProductDeleter::deleteAll() { // ������� ��� �������� ���� ���������
    return db_.deleteAllProducts();
}

void ProductDeleter::runDeleteUI() { // ������� ��� ������� ����������������� ���������� �������� ���������
    std::cout << "1 - ������� ������� �� ID\n";
    std::cout << "2 - ������� ��� ��������\n";
    int choice = 0; 
	while (true) { // ���� ��� ������ ��������
        std::cout << "�����: ";
        std::cin >> choice;
		if (std::cin.fail()) { // �������� �� ��������� �� ������ ��� �����
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "�� �� ����� ������. ����������, �������� ������� �� ����.\n";
            continue; 
        }
        if (choice == 1) {
			deleteByIdUI(); // ������� ��� ������� ���������� �������� �������� �� ID
            break;
        }
        else if (choice == 2) {
			deleteAllUI(); // ������� ��� ������� ���������� �������� ���� ���������
            break;
        }
        else {
            std::cout << "�������� �����. ����������, �������� 1 ��� 2.\n";
        }
    }
}

void ProductDeleter::deleteByIdUI() { // ������� ��� ����������� ���������� �������� �������� �� ID
	int passed = 0; // ���������� ��� ������������
    do {
        int id;
        std::cout << "������� ID ��� ��������: ";
        std::cin >> id;
		if (std::cin.fail()) { // �������� �� ��������� �� ������ ��� �����
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "�� �� ����� ������.\n";
            continue;
        }
		if (deleteById(id)) // ������� ������� ������� �� ID
            std::cout << "�������.\n";
        else
            std::cout << "������� � ����� ID �� ������.\n";

		std::string confirm; // ���������� ��� ������������� ��������
		while (true) { // ���� ��� ������������� ��������
            std::cout << "������� ��� ���� �������? (y/n): ";
            std::cin >> confirm;
			if (confirm.empty()) { // �������� �� ������ ����
                std::cout << "����� �� ����� ���� ������. ����������, ������� 'y' ��� 'n'.\n";
                continue;
            }
            else if (confirm == "y" || confirm == "Y") {
                passed = 0;
                break;
            }
            else if (confirm == "n" || confirm == "N") {
                passed = 1;
                break;
            }
            else {
                std::cout << "�������� ����. ����������, ������� 'y' ��� 'n'.\n";
            }
        }
    } while (passed != 1);
}

void ProductDeleter::deleteAllUI() { // ������� ��� ����������� ���������� �������� ���� ���������
	std::string confirm; // ���������� ��� ������������� ��������
    while (true) {
        std::cout << "������� ��� ��������? (y/n): ";
        std::cin >> confirm;
		if (confirm.empty()) { // �������� �� ������ ����   
            std::cout << "����� �� ����� ���� ������. ����������, ������� 'y' ��� 'n'.\n";
            continue;
        }
        else if (confirm == "y" || confirm == "Y") {
			if (deleteAll()) // ������� ������� ��� ��������    
                std::cout << "��� �������� �������.\n";
            break;
        }
        else if (confirm == "n" || confirm == "N") {
            std::cout << "�������� ��������.\n";
            break;
        }
        else {
            std::cout << "�������� ����. ����������, ������� 'y' ��� 'n'.\n";
        }
    }
}