#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>

using namespace std;

class Product
{
public:
    int id;
    string name;
    double kcal_per_100g;
    double protein;
    double fat;
    double carbs;

    Product(string name, double kcal, double protein, double fat, double carbs);
    Product(int id, string name, double kcal, double protein, double fat, double carbs);

    void printProducts() const;
};

#endif
