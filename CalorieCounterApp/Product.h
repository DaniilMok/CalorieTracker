#pragma once
#include <string>

class Product
{
public: // ѕеременные id , им€, калории, белки, жиры и углеводы
    int id; 
    std::string name;
    double kcal_per_100g;
    double protein;
    double fat;
    double carbs;

	Product(std::string name, double kcal, double protein, double fat, double carbs); //  онструктор дл€ создани€ продукта с именем и питательными веществами
	Product(int id, std::string name, double kcal, double protein, double fat, double carbs); //  онструктор дл€ создани€ продукта с ID, c именем и питательными веществами

	void printProducts() const; // ‘ункци€ дл€ вывода информации о продукте
};
