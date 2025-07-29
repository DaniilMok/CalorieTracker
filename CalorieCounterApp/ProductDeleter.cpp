#include "ProductDeleter.h"
#include <iostream>
#include <limits>

using namespace std;

ProductDeleter::ProductDeleter(DataBase& db) : db_(db) {}

bool ProductDeleter::deleteById(int id) {
    return db_.deleteProductById(id);
}

bool ProductDeleter::deleteAll() {
    return db_.deleteAllProducts();
}

void ProductDeleter::runDeleteUI() {
    cout << "1 - ������� ������� �� ID\n";
    cout << "2 - ������� ��� ��������\n";
    int choice = 0;
    while (true) {
        cout << "�����: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�� �� ����� ������. ����������, �������� ������� �� ����.\n";
            continue;
        }
        if (choice == 1) {
            deleteByIdUI();
            break;
        }
        else if (choice == 2) {
            deleteAllUI();
            break;
        }
        else {
            cout << "�������� �����. ����������, �������� 1 ��� 2.\n";
        }
    }
}

void ProductDeleter::deleteByIdUI() {
    int passed = 0;
    do {
        int id;
        cout << "������� ID ��� ��������: ";
        cin >> id;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�� �� ����� ������.\n";
            continue;
        }
        if (deleteById(id))
            cout << "�������.\n";
        else
            cout << "������� � ����� ID �� ������.\n";

        string confirm;
        while (true) {
            cout << "������� ��� ���� �������? (y/n): ";
            cin >> confirm;
            if (confirm.empty()) {
                cout << "����� �� ����� ���� ������. ����������, ������� 'y' ��� 'n'.\n";
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
                cout << "�������� ����. ����������, ������� 'y' ��� 'n'.\n";
            }
        }
    } while (passed != 1);
}

void ProductDeleter::deleteAllUI() {
    string confirm;
    while (true) {
        cout << "������� ��� ��������? (y/n): ";
        cin >> confirm;
        if (confirm.empty()) {
            cout << "����� �� ����� ���� ������. ����������, ������� 'y' ��� 'n'.\n";
            continue;
        }
        else if (confirm == "y" || confirm == "Y") {
            if (deleteAll())
                cout << "��� �������� �������.\n";
            break;
        }
        else if (confirm == "n" || confirm == "N") {
            cout << "�������� ��������.\n";
            break;
        }
        else {
            cout << "�������� ����. ����������, ������� 'y' ��� 'n'.\n";
        }
    }
}