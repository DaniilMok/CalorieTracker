#include "ProductDeleter.h"
#include <iostream>
#include <limits>

using namespace std;

ProductDeleter::ProductDeleter(DataBase& db) : db_(db) {}

bool ProductDeleter::deleteById(int id) {
    return db_.deleteProductById(id);
}

bool ProductDeleter::deleteAll() {
    return db_.deleteAllProducts();
}

void ProductDeleter::runDeleteUI() {
    cout << "1 - Удалить продукт по ID\n";
    cout << "2 - Удалить все продукты\n";
    int choice = 0;
    while (true) {
        cout << "Выбор: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы не ввели ничего. Пожалуйста, выберите вариант из меню.\n";
            continue;
        }
        if (choice == 1) {
            deleteByIdUI();
            break;
        }
        else if (choice == 2) {
            deleteAllUI();
            break;
        }
        else {
            cout << "Неверный выбор. Пожалуйста, выберите 1 или 2.\n";
        }
    }
}

void ProductDeleter::deleteByIdUI() {
    int passed = 0;
    do {
        int id;
        cout << "Введите ID для удаления: ";
        cin >> id;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Вы не ввели ничего.\n";
            continue;
        }
        if (deleteById(id))
            cout << "Удалено.\n";
        else
            cout << "Продукт с таким ID не найден.\n";

        string confirm;
        while (true) {
            cout << "Удалить еще один продукт? (y/n): ";
            cin >> confirm;
            if (confirm.empty()) {
                cout << "Выбор не может быть пустым. Пожалуйста, введите 'y' или 'n'.\n";
                continue;
            }
            else if (confirm == "y" || confirm == "Y") {
                passed = 0;
                break;
            }
            else if (confirm == "n" || confirm == "N") {
                passed = 1;
                break;
            }
            else {
                cout << "Неверный ввод. Пожалуйста, введите 'y' или 'n'.\n";
            }
        }
    } while (passed != 1);
}

void ProductDeleter::deleteAllUI() {
    string confirm;
    while (true) {
        cout << "Удалить все продукты? (y/n): ";
        cin >> confirm;
        if (confirm.empty()) {
            cout << "Выбор не может быть пустым. Пожалуйста, введите 'y' или 'n'.\n";
            continue;
        }
        else if (confirm == "y" || confirm == "Y") {
            if (deleteAll())
                cout << "Все продукты удалены.\n";
            break;
        }
        else if (confirm == "n" || confirm == "N") {
            cout << "Удаление отменено.\n";
            break;
        }
        else {
            cout << "Неверный ввод. Пожалуйста, введите 'y' или 'n'.\n";
        }
    }
}