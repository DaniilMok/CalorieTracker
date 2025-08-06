#pragma once
#include "DataBase.h" 
#include <string>

class ProductDeleter { 
private: 
	DataBase& db_; // Ссылка на базу данных
	void deleteByIdUI(); // Функция для пользовательского интерфейса удаления по ID
	void deleteAllUI(); // Функция для пользовательского интерфейса удаления всех продуктов

public:
	explicit ProductDeleter(DataBase& db); // Конструктор принимает ссылку на базу данных
	bool deleteById(int id); // Функция для удаления продукта по ID
	bool deleteAll(); // Функция для удаления всех продуктов
	void runDeleteUI(); // Функция для запуска пользовательского интерфейса удаления продуктов
};