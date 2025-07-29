#include "ProductInput.h"
#include <iostream>
#include <limits>

using namespace std;

Product ProductInput::inputProduct() {
    string name;
    double kcal, protein, fat, carbs;

    cin.ignore();
    cout << "На 1 грамм\n";
    do {
        cout << "Название: "; getline(cin, name);
        if (name.empty()) {
            cout << "Название не может быть пустым. Пожалуйста, введите название продукта.\n";
            continue;
        } else break;
    } while (true);
    do {
        cout << "Ккал: "; cin >> kcal;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы не ввели ничего или ввели иной символ. Пожалуйста, введите положительное значение калорий.\n";
            continue;
        } else if (kcal < 0) {
            cout << "Калории не могут быть отрицательными. Пожалуйста, введите положительное значение.\n";
            continue;
        } else break;
    } while (true);
    do {
        cout << "Белки: "; cin >> protein;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы не ввели ничего или ввели иной символ. Пожалуйста, введите положительное значение белков.\n";
        } else if (protein < 0) {
            cout << "Белки не могут быть отрицательными. Пожалуйста, введите положительное значение.\n";
            continue;
        } else break;
    } while (true);
    do {
        cout << "Жиры: "; cin >> fat;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы не ввели ничего или ввели иной символ. Пожалуйста, введите положительное значение жиров.\n";
        } else if (fat < 0) {
            cout << "Жиры не могут быть отрицательными. Пожалуйста, введите положительное значение.\n";
            continue;
        } else break;
    } while (true);
    do {
        cout << "Углеводы: "; cin >> carbs;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы не ввели ничего или ввели иной символ. Пожалуйста, введите положительное значение углеводов.\n";
        } else if (carbs < 0) {
            cout << "Углеводы не могут быть отрицательными. Пожалуйста, введите положительное значение.\n";
            continue;
        } else break;
    } while (true);

    return Product(name, kcal, protein, fat, carbs);
}