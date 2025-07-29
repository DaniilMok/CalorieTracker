#pragma once
#include "Product.h" // ��������� ������������� ���� � Product.h
#include "Activities.h" // ��������� ������������� ���� � Activities.h
#include "sqlite-amalgamation-3500300/sqlite3.h" // ��������� ������������� ���� � sqlite3.h
#include <vector> // ���������� ������ ��� �������� ���������

class DataBase 
{
private: // ��������� �� ���� ������ SQLite
    sqlite3* db; 

public: // ����������� � ����������
	DataBase(const char* filename); // ����������� ��������� ��� ����� ���� ������
	~DataBase(); // ���������� ��������� ���� ������

	bool createTableProducts(); // ������� ������� ���������
	bool createTableActivities(); // ������� ������� �����������
	bool addProduct(const Product& product); // ��������� ������� � ���� ������
	bool deleteProductById(int id); // ������� ������� �� ID
	bool deleteAllProducts(); // ������� ��� �������� �� ���� ������
	bool addActivities(const Activities& activities); // ��������� ���������� � ���� ������
	vector<Product> getAllProducts(); // �������� ��� �������� �� ���� ������
};

