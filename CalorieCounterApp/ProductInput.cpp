#include "ProductInput.h"
#include <iostream>
#include <limits>

using namespace std;

Product ProductInput::inputProduct() {
    string name;
    double kcal, protein, fat, carbs;

    cin.ignore();
    cout << "�� 1 �����\n";
    do {
        cout << "��������: "; getline(cin, name);
        if (name.empty()) {
            cout << "�������� �� ����� ���� ������. ����������, ������� �������� ��������.\n";
            continue;
        } else break;
    } while (true);
    do {
        cout << "����: "; cin >> kcal;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�� �� ����� ������ ��� ����� ���� ������. ����������, ������� ������������� �������� �������.\n";
            continue;
        } else if (kcal < 0) {
            cout << "������� �� ����� ���� ��������������. ����������, ������� ������������� ��������.\n";
            continue;
        } else break;
    } while (true);
    do {
        cout << "�����: "; cin >> protein;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�� �� ����� ������ ��� ����� ���� ������. ����������, ������� ������������� �������� ������.\n";
        } else if (protein < 0) {
            cout << "����� �� ����� ���� ��������������. ����������, ������� ������������� ��������.\n";
            continue;
        } else break;
    } while (true);
    do {
        cout << "����: "; cin >> fat;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�� �� ����� ������ ��� ����� ���� ������. ����������, ������� ������������� �������� �����.\n";
        } else if (fat < 0) {
            cout << "���� �� ����� ���� ��������������. ����������, ������� ������������� ��������.\n";
            continue;
        } else break;
    } while (true);
    do {
        cout << "��������: "; cin >> carbs;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "�� �� ����� ������ ��� ����� ���� ������. ����������, ������� ������������� �������� ���������.\n";
        } else if (carbs < 0) {
            cout << "�������� �� ����� ���� ��������������. ����������, ������� ������������� ��������.\n";
            continue;
        } else break;
    } while (true);

    return Product(name, kcal, protein, fat, carbs);
}