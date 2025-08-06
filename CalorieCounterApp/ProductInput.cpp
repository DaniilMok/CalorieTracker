#include "ProductInput.h"
#include "InputHelper.h"
#include <iostream>
#include <string>

Product ProductInput::inputProduct() { // ������� ��� ����� ���������� � ��������
    std::string name;
    std::cin.ignore();
    std::cout << "��������: ";
    std::getline(std::cin, name);
	while (name.empty()) { // �������� �� ������ ��������
        std::cout << "�������� �� ����� ���� ������. ������� ��������: ";
        std::getline(std::cin, name);
    }

	// ���� ����������� �������, � ��������� �����
    double kcal = inputPositiveNumber<double>("����: ");
    double protein = inputPositiveNumber<double>("�����: ");
    double fat = inputPositiveNumber<double>("����: ");
    double carbs = inputPositiveNumber<double>("��������: ");

    return Product(name, kcal, protein, fat, carbs);
}
