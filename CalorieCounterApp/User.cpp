#include "User.h"
#include <iostream>
#include <limits>

User::User(std::string name, std::string gender, double years, double growth, double weight, std::string activity_type, std::string food_type) // ����������� ��� �������� ������������
	: name(name), gender(gender), years(years), growth(growth), weight(weight), activity_type(activity_type), food_type(food_type) {
}
User::User(int id, std::string name, std::string gender, double years, double growth, double weight, std::string activity_type, std::string food_type) // ����������� ��� �������� ������������ � ID
	: name(name), gender(gender), years(years), growth(growth), weight(weight), activity_type(activity_type), food_type(food_type) {
	this->id = id; // ������������� ID ������������
}
void User::printUser() const { // ������� ��� ������ ���������� � ������������
	std::cout << "ID: " << id << "\n"
		<< "���: " << name << "\n"
		<< "���: " << gender << "\n"
		<< "�������: " << years << " ���\n"
		<< "����: " << growth << " ��\n"
		<< "���: " << weight << " ��\n"
		<< "��� ����������: " << activity_type << "\n"
		<< "��� �������: " << food_type << "\n"
		<< "---------------------------\n";
}