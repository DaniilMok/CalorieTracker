#include "Product.h" // Указывает относительный путь к Product.h
#include <iostream> // Указывает относительный путь к iostream
using namespace std; // Пространство имен std для удобства

Product::Product(string name, double kcal, double protein, double fat, double carbs) // Конструктор для создания продукта с именем и питательными веществами
	: id(0), name(name), kcal_per_100g(kcal), protein(protein), fat(fat), carbs(carbs) { // Инициализация полей id, name, kcal_per_100g, protein, fat и carbs
}

Product::Product(int id, string name, double kcal, double protein, double fat, double carbs) // Конструктор для создания продукта с ID, именем и питательными веществами
	: id(id), name(name), kcal_per_100g(kcal), protein(protein), fat(fat), carbs(carbs) { // Инициализация полей id, name, kcal_per_100g, protein, fat и carbs
}

void Product::printProducts() const { // Метод для вывода информации о продукте
    cout << fixed << "ID: " << id << "\n"
        << "Продукт: " << name << "\n"
        << "Ккал: " << kcal_per_100g << ", Б: " << protein
        << ", Ж: " << fat << ", У: " << carbs << "\n"
        << "---------------------------\n";
}
