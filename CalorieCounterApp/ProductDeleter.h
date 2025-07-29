#pragma once
#include "DataBase.h"
#include <string>

class ProductDeleter {
public:
    explicit ProductDeleter(DataBase& db);

    // Старые методы для прямого удаления
    bool deleteById(int id);
    bool deleteAll();

    // Новый метод: полный пользовательский интерфейс удаления
    void runDeleteUI();

private:
    DataBase& db_;
    void deleteByIdUI();
    void deleteAllUI();
};