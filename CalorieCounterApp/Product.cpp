#include "Product.h" // ��������� ������������� ���� � Product.h
#include <iostream> // ��������� ������������� ���� � iostream
using namespace std; // ������������ ���� std ��� ��������

Product::Product(string name, double kcal, double protein, double fat, double carbs) // ����������� ��� �������� �������� � ������ � ������������ ����������
	: id(0), name(name), kcal_per_100g(kcal), protein(protein), fat(fat), carbs(carbs) { // ������������� ����� id, name, kcal_per_100g, protein, fat � carbs
}

Product::Product(int id, string name, double kcal, double protein, double fat, double carbs) // ����������� ��� �������� �������� � ID, ������ � ������������ ����������
	: id(id), name(name), kcal_per_100g(kcal), protein(protein), fat(fat), carbs(carbs) { // ������������� ����� id, name, kcal_per_100g, protein, fat � carbs
}

void Product::printProducts() const { // ����� ��� ������ ���������� � ��������
    cout << fixed << "ID: " << id << "\n"
        << "�������: " << name << "\n"
        << "����: " << kcal_per_100g << ", �: " << protein
        << ", �: " << fat << ", �: " << carbs << "\n"
        << "---------------------------\n";
}
