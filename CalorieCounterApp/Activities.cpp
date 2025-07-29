#include "Activities.h" // ��������� ������������� ���� � Activities.h
#include<string> // ��������� ������������� ���� � string
#include <iostream> // ��������� ������������� ���� � iostream ��� �����-������

using namespace std; // ���������� ������������ ���� std ��� ��������

Activities::Activities(string name, double calBurn) // ����������� ��� �������� ���������� � ������ � ���������, ���������� �� ������
	: id(0), name(name), calories_burned_per_minute(calBurn) { // ������������� ����� id, name � calories_burned_per_minute
}

Activities::Activities(int id, string name, double calBurn) // ����������� ��� �������� ���������� � ID, ������ � ���������, ���������� �� ������
	: id(id), name(name), calories_burned_per_minute(calBurn) { // ������������� ����� id, name � calories_burned_per_minute
}

void Activities::printActivities() const { // ����� ��� ������ ���������� �� ����������
	cout << "ID: " << id << "\n" // ����� ID ����������
		<< "����������: " << name << "\n" // ����� �������� ����������
		<< "������� ������� � ������: " << calories_burned_per_minute << "\n" // ����� �������, ��������� �� ������
		<< "---------------------------\n"; // ����������� ��� �������� ������
}
