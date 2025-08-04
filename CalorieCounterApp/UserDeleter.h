#pragma once
#include "DataBase.h"

class UserDeleter
{
	private:
		DataBase& db; // Ссылка на объект базы данных
	public:
		UserDeleter(DataBase& database) : db(database) {} // Конструктор
		int runDeleteUI(); // Метод для пользовательского интерфейса удаления пользователя
};

