#pragma once
#include "DataBase.h"

class ActivitiesDeleter
{
	private:
		DataBase& db;
		void deleteByIdUI(); 
		void deleteAllUI();
	public:
		explicit ActivitiesDeleter(DataBase& db); // Конструктор, принимающий ссылку на объект базы данных
		bool deleteActivityById(int id); // Функция для удаления активности по ID
		bool deleteAllActivities(); // Функция для удаления всех активностей из базы данных
		void runDeleteUI(); // Функция для запуска пользовательского интерфейса удаления активностей
};

