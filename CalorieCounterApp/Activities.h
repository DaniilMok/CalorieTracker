#pragma once
#include<string> // ��������� ������������� ���� � string

using namespace std; // ���������� ������������ ���� std ��� ��������

class Activities // ����� ��� ������������� ����������
{
public: 
	int id; // ID ����������
	string name; // �������� ����������
	double calories_burned_per_minute; // ���������� �������, ��������� �� ������

	Activities(string name, double calBurn); // ����������� ��� �������� ���������� � ������ � ���������, ���������� �� ������
	Activities(int id, string name, double calBurn); // ����������� ��� �������� ���������� � ID, ������ � ���������, ���������� �� ������

	void printActivities() const; // ����� ��� ������ ���������� �� ����������
};

