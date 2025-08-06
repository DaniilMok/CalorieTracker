#include "Product.h" 
#include <iostream> 

Product::Product(std::string name, double kcal, double protein, double fat, double carbs) // Конструктор для создания продукта с именем и питательными веществами
	: id(0), name(name), kcal_per_100g(kcal), protein(protein), fat(fat), carbs(carbs) { // Инициализация полей id, name, kcal_per_100g, protein, fat и carbs
}

Product::Product(int id, std::string name, double kcal, double protein, double fat, double carbs) // Конструктор для создания продукта с ID, именем и питательными веществами
	: id(id), name(name), kcal_per_100g(kcal), protein(protein), fat(fat), carbs(carbs) { // Инициализация полей id, name, kcal_per_100g, protein, fat и carbs
}

void Product::printProducts() const { // Функция для вывода информации о продукте
    std::cout << std::fixed << "ID: " << id << "\n"
        << "Продукт: " << name << "\n"
        << "Ккал: " << kcal_per_100g << ", Б: " << protein
        << ", Ж: " << fat << ", У: " << carbs << "\n"
        << "---------------------------\n";
}
