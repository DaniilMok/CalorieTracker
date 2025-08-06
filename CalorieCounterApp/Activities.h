#pragma once
#include<string> 

class Activities // ����� ��� ������������� ����������
{
public: 
	int id; // ID ����������
	std::string name; // �������� ����������
	double calories_burned_per_minute; // ���������� �������, ��������� �� ������

	Activities(std::string name, double calBurn); // ����������� ��� �������� ���������� � ������ � ���������, ���������� �� ������
	Activities(int id, std::string name, double calBurn); // ����������� ��� �������� ���������� � ID, ������ � ���������, ���������� �� ������

	void printActivities() const; // ������� ��� ������ ���������� �� ����������
};
