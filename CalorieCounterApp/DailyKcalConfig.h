#pragma once
#include "DataBase.h"
#include <string>  

class DailyKcalConfig // Класс для хранения суточной нормы калорий для пользователя
{
public:
    DailyKcalConfig(int userId, double dailyCaloricIntake);
    double getDailyCaloricIntake() const;

private:
    int userId;
    double dailyCaloricIntake;
};

