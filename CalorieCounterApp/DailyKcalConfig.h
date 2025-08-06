#pragma once
#include "DataBase.h"
#include <string>  

class DailyKcalConfig // ����� ��� �������� �������� ����� ������� ��� ������������
{
public:
    DailyKcalConfig(int userId, double dailyCaloricIntake);
    double getDailyCaloricIntake() const;

private:
    int userId;
    double dailyCaloricIntake;
};

