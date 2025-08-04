#include "UserInput.h"
#include "InputHelper.h" // ���������� InputHelper ��� ����� �����
#include <iostream>
#include <limits>

using namespace std;

User UserInput::inputUser() {
	string gender;
	int choice_gender;
	do
	{
		do {
			cout << "������� ��� (1 - �������, 2 - �������): ";
			cin >> choice_gender;
			if (cin.fail()) {
				cin.clear(); // ���������� ��������� ������
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������� ������
				cout << "������ �����. ����������, ������� ����� �� 1 �� 3.\n";
				continue; // ���������� ���� ��� ���������� �����
			}
			switch (choice_gender) {
			case 1:
				gender = "�������";
				break;
			case 2:
				gender = "�������";
				break;
			default:
				cout << "�������� ���. ����������, ������� (1 - �������, 2 - �������).\n";
				gender.clear(); // ������� ������ ��� ���������� �����
				break;
			}
		} while (gender.empty());
	} while (gender.empty());

	string name;
	cout << "������� ��� ������������: ";
	cin.ignore();
	getline(cin, name);
	while (name.empty()) {
		cout << "��� �� ����� ���� ������. ����������, ������� ���: ";
		getline(cin, name);
	}
	double years = inputPositiveNumber<double>("������� ������� (� �����): ");
	double growth = inputPositiveNumber<double>("������� ���� (� ��): ");
	double weight = inputPositiveNumber<double>("������� ��� (� ��): ");
	
	string activity_type;
	int choice_activity;
	do
	{
		do {
		cout << "������� ��� ���������� (1 - ������, 2 - �������, 3 - �������): ";
		cin >> choice_activity;
		if (cin.fail()) {
			cin.clear(); // ���������� ��������� ������
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������� ������
			cout << "������ �����. ����������, ������� ����� �� 1 �� 3.\n";
			continue; // ���������� ���� ��� ���������� �����
		}
		switch (choice_activity) {
			case 1:
				activity_type = "������";
				break;
			case 2:
				activity_type = "�������";
				break;
			case 3:
				activity_type = "�������";
				break;
			default:
				cout << "�������� ��� ����������. ����������, ������� (1 - ������, 2 - �������, 3 - �������).\n";
				activity_type.clear(); // ������� ������ ��� ���������� �����
				break;
		}
		} while (activity_type.empty());
	} while (activity_type.empty());

	int choice_food;
	string food_type;
	do
	{
		do {
		cout << "������� ��� ������� (1 - � �����, 2 - ��� ����): ";
		cin >> choice_food;		
		if (cin.fail()) {
			cin.clear(); // ���������� ��������� ������
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ������� ������
			cout << "������ �����. ����������, ������� ����� �� 1 �� 2.\n";
			continue; // ���������� ���� ��� ���������� �����
		}
		switch (choice_food) {
			case 1:
				food_type = "� �����";
				break;
			case 2:
				food_type = "��� ����";
				break;
			default:
				cout << "�������� ��� �������. ����������, ������� (1 - � �����, 2 - ��� ����).\n";
				food_type.clear(); // ������� ������ ��� ���������� �����
				break;
		}
		} while (food_type.empty());
	} while (food_type.empty());

	return User(name, gender, years, growth, weight, activity_type, food_type);
}
