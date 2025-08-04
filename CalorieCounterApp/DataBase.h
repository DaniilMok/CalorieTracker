#pragma once
#include "Product.h" // Указывает относительный путь к Product.h
#include "Activities.h" // Указывает относительный путь к Activities.h
#include "User.h" // Указывает относительный путь к User.h
#include "sqlite-amalgamation-3500300/sqlite3.h" // Указывает относительный путь к sqlite3.h
#include <vector> // Используем вектор для хранения продуктов

class DataBase 
{
private: // Указатель на базу данных SQLite
    sqlite3* db; 

public: // Конструктор и деструктор
	DataBase(const char* filename); // Конструктор принимает имя файла базы данных
	~DataBase(); // Деструктор закрывает базу данных

	bool createTableUsers(); // Создает таблицу с пользователями
	bool createTableInfoUsers(); // Создает таблицу с информацией о пользователях
	bool createTableUserActivities(); // Создает таблицу с активностями пользователей
	bool createTableUserProducts(); // Создает таблицу с продуктами пользователей
	bool createTableProducts(); // Создает таблицу продуктов
	bool createTableActivities(); // Создает таблицу активностей
	bool addUser(const User& user); // Добавляет пользователя в базу данных
	int isUserExists(int confirm); // Получает пользователя по ID
	bool deleteUser(); // Удаляет таблицу пользователя из базы данных
	bool addProduct(const Product& product); // Добавляет продукт в базу данных
	bool deleteProductById(int id); // Удаляет продукт по ID
	bool deleteAllProducts(); // Удаляет все продукты из базы данных
	bool addActivities(const Activities& activities); // Добавляет активность в базу данных
	bool deleteActivityById(int id); // Удаляет активность по ID
	bool deleteAllActivities(); // Удаляет все активности из базы данных
	vector<Product> getAllProducts(); // Получает все продукты из базы данных
	vector<Activities> getAllActivities(); // Получает все активности из базы данных
};

