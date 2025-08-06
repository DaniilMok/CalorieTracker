#pragma once
#include "DataBase.h"

class UserDeleter
{
	private:
		DataBase& db; // Ссылка на объект базы данных
	public:
		UserDeleter(DataBase& database) : db(database) {} // Конструктор
		int runDeleteUI(int& choiceUserMenu); // Функция для пользовательского интерфейса удаления пользователя
};

