#pragma once
#include "Product.h" 
#include "Activities.h" 
#include "User.h"
#include "sqlite-amalgamation-3500300/sqlite3.h" 
#include <vector> 

class DataBase 
{
private:
	sqlite3* db; // ”казатель на базу данных SQLite

public: 
	DataBase(const char* filename); //  онструктор принимает им€ файла базы данных
	~DataBase(); // ƒеструктор закрывает базу данных

	bool createTableUsers(); // ‘ункци€, создающий таблицу с пользовател€ми
	bool createTableInfoUsers(); // ‘ункци€, создающий таблицу с информацией о пользовател€х
	bool createTableUserActivities(); // ‘ункци€, создающий таблицу с активност€ми пользователей
	bool createTableUserProducts(); // ‘ункци€, создающий таблицу с продуктами пользователей
	bool createTableProducts(); // ‘ункци€, создающий таблицу продуктов
	bool createTableActivities(); // ‘ункци€, создающий таблицу активностей
	bool addUser(const User& user); // ‘ункци€, добавл€ющий пользовател€ в базу данных
	bool editUser(const std::string& columnName, const std::string& newValue); // ‘ункци€, редактирующий информацию о пользователе
	int isUserExists(int confirm); // ‘ункци€, провер€ющий существование пользовател€ по ID
	bool deleteUser(); // ‘ункци€, удал€ющий таблицу пользовател€ из базы данных
	bool addProduct(const Product& product); // ‘ункци€, добавл€ющий продукт в базу данных
	bool deleteProductById(int id); // ‘ункци€, удал€ющий продукт по ID
	bool deleteAllProducts(); // ‘ункци€, удал€ющий все продукты из базы данных
	bool addActivities(const Activities& activities); // ‘ункци€, добавл€ющий активность в базу данных
	bool deleteActivityById(int id); // ‘ункци€, удал€ющий активность по ID
	bool deleteAllActivities(); // ‘ункци€, удал€ющий все активности из базы данных
	std::vector<Product> getAllProducts(); // ‘ункци€, получающий все продукты из базы данных
	std::vector<Activities> getAllActivities(); // ‘ункци€, получающий все активности из базы данных
};

