#include "ActivitiesDeleter.h"
#include <iostream>
#include <limits>

using namespace std;

ActivitiesDeleter::ActivitiesDeleter(DataBase& db) : db(db) {} 

bool ActivitiesDeleter::deleteActivityById(int id) {
	return db.deleteActivityById(id);
}

bool ActivitiesDeleter::deleteAllActivities() {
	return db.deleteAllActivities();
}

void ActivitiesDeleter::runDeleteUI() {
	cout << "1 - ������� ���������� �� ID\n";
	cout << "2 - ������� ��� ����������\n";
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

void ActivitiesDeleter::deleteByIdUI() {
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
		if (deleteActivityById(id))
			cout << "�������.\n";
		else
			cout << "���������� � ����� ID �� �������.\n";
		passed++;
	} while (passed < 1);
}

void ActivitiesDeleter::deleteAllUI() {
	int passed = 0;
	do {
		cout << "�� �������, ��� ������ ������� ��� ����������? (y/n): ";
		char confirm;
		cin >> confirm;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�� �� ����� ������.\n";
			continue;
		}
		if (confirm == 'y' || confirm == 'Y') {
			if (deleteAllActivities())
				cout << "��� ���������� �������.\n";
			else
				cout << "������ ��� �������� �����������.\n";
		}
		passed++;
	} while (passed < 1);
}
