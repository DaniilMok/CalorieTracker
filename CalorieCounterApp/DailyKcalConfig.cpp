#include "DailyKcalConfig.h"
#include <iostream>
#include <limits>

DailyKcalConfig::DailyKcalConfig(int userId, double dailyCaloricIntake) 
	: userId(userId), dailyCaloricIntake(dailyCaloricIntake) {
}

double DailyKcalConfig::getDailyCaloricIntake() const {

	return dailyCaloricIntake;
}
