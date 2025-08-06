#pragma once
#include "Product.h" 
#include "Activities.h" 
#include "User.h"
#include "sqlite-amalgamation-3500300/sqlite3.h" 
#include <vector> 

class DataBase 
{
private:
	sqlite3* db; // ��������� �� ���� ������ SQLite

public: 
	DataBase(const char* filename); // ����������� ��������� ��� ����� ���� ������
	~DataBase(); // ���������� ��������� ���� ������

	bool createTableUsers(); // �������, ��������� ������� � ��������������
	bool createTableInfoUsers(); // �������, ��������� ������� � ����������� � �������������
	bool createTableUserActivities(); // �������, ��������� ������� � ������������ �������������
	bool createTableUserProducts(); // �������, ��������� ������� � ���������� �������������
	bool createTableProducts(); // �������, ��������� ������� ���������
	bool createTableActivities(); // �������, ��������� ������� �����������
	bool addUser(const User& user); // �������, ����������� ������������ � ���� ������
	bool editUser(const std::string& columnName, const std::string& newValue); // �������, ������������� ���������� � ������������
	int isUserExists(int confirm); // �������, ����������� ������������� ������������ �� ID
	bool deleteUser(); // �������, ��������� ������� ������������ �� ���� ������
	bool addProduct(const Product& product); // �������, ����������� ������� � ���� ������
	bool deleteProductById(int id); // �������, ��������� ������� �� ID
	bool deleteAllProducts(); // �������, ��������� ��� �������� �� ���� ������
	bool addActivities(const Activities& activities); // �������, ����������� ���������� � ���� ������
	bool deleteActivityById(int id); // �������, ��������� ���������� �� ID
	bool deleteAllActivities(); // �������, ��������� ��� ���������� �� ���� ������
	std::vector<Product> getAllProducts(); // �������, ���������� ��� �������� �� ���� ������
	std::vector<Activities> getAllActivities(); // �������, ���������� ��� ���������� �� ���� ������
};

