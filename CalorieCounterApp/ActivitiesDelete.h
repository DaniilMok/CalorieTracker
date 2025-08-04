#pragma once
#include "Activities.h" // Для работы с активностями
#include "DataBase.h"  // Для работы с базой данных
#include <vector>      // Для хранения коллекции активностей

class ActivitiesDelete
{
	private:
		DataBase& db; // Ссылка на базу данных
		void deleteByIdUI(); // Метод для удаления активности по ID
		void deleteAllUI(); // Метод для удаления всех активностей
	public:
		explicit ActivitiesDelete(DataBase& database); // Конструктор, принимающий ссылку на базу данных

		bool deleteActivityById(int id); // Удаление активности по ID
		bool deleteAllActivities(); // Удаление всех активностей
		void runDeleteUI(); // Запуск пользовательского интерфейса для удаления активностей
};

