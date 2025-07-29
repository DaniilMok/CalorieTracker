#pragma once
#include "DataBase.h"
#include <string>

class ProductDeleter {
public:
    explicit ProductDeleter(DataBase& db);

    // ������ ������ ��� ������� ��������
    bool deleteById(int id);
    bool deleteAll();

    // ����� �����: ������ ���������������� ��������� ��������
    void runDeleteUI();

private:
    DataBase& db_;
    void deleteByIdUI();
    void deleteAllUI();
};