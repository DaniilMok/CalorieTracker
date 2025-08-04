#include "DailyKcalConfig.h"
#include <iostream>
#include <limits>

DailyKcalConfig::DailyKcalConfig(int userId, double dailyCaloricIntake)
	: userId(userId), dailyCaloricIntake(dailyCaloricIntake) {
}

int DailyKcalConfig::getUserId() const {
	return userId; // Возвращает ID пользователя
}

double DailyKcalConfig::getDailyCaloricIntake() const {

	return dailyCaloricIntake; // Возвращает суточную норму калорий
}
