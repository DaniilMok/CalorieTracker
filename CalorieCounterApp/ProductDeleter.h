#pragma once
#include "DataBase.h" 
#include <string>

class ProductDeleter { 
private: 
	DataBase& db_; // ������ �� ���� ������
	void deleteByIdUI(); // ������� ��� ����������������� ���������� �������� �� ID
	void deleteAllUI(); // ������� ��� ����������������� ���������� �������� ���� ���������

public:
	explicit ProductDeleter(DataBase& db); // ����������� ��������� ������ �� ���� ������
	bool deleteById(int id); // ������� ��� �������� �������� �� ID
	bool deleteAll(); // ������� ��� �������� ���� ���������
	void runDeleteUI(); // ������� ��� ������� ����������������� ���������� �������� ���������
};