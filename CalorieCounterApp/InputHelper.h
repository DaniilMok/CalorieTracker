#pragma once
#include <iostream>
#include <limits>
#include <string>

template<typename T> // ������� ��� ����� �������������� ����� � ���������
T inputPositiveNumber(const std::string& prompt) { // ��������� ������� ��� ����� �������������� �����
	T value; // ���������� ��� �������� ���������� ��������
    while (true) {
        std::cout << prompt;
        std::cin >> value;
		if (std::cin.fail() || value < 0) { // ���������, �� ��������� �� ������ ��� ����� � �������� �� �������� �������������
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "������ �����, ������� ������������� �����.\n";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // �������� ������� ������
            return value;
        }
    }
}