#include "User.h"
#include <iostream>
#include <limits>


using namespace std;

User::User(string name, string gender, double years, double growth, double weight, string activity_type, string food_type)
	: name(name), gender(gender), years(years), growth(growth), weight(weight), activity_type(activity_type), food_type(food_type) {
}
User::User(int id, string name, string gender, double years, double growth, double weight, string activity_type, string food_type)
	: name(name), gender(gender), years(years), growth(growth), weight(weight), activity_type(activity_type), food_type(food_type) {
	this->id = id; // ������������� ID ������������
}
void User::printUser() const { // ����� ��� ������ ���������� � ������������
	cout << "ID: " << id << "\n"
		<< "���: " << name << "\n"
		<< "���: " << gender << "\n"
		<< "�������: " << years << " ���\n"
		<< "����: " << growth << " ��\n"
		<< "���: " << weight << " ��\n"
		<< "��� ����������: " << activity_type << "\n"
		<< "��� �������: " << food_type << "\n"
		<< "---------------------------\n"; // ����������� ��� �������� ������
}