#pragma once
#include "DataBase.h"
#include <string>

class UserSelecter
{
private:
	DataBase& db;
	bool selectUserByIdUI(int& userId, std::string& userName, int& userCalories, int& userWeight, std::string& activityType, std::string& foodType);
	bool selectUserByNameUI(int& userId, std::string& userName, int& userCalories, int& userWeight, std::string& activityType, std::string& foodType);
public:
	explicit UserSelecter(DataBase& db);
	bool selectUserById(int& userId, std::string& userName, int& userCalories, int& userWeight, std::string& activityType, std::string& foodType);
	bool selectUserByName(int& userId, std::string& userName, int& userCalories, int& userWeight, std::string& activityType, std::string& foodType);
	void runSelectUserUI(int& userId, std::string& userName, int& userCalories, int& userWeight, std::string& activityType, std::string& foodType);
};

