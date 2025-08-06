#pragma once
#include <string>

class Product
{
public: // ���������� id , ���, �������, �����, ���� � ��������
    int id; 
    std::string name;
    double kcal_per_100g;
    double protein;
    double fat;
    double carbs;

	Product(std::string name, double kcal, double protein, double fat, double carbs); // ����������� ��� �������� �������� � ������ � ������������ ����������
	Product(int id, std::string name, double kcal, double protein, double fat, double carbs); // ����������� ��� �������� �������� � ID, c ������ � ������������ ����������

	void printProducts() const; // ������� ��� ������ ���������� � ��������
};
