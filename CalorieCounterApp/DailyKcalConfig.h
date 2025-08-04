#pragma once
#include "DataBase.h"
#include <string>  

class DailyKcalConfig
{
public:
    DailyKcalConfig(int userId, double dailyCaloricIntake);

    int getUserId() const;
    double getDailyCaloricIntake() const;

private:
    int userId;
    double dailyCaloricIntake;
};

