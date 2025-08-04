#pragma once
#include "Product.h" // ��������� ������������� ���� � Product.h
#include "Activities.h" // ��������� ������������� ���� � Activities.h
#include "User.h" // ��������� ������������� ���� � User.h
#include "sqlite-amalgamation-3500300/sqlite3.h" // ��������� ������������� ���� � sqlite3.h
#include <vector> // ���������� ������ ��� �������� ���������

class DataBase 
{
private: // ��������� �� ���� ������ SQLite
    sqlite3* db; 

public: // ����������� � ����������
	DataBase(const char* filename); // ����������� ��������� ��� ����� ���� ������
	~DataBase(); // ���������� ��������� ���� ������

	bool createTableUsers(); // ������� ������� � ��������������
	bool createTableInfoUsers(); // ������� ������� � ����������� � �������������
	bool createTableUserActivities(); // ������� ������� � ������������ �������������
	bool createTableUserProducts(); // ������� ������� � ���������� �������������
	bool createTableProducts(); // ������� ������� ���������
	bool createTableActivities(); // ������� ������� �����������
	bool addUser(const User& user); // ��������� ������������ � ���� ������
	int isUserExists(int confirm); // �������� ������������ �� ID
	bool deleteUser(); // ������� ������� ������������ �� ���� ������
	bool addProduct(const Product& product); // ��������� ������� � ���� ������
	bool deleteProductById(int id); // ������� ������� �� ID
	bool deleteAllProducts(); // ������� ��� �������� �� ���� ������
	bool addActivities(const Activities& activities); // ��������� ���������� � ���� ������
	bool deleteActivityById(int id); // ������� ���������� �� ID
	bool deleteAllActivities(); // ������� ��� ���������� �� ���� ������
	vector<Product> getAllProducts(); // �������� ��� �������� �� ���� ������
	vector<Activities> getAllActivities(); // �������� ��� ���������� �� ���� ������
};

