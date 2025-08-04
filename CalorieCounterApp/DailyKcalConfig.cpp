#include "DailyKcalConfig.h"
#include <iostream>
#include <limits>

DailyKcalConfig::DailyKcalConfig(int userId, double dailyCaloricIntake)
	: userId(userId), dailyCaloricIntake(dailyCaloricIntake) {
}

int DailyKcalConfig::getUserId() const {
	return userId; // ���������� ID ������������
}

double DailyKcalConfig::getDailyCaloricIntake() const {

	return dailyCaloricIntake; // ���������� �������� ����� �������
}
