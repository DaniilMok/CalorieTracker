#include "Activities.h" 
#include <iostream> 

Activities::Activities(std::string name, double calBurn) // ����������� ��� �������� ���������� � ������ � ���������, ���������� �� ������
	: id(0), name(name), calories_burned_per_minute(calBurn) { 
}

Activities::Activities(int id, std::string name, double calBurn) // ����������� ��� �������� ���������� � ID, ������ � ���������, ���������� �� ������
	: id(id), name(name), calories_burned_per_minute(calBurn) { 
}

void Activities::printActivities() const { // ������� ��� ������ ���������� �� ����������
	std::cout << "ID: " << id << "\n"
		<< "����������: " << name << "\n" 
		<< "������� ������� � ������: " << calories_burned_per_minute << "\n"
		<< "---------------------------\n";
}
